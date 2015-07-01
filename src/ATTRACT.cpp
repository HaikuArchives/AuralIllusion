// ATTRACT.cpp
// Copyright (c) Blachford Technology 1999
// 7/6/99


#include <Application.h>
#include <StringView.h>
#include <CheckBox.h>
#include <Control.h>
#include <OS.h>

#include <stdio.h>
#include <stdlib.h>

#include "ATTRACT.h"
#include "MsgVals.h"

#include "ATTRACTVars.h" // globals

// --------------------------------------------------------

int32 atmakechans;
float fheight;
float fwidth;

int16 *atsampoint;
int32 athalfmemsize;
int32 atrngstrval;
int32 atrnglenval;
int32 atsamcount;

void *atpoint;
int32 asamhalfmemsize;
int32 asamrngstrval;
int32 asamrnglenval;
int32 asammakechans;

/*****************************************************************/

const BRect rect(200,23,600,423);  
BView* attractview;

BCheckBox* Lines;
BCheckBox* Invert;

char attxt[50]; // Test message text
BStringView* messageboxstring;

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

ATTRACT::ATTRACT()
	: BWindow(rect, "Attractor Display", B_TITLED_WINDOW, B_CURRENT_WORKSPACE)
{
	SetSizeLimits(200,1400,200,1400);
	attractview = new AttractView(BRect(0,0,400,400));

	attractview->SetViewColor(216,216,216); // View is Grey
	attractview->SetHighColor(255,255,255);
	attractview->SetLowColor(0,0,0);

	// Checkbox for lines
	Lines = new BCheckBox(BRect(20,2,65,18), "Lines", "Lines",	new BMessage(ATT_LINES));
	attractview->AddChild(Lines);

	// Checkbox for invert
	Invert = new BCheckBox(BRect(100,2,145,18), "Invert", "Invert",	new BMessage(ATT_INVERT));
	attractview->AddChild(Invert);

	atmakechans=3; // 0=Left 1=Right 2=Stereo 3=Mono

	fheight=360;	// Start vals
	fwidth=400;
	height=360;
	width=400;
	lines=0;
	invert=0;

	messageboxstring = new BStringView(BRect(3,0,259,16), "messageboxstring",
							"",  B_WILL_DRAW);
	messageboxstring->SetHighColor(255,255,255); // text to white
	attractview->AddChild(messageboxstring);

	// show the window
	AddChild(attractview);
	Show();

}

//====================================================================================================

ATTRACT::~ATTRACT(void) // Destructor
{

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void ATTRACT::Drawsample(void)		// Displays Attractor
{
int32 end;

width = fwidth;
height=fheight;

attractview->SetDrawingMode(B_OP_COPY);

attractview->SetHighColor(185,185,185);
attractview->StrokeLine(BPoint(0,24),BPoint(width,24),B_SOLID_HIGH);
attractview->SetHighColor(160,160,160);
attractview->StrokeLine(BPoint(0,25),BPoint(width,25),B_SOLID_HIGH);

if (invert == 0)
	{
	attractview->SetLowColor(0,0,0);
	attractview->SetHighColor(255,255,255);
	}
if (invert == 1)
	{
	attractview->SetLowColor(255,255,255);
	attractview->SetHighColor(0,0,0);
	}

attractview->FillRect(BRect(0,26,width,height+40),B_SOLID_LOW); // fill background

if (lines == 1)	// don't draw more than 50000 lines
	{
	if (atrnglenval >= 50000)
		{
		end = atrngstrval+50000;
		}
	else
		{
		end = atrngstrval+atrnglenval;
		}
	}
else			// don't draw more than 250000 dots
	{
	if (atrnglenval >= 250000)
		{
		end = atrngstrval+250000;
		}
	else
		{
		end = atrngstrval+atrnglenval;
		}
	}
if (end < atrngstrval) end = atrngstrval;

	
if ((atrnglenval > 0) || (end >= 1))
	{	
	int32 temp;
	int32 tempb;
	float ftemp;
	float ftempb;
	float fdwidth;
	float fdheight;
	float widthmul;
	float heightmul;
	int32 xpoint1;
	int32 xpoint2;
	int32 ypoint1;
	int32 ypoint2;

	fdwidth = fwidth-3.0;
	fdheight = fheight+13.0;

	widthmul = 65536.0/fdwidth;
	widthmul = 1/widthmul;
	heightmul = 65536.0/fdheight;
	heightmul = 1/heightmul;

	temp=0;
	ftemp=(float)temp;
	ftemp=ftemp+32767;
	ftemp=ftemp*widthmul;
	xpoint1=(int32)ftemp+2;
	tempb=0;
	ftempb=(float)tempb;
	ftempb=ftempb+32767;
	ftempb=ftempb*heightmul;
	ypoint1=(int32)ftempb;
	ypoint1=ypoint1+40;
	attractview->StrokeLine(BPoint(xpoint1,ypoint1),BPoint(xpoint1,ypoint1),B_SOLID_HIGH);

	for (atsamcount=atrngstrval;atsamcount<=end;atsamcount++)
		{
		temp=*(atsampoint+atsamcount);
		ftemp=(float)temp;
		ftemp=ftemp+32767;
		ftemp=ftemp*widthmul;
		xpoint2=(int32)ftemp+2;
		tempb=*(atsampoint+atsamcount+1);
		ftempb=(float)tempb;
		ftempb=ftempb+32767;
		ftempb=ftempb*heightmul;
		ypoint2=(int32)ftempb;
		ypoint2=~ypoint2;
		ypoint2=ypoint2+fheight+40;
		if (lines == 0)	// points
			{
			attractview->StrokeLine(BPoint(xpoint2,ypoint2),BPoint(xpoint2,ypoint2),B_SOLID_HIGH);
			}
		else			// lines
			{
			attractview->StrokeLine(BPoint(xpoint2,ypoint2),B_SOLID_HIGH);
			xpoint1=xpoint2;
			ypoint1=ypoint2;
			}
		}
//	sprintf(attxt, "%d %d %d %d",atrngstrval,atrnglenval,end,atmakechans);
//	messageboxstring->SetText(attxt);
	}

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void ATTRACT::FrameResized(float width, float height)
{
fheight=height-40;
fwidth=width;
Drawsample();
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

bool ATTRACT::QuitRequested(void)
{
be_app->PostMessage(ATT_CLOSED,be_app);
return (1);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void ATTRACT::MessageReceived(BMessage* msg)
{
//msg->PrintToStream();
//BWindow::MessageReceived(msg);

	switch(msg->what)
	{
	case APP_DRAWATTRACT: // Settings
		msg->FindPointer("appoint", &point);
		msg->FindInt32("aphalfmemsize", &asamhalfmemsize);
		msg->FindInt32("aprngstrval", &asamrngstrval);
		msg->FindInt32("aprnglenval", &asamrnglenval);
		msg->FindInt32("apmakechans", &asammakechans);
		atsampoint = (int16 *)point;		// Convert these to values we understand
		athalfmemsize=asamhalfmemsize;
		atrngstrval = asamrngstrval;
		atrnglenval = asamrnglenval;
		atmakechans = asammakechans;
		if (atrnglenval > 250000) atrnglenval = 250000;
		if (atrnglenval < 0) atrnglenval = 0;
		Drawsample();
		break;

	case ATT_LINES: // Lines
		if (lines == 0) lines = 1;
		else lines = 0;
		Drawsample();
		break;

	case ATT_INVERT: // Invert
		if (invert == 0) invert = 1;
		else invert = 0;
		Drawsample();
		break;

	 default:
		// always pass on messages we don't understand 
	 	BWindow::MessageReceived(msg);
	 	break;
	}
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// SampleView

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

AttractView::AttractView(BRect R)
	: BView(R, "Sample", B_FOLLOW_ALL, B_WILL_DRAW)
{
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void AttractView::MessageReceived(BMessage* msg)
{
	switch(msg->what)
	{
//	message->PrintToStream();
//	BWindow::MessageReceived(message);

	default:
		BView::MessageReceived(msg);
		break;
	}
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void AttractView::Draw(BRect updateRect)
{

SetDrawingMode(B_OP_COPY);
//FillRect(BRect(0,26,width,height+40),B_SOLID_LOW); // fill background Black

SetHighColor(185,185,185);
StrokeLine(BPoint(0,24),BPoint(width,24),B_SOLID_HIGH);
SetHighColor(160,160,160);
StrokeLine(BPoint(0,25),BPoint(width,25),B_SOLID_HIGH);

/*
int32 Count=0;


FillRect(BRect(0,1,fwidth,fheight),B_SOLID_LOW);	// fill background Black

if (drawchans == 2)
	{
	while(Count<Xlim)
		{
		StrokeLine(BPoint(Count,z[Count]),BPoint(Count+1,z[Count+1]),B_SOLID_HIGH);
		StrokeLine(BPoint(Count,zb[Count]),BPoint(Count+1,zb[Count+1]),B_SOLID_HIGH);
		Count++;
		}
	}
else
	{
	StrokeLine(BPoint(Count,z[Count]),BPoint(Count+1,z[Count+1]),B_SOLID_HIGH);
	while(Count<Xlim)
		{
		Count++;
		StrokeLine(BPoint(Count,z[Count]),B_SOLID_HIGH);
		}
	}

SetDrawingMode(B_OP_INVERT);	// Invert for Range Display
FillRect(BRect(drawrngstrt,drawrngtop,drawrngend,drawrngbottom));

SetDrawingMode(B_OP_COPY);		// Back to normal for Zone display
SetHighColor(255,0,0);
StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
SetHighColor(255,255,255);
*/
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************


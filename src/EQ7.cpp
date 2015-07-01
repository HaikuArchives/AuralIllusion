// EQ7.cpp
// Copyright (c) Blachford Technology 1999
// eq7/6/99 

#include <Application.h>
#include <StringView.h>
#include <OS.h>
#include <Button.h>
#include <ScrollBar.h>

#include <stdio.h>
#include <stdlib.h>

#include "EQ7.h"
#include "EQ7Globals.h"
#include "MsgVals.h"

/*****************************************************************/
BView* eq7view;

BStringView*	eq1val;
BStringView* 	eq1string;
char			eq1txt[25];
BStringView*	eq2val;
BStringView*	eq2string;
char 			eq2txt[25];
BStringView*	eq3val;
BStringView*	eq3string;
char 			eq3txt[25];
BStringView*	eq4val;
BStringView*	eq4string;
char 			eq4txt[25];
BStringView*	eq5val;
BStringView*	eq5string;
char 			eq5txt[25];
BStringView*	eq6val;
BStringView*	eq6string;
char 			eq6txt[25];
BStringView*	eq7val;
BStringView*	eq7string;
char 			eq7txt[25];

const BRect rect(200,23,425,208);

//int32 eq7listtype;
//int32 eq7listnumber;
//int32 eq7fxtype;
//int32 eq7fxnumber;
int16 eq7iewmsgtyp;
int16 eq7iewtyp;

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

EQ7::EQ7()
	: BWindow(rect, "7 Band Graphic Equalizer", B_TITLED_WINDOW, B_CURRENT_WORKSPACE)
{
	BView* eq7view = new BView(BRect(0,0,225,285),"eq7view", B_FOLLOW_ALL, B_WILL_DRAW);

	eq7view->SetViewColor(216,216,216); // View is Grey
	eq7view->SetHighColor(255,255,255);
	eq7view->SetLowColor(0,0,0);

	eq1val = new BStringView(BRect(12,3,35,19), "eq1val","256",  B_WILL_DRAW);
	eq1val->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq1val);
	eq2val = new BStringView(BRect(42,3,65,19), "eq2val","256",  B_WILL_DRAW);
	eq2val->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq2val);
	eq3val = new BStringView(BRect(72,3,95,19), "eq3val","256",  B_WILL_DRAW);
	eq3val->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq3val);
	eq4val = new BStringView(BRect(102,3,125,19), "eq4val","256",  B_WILL_DRAW);
	eq4val->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq4val);
	eq5val = new BStringView(BRect(132,3,155,19), "eq5val","256",  B_WILL_DRAW);
	eq5val->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq5val);
	eq6val = new BStringView(BRect(162,3,185,19), "eq6val","256",  B_WILL_DRAW);
	eq6val->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq6val);
	eq7val = new BStringView(BRect(192,3,215,19), "eq7val","256",  B_WILL_DRAW);
	eq7val->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq7val);

	// eq1 ScrollBars
	eq1lev = new EQ1(BRect(15,20,29,160));
	eq7view->AddChild(eq1lev);
	eq2lev = new EQ2(BRect(45,20,59,160));
	eq7view->AddChild(eq2lev);
	eq3lev = new EQ3(BRect(75,20,89,160));
	eq7view->AddChild(eq3lev);
	eq4lev = new EQ4(BRect(105,20,119,160));
	eq7view->AddChild(eq4lev);
	eq5lev = new EQ5(BRect(135,20,149,160));
	eq7view->AddChild(eq5lev);
	eq6lev = new EQ6(BRect(165,20,179,160));
	eq7view->AddChild(eq6lev);
	eq7lev = new EQ7s(BRect(195,20,209,160)); // renames EQ7s to avoid conflicts with main class
	eq7view->AddChild(eq7lev);

	eq1string = new BStringView(BRect(10,160,39,180), "eq1string","Sub",  B_WILL_DRAW);
	eq1string->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq1string);
	eq2string = new BStringView(BRect(40,160,69,180), "eq2string","Bass",  B_WILL_DRAW);
	eq2string->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq2string);
	eq3string = new BStringView(BRect(70,160,99,180), "eq3string","LMid",  B_WILL_DRAW);
	eq3string->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq3string);
	eq4string = new BStringView(BRect(100,160,129,180), "eq4string","Mid",  B_WILL_DRAW);
	eq4string->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq4string);
	eq5string = new BStringView(BRect(130,160,159,180), "eq5string","HMid",  B_WILL_DRAW);
	eq5string->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq5string);
	eq6string = new BStringView(BRect(160,160,189,180), "eq6string","High",  B_WILL_DRAW);
	eq6string->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq6string);
	eq7string = new BStringView(BRect(190,160,229,180), "eq7string","VHigh",  B_WILL_DRAW);
	eq7string->SetHighColor(0,0,0); // text to Black
	eq7view->AddChild(eq7string);

	// OK Button
//	memok = new BButton(BRect(80,130,130,150), "ok", "OK",	new BMessage(MEM_OK));
//	memok->MakeDefault(1); // set as default for fancy surround
//	memok->SetFont(be_bold_font);
//	eq7view->AddChild(memok);

	// show the window
	AddChild(eq7view);
	Show();
	SetFlags(B_NOT_RESIZABLE | B_NOT_ZOOMABLE);

	eq7changed = 0;


	eq7listtype	=1;
	eq7listnumber =0;
	eq7fxtype =1;
	eq7fxnumber =80;
}

//====================================================================================================

EQ7::~EQ7(void) // Destructor
{

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void EQ7::Updateeq7(void)	// Scroll bar has eq7changed
{

sprintf(eq1txt,"%d ",vals[1]);
sprintf(eq2txt,"%d ",vals[2]);
sprintf(eq3txt,"%d ",vals[3]);
sprintf(eq4txt,"%d ",vals[4]);
sprintf(eq5txt,"%d ",vals[5]);
sprintf(eq6txt,"%d ",vals[6]);
sprintf(eq7txt,"%d ",vals[7]);

Lock();
if (eq7changed == 1)	eq1val->SetText(eq1txt);
if (eq7changed == 2)	eq2val->SetText(eq2txt);
if (eq7changed == 3)	eq3val->SetText(eq3txt);
if (eq7changed == 4)	eq4val->SetText(eq4txt);
if (eq7changed == 5)	eq5val->SetText(eq5txt);
if (eq7changed == 6)	eq6val->SetText(eq6txt);
if (eq7changed == 7)	eq7val->SetText(eq7txt);
Unlock();
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void EQ7::Updatealleq7(void)	// Scroll bar has eq7changed
{
int16 temp;

sprintf(eq1txt,"%d ",vals[1]);
sprintf(eq2txt,"%d ",vals[2]);
sprintf(eq3txt,"%d ",vals[3]);
sprintf(eq4txt,"%d ",vals[4]);
sprintf(eq5txt,"%d ",vals[5]);
sprintf(eq6txt,"%d ",vals[6]);
sprintf(eq7txt,"%d ",vals[7]);

Lock();
eq1val->SetText(eq1txt);
eq2val->SetText(eq2txt);
eq3val->SetText(eq3txt);
eq4val->SetText(eq4txt);
eq5val->SetText(eq5txt);
eq6val->SetText(eq6txt);
eq7val->SetText(eq7txt);
temp=256-vals[1];
eq1lev->SetValue(temp);
temp=256-vals[2];
eq2lev->SetValue(temp);
temp=256-vals[3];
eq3lev->SetValue(temp);
temp=256-vals[4];
eq4lev->SetValue(temp);
temp=256-vals[5];
eq5lev->SetValue(temp);
temp=256-vals[6];
eq6lev->SetValue(temp);
temp=256-vals[7];
eq7lev->SetValue(temp);
Unlock();
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

bool EQ7::QuitRequested(void)
{
BMessage *msg = new BMessage(IW_CLOSED);
msg->AddInt16("iewtyp", 0);	// EQ7 closed
be_app->PostMessage(msg,be_app);
delete (msg);

return (1);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void EQ7::MessageReceived(BMessage* msg)
{
//msg->PrintToStream();
//BWindow::MessageReceived(msg);

switch(msg->what)
	{

// Messages from other windows

	case IAP_SET:	// New Settings
	msg->FindInt16("iewmsgtyp", &eq7iewmsgtyp);
//	msg->FindInt32("listtype", &eq7listtype);
//	msg->FindInt32("listnumber", &eq7listnumber);
//	msg->FindInt32("fxtype", &eq7fxtype);
//	msg->FindInt32("fxnumber", &eq7fxnumber);
	msg->FindInt16("iewtyp", &eq7iewtyp);
	msg->FindInt16("eq0lev", &vals[0]);
	msg->FindInt16("eq1lev", &vals[1]);
	msg->FindInt16("eq2lev", &vals[2]);
	msg->FindInt16("eq3lev", &vals[3]);
	msg->FindInt16("eq4lev", &vals[4]);
	msg->FindInt16("eq5lev", &vals[5]);
	msg->FindInt16("eq6lev", &vals[6]);
	msg->FindInt16("eq7lev", &vals[7]);
	Updatealleq7();
	break;

	case IAP_NEWVAL:	// New Val in EQ7
//	msg->FindInt32("listtype", &eq7listtype);
//	msg->FindInt32("listnumber", &eq7listnumber);
//	msg->FindInt32("fxtype", &eq7fxtype);
//	msg->FindInt32("fxnumber", &eq7fxnumber);
	msg->FindInt16("iewtyp", &eq7iewtyp);
	msg->FindInt16("iewmsgtyp", &eq7iewmsgtyp);
	Updateeq7();
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

// OVERRIDES FOR SCROLL BARS 

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ1::EQ1(BRect R)
	: BScrollBar(BRect(15,20,29,160),"eq1",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ1::MessageReceived(BMessage* msg)
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
void EQ1::ValueChanged(float value)
{
inum = (int16)Value();
inum = 256 - inum;
vals[1] = inum;
eq7changed=1;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq7listtype);
msg->AddInt32("listnumber", eq7listnumber);
msg->AddInt32("fxtype", eq7fxtype);
msg->AddInt32("fxnumber", eq7fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 0);	//	0=EQ7
msg->AddInt16("eq0lev", vals[0]);
msg->AddInt16("eq1lev", vals[1]);
msg->AddInt16("eq2lev", vals[2]);
msg->AddInt16("eq3lev", vals[3]);
msg->AddInt16("eq4lev", vals[4]);
msg->AddInt16("eq5lev", vals[5]);
msg->AddInt16("eq6lev", vals[6]);
msg->AddInt16("eq7lev", vals[7]);
msg->AddInt16("eq8lev", 0);
msg->AddInt16("eq9lev", 0);
msg->AddInt16("eq10lev", 0);
msg->AddInt16("eq11lev", 0);
msg->AddInt16("eq12lev", 0);
msg->AddInt16("eq13lev", 0);
msg->AddInt16("eq14lev", 0);
msg->AddInt16("eq15lev", 0);
msg->AddInt16("eq16lev", 0);
msg->AddInt16("eq17lev", 0);
msg->AddInt16("eq18lev", 0);
msg->AddInt16("eq19lev", 0);
msg->AddInt16("eq20lev", 0);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ2::EQ2(BRect R)
	: BScrollBar(BRect(45,20,59,160),"eq2",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ2::MessageReceived(BMessage* msg)
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
void EQ2::ValueChanged(float value)
{
inum = (int32)Value();
inum = 256 - inum;
vals[2] = inum;
eq7changed=2;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq7listtype);
msg->AddInt32("listnumber", eq7listnumber);
msg->AddInt32("fxtype", eq7fxtype);
msg->AddInt32("fxnumber", eq7fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 0);	//	0=EQ7
msg->AddInt16("eq0lev", vals[0]);
msg->AddInt16("eq1lev", vals[1]);
msg->AddInt16("eq2lev", vals[2]);
msg->AddInt16("eq3lev", vals[3]);
msg->AddInt16("eq4lev", vals[4]);
msg->AddInt16("eq5lev", vals[5]);
msg->AddInt16("eq6lev", vals[6]);
msg->AddInt16("eq7lev", vals[7]);
msg->AddInt16("eq8lev", 0);
msg->AddInt16("eq9lev", 0);
msg->AddInt16("eq10lev", 0);
msg->AddInt16("eq11lev", 0);
msg->AddInt16("eq12lev", 0);
msg->AddInt16("eq13lev", 0);
msg->AddInt16("eq14lev", 0);
msg->AddInt16("eq15lev", 0);
msg->AddInt16("eq16lev", 0);
msg->AddInt16("eq17lev", 0);
msg->AddInt16("eq18lev", 0);
msg->AddInt16("eq19lev", 0);
msg->AddInt16("eq20lev", 0);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ3::EQ3(BRect R)
	: BScrollBar(BRect(75,20,89,160),"eq3",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ3::MessageReceived(BMessage* msg)
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
void EQ3::ValueChanged(float value)
{
inum = (int32)Value();
inum = 256 - inum;
vals[3] = inum;
eq7changed=3;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq7listtype);
msg->AddInt32("listnumber", eq7listnumber);
msg->AddInt32("fxtype", eq7fxtype);
msg->AddInt32("fxnumber", eq7fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 0);	//	0=EQ7
msg->AddInt16("eq0lev", vals[0]);
msg->AddInt16("eq1lev", vals[1]);
msg->AddInt16("eq2lev", vals[2]);
msg->AddInt16("eq3lev", vals[3]);
msg->AddInt16("eq4lev", vals[4]);
msg->AddInt16("eq5lev", vals[5]);
msg->AddInt16("eq6lev", vals[6]);
msg->AddInt16("eq7lev", vals[7]);
msg->AddInt16("eq8lev", 0);
msg->AddInt16("eq9lev", 0);
msg->AddInt16("eq10lev", 0);
msg->AddInt16("eq11lev", 0);
msg->AddInt16("eq12lev", 0);
msg->AddInt16("eq13lev", 0);
msg->AddInt16("eq14lev", 0);
msg->AddInt16("eq15lev", 0);
msg->AddInt16("eq16lev", 0);
msg->AddInt16("eq17lev", 0);
msg->AddInt16("eq18lev", 0);
msg->AddInt16("eq19lev", 0);
msg->AddInt16("eq20lev", 0);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ4::EQ4(BRect R)
	: BScrollBar(BRect(105,20,119,160),"eq4",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ4::MessageReceived(BMessage* msg)
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
void EQ4::ValueChanged(float value)
{
inum = (int32)Value();
inum = 256 - inum;
vals[4] = inum;
eq7changed=4;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq7listtype);
msg->AddInt32("listnumber", eq7listnumber);
msg->AddInt32("fxtype", eq7fxtype);
msg->AddInt32("fxnumber", eq7fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 0);	//	0=EQ7
msg->AddInt16("eq0lev", vals[0]);
msg->AddInt16("eq1lev", vals[1]);
msg->AddInt16("eq2lev", vals[2]);
msg->AddInt16("eq3lev", vals[3]);
msg->AddInt16("eq4lev", vals[4]);
msg->AddInt16("eq5lev", vals[5]);
msg->AddInt16("eq6lev", vals[6]);
msg->AddInt16("eq7lev", vals[7]);
msg->AddInt16("eq8lev", 0);
msg->AddInt16("eq9lev", 0);
msg->AddInt16("eq10lev", 0);
msg->AddInt16("eq11lev", 0);
msg->AddInt16("eq12lev", 0);
msg->AddInt16("eq13lev", 0);
msg->AddInt16("eq14lev", 0);
msg->AddInt16("eq15lev", 0);
msg->AddInt16("eq16lev", 0);
msg->AddInt16("eq17lev", 0);
msg->AddInt16("eq18lev", 0);
msg->AddInt16("eq19lev", 0);
msg->AddInt16("eq20lev", 0);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ5::EQ5(BRect R)
	: BScrollBar(BRect(135,20,149,160),"eq5",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ5::MessageReceived(BMessage* msg)
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
void EQ5::ValueChanged(float value)
{
inum = (int32)Value();
inum = 256 - inum;
vals[5] = inum;
eq7changed=5;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq7listtype);
msg->AddInt32("listnumber", eq7listnumber);
msg->AddInt32("fxtype", eq7fxtype);
msg->AddInt32("fxnumber", eq7fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 0);	//	0=EQ7
msg->AddInt16("eq0lev", vals[0]);
msg->AddInt16("eq1lev", vals[1]);
msg->AddInt16("eq2lev", vals[2]);
msg->AddInt16("eq3lev", vals[3]);
msg->AddInt16("eq4lev", vals[4]);
msg->AddInt16("eq5lev", vals[5]);
msg->AddInt16("eq6lev", vals[6]);
msg->AddInt16("eq7lev", vals[7]);
msg->AddInt16("eq8lev", 0);
msg->AddInt16("eq9lev", 0);
msg->AddInt16("eq10lev", 0);
msg->AddInt16("eq11lev", 0);
msg->AddInt16("eq12lev", 0);
msg->AddInt16("eq13lev", 0);
msg->AddInt16("eq14lev", 0);
msg->AddInt16("eq15lev", 0);
msg->AddInt16("eq16lev", 0);
msg->AddInt16("eq17lev", 0);
msg->AddInt16("eq18lev", 0);
msg->AddInt16("eq19lev", 0);
msg->AddInt16("eq20lev", 0);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ6::EQ6(BRect R)
	: BScrollBar(BRect(165,20,179,160),"eq6",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ6::MessageReceived(BMessage* msg)
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
void EQ6::ValueChanged(float value)
{
inum = (int32)Value();
inum = 256 - inum;
vals[6] = inum;
eq7changed=6;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq7listtype);
msg->AddInt32("listnumber", eq7listnumber);
msg->AddInt32("fxtype", eq7fxtype);
msg->AddInt32("fxnumber", eq7fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 0);	//	0=EQ7
msg->AddInt16("eq0lev", vals[0]);
msg->AddInt16("eq1lev", vals[1]);
msg->AddInt16("eq2lev", vals[2]);
msg->AddInt16("eq3lev", vals[3]);
msg->AddInt16("eq4lev", vals[4]);
msg->AddInt16("eq5lev", vals[5]);
msg->AddInt16("eq6lev", vals[6]);
msg->AddInt16("eq7lev", vals[7]);
msg->AddInt16("eq8lev", 0);
msg->AddInt16("eq9lev", 0);
msg->AddInt16("eq10lev", 0);
msg->AddInt16("eq11lev", 0);
msg->AddInt16("eq12lev", 0);
msg->AddInt16("eq13lev", 0);
msg->AddInt16("eq14lev", 0);
msg->AddInt16("eq15lev", 0);
msg->AddInt16("eq16lev", 0);
msg->AddInt16("eq17lev", 0);
msg->AddInt16("eq18lev", 0);
msg->AddInt16("eq19lev", 0);
msg->AddInt16("eq20lev", 0);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ7s::EQ7s(BRect R)
	: BScrollBar(BRect(195,20,209,160),"eq7",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ7s::MessageReceived(BMessage* msg)
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
void EQ7s::ValueChanged(float value)
{
inum = (int32)Value();
inum = 256 - inum;
vals[7] = inum;
eq7changed=7;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq7listtype);
msg->AddInt32("listnumber", eq7listnumber);
msg->AddInt32("fxtype", eq7fxtype);
msg->AddInt32("fxnumber", eq7fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 0);	//	0=EQ7
msg->AddInt16("eq0lev", vals[0]);
msg->AddInt16("eq1lev", vals[1]);
msg->AddInt16("eq2lev", vals[2]);
msg->AddInt16("eq3lev", vals[3]);
msg->AddInt16("eq4lev", vals[4]);
msg->AddInt16("eq5lev", vals[5]);
msg->AddInt16("eq6lev", vals[6]);
msg->AddInt16("eq7lev", vals[7]);
msg->AddInt16("eq8lev", 0);
msg->AddInt16("eq9lev", 0);
msg->AddInt16("eq10lev", 0);
msg->AddInt16("eq11lev", 0);
msg->AddInt16("eq12lev", 0);
msg->AddInt16("eq13lev", 0);
msg->AddInt16("eq14lev", 0);
msg->AddInt16("eq15lev", 0);
msg->AddInt16("eq16lev", 0);
msg->AddInt16("eq17lev", 0);
msg->AddInt16("eq18lev", 0);
msg->AddInt16("eq19lev", 0);
msg->AddInt16("eq20lev", 0);
be_app->PostMessage(msg,be_app);
delete (msg);
}


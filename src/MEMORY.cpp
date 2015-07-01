// MEMORY.cpp
// Copyright (c) Blachford Technology 1999
// 7/6/99

#include <Alert.h>
#include <Application.h>
#include <StringView.h>
#include <CheckBox.h>
#include <Control.h>
#include <OS.h>
#include <Slider.h>
#include <Button.h>
#include <RadioButton.h>

#include <stdio.h>
#include <stdlib.h>

#include "MEMORY.h"
#include "MsgVals.h"

/*****************************************************************/
BView* memoryview;

BStringView* memstring;
char memtxt[25]; // memory message text
BStringView* timestring;
char timetxt[25]; // Time message text
BStringView* kstring;

int32 memmemsize;
int32 memtyp;
int32 sliderlev;


const BRect rect(200,23,410,183);

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

MEMORY::MEMORY()
	: BWindow(rect, "Aural illusion - Memory Setup", B_TITLED_WINDOW, B_CURRENT_WORKSPACE)
{
	BView* memoryview = new BView(BRect(0,0,210,160),"memoryview", B_FOLLOW_ALL, B_WILL_DRAW);

	memoryview->SetViewColor(216,216,216); // View is Grey
	memoryview->SetHighColor(255,255,255);
	memoryview->SetLowColor(0,0,0);

	memlev = new BSlider(BRect(3,3,200,53), "memlev", "Memory Size",  new BMessage(MEM_LEV), 0,100);
	memlev->SetHashMarks(B_HASH_MARKS_BOTH);
	memlev->SetHashMarkCount(9);
	memlev->SetLimitLabels("Min", "Max");
	memlev->SetValue(0);
	memoryview->AddChild(memlev);

	// View for Radio Buttons
	BView* memtypview = new BView(BRect(145,65,210,135), "memtypview", B_FOLLOW_ALL, B_WILL_DRAW);
	
	small = new BRadioButton(BRect(0,0,65,15),"small","Small",			new BMessage(MEM_SMALL));
	small->SetValue(1); // default is small
	memtypview->AddChild(small);

	medium = new BRadioButton(BRect(0,16,65,29),"medium","Medium",		new BMessage(MEM_MEDIUM));
	memtypview->AddChild(medium);

	large = new BRadioButton(BRect(0,32,65,33),"large","Large",		new BMessage(MEM_LARGE));
	memtypview->AddChild(large);

	memtypview->SetViewColor(216,216,216);
	memoryview->AddChild(memtypview);

	// OK Button
	memok = new BButton(BRect(80,130,130,150), "ok", "OK",	new BMessage(MEM_OK));
	memok->MakeDefault(1); // set as default for fancy surround
	memok->SetFont(be_bold_font);
	memoryview->AddChild(memok);

	// memory display string
	memstring = new BStringView(BRect(5,70,144,84), "memstring"," ",  B_WILL_DRAW);
	memstring->SetFont(be_bold_font);
	memstring->SetHighColor(0,0,0); // text to Black
	memoryview->AddChild(memstring);

	// Time display string
	timestring = new BStringView(BRect(5,85,144,100), "timestring"," ",  B_WILL_DRAW);
	timestring->SetFont(be_bold_font);
	timestring->SetHighColor(0,0,0); // text to Black
	memoryview->AddChild(timestring);

	// KHz string
	kstring = new BStringView(BRect(5,101,144,116), "kstring","at 44KHz Mono",  B_WILL_DRAW);
	kstring->SetFont(be_bold_font);
	kstring->SetHighColor(0,0,0); // text to Black
	memoryview->AddChild(kstring);

	// show the window
	AddChild(memoryview);
	Show();
	SetFlags(B_NOT_RESIZABLE | B_NOT_ZOOMABLE | B_NOT_CLOSABLE);
	
//	BRect screenrect = Frame();
	memtyp = 1;
	Displaymemory();
}

//====================================================================================================

MEMORY::~MEMORY(void) // Destructor
{

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void MEMORY::Setupmemory(void)		// Sets up memory
{

// TEST default to 8MB
//memmemsize = B_PAGE_SIZE*2000; // 8MB
//memmemsize = B_PAGE_SIZE*25000; // 100MB

// Ask App to allocate this much RAM 
BMessage *msg = new BMessage(MEM_FETCH);
msg->AddInt32("memmemsize", memmemsize); // int32
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void MEMORY::Displaymemory(void)		// Sets up memory
{
float fslide;
int32 displaysize;

sliderlev = memlev->Value();
fslide = (float)sliderlev;
fslide = fslide * B_PAGE_SIZE; // * 4096

// First calculate value
if (memtyp == 1)	// 200K - 4MB - 12 secs
	{
	fslide = fslide * 9.74;
	fslide = fslide + 204800;
	}
if (memtyp == 2)	// 2MB - 20MB - 1 min
	{
	fslide = fslide * 46.08;
	fslide = fslide + 2097152;
	}
if (memtyp == 3)	// 10MB - 200MB - 10 mins
	{
	fslide = fslide * 486.4;
	fslide = fslide + 10485760;
	}
memmemsize = (int32)fslide;
memmemsize = memmemsize >> 12;
memmemsize = memmemsize << 12;

// Display memory value
if (memtyp == 1)	// 200K - 4MB - 12 secs
	{
	fslide = fslide * 0.001;
	}
if (memtyp == 2)	// 2MB - 20MB - 1 min
	{
	fslide = fslide * 0.001;
	}
if (memtyp == 3)	// 10MB - 200MB - 10 mins
	{
	fslide = fslide * 0.000001;
	}
displaysize = (int32)fslide;
if ((memtyp == 1) || (memtyp == 2)) sprintf(memtxt,"%d KBytes",displaysize);
if (memtyp == 3) sprintf(memtxt,"%d MBytes",displaysize);

// Display time value
if (memtyp == 1)	// 200K - 4MB - 12 secs
	{
	fslide = fslide * 1000;
	fslide = fslide / 176440;
	}
if (memtyp == 2)	// 2MB - 20MB - 1 min
	{
	fslide = fslide * 1000;
	fslide = fslide / 176440;
	}
if (memtyp == 3)	// 10MB - 200MB - 10 mins
	{
	fslide = fslide * 1000000;
	fslide = fslide / 10586400;
	}
displaysize = (int32)fslide;
if ((memtyp == 1) || (memtyp == 2)) sprintf(timetxt,"%d Seconds",displaysize);
if (memtyp == 3) sprintf(timetxt,"%d Minutes",displaysize);

Lock();
memstring->SetText(memtxt);
timestring->SetText(timetxt);

//sprintf(timetxt,"%d",memmemsize);
//kstring->SetText(timetxt);

Unlock();
}
	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void MEMORY::Oops(void)
{
	(new BAlert("Oops!\n\n",
		"Can't allocate that much memory",
		"Oops!"))->Go();
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

bool MEMORY::QuitRequested(void)
{
return (1);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void MEMORY::MessageReceived(BMessage* msg)
{
//msg->PrintToStream();
//BWindow::MessageReceived(msg);

switch(msg->what)
	{

	case MEM_OK: // OK Clicked
	Setupmemory();
	break;

	case MEM_LEV: //  Slider Clicked
	Displaymemory();
	break;

	case MEM_SMALL: //  Small Clicked
	memtyp = 1;
	Displaymemory();
	break;

	case MEM_MEDIUM: //  Medium Clicked
	memtyp = 2;
	Displaymemory();
	break;

	case MEM_LARGE: //  Large Clicked
	memtyp = 3;
	Displaymemory();
	break;

// Messages from other windows

	case MEM_NOT: //  CAN'T ALLOCATE THIS MUCH RAM
	Oops();
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
// LOAD.cpp 
// Copyright (c) Blachford Technology 1999
// 28/4/99

#include <Box.h>
#include <Slider.h>
#include <CheckBox.h>
#include <Application.h>
#include "MsgVals.h"
#include <Button.h>
#include <RadioButton.h>
#include <StringView.h>
#include <Alert.h>
#include <Message.h>
#include <ListView.h>
#include <ScrollView.h>
#include <MenuField.h>
#include <Menu.h>
#include <MenuItem.h>

#include "FilePanel.h"
#include <File.h>
#include <Path.h>
#include <Entry.h>
#include <String.h>
#include <MediaFile.h>
#include <MediaTrack.h>

#include "LOAD.h"

#include <stdio.h>
#include <stdlib.h>

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

// LOAD Globals & definitions

int32 tloadtype;
int32 tloadhalfmemsize;
int32 tloadsamstart;
int32 tloadsamend;
int32 tloadsamlen;
int32 tloadmakechans;

int16 *bufferpoint;
int16 *loadpoint;
uint32 loadhalfmemsize;
uint32 loadmemsize;
uint32 loadsamstart;
uint32 loadsamend;
uint32 loadsamlen;
int32 loadmakechans;

void *loadvpoint;

static int32 listnumber;	// for list elements
static int32 loadnumber;	// for displaying data / calling load

static int32 listloadno;	// Current loader selected
static int32 listsaveno;	// Current saver selected

static int32 loadtype;		// 0=load	1=save

static int32 loadinputL1;	// settings for radio buttons
static int32 loadinputL2;
static int32 loadinputL3;

static int32 loadinputS1;	// same for saving
static int32 loadinputS2;
static int32 loadinputS3;

static int32 lbyteswap;
static int32 lbits;
static int32 ltranslate;
static int32 sbyteswap;
static int32 sbits;
static int32 stranslate;

BFilePanel* loadfilepanel;
entry_ref lo_aref;
BFile* lo_afile;

BFilePanel* savefilepanel;
entry_ref sa_aref;
BFile* sa_afile;
const char *sa_filename;
BDirectory* sa_dir;

BMessenger* loadmessenger;

// another text array here for LOAD / SAVE message box
char loadboxtxt[2][16][3][50];

char loadtexttest[4][20];
int8 loadvals[2][16][3];



// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

LOAD::LOAD(void)
	: BWindow(BRect(248,23,663,230), "Load Sample", B_TITLED_WINDOW_LOOK,B_NORMAL_WINDOW_FEEL, 0)
{

	loadmessenger = new BMessenger(NULL,this,NULL);

	loadfilepanel = new BFilePanel(	//  Load Requester
		B_OPEN_PANEL,
		loadmessenger,	// 	NULL sends to be_app
		&lo_aref,
		0,
		false, 	// don't allow_multiple_selection
		new BMessage(LOAD_LOAD),
		NULL,
		false, 	// not modal
		true );	// hide_when_done

	savefilepanel = new BFilePanel(	//  Save requester
		B_SAVE_PANEL,
		loadmessenger,
		&sa_aref,
		0,
		false, 	// don't allow_multiple_selection
		new BMessage(LOAD_SAVE),
		NULL,
		false, 	// not modal
		true );	// hide_when_done

	BView* loadview = new BView(BRect(0,0,416,207), "loadview", B_FOLLOW_ALL, B_WILL_DRAW);

	// View and Radio Buttons 1
	BView* loadradio1 = new BView(BRect(15,23,80,93), "viewmodeview", B_FOLLOW_ALL, B_WILL_DRAW);

	loadadd1a = new BRadioButton(BRect(0,0,75,13),"loadadd1a","Left",		new BMessage(LOAD_RADIOA1));
	loadradio1->AddChild(loadadd1a);

	loadadd1b = new BRadioButton(BRect(0,14,75,27),"loadadd1b","Right",	new BMessage(LOAD_RADIOA2));
	loadradio1->AddChild(loadadd1b);

	loadadd1c = new BRadioButton(BRect(0,28,75,41),"loadadd1c","Stereo",	new BMessage(LOAD_RADIOA3));
	loadradio1->AddChild(loadadd1c);

	loadadd1d = new BRadioButton(BRect(0,42,75,55),"loadadd1d","Mono",		new BMessage(LOAD_RADIOA4));
	loadradio1->AddChild(loadadd1d);

	loadadd1e = new BRadioButton(BRect(0,56,75,68),"loadadd1e","As is",		new BMessage(LOAD_RADIOA5));
	loadradio1->AddChild(loadadd1e);
	
	loadradio1->SetViewColor(216,216,216);
	loadview->AddChild(loadradio1);

	// View and Radio Buttons 2
	BView* loadradio2 = new BView(BRect(137,23,247,93), "viewmodeview", B_FOLLOW_ALL, B_WILL_DRAW);

	loadadd2a = new BRadioButton(BRect(0,0,100,13),"loadadd2a","Left",	new BMessage(LOAD_RADIOB1));
	loadradio2->AddChild(loadadd2a);

	loadadd2b = new BRadioButton(BRect(0,14,100,27),"loadadd2b","Right",	new BMessage(LOAD_RADIOB2));
	loadradio2->AddChild(loadadd2b);

	loadadd2c = new BRadioButton(BRect(0,28,100,41),"loadadd2c","Stereo",	new BMessage(LOAD_RADIOB3));
	loadradio2->AddChild(loadadd2c);

	loadadd2d = new BRadioButton(BRect(0,42,100,55),"loadadd2d","Mono",		new BMessage(LOAD_RADIOB4));
	loadradio2->AddChild(loadadd2d);

	loadadd2e = new BRadioButton(BRect(0,56,100,68),"loadadd2e","As is",		new BMessage(LOAD_RADIOB5));
	loadradio2->AddChild(loadadd2e);

	loadradio2->SetViewColor(216,216,216);
	loadview->AddChild(loadradio2);

	// View and Radio Buttons for Range / Window selection
	BView* loadradio3 = new BView(BRect(15,120,125,150), "viewmodeview", B_FOLLOW_ALL, B_WILL_DRAW);

	loadrng = new BRadioButton(BRect(0,0,100,13),"loadrng","Range",	new BMessage(LOAD_RNG));
	loadradio3->AddChild(loadrng);

	loadall = new BRadioButton(BRect(0,14,100,27),"loadall","All",	new BMessage(LOAD_ALL));
	loadradio3->AddChild(loadall);

	loadradio3->SetViewColor(216,216,216);
	loadview->AddChild(loadradio3);

	// Loader / Saver List
	loadpick = new BListView(BRect(246,3,399,123),"loadpick",B_SINGLE_SELECTION_LIST,B_WILL_DRAW);
	loadpick->SetSelectionMessage(new BMessage(LOAD_PICK));
	
	loadpickparent = new BScrollView("loadpickparent",loadpick,0,0,false,true,B_PLAIN_BORDER);
	loadview->AddChild(loadpickparent);

	// LOAD button
	loadgo = new BButton(BRect(361,130,411,156), "LOAD", "LOAD",	new BMessage(LOAD_GO));
	loadgo->MakeDefault(1); // set as default for fancy surround
	loadgo->SetFont(be_bold_font);
	loadview->AddChild(loadgo);

	// Cancel button
	loadclose = new BButton(BRect(244,130,298,156), "CLOSE", "Close",	new BMessage(LOAD_CANCEL));
	loadview->AddChild(loadclose);

	loadtext1 = new BStringView(BRect(80,105,240,119), "loadtext1"," ", B_FOLLOW_ALL, B_WILL_DRAW);
	loadtext1->SetHighColor(0,0,0); // text to black
	loadview->AddChild(loadtext1);
	loadtext2 = new BStringView(BRect(80,120,240,134), "loadtext2"," ", B_FOLLOW_ALL, B_WILL_DRAW);
	loadtext2->SetHighColor(0,0,0); // text to black
	loadview->AddChild(loadtext2);
	loadtext3 = new BStringView(BRect(80,135,240,149), "loadtext3"," ", B_FOLLOW_ALL, B_WILL_DRAW);
	loadtext3->SetHighColor(0,0,0); // text to black
	loadview->AddChild(loadtext3);
	loadtext4 = new BStringView(BRect(80,150,240,164), "loadtext4"," ", B_FOLLOW_ALL, B_WILL_DRAW);
	loadtext4->SetHighColor(0,0,0); // text to black
	loadview->AddChild(loadtext4);

	// Message box
	BView* loadtextview = new BView(BRect(1,162,414,206), "fxtextview", B_FOLLOW_ALL, B_WILL_DRAW);

	loadtextgo = new BStringView(BRect(2,3,410,14), "loadtextgo","Welcome", B_FOLLOW_ALL, B_WILL_DRAW);
	loadtextgo->SetHighColor(255,255,255); // text to white
	loadtextview->AddChild(loadtextgo);

	loadtextgob = new BStringView(BRect(2,16,410,27), "loadtextgob","to the", B_FOLLOW_ALL, B_WILL_DRAW);
	loadtextgob->SetHighColor(255,255,255); // text to white
	loadtextview->AddChild(loadtextgob);

	loadtextgoc = new BStringView(BRect(2,29,410,40), "loadtextgoc","Pleasure dome", B_FOLLOW_ALL, B_WILL_DRAW);
	loadtextgoc->SetHighColor(255,255,255); // text to white
	loadtextview->AddChild(loadtextgoc);

	loadtextview->SetViewColor(0,0,0); // background to black
	loadview->AddChild(loadtextview);
	
	// set the view color to gray, add the view
	loadview->SetViewColor(216,216,216);
	AddChild(loadview);

	// Variable setup

	listnumber = 0;
	loadnumber = 0;

	loadinputL1 = 5;
	loadinputL2 = 5;
	loadinputL3 = 2;
	loadinputS1 = 5;
	loadinputS2 = 5;
	loadinputS3 = 2;
	
	// show the window
	Show();
	
	Lock();
	Drawlist(1,0);	// default to load

	Setvars(); // set up variable arrays
	Updateloadwindow(0,loadtype,loadnumber);  // update window
	Unlock();
}

// ------------------------------------------------------------------------

LOAD::~LOAD(void) // Destructor
{
	Drawlist(1,100);  // clear list
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

void LOAD::Drawlist(int16 option, int16 listtype)
{

Lock();

if (option == 0)	// clear list
	{
	loadpick->RemoveItems(0,9);
	}

// now draw new one

if (listtype == 0)	// Loaders
	{
	loadpick->AddItem(new BStringItem("AIFF"));
	loadpick->AddItem(new BStringItem("WAV"));
	loadpick->AddItem(new BStringItem("RAW 8 Mac / Amiga"));
	loadpick->AddItem(new BStringItem("RAW 8 PC"));
	loadpick->AddItem(new BStringItem("RAW 16 Mac / Amiga"));
	loadpick->AddItem(new BStringItem("RAW 16 PC"));
	loadpick->AddItem(new BStringItem("IFF"));
	loadpick->AddItem(new BStringItem("AU"));
	loadpick->AddItem(new BStringItem("SAFF"));
	loadpick->Select(listloadno);
	}

if (listtype == 1)	// Savers
	{
	loadpick->AddItem(new BStringItem("AIFF"));
	loadpick->AddItem(new BStringItem("WAV"));
	loadpick->AddItem(new BStringItem("RAW 8 Mac / Amiga"));
	loadpick->AddItem(new BStringItem("RAW 8 PC"));
	loadpick->AddItem(new BStringItem("RAW 16 Mac / Amiga"));
	loadpick->AddItem(new BStringItem("RAW 16 PC"));
	loadpick->AddItem(new BStringItem("IFF"));
	loadpick->AddItem(new BStringItem("AU"));
	loadpick->AddItem(new BStringItem("SAFF"));
	loadpick->Select(listsaveno);
	}

	loadpick->ScrollToSelection();

Unlock();
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

void LOAD::Setvars(void)
{
int16 setoutcount;
int16 setincount;

// set arrarys with default vals
for (setoutcount=0;setoutcount<=1;setoutcount++)
	{
	for (setincount=0;setincount<=9;setincount++)
		{
		sprintf(loadboxtxt[setoutcount][setincount][0], " ");
		sprintf(loadboxtxt[setoutcount][setincount][1], " ");
		sprintf(loadboxtxt[setoutcount][setincount][2], " ");
		}
	}

for (setincount=0;setincount<=9;setincount++)
	{
	Setloadvars(setincount);
	Setsavevars(setincount);
	}
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************
// Set individual Loader vars

void LOAD::Setloadvars(int16 incount)	// LOAD
{

if (incount == 0)	//	AIFF
	{
	sprintf(loadboxtxt[0][incount][0], "Audio Interchange File Format");
	sprintf(loadboxtxt[0][incount][1], ".aif   .aiff");
	sprintf(loadboxtxt[0][incount][2], "Apple Macintosh native audio format");
	loadvals[0][incount][0] = 0;	//	byteswap
	loadvals[0][incount][1] = 16;	//	bits
	loadvals[0][incount][2] = 1;	//	translate
	}

if (incount == 1)	//	WAV
	{
	sprintf(loadboxtxt[0][incount][0], "WAVE");
	sprintf(loadboxtxt[0][incount][1], "WAV   .wav   also known as RIFF");
	sprintf(loadboxtxt[0][incount][2], "Windows native audio format");
	loadvals[0][incount][0] = 1;	//	byteswap
	loadvals[0][incount][1] = 16;	//	bits
	loadvals[0][incount][2] = 1;	//	translate
	}

if (incount == 2)	//	RAW 8 Mac/Amiga
	{
	sprintf(loadboxtxt[0][incount][0], "RAW 8 bit data from Mac or Amiga");
	sprintf(loadboxtxt[0][incount][1], " ");
	sprintf(loadboxtxt[0][incount][2], "Signed");
	loadvals[0][incount][0] = 0;	//	byteswap
	loadvals[0][incount][1] = 8;	//	bits
	loadvals[0][incount][2] = 0;	//	translate
	}

if (incount == 3)	//	RAW 8 PC
	{
	sprintf(loadboxtxt[0][incount][0], "RAW 8 bit data from PC");
	sprintf(loadboxtxt[0][incount][1], " ");
	sprintf(loadboxtxt[0][incount][2], "Unsigned");
	loadvals[0][incount][0] = 1;	//	byteswap
	loadvals[0][incount][1] = 8;	//	bits
	loadvals[0][incount][2] = 0;	//	translate
	}

if (incount == 4)	//	RAW 16 Mac/Amiga
	{
	sprintf(loadboxtxt[0][incount][0], "RAW 16 bit data from Mac or Amiga");
	sprintf(loadboxtxt[0][incount][1], " ");
	sprintf(loadboxtxt[0][incount][2], "Most Significant Byte first");
	loadvals[0][incount][0] = 1;	//	byteswap
	loadvals[0][incount][1] = 16;	//	bits
	loadvals[0][incount][2] = 0;	//	translate
	}

if (incount == 5)	//	RAW 16 PC
	{
	sprintf(loadboxtxt[0][incount][0], "RAW 16 bit data from PC");
	sprintf(loadboxtxt[0][incount][1], " ");
	sprintf(loadboxtxt[0][incount][2], "Least Significant Byte first");
	loadvals[0][incount][0] = 0;	//	byteswap
	loadvals[0][incount][1] = 16;	//	bits
	loadvals[0][incount][2] = 0;	//	translate
	}

if (incount == 6)	//	IFF
	{
	sprintf(loadboxtxt[0][incount][0], "Interchange File Format");
	sprintf(loadboxtxt[0][incount][1], ".iff");
	sprintf(loadboxtxt[0][incount][2], "Amiga native audio format, 8 bit only");
	loadvals[0][incount][0] = 0;	//	byteswap
	loadvals[0][incount][1] = 8;	//	bits
	loadvals[0][incount][2] = 1;	//	translate
	}

if (incount == 7)	//	AU
	{
	sprintf(loadboxtxt[0][incount][0], "AU");
	sprintf(loadboxtxt[0][incount][1], ".au");
	sprintf(loadboxtxt[0][incount][2], "Unix (various types) native audio format");
	loadvals[0][incount][0] = 0;	//	byteswap
	loadvals[0][incount][1] = 8;	//	bits
	loadvals[0][incount][2] = 1;	//	translate
	}

if (incount == 8)	//	SAFF
	{
	sprintf(loadboxtxt[0][incount][0], "Simple Audio File Format   ");
	sprintf(loadboxtxt[0][incount][1], ".saff");
	sprintf(loadboxtxt[0][incount][2], "Native to Aural illusion");
	loadvals[0][incount][0] = 0;	//	byteswap
	loadvals[0][incount][1] = 16;	//	bits
	loadvals[0][incount][2] = 0;	//	translate
	}

if (incount >= 9)	//	Blank
	{
	sprintf(loadboxtxt[0][incount][0], " ");
	sprintf(loadboxtxt[0][incount][1], " ");
	sprintf(loadboxtxt[0][incount][2], " ");
	loadvals[0][incount][0] = 0;	//	byteswap
	loadvals[0][incount][1] = 16;	//	bits
	loadvals[0][incount][2] = 0;	//	translate
	}
	
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************
// Set individual Loader vars

void LOAD::Setsavevars(int16 incount)	// SAVE
{

if (incount == 0)	//	AIFF
	{
	sprintf(loadboxtxt[1][incount][0], "Audio Interchange File Format");
	sprintf(loadboxtxt[1][incount][1], ".aif   .aiff");
	sprintf(loadboxtxt[1][incount][2], "Apple Macintosh native audio format");
	loadvals[1][incount][0] = 0;	//	byteswap
	loadvals[1][incount][1] = 16;	//	bits
	loadvals[1][incount][2] = 1;	//	translate
	}

if (incount == 1)	//	WAV
	{
	sprintf(loadboxtxt[1][incount][0], "WAVE");
	sprintf(loadboxtxt[1][incount][1], "WAV   .wav   also known as RIFF");
	sprintf(loadboxtxt[1][incount][2], "Windows native audio format");
	loadvals[1][incount][0] = 1;	//	byteswap
	loadvals[1][incount][1] = 16;	//	bits
	loadvals[1][incount][2] = 1;	//	translate
	}

if (incount == 2)	//	RAW 8 Mac/Amiga
	{
	sprintf(loadboxtxt[1][incount][0], "RAW 8 bit data from Mac or Amiga");
	sprintf(loadboxtxt[1][incount][1], " ");
	sprintf(loadboxtxt[1][incount][2], "Signed");
	loadvals[1][incount][0] = 0;	//	byteswap
	loadvals[1][incount][1] = 8;	//	bits
	loadvals[1][incount][2] = 0;	//	translate
	}

if (incount == 3)	//	RAW 8 PC
	{
	sprintf(loadboxtxt[1][incount][0], "RAW 8 bit data from PC");
	sprintf(loadboxtxt[1][incount][1], " ");
	sprintf(loadboxtxt[1][incount][2], "Unsigned");
	loadvals[1][incount][0] = 1;	//	byteswap
	loadvals[1][incount][1] = 8;	//	bits
	loadvals[1][incount][2] = 0;	//	translate
	}

if (incount == 4)	//	RAW 16 Mac/Amiga
	{
	sprintf(loadboxtxt[1][incount][0], "RAW 16 bit data from Mac or Amiga");
	sprintf(loadboxtxt[1][incount][1], " ");
	sprintf(loadboxtxt[1][incount][2], "Most Significant Byte first");
	loadvals[1][incount][0] = 1;	//	byteswap
	loadvals[1][incount][1] = 16;	//	bits
	loadvals[1][incount][2] = 0;	//	translate
	}

if (incount == 5)	//	RAW 16 PC
	{
	sprintf(loadboxtxt[1][incount][0], "RAW 16 bit data from PC");
	sprintf(loadboxtxt[1][incount][1], " ");
	sprintf(loadboxtxt[1][incount][2], "Least Significant Byte first");
	loadvals[1][incount][0] = 0;	//	byteswap
	loadvals[1][incount][1] = 16;	//	bits
	loadvals[1][incount][2] = 0;	//	translate
	}

if (incount == 6)	//	IFF
	{
	sprintf(loadboxtxt[1][incount][0], "Interchange File Format");
	sprintf(loadboxtxt[1][incount][1], ".iff");
	sprintf(loadboxtxt[1][incount][2], "Amiga native audio format, 8 bit only");
	loadvals[1][incount][0] = 0;	//	byteswap
	loadvals[1][incount][1] = 8;	//	bits
	loadvals[1][incount][2] = 1;	//	translate
	}

if (incount == 7)	//	AU
	{
	sprintf(loadboxtxt[1][incount][0], "AU");
	sprintf(loadboxtxt[1][incount][1], ".au");
	sprintf(loadboxtxt[1][incount][2], "Unix (various types) native audio format");
	loadvals[1][incount][0] = 0;	//	byteswap
	loadvals[1][incount][1] = 8;	//	bits
	loadvals[1][incount][2] = 1;	//	translate
	}

if (incount == 8)	//	SAFF
	{
	sprintf(loadboxtxt[1][incount][0], "Simple Audio File Format   ");
	sprintf(loadboxtxt[1][incount][1], ".saff");
	sprintf(loadboxtxt[1][incount][2], "Native to Aural illusion");
	loadvals[1][incount][0] = 0;	//	byteswap
	loadvals[1][incount][1] = 16;	//	bits
	loadvals[1][incount][2] = 1;	//	translate
	}

if (incount >= 9)	//	Blank
	{
	sprintf(loadboxtxt[1][incount][0], " ");
	sprintf(loadboxtxt[1][incount][1], " ");
	sprintf(loadboxtxt[1][incount][2], " ");
	loadvals[1][incount][0] = 0;	//	byteswap
	loadvals[1][incount][1] = 16;	//	bits
	loadvals[1][incount][2] = 1;	//	translate
	}

}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

void LOAD::Updateloadwindow(int32 mess_no, int32 loadtype, int32 loadnumber)
{
// Update window

Lock();

if (loadtype == 0)
	{
	if ((listloadno > 1) && (listloadno < 6))
		{
		loadadd1e->SetEnabled(0);
		loadadd2e->SetEnabled(0);
		if (loadinputL1 == 5) loadinputL1 = 3;
		if (loadinputL2 == 5) loadinputL2 = 3;
		}
	if ((listloadno < 2) || (listloadno > 5))
		{
		loadadd1e->SetEnabled(1);
		loadadd2e->SetEnabled(1);
		}

	if (loadinputL1 == 1)	loadadd1a->SetValue(1);
	if (loadinputL1 == 2)	loadadd1b->SetValue(1);
	if (loadinputL1 == 3)	loadadd1c->SetValue(1);
	if (loadinputL1 == 4)	loadadd1d->SetValue(1);
	if (loadinputL1 == 5)	loadadd1e->SetValue(1);

	if (loadinputL2 == 1)	loadadd2a->SetValue(1);
	if (loadinputL2 == 2)	loadadd2b->SetValue(1);
	if (loadinputL2 == 3)	loadadd2c->SetValue(1);
	if (loadinputL2 == 4)	loadadd2d->SetValue(1);
	if (loadinputL2 == 5)	loadadd2e->SetValue(1);

	if (loadinputL3 == 1)	loadrng->SetValue(1);
	if (loadinputL3 == 2)	loadall->SetValue(1);

	SetTitle("Load Sample");
	loadgo->SetLabel("LOAD");

	loadtextgo->SetText(loadboxtxt[0][loadnumber][0]); // Message Box
	loadtextgob->SetText(loadboxtxt[0][loadnumber][1]);
	loadtextgoc->SetText(loadboxtxt[0][loadnumber][2]);
	lbyteswap 	= loadvals[0][loadnumber][0];
	lbits 		= loadvals[0][loadnumber][1];
	ltranslate 	= loadvals[0][loadnumber][2];

//sprintf(loadtexttest[0],"%d",lbyteswap);
//sprintf(loadtexttest[1],"%d",lbits);
//sprintf(loadtexttest[2],"%d",ltranslate);
	}

else if (loadtype == 1)
	{
	if ((listsaveno > 1) && (listsaveno < 6))
		{
		loadadd1e->SetEnabled(0);
		loadadd2e->SetEnabled(0);
		if (loadinputS1 == 5) loadinputS1 = 3;
		if (loadinputS2 == 5) loadinputS2 = 3;
		}
	if ((listsaveno < 2) || (listsaveno > 5))
		{
		loadadd1e->SetEnabled(1);
		loadadd2e->SetEnabled(1);
		}

	if (loadinputS1 == 1)	loadadd1a->SetValue(1);
	if (loadinputS1 == 2)	loadadd1b->SetValue(1);
	if (loadinputS1 == 3)	loadadd1c->SetValue(1);
	if (loadinputS1 == 4)	loadadd1d->SetValue(1);
	if (loadinputS1 == 5)	loadadd1e->SetValue(1);

	if (loadinputS2 == 1)	loadadd2a->SetValue(1);
	if (loadinputS2 == 2)	loadadd2b->SetValue(1);
	if (loadinputS2 == 3)	loadadd2c->SetValue(1);
	if (loadinputS2 == 4)	loadadd2d->SetValue(1);
	if (loadinputS2 == 5)	loadadd2e->SetValue(1);

	if (loadinputS3 == 1)	loadrng->SetValue(1);
	if (loadinputS3 == 2)	loadall->SetValue(1);

	SetTitle("Save Sample");
	loadgo->SetLabel("SAVE");

	loadtextgo->SetText(loadboxtxt[1][loadnumber][0]);
	loadtextgob->SetText(loadboxtxt[1][loadnumber][1]);
	loadtextgoc->SetText(loadboxtxt[1][loadnumber][2]);
	sbyteswap 	= loadvals[1][loadnumber][0];
	sbits 		= loadvals[1][loadnumber][1];
	stranslate 	= loadvals[1][loadnumber][2];

//sprintf(loadtexttest[0],"%d",sbyteswap);
//sprintf(loadtexttest[1],"%d",sbits);
//sprintf(loadtexttest[2],"%d",stranslate);
	}
loadtextgo->SetText(loadtexttest[0]);
loadtextgob->SetText(loadtexttest[1]);
loadtextgoc->SetText(loadtexttest[2]);

Unlock();

}


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

void LOAD::Updatedonebox(int16 drawmode, int16 drawmax, int16 drawnum)
{
BMessage *msg = new BMessage(FXR_DRAWBAR);
msg->AddInt16("apbar1", drawmode);
msg->AddInt16("apbar2", drawmax);
msg->AddInt16("apbar3", drawnum);
msg->AddInt16("apbar4", 0);
msg->AddInt16("apbar5", 0);
msg->AddInt16("apbar6", 0);
be_app->PostMessage(msg,be_app);
delete (msg);
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

void LOAD::Clickedloadwindow(int32 mess_no)
{
int16 number;

int32 listselected;
static char numbertxt[5];

Lock();

// Remember clicking any of these will 
// reset the current selected LOADER / SAVER
// in the EDIT window

if (mess_no == 1)  // RadioA1
 	{
 	if (loadtype == 0)
 		{
 		loadinputL1=1;
 		}
 	else loadinputS1=1;
 	}
 	
if (mess_no == 2) // RadioA2
 	{
 	if (loadtype == 0)
 		{
 		loadinputL1=2;
 		}
 	else loadinputS1=2;
 	}

if (mess_no == 3) // RadioA3
 	{
 	if (loadtype == 0)
 		{
 		loadinputL1=3;
 		}
 	else loadinputS1=3;
 	}

if (mess_no == 4) // RadioA4
 	{
 	if (loadtype == 0)
 		{
 		loadinputL1=4;
 		}
 	else loadinputS1=4;
 	}

if (mess_no == 5)  // RadioA5
 	{
 	if (loadtype == 0)
 		{
 		loadinputL1=5;
 		}
 	else loadinputS1=5;
 	}
 	
if (mess_no == 6) // RadioB1
 	{
 	if (loadtype == 0)
 		{
 		loadinputL2=1;
 		}
 	else loadinputS2=1;
 	}

if (mess_no == 7) // RadioB2
 	{
 	if (loadtype == 0)
 		{
 		loadinputL2=2;
 		}
 	else loadinputS2=2;
 	}

if (mess_no == 8) // RadioB3
 	{
 	if (loadtype == 0)
 		{
 		loadinputL2=3;
 		}
 	else loadinputS2=3;
 	}

if (mess_no == 9) // RadioB4
 	{
 	if (loadtype == 0)
 		{
 		loadinputL2=4;
 		}
 	else loadinputS2=4;
 	}

if (mess_no == 10) // RadioB5
 	{
 	if (loadtype == 0)
 		{
 		loadinputL2=5;
 		}
 	else loadinputS2=5;
 	}

if (mess_no == 11) // Load Range
 	{
 	if (loadtype == 0)
 		{
 		loadinputL3=1;
 		}
 	else loadinputS3=1;
 	}

if (mess_no == 12) // Load All
 	{
 	if (loadtype == 0)
 		{
 		loadinputL3=2;
 		}
 	else loadinputS3=2;
 	}

if (mess_no == 13) //  Loader/Saver Selected
	{
	listselected = loadpick->CurrentSelection(0);
	listnumber = listselected;
	if (loadtype == 0)	listloadno = listnumber;
	if (loadtype == 1)	listsaveno = listnumber;
	Updateloadwindow(0, loadtype, listnumber);
	}

if (mess_no == 14) // GO (LOAD/SAVE) Pressed
	{
	if (loadtype == 0)	loadfilepanel->Show();
	if (loadtype == 1)	savefilepanel->Show();
	}

if (mess_no == 15) // Cancel
 	{
 	Hide();
 	}

Unlock();
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

// Handling of user interface and other events
void LOAD::MessageReceived(BMessage *message)
{
//	message->PrintToStream();
//	BWindow::MessageReceived(message);

	switch(message->what){

		case LOAD_RADIOA1:
		Clickedloadwindow(1);
		break;

		case LOAD_RADIOA2:
		Clickedloadwindow(2);
		break;

		case LOAD_RADIOA3:
		Clickedloadwindow(3);
		break;

		case LOAD_RADIOA4:
		Clickedloadwindow(4);
		break;

		case LOAD_RADIOA5:
		Clickedloadwindow(5);
		break;

		case LOAD_RADIOB1:
		Clickedloadwindow(6);
		break;

		case LOAD_RADIOB2:
		Clickedloadwindow(7);
		break;

		case LOAD_RADIOB3:
		Clickedloadwindow(8);
		break;

		case LOAD_RADIOB4:
		Clickedloadwindow(9);
		break;

		case LOAD_RADIOB5:
		Clickedloadwindow(10);
		break;

		case LOAD_RNG:
		Clickedloadwindow(11);
		break;

		case LOAD_ALL:
		Clickedloadwindow(12);
		break;

		case LOAD_PICK:
		Clickedloadwindow(13);
		break;

		case LOAD_GO:
		Clickedloadwindow(14);
		break;

		case LOAD_CANCEL:
		Clickedloadwindow(15);
		break;

// Messages from elsewhere

		case APP_LOAD:
		message->FindInt32("loadorsave", &loadtype);
		Drawlist(0, loadtype);
		Updateloadwindow(0,loadtype,loadnumber);
		break;

		case APP_SAVE:
		message->FindInt32("loadorsave", &loadtype);
		Drawlist(0, loadtype);
		Updateloadwindow(0,loadtype,loadnumber);
		break;

		case APP_LOADDATA:		// Select mode
		message->FindPointer("appoint", &loadvpoint);
		message->FindInt32("chanmode", &loadmakechans);
		message->FindInt32("halfmemsize", &tloadhalfmemsize);
		message->FindInt32("samstart", &tloadsamstart);
		message->FindInt32("samend", &tloadsamend);
		message->FindInt32("samlen", &tloadsamlen);
		loadpoint = (int16 *)loadvpoint;		// Convert this to 16 bit pointer
		loadhalfmemsize=tloadhalfmemsize;
		loadmemsize=loadhalfmemsize << 1;
		loadsamstart=tloadsamstart;
		loadsamend=tloadsamend;
		loadsamlen=tloadsamlen;
		if (loadtype == 0) Loaddata();
		if (loadtype == 1) Savedata();
//		Drawlist(0, loadtype);
//		Updateloadwindow(0,loadtype,loadnumber);
		break;

	case LOAD_LOAD:	// Load a Sample
		message->FindRef("refs",&lo_aref);
		be_app->PostMessage(LOAD_REQUESTDATA,be_app);	// As App for details
		break;

	case LOAD_SAVE:	// Save a Sample
		message->FindRef("directory",&sa_aref);
		message->FindString("name",&sa_filename);
		be_app->PostMessage(LOAD_REQUESTDATA,be_app);	// As App for details
		break;

		default:
			inherited::MessageReceived(message);
			break;
	}
}

	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void LOAD::Loaddata(void)	// Load a sample
{
void * bufferstart;
size_t len;
bool test;
ssize_t readnum;
int16* lo_appoint;

uint32 incount=0;
uint32 samcount=0;
uint32 quartlen=0;
uint32 quartval=0;
uint32 maincount=0;
uint32 current=0;
uint32 leftcount=0;
uint32 rightcount=0;
uint32 mainstart=0;
uint32 mainend=0;
uint32 mainlen=0;

uint32 displaycount=0;
uint32 display=0;
int16 done=0;
int16 wordval=0;
int8  byteval=0;
int16 tempval=0;
int32 temp=0;
int32 tempb=0;
int32 loadmode=0;
int32 loadstereo=0;
int8 *load8bitpoint;

area_id load_area; // memory area used for loading

// Create an area.
load_area = create_area("my area",	// name you give to the area
(void **)&bufferpoint,				// returns the starting addr
B_ANY_ADDRESS,						// area can start anywhere
131072,								// size in bytes
B_FULL_LOCK,						// Lock in RAM? Yes  - B_NO_LOCK = No
B_READ_AREA | B_WRITE_AREA);		// permissions

sprintf(loadtexttest[0]," ");
sprintf(loadtexttest[1]," ");
sprintf(loadtexttest[2]," ");
loadtextgo->SetText(loadtexttest[0]);
loadtextgob->SetText(loadtexttest[1]);
loadtextgoc->SetText(loadtexttest[2]);

if (loadinputL3 == 1)	//	1	Load Range
	{
	mainstart = loadsamstart;
	mainend = loadsamend;
	}

if (loadinputL3 == 2)	//	2	Load All
	{
	mainstart = 0;
	mainend = loadmemsize;
	}
sprintf(loadtexttest[0],"loadinputL3=%d  loadmemsize=%d",loadinputL3,loadmemsize);
loadtextgo->SetText(loadtexttest[0]);
sprintf(loadtexttest[1],"mainstart=%d  mainend=%d",mainstart,mainend);
loadtextgob->SetText(loadtexttest[1]);

if (loadinputL1 == 1)	//	Load Left
	{
	if (loadinputL2 == 1)
		{
		loadmode = 1;
		}
	if (loadinputL2 == 2)
		{
		loadmode = 2;
		}
	if (loadinputL2 == 3)
		{
		loadmode = 3;
		}
	if (loadinputL2 == 4)
		{
		loadmode = 4;
		}
	}
else if (loadinputL1 == 2)	//	Load Right
	{
	if (loadinputL2 == 1)
		{
		loadmode = 5;
		}
	if (loadinputL2 == 2)
		{
		loadmode = 6;
		}
	if (loadinputL2 == 3)
		{
		loadmode = 7;
		}
	if (loadinputL2 == 4)
		{
		loadmode = 8;
		}
	}
else if (loadinputL1 == 3)	//	Load Stereo
	{
	if (loadinputL2 == 1)
		{
		loadmode = 9;
		}
	if (loadinputL2 == 2)
		{
		loadmode = 10;
		}
	if (loadinputL2 == 3)
		{
		loadmode = 11;
		}
	if (loadinputL2 == 4)
		{
		loadmode = 12;
		}
	}
else if (loadinputL1 == 4)	//	Load Mono
	{
	if (loadinputL2 == 1)
		{
		loadmode = 13;
		}
	if (loadinputL2 == 2)
		{
		loadmode = 14;
		}
	if (loadinputL2 == 3)
		{
		loadmode = 15;
		}
	if (loadinputL2 == 4)
		{
		loadmode = 16;
		}
	}
loadstereo = 1;
if ((loadmode == 4) || (loadmode == 8) || (loadmode == 12) || (loadmode == 16))	loadstereo = 0;

if (ltranslate == 1)
	{		//	Call Translator here to determine
			//	new loadmode, loadstereo bits
	}		//	bits and byteswap


load8bitpoint = (int8 *)bufferpoint;
bufferstart = (void *)bufferpoint;
len = (size_t)131072;

// ***************************************************************************************************
/*
status_t err;
entry_ref ref;
BMediaFile *mediaFile;
BMediaTrack *track = NULL, *audtrack = NULL;
int32 i=0, numTracks=0;

char *chunk;
char *bitmap = NULL, *sound_buffer = NULL;
bool found_audio_encoder = false;
bool found_family;
int32 sz=0, cookie=0;
int64 numFrames=0, j=0;
int64 framesize=0;
BMediaTrack *aud = NULL;
media_format format, outfmt;
media_codec_info mci;
media_file_format mfi;
media_header mh;
int64 framecount = 0;

int32 smallnumFrames=0;
int32 smallframesize=0;
int32 smallframecount=0;
int32 smallcount=0;

mediaFile = new BMediaFile(&lo_aref);
err = mediaFile->InitCheck();

if (err != B_OK)
	{
	sprintf(loadtexttest[0],"cannot contruct BMediaFile %s\\n",strerror(err));
	loadtextgo->SetText(loadtexttest[0]);
	}
else if (err == B_OK)
	{  // err = B_OK
	numTracks = mediaFile->CountTracks();

	for(i=0; i < numTracks; i++)
		{
		track = mediaFile->TrackAt(i);
		if (!track)
			{
			sprintf(loadtexttest[1],"can't get track %d of %d",i,numTracks);
			loadtextgob->SetText(loadtexttest[1]);
			}
		else
			{  // == track
			err = track->EncodedFormat(&format);//			get the encoded format 
			if (err != B_OK)
				{
				sprintf(loadtexttest[2],"encode error %s",strerror(err));
				loadtextgoc->SetText(loadtexttest[2]);
//				printf("BMediaTrack::EncodedFormat error -- %s\\n", strerror(err));
				}
			else // err == B_OK
				{
				if (format.type == B_MEDIA_RAW_AUDIO || format.type == B_MEDIA_ENCODED_AUDIO)
					{
					audtrack = track;
					if (audtrack == NULL)
						{ 
						sprintf(loadtexttest[2],"no audio tracks");
						loadtextgoc->SetText(loadtexttest[2]);
						}
					else 
						{
						format.type = B_MEDIA_RAW_AUDIO;
						err = audtrack->DecodedFormat(&format);	// this is the foul up!
//						I want  B_MEDIA_RAW_AUDIO
						if (err == B_OK)
						{
						sound_buffer = (char*)malloc(format.u.raw_audio.buffer_size);
						framesize = (format.u.raw_audio.format&15)*format.u.raw_audio.channel_count;
						smallframesize=(int32)framesize;
//						sprintf(loadtexttest[0],"audtrack found, numtracks=%d  framesize=%d",numTracks,smallframesize);
//						loadtextgo->SetText(loadtexttest[0]);

						lo_appoint = (int16 *)sound_buffer;	
						numFrames = audtrack->CountFrames();
						smallnumFrames=(int32)numFrames;
						if (numFrames > 0)
						{
//						sprintf(loadtexttest[1],"j=%d   numFrames=%d  framecount=%d",j,smallnumFrames,framecount);
//						loadtextgob->SetText(loadtexttest[1]);

//						for (j = 0; j < 10000; j++)
//							{
//							*(loadpoint+j)	= *(lo_appoint+j);
//							}
	
						for (j = 0; j < numFrames; j+=framecount)
							{
							err = audtrack->ReadFrames(sound_buffer, &framecount, &mh);
							if (err == B_OK)
								{
								*(loadpoint+smallcount)	= *(lo_appoint);
								smallcount++;
								}
							}

//						framecount = 0;
//						smallframecount=(int32)framecount;
//						sprintf(loadtexttest[2],"i=%d  j=%d   numFrames=%d  framecount=%d",i,j,smallnumFrames,smallframecount);
//						loadtextgob->SetText(loadtexttest[2]);
						}
						}
						}	// if audtrack
					} // format.type OK
				else
					{
					mediaFile->ReleaseTrack(track);
					track = NULL;
					}
				} // encoded format = B_OK
			} // track
		}	// for i ...
	} // err = B_OK

sprintf(loadtexttest[2],"Tracks=%d Frames=%d Framesize=%d i=%d j=%d framecount=%d scount=%d"
						,numTracks,smallnumFrames,smallframesize,i,j,smallframecount,smallcount);
loadtextgoc->SetText(loadtexttest[2]);


//				else
//					{
//					printf("processing chunks...\\n");
//					while (true)
//						{
//						numFrames = audtrack->CountFrames();
//						err = audtrack->ReadFrames(sound_buffer, &framecount, &mh);
//						if (err)
//							{
//							sprintf(loadtexttest[2],"j=%d   No Frames=%d  framecount=%d",j,numFrames,framecount);
//							loadtextgoc->SetText(loadtexttest[2]);
//							printf("audio: GetNextChunk error -- %s\\n", strerror(err));
//							break;
//							}
//						}
//					}


//Once loading the audio is done, there's very little left to do but release the
//audio buffers we've allocated, close the output BMediaFile, and delete it.

if (sound_buffer) free(sound_buffer);

//After this function returns, the caller is responsible for deleting the source BMediaFile.

delete mediaFile;

*/
// ***************************************************************************************************
//if (test == true)	// old 
//	{
//	Hide();
//	incount=0;	// Comvert to Interleaved Stereo
//	for (samcount=0;samcount<loadmemsize;samcount=samcount+2)	// to undo buffer
//		{
//		*(loadpoint+loadmemsize+samcount)	= *(loadpoint+incount);
//		*(loadpoint+loadmemsize+samcount+1)	= *(loadpoint+incount+loadhalfmemsize);
//		incount++;
//		}
//	for (samcount=0;samcount<=loadmemsize;samcount++)	// from undo buffer
//		{
//		*(loadpoint+samcount)	= *(loadpoint+samcount+loadmemsize);
//		}
//	}

// ***************************************************************************************************

//	sprintf(loadtexttest[0],"%d",lbyteswap);
//	sprintf(loadtexttest[1],"%d",lbits);
//	sprintf(loadtexttest[2],"%d",ltranslate);
//	loadtextgo->SetText(loadtexttest[0]);
//	loadtextgob->SetText(loadtexttest[1]);
//	loadtextgoc->SetText(loadtexttest[2]);


lo_afile = new BFile(&lo_aref,B_READ_ONLY);
test=lo_afile->IsReadable();

if (test == true)
	{
	if (loadstereo == 1)
		{
		if (mainstart >= loadhalfmemsize)
			{
			mainstart = mainstart - loadhalfmemsize;
			mainend = mainend - loadhalfmemsize;
			}
		if (mainend > loadhalfmemsize)	mainend = loadhalfmemsize;
		}

	if ((loadmode == 1) || (loadmode == 5) || (loadmode == 9) || (loadmode == 13))
		{
		for (samcount=mainstart;samcount<=mainend;samcount++)	// Zero Left
			{
			*(loadpoint+samcount) = 0;
			}
		}
	if ((loadmode == 2) || (loadmode == 6) || (loadmode == 10) || (loadmode == 14))
		{
		for (samcount=mainstart;samcount<=mainend;samcount++)	// Zero Right
			{
			*(loadpoint+samcount+loadhalfmemsize) = 0;
			}
		}
	if ((loadmode == 3) || (loadmode == 7) || (loadmode == 11) || (loadmode == 15))
		{
		for (samcount=mainstart;samcount<=mainend;samcount++)	// Zero Stereo
			{
			*(loadpoint+samcount) = 0;
			*(loadpoint+samcount+loadhalfmemsize) = 0;
			}
		}
	if ((loadmode == 4) || (loadmode == 8) || (loadmode == 12) || (loadmode == 16))
		{
		for (samcount=mainstart;samcount<=mainend;samcount++)	// Zero Mono
			{
			*(loadpoint+samcount) = 0;
			}
		}

maincount = 0;

	if (lbits == 16)	// --------------------------------------------------------------------------
		{			// 16 BIT LOADERS
		if ((loadmode >= 0) && (loadmode <= 12)) quartval = 32767;
		if ((loadmode >= 13) && (loadmode <= 16)) quartval = 65535;
		quartlen = quartval;
		mainlen = mainend-mainstart;
		display=mainlen >> 5;
		displaycount=display+mainstart;
		done=1;
		current=0;
		leftcount=mainstart;
		rightcount=mainstart+loadhalfmemsize;
		while (maincount<mainend)
			{
			for (samcount=0;samcount<=65535;samcount++)	// zero load buffer
				{
				*(bufferpoint+samcount) = 0;
				}
			readnum = lo_afile->Read(bufferstart,len);	//	read 128KB to load buffer
			if (readnum == 0)
				{
				maincount = mainend;
				samcount = quartlen;
				Updatedonebox(2,32,32);
				}
			if (lbyteswap == 1)	// Swap bytes if necessary
				{
				for (samcount=0;samcount<=65535;samcount++)
					{
					tempval=*(bufferpoint+samcount);
					byteval=tempval;
					wordval=byteval;
					wordval=wordval << 8;
					tempval=tempval >> 8;
					tempval=tempval + wordval;
					*(bufferpoint+samcount)=tempval;
					}
				}
			incount=0;
			if (loadmode == 1)	// LEFT to LEFT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount);
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 2)	// LEFT to RIGHT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+rightcount)			= *(bufferpoint+incount);
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 3)	// LEFT to STEREO
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount);
					*(loadpoint+rightcount)			= *(bufferpoint+incount);
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 4)	// LEFT to MONO	// STOP AT FULL MEMSIZE
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount);
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 5)	// RIGHT to LEFT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount+1);
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 6)	// RIGHT to RIGHT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+rightcount)			= *(bufferpoint+incount+1);
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 7)	// RIGHT to STEREO
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount+1);
					*(loadpoint+rightcount)			= *(bufferpoint+incount+1);
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 8)	// RIGHT to MONO	// STOP AT FULL MEMSIZE
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount+1);
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 9)	// STEREO to LEFT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp=*(bufferpoint+incount);
					temp=temp + *(bufferpoint+incount+1);
					temp = temp >> 1;
					*(loadpoint+leftcount)			= temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 10)	// STEREO to RIGHT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp=*(bufferpoint+incount);
					temp=temp + *(bufferpoint+incount+1);
					temp = temp >> 1;
					*(loadpoint+rightcount)			= temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 11)	// STEREO to STEREO
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount);
					*(loadpoint+rightcount)			= *(bufferpoint+incount+1);
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 12)	// STEREO to MONO	// STOP AT FULL MEMSIZE
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp=*(bufferpoint+incount);
					temp=temp + *(bufferpoint+incount+1);
					temp = temp >> 1;
					*(loadpoint+leftcount)			= temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 13)	// MONO to LEFT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount);
					incount++;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 14)	// MONO to RIGHT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+rightcount)			= *(bufferpoint+incount);
					incount++;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 15)	// MONO to STEREO
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount);
					*(loadpoint+rightcount)			= *(bufferpoint+incount);
					incount++;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 16)	// MONO to MONO	// STOP AT FULL MEMSIZE
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(loadpoint+leftcount)			= *(bufferpoint+incount);
					incount++;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			current=samcount;
			quartlen = quartlen+quartval;
			}
		}
// --------------------------------------------------------------------------
// --------------------------------------------------------//	8 BIT LOADERS
// --------------------------------------------------------------------------
	if (lbits == 8)
		{			
		if ((loadmode >= 0) && (loadmode <= 12)) quartval = 65535;
		if ((loadmode >= 13) && (loadmode <= 16)) quartval = 131071;
		quartlen = quartval;
		mainlen = mainend-mainstart;
		display=mainlen >> 5;
		displaycount=display+mainstart;
		done=1;
		current=0;
		leftcount=mainstart;
		rightcount=mainstart+loadhalfmemsize;
		while (maincount<mainend)
			{
			for (samcount=0;samcount<=65535;samcount++)	// zero load buffer
				{
				*(bufferpoint+samcount) = 0;
				}
			readnum = lo_afile->Read(bufferstart,len);	//	read 128KB to load buffer
			if (readnum == 0)
				{
				maincount = mainend;
				samcount = quartlen;
				Updatedonebox(2,32,32);
				}
			if (lbyteswap == 1)	// Change from Unsigned if nexessary
				{
				for (samcount=0;samcount<=131071;samcount++)
					{
					temp = *(load8bitpoint+samcount);
					temp = temp << 8;
					if (temp>0) temp=temp-32766;
					else if (temp<0) temp=temp+32766;
					temp = temp >> 8;
					*(load8bitpoint+samcount) = temp;
					}
				}
			incount=0;
			if (loadmode == 1)	// LEFT to LEFT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 2)	// LEFT to RIGHT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+rightcount)	=	temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 3)	// LEFT to STEREO	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					*(loadpoint+rightcount)	=	temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 4)	// LEFT to MONO	// STOP AT FULL MEMSIZE	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 5)	// RIGHT to LEFT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+leftcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 6)	// RIGHT to RIGHT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+rightcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 7)	// RIGHT to STEREO	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+leftcount)	=	tempb;
					*(loadpoint+rightcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 8)	// RIGHT to MONO	// STOP AT FULL MEMSIZE	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+leftcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 9)	// STEREO to LEFT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					temp = temp+tempb;
					temp = temp >> 1;
					*(loadpoint+leftcount)	=	temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 10)	// STEREO to RIGHT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					temp = temp+tempb;
					temp = temp >> 1;
					*(loadpoint+rightcount)	=	temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 11)	// STEREO to STEREO	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+leftcount)	=	temp;
					*(loadpoint+rightcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 12)	// STEREO to MONO	// STOP AT FULL MEMSIZE	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					temp = temp+tempb;
					temp = temp >> 1;
					*(loadpoint+leftcount)	=	temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 13)	// MONO to LEFT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					incount++;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 14)	// MONO to RIGHT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+rightcount)	=	temp;
					incount++;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 15)	// MONO to STEREO	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					*(loadpoint+rightcount)	=	temp;
					incount++;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 16)	// MONO to MONO	// STOP AT FULL MEMSIZE	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					incount++;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			current=samcount;
			quartlen = quartlen+quartval;
			}	// loop
		}	// bits = 8
	delete lo_afile;
	}	// Test = true


//	sprintf(loadtexttest[0],"%d",lbyteswap);
//	sprintf(loadtexttest[1],"%d",lbits);
//	sprintf(loadtexttest[2],"%d",ltranslate);
//	loadtextgo->SetText(loadtexttest[0]);
//	loadtextgob->SetText(loadtexttest[1]);
//	loadtextgoc->SetText(loadtexttest[2]);
// ***************************************************************************************************

/*
if (type == 1)	// Old Save As
	{
	bufferstart = (void *)loadpoint;
	len = (size_t)loadmemsize << 1;
	
	sa_afile = new BFile(new BDirectory(sa_aref),sa_filename[0], B_ERASE_FILE | B_CREATE_FILE | B_WRITE_ONLY);
	test=sa_afile->IsWritable();

	if (test == true)
		{
		Hide();
		incount=0;	// Comvert to Interleaved Stereo
		for (samcount=0;samcount<loadmemsize;samcount=samcount+2)	// to undo buffer
			{
			*(loadpoint+loadmemsize+samcount)	= *(loadpoint+incount);
			*(loadpoint+loadmemsize+samcount+1)	= *(loadpoint+incount+loadhalfmemsize);
			incount++;
			}
		for (samcount=0;samcount<=loadmemsize;samcount++)	// from undo buffer
			{
			*(loadpoint+samcount)	= *(loadpoint+samcount+loadmemsize);
			}

		readnum = sa_afile->Write(bufferstart,len);
		delete sa_afile;
		}
	}
*/
BMessage *msg = new BMessage(EDIT_EDITGO);
msg->AddInt32("edlisttype", 21);
msg->AddInt32("edlistnumber", 17);
msg->AddInt16("edvalue", 0);
be_app->PostMessage(msg,be_app);
delete msg;

delete_area(load_area);	// delete the area:
}

	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void LOAD::Savedata(void)	// Save a sample
{
void * bufferstart;
size_t len;
bool test;
ssize_t readnum;
int16* lo_appoint;

uint32 incount;
uint32 samcount;
uint32 quartlen;
uint32 quartval;
uint32 maincount;
uint32 current;
uint32 leftcount;
uint32 rightcount;
uint32 mainstart;
uint32 mainend;
uint32 mainlen;
uint32 fullbytelen;
size_t fulllen;

uint32 displaycount;
uint32 display;
int16 done;
int16 wordval;
int8  byteval;
int16 tempval;
int32 temp;
int32 tempb;
int32 loadmode;
int32 loadstereo;
int8 *load8bitpoint;

area_id save_area; // memory area used for saving

// Create an area.
save_area = create_area("my area",	// name you give to the area
(void **)&bufferpoint,				// returns the starting addr
B_ANY_ADDRESS,						// area can start anywhere
131072,								// size in bytes
B_FULL_LOCK,						// Lock in RAM? Yes  - B_NO_LOCK = No
B_READ_AREA | B_WRITE_AREA);		// permissions


if (loadinputS3 == 1)	//	1	Save Range
	{
	mainstart = loadsamstart;
	mainend = loadsamend;
	}

if (loadinputS3 == 2)	//	2	Save All
	{
	mainstart = 0;
	mainend = loadmemsize;
	}

if (loadinputS1 == 1)	//	Save Left
	{
	if (loadinputS2 == 1)
		{
		loadmode = 1;
		}
	if (loadinputS2 == 2)
		{
		loadmode = 2;
		}
	if (loadinputS2 == 3)
		{
		loadmode = 3;
		}
	if (loadinputS2 == 4)
		{
		loadmode = 4;
		}
	loadstereo = 1;
	}
else if (loadinputS1 == 2)	//	Save Right
	{
	if (loadinputS2 == 1)
		{
		loadmode = 5;
		}
	if (loadinputS2 == 2)
		{
		loadmode = 6;
		}
	if (loadinputS2 == 3)
		{
		loadmode = 7;
		}
	if (loadinputS2 == 4)
		{
		loadmode = 8;
		}
	loadstereo = 1;
	}
else if (loadinputS1 == 3)	//	Save Stereo
	{
	if (loadinputS2 == 1)
		{
		loadmode = 9;
		}
	if (loadinputS2 == 2)
		{
		loadmode = 10;
		}
	if (loadinputS2 == 3)
		{
		loadmode = 11;
		}
	if (loadinputS2 == 4)
		{
		loadmode = 12;
		}
	loadstereo = 1;
	}
else if (loadinputS1 == 4)	//	Save Mono
	{
	if (loadinputS2 == 1)
		{
		loadmode = 13;
		}
	if (loadinputS2 == 2)
		{
		loadmode = 14;
		}
	if (loadinputS2 == 3)
		{
		loadmode = 15;
		}
	if (loadinputS2 == 4)
		{
		loadmode = 16;
		}
	loadstereo = 0;
	}

if (stranslate == 1)
	{		//	Call Translator here to determine
			//	new loadmode, loadstereo bits
	}		//	bits and byteswap

// Save As
load8bitpoint = (int8 *)bufferpoint;
len = (size_t)131072;
bufferstart = (void *)bufferpoint;	// from loader
BDirectory sa_dir(&sa_aref);
sa_afile = new BFile(&sa_dir, sa_filename, B_READ_WRITE | B_CREATE_FILE | B_ERASE_FILE);
test=sa_afile->IsWritable();

//if (test == true)	// old saver
//	{
//	Hide();
//	incount=0;	// Comvert to Interleaved Stereo
//	for (samcount=0;samcount<loadmemsize;samcount=samcount+2)	// to undo buffer
//		{
//		*(loadpoint+loadmemsize+samcount)	= *(loadpoint+incount);
//		*(loadpoint+loadmemsize+samcount+1)	= *(loadpoint+incount+loadhalfmemsize);
//		incount++;
//		}
//	for (samcount=0;samcount<=loadmemsize;samcount++)	// from undo buffer
//		{
//		*(loadpoint+samcount)	= *(loadpoint+samcount+loadmemsize);
//		}
//	}

if (test == true)
	{
	if (loadstereo == 1)
		{
		if (mainstart >= loadhalfmemsize)
			{
			mainstart = mainstart - loadhalfmemsize;
			mainend = mainend - loadhalfmemsize;
			}
		if (mainend > loadhalfmemsize)	mainend = loadhalfmemsize;
		}

	maincount = 0;

	if (sbits == 16)	// --------------------------------------------------------------------------
		{				// 16 BIT SAVERS
		quartval = 32767;
		if ((loadmode == 4) || (loadmode == 8) || (loadmode == 12) || (loadmode == 16))	quartval = 65535;
		quartlen = quartval;
		mainlen = mainend-mainstart;
		display=mainlen >> 5;
		displaycount=display+mainstart;
		done=1;
		fullbytelen = mainlen << 2;
		if ((loadmode == 4) || (loadmode == 8) || (loadmode == 12) || (loadmode == 16))	fullbytelen = mainlen << 1;
		fulllen=(size_t)fullbytelen;
		current=0;
		leftcount=mainstart;
		rightcount=mainstart+loadhalfmemsize;
		while (maincount<mainend)
			{
			for (samcount=0;samcount<=65535;samcount++)	// zero save buffer
				{
				*(bufferpoint+samcount) = 0;
				}
			incount=0;
			if (loadmode == 1)	// LEFT to LEFT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+leftcount);
					*(bufferpoint+incount)			= temp;
					*(bufferpoint+incount+1)		= 0;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 2)	// LEFT to RIGHT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+leftcount);
					*(bufferpoint+incount)			= 0;
					*(bufferpoint+incount+1)		= temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 3)	// LEFT to STEREO
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+leftcount);
					*(bufferpoint+incount)			= temp;
					*(bufferpoint+incount+1)		= temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 4)	// LEFT to MONO	// STOP AT FULL MEMSIZE
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+leftcount);
					*(bufferpoint+incount)			= temp;
					incount++;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 5)	// RIGHT to LEFT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+rightcount);
					*(bufferpoint+incount)			= temp;
					*(bufferpoint+incount+1)		= 0;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 6)	// RIGHT to RIGHT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+rightcount);
					*(bufferpoint+incount)			= 0;
					*(bufferpoint+incount+1)		= temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 7)	// RIGHT to STEREO
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+rightcount);
					*(bufferpoint+incount)			= temp;
					*(bufferpoint+incount+1)		= temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 8)	// RIGHT to MONO	// STOP AT FULL MEMSIZE
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+rightcount);
					*(bufferpoint+incount)			= temp;
					incount++;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 9)	// STEREO to LEFT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+leftcount);
					tempb							= *(loadpoint+rightcount);
					temp=temp + tempb;
					temp = temp >> 1;
					*(bufferpoint+incount)			= temp;
					*(bufferpoint+incount+1)		= 0;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 10)	// STEREO to RIGHT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+leftcount);
					tempb							= *(loadpoint+rightcount);
					temp=temp + tempb;
					temp = temp >> 1;
					*(bufferpoint+incount)			= 0;
					*(bufferpoint+incount+1)		= temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 11)	// STEREO to STEREO
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(bufferpoint+incount)			= *(loadpoint+leftcount);
					*(bufferpoint+incount+1)		= *(loadpoint+rightcount);
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 12)	// STEREO to MONO	// STOP AT FULL MEMSIZE
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp							= *(loadpoint+leftcount);
					tempb							= *(loadpoint+rightcount);
					temp=temp + tempb;
					temp = temp >> 1;
					*(bufferpoint+incount)			= temp;
					incount++;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 13)	// MONO to LEFT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(bufferpoint+incount)			= *(loadpoint+leftcount);
					*(bufferpoint+incount+1)		= 0;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 14)	// MONO to RIGHT
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(bufferpoint+incount)			= 0;
					*(bufferpoint+incount+1)		= *(loadpoint+leftcount);
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 15)	// MONO to STEREO
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(bufferpoint+incount)			= *(loadpoint+leftcount);
					*(bufferpoint+incount+1)		= *(loadpoint+leftcount);
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 16)	// MONO to MONO	// STOP AT FULL MEMSIZE
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					*(bufferpoint+incount)			= *(loadpoint+leftcount);
					incount++;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			current=samcount;
			quartlen = quartlen+quartval;

			if (sbyteswap == 1)	// Swap bytes if necessary
				{
				for (samcount=0;samcount<=65535;samcount++)
					{
					tempval=*(bufferpoint+samcount);
					byteval=tempval;
					wordval=byteval;
					wordval=wordval << 8;
					tempval=tempval >> 8;
					tempval=tempval + wordval;
					*(bufferpoint+samcount)=tempval;
					}
				}
			if (fulllen >= 131072)
				{
				readnum = sa_afile->Write(bufferstart,len);	//	write 128KB to save buffer
				fulllen = fulllen - 131072;
				}
			else if (fulllen < 131072)
				{
				readnum = sa_afile->Write(bufferstart,fulllen);	//	write rest to save buffer
				}
			}// loop
		} // bits = 16
// --------------------------------------------------------------------------
// --------------------------------------------------------//	8 BIT SAVERS
// --------------------------------------------------------------------------
	if (sbits == 8)
		{			
		if ((loadmode >= 0) && (loadmode <= 12)) quartval = 65535;
		if ((loadmode >= 13) && (loadmode <= 16)) quartval = 131071;
		quartlen = quartval;
		mainlen = mainend-mainstart;
		display=mainlen >> 5;
		displaycount=display+mainstart;
		done=1;
		current=0;
		leftcount=mainstart;
		rightcount=mainstart+loadhalfmemsize;
		while (maincount<mainend)
			{
			for (samcount=0;samcount<=65535;samcount++)	// zero load buffer
				{
				*(bufferpoint+samcount) = 0;
				}
			readnum = lo_afile->Read(bufferstart,len);	//	read 128KB to load buffer
			if (readnum == 0)
				{
				maincount = mainend;
				samcount = quartlen;
				Updatedonebox(2,32,32);
				}
			if (sbyteswap == 1)	// Change from Unsigned if nexessary
				{
				for (samcount=0;samcount<=131071;samcount++)
					{
					temp = *(load8bitpoint+samcount);
					temp = temp << 8;
					if (temp>0) temp=temp-32766;
					else if (temp<0) temp=temp+32766;
					temp = temp >> 8;
					*(load8bitpoint+samcount) = temp;
					}
				}
			incount=0;
			if (loadmode == 1)	// LEFT to LEFT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 2)	// LEFT to RIGHT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+rightcount)	=	temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 3)	// LEFT to STEREO	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					*(loadpoint+rightcount)	=	temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 4)	// LEFT to MONO	// STOP AT FULL MEMSIZE	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 5)	// RIGHT to LEFT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+leftcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 6)	// RIGHT to RIGHT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+rightcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 7)	// RIGHT to STEREO	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+leftcount)	=	tempb;
					*(loadpoint+rightcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 8)	// RIGHT to MONO	// STOP AT FULL MEMSIZE	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+leftcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 9)	// STEREO to LEFT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					temp = temp+tempb;
					temp = temp >> 1;
					*(loadpoint+leftcount)	=	temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 10)	// STEREO to RIGHT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					temp = temp+tempb;
					temp = temp >> 1;
					*(loadpoint+rightcount)	=	temp;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 11)	// STEREO to STEREO	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					*(loadpoint+leftcount)	=	temp;
					*(loadpoint+rightcount)	=	tempb;
					incount=incount+2;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 12)	// STEREO to MONO	// STOP AT FULL MEMSIZE	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					tempb = *(load8bitpoint+incount+1);
					tempb = tempb << 8;
					temp = temp+tempb;
					temp = temp >> 1;
					*(loadpoint+leftcount)	=	temp;
					incount=incount+2;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 13)	// MONO to LEFT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					incount++;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 14)	// MONO to RIGHT	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+rightcount)	=	temp;
					incount++;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 15)	// MONO to STEREO	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					*(loadpoint+rightcount)	=	temp;
					incount++;
					leftcount++;
					rightcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}
			if (loadmode == 16)	// MONO to MONO	// STOP AT FULL MEMSIZE	- 8 bit
				{
				for (samcount=current;samcount<=quartlen;samcount++)
					{
					temp = *(load8bitpoint+incount);
					temp = temp << 8;
					*(loadpoint+leftcount)	=	temp;
					incount++;
					leftcount++;
					if (leftcount >= mainend)
						{
						maincount = mainend;
						samcount = quartlen;
						Updatedonebox(2,32,32);
						}
					if (leftcount >= displaycount)
						{
						Updatedonebox(2,32,done);
						done++;
						displaycount=displaycount+display;
						}
					}
				}

			current=samcount;
			quartlen = quartlen+quartval;
			}	// loop
		}	// bits = 8
	// delete lo_afile;
	}	// Test = true

	delete sa_afile;

//	sprintf(loadtexttest[0],"%d",leftcount);
//	sprintf(loadtexttest[1],"%d",incount);
//	sprintf(loadtexttest[2],"%d",sbyteswap);
//	loadtextgo->SetText(loadtexttest[0]);
//	loadtextgob->SetText(loadtexttest[1]);
//	loadtextgoc->SetText(loadtexttest[2]);

BMessage *msg = new BMessage(EDIT_EDITGO);
msg->AddInt32("edlisttype", 21);
msg->AddInt32("edlistnumber", 17);
msg->AddInt16("edvalue", 0);
be_app->PostMessage(msg,be_app);
delete msg;

delete_area(save_area);	// delete the area:
}

	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

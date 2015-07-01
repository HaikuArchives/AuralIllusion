// ALLFX.cpp 
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

#include "ALLFX.h"

#include <stdio.h>
#include <stdlib.h>


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************


// ALLFX Globals & definitions

//	0 = Standard FX
//	1 = Complex FX
//	2 = Manips 1
//	3 = Manips 2
//	4 = Dual FX
//	5 = Stereo FX

static int32 listtype;		// for list elements
static int32 listnumber;

static int32 listfxno;  // Current effect selected in each window
static int32 listcfxno;
static int32 listman1no;
static int32 listman2no;
static int32 listdmanno;
static int32 listsfxno;

static int32 fxtype;		// for displaying data / calling fx
static int32 fxnumber;

//  Text for ALLFX window gadgets is of type [fxtype][fxnumber][x]
//  where x is one of below
//
//	0 = Slider 1
//	1 = Slider 2
//	2 = Slider 3
//	3 = Slider 4
//	4 = Radio Button 1A
//	5 = Radio Button 1B
//	6 = Radio Button 2A
//	7 = Radion Button 2B
//	8 = Mix Level

char allfxtxt[6][84][9][20]; 

// and yet another for FX values and ghosts
// 0 = off  1 = on
//
// 	0 = Slider 1
//	1 = Slider 2
//	2 = Slider 3
//	3 = Slider 4
//	4 = Radio Button 1
//	6 = Radio Button 2
//	8 = Mix Level

int16 allfxvals[6][84][7];
int8 allfxghosts[6][84][7];

// maximum slider values
// if value exceeds these slider is ghosted
// int16 allfxmaxvals[6][64][4];

// another text array here for ALLFX message box
char allfxboxtxt[6][84][3][50];

int16 drawlen; // for drawbar on EDIT

	BMenuItem* fxfxmenuitem; // These are global so they can be changed
	BMenuItem* cfxmenuitem;
	BMenuItem* sfxmenuitem;

int16 iewvals[2][21];	// array for EQvalues 0 = EQ7  1 = EQ20
int16 iewmsgtyp;
int16 iewtyp;

// These are Dummy functions for other ALLFX_xx files

//	void ALLFX::Setfxvars(int16 incount) {}
//	void ALLFX::Setcomplexfxvars(int16 incount) {}
//	void ALLFX::Setmanip1vars(int16 incount) {}
//	void ALLFX::Setmanip2vars(int16 incount) {}
//	void ALLFX::Setdualmanipvars(int16 incount) {}
//	void ALLFX::Setstereofxvars(int16 incount) {}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

ALLFX::ALLFX(void)
	: BWindow(BRect(148,23,563,354), "Effects", B_TITLED_WINDOW_LOOK,B_NORMAL_WINDOW_FEEL, 0)
{

	BView* allfxview = new BView(BRect(-2,-3,416,350), "allfxview", B_FOLLOW_ALL, B_WILL_DRAW);

	// GO - Set buttons
	fxgo = new BButton(BRect(367,258,413,284), "go", "GO",	new BMessage(ALLFX_FXGO));
	fxgo->MakeDefault(1); // set as default for fancy surround
	fxgo->SetFont(be_bold_font);
	allfxview->AddChild(fxgo);

	fxdefault = new BButton(BRect(250,258,337,278), "fxdefault", "Default Values",	new BMessage(ALLFX_FXDEFAULT));
	allfxview->AddChild(fxdefault);

	fxset = new BButton(BRect(369,228,410,248), "set", "Set",	new BMessage(ALLFX_FXSET));
	allfxview->AddChild(fxset);

	fxlev1 = new BSlider(BRect(3,2,223,52), "fxlev1", "Level 1",  new BMessage(ALLFX_FXLEV1), 0,256);
	fxlev1->SetHashMarks(B_HASH_MARKS_BOTH);
	fxlev1->SetHashMarkCount(9);
	fxlev1->SetLimitLabels("0", "256");
	fxlev1->SetValue(0);
	allfxview->AddChild(fxlev1);

	fxlev2 = new BSlider(BRect(3,52,223,102), "fxlev2", "Level 2",  new BMessage(ALLFX_FXLEV2), 0,256);
	fxlev2->SetHashMarks(B_HASH_MARKS_BOTH);
	fxlev2->SetHashMarkCount(9);
	fxlev2->SetLimitLabels("0", "256");
	fxlev2->SetValue(0);
	allfxview->AddChild(fxlev2);

	fxlev3 = new BSlider(BRect(3,102,223,152), "fxlev3", "Level 3",  new BMessage(ALLFX_FXLEV3), 0,256);
	fxlev3->SetHashMarks(B_HASH_MARKS_BOTH);
	fxlev3->SetHashMarkCount(9);
	fxlev3->SetLimitLabels("0", "256");
	fxlev3->SetValue(0);
	allfxview->AddChild(fxlev3);

	fxlev4 = new BSlider(BRect(3,152,223,202), "fxlev4", "Level 4",  new BMessage(ALLFX_FXLEV4), 0,256);
	fxlev4->SetHashMarks(B_HASH_MARKS_BOTH);
	fxlev4->SetHashMarkCount(9);
	fxlev4->SetLimitLabels("0", "256");
	fxlev4->SetValue(0);
	allfxview->AddChild(fxlev4);

	fxlev = new BSlider(BRect(3,237,223,287), "fxlev", "Mix Level",  new BMessage(ALLFX_FXLEV), 0,256);
	fxlev->SetHashMarks(B_HASH_MARKS_BOTH);
	fxlev->SetHashMarkCount(9);
	fxlev->SetLimitLabels("0", "256");
	fxlev->SetValue(0);
	allfxview->AddChild(fxlev);
	
	// View and Radio Buttons 1
	BView* fxradio1 = new BView(BRect(15,203,125,236), "viewmodeview", B_FOLLOW_ALL, B_WILL_DRAW);
	
	fxadd1a = new BRadioButton(BRect(0,0,22,17),"fxadd1a"," ",		new BMessage(ALLFX_FXADD1A));
	fxradio1->AddChild(fxadd1a);
	
	fxadd1b = new BRadioButton(BRect(0,16,22,33),"fxadd1b"," ",		new BMessage(ALLFX_FXADD1B));
	fxradio1->AddChild(fxadd1b);
	
	fxadd1atxt = new BStringView(BRect(24,3,108,14), "fxadd1atxt","Addition", B_FOLLOW_ALL, B_WILL_DRAW);
	fxradio1->AddChild(fxadd1atxt);
	
	fxadd1btxt = new BStringView(BRect(24,19,108,30), "fxadd1btxt","Subtraction", B_FOLLOW_ALL, B_WILL_DRAW);
	fxradio1->AddChild(fxadd1btxt);
										
	fxradio1->SetViewColor(216,216,216);
	allfxview->AddChild(fxradio1);
	
	// View and Radio Buttons 2
	BView* fxradio2 = new BView(BRect(137,203,247,236), "viewmodeview", B_FOLLOW_ALL, B_WILL_DRAW);
	
	fxadd2a = new BRadioButton(BRect(0,0,22,17),"fxadd2a"," ",		new BMessage(ALLFX_FXADD2A));
	fxradio2->AddChild(fxadd2a);
	
	fxadd2b = new BRadioButton(BRect(0,16,22,33),"fxadd2b"," ",		new BMessage(ALLFX_FXADD2B));
	fxradio2->AddChild(fxadd2b);
	
	fxadd2atxt = new BStringView(BRect(24,3,108,14), "fxadd2atxt","Multiply", B_FOLLOW_ALL, B_WILL_DRAW);
	fxradio2->AddChild(fxadd2atxt);
	
	fxadd2btxt = new BStringView(BRect(24,19,108,30), "fxadd2btxt","Divide", B_FOLLOW_ALL, B_WILL_DRAW);
	fxradio2->AddChild(fxadd2btxt);
										
	fxradio2->SetViewColor(216,216,216);
	allfxview->AddChild(fxradio2);

	// Message box
	BView* fxtextview = new BView(BRect(3,290,416,334), "fxtextview", B_FOLLOW_ALL, B_WILL_DRAW);

	fxtextgo = new BStringView(BRect(2,3,410,14), "fxtextgo","Welcome", B_FOLLOW_ALL, B_WILL_DRAW);
	fxtextgo->SetHighColor(255,255,255); // text to white
	fxtextview->AddChild(fxtextgo);

	fxtextgob = new BStringView(BRect(2,16,410,27), "fxtextgob","to the", B_FOLLOW_ALL, B_WILL_DRAW);
	fxtextgob->SetHighColor(255,255,255); // text to white
	fxtextview->AddChild(fxtextgob);

	fxtextgoc = new BStringView(BRect(2,29,410,40), "fxtextgoc","Pleasure dome", B_FOLLOW_ALL, B_WILL_DRAW);
	fxtextgoc->SetHighColor(255,255,255); // text to white
	fxtextview->AddChild(fxtextgoc);

	fxtextview->SetViewColor(0,0,0); // background to black
	allfxview->AddChild(fxtextview);

	// Slider Value Strings

	fxlevtxt1 = new BStringView(BRect(224,23,249,34), "fxlevtxt1","256", B_FOLLOW_ALL, B_WILL_DRAW);
	allfxview->AddChild(fxlevtxt1);

	fxlevtxt2 = new BStringView(BRect(224,73,249,84), "fxlevtxt2","256", B_FOLLOW_ALL, B_WILL_DRAW);
	allfxview->AddChild(fxlevtxt2);

	fxlevtxt3 = new BStringView(BRect(224,123,249,134), "fxlevtxt3","256", B_FOLLOW_ALL, B_WILL_DRAW);
	allfxview->AddChild(fxlevtxt3);

	fxlevtxt4 = new BStringView(BRect(224,173,249,184), "fxlevtxt4","256", B_FOLLOW_ALL, B_WILL_DRAW);
	allfxview->AddChild(fxlevtxt4);

	fxlevtxt = new BStringView(BRect(224,258,249,269), "fxlevtxt","256", B_FOLLOW_ALL, B_WILL_DRAW);
	allfxview->AddChild(fxlevtxt);

	// Effects List

	fxpick = new BListView(BRect(246,5,400,224),"fxpick",B_SINGLE_SELECTION_LIST,B_WILL_DRAW);
	fxpick->SetSelectionMessage(new BMessage(ALLFX_FXPICK_SELECTION));
	
	fxpickparent = new BScrollView("fxpickparent",fxpick,0,0,false,true,B_PLAIN_BORDER);
	allfxview->AddChild(fxpickparent);
	
	// FX type selector
	fxmenu = new BMenu("Standard FX",B_ITEMS_IN_COLUMN);
	fxmenu->SetLabelFromMarked(true);

	BMenuItem* fxmenuitem;
	
	fxfxmenuitem = new BMenuItem("Standard FX", new BMessage(ALLFX_FXTYPE_STANDARD_FX));
	fxmenu->AddItem(fxfxmenuitem);

	cfxmenuitem = new BMenuItem("Complex FX", new BMessage(ALLFX_FXTYPE_COMPLEX_FX));
	fxmenu->AddItem(cfxmenuitem);

	fxmenuitem = new BMenuItem("Manips 1", new BMessage(ALLFX_FXTYPE_MANIPS_1));
	fxmenu->AddItem(fxmenuitem);

	fxmenuitem = new BMenuItem("Manips 2", new BMessage(ALLFX_FXTYPE_MANIPS_2));
	fxmenu->AddItem(fxmenuitem);

	fxmenuitem = new BMenuItem("Dual Manips", new BMessage(ALLFX_FXTYPE_DUAL_MANIPS));
	fxmenu->AddItem(fxmenuitem);

	sfxmenuitem = new BMenuItem("Stereo FX", new BMessage(ALLFX_FXTYPE_STEREO_FX));
	fxmenu->AddItem(sfxmenuitem);

	fxtypefield = new BMenuField(BRect(250,227,350,249),"fxtype",NULL,fxmenu,true,B_WILL_DRAW);
	allfxview->AddChild(fxtypefield);

	// set the view color to gray, add the view
	allfxview->SetViewColor(216,216,216);
	AddChild(allfxview);

	// Variable setup

	listtype = 0;	// List defaults to Standard FX
	listnumber = 0;

	listfxno=0;  // Each list defaults to first effect
	listcfxno=0;
	listman1no=0;
	listman2no=0;
	listdmanno=0;
	listsfxno=0;

	fxtype = 0;
	fxnumber = 0;

	// show the window
	Show();
	
	Lock();
	Drawlist(1,0); // draw StandardFX list
	fxpick->Select(listfxno);
	fxfxmenuitem->SetMarked(1);
	sfxmenuitem->SetEnabled(0);
	Unlock();

	// Call MAPPER
	fxtype = Mapper(0,listtype,listnumber);
	fxnumber = Mapper(1,listtype,listnumber);

	Setallfxvars(); // set up variable arrays
	Updateallfxwindow(0,fxtype,fxnumber);  // update sliders

}


ALLFX::~ALLFX(void) // Destructor
{
	Drawlist(1,100);  // clear list
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

// DUMMY FUNCTIONS - Rem out when not in use
/*
	// ALLFX_fx.cpp
	void ALLFX::Setfxvars(int16 incount) {};
	// ALLFX_cfx.cpp
	void ALLFX::Setcomplexfxvars(int16 incount) {};
	// ALLFX_man1.cpp
	void ALLFX::Setmanip1vars(int16 incount) {};
	// ALLFX_man2.cpp
	void ALLFX::Setmanip2vars(int16 incount) {};
	// ALLFX_dman.cpp
	void ALLFX::Setdualmanipvars(int16 incount) {};
	// ALLFX_sfx.cpp
	void ALLFX::Setstereofxvars(int16 incount) {};
*/

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************


void ALLFX::Drawlist(int16 option, int16 listtype)
{

Lock();

if (option == 0)	// clear list
	{
	fxpick->RemoveItems(0,100);
	}

// now draw new one

if (listtype == 0)	// Standard FX
	{
	fxpick->AddItem(new BStringItem("Reverb"));
	fxpick->AddItem(new BStringItem("Echo"));
	fxpick->AddItem(new BStringItem("Delay"));
	fxpick->AddItem(new BStringItem("Phase Shift"));
	fxpick->AddItem(new BStringItem("Phaser"));
	fxpick->AddItem(new BStringItem("Chorus"));
	fxpick->AddItem(new BStringItem("Flange"));
	fxpick->AddItem(new BStringItem("Distortion"));
	fxpick->AddItem(new BStringItem("Compress"));	// Dubious
	fxpick->AddItem(new BStringItem("Expand"));	// Dubious
	fxpick->AddItem(new BStringItem("Enhance"));
	fxpick->AddItem(new BStringItem("Resample"));
	fxpick->AddItem(new BStringItem("Detune"));
	fxpick->AddItem(new BStringItem("Fade"));
	fxpick->AddItem(new BStringItem("Boost"));
	fxpick->AddItem(new BStringItem("Resolution"));
	fxpick->AddItem(new BStringItem("Bandwidth"));
	fxpick->AddItem(new BStringItem("Alternate"));
	fxpick->AddItem(new BStringItem("Filter Low Pass"));
	fxpick->AddItem(new BStringItem("Filter High Pass"));
	fxpick->AddItem(new BStringItem("Filter Band Pass"));
	fxpick->AddItem(new BStringItem("Filter Band Cut"));
	fxpick->AddItem(new BStringItem("Filter Notch Pass"));
	fxpick->AddItem(new BStringItem("Filter Notch Cut"));
	fxpick->AddItem(new BStringItem("Backwards Reverb"));
	fxpick->AddItem(new BStringItem("Reverb Phaser"));
	fxpick->AddItem(new BStringItem("Reverb Only"));
	fxpick->AddItem(new BStringItem("Long Delay"));
	fxpick->AddItem(new BStringItem("Multi Tap Delay"));
	fxpick->AddItem(new BStringItem("Feedback Delay"));
	fxpick->AddItem(new BStringItem("Bounce Delay"));
	fxpick->AddItem(new BStringItem("Jump Flange"));
	fxpick->AddItem(new BStringItem("Strange Flange"));
	fxpick->AddItem(new BStringItem("Delay Flange"));
	fxpick->AddItem(new BStringItem("Digital Distortion"));
	fxpick->AddItem(new BStringItem("Contortion"));
	fxpick->AddItem(new BStringItem("Mix Contortion"));
	fxpick->AddItem(new BStringItem("Bandwidth Smooth"));
	}	//	38 / 38


if (listtype == 1)	// Complex FX
	{
	fxpick->AddItem(new BStringItem("Graphic Equalizer 7 Band"));
	fxpick->AddItem(new BStringItem("Graphic Equalizer 20 Band"));
	fxpick->AddItem(new BStringItem("1/x"));
	fxpick->AddItem(new BStringItem("Acos"));
	fxpick->AddItem(new BStringItem("Asin"));
	fxpick->AddItem(new BStringItem("Atan"));
	fxpick->AddItem(new BStringItem("Cos"));
	fxpick->AddItem(new BStringItem("Sin"));
	fxpick->AddItem(new BStringItem("Tan"));
	fxpick->AddItem(new BStringItem("Cosh"));
	fxpick->AddItem(new BStringItem("Sinh"));
	fxpick->AddItem(new BStringItem("Tanh"));
	fxpick->AddItem(new BStringItem("Acosh"));
	fxpick->AddItem(new BStringItem("Asinh"));
	fxpick->AddItem(new BStringItem("Atanh"));
	fxpick->AddItem(new BStringItem("Sec"));
	fxpick->AddItem(new BStringItem("Cosec"));
	fxpick->AddItem(new BStringItem("Cot"));
	fxpick->AddItem(new BStringItem("+Sin"));
	fxpick->AddItem(new BStringItem("Exp"));
	fxpick->AddItem(new BStringItem("Log"));
	fxpick->AddItem(new BStringItem("Log10"));
	fxpick->AddItem(new BStringItem("Expm1"));
	fxpick->AddItem(new BStringItem("Log1p"));
	fxpick->AddItem(new BStringItem("Logb"));
	fxpick->AddItem(new BStringItem("+Log"));
	fxpick->AddItem(new BStringItem("Sqrt"));
	fxpick->AddItem(new BStringItem("Cbrt"));
	fxpick->AddItem(new BStringItem("Ceil"));
	fxpick->AddItem(new BStringItem("Fabs"));
	fxpick->AddItem(new BStringItem("Floor"));
	fxpick->AddItem(new BStringItem("Significand"));
	fxpick->AddItem(new BStringItem("J0"));
	fxpick->AddItem(new BStringItem("J1"));
	fxpick->AddItem(new BStringItem("Y0"));
	fxpick->AddItem(new BStringItem("Y1"));
	fxpick->AddItem(new BStringItem("Erf"));
	fxpick->AddItem(new BStringItem("Erfc"));
	fxpick->AddItem(new BStringItem("Gamma"));
	fxpick->AddItem(new BStringItem("Lgamma"));
	fxpick->AddItem(new BStringItem("Rint"));
	fxpick->AddItem(new BStringItem("Ilogbf"));
	fxpick->AddItem(new BStringItem("Delay 1/x"));
	fxpick->AddItem(new BStringItem("Delay Acos"));
	fxpick->AddItem(new BStringItem("Delay Asin"));
	fxpick->AddItem(new BStringItem("Delay Atan"));
	fxpick->AddItem(new BStringItem("Delay Cos"));
	fxpick->AddItem(new BStringItem("Delay Sin"));
	fxpick->AddItem(new BStringItem("Delay Tan"));
	fxpick->AddItem(new BStringItem("Delay Cosh"));
	fxpick->AddItem(new BStringItem("Delay Sinh"));
	fxpick->AddItem(new BStringItem("Delay Tanh"));
	fxpick->AddItem(new BStringItem("Delay Acosh"));
	fxpick->AddItem(new BStringItem("Delay Asinh"));
	fxpick->AddItem(new BStringItem("Delay Atanh"));
	fxpick->AddItem(new BStringItem("Delay Sec"));
	fxpick->AddItem(new BStringItem("Delay Cosec"));
	fxpick->AddItem(new BStringItem("Delay Cot"));
	fxpick->AddItem(new BStringItem("Delay +Sin"));
	fxpick->AddItem(new BStringItem("Delay Exp"));
	fxpick->AddItem(new BStringItem("Delay Log"));
	fxpick->AddItem(new BStringItem("Delay Log10"));
	fxpick->AddItem(new BStringItem("Delay Expm1"));
	fxpick->AddItem(new BStringItem("Delay Log1p"));
	fxpick->AddItem(new BStringItem("Delay Logb"));
	fxpick->AddItem(new BStringItem("Delay +Log"));
	fxpick->AddItem(new BStringItem("Delay Sqrt"));
	fxpick->AddItem(new BStringItem("Delay Cbrt"));
	fxpick->AddItem(new BStringItem("Delay Ceil"));
	fxpick->AddItem(new BStringItem("Delay Fabs"));
	fxpick->AddItem(new BStringItem("Delay Floor"));
	fxpick->AddItem(new BStringItem("Delay Significand"));
	fxpick->AddItem(new BStringItem("Delay J0"));
	fxpick->AddItem(new BStringItem("Delay J1"));
	fxpick->AddItem(new BStringItem("Delay Y0"));
	fxpick->AddItem(new BStringItem("Delay Y1"));
	fxpick->AddItem(new BStringItem("Delay Erf"));
	fxpick->AddItem(new BStringItem("Delay Erfc"));
	fxpick->AddItem(new BStringItem("Delay Gamma"));
	fxpick->AddItem(new BStringItem("Delay Lgamma"));
	fxpick->AddItem(new BStringItem("Delay Rint"));
	fxpick->AddItem(new BStringItem("Delay Ilogbf"));
	}	//	82 / 82

if (listtype == 2)	// Manips 1
	{
	fxpick->AddItem(new BStringItem("Invert"));
	fxpick->AddItem(new BStringItem("Half Wave Rectify"));
	fxpick->AddItem(new BStringItem("Full Wave Rectify"));
	fxpick->AddItem(new BStringItem("Flip"));
	fxpick->AddItem(new BStringItem("Centre"));
	fxpick->AddItem(new BStringItem("Reverse"));
	fxpick->AddItem(new BStringItem("Clean"));
	fxpick->AddItem(new BStringItem("Thicken"));
	fxpick->AddItem(new BStringItem("Double Thicken"));
	fxpick->AddItem(new BStringItem("Quarter Value"));
	fxpick->AddItem(new BStringItem("Half Value"));
	fxpick->AddItem(new BStringItem("Double Value"));
	fxpick->AddItem(new BStringItem("Quadruple Value"));
	fxpick->AddItem(new BStringItem("Fade In"));
	fxpick->AddItem(new BStringItem("Fade Out"));
	fxpick->AddItem(new BStringItem("Recreate"));
	fxpick->AddItem(new BStringItem("Loudness"));
	fxpick->AddItem(new BStringItem("UnLoudness"));
	fxpick->AddItem(new BStringItem("Filter Very High"));
	fxpick->AddItem(new BStringItem("Filter High Band"));
	fxpick->AddItem(new BStringItem("Filter High Mid"));
	fxpick->AddItem(new BStringItem("Filter Mid Band"));
	fxpick->AddItem(new BStringItem("Filter Low Mid"));
	fxpick->AddItem(new BStringItem("Filter Low Band"));
	fxpick->AddItem(new BStringItem("Filter Sub Bass"));
	fxpick->AddItem(new BStringItem("Tune 2 Octaves"));
	fxpick->AddItem(new BStringItem("Tune Octave"));
	fxpick->AddItem(new BStringItem("Tune Note"));
	fxpick->AddItem(new BStringItem("Tune Semitone"));
	fxpick->AddItem(new BStringItem("Tune 1/8 Note"));
	fxpick->AddItem(new BStringItem("Zero Out"));
	fxpick->AddItem(new BStringItem("More +/-"));
	fxpick->AddItem(new BStringItem("Blur Filter"));
	fxpick->AddItem(new BStringItem("2D Blur Filter"));
	fxpick->AddItem(new BStringItem("Auto Stutter"));
	fxpick->AddItem(new BStringItem("Strange Delay"));
	fxpick->AddItem(new BStringItem("Stranger Delay"));
	fxpick->AddItem(new BStringItem("Half Distortion"));
	fxpick->AddItem(new BStringItem("Half Contortion"));
	}	//	39 / 39

if (listtype == 3)	// Manips 2
	{
	fxpick->AddItem(new BStringItem("Over"));
	fxpick->AddItem(new BStringItem("Under"));
	fxpick->AddItem(new BStringItem("In Between"));
	fxpick->AddItem(new BStringItem("Out Between"));
	fxpick->AddItem(new BStringItem("Limit Low"));
	fxpick->AddItem(new BStringItem("Limit High"));
	fxpick->AddItem(new BStringItem("Add Spikes"));
	fxpick->AddItem(new BStringItem("Delete Spikes"));
	fxpick->AddItem(new BStringItem("Capacitance"));
	fxpick->AddItem(new BStringItem("Replacement"));
	fxpick->AddItem(new BStringItem("Tear"));
	fxpick->AddItem(new BStringItem("Swap Byte Order"));
	fxpick->AddItem(new BStringItem("Delta"));
	fxpick->AddItem(new BStringItem("Square"));
	fxpick->AddItem(new BStringItem("Half Square"));
	fxpick->AddItem(new BStringItem("Transform Blocks"));
	fxpick->AddItem(new BStringItem("Reverse Single Blocks"));
	fxpick->AddItem(new BStringItem("Reverse All Blocks"));
	fxpick->AddItem(new BStringItem("Skip Blocks"));
	fxpick->AddItem(new BStringItem("Repeat Blocks"));
	fxpick->AddItem(new BStringItem("Unorder Samples"));
	fxpick->AddItem(new BStringItem("Unorder Blocks"));
	fxpick->AddItem(new BStringItem("Flip Alternate"));
	fxpick->AddItem(new BStringItem("Ramdom Amplifier"));
	fxpick->AddItem(new BStringItem("Swap Halves"));
	fxpick->AddItem(new BStringItem("Remove Centre"));
	fxpick->AddItem(new BStringItem("Add Centre"));
	fxpick->AddItem(new BStringItem("Remove Flat"));
	fxpick->AddItem(new BStringItem("Keep Flat"));
	fxpick->AddItem(new BStringItem("Remove Middle"));
	fxpick->AddItem(new BStringItem("Transmogrify"));
	fxpick->AddItem(new BStringItem("Non-Transmogrify"));
	fxpick->AddItem(new BStringItem("Delay Delta"));
	fxpick->AddItem(new BStringItem("Delay Backwards Subtract"));
	fxpick->AddItem(new BStringItem("Delay Multiply"));
	fxpick->AddItem(new BStringItem("Delay Divide"));
	fxpick->AddItem(new BStringItem("Delay Backwards Divide"));
	fxpick->AddItem(new BStringItem("Delay AND"));
	fxpick->AddItem(new BStringItem("Delay OR"));
	fxpick->AddItem(new BStringItem("Delay XOR"));
	fxpick->AddItem(new BStringItem("Delay Rectify"));
	fxpick->AddItem(new BStringItem("Delay Greater"));
	fxpick->AddItem(new BStringItem("Delay Lesser"));
	fxpick->AddItem(new BStringItem("Delay Interleave"));
	fxpick->AddItem(new BStringItem("Delay Modulus"));
	fxpick->AddItem(new BStringItem("Delay Backwards Modulus"));
	fxpick->AddItem(new BStringItem("Noise"));
	fxpick->AddItem(new BStringItem("Filtered Noise"));
	fxpick->AddItem(new BStringItem("Rumble"));
	fxpick->AddItem(new BStringItem("Chaos"));
	fxpick->AddItem(new BStringItem("Random"));
	}	//	51 / 51

if (listtype == 4)	// Dual Manips
	{
	fxpick->AddItem(new BStringItem("XXX - Powered Compress"));	//	NI
	fxpick->AddItem(new BStringItem("XXX - Powered Expand"));	//	NI
	fxpick->AddItem(new BStringItem("Half Rectify and Add"));
	fxpick->AddItem(new BStringItem("Full Rectify and Add"));
	fxpick->AddItem(new BStringItem("Add"));
	fxpick->AddItem(new BStringItem("Subtract"));
	fxpick->AddItem(new BStringItem("Backwards Subtract"));
	fxpick->AddItem(new BStringItem("Multiply"));
	fxpick->AddItem(new BStringItem("Divide"));
	fxpick->AddItem(new BStringItem("Backwards Divide"));
	fxpick->AddItem(new BStringItem("AND"));
	fxpick->AddItem(new BStringItem("OR"));
	fxpick->AddItem(new BStringItem("XOR"));
	fxpick->AddItem(new BStringItem("Greater"));
	fxpick->AddItem(new BStringItem("Lesser"));
	fxpick->AddItem(new BStringItem("Interleave"));
	fxpick->AddItem(new BStringItem("Rectify"));
	fxpick->AddItem(new BStringItem("Stutter"));
	fxpick->AddItem(new BStringItem("Modulus"));
	fxpick->AddItem(new BStringItem("Backwards Modulus"));
	fxpick->AddItem(new BStringItem("Amplitude Modulation"));
	}	//	19 / 21

if (listtype == 5)	// Stereo FX
	{
	fxpick->AddItem(new BStringItem("Stereo Reverb"));
	fxpick->AddItem(new BStringItem("Stereo Reverb Only"));
	fxpick->AddItem(new BStringItem("Swap Sides Left<->Right"));
	fxpick->AddItem(new BStringItem("Cross Fade Left<->Right"));
	fxpick->AddItem(new BStringItem("Cross Fade Stereo Mono"));
	fxpick->AddItem(new BStringItem("Pan Manual"));
	fxpick->AddItem(new BStringItem("Pan Ping Pong"));
	fxpick->AddItem(new BStringItem("Pan Mono Left"));
	fxpick->AddItem(new BStringItem("Pan Mono Right"));
	fxpick->AddItem(new BStringItem("Add"));
	fxpick->AddItem(new BStringItem("Subtract"));
	fxpick->AddItem(new BStringItem("Backwards Subtract"));
	fxpick->AddItem(new BStringItem("Multiply"));
	fxpick->AddItem(new BStringItem("Divide"));
	fxpick->AddItem(new BStringItem("Backwards Divide"));
	fxpick->AddItem(new BStringItem("AND"));
	fxpick->AddItem(new BStringItem("OR"));
	fxpick->AddItem(new BStringItem("XOR"));
	fxpick->AddItem(new BStringItem("Greater"));
	fxpick->AddItem(new BStringItem("Lesser"));
	fxpick->AddItem(new BStringItem("Interleave"));
	fxpick->AddItem(new BStringItem("Modulus"));
	fxpick->AddItem(new BStringItem("Backwards Modulus"));
	fxpick->AddItem(new BStringItem("Stutter"));
	fxpick->AddItem(new BStringItem("Rectify"));
	}	//	25 / 25
	//	254 / 256 13/10/99


Unlock();

}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************


void ALLFX::Updateallfxwindow(int32 mess_no, int32 fxtype, int32 fxnumber)
{
static char levnumtxt[4][5];

// Update window

Lock();

 	fxlev1->SetEnabled(allfxghosts[fxtype][fxnumber][0]); // sliders
 	fxlev1->SetValue(allfxvals[fxtype][fxnumber][0]);
 	fxlev1->SetLabel(allfxtxt[fxtype][fxnumber][0]);
	sprintf(levnumtxt[0],"%d",allfxvals[fxtype][fxnumber][0]);
	fxlevtxt1->SetText(levnumtxt[0]);

 	fxlev2->SetEnabled(allfxghosts[fxtype][fxnumber][1]);
 	fxlev2->SetValue(allfxvals[fxtype][fxnumber][1]);
	fxlev2->SetLabel(allfxtxt[fxtype][fxnumber][1]);
	sprintf(levnumtxt[1],"%d",allfxvals[fxtype][fxnumber][1]);
	fxlevtxt2->SetText(levnumtxt[1]);

 	fxlev3->SetEnabled(allfxghosts[fxtype][fxnumber][2]);
	fxlev3->SetValue(allfxvals[fxtype][fxnumber][2]);
	fxlev3->SetLabel(allfxtxt[fxtype][fxnumber][2]);
	sprintf(levnumtxt[2],"%d",allfxvals[fxtype][fxnumber][2]);
	fxlevtxt3->SetText(levnumtxt[2]);

 	fxlev4->SetEnabled(allfxghosts[fxtype][fxnumber][3]);
	fxlev4->SetValue(allfxvals[fxtype][fxnumber][3]);
	fxlev4->SetLabel(allfxtxt[fxtype][fxnumber][3]);
	sprintf(levnumtxt[3],"%d",allfxvals[fxtype][fxnumber][3]);
	fxlevtxt4->SetText(levnumtxt[3]);

	fxadd1a->SetEnabled(allfxghosts[fxtype][fxnumber][4]); // Radio Buttons
	fxadd1b->SetEnabled(allfxghosts[fxtype][fxnumber][4]);
	if (allfxvals[fxtype][fxnumber][4] == 0) fxadd1a->SetValue(1);
	else fxadd1b->SetValue(1);
	fxadd1atxt->SetText(allfxtxt[fxtype][fxnumber][4]);
	fxadd1btxt->SetText(allfxtxt[fxtype][fxnumber][5]);

	fxadd2a->SetEnabled(allfxghosts[fxtype][fxnumber][5]);
	fxadd2b->SetEnabled(allfxghosts[fxtype][fxnumber][5]);
	if (allfxvals[fxtype][fxnumber][5] == 0) fxadd2a->SetValue(1);
	else fxadd2b->SetValue(1);
	fxadd2atxt->SetText(allfxtxt[fxtype][fxnumber][6]);
	fxadd2btxt->SetText(allfxtxt[fxtype][fxnumber][7]);
	
 	fxlev->SetEnabled(allfxghosts[fxtype][fxnumber][6]); // Mix Level
 	fxlev->SetValue(allfxvals[fxtype][fxnumber][6]);
	fxlev->SetLabel(allfxtxt[fxtype][fxnumber][8]); // 8 for label value
	sprintf(levnumtxt[0],"%d",allfxvals[fxtype][fxnumber][6]);
	fxlevtxt->SetText(levnumtxt[0]);
 	
	fxtextgo->SetText(allfxboxtxt[fxtype][fxnumber][0]); // Message Box
	fxtextgob->SetText(allfxboxtxt[fxtype][fxnumber][1]);
	fxtextgoc->SetText(allfxboxtxt[fxtype][fxnumber][2]);

Unlock();

}
// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************
void ALLFX::Clickedallfxwindow(int32 mess_no)
{
int16 number;

int32 listselected;
static char numbertxt[5];

Lock();

// Remember clicking any of these will 
// reset the current selected FX
// in the EDIT window

if (mess_no == 1)  // Radio 1-A
 	{
 	allfxvals[fxtype][fxnumber][4] = 0;
 	}
 	
if (mess_no == 2) // Radio 1-B
 	{
 	allfxvals[fxtype][fxnumber][4] = 1;
 	}

if (mess_no == 3) {}  // this called every time so not point doing anything here

if (mess_no == 4) // Radio 2-A
 	{
 	allfxvals[fxtype][fxnumber][5] = 0;
 	}
 	
if (mess_no == 5) // Radio 2-B
 	{
 	allfxvals[fxtype][fxnumber][5] = 1;
 	}

if (mess_no == 6) //  Effect Selected
	{
	listselected = fxpick->CurrentSelection(0);
	listnumber = listselected;
	
	if (listtype == 0)
		{
		listfxno = listnumber;
		}
	if (listtype == 1)
		{
		listcfxno = listnumber;
		}
	if (listtype == 2)
		{
		listman1no = listnumber;
		}
	if (listtype == 3)
		{
		listman2no = listnumber;
		}
	if (listtype == 4)
		{
		listdmanno = listnumber;
		}
	if (listtype == 5)
		{
		listsfxno = listnumber;
		}
	}

if (mess_no == 8)  //  Sliders 1
	{
	number = fxlev1->Value();
	allfxvals[fxtype][fxnumber][0]=number;
	sprintf(numbertxt,"%d",number);
	fxlevtxt1->SetText(numbertxt);
	}

if (mess_no == 9)  //  Sliders 2
	{
	number = fxlev2->Value();
	allfxvals[fxtype][fxnumber][1]=number;
	sprintf(numbertxt,"%d",number);
	fxlevtxt2->SetText(numbertxt);
	}

if (mess_no == 10)  //  Sliders 3
	{
	number = fxlev3->Value();
	allfxvals[fxtype][fxnumber][2]=number;
	sprintf(numbertxt,"%d",number);
	fxlevtxt3->SetText(numbertxt);
	}

if (mess_no == 11)  //  Sliders 4
	{
	number = fxlev4->Value();
	allfxvals[fxtype][fxnumber][3]=number;
	sprintf(numbertxt,"%d",number);
	fxlevtxt4->SetText(numbertxt);
	}

if (mess_no == 12)  //  Mix Level Slider
	{
	number = fxlev->Value();
	allfxvals[fxtype][fxnumber][6]=number;
	sprintf(numbertxt,"%d",number);
	fxlevtxt->SetText(numbertxt);
	}

if (mess_no == 13)  // Standard FX
	{
	if (listtype != 0)
		{
		listtype = 0;
		}
	Drawlist(0,listtype);
	fxpick->Select(listfxno);
	fxpick->ScrollToSelection();
 	}

if (mess_no == 14)   // Complex FX
	{
	if (listtype != 1)
		{
		listtype = 1;
		}
	Drawlist(0,listtype);
	fxpick->Select(listcfxno);
	fxpick->ScrollToSelection();
	}

if (mess_no == 15)   // Manips 1
	{
	if (listtype != 2)
		{
		listtype = 2;
		}
	Drawlist(0,listtype);
	fxpick->Select(listman1no);
	fxpick->ScrollToSelection();
	}

if (mess_no == 16)   // Manips 2
	{
	if (listtype != 3)
		{
		listtype = 3;
		}
	Drawlist(0,listtype);
	fxpick->Select(listman2no);
	fxpick->ScrollToSelection();
	}

if (mess_no == 17)   // Dual Manips
	{
	if (listtype != 4)
		{
		listtype = 4;
		}
	Drawlist(0,listtype);
	fxpick->Select(listdmanno);
	fxpick->ScrollToSelection();
	}

if (mess_no == 18)   // Stereo FX
	{
	if (listtype != 5)
		{
		listtype = 5;
		}
	Drawlist(0,listtype);
	fxpick->Select(listsfxno);
	fxpick->ScrollToSelection();
	}

if (mess_no == 19)   // Set Default
	{
	if (fxtype == 0)  Setfxvars(fxnumber);
	if (fxtype == 1)  Setcomplexfxvars(fxnumber);
	if (fxtype == 2)  Setmanip1vars(fxnumber);
	if (fxtype == 3)  Setmanip2vars(fxnumber);
	if (fxtype == 4)  Setdualmanipvars(fxnumber);
	if (fxtype == 5)  Setstereofxvars(fxnumber);
	}

// Make sure corrct list is used for MAPPER
	if (listtype == 0)
		{
		listnumber = listfxno;
		}
	if (listtype == 1)
		{
		listnumber = listcfxno;
		}
	if (listtype == 2)
		{
		listnumber = listman1no;
		}
	if (listtype == 3)
		{
		listnumber = listman2no;
		}
	if (listtype == 4)
		{
		listnumber = listdmanno;
		}
	if (listtype == 5)
		{
		listnumber = listsfxno;
		}

// Call MAPPER everytime
fxtype = Mapper(0,listtype,listnumber);
fxnumber = Mapper(1,listtype,listnumber);

if ((mess_no == 6) || ((mess_no >= 12) && (mess_no <=19))) // Update ALLFX window with new values
	{
	Updateallfxwindow(0,fxtype,fxnumber);
	}

if (mess_no == 7) // GO Pressed
	{
	BMessage *msg = new BMessage(ALLFX_FXGO); // Tell App which effect selected
	msg->AddInt32("listtype", listtype);
	msg->AddInt32("listnumber", listnumber);
	be_app->PostMessage(msg,be_app);
	delete msg;
	}

if (mess_no != 7)	// tell BeApp there is a new current effect only
	{
	BMessage *msg = new BMessage(ALLFX_FXCURRENT); // Tell App which effect selected
	msg->AddInt32("listtype", listtype);
	msg->AddInt32("listnumber", listnumber);
	be_app->PostMessage(msg,be_app);
	delete msg;
	}

Unlock();
}


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

// Mapper
// This converts the number from the ALLFX list
// Into the number used for the Effects selected

int16 ALLFX::Mapper(int16 mapoption, int16 listtype, int16 listnumber)
{
int16 mappedno;
int16 mapfxtype=0;
int16 mapfxnumber=0;


if (listtype == 0) // Standard Effects
{
mapfxtype = 0;
if (listnumber == 0) mapfxnumber = 0;  // Reverb
if (listnumber == 1) mapfxnumber = 1;  // Echo
if (listnumber == 2) mapfxnumber = 2;  // Delay
if (listnumber == 3) mapfxnumber = 3;  // Phase Shift
if (listnumber == 4) mapfxnumber = 4;  // Phaser
if (listnumber == 5) mapfxnumber = 5;  // Chorus
if (listnumber == 6) mapfxnumber = 6;  // Flange
if (listnumber == 7) mapfxnumber = 7;  // Distortion
if (listnumber == 8) mapfxnumber = 8;  // Compress
if (listnumber == 9) mapfxnumber = 9;  // Expand
if (listnumber == 10) mapfxnumber = 11;  // Enhance
if (listnumber == 11) mapfxnumber = 12;  // Resample
if (listnumber == 12) mapfxnumber = 13;  // Detune
if (listnumber == 13) mapfxnumber = 14;  // Fade
if (listnumber == 14) mapfxnumber = 15;  // Boost
if (listnumber == 15) mapfxnumber = 16;  // Resolution
if (listnumber == 16) mapfxnumber = 17;  // Bandwidth
if (listnumber == 17) mapfxnumber = 21;  // Alternate
if (listnumber == 18) mapfxnumber = 27;  // Filter Low Pass
if (listnumber == 19) mapfxnumber = 28;  // Filter High Pass
if (listnumber == 20) mapfxnumber = 29;  // Filter Band Pass
if (listnumber == 21) mapfxnumber = 30;  // Filter Band Cut
if (listnumber == 22) mapfxnumber = 31;  // Filter Notch Pass
if (listnumber == 23) mapfxnumber = 32;  // Filter Notch Cut
if (listnumber == 24) mapfxnumber = 33;  // Backwards Reverb
if (listnumber == 25) mapfxnumber = 34;  // Reverb Phaser
if (listnumber == 26) mapfxnumber = 36;  // Reverb Only
if (listnumber == 27) mapfxnumber = 37;  // Long Delay
if (listnumber == 28) mapfxnumber = 38;  // Multi Tap Delay
if (listnumber == 29) mapfxnumber = 39;  // Feedback Delay
if (listnumber == 30) mapfxnumber = 40;  // Bounce Delay
if (listnumber == 31) mapfxnumber = 41;  // Jump Flange
if (listnumber == 32) mapfxnumber = 42;  // Strange Flange
if (listnumber == 33) mapfxnumber = 43;  // Delay Flange
if (listnumber == 34) mapfxnumber = 44;  // Digital Distortion
if (listnumber == 35) mapfxnumber = 45;  // Contortion
if (listnumber == 36) mapfxnumber = 46;  // Mix Contortion
if (listnumber == 37) mapfxnumber = 47;  // Bandwidth Smooth

if (listnumber >= 38) mapfxnumber = 0;  //
}

if (listtype == 1) // Complex Effects
{
mapfxtype = 1;
if (listnumber == 0) mapfxnumber = 80;  // Graphic Equalizer 7 Band
if (listnumber == 1) mapfxnumber = 81;  // Graphic Equalizer 20 Band
if (listnumber == 2) mapfxnumber = 0;  // 1/x
if (listnumber == 3) mapfxnumber = 1;  // acos
if (listnumber == 4) mapfxnumber = 2;  // asin
if (listnumber == 5) mapfxnumber = 3;  // atan
if (listnumber == 6) mapfxnumber = 4;  // cos
if (listnumber == 7) mapfxnumber = 5;  // sin
if (listnumber == 8) mapfxnumber = 6;  // tan
if (listnumber == 9) mapfxnumber = 7;  // cosh
if (listnumber == 10) mapfxnumber = 8;  // sinh
if (listnumber == 11) mapfxnumber = 9;  // tanh
if (listnumber == 12) mapfxnumber = 10;  // acosh
if (listnumber == 13) mapfxnumber = 11;  // asinh
if (listnumber == 14) mapfxnumber = 12;  // atanh
if (listnumber == 15) mapfxnumber = 13;  // sec
if (listnumber == 16) mapfxnumber = 14;  // cosec
if (listnumber == 17) mapfxnumber = 15;  // Cot
if (listnumber == 18) mapfxnumber = 16;  // +Sin
if (listnumber == 19) mapfxnumber = 17;  // exp
if (listnumber == 20) mapfxnumber = 18;  // log
if (listnumber == 21) mapfxnumber = 19;  // log10
if (listnumber == 22) mapfxnumber = 20;  // expm1
if (listnumber == 23) mapfxnumber = 21;  // log1p
if (listnumber == 24) mapfxnumber = 22;  // logb
if (listnumber == 25) mapfxnumber = 23;  // +Log
if (listnumber == 26) mapfxnumber = 24;  // sqrt
if (listnumber == 27) mapfxnumber = 25;  // cbrt
if (listnumber == 28) mapfxnumber = 26;  // ceil
if (listnumber == 29) mapfxnumber = 27;  // fabs
if (listnumber == 30) mapfxnumber = 28;  // floor
if (listnumber == 31) mapfxnumber = 29;  // significand
if (listnumber == 32) mapfxnumber = 30;  // j0
if (listnumber == 33) mapfxnumber = 31;  // j1
if (listnumber == 34) mapfxnumber = 32;  // y0
if (listnumber == 35) mapfxnumber = 33;  // y1
if (listnumber == 36) mapfxnumber = 34;  // erf
if (listnumber == 37) mapfxnumber = 35;  // erfc
if (listnumber == 38) mapfxnumber = 36;  // gamma
if (listnumber == 39) mapfxnumber = 37;  // lgamma
if (listnumber == 40) mapfxnumber = 38;  // rint
if (listnumber == 41) mapfxnumber = 39;  // ilogbf
if (listnumber == 42) mapfxnumber = 40;  // Delay 1/x
if (listnumber == 43) mapfxnumber = 41;  // Delay acos
if (listnumber == 44) mapfxnumber = 42;  // Delay asin
if (listnumber == 45) mapfxnumber = 43;  // Delay atan
if (listnumber == 46) mapfxnumber = 44;  // Delay cos
if (listnumber == 47) mapfxnumber = 45;  // Delay sin
if (listnumber == 48) mapfxnumber = 46;  // Delay tan
if (listnumber == 49) mapfxnumber = 47;  // Delay cosh
if (listnumber == 50) mapfxnumber = 48;  // Delay sinh
if (listnumber == 51) mapfxnumber = 49;  // Delay tanh
if (listnumber == 52) mapfxnumber = 50;  // Delay acosh
if (listnumber == 53) mapfxnumber = 51;  // Delay asinh
if (listnumber == 54) mapfxnumber = 52;  // Delay atanh
if (listnumber == 55) mapfxnumber = 53;  // Delay sec
if (listnumber == 56) mapfxnumber = 54;  // Delay cosec
if (listnumber == 57) mapfxnumber = 55;  // Delay Cot
if (listnumber == 58) mapfxnumber = 56;  // Delay +Sin
if (listnumber == 59) mapfxnumber = 57;  // Delay exp
if (listnumber == 60) mapfxnumber = 58;  // Delay log
if (listnumber == 61) mapfxnumber = 59;  // Delay log10
if (listnumber == 62) mapfxnumber = 60;  // Delay expm1
if (listnumber == 63) mapfxnumber = 61;  // Delay log1p
if (listnumber == 64) mapfxnumber = 62;  // Delay logb
if (listnumber == 65) mapfxnumber = 63;  // Delay +Log
if (listnumber == 66) mapfxnumber = 64;  // Delay sqrt
if (listnumber == 67) mapfxnumber = 65;  // Delay cbrt
if (listnumber == 68) mapfxnumber = 66;  // Delay ceil
if (listnumber == 69) mapfxnumber = 67;  // Delay fabs
if (listnumber == 70) mapfxnumber = 68;  // Delay floor
if (listnumber == 71) mapfxnumber = 69;  // Delay significand
if (listnumber == 72) mapfxnumber = 70;  // Delay j0
if (listnumber == 73) mapfxnumber = 71;  // Delay j1
if (listnumber == 74) mapfxnumber = 72;  // Delay y0
if (listnumber == 75) mapfxnumber = 73;  // Delay y1
if (listnumber == 76) mapfxnumber = 74;  // Delay erf
if (listnumber == 77) mapfxnumber = 75;  // Delay erfc
if (listnumber == 78) mapfxnumber = 76;  // Delay gamma
if (listnumber == 79) mapfxnumber = 77;  // Delay lgamma
if (listnumber == 80) mapfxnumber = 78;  // Delay rint
if (listnumber == 81) mapfxnumber = 79;  // Delay ilogbf

if (listnumber >= 82) mapfxnumber = 0;
}

if (listtype == 2) // Manipulations A
{
mapfxtype = 2;
if (listnumber == 0) mapfxnumber = 0;  // Invert
if (listnumber == 1) mapfxnumber = 1;  // Half Wave Rectify
if (listnumber == 2) mapfxnumber = 2;  // Full Wave Rectify
if (listnumber == 3) mapfxnumber = 3;  // Flip
if (listnumber == 4) mapfxnumber = 4;  // Centre
if (listnumber == 5) mapfxnumber = 5;  // Reverse
if (listnumber == 6) mapfxnumber = 6;  // Clean
if (listnumber == 7) mapfxnumber = 7;  // Thicken
if (listnumber == 8) mapfxnumber = 8;  // Double Thicken
if (listnumber == 9) mapfxnumber = 11;  // Quarter Value
if (listnumber == 10) mapfxnumber = 12;  // Half Value
if (listnumber == 11) mapfxnumber = 13;  // Double Value
if (listnumber == 12) mapfxnumber = 14;  // Quadruple Value
if (listnumber == 13) mapfxnumber = 15;  // Fade In
if (listnumber == 14) mapfxnumber = 16;  // Fade Out
if (listnumber == 15) mapfxnumber = 17;  // Recreate
if (listnumber == 16) mapfxnumber = 18;  // Loudness
if (listnumber == 17) mapfxnumber = 19;  // UnLoudness
if (listnumber == 18) mapfxnumber = 20;  // Filter Very High
if (listnumber == 19) mapfxnumber = 21;  // Filter High Band
if (listnumber == 20) mapfxnumber = 22;  // Filter High Mid
if (listnumber == 21) mapfxnumber = 23;  // Filter Mid Band
if (listnumber == 22) mapfxnumber = 24;  // Filter Low Mid
if (listnumber == 23) mapfxnumber = 25;  // Filter Low Band
if (listnumber == 24) mapfxnumber = 26;  // Filter Sub Bass
if (listnumber == 25) mapfxnumber = 27;  // Tune 2 Octaves
if (listnumber == 26) mapfxnumber = 28;  // Tune Octave
if (listnumber == 27) mapfxnumber = 29;  // Tune Note
if (listnumber == 28) mapfxnumber = 30;  // Tune Semitone
if (listnumber == 29) mapfxnumber = 31;  // Tune 1/8 Note
if (listnumber == 30) mapfxnumber = 32;  // Zero Out
if (listnumber == 31) mapfxnumber = 33;  // More +/-
if (listnumber == 32) mapfxnumber = 34;  // Blur Filter
if (listnumber == 33) mapfxnumber = 35;  // 2D Blur Filter
if (listnumber == 34) mapfxnumber = 36;  // Auto Stutter
if (listnumber == 35) mapfxnumber = 37;  // Strange Delay
if (listnumber == 36) mapfxnumber = 38;  // Stranger Delay
if (listnumber == 37) mapfxnumber = 41;  // Half Distortion
if (listnumber == 38) mapfxnumber = 42;  // Half Contortion

if (listnumber >= 39) mapfxnumber = 0;  //
}

if (listtype == 3) // Manipulations B
{
mapfxtype = 3;
if (listnumber == 0) mapfxnumber = 0;  // Over
if (listnumber == 1) mapfxnumber = 1;  // Under
if (listnumber == 2) mapfxnumber = 2;  // In Between
if (listnumber == 3) mapfxnumber = 3;  // Out Between
if (listnumber == 4) mapfxnumber = 4;  // Limit Low
if (listnumber == 5) mapfxnumber = 5;  // Limit High
if (listnumber == 6) mapfxnumber = 6;  // Add Spikes
if (listnumber == 7) mapfxnumber = 7;  // Delete Spikes
if (listnumber == 8) mapfxnumber = 8;  // Capacitance
if (listnumber == 9) mapfxnumber = 9;  // Replacement
if (listnumber == 10) mapfxnumber = 10;  // Tear
if (listnumber == 11) mapfxnumber = 11;  // SwapByteOrder
if (listnumber == 12) mapfxnumber = 12;  // Delta
if (listnumber == 13) mapfxnumber = 13;  // Square
if (listnumber == 14) mapfxnumber = 14;  // Half Square
if (listnumber == 15) mapfxnumber = 18;  // Transform Blocks
if (listnumber == 16) mapfxnumber = 19;  // Reverse Single Blocks
if (listnumber == 17) mapfxnumber = 20;  // Reverse All Blocks
if (listnumber == 18) mapfxnumber = 21;  // Skip Blocks
if (listnumber == 19) mapfxnumber = 22;  // Repeat Blocks
if (listnumber == 20) mapfxnumber = 23;  // Unorder Samples
if (listnumber == 21) mapfxnumber = 24;  // Unorder Blocks
if (listnumber == 22) mapfxnumber = 26;  // Flip Alternate
if (listnumber == 23) mapfxnumber = 27;  // Ramdom Amplifier
if (listnumber == 24) mapfxnumber = 29;  // Swap Halves
if (listnumber == 25) mapfxnumber = 30;  // Remove Center
if (listnumber == 26) mapfxnumber = 31;  // Add Centre
if (listnumber == 27) mapfxnumber = 32;  // Remove Flat
if (listnumber == 28) mapfxnumber = 33;  // Keep Flat
if (listnumber == 29) mapfxnumber = 34;  // Remove Middle
if (listnumber == 30) mapfxnumber = 35;  // Transmogrify
if (listnumber == 31) mapfxnumber = 36;  // Non-Transmogrify
if (listnumber == 32) mapfxnumber = 37;  // Delay Delta
if (listnumber == 33) mapfxnumber = 38;  // Delay Backwards Subtract
if (listnumber == 34) mapfxnumber = 39;  // Delay Multiply
if (listnumber == 35) mapfxnumber = 40;  // Delay Divide
if (listnumber == 36) mapfxnumber = 41;  // Delay Backwards Divide
if (listnumber == 37) mapfxnumber = 42;  // Delay AND
if (listnumber == 38) mapfxnumber = 43;  // Delay OR
if (listnumber == 39) mapfxnumber = 44;  // Delay XOR
if (listnumber == 40) mapfxnumber = 45;  // Delay Rectify
if (listnumber == 41) mapfxnumber = 46;  // Delay Greater
if (listnumber == 42) mapfxnumber = 47;  // Delay Lesser
if (listnumber == 43) mapfxnumber = 48;  // Delay Interleave
if (listnumber == 44) mapfxnumber = 49;  // Delay Modulus
if (listnumber == 45) mapfxnumber = 50;  // Delay Backwards Modulus
if (listnumber == 46) mapfxnumber = 51;  // Noise
if (listnumber == 47) mapfxnumber = 52;  // Filtered Noise
if (listnumber == 48) mapfxnumber = 53;  // Rumble
if (listnumber == 49) mapfxnumber = 54;  // Chaos
if (listnumber == 50) mapfxnumber = 55;  // Random

if (listnumber >= 51) mapfxnumber = 0;  //
}

if (listtype == 4) // Dual Manipulations
{
mapfxtype = 4;
if (listnumber == 0) mapfxnumber = 4;  // Powered Compress
if (listnumber == 1) mapfxnumber = 5;  // Powered Expand
if (listnumber == 2) mapfxnumber = 6;  // Half Rectify and Add
if (listnumber == 3) mapfxnumber = 7;  // Full Rectify and Add
if (listnumber == 4) mapfxnumber = 8;  // Add
if (listnumber == 5) mapfxnumber = 9;  // Subtract
if (listnumber == 6) mapfxnumber = 10;  // Backwards Subtract
if (listnumber == 7) mapfxnumber = 11;  // Multiply
if (listnumber == 8) mapfxnumber = 12;  // Divide
if (listnumber == 9) mapfxnumber = 13;  // Backwards Divide
if (listnumber == 10) mapfxnumber = 14;  // AND
if (listnumber == 11) mapfxnumber = 15;  // OR
if (listnumber == 12) mapfxnumber = 16;  // XOR
if (listnumber == 13) mapfxnumber = 17;  // Greater
if (listnumber == 14) mapfxnumber = 18;  // Lesser
if (listnumber == 15) mapfxnumber = 19;  // Interleave
if (listnumber == 16) mapfxnumber = 20;  // Rectify
if (listnumber == 17) mapfxnumber = 21;  // Stutter
if (listnumber == 18) mapfxnumber = 22;  // Modulus
if (listnumber == 19) mapfxnumber = 23;  // Backwards Modulus
if (listnumber == 20) mapfxnumber = 27;  // Amplitude Modulation

if (listnumber >= 21) mapfxnumber = 0;  // 
}

if (listtype == 5) // Stereo Effects
{
mapfxtype = 5;
if (listnumber == 0) mapfxnumber = 0;  // Stereo Reverb
if (listnumber == 1) mapfxnumber = 1;  // Stereo Reverb Only
if (listnumber == 2) mapfxnumber = 9;  // Swap Sides Left<->Right
if (listnumber == 3) mapfxnumber = 12;  // Cross Fade Left<->Right
if (listnumber == 4) mapfxnumber = 13;  // Cross Fade Stereo Mono
if (listnumber == 5) mapfxnumber = 15;  // Pan Manual
if (listnumber == 6) mapfxnumber = 16;  // Pan Ping Pong
if (listnumber == 7) mapfxnumber = 17;  // Pan Mono Left
if (listnumber == 8) mapfxnumber = 18;  // Pan Mono Right
if (listnumber == 9) mapfxnumber = 35;  // Add
if (listnumber == 10) mapfxnumber = 36;  // Subtract
if (listnumber == 11) mapfxnumber = 37;  // Backwards Subtract
if (listnumber == 12) mapfxnumber = 38;  // Multiply
if (listnumber == 13) mapfxnumber = 39;  // Divide
if (listnumber == 14) mapfxnumber = 40;  // Backwards Divide
if (listnumber == 15) mapfxnumber = 41;  // AND
if (listnumber == 16) mapfxnumber = 42;  // OR
if (listnumber == 17) mapfxnumber = 43;  // XOR
if (listnumber == 18) mapfxnumber = 44;  // Greater
if (listnumber == 19) mapfxnumber = 45;  // Lesser
if (listnumber == 20) mapfxnumber = 46;  // Interleave
if (listnumber == 21) mapfxnumber = 47;  // Modulus
if (listnumber == 22) mapfxnumber = 48;  // Backwards Modulus
if (listnumber == 23) mapfxnumber = 49;  // Stutter
if (listnumber == 24) mapfxnumber = 50;  // Rectify
if (listnumber >= 25) mapfxnumber = 0;  // 
}


if (mapoption == 0) mappedno = mapfxtype;
if (mapoption == 1) mappedno = mapfxnumber;

return mappedno;
}


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

// Handling of user interface and other events
void ALLFX::MessageReceived(BMessage *message)
{

//	message->PrintToStream();
//	BWindow::MessageReceived(message);

	switch(message->what){
		case ALLFX_FXADD1A:	// 'fxadd1a' is pressed...
		Clickedallfxwindow(1);
			break;

		case ALLFX_FXADD1B:	// 'fxadd1b' is pressed...
		Clickedallfxwindow(2);
			break;

		case ALLFX_FXSET:	// 'fxset' is pressed...
		Clickedallfxwindow(3);
			break;

		case ALLFX_FXADD2A:	// 'fxadd2a' is pressed...
		Clickedallfxwindow(4);
			break;

		case ALLFX_FXADD2B:	// 'fxadd2b' is pressed...
		Clickedallfxwindow(5);
			break;

		case ALLFX_FXPICK_SELECTION:	// list item is selected in 'fxpick' 
		Clickedallfxwindow(6);
			break;

		case ALLFX_FXPICK_INVOCATION:	// list item is invoked in 'fxpick' 
		Clickedallfxwindow(6);
			break;

		case ALLFX_FXGO:	// 'fxgo' is pressed...
		Clickedallfxwindow(7);
			break;

		case ALLFX_FXLEV1:	// 'fxlev1' is operated...
		Clickedallfxwindow(8);
			break;

		case ALLFX_FXLEV2:	// 'fxlev2' is operated...
		Clickedallfxwindow(9);
			break;

		case ALLFX_FXLEV3:	// 'fxlev3' is operated...
		Clickedallfxwindow(10);
			break;

		case ALLFX_FXLEV4:	// 'fxlev4' is operated...
		Clickedallfxwindow(11);
			break;

		case ALLFX_FXLEV:	// 'fxlev' is operated...
		Clickedallfxwindow(12);
			break;

		case ALLFX_FXTYPE_STANDARD_FX:	// "Standard FX" is selected from menufield 'fxtype'
		Clickedallfxwindow(13);
			break;

		case ALLFX_FXTYPE_COMPLEX_FX:	// "Complex FX" is selected from menufield 'fxtype'
		Clickedallfxwindow(14);
			break;

		case ALLFX_FXTYPE_MANIPS_1:	// "Manips 1" is selected from menufield 'fxtype'
		Clickedallfxwindow(15);
			break;

		case ALLFX_FXTYPE_MANIPS_2:	// "Manips 2" is selected from menufield 'fxtype'
		Clickedallfxwindow(16);
			break;

		case ALLFX_FXTYPE_DUAL_MANIPS:	// "Dual Manips" is selected from menufield 'fxtype'
		Clickedallfxwindow(17);
			break;

		case ALLFX_FXTYPE_STEREO_FX:	// "Stereo FX" is selected from menufield 'fxtype'
		Clickedallfxwindow(18);
			break;

		case ALLFX_FXDEFAULT:	// 'fxdefault' is pressed...
		Clickedallfxwindow(19);
			break;

// Messages from elsewhere
//
		case APP_GETSETTINGS:	// 'fxdefault' is pressed...
		Sendgodata();
		break;

		case IAP_REQSET:	// Request settings for individual window
		message->FindInt16("iewtyp", &iewtyp);
		Sendiewdata(0);
		break;

		case IAPGO_REQSET:	// GO pressed, request settings for Effector
		message->FindInt16("iewtyp", &iewtyp);
		Sendiewdata(1);
		break;

		case IAP_NEWVAL:	// New Val in IEW
		//message->FindInt32("listtype", &listtype);
		message->FindInt32("listnumber", &listnumber);
		message->FindInt32("fxtype", &fxtype);
		message->FindInt32("fxnumber", &fxnumber);
		message->FindInt16("iewmsgtyp", &iewmsgtyp);
		message->FindInt16("iewtyp", &iewtyp);
		message->FindInt16("eq0lev", &iewvals[iewtyp][0]);
		message->FindInt16("eq1lev", &iewvals[iewtyp][1]);
		message->FindInt16("eq2lev", &iewvals[iewtyp][2]);
		message->FindInt16("eq3lev", &iewvals[iewtyp][3]);
		message->FindInt16("eq4lev", &iewvals[iewtyp][4]);
		message->FindInt16("eq5lev", &iewvals[iewtyp][5]);
		message->FindInt16("eq6lev", &iewvals[iewtyp][6]);
		message->FindInt16("eq7lev", &iewvals[iewtyp][7]);
		message->FindInt16("eq8lev", &iewvals[iewtyp][8]);
		message->FindInt16("eq9lev", &iewvals[iewtyp][9]);
		message->FindInt16("eq10lev", &iewvals[iewtyp][10]);
		message->FindInt16("eq11lev", &iewvals[iewtyp][11]);
		message->FindInt16("eq12lev", &iewvals[iewtyp][12]);
		message->FindInt16("eq13lev", &iewvals[iewtyp][13]);
		message->FindInt16("eq14lev", &iewvals[iewtyp][14]);
		message->FindInt16("eq15lev", &iewvals[iewtyp][15]);
		message->FindInt16("eq16lev", &iewvals[iewtyp][16]);
		message->FindInt16("eq17lev", &iewvals[iewtyp][17]);
		message->FindInt16("eq18lev", &iewvals[iewtyp][18]);
		message->FindInt16("eq19lev", &iewvals[iewtyp][19]);
		message->FindInt16("eq20lev", &iewvals[iewtyp][20]);
		Setwindoweffect();
		break;

		case APP_MONO:		// Mono mode
		Setmode(0);
			break;
			
		case APP_STEREO:	// Stereo mode
		Setmode(1);
			break;

		default:
			inherited::MessageReceived(message);
			break;
	}

}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************


void ALLFX::Setallfxvars(void)
{
int16 setoutcount;
int16 setincount;

// set arrarys with default vals
for (setoutcount=0;setoutcount<=5;setoutcount++)
	{
	for (setincount=0;setincount<=83;setincount++)
		{
		sprintf(allfxtxt[setoutcount][setincount][0]," ");
		sprintf(allfxtxt[setoutcount][setincount][1]," ");
		sprintf(allfxtxt[setoutcount][setincount][2]," ");
		sprintf(allfxtxt[setoutcount][setincount][3]," ");
		sprintf(allfxtxt[setoutcount][setincount][4]," ");
		sprintf(allfxtxt[setoutcount][setincount][5]," ");
		sprintf(allfxtxt[setoutcount][setincount][6]," ");
		sprintf(allfxtxt[setoutcount][setincount][7]," ");
		sprintf(allfxtxt[setoutcount][setincount][8],"Mix Level");

		sprintf(allfxboxtxt[setoutcount][setincount][0], " ");
		sprintf(allfxboxtxt[setoutcount][setincount][1], " ");
		sprintf(allfxboxtxt[setoutcount][setincount][2], " ");

		allfxghosts[setoutcount][setincount][0]=0;
		allfxghosts[setoutcount][setincount][1]=0;
		allfxghosts[setoutcount][setincount][2]=0;
		allfxghosts[setoutcount][setincount][3]=0;
		allfxghosts[setoutcount][setincount][4]=0;
		allfxghosts[setoutcount][setincount][5]=0;
		allfxghosts[setoutcount][setincount][6]=0;

		allfxvals[setoutcount][setincount][0]=0; // vals might be setup elsewhere
		allfxvals[setoutcount][setincount][1]=0;
		allfxvals[setoutcount][setincount][2]=0;
		allfxvals[setoutcount][setincount][3]=0;
		allfxvals[setoutcount][setincount][4]=0;
		allfxvals[setoutcount][setincount][5]=1;
		allfxvals[setoutcount][setincount][6]=256;
		}
	Sendsetmessage((setoutcount+1));
	}
	
for (setincount=0;setincount<=63;setincount++)
	{
	Setfxvars(setincount);
	}
Sendsetmessage(7);

for (setincount=0;setincount<=83;setincount++)
	{
	Setcomplexfxvars(setincount);
	}
Sendsetmessage(8);

for (setincount=0;setincount<=63;setincount++)
	{
	Setmanip1vars(setincount);
	}
Sendsetmessage(9);

for (setincount=0;setincount<=63;setincount++)
	{
	Setmanip2vars(setincount);
	}
Sendsetmessage(10);

for (setincount=0;setincount<=63;setincount++)
	{
	Setdualmanipvars(setincount);
	}
Sendsetmessage(11);

for (setincount=0;setincount<=63;setincount++)
	{
	Setstereofxvars(setincount);
	}
Sendsetmessage(12);

iewvals[0][0]=128;	// EQ7
iewvals[0][1]=128;
iewvals[0][2]=128;
iewvals[0][3]=128;
iewvals[0][4]=128;
iewvals[0][5]=128;
iewvals[0][6]=128;
iewvals[0][7]=128;

iewvals[0][0]=512;	// EQ20
iewvals[1][1]=128;
iewvals[1][2]=128;
iewvals[1][3]=128;
iewvals[1][4]=128;
iewvals[1][5]=128;
iewvals[1][6]=128;
iewvals[1][7]=128;
iewvals[1][8]=128;
iewvals[1][9]=128;
iewvals[1][10]=128;
iewvals[1][11]=128;
iewvals[1][12]=128;
iewvals[1][13]=128;
iewvals[1][14]=128;
iewvals[1][15]=128;
iewvals[1][16]=128;
iewvals[1][17]=128;
iewvals[1][18]=128;
iewvals[1][19]=128;
iewvals[1][20]=128;

Sendsetmessage(0);
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

void ALLFX::Sendsetmessage(int16 drawlen)
{

	BMessage *msg = new BMessage(FXR_DRAWBAR);
	msg->AddInt16("apbar1", 2);
	msg->AddInt16("apbar2", 12);
	msg->AddInt16("apbar3", drawlen);
	msg->AddInt16("apbar4", 0);
	msg->AddInt16("apbar5", 0);
	msg->AddInt16("apbar6", 0);
	be_app->PostMessage(msg,be_app);
	delete (msg);
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************
void ALLFX::Sendgodata(void)
{
//	this sends all the settings to the be_app
int16 slider1;
int16 slider2;
int16 slider3;
int16 slider4;
int16 slider;
int16 radio1;
int16 radio2;

slider1 = allfxvals[fxtype][fxnumber][0];
slider2 = allfxvals[fxtype][fxnumber][1];
slider3 = allfxvals[fxtype][fxnumber][2];
slider4 = allfxvals[fxtype][fxnumber][3];
slider = allfxvals[fxtype][fxnumber][6];
radio1 = allfxvals[fxtype][fxnumber][4];
radio2 = allfxvals[fxtype][fxnumber][5];

BMessage *msg = new BMessage(ALLFX_SETTINGS);
msg->AddInt32("listtype", listtype);
msg->AddInt32("listnumber", listnumber);
msg->AddInt32("fxtype", fxtype);
msg->AddInt32("fxnumber", fxnumber);
msg->AddInt16("slider1", slider1);
msg->AddInt16("slider2", slider2);
msg->AddInt16("slider3", slider3);
msg->AddInt16("slider4", slider4);
msg->AddInt16("slider", slider);
msg->AddInt16("radio1", radio1);
msg->AddInt16("radio2", radio2);
be_app->PostMessage(msg,be_app);
delete (msg);
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************
void ALLFX::Sendiewdata(int32 whichdata)
{
//	this sends all the IEW settings to the be_app

if (whichdata == 0)	// Settings to update window
	{
	BMessage *msg = new BMessage(IAL_SET);
	msg->AddInt32("listtype", listtype);
	msg->AddInt32("listnumber", listnumber);
	msg->AddInt32("fxtype", fxtype);
	msg->AddInt32("fxnumber", fxnumber);
	msg->AddInt16("iewmsgtyp", iewmsgtyp);	//
	msg->AddInt16("iewtyp", iewtyp);
	msg->AddInt16("eq0lev", iewvals[iewtyp][0]);
	msg->AddInt16("eq1lev", iewvals[iewtyp][1]);
	msg->AddInt16("eq2lev", iewvals[iewtyp][2]);
	msg->AddInt16("eq3lev", iewvals[iewtyp][3]);
	msg->AddInt16("eq4lev", iewvals[iewtyp][4]);
	msg->AddInt16("eq5lev", iewvals[iewtyp][5]);
	msg->AddInt16("eq6lev", iewvals[iewtyp][6]);
	msg->AddInt16("eq7lev", iewvals[iewtyp][7]);
	msg->AddInt16("eq8lev", iewvals[iewtyp][8]);
	msg->AddInt16("eq9lev", iewvals[iewtyp][9]);
	msg->AddInt16("eq10lev", iewvals[iewtyp][10]);
	msg->AddInt16("eq11lev", iewvals[iewtyp][11]);
	msg->AddInt16("eq12lev", iewvals[iewtyp][12]);
	msg->AddInt16("eq13lev", iewvals[iewtyp][13]);
	msg->AddInt16("eq14lev", iewvals[iewtyp][14]);
	msg->AddInt16("eq15lev", iewvals[iewtyp][15]);
	msg->AddInt16("eq16lev", iewvals[iewtyp][16]);
	msg->AddInt16("eq17lev", iewvals[iewtyp][17]);
	msg->AddInt16("eq18lev", iewvals[iewtyp][18]);
	msg->AddInt16("eq19lev", iewvals[iewtyp][19]);
	msg->AddInt16("eq20lev", iewvals[iewtyp][20]);
	be_app->PostMessage(msg,be_app);
	delete (msg);
	}

if (whichdata == 1)	// GO pressed, Settings for Effector
	{
	BMessage *msg = new BMessage(IALGO_SET);
	msg->AddInt32("listtype", listtype);
	msg->AddInt32("listnumber", listnumber);
	msg->AddInt32("fxtype", fxtype);
	msg->AddInt32("fxnumber", fxnumber);
	msg->AddInt16("iewmsgtyp", iewmsgtyp);	// 1=Send to Effector 5=settings te EQ window
	msg->AddInt16("iewtyp", iewtyp);
	msg->AddInt16("eq0lev", iewvals[iewtyp][0]);
	msg->AddInt16("eq1lev", iewvals[iewtyp][1]);
	msg->AddInt16("eq2lev", iewvals[iewtyp][2]);
	msg->AddInt16("eq3lev", iewvals[iewtyp][3]);
	msg->AddInt16("eq4lev", iewvals[iewtyp][4]);
	msg->AddInt16("eq5lev", iewvals[iewtyp][5]);
	msg->AddInt16("eq6lev", iewvals[iewtyp][6]);
	msg->AddInt16("eq7lev", iewvals[iewtyp][7]);
	msg->AddInt16("eq8lev", iewvals[iewtyp][8]);
	msg->AddInt16("eq9lev", iewvals[iewtyp][9]);
	msg->AddInt16("eq10lev", iewvals[iewtyp][10]);
	msg->AddInt16("eq11lev", iewvals[iewtyp][11]);
	msg->AddInt16("eq12lev", iewvals[iewtyp][12]);
	msg->AddInt16("eq13lev", iewvals[iewtyp][13]);
	msg->AddInt16("eq14lev", iewvals[iewtyp][14]);
	msg->AddInt16("eq15lev", iewvals[iewtyp][15]);
	msg->AddInt16("eq16lev", iewvals[iewtyp][16]);
	msg->AddInt16("eq17lev", iewvals[iewtyp][17]);
	msg->AddInt16("eq18lev", iewvals[iewtyp][18]);
	msg->AddInt16("eq19lev", iewvals[iewtyp][19]);
	msg->AddInt16("eq20lev", iewvals[iewtyp][20]);
	be_app->PostMessage(msg,be_app);
	delete (msg);
	}
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

void ALLFX::Setmode(int32 viewmode)
{
Lock();
if (viewmode == 0) // Mono
	{
	if (listtype == 5)
		{
		fxfxmenuitem->SetMarked(1);
		PostMessage(ALLFX_FXTYPE_STANDARD_FX,NULL);
		}
	sfxmenuitem->SetEnabled(0);
	}
if (viewmode == 1) // Stereo
	{
	sfxmenuitem->SetEnabled(1);
	}
Unlock();
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

void ALLFX::Setwindoweffect(void)
{
Lock();

if (listtype != 1)
	{
	listtype = 1;
	Drawlist(0,listtype);
	cfxmenuitem->SetMarked(1);
	}
if (iewtyp == 0) listnumber = 0;
if (iewtyp == 1) listnumber = 1;
if (listcfxno != listnumber)
	{
	listcfxno=listnumber;
	fxpick->Select(listcfxno);
	fxpick->ScrollToSelection();
	}


Unlock();
}

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************



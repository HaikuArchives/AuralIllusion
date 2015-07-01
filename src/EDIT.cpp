// EDIT.cpp 
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
#include <View.h>
#include <Window.h>

#include <stdio.h>
#include <stdlib.h>

#include "EDIT.h"
//#include "AudioRoutine.h"

// used to display the current effect / operation
int32 edlisttype=22;
int32 edlistnumber=1;
int32 bacedlisttype=22;
int32 bacedlistnumber=1;

int16 edvalue=0; // used to transfer values of sliders etc.
int32 othergoclicked=1; // used to stop Bmessage being sent

int16 drawbarmode; // For Drawbar
int16 drawbar1;
int16 drawbar2;
int16 drawbar3;
int16 drawbar4;
int16 drawbar5;

int32 apcusrval;
int32 aprngval;
int32 apzoneval;
int32 edcusrval;
int32 edrngval;
int32 edzoneval;
char cusrtxt[9];
char rngtxt[9];
char zonetxt[9];

static int32 drawlen=0;
char progresstxt[20];

BBox* viewdrawbarbox; // progress bar / box
char txt[256]; // used for writing into message box
int32 number; // for testing sliders
BView* drawbar;
BButton* undo;

BStringView* cusrvaltext;
BStringView* rangevaltext;
BStringView* zonevaltext;


//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

EDIT::EDIT(void)
	: BWindow(BRect(4,456,588,596), "Aural illusion v4.0 - Alpha 5", B_TITLED_WINDOW_LOOK, B_NORMAL_WINDOW_FEEL,0)
{

	BView* editview = new BView(BRect(-1,0,585,140), "editview", B_FOLLOW_ALL, B_WILL_DRAW);

	editview->SetFontSize(10.0); // use for everything

	// Go & Undo buttons
	go = new BButton(BRect(3,2,59,38), "go", "GO",							new BMessage(EDIT_EDITGO));
	go->MakeDefault(1); // set as default for fancy surround
	go->SetFont(be_bold_font);
	editview->AddChild(go);

	undo = new BButton(BRect(69,0,125,20), "undo", "UNDO",					new BMessage(EDIT_EDITUNDO));
	//undo->SetEnabled(0);  //disabled
	undo->SetFont(be_bold_font);
	editview->AddChild(undo);

	// position cotrols
	zoomin = new BButton(BRect(135,0,175,20), "zoomin", "> <",				new BMessage(EDIT_EDITZOOMIN));
	editview->AddChild(zoomin);
	
	zoomout = new BButton(BRect(175,0,215,20), "zoomout", "< >",				new BMessage(EDIT_EDITZOOMOUT));
	editview->AddChild(zoomout);
	
	start = new BButton(BRect(225,0,265,20), "start", "|<",					new BMessage(EDIT_EDITSTART));
	editview->AddChild(start);
	
	fastback = new BButton(BRect(265,0,305,20), "fastback", "<<",			new BMessage(EDIT_EDITFASTBACK));
	editview->AddChild(fastback);
	
	back = new BButton(BRect(305,0,345,20), "back", " < ",					new BMessage(EDIT_EDITBACK));
	editview->AddChild(back);
	
	forward = new BButton(BRect(345,0,385,20), "forward", " > ",			new BMessage(EDIT_EDITFORWARD));
	editview->AddChild(forward);
	
	fastforward = new BButton(BRect(385,0,425,20), "fastforward", ">>",		new BMessage(EDIT_EDITFASTFORWARD));
	editview->AddChild(fastforward);
	
	end = new BButton(BRect(425,0,465,20), "end", ">|",						new BMessage(EDIT_EDITEND));
	editview->AddChild(end);
	
	
	// Checkbox for draw
//	draw = new BCheckBox(BRect(524,2,572,18), "draw", "Draw",				 new BMessage(EDIT_EDITDRAW));
//	draw->SetValue(1);
//	editview->AddChild(draw);

	// Checkbox for loop
	loop = new BCheckBox(BRect(500,2,544,18), "loop", "Loop",				new BMessage(EDIT_EDITLOOP));
	loop->SetEnabled(0);
	editview->AddChild(loop);
	
	
	// View for Message box
	BView* messageboxview = new BView(BRect(64,25,300,39), "messageboxview", B_FOLLOW_ALL, B_WILL_DRAW);
		
	messageboxstring = new BStringView(BRect(2,3,235,14), "messageboxstring",
							"Executing Attempted suicide by Chocolate moose", B_FOLLOW_ALL, B_WILL_DRAW);
	messageboxstring->SetHighColor(255,255,255); // text to white
	messageboxview->AddChild(messageboxstring);
		
	messageboxview->SetViewColor(0,0,0); // background to black
	editview->AddChild(messageboxview);


	// Main button bank
	// cut - rangeall
	setzone = new BButton(BRect(1,40,61,60), "setzone", "Set Zone",		new BMessage(EDIT_EDITSETZONE));
	editview->AddChild(setzone);
	
	cut = new BButton(BRect(61,40,121,60), "cut", "Cut",						new BMessage(EDIT_EDITCUT));
	editview->AddChild(cut);
	
	playview = new BButton(BRect(121,40,181,60), "playview", "Play View",	new BMessage(EDIT_EDITPLAYVIEW));
	editview->AddChild(playview);
	
	showrng = new BButton(BRect(181,40,241,60), "showrng", "Show Rng",		new BMessage(EDIT_EDITSHOWRNG));
	editview->AddChild(showrng);

	// pasteover - scale
	lr = new BButton(BRect(241,40,271,60), "lr", "L>R",						new BMessage(EDIT_EDITLR));
	lr->SetEnabled(0);  //disabled
	editview->AddChild(lr);

	rl = new BButton(BRect(271,40,301,60), "rl", "R>L",					new BMessage(EDIT_EDITRL));
	rl->SetEnabled(0);  //disabled
	editview->AddChild(rl);


	// copy - zero
	zoneover = new BButton(BRect(1,62,61,82), "zoneover", "Zone Over",	new BMessage(EDIT_EDITZONEOVER));
	editview->AddChild(zoneover);
	
	copy = new BButton(BRect(61,62,121,82), "copy", "To Clip",					new BMessage(EDIT_EDITCOPY));
	copy->SetEnabled(0);
	editview->AddChild(copy);
	
	playrange = new BButton(BRect(121,62,181,82), "playrange", "PlayRange",	new BMessage(EDIT_EDITPLAYRANGE));
	editview->AddChild(playrange);
	
	showall = new BButton(BRect(181,62,241,82), "showall", "Show All",		new BMessage(EDIT_EDITSHOWALL));
	editview->AddChild(showall);
	
	zero = new BButton(BRect(241,62,301,82), "zero", "Zero",				new BMessage(EDIT_EDITZERO));
	editview->AddChild(zero);


	//paste into - rescale
	zoneinto = new BButton(BRect(1,84,61,104), "zoneinto", "Zone Into",	new BMessage(EDIT_EDITZONEINTO));
	editview->AddChild(zoneinto);
	
	pasteover = new BButton(BRect(61,84,121,104), "pasteover", "Clip Over",	new BMessage(EDIT_EDITPASTEOVER));
	pasteover->SetEnabled(0);
	editview->AddChild(pasteover);
	
	playall = new BButton(BRect(121,84,181,104), "playall", "Play All",		new BMessage(EDIT_EDITPLAYALL));
	editview->AddChild(playall);
	
	rangeall = new BButton(BRect(181,84,241,104), "rangeall", "Range All",	new BMessage(EDIT_EDITRANGEALL));
	editview->AddChild(rangeall);
	
	rescale = new BButton(BRect(241,84,301,104), "rescale", "Maximise",		new BMessage(EDIT_EDITRESCALE));
	editview->AddChild(rescale);

	// 
	movezone = new BButton(BRect(1,106,61,126), "movezone", "Zone Move",	new BMessage(EDIT_EDITMOVEZONE));
	editview->AddChild(movezone);
	
	pasteinto = new BButton(BRect(61,106,121,126), "pasteinto", "Clip Into",	new BMessage(EDIT_EDITPASTEINTO));
	pasteinto->SetEnabled(0);
	editview->AddChild(pasteinto);
	
	playloop = new BButton(BRect(121,106,181,126), "playloop", "Play Loop",	new BMessage(EDIT_EDITPLAYLOOP));
	editview->AddChild(playloop);
	
	redraw = new BButton(BRect(181,106,241,126), "redraw", "Redraw",		new BMessage(EDIT_EDITREDRAW));
	editview->AddChild(redraw);
	
	scale = new BButton(BRect(241,106,301,126), "scale", "Scale",			new BMessage(EDIT_EDITSCALE));
	editview->AddChild(scale);


	// View for Radio Buttons
	BView* viewmodeview = new BView(BRect(529,33,585,88), "viewmodeview", B_FOLLOW_ALL, B_WILL_DRAW);
	
	left = new BRadioButton(BRect(0,-2,42,15),"left","Left", 				new BMessage(EDIT_EDITLEFT));
	viewmodeview->AddChild(left);
	right = new BRadioButton(BRect(0,12,45,29),"right","Right", 			new BMessage(EDIT_EDITRIGHT));
	viewmodeview->AddChild(right);
	stereo = new BRadioButton(BRect(0,26,54,33),"stereo","Stereo",			new BMessage(EDIT_EDITSTEREO));
	viewmodeview->AddChild(stereo);
	mono = new BRadioButton(BRect(0,40,47,57),"mono","Mono", 				new BMessage(EDIT_EDITMONO));
	mono->SetValue(1); // default is mono
	viewmodeview->AddChild(mono);
	
	viewmodeview->SetViewColor(216,216,216);
	editview->AddChild(viewmodeview);


	// BBox for progress bar
	viewdrawbarbox = new BBox(BRect(308,35,519,83), "viewdrawbarbox", B_FOLLOW_ALL, B_WILL_DRAW, B_FANCY_BORDER);
	viewdrawbarbox->SetFont(be_plain_font);
	viewdrawbarbox->SetLabel("Progress");
	viewdrawbarbox->SetViewColor(216,216,216);
	editview->AddChild(viewdrawbarbox);

	// Progress Bar
	drawbar = new ProgressView(BRect(5,19,205,35));
	drawbar->SetViewColor(0,0,0); // background to black
	drawbar->SetLowColor(0,0,0);
	drawbar->SetHighColor(255,0,0);
	viewdrawbarbox->AddChild(drawbar);


	// Scale Slider
	scaleval = new BSlider(BRect(301,93,423,143), "scaleval", "Scale Level",  new BMessage(EDIT_EDITSCALEVAL),0,200);
	scaleval->SetHashMarks(B_HASH_MARKS_BOTH);
	scaleval->SetHashMarkCount(5);
	scaleval->SetLimitLabels("0%","200%");
	scaleval->SetValue(50);
	editview->AddChild(scaleval);
	
	// Sample Rate Slider
	rate = new BSlider(BRect(424,93,504,143), "rate", "Sample Rate",  new BMessage(EDIT_EDITRATE),1,4);
	rate->SetHashMarks(B_HASH_MARKS_BOTH);
	rate->SetHashMarkCount(4);
	rate->SetLimitLabels("11KHz","96KHz");
	rate->SetValue(3);
	editview->AddChild(rate);
	
	// Magnify Slider
	mag = new BSlider(BRect(505,93,585,143), "mag", "Magnify",  new BMessage(EDIT_EDITMAG),1,10);
	mag->SetHashMarks(B_HASH_MARKS_BOTH);
	mag->SetHashMarkCount(11);
	mag->SetLimitLabels("1X","10X");
	mag->SetValue(1);
	editview->AddChild(mag);

	
	// View Cusr Value
	BView* cusrvaltextview = new BView(BRect(35,131,97,139), "cusrvaltextview", B_FOLLOW_ALL, B_WILL_DRAW);
	cusrvaltext = new BStringView(BRect(0,0,60,11), "cusrvaltext", "0000000000", B_FOLLOW_ALL, B_WILL_DRAW);
	cusrvaltext->SetHighColor(255,255,255); // text to white
	cusrvaltextview->AddChild(cusrvaltext);
	cusrvaltextview->SetViewColor(0,0,0); // background to black
	editview->AddChild(cusrvaltextview);

	cusrtext = new BStringView(BRect(3,131,33,142), "cusrtext", "Cusr  :", B_FOLLOW_ALL, B_WILL_DRAW);
	editview->AddChild(cusrtext);

	// View for Range value
	BView* rangevaltextview = new BView(BRect(137,131,199,139), "rangevaltextview", B_FOLLOW_ALL, B_WILL_DRAW);
	rangevaltext = new BStringView(BRect(0,0,60,11), "rangevaltext", "0000000000", B_FOLLOW_ALL, B_WILL_DRAW);
	rangevaltext->SetHighColor(255,255,255); // text to white
	rangevaltextview->AddChild(rangevaltext);
	rangevaltextview->SetViewColor(0,0,0); // background to black
	editview->AddChild(rangevaltextview);

	rangetext = new BStringView(BRect(100,131,134,142), "rangetext", "Range :", B_FOLLOW_ALL, B_WILL_DRAW);
	editview->AddChild(rangetext);

	// View for Zone value
	BView* zonevaltextview = new BView(BRect(236,131,298,139), "zonevaltextview", B_FOLLOW_ALL, B_WILL_DRAW);
	zonevaltext = new BStringView(BRect(0,0,60,11), "zonevaltext", "0000000000", B_FOLLOW_ALL, B_WILL_DRAW);
	zonevaltext->SetHighColor(255,255,255); // text to white
	zonevaltextview->AddChild(zonevaltext);
	zonevaltextview->SetViewColor(0,0,0); // background to black
	editview->AddChild(zonevaltextview);

	zonetext = new BStringView(BRect(202,132,231,142), "zonetext", "Zone :", B_FOLLOW_ALL, B_WILL_DRAW);
	editview->AddChild(zonetext);


	// set the color to gray, add the child, and show the window
	editview->SetViewColor(216,216,216);
	AddChild(editview);
		
	Show();
	
	Updateeditwindow(0);  // say Eh Oh

}


EDIT::~EDIT(void)
{
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************


void EDIT::Updateeditwindow(int32 mess_no)
{
char scaletxt[20];
char ratetxt[20];
char magtxt[20];
char cusrtxt[15];
char rangetxt[15];
char zonetxt[15];

static int16 drawval=1;
static int16 loopval=0;
static int16 scalevalue=50;
static int16 magval=1;
static int16 rateval=3;
static int16 viewval=4;
static int32 undoval=0;

Lock();

if ((edlisttype == 21) || (mess_no == 500))
	{}
else
	{
	if (mess_no != 22)
		{
		undo->SetLabel("UNDO");
		undoval=1;
		}
	}

if (mess_no == 0) // Say Hello
	{
	// write into txt
	sprintf(txt, "Welcome to Aural illusion for the BeOS");
	sprintf(progresstxt,"Progress");
	sprintf(ratetxt,"PlayRate 44 KHz");
	sprintf(scaletxt,"Scale Level 50%%");
	sprintf(magtxt,"Magnify X1");
	sprintf(cusrtxt,"0");
	sprintf(rangetxt,"0");
	sprintf(zonetxt,"0");
	}
if (mess_no == 1) sprintf(txt,"Cutting");
if (mess_no == 2) sprintf(txt,"Copying");
if (mess_no == 3) sprintf(txt,"Pasting Into");
if (mess_no == 4) sprintf(txt,"Pasting Over");
if (mess_no == 5) sprintf(txt,"Setting Zone");
if (mess_no == 6) sprintf(txt,"Copying Zone Into");
if (mess_no == 7) sprintf(txt,"Copying Zone Over");
if (mess_no == 8) sprintf(txt,"Copying Left to Right");
if (mess_no == 9) sprintf(txt,"Copying Right to Left");
if (mess_no == 10) sprintf(txt,"Playing View - Any Play Button to Stop");
if (mess_no == 11) sprintf(txt,"Playing Range - Any Play Button to Stop");
if (mess_no == 12) sprintf(txt,"Playing All - Any Play Button to Stop");
if (mess_no == 13) sprintf(txt,"Playing Loop - Any Play Button to Stop");
if (mess_no == 14) sprintf(txt,"Showing Range");
if (mess_no == 15) sprintf(txt,"Showing All");
if (mess_no == 16) sprintf(txt,"Moving Zone");
if (mess_no == 17) sprintf(txt,"Redrawing Sample");
if (mess_no == 18) sprintf(txt,"Ranging All");
if (mess_no == 19) sprintf(txt,"Zeroing Range");
if (mess_no == 20) sprintf(txt,"Maximising Range");
if (mess_no == 21)
	{
	edvalue=scalevalue;
	sprintf(txt,"Scaling Range to %d%%",scalevalue);
	}
if (mess_no == 22)
	{
	if (undoval == 1)
		{
		sprintf(txt,"Undoing");
		undo->SetLabel("REDO");
		undoval=0;
		}
	else	// undoval == 0;
		{
		sprintf(txt,"Redoing");
		undo->SetLabel("UNDO");
		undoval=1;
		}
	}
if (mess_no == 23) sprintf(txt,"Zooming In");
if (mess_no == 24) sprintf(txt,"Zooming Out");
if (mess_no == 25) sprintf(txt,"Going to the Beginning");
if (mess_no == 26) sprintf(txt,"Going Backwards Fast");
if (mess_no == 27) sprintf(txt,"Going Backwards");
if (mess_no == 28) sprintf(txt,"Going Forwards");
if (mess_no == 29) sprintf(txt,"Going Forwards Fast");
if (mess_no == 30) sprintf(txt,"Going to the End");
if (mess_no == 31)
	{
	loopval = loop->Value();
	edvalue = loopval;
	if(loopval == 1 )
		{
		sprintf(txt,"Loop On");
		}
	else
		{
		sprintf(txt,"Loop Off");
		}
	}
if (mess_no == 32)
	{
	drawval = draw->Value();
	edvalue = drawval;
	if(drawval == 1 )
		{
		sprintf(txt,"Drawing On");
		}
	else
		{
		sprintf(txt,"Drawing Off");
		}
	}
if (mess_no == 33)
	{
	viewval = 0;	// Left
	edlistnumber=33;
	}
if (mess_no == 34) 
	{
	viewval = 1;	// Right
	edlistnumber=33;
	}
if (mess_no == 35) 
	{
	viewval = 2;	// Stereo
	edlistnumber=33;
	}
if (mess_no == 36) 
	{
	viewval = 3;	// Mono
	edlistnumber=33;
	}
if (edlistnumber == 33) 
	{
	edvalue = viewval;
	if (viewval == 3)	// mono
		{
		lr->SetEnabled(0);
		rl->SetEnabled(0);
		}
	else
		{
		lr->SetEnabled(1);
		rl->SetEnabled(1);
		}
	edvalue = viewval;
	edlistnumber=33;
	}
if (mess_no == 37)
	{
	scalevalue = scaleval->Value();
	edvalue=scalevalue;
	sprintf(scaletxt,"Scale Level %d%%",scalevalue);
	othergoclicked=1;
	}
if (mess_no == 38)
	{
	rateval = rate->Value();
	edvalue=rateval;
	if (rateval == 1) sprintf(ratetxt,"PlayRate 11 KHz");
	if (rateval == 2) sprintf(ratetxt,"PlayRate 22 KHz");
	if (rateval == 3) sprintf(ratetxt,"PlayRate 44 KHz");
	if (rateval == 4) sprintf(ratetxt,"PlayRate 96 KHz");
	}
if (mess_no == 39)
	{
	magval = mag->Value();
	edvalue=magval;
	sprintf(magtxt,"Magnify X%d",magval);
	}

if (mess_no == 200)
{
if (edlisttype == 0)	// Standard FX Executing
	{
	if (edlistnumber == 0) sprintf(txt, "Executing Reverb");
	if (edlistnumber == 1) sprintf(txt, "Executing Echo");
	if (edlistnumber == 2) sprintf(txt, "Executing Delay");
	if (edlistnumber == 3) sprintf(txt, "Executing Phase Shift");
	if (edlistnumber == 4) sprintf(txt, "Executing Phaser");
	if (edlistnumber == 5) sprintf(txt, "Executing Chorus");
	if (edlistnumber == 6) sprintf(txt, "Executing Flange");
	if (edlistnumber == 7) sprintf(txt, "Executing Distortion");
	if (edlistnumber == 8) sprintf(txt, "Executing Compress");
	if (edlistnumber == 9) sprintf(txt, "Executing Expand");
	if (edlistnumber == 10) sprintf(txt, "Executing Enhance");
	if (edlistnumber == 11) sprintf(txt, "Executing Resample");
	if (edlistnumber == 12) sprintf(txt, "Executing Detune");
	if (edlistnumber == 13) sprintf(txt, "Executing Fade");
	if (edlistnumber == 14) sprintf(txt, "Executing Boost");
	if (edlistnumber == 15) sprintf(txt, "Executing Resolution");
	if (edlistnumber == 16) sprintf(txt, "Executing Bandwidth");
	if (edlistnumber == 17) sprintf(txt, "Executing Alternate");
	if (edlistnumber == 18) sprintf(txt, "Executing Filter Low Pass");
	if (edlistnumber == 19) sprintf(txt, "Executing Filter High Pass");
	if (edlistnumber == 20) sprintf(txt, "Executing Filter Band Pass");
	if (edlistnumber == 21) sprintf(txt, "Executing Filter Band Cut");
	if (edlistnumber == 22) sprintf(txt, "Executing Filter Notch Pass");
	if (edlistnumber == 23) sprintf(txt, "Executing Filter Notch Cut");
	if (edlistnumber == 24) sprintf(txt, "Executing Backwards Reverb");
	if (edlistnumber == 25) sprintf(txt, "Executing Reverb Phaser");
	if (edlistnumber == 26) sprintf(txt, "Executing Reverb Only");
	if (edlistnumber == 27) sprintf(txt, "Executing Long Delay");
	if (edlistnumber == 28) sprintf(txt, "Executing Multi Tap Delay");
	if (edlistnumber == 29) sprintf(txt, "Executing Feedback Delay");
	if (edlistnumber == 30) sprintf(txt, "Executing Bounce Delay");
	if (edlistnumber == 31) sprintf(txt, "Executing Jump Flange");
	if (edlistnumber == 32) sprintf(txt, "Executing Strange Flange");
	if (edlistnumber == 33) sprintf(txt, "Executing Delay Flange");
	if (edlistnumber == 34) sprintf(txt, "Executing Digital Distortion");
	if (edlistnumber == 35) sprintf(txt, "Executing Contortion");
	if (edlistnumber == 36) sprintf(txt, "Executing Mix Contortion");
	if (edlistnumber == 37) sprintf(txt, "Executing Bandwidth Smooth");
	}

if (edlisttype == 1)	// Complex FX
	{
	if (edlistnumber == 0) sprintf(txt, "Executing Graphic Equalizer 7 Band");
	if (edlistnumber == 1) sprintf(txt, "Executing Graphic Equalizer 20 Band");
	if (edlistnumber == 2) sprintf(txt, "Executing 1/x");
	if (edlistnumber == 3) sprintf(txt, "Executing Acos");
	if (edlistnumber == 4) sprintf(txt, "Executing Asin");
	if (edlistnumber == 5) sprintf(txt, "Executing Atan");
	if (edlistnumber == 6) sprintf(txt, "Executing Cos");
	if (edlistnumber == 7) sprintf(txt, "Executing Sin");
	if (edlistnumber == 8) sprintf(txt, "Executing Tan");
	if (edlistnumber == 9) sprintf(txt, "Executing Cosh");
	if (edlistnumber == 10) sprintf(txt, "Executing Sinh");
	if (edlistnumber == 11) sprintf(txt, "Executing Tanh");
	if (edlistnumber == 12) sprintf(txt, "Executing Acosh");
	if (edlistnumber == 13) sprintf(txt, "Executing Asinh");
	if (edlistnumber == 14) sprintf(txt, "Executing Atanh");
	if (edlistnumber == 15) sprintf(txt, "Executing Sec");
	if (edlistnumber == 16) sprintf(txt, "Executing Cosec");
	if (edlistnumber == 17) sprintf(txt, "Executing Cot");
	if (edlistnumber == 18) sprintf(txt, "Executing +Sin");
	if (edlistnumber == 19) sprintf(txt, "Executing Exp");
	if (edlistnumber == 20) sprintf(txt, "Executing Log");
	if (edlistnumber == 21) sprintf(txt, "Executing Log10");
	if (edlistnumber == 22) sprintf(txt, "Executing Expm1");
	if (edlistnumber == 23) sprintf(txt, "Executing Log1p");
	if (edlistnumber == 24) sprintf(txt, "Executing Logb");
	if (edlistnumber == 25) sprintf(txt, "Executing +Log");
	if (edlistnumber == 26) sprintf(txt, "Executing Sqrt");
	if (edlistnumber == 27) sprintf(txt, "Executing Cbrt");
	if (edlistnumber == 28) sprintf(txt, "Executing Ceil");
	if (edlistnumber == 29) sprintf(txt, "Executing Fabs");
	if (edlistnumber == 30) sprintf(txt, "Executing Floor");
	if (edlistnumber == 31) sprintf(txt, "Executing Significand");
	if (edlistnumber == 32) sprintf(txt, "Executing J0");
	if (edlistnumber == 33) sprintf(txt, "Executing J1");
	if (edlistnumber == 34) sprintf(txt, "Executing Y0");
	if (edlistnumber == 35) sprintf(txt, "Executing Y1");
	if (edlistnumber == 36) sprintf(txt, "Executing Erf");
	if (edlistnumber == 37) sprintf(txt, "Executing Erfc");
	if (edlistnumber == 38) sprintf(txt, "Executing Gamma");
	if (edlistnumber == 39) sprintf(txt, "Executing Lgamma");
	if (edlistnumber == 40) sprintf(txt, "Executing Rint");
	if (edlistnumber == 41) sprintf(txt, "Executing Ilogbf");
	if (edlistnumber == 42) sprintf(txt, "Executing Delay 1/x");
	if (edlistnumber == 43) sprintf(txt, "Executing Delay Acos");
	if (edlistnumber == 44) sprintf(txt, "Executing Delay Asin");
	if (edlistnumber == 45) sprintf(txt, "Executing Delay Atan");
	if (edlistnumber == 46) sprintf(txt, "Executing Delay Cos");
	if (edlistnumber == 47) sprintf(txt, "Executing Delay Sin");
	if (edlistnumber == 48) sprintf(txt, "Executing Delay Tan");
	if (edlistnumber == 49) sprintf(txt, "Executing Delay Cosh");
	if (edlistnumber == 50) sprintf(txt, "Executing Delay Sinh");
	if (edlistnumber == 51) sprintf(txt, "Executing Delay Tanh");
	if (edlistnumber == 52) sprintf(txt, "Executing Delay Acosh");
	if (edlistnumber == 53) sprintf(txt, "Executing Delay Asinh");
	if (edlistnumber == 54) sprintf(txt, "Executing Delay Atanh");
	if (edlistnumber == 55) sprintf(txt, "Executing Delay Sec");
	if (edlistnumber == 56) sprintf(txt, "Executing Delay Cosec");
	if (edlistnumber == 57) sprintf(txt, "Executing Delay Cot");
	if (edlistnumber == 58) sprintf(txt, "Executing Delay +Sin");
	if (edlistnumber == 59) sprintf(txt, "Executing Delay Exp");
	if (edlistnumber == 60) sprintf(txt, "Executing Delay Log");
	if (edlistnumber == 61) sprintf(txt, "Executing Delay Log10");
	if (edlistnumber == 62) sprintf(txt, "Executing Delay Expm1");
	if (edlistnumber == 63) sprintf(txt, "Executing Delay Log1p");
	if (edlistnumber == 64) sprintf(txt, "Executing Delay Logb");
	if (edlistnumber == 65) sprintf(txt, "Executing Delay +Log");
	if (edlistnumber == 66) sprintf(txt, "Executing Delay Sqrt");
	if (edlistnumber == 67) sprintf(txt, "Executing Delay Cbrt");
	if (edlistnumber == 68) sprintf(txt, "Executing Delay Ceil");
	if (edlistnumber == 69) sprintf(txt, "Executing Delay Fabs");
	if (edlistnumber == 70) sprintf(txt, "Executing Delay Floor");
	if (edlistnumber == 71) sprintf(txt, "Executing Delay Significand");
	if (edlistnumber == 72) sprintf(txt, "Executing Delay J0");
	if (edlistnumber == 73) sprintf(txt, "Executing Delay J1");
	if (edlistnumber == 74) sprintf(txt, "Executing Delay Y0");
	if (edlistnumber == 75) sprintf(txt, "Executing Delay Y1");
	if (edlistnumber == 76) sprintf(txt, "Executing Delay Erf");
	if (edlistnumber == 77) sprintf(txt, "Executing Delay Erfc");
	if (edlistnumber == 78) sprintf(txt, "Executing Delay Gamma");
	if (edlistnumber == 79) sprintf(txt, "Executing Delay Lgamma");
	if (edlistnumber == 80) sprintf(txt, "Executing Delay Rint");
	if (edlistnumber == 81) sprintf(txt, "Executing Delay Ilogbf");
	}

if (edlisttype == 2)	// Manips 1
	{
	if (edlistnumber == 0) sprintf(txt, "Executing Invert");
	if (edlistnumber == 1) sprintf(txt, "Executing Half Wave Rectify");
	if (edlistnumber == 2) sprintf(txt, "Executing Full Wave Rectify");
	if (edlistnumber == 3) sprintf(txt, "Executing Flip");
	if (edlistnumber == 4) sprintf(txt, "Executing Centre");
	if (edlistnumber == 5) sprintf(txt, "Executing Reverse");
	if (edlistnumber == 6) sprintf(txt, "Executing Clean");
	if (edlistnumber == 7) sprintf(txt, "Executing Thicken");
	if (edlistnumber == 8) sprintf(txt, "Executing Double Thicken");
	if (edlistnumber == 9) sprintf(txt, "Executing Quarter Value");
	if (edlistnumber == 10) sprintf(txt, "Executing Half Value");
	if (edlistnumber == 11) sprintf(txt, "Executing Double Value");
	if (edlistnumber == 12) sprintf(txt, "Executing Quadruple Value");
	if (edlistnumber == 13) sprintf(txt, "Executing Fade In");
	if (edlistnumber == 14) sprintf(txt, "Executing Fade Out");
	if (edlistnumber == 15) sprintf(txt, "Executing Recreate");
	if (edlistnumber == 16) sprintf(txt, "Executing Loudness");
	if (edlistnumber == 17) sprintf(txt, "Executing UnLoudness");
	if (edlistnumber == 18) sprintf(txt, "Executing Filter Very High");
	if (edlistnumber == 19) sprintf(txt, "Executing Filter High Band");
	if (edlistnumber == 20) sprintf(txt, "Executing Filter High Mid");
	if (edlistnumber == 21) sprintf(txt, "Executing Filter Mid Band");
	if (edlistnumber == 22) sprintf(txt, "Executing Filter Low Mid");
	if (edlistnumber == 23) sprintf(txt, "Executing Filter Low Band");
	if (edlistnumber == 24) sprintf(txt, "Executing Filter Sub Bass");
	if (edlistnumber == 25) sprintf(txt, "Executing Tune 2 Octaves");
	if (edlistnumber == 26) sprintf(txt, "Executing Tune Octave");
	if (edlistnumber == 27) sprintf(txt, "Executing Tune Note");
	if (edlistnumber == 28) sprintf(txt, "Executing Tune Semitone");
	if (edlistnumber == 29) sprintf(txt, "Executing Tune 1/8 Note");
	if (edlistnumber == 30) sprintf(txt, "Executing Zero Out");
	if (edlistnumber == 31) sprintf(txt, "Executing More +/-");
	if (edlistnumber == 32) sprintf(txt, "Executing Blur Filter");
	if (edlistnumber == 33) sprintf(txt, "Executing 2D Blur Filter");
	if (edlistnumber == 34) sprintf(txt, "Executing Auto Stutter");
	if (edlistnumber == 35) sprintf(txt, "Executing Strange Delay");
	if (edlistnumber == 36) sprintf(txt, "Executing Stranger Delay");
	if (edlistnumber == 37) sprintf(txt, "Executing Half Distortion");
	if (edlistnumber == 38) sprintf(txt, "Executing Half Contortion");
	}

if (edlisttype == 3)	// Manips 2
	{
	if (edlistnumber == 0) sprintf(txt, "Executing Over");
	if (edlistnumber == 1) sprintf(txt, "Executing Under");
	if (edlistnumber == 2) sprintf(txt, "Executing In Between");
	if (edlistnumber == 3) sprintf(txt, "Executing Out Between");
	if (edlistnumber == 4) sprintf(txt, "Executing Limit Low");
	if (edlistnumber == 5) sprintf(txt, "Executing Limit High");
	if (edlistnumber == 6) sprintf(txt, "Executing Add Spikes");
	if (edlistnumber == 7) sprintf(txt, "Executing Delete Spikes");
	if (edlistnumber == 8) sprintf(txt, "Executing Capacitance");
	if (edlistnumber == 9) sprintf(txt, "Executing Replacement");
	if (edlistnumber == 10) sprintf(txt, "Executing Tear");
	if (edlistnumber == 11) sprintf(txt, "Executing Swap Byte Order");
	if (edlistnumber == 12) sprintf(txt, "Executing Delta");
	if (edlistnumber == 13) sprintf(txt, "Executing Square");
	if (edlistnumber == 14) sprintf(txt, "Executing Half Square");
	if (edlistnumber == 15) sprintf(txt, "Executing Transform Blocks");
	if (edlistnumber == 16) sprintf(txt, "Executing Reverse Single Blocks");
	if (edlistnumber == 17) sprintf(txt, "Executing Reverse All Blocks");
	if (edlistnumber == 18) sprintf(txt, "Executing Skip Blocks");
	if (edlistnumber == 19) sprintf(txt, "Executing Repeat Blocks");
	if (edlistnumber == 20) sprintf(txt, "Executing Unorder Samples");
	if (edlistnumber == 21) sprintf(txt, "Executing Unorder Blocks");
	if (edlistnumber == 22) sprintf(txt, "Executing Flip Alternate");
	if (edlistnumber == 23) sprintf(txt, "Executing Ramdom Amplifier");
	if (edlistnumber == 24) sprintf(txt, "Executing Swap Halves");
	if (edlistnumber == 25) sprintf(txt, "Executing Remove Centre");
	if (edlistnumber == 26) sprintf(txt, "Executing Add Centre");
	if (edlistnumber == 27) sprintf(txt, "Executing Remove Flat");
	if (edlistnumber == 28) sprintf(txt, "Executing Keep Flat");
	if (edlistnumber == 29) sprintf(txt, "Executing Remove Middle");
	if (edlistnumber == 30) sprintf(txt, "Executing Transmogrify");
	if (edlistnumber == 31) sprintf(txt, "Executing Non-Transmogrify");
	if (edlistnumber == 32) sprintf(txt, "Executing Delay Delta");
	if (edlistnumber == 33) sprintf(txt, "Executing Delay Backwards Subtract");
	if (edlistnumber == 34) sprintf(txt, "Executing Delay Multiply");
	if (edlistnumber == 35) sprintf(txt, "Executing Delay Divide");
	if (edlistnumber == 36) sprintf(txt, "Executing Delay Backwards Divide");
	if (edlistnumber == 37) sprintf(txt, "Executing Delay AND");
	if (edlistnumber == 38) sprintf(txt, "Executing Delay OR");
	if (edlistnumber == 39) sprintf(txt, "Executing Delay XOR");
	if (edlistnumber == 40) sprintf(txt, "Executing Delay Rectify");
	if (edlistnumber == 41) sprintf(txt, "Executing Delay Greater");
	if (edlistnumber == 42) sprintf(txt, "Executing Delay Lesser");
	if (edlistnumber == 43) sprintf(txt, "Executing Delay Interleave");
	if (edlistnumber == 44) sprintf(txt, "Executing Delay Modulus");
	if (edlistnumber == 45) sprintf(txt, "Executing Delay Backwards Modulus");
	if (edlistnumber == 46) sprintf(txt, "Executing Noise");
	if (edlistnumber == 47) sprintf(txt, "Executing Filtered Noise");
	if (edlistnumber == 48) sprintf(txt, "Executing Rumble");
	if (edlistnumber == 49) sprintf(txt, "Executing Chaos");
	if (edlistnumber == 50) sprintf(txt, "Executing Random");
	}

if (edlisttype == 4)	// Dual Manips
	{
	if (edlistnumber == 0) sprintf(txt, "Executing Powered Compress");
	if (edlistnumber == 1) sprintf(txt, "Executing Powered Expand");
	if (edlistnumber == 2) sprintf(txt, "Executing Half Rectify and Add");
	if (edlistnumber == 3) sprintf(txt, "Executing Full Rectify and Add");
	if (edlistnumber == 4) sprintf(txt, "Executing Add");
	if (edlistnumber == 5) sprintf(txt, "Executing Subtract");
	if (edlistnumber == 6) sprintf(txt, "Executing Backwards Subtract");
	if (edlistnumber == 7) sprintf(txt, "Executing Multiply");
	if (edlistnumber == 8) sprintf(txt, "Executing Divide");
	if (edlistnumber == 9) sprintf(txt, "Executing Backwards Divide");
	if (edlistnumber == 10) sprintf(txt, "Executing AND");
	if (edlistnumber == 11) sprintf(txt, "Executing OR");
	if (edlistnumber == 12) sprintf(txt, "Executing XOR");
	if (edlistnumber == 13) sprintf(txt, "Executing Greater");
	if (edlistnumber == 14) sprintf(txt, "Executing Lesser");
	if (edlistnumber == 15) sprintf(txt, "Executing Interleave");
	if (edlistnumber == 16) sprintf(txt, "Executing Rectify");
	if (edlistnumber == 17) sprintf(txt, "Executing Stutter");
	if (edlistnumber == 18) sprintf(txt, "Executing Modulus");
	if (edlistnumber == 19) sprintf(txt, "Executing Backwards Modulus");
	if (edlistnumber == 20) sprintf(txt, "Executing Amplitude Modulation");
	}

if (edlisttype == 5)	// Stereo FX
	{
	if (edlistnumber == 0) sprintf(txt, "Executing Stereo Reverb");
	if (edlistnumber == 1) sprintf(txt, "Executing Stereo Reverb Only");
	if (edlistnumber == 2) sprintf(txt, "Executing Swap Sides Left<->Right");
	if (edlistnumber == 3) sprintf(txt, "Executing Cross Fade Left<->Right");
	if (edlistnumber == 4) sprintf(txt, "Executing Cross Fade Stereo Mono");
	if (edlistnumber == 5) sprintf(txt, "Executing Pan Manual");
	if (edlistnumber == 6) sprintf(txt, "Executing Pan Ping Pong");
	if (edlistnumber == 7) sprintf(txt, "Executing Pan Mono Left");
	if (edlistnumber == 8) sprintf(txt, "Executing Pan Mono Right");
	if (edlistnumber == 9) sprintf(txt, "Executing Add");
	if (edlistnumber == 10) sprintf(txt, "Executing Subtract");
	if (edlistnumber == 11) sprintf(txt, "Executing Backwards Subtract");
	if (edlistnumber == 12) sprintf(txt, "Executing Multiply");
	if (edlistnumber == 13) sprintf(txt, "Executing Divide");
	if (edlistnumber == 14) sprintf(txt, "Executing Backwards Divide");
	if (edlistnumber == 15) sprintf(txt, "Executing AND");
	if (edlistnumber == 16) sprintf(txt, "Executing OR");
	if (edlistnumber == 17) sprintf(txt, "Executing XOR");
	if (edlistnumber == 18) sprintf(txt, "Executing Greater");
	if (edlistnumber == 19) sprintf(txt, "Executing Lesser");
	if (edlistnumber == 20) sprintf(txt, "Executing Interleave");
	if (edlistnumber == 21) sprintf(txt, "Executing Modulus");
	if (edlistnumber == 22) sprintf(txt, "Executing Backwards Modulus");
	if (edlistnumber == 23) sprintf(txt, "Executing Stutter");
	if (edlistnumber == 24) sprintf(txt, "Executing Rectify");
	}

if (edlisttype == 22)	// Other Operations
	{
	if (edlistnumber == 1) sprintf(txt, "Executing Open Sample");
	if (edlistnumber == 2) sprintf(txt, "Executing Save Sample");
	if (edlistnumber == 3) sprintf(txt, "Executing Save As");
	if (edlistnumber == 4) sprintf(txt, "Executing Temp1");
	if (edlistnumber == 5) sprintf(txt, "Executing Temp2");
	if (edlistnumber == 6) sprintf(txt, "Executing Temp3");
	if (edlistnumber == 7) sprintf(txt, "Executing Temp4");
	if (edlistnumber == 8) sprintf(txt, "Executing Temp5");
	}
}

if (mess_no == 500)
{
if (edlisttype == 0)	// Standard FX *NOT* Executing
	{
	if (edlistnumber == 0) sprintf(txt, "Reverb");
	if (edlistnumber == 1) sprintf(txt, "Echo");
	if (edlistnumber == 2) sprintf(txt, "Delay");
	if (edlistnumber == 3) sprintf(txt, "Phase Shift");
	if (edlistnumber == 4) sprintf(txt, "Phaser");
	if (edlistnumber == 5) sprintf(txt, "Chorus");
	if (edlistnumber == 6) sprintf(txt, "Flange");
	if (edlistnumber == 7) sprintf(txt, "Distortion");
	if (edlistnumber == 8) sprintf(txt, "Compress");
	if (edlistnumber == 9) sprintf(txt, "Expand");
	if (edlistnumber == 10) sprintf(txt, "Enhance");
	if (edlistnumber == 11) sprintf(txt, "Resample");
	if (edlistnumber == 12) sprintf(txt, "Detune");
	if (edlistnumber == 13) sprintf(txt, "Fade");
	if (edlistnumber == 14) sprintf(txt, "Boost");
	if (edlistnumber == 15) sprintf(txt, "Resolution");
	if (edlistnumber == 16) sprintf(txt, "Bandwidth");
	if (edlistnumber == 17) sprintf(txt, "Alternate");
	if (edlistnumber == 18) sprintf(txt, "Filter Low Pass");
	if (edlistnumber == 19) sprintf(txt, "Filter High Pass");
	if (edlistnumber == 20) sprintf(txt, "Filter Band Pass");
	if (edlistnumber == 21) sprintf(txt, "Filter Band Cut");
	if (edlistnumber == 22) sprintf(txt, "Filter Notch Pass");
	if (edlistnumber == 23) sprintf(txt, "Filter Notch Cut");
	if (edlistnumber == 24) sprintf(txt, "Backwards Reverb");
	if (edlistnumber == 25) sprintf(txt, "Reverb Phaser");
	if (edlistnumber == 26) sprintf(txt, "Reverb Only");
	if (edlistnumber == 27) sprintf(txt, "Long Delay");
	if (edlistnumber == 28) sprintf(txt, "Multi Tap Delay");
	if (edlistnumber == 29) sprintf(txt, "Feedback Delay");
	if (edlistnumber == 30) sprintf(txt, "Bounce Delay");
	if (edlistnumber == 31) sprintf(txt, "Jump Flange");
	if (edlistnumber == 32) sprintf(txt, "Strange Flange");
	if (edlistnumber == 33) sprintf(txt, "Delay Flange");
	if (edlistnumber == 34) sprintf(txt, "Digital Distortion");
	if (edlistnumber == 35) sprintf(txt, "Contortion");
	if (edlistnumber == 36) sprintf(txt, "Mix Contortion");
	if (edlistnumber == 37) sprintf(txt, "Bandwidth Smooth");
	}

if (edlisttype == 1)	// Complex FX
	{
	if (edlistnumber == 0) sprintf(txt, "Graphic Equalizer 7 Band");
	if (edlistnumber == 1) sprintf(txt, "Graphic Equalizer 20 Band");
	if (edlistnumber == 2) sprintf(txt, "1/x");
	if (edlistnumber == 3) sprintf(txt, "Acos");
	if (edlistnumber == 4) sprintf(txt, "Asin");
	if (edlistnumber == 5) sprintf(txt, "Atan");
	if (edlistnumber == 6) sprintf(txt, "Cos");
	if (edlistnumber == 7) sprintf(txt, "Sin");
	if (edlistnumber == 8) sprintf(txt, "Tan");
	if (edlistnumber == 9) sprintf(txt, "Cosh");
	if (edlistnumber == 10) sprintf(txt, "Sinh");
	if (edlistnumber == 11) sprintf(txt, "Tanh");
	if (edlistnumber == 12) sprintf(txt, "Acosh");
	if (edlistnumber == 13) sprintf(txt, "Asinh");
	if (edlistnumber == 14) sprintf(txt, "Atanh");
	if (edlistnumber == 15) sprintf(txt, "Sec");
	if (edlistnumber == 16) sprintf(txt, "Cosec");
	if (edlistnumber == 17) sprintf(txt, "Cot");
	if (edlistnumber == 18) sprintf(txt, "+Sin");
	if (edlistnumber == 19) sprintf(txt, "Exp");
	if (edlistnumber == 20) sprintf(txt, "Log");
	if (edlistnumber == 21) sprintf(txt, "Log10");
	if (edlistnumber == 22) sprintf(txt, "Expm1");
	if (edlistnumber == 23) sprintf(txt, "Log1p");
	if (edlistnumber == 24) sprintf(txt, "Logb");
	if (edlistnumber == 25) sprintf(txt, "+Log");
	if (edlistnumber == 26) sprintf(txt, "Sqrt");
	if (edlistnumber == 27) sprintf(txt, "Cbrt");
	if (edlistnumber == 28) sprintf(txt, "Ceil");
	if (edlistnumber == 29) sprintf(txt, "Fabs");
	if (edlistnumber == 30) sprintf(txt, "Floor");
	if (edlistnumber == 31) sprintf(txt, "Significand");
	if (edlistnumber == 32) sprintf(txt, "J0");
	if (edlistnumber == 33) sprintf(txt, "J1");
	if (edlistnumber == 34) sprintf(txt, "Y0");
	if (edlistnumber == 35) sprintf(txt, "Y1");
	if (edlistnumber == 36) sprintf(txt, "Erf");
	if (edlistnumber == 37) sprintf(txt, "Erfc");
	if (edlistnumber == 38) sprintf(txt, "Gamma");
	if (edlistnumber == 39) sprintf(txt, "Lgamma");
	if (edlistnumber == 40) sprintf(txt, "Rint");
	if (edlistnumber == 41) sprintf(txt, "Ilogbf");
	if (edlistnumber == 42) sprintf(txt, "Delay 1/x");
	if (edlistnumber == 43) sprintf(txt, "Delay Acos");
	if (edlistnumber == 44) sprintf(txt, "Delay Asin");
	if (edlistnumber == 45) sprintf(txt, "Delay Atan");
	if (edlistnumber == 46) sprintf(txt, "Delay Cos");
	if (edlistnumber == 47) sprintf(txt, "Delay Sin");
	if (edlistnumber == 48) sprintf(txt, "Delay Tan");
	if (edlistnumber == 49) sprintf(txt, "Delay Cosh");
	if (edlistnumber == 50) sprintf(txt, "Delay Sinh");
	if (edlistnumber == 51) sprintf(txt, "Delay Tanh");
	if (edlistnumber == 52) sprintf(txt, "Delay Acosh");
	if (edlistnumber == 53) sprintf(txt, "Delay Asinh");
	if (edlistnumber == 54) sprintf(txt, "Delay Atanh");
	if (edlistnumber == 55) sprintf(txt, "Delay Sec");
	if (edlistnumber == 56) sprintf(txt, "Delay Cosec");
	if (edlistnumber == 57) sprintf(txt, "Delay Cot");
	if (edlistnumber == 58) sprintf(txt, "Delay +Sin");
	if (edlistnumber == 59) sprintf(txt, "Delay Exp");
	if (edlistnumber == 60) sprintf(txt, "Delay Log");
	if (edlistnumber == 61) sprintf(txt, "Delay Log10");
	if (edlistnumber == 62) sprintf(txt, "Delay Expm1");
	if (edlistnumber == 63) sprintf(txt, "Delay Log1p");
	if (edlistnumber == 64) sprintf(txt, "Delay Logb");
	if (edlistnumber == 65) sprintf(txt, "Delay +Log");
	if (edlistnumber == 66) sprintf(txt, "Delay Sqrt");
	if (edlistnumber == 67) sprintf(txt, "Delay Cbrt");
	if (edlistnumber == 68) sprintf(txt, "Delay Ceil");
	if (edlistnumber == 69) sprintf(txt, "Delay Fabs");
	if (edlistnumber == 70) sprintf(txt, "Delay Floor");
	if (edlistnumber == 71) sprintf(txt, "Delay Significand");
	if (edlistnumber == 72) sprintf(txt, "Delay J0");
	if (edlistnumber == 73) sprintf(txt, "Delay J1");
	if (edlistnumber == 74) sprintf(txt, "Delay Y0");
	if (edlistnumber == 75) sprintf(txt, "Delay Y1");
	if (edlistnumber == 76) sprintf(txt, "Delay Erf");
	if (edlistnumber == 77) sprintf(txt, "Delay Erfc");
	if (edlistnumber == 78) sprintf(txt, "Delay Gamma");
	if (edlistnumber == 79) sprintf(txt, "Delay Lgamma");
	if (edlistnumber == 80) sprintf(txt, "Delay Rint");
	if (edlistnumber == 81) sprintf(txt, "Delay Ilogbf");
	}

if (edlisttype == 2)	// Manips 1
	{
	if (edlistnumber == 0) sprintf(txt, "Invert");
	if (edlistnumber == 1) sprintf(txt, "Half Wave Rectify");
	if (edlistnumber == 2) sprintf(txt, "Full Wave Rectify");
	if (edlistnumber == 3) sprintf(txt, "Flip");
	if (edlistnumber == 4) sprintf(txt, "Centre");
	if (edlistnumber == 5) sprintf(txt, "Reverse");
	if (edlistnumber == 6) sprintf(txt, "Clean");
	if (edlistnumber == 7) sprintf(txt, "Thicken");
	if (edlistnumber == 8) sprintf(txt, "Double Thicken");
	if (edlistnumber == 9) sprintf(txt, "Quarter Value");
	if (edlistnumber == 10) sprintf(txt, "Half Value");
	if (edlistnumber == 11) sprintf(txt, "Double Value");
	if (edlistnumber == 12) sprintf(txt, "Quadruple Value");
	if (edlistnumber == 13) sprintf(txt, "Fade In");
	if (edlistnumber == 14) sprintf(txt, "Fade Out");
	if (edlistnumber == 15) sprintf(txt, "Recreate");
	if (edlistnumber == 16) sprintf(txt, "Loudness");
	if (edlistnumber == 17) sprintf(txt, "UnLoudness");
	if (edlistnumber == 18) sprintf(txt, "Filter Very High");
	if (edlistnumber == 19) sprintf(txt, "Filter High Band");
	if (edlistnumber == 20) sprintf(txt, "Filter High Mid");
	if (edlistnumber == 21) sprintf(txt, "Filter Mid Band");
	if (edlistnumber == 22) sprintf(txt, "Filter Low Mid");
	if (edlistnumber == 23) sprintf(txt, "Filter Low Band");
	if (edlistnumber == 24) sprintf(txt, "Filter Sub Bass");
	if (edlistnumber == 25) sprintf(txt, "Tune 2 Octaves");
	if (edlistnumber == 26) sprintf(txt, "Tune Octave");
	if (edlistnumber == 27) sprintf(txt, "Tune Note");
	if (edlistnumber == 28) sprintf(txt, "Tune Semitone");
	if (edlistnumber == 29) sprintf(txt, "Tune 1/8 Note");
	if (edlistnumber == 30) sprintf(txt, "Zero Out");
	if (edlistnumber == 31) sprintf(txt, "More +/-");
	if (edlistnumber == 32) sprintf(txt, "Blur Filter");
	if (edlistnumber == 33) sprintf(txt, "2D Blur Filter");
	if (edlistnumber == 34) sprintf(txt, "Auto Stutter");
	if (edlistnumber == 35) sprintf(txt, "Strange Delay");
	if (edlistnumber == 36) sprintf(txt, "Stranger Delay");
	if (edlistnumber == 37) sprintf(txt, "Half Distortion");
	if (edlistnumber == 38) sprintf(txt, "Half Contortion");
	}

if (edlisttype == 3)	// Manips 2
	{
	if (edlistnumber == 0) sprintf(txt, "Over");
	if (edlistnumber == 1) sprintf(txt, "Under");
	if (edlistnumber == 2) sprintf(txt, "In Between");
	if (edlistnumber == 3) sprintf(txt, "Out Between");
	if (edlistnumber == 4) sprintf(txt, "Limit Low");
	if (edlistnumber == 5) sprintf(txt, "Limit High");
	if (edlistnumber == 6) sprintf(txt, "Add Spikes");
	if (edlistnumber == 7) sprintf(txt, "Delete Spikes");
	if (edlistnumber == 8) sprintf(txt, "Capacitance");
	if (edlistnumber == 9) sprintf(txt, "Replacement");
	if (edlistnumber == 10) sprintf(txt, "Tear");
	if (edlistnumber == 11) sprintf(txt, "Swap Byte Order");
	if (edlistnumber == 12) sprintf(txt, "Delta");
	if (edlistnumber == 13) sprintf(txt, "Square");
	if (edlistnumber == 14) sprintf(txt, "Half Square");
	if (edlistnumber == 15) sprintf(txt, "Transform Blocks");
	if (edlistnumber == 16) sprintf(txt, "Reverse Single Blocks");
	if (edlistnumber == 17) sprintf(txt, "Reverse All Blocks");
	if (edlistnumber == 18) sprintf(txt, "Skip Blocks");
	if (edlistnumber == 19) sprintf(txt, "Repeat Blocks");
	if (edlistnumber == 20) sprintf(txt, "Unorder Samples");
	if (edlistnumber == 21) sprintf(txt, "Unorder Blocks");
	if (edlistnumber == 22) sprintf(txt, "Flip Alternate");
	if (edlistnumber == 23) sprintf(txt, "Ramdom Amplifier");
	if (edlistnumber == 24) sprintf(txt, "Swap Halves");
	if (edlistnumber == 25) sprintf(txt, "Remove Centre");
	if (edlistnumber == 26) sprintf(txt, "Add Centre");
	if (edlistnumber == 27) sprintf(txt, "Remove Flat");
	if (edlistnumber == 28) sprintf(txt, "Keep Flat");
	if (edlistnumber == 29) sprintf(txt, "Remove Middle");
	if (edlistnumber == 30) sprintf(txt, "Transmogrify");
	if (edlistnumber == 31) sprintf(txt, "Non-Transmogrify");
	if (edlistnumber == 32) sprintf(txt, "Delay Delta");
	if (edlistnumber == 33) sprintf(txt, "Delay Backwards Subtract");
	if (edlistnumber == 34) sprintf(txt, "Delay Multiply");
	if (edlistnumber == 35) sprintf(txt, "Delay Divide");
	if (edlistnumber == 36) sprintf(txt, "Delay Backwards Divide");
	if (edlistnumber == 37) sprintf(txt, "Delay AND");
	if (edlistnumber == 38) sprintf(txt, "Delay OR");
	if (edlistnumber == 39) sprintf(txt, "Delay XOR");
	if (edlistnumber == 40) sprintf(txt, "Delay Rectify");
	if (edlistnumber == 41) sprintf(txt, "Delay Greater");
	if (edlistnumber == 42) sprintf(txt, "Delay Lesser");
	if (edlistnumber == 43) sprintf(txt, "Delay Interleave");
	if (edlistnumber == 44) sprintf(txt, "Delay Modulus");
	if (edlistnumber == 45) sprintf(txt, "Delay Backwards Modulus");
	if (edlistnumber == 46) sprintf(txt, "Noise");
	if (edlistnumber == 47) sprintf(txt, "Filtered Noise");
	if (edlistnumber == 48) sprintf(txt, "Rumble");
	if (edlistnumber == 49) sprintf(txt, "Chaos");
	if (edlistnumber == 50) sprintf(txt, "Random");
	}

if (edlisttype == 4)	// Dual Manips
	{
	if (edlistnumber == 0) sprintf(txt, "Powered Compress");
	if (edlistnumber == 1) sprintf(txt, "Powered Expand");
	if (edlistnumber == 2) sprintf(txt, "Half Rectify and Add");
	if (edlistnumber == 3) sprintf(txt, "Full Rectify and Add");
	if (edlistnumber == 4) sprintf(txt, "Add");
	if (edlistnumber == 5) sprintf(txt, "Subtract");
	if (edlistnumber == 6) sprintf(txt, "Backwards Subtract");
	if (edlistnumber == 7) sprintf(txt, "Multiply");
	if (edlistnumber == 8) sprintf(txt, "Divide");
	if (edlistnumber == 9) sprintf(txt, "Backwards Divide");
	if (edlistnumber == 10) sprintf(txt, "AND");
	if (edlistnumber == 11) sprintf(txt, "OR");
	if (edlistnumber == 12) sprintf(txt, "XOR");
	if (edlistnumber == 13) sprintf(txt, "Greater");
	if (edlistnumber == 14) sprintf(txt, "Lesser");
	if (edlistnumber == 15) sprintf(txt, "Interleave");
	if (edlistnumber == 16) sprintf(txt, "Rectify");
	if (edlistnumber == 17) sprintf(txt, "Stutter");
	if (edlistnumber == 18) sprintf(txt, "Modulus");
	if (edlistnumber == 19) sprintf(txt, "Backwards Modulus");
	if (edlistnumber == 20) sprintf(txt, "Amplitude Modulation");
	}

if (edlisttype == 5)	// Stereo FX
	{
	if (edlistnumber == 0) sprintf(txt, "Stereo Reverb");
	if (edlistnumber == 1) sprintf(txt, "Stereo Reverb Only");
	if (edlistnumber == 2) sprintf(txt, "Swap Sides Left<->Right");
	if (edlistnumber == 3) sprintf(txt, "Cross Fade Left<->Right");
	if (edlistnumber == 4) sprintf(txt, "Cross Fade Stereo Mono");
	if (edlistnumber == 5) sprintf(txt, "Pan Manual");
	if (edlistnumber == 6) sprintf(txt, "Pan Ping Pong");
	if (edlistnumber == 7) sprintf(txt, "Pan Mono Left");
	if (edlistnumber == 8) sprintf(txt, "Pan Mono Right");
	if (edlistnumber == 9) sprintf(txt, "Add");
	if (edlistnumber == 10) sprintf(txt, "Subtract");
	if (edlistnumber == 11) sprintf(txt, "Backwards Subtract");
	if (edlistnumber == 12) sprintf(txt, "Multiply");
	if (edlistnumber == 13) sprintf(txt, "Divide");
	if (edlistnumber == 14) sprintf(txt, "Backwards Divide");
	if (edlistnumber == 15) sprintf(txt, "AND");
	if (edlistnumber == 16) sprintf(txt, "OR");
	if (edlistnumber == 17) sprintf(txt, "XOR");
	if (edlistnumber == 18) sprintf(txt, "Greater");
	if (edlistnumber == 19) sprintf(txt, "Lesser");
	if (edlistnumber == 20) sprintf(txt, "Interleave");
	if (edlistnumber == 21) sprintf(txt, "Modulus");
	if (edlistnumber == 22) sprintf(txt, "Backwards Modulus");
	if (edlistnumber == 23) sprintf(txt, "Stutter");
	if (edlistnumber == 24) sprintf(txt, "Rectify");
	}

if (edlisttype == 22)	// Other Operations
	{
	if (edlistnumber == 1) sprintf(txt, "Open Sample");
	if (edlistnumber == 2) sprintf(txt, "Save Sample");
	if (edlistnumber == 3) sprintf(txt, "Save As");
	if (edlistnumber == 4) sprintf(txt, "Temp1");
	if (edlistnumber == 5) sprintf(txt, "Temp2");
	if (edlistnumber == 6) sprintf(txt, "Temp3");
	if (edlistnumber == 7) sprintf(txt, "Temp4");
	if (edlistnumber == 8) sprintf(txt, "Temp5");
	}
}

//display
messageboxstring->SetText(txt);

if ((mess_no == 37) || (mess_no == 0)) scaleval->SetLabel(scaletxt);
if ((mess_no == 38) || (mess_no == 0)) rate->SetLabel(ratetxt);
if ((mess_no == 39) || (mess_no == 0)) mag->SetLabel(magtxt);
if ((mess_no == 201) || (mess_no == 0)) cusrvaltext->SetText(cusrtxt);
if ((mess_no == 202) || (mess_no == 0)) rangevaltext->SetText(rangetxt);
if ((mess_no == 203) || (mess_no == 0)) zonevaltext->SetText(zonetxt);

Unlock();


if (othergoclicked == 0)		// Only send message if EDIT button clicked
	{
	BMessage *msg = new BMessage(EDIT_EDITGO);
	msg->AddInt32("edlisttype", edlisttype);
	msg->AddInt32("edlistnumber", edlistnumber);
	msg->AddInt16("edvalue", edvalue);
	be_app->PostMessage(msg,be_app);
	delete msg;
	}

// restore original vals
othergoclicked=0;
edvalue=0;
edlisttype=bacedlisttype;
edlistnumber=bacedlistnumber;
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// Fill in Drawbar to indicate progress 
void EDIT::Drawdrawbar(int16 mode, int16 draw1, int16 draw2, int16 draw3, int16 draw4, int16 draw5)
{

//sprintf("VALS %d %d %d %d %d %d ",(char *)mode,(char *)draw1,(char *)draw2,(char *)draw3,(char *)draw4,(char *)draw5);
// drawbar rect (5,19,205,35)
drawlen=0;

int32 start;
int32 end;
int32 max;
int32 val;
int32 len;
int32 chanmode;

chanmode = draw5; // 0=mono/stereo(0%-100%) 1=left(0%-50%) 2=right(50%-100%)

Lock();
if (mode == 0) // Same as Ai v3.0 - counts up to 10
	{
	if ((draw1 <= 10) && (draw1 >= 1))
		{
		drawlen=draw1 * 20;
		if (chanmode == 1) drawlen=drawlen >> 1;
		if (chanmode == 2)
			{
			drawlen=drawlen >> 1;
			drawlen=drawlen+100;
			}
		drawbar->FillRect(BRect(0,0,drawlen,16),B_SOLID_HIGH);
		}
	if ((draw1 == 0) && (chanmode != 2))
		{
		drawbar->FillRect(BRect(0,0,200,16),B_SOLID_LOW); // Clear
		}
	}

if (mode == 1) // Counts up to 100
	{
	if ((draw1 <= 100) && (draw1 >= 1))
		{
		drawlen=draw1 * 2;
		if (chanmode == 1) drawlen=drawlen >> 1;
		if (chanmode == 2)
			{
			drawlen=drawlen >> 1;
			drawlen=drawlen+100;
			}
		drawbar->FillRect(BRect(0,0,drawlen,16),B_SOLID_HIGH);
		}
	if ((draw1 == 0) && (chanmode != 2))
		{
		drawbar->FillRect(BRect(0,0,200,16),B_SOLID_LOW); // Clear
		}
	}

if (mode == 2) // Complex draw1=max draw2=val
	{
	max=draw1; // max
	val=draw2; // val
	
	if (val != 0)
		{
		if ((val >= 0) && (val <= max))
			{
			val = val * 200;
			drawlen = val / max;
			if (chanmode == 1) drawlen=drawlen >> 1;
			if (chanmode == 2)
				{
				drawlen=drawlen >> 1;
				drawlen=drawlen+100;
				}
			drawbar->FillRect(BRect(0,0,drawlen,16),B_SOLID_HIGH);
			}
		}
	if ((val == 0) && (chanmode != 2))
		{
		drawbar->FillRect(BRect(0,0,200,16),B_SOLID_LOW); // Clear
		}
	}

if (mode == 3) // Very Complex draw1=start draw2=end draw3=max draw4=val
	{
	start=draw1 << 1;
	end=draw2 << 1;
	max=draw3 << 1;
	val=draw4 << 1;
	
	len=end-start;
	
	if (val != 0)
		{
		if ((val >= 0) && (val <= max))
			{
			val = val * len;
			drawlen = val / max;
			drawlen = drawlen + start;
			if (chanmode == 1) drawlen=drawlen >> 1;
			if (chanmode == 2)
				{
				drawlen=drawlen >> 1;
				drawlen=drawlen+100;
				}
			drawbar->FillRect(BRect(0,0,drawlen,16),B_SOLID_HIGH);
			}
		}
	if ((val == 0) && (chanmode != 2))
		{
		drawbar->FillRect(BRect(0,0,200,16),B_SOLID_LOW); // Clear
		}
	}

// Progress % Printer
int16 valdrawlen;
valdrawlen=drawlen >> 1;
if (drawlen == 0) sprintf(progresstxt, "Progress");
else sprintf(progresstxt, "Progress %d%%",valdrawlen);
viewdrawbarbox->SetLabel(progresstxt);
Unlock();
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************


// Handling of user interface and other events 
void EDIT::MessageReceived(BMessage *message)
{
//	message->PrintToStream();
//	BWindow::MessageReceived(message);

	switch(message->what)
	{
		case EDIT_EDITCUT:	// 'editcut' is pressed...
		edlisttype=20;
		edlistnumber=1;
		Updateeditwindow(1);
			break;

		case EDIT_EDITPASTEINTO:	// 'editpasteinto' is pressed...
		edlisttype=20;
		edlistnumber=3;
		Updateeditwindow(3);
			break;

		case EDIT_EDITSETZONE:	// 'editsetzone' is pressed...
		edlisttype=21;
		edlistnumber=5;
		Updateeditwindow(5);
			break;

		case EDIT_EDITZONEOVER:	// 'editzoneover' is pressed...
		edlisttype=20;
		edlistnumber=7;
		Updateeditwindow(7);
			break;

		case EDIT_EDITZONEINTO:	// 'editzoneinto' is pressed...
		edlisttype=20;
		edlistnumber=6;
		Updateeditwindow(6);
			break;

		case EDIT_EDITPLAYVIEW:	// 'editplayview' is pressed...
		edlisttype=21;
		edlistnumber=10;
		Updateeditwindow(10);
			break;

		case EDIT_EDITPLAYRANGE:	// 'editplayrange' is pressed...
		edlisttype=21;
		edlistnumber=11;
		Updateeditwindow(11);
			break;

		case EDIT_EDITPLAYALL:	// 'editplayall' is pressed...
		edlisttype=21;
		edlistnumber=12;
		Updateeditwindow(12);
			break;

		case EDIT_EDITPLAYLOOP:	// 'editplayloop' is pressed...
		edlisttype=21;
		edlistnumber=13;
		Updateeditwindow(13);
			break;

		case EDIT_EDITSHOWRNG:	// 'editshowrng' is pressed...
		edlisttype=21;
		edlistnumber=14;
		Updateeditwindow(14);
			break;

		case EDIT_EDITSHOWALL:	// 'editshowall' is pressed...
		edlisttype=21;
		edlistnumber=15;
		Updateeditwindow(15);
			break;

		case EDIT_EDITMOVEZONE:	// 'editmovezone' is pressed...
		edlisttype=20;
		edlistnumber=16;
		Updateeditwindow(16);
			break;

		case EDIT_EDITLR:	// 'editlr' is pressed...
		edlisttype=20;
		edlistnumber=8;
		Updateeditwindow(8);
			break;

		case EDIT_EDITRANGEALL:	// 'editrangeall' is pressed...
		edlisttype=21;
		edlistnumber=18;
		Updateeditwindow(18);
			break;

		case EDIT_EDITZERO:	// 'editzero' is pressed...
		edlisttype=20;
		edlistnumber=19;
		Updateeditwindow(19);
			break;

		case EDIT_EDITRESCALE:	// 'editrescale' is pressed...
		edlisttype=20;
		edlistnumber=20;
		Updateeditwindow(20);
			break;

		case EDIT_EDITSCALE:	// 'editscale' is pressed...
		edlisttype=20;
		edlistnumber=21;
		Updateeditwindow(21);
			break;

		case EDIT_EDITCOPY:	// 'editcopy' is pressed...
		edlisttype=20;
		edlistnumber=2;
		Updateeditwindow(2);
			break;

		case EDIT_EDITPASTEOVER:	// 'editpasteover' is pressed...
		edlisttype=20;
		edlistnumber=4;
		Updateeditwindow(4);
			break;

		case EDIT_EDITUNDO:	// 'editundo' is pressed...
		edlisttype=20;
		edlistnumber=22;
		Updateeditwindow(22);
			break;

		case EDIT_EDITZOOMIN:	// 'editzoomin' is pressed...
		edlisttype=21;
		edlistnumber=23;
		Updateeditwindow(23);
			break;

		case EDIT_EDITZOOMOUT:	// 'editzoomout' is pressed...
		edlisttype=21;
		edlistnumber=24;
		Updateeditwindow(24);
			break;

		case EDIT_EDITSTART:	// 'editstart' is pressed...
		edlisttype=21;
		edlistnumber=25;
		Updateeditwindow(25);
			break;

		case EDIT_EDITFASTBACK:	// 'editfastback' is pressed...
		edlisttype=21;
		edlistnumber=26;
		Updateeditwindow(26);
			break;

		case EDIT_EDITBACK:	// 'editback' is pressed...
		edlisttype=21;
		edlistnumber=27;
		Updateeditwindow(27);
			break;

		case EDIT_EDITFORWARD:	// 'editforward' is pressed...
		edlisttype=21;
		edlistnumber=28;
		Updateeditwindow(28);
			break;

		case EDIT_EDITFASTFORWARD:	// 'editfastforward' is pressed...
		edlisttype=21;
		edlistnumber=29;
		Updateeditwindow(29);
			break;

		case EDIT_EDITEND:	// 'editend' is pressed...
		edlisttype=21;
		edlistnumber=30;
		Updateeditwindow(30);
			break;

		case EDIT_EDITRL:	// 'editrl' is pressed...
		edlisttype=20;
		edlistnumber=9;
		Updateeditwindow(9);
			break;

		case EDIT_EDITREDRAW:	// 'editredraw' is pressed...
		edlisttype=21;
		edlistnumber=17;
		Updateeditwindow(17);
			break;

		case EDIT_EDITSCALEVAL:	// 'editscaleval' is operated...
		edlisttype=21;
		edlistnumber=37;
		Updateeditwindow(37);
			break;

		case EDIT_EDITMAG:	// 'editmag' is operated...
		edlisttype=21;
		edlistnumber=39;
		Updateeditwindow(39);
			break;

		case EDIT_EDITRATE:	// 'editrate' is operated...
		edlisttype=21;
		edlistnumber=38;
		Updateeditwindow(38);
			break;

		case EDIT_EDITDRAW:	// 'editdraw' is pressed...
		edlisttype=21;
		edlistnumber=32;
		Updateeditwindow(32);
			break;

		case EDIT_EDITLEFT:	// 'editleft' is pressed...
		edlisttype=21;
		edlistnumber=33;
		Updateeditwindow(33);
			break;

		case EDIT_EDITRIGHT:	// 'editright' is pressed...
		edlisttype=21;
		edlistnumber=34;
		Updateeditwindow(34);
			break;

		case EDIT_EDITSTEREO:	// 'editstereo' is pressed...
		edlisttype=21;
		edlistnumber=35;
		Updateeditwindow(35);
			break;

		case EDIT_EDITMONO:	// 'editmono' is pressed...
		edlisttype=21;
		edlistnumber=36;
		Updateeditwindow(36);
			break;

		case EDIT_EDITLOOP:	// 'editloop' is pressed...
		edlisttype=21;
		edlistnumber=31;
		Updateeditwindow(31);
			break;

		case EDIT_EDITGO:	// 'editgo' is pressed...
		edlisttype=bacedlisttype;
		edlistnumber=bacedlistnumber;
		Updateeditwindow(200);
			break;

//		Get messages from other windows
//		Sent via the app

		case APP_CURRENT:	// New Current Effect
		message->FindInt32("aplisttype", &edlisttype);
	 	message->FindInt32("aplistnumber", &edlistnumber);
		bacedlisttype=edlisttype;
		bacedlistnumber=edlistnumber;
	 	othergoclicked=1;  // Dont send a message
		Updateeditwindow(500);
			break;

		case APP_FXGO:	// Some other GO and new Current Effect
		message->FindInt32("aplisttype", &edlisttype);
	 	message->FindInt32("aplistnumber", &edlistnumber);
		bacedlisttype=edlisttype;
		bacedlistnumber=edlistnumber;
	 	othergoclicked=1;
		Updateeditwindow(200);
			break;

		case APP_FXGONONEW:	// Some other GO, no change to current effect
		message->FindInt32("aplisttype", &edlisttype);
	 	message->FindInt32("aplistnumber", &edlistnumber);
	 	othergoclicked=1;
		Updateeditwindow(200);
			break;

		case APP_DRAWBAR:	// New Current Effect
		message->FindInt16("apbar1", &drawbarmode);
	 	message->FindInt16("apbar2", &drawbar1);
		message->FindInt16("apbar3", &drawbar2);
	 	message->FindInt16("apbar4", &drawbar3);
		message->FindInt16("apbar5", &drawbar4);
		message->FindInt16("apbar6", &drawbar5);
	 	Drawdrawbar(drawbarmode,drawbar1,drawbar2,drawbar3,drawbar4,drawbar5);
		break;

		case APP_DONE:	// Operation Completed
	 	othergoclicked=1;
		Updateeditwindow(500);
	 	Drawdrawbar(0,0,0,0,0,0);
		break;

		case SAM_RNGVALS:	// New Cusr/Range/Zone display vals
		message->FindInt32("apcusr", &apcusrval);
		message->FindInt32("aprange", &aprngval);
		message->FindInt32("apzone", &apzoneval);
		if (edcusrval != apcusrval)
			{
			edcusrval = apcusrval;
			sprintf(cusrtxt,"%d", edcusrval);
			cusrvaltext->SetText(cusrtxt);
			}
		if (edrngval != aprngval)
			{
			edrngval = aprngval;
			sprintf(rngtxt,"%d", edrngval);
			rangevaltext->SetText(rngtxt);
			}
		if (edzoneval != apzoneval)
			{
			edzoneval = apzoneval;
			sprintf(zonetxt,"%d", edzoneval);
			zonevaltext->SetText(zonetxt);
			}
		break;

		default:
	 	BWindow::MessageReceived(message);
			break;
	}
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

//	drawbar = new ProgressView(BRect(5,19,205,35), "drawbar", B_FOLLOW_ALL, B_WILL_DRAW );

ProgressView::ProgressView( BRect frame )
	: BView( frame, "drawbar", B_FOLLOW_ALL, B_WILL_DRAW )
{
	return;
}

ProgressView::~ProgressView()
{
	return;
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// Update Drawbar when image destroyed 
void ProgressView::Draw( BRect updateRect )
{
FillRect(BRect(0,0,drawlen,16),B_SOLID_HIGH);
}

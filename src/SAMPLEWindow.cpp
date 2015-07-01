// SAMPLEWindow.cpp
// Copyright (c) Blachford Technology 1999
// 28/4/99 


#include <Application.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <StringView.h>
#include <OS.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "SAMPLEWindow.h"
#include "MsgVals.h"

#include "SAMPLEWindowVars.h"

//#include "AudioRoutine.h"

/*****************************************************************/
// Ai v4.0 SAMPLEWindow Class Variables

int32 wavebuf[15][251];        //  bufs are for calculation 
int32 wavetemp[1001];           //  so is wavetemp 
int16 complexbuf[65538];

// Window numbers to check if they are open - probably have to be moved
// - some not necessary
//int32  sourcewin,filwin,saveswin,genwin, memwin,
//      quitwin,basicwin,outwin,loopwin,oscwin,wavewin,
//      envwin,rfiltwin,miscwin,ampwin,eq2win,recwin,

// Variable tables

//int32 ghost[9];     // ???
//int32 modtype[10];  // ???

int32 result; //  this will store the result of any input  
int32 value;  //  so will this 

// Other variables 

uint32 playing=0;   // sample playing = 1

uint32 loopmode=0;  // loop on/off
int32 sourcevar[4]; // ???

int16 *sampoint;		// Sample Pointer
uint32 memsize;			// size of sample block, half of fullmemsize
uint32 halfmemsize;		// Half of above

void *point;			// used for transfer from App
int32 sammemsize;		// used for transfer from App
int32 samhalfmemsize;	// used for transfer from App

int32 outchan;           // no of chans being output 
                         // 1=Mono  3=Stereo

int32 makechans;        // no of chans in use
                        // 0=mono all 1=Left 2=Right 3=Both

int32 split;             // Normal=0  Splitview=1  

int32 stop;              // ???

uint32  device,devicel;  // ???  May be used for allocating audio

int32 samrng1;			// used to transfer new cusr/range/zone vals
int32 samrng2;
int32 samrngsel;

int32 but=0,xmouse,dir;
uint32 origmouse,firstx,lastx,nx,chngdir,maxchng;

int32 viewlen;           // view length in samples

int32 resetrange;        // changes the range settings when window resized
int32 rangechange;       // changes the method by which the range is drawn
                         // 0=normal 1=calculate

int32 viewheight;       // used for redrawing window
int32 viewwidth;
int32 viewzoom=1;

uint32 samcount;   // counter

uint32 samstart;   // start of area
uint32 samend;     // end of area
uint32 samstartb;  // start of area for stereo
uint32 samendb;    // end of area for stereo
uint32 samstartL;  // start of area
uint32 samendL;    // end of area
uint32 samstartR;  // start of area for stereo
uint32 samendR;    // end of area for stereo
uint32 samlen;     // length of area to be processed

uint32 memdiv;     // length/10
uint32 memdivtodo; // value to reach to update done box
uint32 done;       // value sent to Drawdonebox
uint32 newmemdiv;     // length/?
uint32 newmemdivtodo; // value to reach to update done box
int16 drawbarside; // which side is being processed
                    // 0=all in one go  1=stereo-left  2=stereo-right

int32 scalelevel;   // value for scale on edit window

int32 position;     // position pointer     NOW CALLED ZONES 
int32 positionend;  // position end pointer 
int32 positionlen;  // length of position 
int32 poside;       // position side     

int32 filmod[2][22][260]; // stores for 7 band EQ 
int32 filstor[2][22];     // more stores for 7 band EQ

//int32 complextable=0;  //  0=none;  1=sin;     2=arcsin; 
                       //  3=cos;   4=arccos;  5=tan;    
                       //  6=tanh;  7=arctan;  8=cot;    
                       //  9=exp;   10=log;    11=sqrt;
                       //  May change these to individual tables
                       //  Will take ~1MB
                       //
                       //  OR perhaps some tables for Compress - Expand
                       //  and another for sin, cos etc..


//---------------------Buffers pinched from Ai_v1-------------------
// May not be needed

int8 buf0[6002],buf1[6002];
int8 buf0L[6002],buf1L[6002];
int16 buf2[6002];

//--------------------------------------------------------------------------------------------------
// More vars, these from ALL_FX window

int32 samfxnumber;
int32 samfxtype;
int16 samslider1;
int16 samslider2;
int16 samslider3;
int16 samslider4;
int16 samslider;
int16 samradio1;
int16 samradio2;

int32 samlistnumber;
const BRect rect(4,23,793,450);  

char samtxt[50]; // Test message text
BView* sampleview;

int32 comvals[5][22];

uint64 currentSample; // Used for playback status
uint64 sampleLength;
uint64 checksamplelength;
int16 *samplePtrL;
int16 *samplePtrR;

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

SAMPLEWindow::SAMPLEWindow()
	: BWindow(rect, "Sample Display", B_TITLED_WINDOW, B_NOT_CLOSABLE)
{
	SetSizeLimits(200,4000,200,4000);

	// Create a menubar, and the submenus...
	BMenuBar* samplemenubar = new BMenuBar(BRect(0,0,rect.right,15), "menubar");

	// Menu one
	BMenu* samplemenu = new BMenu("File");

	samplemenu->AddItem(new BMenuItem("Zero All", new BMessage(SAM_ZEROALL)));
	samplemenu->AddItem(new BMenuItem("Open...", new BMessage(SAM_OPEN)));
	samplemenu->AddItem(new BMenuItem("Save", new BMessage(SAM_SAVE)));
	samplemenu->AddItem(new BMenuItem("Save As...", new BMessage(SAM_SAVEAS)));
	BSeparatorItem *separator1 = new BSeparatorItem;
	samplemenu->AddItem(separator1);

	BMenuItem* tmpItem = new BMenuItem("About Aural illusion v4.0...", new BMessage(B_ABOUT_REQUESTED));
	tmpItem->SetTarget(be_app);
	samplemenu->AddItem(tmpItem);
	samplemenu->AddSeparatorItem();
	tmpItem = new BMenuItem("Quit Aural illusion...", new BMessage(SAM_QUIT));
	tmpItem->SetTarget(be_app);
	samplemenu->AddItem(tmpItem);
	samplemenubar->AddItem(samplemenu);

	// Menu two
	samplemenu = new BMenu("Edit");
	samplemenu->AddItem(new BMenuItem("temp1", new BMessage(SAM_TEMP1)));
	samplemenu->AddItem(new BMenuItem("temp2", new BMessage(SAM_TEMP2)));
	samplemenu->AddSeparatorItem();
	samplemenu->AddItem(new BMenuItem("temp3", new BMessage(SAM_TEMP3)));
	samplemenubar->AddItem(samplemenu);

	// Menu three
	samplemenu = new BMenu("Cool");
	samplemenu->AddItem(scaleItem = new BMenuItem("Attractor Display", new BMessage(SAM_TEMP4)));
	samplemenu->AddItem(new BMenuItem("temp5", new BMessage(SAM_TEMP5)));
//	scaleItem->SetMarked(true);
	samplemenubar->AddItem(samplemenu);

	AddChild(samplemenubar);

	// Create the View
	float mb_height = samplemenubar->Bounds().Height();
	sampleview = new SampleView(BRect(0, mb_height, rect.right, rect.bottom - mb_height));
	sampleview->SetViewColor(0,0,0); // View is black
	sampleview->SetLowColor(0,0,0);

/*
	messageboxstring = new BStringView(BRect(3,0,259,16), "messageboxstring",
							"",  B_WILL_DRAW);
	messageboxstring->SetHighColor(255,255,255); // text to white
	sampleview->AddChild(messageboxstring);
*/

	// Other variables Initisation
	playing=0;		// sample playing = off
	loopmode=0;		// loop = off
	viewzoom=1;		// not zoomed
//	complextable=0;
	scalelevel=50;
	makechans=3; // 0=Left 1=Right 2=Stereo 3=Mono
	playing=0;
	stop=0;
	// Screen & Range Drawing stuff 
	viewheight=408;		// TEST
	viewwidth=789;		// TEST

	// show the window
	AddChild(sampleview);
	Show();

//	Setcalcvals();

//	//Initialise the Audio playback routines
//	AudioInit(SAMPLEWindow::ProduceNextBuffer, 1024);	
//	// CONTANTS ! TODO
//	AudioSetParameters(44100, 2, 2);
}

//-----------------------------------------------------------------

SAMPLEWindow::~SAMPLEWindow(void) // Destructor
{
//	AudioClose();
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
// Sets up values for calculation 

void SAMPLEWindow::Setcalcvals(void)
{
//  samcount;    start of area
//  samstart;    start of area
//  samend;      end of area
//  samstartb;   start of area for stereo
//  samendb;     end of area for stereo
//  samlen;      length of area to be processed
//  memdiv;      length/10
//  memdivtodo;  value to reach to update done box
//  done;        valuse sent to Drawdonebox

 if (makechans==0) // Left
   {
   samstart=rngstrval;
   if ((samstart>=0) && (samstart<halfmemsize))
      {
      samend=rnglenval+rngstrval;
      if (samend>=halfmemsize) samend=halfmemsize-1;
      samlen=samend-samstart;
      memdiv=samlen/75;
      memdivtodo=memdiv+samstart;
      samstartb=samstart+halfmemsize;
      samendb=samend+halfmemsize;
      samstartL=samstart;
      samendL=samend;
      samstartR=samstartb;
      samendR=samendb;
      }
   else
      {
      samstart=0;
      samend=0;
      }
   }

 if (makechans==1) // Right
   {
   samend=rnglenval+rngstrval;
   if (samend>=halfmemsize)
      {
      samstart=rngstrval;
      if (samstart<=halfmemsize) samstart=halfmemsize-1;
      if (samend>=memsize) samend=memsize;
      samlen=samend-samstart;
      memdiv=samlen/75;
      memdivtodo=memdiv+samstart;
      samstartb=samstart-halfmemsize;
      samendb=samend-halfmemsize;
      samstartL=samstartb;
      samendL=samendb;
      samstartR=samstart;
      samendR=samend;
      }
   else
      {
      samstart=0;
      samend=0;
      }
   }

 if (makechans==2) // Stereo
   {
   samstart=rngstrval;
   if (samstart<=halfmemsize)
      {
      if (samstart<=0) samstart=0;
      samend=rnglenval+rngstrval;
      if (samend>=halfmemsize) samend=halfmemsize-1;
      samlen=samend-samstart;
      samstartb=samstart+halfmemsize;
      samendb=samend+halfmemsize;
      memdiv=samlen/75;
      memdivtodo=memdiv+samstart;
      samstartL=samstart;
      samendL=samend;
      samstartR=samstartb;
      samendR=samendb;
      }
   else
      {
      samstart=0;
      samend=0;
      samstartb=0;
      samendb=0;
      }
   }

 if (makechans==3) // mono all
   {
   samstart=rngstrval;
   if (samstart<=memsize)
      {
      if (samstart<=0) samstart=0;
      if (samstart>=memsize) samstart=memsize;
      samend=rnglenval+rngstrval;
      if (samend>=memsize) samend=memsize-1;
      if (samend<=0) samend=0;
      samlen=samend-samstart;
      memdiv=samlen/75;
      memdivtodo=memdiv+samstart;
      samstartL=0;
      samendL=0;
      samstartR=0;
      samendR=0;
      }
   else
      {
      samstart=0;
      samend=0;
      }
   }

BMessage *msg = new BMessage(SAM_RNGVALS);
msg->AddInt32("samrng1", rngval);
msg->AddInt32("samrng2", rnglenval);
msg->AddInt32("samrngsel", zonelenval);
msg->AddInt32("makechans", makechans);
msg->AddInt32("samstart", rngstrval);
be_app->PostMessage(msg,be_app);
delete (msg);

done=0;
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::Drawdonebox(uint32 done) // Compatibility for v3.0 drawbar drawing 
{
int16 smalldone;
smalldone = done;

	BMessage *msg = new BMessage(FXR_DRAWBAR);
	msg->AddInt16("apbar1", 0);
	msg->AddInt16("apbar2", smalldone);
	msg->AddInt16("apbar3", 0);
	msg->AddInt16("apbar4", 0);
	msg->AddInt16("apbar5", 0);
	msg->AddInt16("apbar6", 0);
	be_app->PostMessage(msg);
	delete (msg);

if (smalldone == 10) snooze(100000);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::Newdrawdonebox(int16 draw1, int16 draw2, int16 draw3, int16 draw4, int16 draw5, int16 draw6)
{
	BMessage *msg = new BMessage(FXR_DRAWBAR);
	msg->AddInt16("apbar1", draw1);
	msg->AddInt16("apbar2", draw2);
	msg->AddInt16("apbar3", draw3);
	msg->AddInt16("apbar4", draw4);
	msg->AddInt16("apbar5", draw5);
	msg->AddInt16("apbar6", draw6);
	be_app->PostMessage(msg);
	delete (msg);

/*
//Drawdrawbar(int16 mode, int16 draw1, int16 draw2, int16 draw3, int16 draw4, int16 draw5)

int32 start;
int32 end;
int32 max;
int32 val;
int32 len;
int32 chanmode;

chanmode = draw5; // 0=mono/stereo(0%-100%) 1=left(0%-50%) 2=right(50%-100%)

mode 0  Same as Ai v3.0 - counts up to 10
mode 1  Counts up to 100
mode 2  draw1=max draw2=val
mode 3  draw1=start draw2=end draw3=max draw4=val
*/
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::Dodisplay(void)
{
uint32 temp;
uint32 tempb;

if (samfxnumber == 5)	// 5  'editsetzone
	{
	Setcalcvals();

	position=samstart;
	positionend=samend;
	if (samend>samstart)
		{
		positionlen=positionend-position;
		}
	else 
		{
		positionend=0;
		positionlen=0;
		}
	if (makechans==0) poside=0;	// Left
	if (makechans==1) poside=1;	// Right
	if (makechans==2) poside=2;	// Stereo
	if (makechans==3)
		{
		if (position<halfmemsize) poside=0;
		if (position>=halfmemsize) poside=1;
		}
	drawzoneside=poside;
	}
if (samfxnumber == 10)	// 10 'editplayview
	{
	if (playing == 1)
		{
//		AudioStop();
		playing = 0;
		}
	else
		{
		currentSample = 0;
		if (makechans == 0) // Left
			{
			sampleLength = viewlen;
			samplePtrL = sampoint+viewstart;
			samplePtrR = sampoint+viewstart;
			checksamplelength = viewlen - viewstart;
			}
		if (makechans == 1) // Right
			{
			sampleLength = viewlen;
			samplePtrL = sampoint+viewstart;
			samplePtrR = sampoint+viewstart;
			checksamplelength = viewlen - viewstart;
			}
		if (makechans == 2) // Stereo
			{
			sampleLength = viewlen;
			samplePtrL = sampoint+viewstart;
			samplePtrR = sampoint + halfmemsize;
			checksamplelength = viewlen - viewstart;
			}
		if (makechans == 3) // mono all
			{
			sampleLength = viewlen;
			samplePtrL = sampoint+viewstart;
			samplePtrR = sampoint+viewstart;
			checksamplelength = viewlen - viewstart;
			}
//		AudioStart();
		playing = 1;
//		printf("sampoint %d samstart %d samend %d halfmemsize %d\n",&*sampoint,samstart,samend,halfmemsize);
		}
	}
if (samfxnumber == 11)	// 11 'editplayrange
	{
	if (playing == 1)
		{
//		AudioStop();
		playing = 0;
		}
	else
		{
		currentSample = 0;
		if (makechans == 0) // Left
			{
			sampleLength = rnglenval;
			samplePtrL = sampoint + rngstrval;
			samplePtrR = sampoint + rngstrval;
			}
		if (makechans == 1) // Right
			{
			sampleLength = rnglenval;
			samplePtrL = sampoint + rngstrval;
			samplePtrR = sampoint + rngstrval;
			}
		if (makechans == 2) // Stereo
			{
			sampleLength = rnglenval;
			samplePtrL = sampoint + rngstrval;
			samplePtrR = sampoint + rngstrval + halfmemsize;
			}
		if (makechans == 3) // mono all
			{
			sampleLength = rnglenval;
			samplePtrL = sampoint + rngstrval;
			samplePtrR = sampoint + rngstrval;
			}
//		AudioStart();
		playing = 1;
//		printf("sampoint %d samstart %d samend %d halfmemsize %d\n",&*sampoint,samstart,samend,halfmemsize);
		}
	}
if (samfxnumber == 12)	// 12 'editplayall
	{
	if (playing == 1)
		{
//		AudioStop();
		playing = 0;
		}
	else
		{		
		currentSample = 0;
		if (makechans == 0) // Left
			{
			sampleLength = halfmemsize;
			samplePtrL = sampoint;
			samplePtrR = sampoint;
			}
		if (makechans == 1) // Right
			{
			sampleLength = halfmemsize;
			samplePtrL = sampoint + halfmemsize;
			samplePtrR = sampoint + halfmemsize;
			}
		if (makechans == 2) // Stereo
			{
			sampleLength = halfmemsize;
			samplePtrL = sampoint;
			samplePtrR = sampoint + halfmemsize;
			}
		if (makechans == 3) // mono all
			{
			sampleLength = memsize;
			samplePtrL = sampoint;
			samplePtrR = sampoint;
			}
//		AudioStart();
		playing = 1;
//		printf("sampoint %d samstart %d samend %d halfmemsize %d\n",&*sampoint,samstart,samend,halfmemsize);
		}
	}
if (samfxnumber == 13)	// 13 'editplayloop
	{
	
	}
if (samfxnumber == 14)	// 14 'editshowrng
	{
	viewstart=rngstrval;
	if (makechans==1) viewstart=viewstart-halfmemsize;
	if (viewstart<=0) viewstart=0;
	viewlen=rnglenval;
	if (viewlen<=viewwidth) viewlen=viewwidth;
	curjump=viewlen/viewwidth;
	scurjump=curjump/2;
	if (makechans<=2)
		{
		curjump=curjump*2;
		scurjump=scurjump*2;
		}
	rangechange=1;
	resetrange=1;
	}
if (samfxnumber == 15)	// 15 'editshowall
	{
	if (makechans==0)
      {
      viewstart=0;
      viewlen=halfmemsize;
      }
    if (makechans==1) 
      {
      viewstart=0;
      viewlen=halfmemsize;
      }
    if (makechans==2) 
      {
      viewstart=0;
      viewlen=halfmemsize;
      }
    if (makechans==3) 
      {
      viewstart=0;
      viewlen=memsize;
      }
    curjump=memsize/viewwidth;
    scurjump=curjump/2;
    rangechange=1;
    resetrange=1;
	}
if (samfxnumber == 17)	// 17 'editredraw
	{
	
	}
if (samfxnumber == 18)	// 18 'editrangeall
	{
	if (viewlen>=halfmemsize)
     {
     if (makechans==0)
       {
       rngstrval=0;
       rnglenval=halfmemsize;
       }
     if (makechans==1) 
       {
       rngstrval=0;
       rnglenval=halfmemsize;
       }
     if (makechans==2) 
       {
       rngstrval=0;
       rnglenval=halfmemsize;
       }
     if (makechans==3) 
       {
       rngstrval=0;
       rnglenval=memsize;
       }
     }
   else
     {
     rnglenval=viewlen;
     rngstrval=viewstart;
     }
   if ((makechans==1) && (rngstrval<=halfmemsize))
     {
     rngstrval=rngstrval+halfmemsize;
     }
    resetrange=1;
    rangechange=1;
    // tell EDIT about new range
	BMessage *msg = new BMessage(SAM_RNGVALS);
	msg->AddInt32("samrng1", rngstrval);
	msg->AddInt32("samrng2", rnglenval);
	msg->AddInt32("samrngsel", 0); //apzone);
	be_app->PostMessage(msg,be_app);
	delete (msg);
	}
if (samfxnumber == 23)	// 23 'editzoomin
	{
	temp=viewlen/2;
	if (temp>=viewwidth) viewlen=temp;
	if (viewlen<=viewwidth) viewlen=viewwidth;
	viewstart=rngstrval;
	if (viewstart<=0) viewstart=0;
	curjump=viewlen/viewwidth;
	scurjump=curjump/2;
	rangechange=1;
	resetrange=1;
	}
if (samfxnumber == 24)	// 24 'editzoomout
	{
	temp=viewlen/4;
	viewstart=viewstart-temp;
	if (viewstart<=0) viewstart=0;
	viewlen=viewlen*2;
	if (viewlen>=memsize) viewlen=memsize;
	curjump=viewlen/viewwidth;
	scurjump=curjump/2;
	rangechange=1;
	resetrange=1;
	}
if (samfxnumber == 25)	// 25 'editstart
	{
	viewstart=0;
	resetrange=1;
	rangechange=1;
	}
if (samfxnumber == 26)	// 26 'editfastback
	{
	temp=viewlen;
    temp=viewlen >> 3;
    temp=viewlen-temp;
    viewstart=viewstart-temp;
    if (viewstart<=0) viewstart=0;
    rangechange=1;
    resetrange=1;
	}
if (samfxnumber == 27)	// 27 'editback
	{
	temp=viewlen >> 2;
    viewstart=viewstart-temp;
    if (viewstart<=0) viewstart=0;
    rangechange=1;
    resetrange=1;
	}
if (samfxnumber == 28)	// 28 'editforward
	{
	temp=viewlen >> 2;
    temp=viewstart+temp;
    tempb=temp+viewlen;
    if (makechans<=2)
      {
      if (tempb>halfmemsize) temp=halfmemsize-viewlen;
      }
    if (makechans==3)
      {
      if (tempb>memsize) temp=memsize-viewlen;
      }
    viewstart=temp;
    rangechange=1;
    resetrange=1;
	}
if (samfxnumber == 29)	// 29 'editfastforward
	{
	temp=viewlen >> 3;
    temp=viewlen-temp;
    tempb=viewstart;
    tempb=tempb+temp;
    if (makechans<=2)
      {
      if ((tempb+viewlen)>=halfmemsize) tempb=halfmemsize-viewlen;
      }
    if (makechans==3)
      {
      if ((tempb+viewlen)>=memsize) tempb=memsize-viewlen;
      }
    viewstart=tempb;
    rangechange=1;
    resetrange=1;
	}
if (samfxnumber == 30)	// 30 'editend
	{
	if (makechans<=2)
      {
      viewstart=halfmemsize-viewlen;
      }
    if (makechans==3)
      {
      viewstart=memsize-viewlen;
      }
    rangechange=1;
    resetrange=1;
	}
if (samfxnumber == 31)	// 31 'editloop
	{
	
	}
if (samfxnumber == 32)	// 32 'editdraw
	{
	
	}
if (samfxnumber == 33) // view mode changed
	{
	makechans = samslider1;
	Setcalcvals();
	}
if (samfxnumber == 37)	// 37 'editscaleval
	{
	
	}
if (samfxnumber == 38)	// 38 'editrate
	{
	
	}
if (samfxnumber == 39) // view magnification - editmag
	{
	viewzoom = samslider1;
	}
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::Drawsample(void) 
{
uint32 Count=0;
int32 Jum=0,Jumb;
int32  Temp;
int16 Tempw=0;

int32 sdiv,div,heightsize,sheightsize,halfheight;
int32 quartheight,dubquartheight;
int32 drawstart;
int32 drawend;
int32 drawbottom;
int32 drawtop;
int32 drawpos;

int32 minL,maxL;
int32 minR,maxR;

drawchans=makechans;
heightsize=viewheight;

div=65500/heightsize;
div++;
if (div==0) div=1;

if (makechans == 2)
	{
	sheightsize=viewheight-4;
	sdiv=65500/sheightsize;
	sdiv++;
	if (sdiv==0) sdiv=1;
	}

halfheight=heightsize >> 1;
halfheight=halfheight+1;

Temp=viewstart+viewlen;

if (makechans<=2)
   {
   if (Temp>=halfmemsize) viewstart=halfmemsize-viewlen;
   if (viewlen>=halfmemsize) viewlen=halfmemsize;
   }
if (makechans==3)
   {
   if (Temp>=memsize) viewstart=memsize-viewlen;
   if (viewlen>=memsize) viewlen=memsize;
   }

if (viewstart<=0) viewstart=0;

int32 halfposheight;

sampleview->SetDrawingMode(B_OP_COPY);
sampleview->FillRect(BRect(0,1,viewwidth,viewheight),B_SOLID_LOW); // fill background Black

drawrngbottom = viewheight;


// ----------------------------------------------------------------------------------
// Displays Left Hand Side

  if (makechans==0)	
        {
        minL=1;
        maxL=viewheight;
        div=div/viewzoom;

        if (scurjump<=0) scurjump=1;

        Xlim=viewwidth;
        Count=0;

		div=65536/div;
		div=~div;

        while(Count<Xlim)
           {
           Temp=*(sampoint+Jum+viewstart);
           Temp=Temp*div;
           Temp=Temp >> 16;
           Tempw=Temp;
           Tempw=Tempw+halfheight;
           if (Tempw<=minL) Tempw=minL;
           if (Tempw>=maxL) Tempw=maxL;
           z[Count]=Tempw;
           Jum=Jum+scurjump;
           Count++;
           }

        z[0]=halfheight;
        z[Count]=halfheight;


       Count=0;
        sampleview->StrokeLine(BPoint(Count,z[Count]),BPoint(Count+1,z[Count+1]),B_SOLID_HIGH);
        while(Count<Xlim)
			{
			Count++;
			sampleview->StrokeLine(BPoint(Count,z[Count]),B_SOLID_HIGH);
			}
        }


// ----------------------------------------------------------------------------------
// Displays Right hand side

  if (makechans==1)
        {
        minL=1;
        maxL=viewheight;
        div=div/viewzoom;

		div=65536/div;
		div=~div;

        if (scurjump<=0) scurjump=1;

        Xlim=viewwidth;
        Count=0;
        Jum=halfmemsize;

        while(Count<Xlim)
           {
           Temp=*(sampoint+Jum+viewstart);
           Temp=Temp*div;
           Temp=Temp >> 16;
           Tempw=Temp;
           Tempw=Tempw+halfheight;
           if (Tempw<=minL) Tempw=minL;
           if (Tempw>=maxL) Tempw=maxL;   
           z[Count]=Tempw;
           Jum=Jum+scurjump;
           Count++;
           }

        z[0]=halfheight;
        z[Count]=halfheight;

        Count=0;
        sampleview->StrokeLine(BPoint(Count,z[Count]),BPoint(Count+1,z[Count+1]),B_SOLID_HIGH);
        while(Count<Xlim)
			{
			Count++;
			sampleview->StrokeLine(BPoint(Count,z[Count]),B_SOLID_HIGH);
			}
        }


// ----------------------------------------------------------------------------------
// Displays Stereo

    if (makechans==2)
        {
        if (scurjump<=0) scurjump=1;
        Jum=0;
        Jumb=halfmemsize;
        quartheight=heightsize >> 2;
        quartheight=quartheight+1;
        sdiv=sdiv << 1;
        dubquartheight=quartheight+halfheight-1;

        minL=2;
        maxL=halfheight-2;
        minR=halfheight+1;
        maxR=viewheight-1;
        sdiv=sdiv/viewzoom;

		sdiv=65536/sdiv;
		sdiv=~sdiv;

        Xlim=viewwidth;
        Count=0;

        while(Count<Xlim)
           {
           Temp=*(sampoint+Jum+viewstart);
           Temp=Temp*sdiv;
           Temp=Temp >> 16;
           Tempw=Temp;
           Tempw=Tempw+quartheight;
           if (Tempw<=minL) Tempw=minL;
           if (Tempw>=maxL) Tempw=maxL;
           z[Count]=Tempw;
           Jum=Jum+scurjump;
           Count++;
           }

        Count=0;
        while(Count<Xlim)
           {
           Temp=*(sampoint+Jumb+viewstart);

           Temp=Temp*sdiv;
           Temp=Temp >> 16;
           Tempw=Temp;
           Tempw=Tempw+dubquartheight;
           if (Tempw<=minR) Tempw=minR;
           if (Tempw>=maxR) Tempw=maxR;
           zb[Count]=Tempw;
           Jumb=Jumb+scurjump;
           Count++;
           }

        z[0]=quartheight;
        z[viewwidth]=quartheight;

        zb[0]=dubquartheight;
        zb[viewwidth]=dubquartheight;

        Count=0;
        
        while(Count<Xlim)
			{
	        sampleview->StrokeLine(BPoint(Count,z[Count]),BPoint(Count+1,z[Count+1]),B_SOLID_HIGH);
			sampleview->StrokeLine(BPoint(Count,zb[Count]),BPoint(Count+1,zb[Count+1]),B_SOLID_HIGH);
			Count++;
			}
        }


// ----------------------------------------------------------------------------------
// Displays Mono

  if (makechans==3)
        {
        minL=1;
        maxL=viewheight;
        div=div/viewzoom;
        if (curjump<=0) curjump=1;

        Xlim=viewwidth;
        Count=0;
		div=65536/div;
		div=~div;

        while(Count<Xlim)
			{
           Temp=*(sampoint+Jum+viewstart);
           Temp=Temp*div;
           Temp=Temp >> 16;
           Tempw=Temp;
           Tempw=Tempw+halfheight;
           if (Tempw<minL) Tempw=minL;
           if (Tempw>maxL) Tempw=maxL;   
           z[Count]=Tempw;
           Jum=Jum+curjump;
           Count++;
           }

        z[0]=halfheight;
        z[Count]=halfheight;

        Xlim=viewwidth;
        Count=0;
        
        sampleview->StrokeLine(BPoint(Count,z[Count]),BPoint(Count+1,z[Count+1]),B_SOLID_HIGH);
        
        while(Count<Xlim)
			{
			Count++;
			sampleview->StrokeLine(BPoint(Count,z[Count]),B_SOLID_HIGH);
			}
		}


// ----------------------------------------------------------------------------------
//  Draw Range Here

drawbottom=viewheight;
drawstart=rngstart;
drawend=rngend;

if (rangechange==1)
 {
 if ((makechans==0) || (makechans==2))
  {
  drawstart=rngstrval;
  drawstart=drawstart-viewstart;
  drawstart=drawstart/scurjump;

  drawend=rngstrval+rnglenval;
  drawend=drawend-viewstart;
  drawend=drawend/scurjump;
  }

 if (makechans==1)
  {
  drawstart=rngstrval;
  drawstart=drawstart-viewstart;
  drawstart=drawstart-halfmemsize;
  drawstart=drawstart/scurjump;
  if (drawstart<=0) drawstart=0;

  drawend=rngstrval+rnglenval;
  drawend=drawend-viewstart;
  drawend=drawend-halfmemsize;
  drawend=drawend/scurjump;
  if (drawend<=0) drawend=0;
  }

 if (makechans==3)
  {
  drawstart=rngstrval;
  drawstart=drawstart-viewstart;
  drawstart=drawstart/curjump;

  drawend=rngstrval+rnglenval;
  drawend=drawend-viewstart;
  drawend=drawend/curjump;
  }

 }

if (drawend>viewwidth) drawend=viewwidth;

if (resetrange==1)
  {
  rngstart=drawstart;
  rngend=drawend;
  rnglen=rngend-rngstart;
  resetrange=0;
  }

drawrngstrt = drawstart;	// set for Draw() method;
drawrngtop = 1;
drawrngend = drawend;
drawrngbottom = drawbottom;

sampleview->SetDrawingMode(B_OP_INVERT);	// Invert for Range Display
sampleview->FillRect(BRect(drawstart,1,drawend,drawbottom));
sampleview->SetDrawingMode(B_OP_COPY);		// Backto Normal for other drawing.


// ----------------------------------------------------------------------------------
//  Draw Position Start Here

drawpos=5000;

 if ((makechans==0) && (position<=halfmemsize))
  {
  drawtop=0;
  drawpos=position-viewstart;
  drawpos=drawpos/scurjump;
  }

 if ((makechans==1) && (position>=halfmemsize))
  {
  drawtop=11;
  drawpos=position-viewstart;
  drawpos=drawpos-halfmemsize;
  drawpos=drawpos/scurjump;
  }

 if (makechans==2)
  {
  if (poside==0)
     {
     drawpos=position-viewstart;
     drawpos=drawpos/scurjump;
     }
  if (poside==1)
     {
     drawtop=halfheight+12;
     drawpos=position-viewstart;
     drawpos=drawpos-halfmemsize;
     drawpos=drawpos/scurjump;
     }
  if (poside==2)
     {
     drawtop=11;
     drawpos=position-viewstart;
     drawpos=drawpos/scurjump;
     }
  }

 if ((makechans==3) && (position<=memsize))
  {
  drawtop=0;
  drawpos=position-viewstart;
  drawpos=drawpos/curjump;
  }

if (drawpos<5000)
    {
    if (drawpos>viewwidth) drawpos=viewwidth;
	drawzonestrt = drawpos;

//	sampleview->SetHighColor(255,0,0);
//	sampleview->StrokeLine(BPoint(drawpos,1),BPoint(drawpos,viewheight),B_SOLID_HIGH);
//	sampleview->SetHighColor(255,255,255);
    }


// ----------------------------------------------------------------------------------
//  Draw Position END Here

if (positionlen>=1)
{
drawpos=5000;

 if ((makechans==0) && (position<=halfmemsize))
  {
  drawtop=1;
  drawpos=positionend-viewstart;
  drawpos=drawpos/scurjump;
  }

 if ((makechans==1) && (positionend>=halfmemsize))
  {
  drawtop=1;
  drawpos=positionend-viewstart;
  drawpos=drawpos-halfmemsize;
  drawpos=drawpos/scurjump;
  }

 if (makechans==2)
  {
  if (poside==0)
     {
     drawpos=positionend-viewstart;
     drawpos=drawpos/scurjump;
     }
  if (poside==1)
     {
     drawtop=halfheight+12;
     drawpos=positionend-viewstart;
     drawpos=drawpos-halfmemsize;
     drawpos=drawpos/scurjump;
     }
  if (poside==2)
     {
     drawtop=11;
     drawpos=positionend-viewstart;
     drawpos=drawpos/scurjump;
     }
  }

 if ((makechans==3) && (positionend<=memsize))
  {
  drawtop=1;
  drawpos=positionend-viewstart;
  drawpos=drawpos/curjump;
  }

if (drawpos<5000)
    {
	drawzoneend = drawpos;
//	sampleview->SetHighColor(255,0,0);
//	sampleview->StrokeLine(BPoint(drawpos,1),BPoint(drawpos,viewheight),B_SOLID_HIGH);
//	sampleview->SetHighColor(255,255,255);
	}
    
}	// position


// ----------------------------------------------------------------------------------
// Redraw Zone display

	sampleview->SetDrawingMode(B_OP_COPY);
	sampleview->SetHighColor(255,0,0);
	if ((drawzoneside == 0) && (drawchans == 0))
		{
		sampleview->StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		sampleview->StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	if ((drawzoneside == 1) && (drawchans == 1))
		{
		sampleview->StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		sampleview->StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	if (drawchans == 2)
		{
		halfposheight = drawrngbottom >> 1;
		if (drawzoneside == 0)
			{
			sampleview->StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,halfposheight),B_SOLID_HIGH);
			sampleview->StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,halfposheight),B_SOLID_HIGH);
			}
		if (drawzoneside == 1)
			{
			sampleview->StrokeLine(BPoint(drawzonestrt,halfposheight),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
			sampleview->StrokeLine(BPoint(drawzoneend,halfposheight),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
			}
		if (drawzoneside == 2)
			{
			sampleview->StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
			sampleview->StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
			}
		}
	if (drawchans == 3)
		{
		sampleview->StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		sampleview->StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	sampleview->SetHighColor(255,255,255);


if (positionend >= position) zonelenval = positionend - position;
if (zonelenval < 0) zonelenval =0;

BMessage *msg = new BMessage(SAM_RNGVALS);
msg->AddInt32("samrng1", rngval);
msg->AddInt32("samrng2", rnglenval);
msg->AddInt32("samrngsel", zonelenval);
msg->AddInt32("makechans", drawchans);
msg->AddInt32("samstart", rngstrval);
be_app->PostMessage(msg,be_app);
delete (msg);

BMessage *mesg = new BMessage(APP_DRAWATTRACT);
mesg->AddInt32("rng", rngstrval);
mesg->AddInt32("updateattract", 0);
be_app->PostMessage(mesg,be_app);
delete (mesg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::FrameResized(float width, float height)
{
	viewheight=height-20;
	viewwidth=width;
	curjump=viewlen/viewwidth;
	if (makechans<=2) curjump=curjump*2;
	if (curjump<=0) curjump=1;
	scurjump=curjump/2;
	if (scurjump<=0) scurjump=1;
	resetrange=1;
	rangechange=1;
	
	Drawsample();

//sampleview::Tellviewmax(viewwidth);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::MessageReceived(BMessage* msg)
{
//	msg->PrintToStream();
//	BWindow::MessageReceived(msg);
int16 temp;
int16 samiewtyp;
int16 samiewmsgtyp;

	switch(msg->what)
	{
	case SAM_ZEROALL: // Zero all memory
		samlistnumber = 0;
		Sendmess(1);
		break;

	case SAM_OPEN: // Load sample
		samlistnumber = 1;
		Sendmess(1);
		break;

	case SAM_SAVE: // Save sample
		samlistnumber = 2;
		Sendmess(1);
		break;

	case SAM_SAVEAS: // Save sample As
		samlistnumber = 3;
		Sendmess(1);
		break;

	case SAM_TEMP1: // 
		samlistnumber = 4;
		Sendmess(1);
		break;

	case SAM_TEMP2: // 
		samlistnumber = 5;
		Sendmess(1);
		break;

	case SAM_TEMP3: // 
		samlistnumber = 6;
		Sendmess(1);
		break;

	case SAM_TEMP4: // 
		samlistnumber = 7;
		Sendmess(1);
		break;

	case SAM_TEMP5: // 
		samlistnumber = 8;
		Sendmess(1);
		break;

// Messages from other windows

	case APP_MEMSETUP: // Memory Settings
		msg->FindPointer("appoint", &point);
		msg->FindInt32("apmemsize", &sammemsize);
		msg->FindInt32("aphalfmemsize", &samhalfmemsize);
		sampoint = (int16 *)point;		// Convert these to values we understand
		memsize=sammemsize;
		halfmemsize=samhalfmemsize;
		drawhalfmemsize = halfmemsize;
		Setcalcvals();	//	Initial setup
		samfxtype=21;	// Show all
		samfxnumber=15;
		Dodisplay();
		Setcalcvals();	// Final setup
		Drawsample();
		Sendmess(2);	// Ready
		break;

	case APP_SETTINGS: // Start new effect
		msg->FindInt32("apfxtype", &samfxtype);
		msg->FindInt32("apfxnumber", &samfxnumber);
		msg->FindInt16("apslider1", &samslider1);
		msg->FindInt16("apslider2", &samslider2);
		msg->FindInt16("apslider3", &samslider3);
		msg->FindInt16("apslider4", &samslider4);
		msg->FindInt16("apslider", &samslider);
		msg->FindInt16("apradio1", &samradio1);
		msg->FindInt16("apradio2", &samradio2);
//	sprintf(samtxt, "%d %d %d %d %d %d %d %d %d",samfxtype,samfxnumber,samslider1,samslider2,samslider3,samslider4,samslider,samradio1,samradio2);
//	messageboxstring->SetText(samtxt);
		if (samfxtype <= 20)	Doeffect();	// These perform operations on samples
		if (samfxtype == 21) Dodisplay();	// These effect the display
		if ((samfxtype == 22) && (samfxnumber == 0))	Doeffect();	// Zero All
		Drawsample();
		Sendmess(2);
		break;

		case IAPGO_SET:	// New Val in IEW
//		msg->FindInt32("listtype", &samlisttype);
//		msg->FindInt32("listnumber", &samlistnumber);
		msg->FindInt32("fxtype", &samfxtype);
		msg->FindInt32("fxnumber", &samfxnumber);
		msg->FindInt16("eqmsgtyp", &samiewmsgtyp);
		msg->FindInt16("iewtyp", &samiewtyp);
		msg->FindInt16("eq0lev", &temp);
		comvals[samiewtyp][0]=(int32)temp;
		msg->FindInt16("eq1lev", &temp);
		comvals[samiewtyp][1]=(int32)temp;
		msg->FindInt16("eq2lev", &temp);
		comvals[samiewtyp][2]=(int32)temp;
		msg->FindInt16("eq3lev", &temp);
		comvals[samiewtyp][3]=(int32)temp;
		msg->FindInt16("eq4lev", &temp);
		comvals[samiewtyp][4]=(int32)temp;
		msg->FindInt16("eq5lev", &temp);
		comvals[samiewtyp][5]=(int32)temp;
		msg->FindInt16("eq6lev", &temp);
		comvals[samiewtyp][6]=(int32)temp;
		msg->FindInt16("eq7lev", &temp);
		comvals[samiewtyp][7]=(int32)temp;
		msg->FindInt16("eq8lev", &temp);
		comvals[samiewtyp][8]=(int32)temp;
		msg->FindInt16("eq9lev", &temp);
		comvals[samiewtyp][9]=(int32)temp;
		msg->FindInt16("eq10lev", &temp);
		comvals[samiewtyp][10]=(int32)temp;
		msg->FindInt16("eq11lev", &temp);
		comvals[samiewtyp][11]=(int32)temp;
		msg->FindInt16("eq12lev", &temp);
		comvals[samiewtyp][12]=(int32)temp;
		msg->FindInt16("eq13lev", &temp);
		comvals[samiewtyp][13]=(int32)temp;
		msg->FindInt16("eq14lev", &temp);
		comvals[samiewtyp][14]=(int32)temp;
		msg->FindInt16("eq15lev", &temp);
		comvals[samiewtyp][15]=(int32)temp;
		msg->FindInt16("eq16lev", &temp);
		comvals[samiewtyp][16]=(int32)temp;
		msg->FindInt16("eq17lev", &temp);
		comvals[samiewtyp][17]=(int32)temp;
		msg->FindInt16("eq18lev", &temp);
		comvals[samiewtyp][18]=(int32)temp;
		msg->FindInt16("eq19lev", &temp);
		comvals[samiewtyp][19]=(int32)temp;
		msg->FindInt16("eq20lev", &temp);
		comvals[samiewtyp][20]=(int32)temp;
//	sprintf(samtxt, "%d %d %d %d %d %d %d %d %d",samfxtype,samfxnumber,samslider1,samslider2,samslider3,samslider4,samslider,samradio1,samradio2);
//	messageboxstring->SetText(samtxt);
		if (samfxtype <= 20)	Doeffect();	// These perform operations on samples
//		if (samfxtype == 21) Dodisplay();	// These effect the display
//		if ((samfxtype == 22) && (samfxnumber == 0))	Doeffect();	// Zero All
		Drawsample();
		Sendmess(2);
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

void SAMPLEWindow::Sendmess(int32 messno)
{
if (messno == 0) // Tell APP we're done
	{
	int16 count; // test for drawbar
	for(count=0;count<=150;count++)
		{
		BMessage *msg = new BMessage(FXR_DRAWBAR);
		msg->AddInt16("apbar1", 2);
		msg->AddInt16("apbar2", 150);
		msg->AddInt16("apbar3", count);
		msg->AddInt16("apbar4", 0);
		msg->AddInt16("apbar5", 0);
		msg->AddInt16("apbar6", 0);
		be_app->PostMessage(msg);
		delete (msg);
		snooze(30000);
		}
	be_app->PostMessage(FXR_DONE,be_app);
	}

if (messno == 1) // Tell APP menu selected
	{
	BMessage *msg = new BMessage(SAM_GOMENU);
	msg->AddInt32("samlisttype", 22);
	msg->AddInt32("samlistnumber", samlistnumber);
	be_app->PostMessage(msg);
	delete msg;
	}

if (messno == 2) // Tell APP Done only
	{
	be_app->PostMessage(FXR_DONE,be_app);
	}
}


//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

int SAMPLEWindow::ProduceNextBuffer(void *buffer, int numSamps)
{
	int16 *bufferPtr = (int16 *)buffer;
	
	for (int loop = 0; loop < numSamps && currentSample <= sampleLength; loop++)
		{
		*bufferPtr++ = *samplePtrL++;
		*bufferPtr++ = *samplePtrR++;
		currentSample++;
		}
		
	if (currentSample >= sampleLength)
		{
//		AudioStop();
		playing = 0;
		}
		
	if (currentSample >= checksamplelength)
		{
//		AudioStop();
		playing = 0;
		}
		
	return numSamps;
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// SampleView

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

SampleView::SampleView(BRect R)
	: BView(R, "Sample", B_FOLLOW_ALL, B_WILL_DRAW)
{
SetHighColor(255,255,255);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SampleView::MessageReceived(BMessage* msg)
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

void SampleView::MouseDown(BPoint point)
{
uint32 buttons=0;

int32 origpos;
int32 drawpos;
int32 oldpos;
int32 halfheight;
int32 drawwidth;

drawwidth = (int32) Xlim;

GetMouse(&point, &buttons, true);

if(buttons == B_PRIMARY_MOUSE_BUTTON)
	{
	// Set Range to zero

	oldpos = (int32)point.x;
	origpos = oldpos;

	sampleview->SetDrawingMode(B_OP_INVERT);	// Remove existing range
	FillRect(BRect(drawrngstrt,drawrngtop,drawrngend,drawrngbottom));

	SetDrawingMode(B_OP_COPY);		// Redraw Zone display
	SetHighColor(255,0,0);
	if ((drawzoneside == 0) && (drawchans == 0))
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	if ((drawzoneside == 1) && (drawchans == 1))
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	if (drawchans == 2)
		{
		halfheight = drawrngbottom >> 1;
		if (drawzoneside == 0)
			{
			StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,halfheight),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,halfheight),B_SOLID_HIGH);
			}
		if (drawzoneside == 1)
			{
			StrokeLine(BPoint(drawzonestrt,halfheight),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,halfheight),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
			}
		if (drawzoneside == 2)
			{
			StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
			}
		}
	if (drawchans == 3)
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	SetHighColor(255,255,255);

	sampleview->SetDrawingMode(B_OP_INVERT);
	while(1)	// loop until button no longer held down 
		{
		GetMouse(&point, &buttons, true);
		if(buttons != B_PRIMARY_MOUSE_BUTTON) break;

		drawpos = (int32)point.x;
		if (drawpos > drawwidth) drawpos = drawwidth;
		if (drawpos <= 0) drawpos = 0;
		if (drawpos != oldpos)
			{
			if (drawpos > oldpos)
				{
				FillRect(BRect(oldpos+1,drawrngtop,drawpos,drawrngbottom));
				}
			else 
				{
				FillRect(BRect(drawpos+1,drawrngtop,oldpos,drawrngbottom));
				}
			oldpos=drawpos;

			// Tell app about new range
			if (origpos > drawpos)
				{
				rngend = origpos;
				rngstart = drawpos;
				}
			else 
				{
				rngend = drawpos;
				rngstart = origpos;
				}
			if (rngstart <0) rngstart = 0;
			if (rngend <0) rngend = 0;
			rnglen=rngend-rngstart;

			if ((drawchans==0) || (drawchans==2))
				{
				rnglenval=rnglen*scurjump;
				rngstrval=rngstart*scurjump;
				rngstrval=rngstrval+viewstart;
				rngval=drawpos*scurjump;
				rngval=rngval+viewstart;
				}
			if (drawchans==1)
				{
				rnglenval=rnglen*scurjump;
				rngstrval=rngstart*scurjump;
				rngstrval=rngstrval+viewstart+drawhalfmemsize;
				rngval=drawpos*scurjump;
				rngval=rngval+viewstart+drawhalfmemsize;
				}
			if (drawchans==3)
				{
				rnglenval=rnglen*curjump;
				rngstrval=rngstart*curjump;
				rngstrval=rngstrval+viewstart;
				rngval=drawpos*curjump;
				rngval=rngval+viewstart;
				}
			if (rngval < 0) rngval = 0;
			BMessage *msg = new BMessage(SAM_RNGVALS);
			msg->AddInt32("samrng1", rngval);
//			msg->AddInt32("samrng1", maxlen);
			msg->AddInt32("samrng2", rnglenval);
			msg->AddInt32("samrngsel", -10);
			msg->AddInt32("makechans", -10);
			msg->AddInt32("samstart", rngstrval);
			be_app->PostMessage(msg,be_app);
			delete (msg);
			}
		snooze(20000); // sleep for this many usecs between mouse reads
		}

	if (origpos > drawpos)
		{
		drawrngstrt = drawpos+1;
		drawrngend = origpos;
		rngend = origpos;
		rngstart = drawpos;
		}
	else
		{
		drawrngstrt = origpos+1;
		drawrngend = drawpos;
		rngend = drawpos;
		rngstart = origpos;
		}
	if (origpos == oldpos)
		{
		drawrngend++;
		FillRect(BRect(drawrngstrt,drawrngtop,drawrngend,drawrngbottom));
		}

	if (rngstart <0) rngstart = 0;
	if (rngend <0) rngend = 0;
	rnglen=rngend-rngstart;

	if ((drawchans==0) || (drawchans==2))
		{
		rnglenval=rnglen*scurjump;
		rngstrval=rngstart*scurjump;
		rngstrval=rngstrval+viewstart;
		rngval=drawpos*scurjump;
		rngval=rngval+viewstart;
		}
	if (drawchans==1)
		{
		rnglenval=rnglen*scurjump;
		rngstrval=rngstart*scurjump;
		rngstrval=rngstrval+viewstart+drawhalfmemsize;
		rngval=drawpos*scurjump;
		rngval=rngval+viewstart+drawhalfmemsize;
		}
	if (drawchans==3)
		{
		rnglenval=rnglen*curjump;
		rngstrval=rngstart*curjump;
		rngstrval=rngstrval+viewstart;
		rngval=drawpos*curjump;
		rngval=rngval+viewstart;
		}
	if (rngval < 0) rngval = 0;
	
	SetDrawingMode(B_OP_COPY);		// Redraw Zone display
	SetHighColor(255,0,0);
	if ((drawzoneside == 0) && (drawchans == 0))
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	if ((drawzoneside == 1) && (drawchans == 1))
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	if (drawchans == 2)
		{
		halfheight = drawrngbottom >> 1;
		if (drawzoneside == 0)
			{
			StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,halfheight),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,halfheight),B_SOLID_HIGH);
			}
		if (drawzoneside == 1)
			{
			StrokeLine(BPoint(drawzonestrt,halfheight),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,halfheight),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
			}
		if (drawzoneside == 2)
			{
			StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
			}
		}
	if (drawchans == 3)
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	SetHighColor(255,255,255);

	BMessage *msg = new BMessage(SAM_RNGVALS);
	msg->AddInt32("samrng1", rngval);
	msg->AddInt32("samrng2", rnglenval);
	msg->AddInt32("samrngsel", -10);
	msg->AddInt32("makechans", -10);
	msg->AddInt32("samstart", rngstrval);
	be_app->PostMessage(msg,be_app);
	delete (msg);

	BMessage *mesg = new BMessage(APP_DRAWATTRACT);
	mesg->AddInt32("rng", rngstrval);
	mesg->AddInt32("updateattract", 1);
	be_app->PostMessage(mesg,be_app);
	delete (mesg);
	}
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SampleView::Draw(BRect updateRect)
{
int32 Count=0;
int32 halfheight;

SetDrawingMode(B_OP_COPY);
FillRect(BRect(0,1,viewwidth,viewheight),B_SOLID_LOW);	// fill background Black

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

SetDrawingMode(B_OP_INVERT);	// Range Display
FillRect(BRect(drawrngstrt,drawrngtop,drawrngend,drawrngbottom));

	SetDrawingMode(B_OP_COPY);		// Redraw Zone display
	SetHighColor(255,0,0);
	if ((drawzoneside == 0) && (drawchans == 0))
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	if ((drawzoneside == 1) && (drawchans == 1))
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	if (drawchans == 2)
		{
		halfheight = drawrngbottom >> 1;
		if (drawzoneside == 0)
			{
			StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,halfheight),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,halfheight),B_SOLID_HIGH);
			}
		if (drawzoneside == 1)
			{
			StrokeLine(BPoint(drawzonestrt,halfheight),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,halfheight),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
			}
		if (drawzoneside == 2)
			{
			StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
			StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
			}
		}
	if (drawchans == 3)
		{
		StrokeLine(BPoint(drawzonestrt,1),BPoint(drawzonestrt,drawrngbottom),B_SOLID_HIGH);
		StrokeLine(BPoint(drawzoneend,1),BPoint(drawzoneend,drawrngbottom),B_SOLID_HIGH);
		}
	SetHighColor(255,255,255);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SampleView::Tellviewmax(int32 max)
{
maxlen = max;
}


//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

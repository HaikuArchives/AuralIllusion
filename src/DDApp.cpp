// DDApp.cpp
// Copyright (c) Blachford Technology 1999
// 28/4/99

#include <Alert.h>
#include "DDApp.h"
#include "FilePanel.h"
#include <File.h>
#include <Path.h>
#include <Entry.h>
#include <String.h>
#include <Screen.h>

#include <stdio.h>
#include <stdlib.h>

#include "MsgVals.h"

int32 apchanmode; // channel mode 
// 1=Left  2=Right  3=Stereo  4=Mono

int32 aplistnumber; // these are reused for various purposes
int32 aplisttype;
int32 apfxnumber;
int32 apfxtype;

int16 apslider1;
int16 apslider2;
int16 apslider3;
int16 apslider4;
int16 apslider;
int16 apradio1;
int16 apradio2;

int32 apcusr;
int32 aprange;
int32 apzone;
int32 aprng1;
int32 aprng2;
int32 aprngsel;

int32 apmessno;

int16 *appoint;				// Sample Pointer
uint32 apfullmemsize;		// FULL memory allocated, for sample and undo
uint32 apmemsize;			// size of sample block, half of fullmemsize
uint32 aphalfmemsize;		// Half of above

uint32 apsamstart;			// Start here
uint32 apsamend;			// End Here
uint32 apsamlen;			// Length
int32 iapsamstart;			// These two used to transfer the above
int32 iapsamend;
int32 attrngstr;
int32 tempzone;
int32 tempchanmode;

int16 tmp0;
int16 tmp1;
int16 tmp2;
int16 tmp3;
int16 tmp4;
int16 tmp5;
int16 tmp6;
int16 tmp7;
int16 tmp8;
int16 tmp9;
int16 tmp10;
int16 tmp11;
int16 tmp12;
int16 tmp13;
int16 tmp14;
int16 tmp15;
int16 tmp16;
int16 tmp17;
int16 tmp18;
int16 tmp19;
int16 tmp20;
int16 apiewmsgtyp;

int16 apiewtyp;	// individual effect window type; 
// 0 = EQ7
// 1 = EQ20

uint32 apsamcount;	// counter

area_id my_area; // memory area allocated

//entry_ref* app_aref;
//const char ** app_filename = new (const char *)[1];
//BString mystring;

//-----------------------
// window vars

int32 attractwin;
int32 loadwin;
int32 eq7win;
int32 eq20win;

// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************
//	Constructor
DDApp::DDApp()
	: BApplication("application/x-vnd.BT-AiJ")
{
memorywindow = new MEMORY();  // Select memory first
memorywindow->SetFlags(B_NOT_RESIZABLE | B_NOT_ZOOMABLE | B_NOT_CLOSABLE);

}

// ***************************************************************************************************

DDApp::~DDApp(void) // Destructor
{
delete_area(my_area);	// delete the area:
}
	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void DDApp::Setupmemory(int32 apmemmemsize)	// REM back in for DEMO version
{

// TEST default to 8MB
//	apfullmemsize = B_PAGE_SIZE*2000; // 8MB
apfullmemsize = (uint32)apmemmemsize;

/*area_id create_area(const char *name, 
      void **addr, 
      uint32 addr_spec, 
      uint32 size, 
      uint32 lock, 
      uint32 protection)*/

// Create an area.
my_area = create_area("my area",	// name you give to the area
	(void **)&appoint,				// returns the starting addr
	B_ANY_ADDRESS,					// area can start anywhere
	apfullmemsize,					// size in bytes
	B_NO_LOCK,						// Lock in RAM? No  - B_FULL_LOCK = Yes
	B_READ_AREA | B_WRITE_AREA);	// permissions

// check for errors
if (my_area < 0)	// Didn't work, tell memory window
	{
	memorywindow->PostMessage(MEM_NOT,memorywindow);
	}
else	// OK it worked
	{
	apmemsize=apfullmemsize-32;
	apmemsize=apmemsize >> 2;		// Converts this to a value in 16 bit Samples
	aphalfmemsize=apmemsize >> 1;

	memorywindow->Lock();
	memorywindow->Quit();

	samplewindow = new SAMPLEWindow();  //	Sample view Window

	allfxwindow = new ALLFX();
	allfxwindow->SetFlags(B_NOT_RESIZABLE | B_NOT_ZOOMABLE | B_NOT_CLOSABLE);

	editwindow = new EDIT();
	editwindow->SetFlags(B_NOT_RESIZABLE | B_NOT_ZOOMABLE | B_NOT_CLOSABLE);

	snooze(10000);	// wait for that lot to complete
/*
	BScreen screen;	// USE THIS TO SET WINDOW SIZES AND POSITIONS
	BRect r = screen.Frame();
	float wid = r.Width()-12;
	SetSizeLimits(min_wid, wid, min_hei, r.Height()-24);

	//	Don't zoom to cover all of screen; user can resize last bit if necessary.
	//	This leaves other windows visible.
	if (wid > 640) 
		{
		wid = 640 + (wid-640)/2;
		}
	SetZoomLimits(wid, r.Height()-24);
*/
	allfxwindow->Activate(1);
	editwindow->Activate(1);

	attractwin=0;
	loadwin=0;
	eq7win = 0;
	eq20win = 0;

	// When memory is set up initilize sample window. 
	BMessage *msg = new BMessage(APP_MEMSETUP);	
	msg->AddPointer("appoint", appoint);
	msg->AddInt32("apmemsize", apmemsize); // uint32 or int32
	msg->AddInt32("aphalfmemsize", aphalfmemsize);
	samplewindow->PostMessage(msg,samplewindow);
	delete (msg);
	}
}
	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void DDApp::Domenuops(void)	// Perform operations selected by menu
{
bool hide;

if (aplisttype == 22)	// this IS a menu op? 
	{
	sendmessage(5);
	
	if (aplistnumber == 0)	//  Zero all memory
		{
		sendmessage(3);
		}

	if (aplistnumber == 1)	//	Load
		{
		if (loadwin == 0)
			{
			loadwindow = new LOAD();
			loadwindow->SetFlags(B_NOT_RESIZABLE | B_NOT_ZOOMABLE | B_NOT_CLOSABLE);
			loadwin = 1;
			}
		else if (loadwin >= 1)
			{
			loadwindow->Lock();
			hide=loadwindow->IsHidden();
			if (hide)	loadwindow->Show();
			loadwindow->Activate();
			loadwindow->Unlock();
			}
		BMessage *msg = new BMessage(APP_LOAD);	// set to LOAD
		msg->AddInt32("loadorsave", 0);		//	0=load	1=save
		loadwindow->PostMessage(msg,loadwindow);
		delete (msg);
		loadwin = 1;			// End Here
		}

	if (aplistnumber == 2)
		{
		
		}

	if (aplistnumber == 3)	//  Save As
		{
		if (loadwin == 0)
			{
			loadwindow = new LOAD();
			loadwindow->SetFlags(B_NOT_RESIZABLE | B_NOT_ZOOMABLE | B_NOT_CLOSABLE);
			loadwin = 2;
			}
		else if (loadwin >= 1)
			{
			loadwindow->Lock();
			hide=loadwindow->IsHidden();
			if (hide)	loadwindow->Show();
			loadwindow->Activate();
			loadwindow->Unlock();
			}
		BMessage *msg = new BMessage(APP_SAVE);	// set to SAVE AS
		msg->AddInt32("loadorsave", 1);		//	0=load	1=save
		loadwindow->PostMessage(msg,loadwindow);
		delete (msg);
		loadwin = 2;
		}
	if (aplistnumber == 4)	//  Temp 1
		{
		Notaboutrequested();
		sendmessage(0);
		}
	if (aplistnumber == 5)	//  Temp 2
		{
		Notaboutrequested();
		sendmessage(0);
		}
	if (aplistnumber == 6)	//  Temp 3
		{
		Notaboutrequested();
		sendmessage(0);
		}
	if (aplistnumber == 7)	//  Open Attractor Window
		{
		if (attractwin == 0)
			{
			attractorwindow = new ATTRACT();
			snooze(20000);
			attractwin=1;
			sendmessage(8);
			}
//		Notaboutrequested();
		sendmessage(0);
		}
	if (aplistnumber == 8)	//  Temp 5
		{
		Notaboutrequested();
		sendmessage(0);
		}
	}
}

// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void DDApp::MessageReceived(BMessage* msg)
{
int32 attup;
int32 apmemmemsize;
int32 listtemp;

//	msg->PrintToStream();
//	BApplication::MessageReceived(msg);

	switch(msg->what)
	{
		
	case MEM_FETCH: // Memory window is asking to allocate this much RAM
		msg->FindInt32("memmemsize", &apmemmemsize);
		Setupmemory(apmemmemsize);
		break;

	 case SAM_QUIT:
		OpenQuitWindow();
		break;

	case FXR_DONE:	// Operation complete
		sendmessage(0);
		sendmessage(8);
		break;

	case SAM_RNGVALS:	// Update main values
		msg->FindInt32("samrng1", &apcusr);
		msg->FindInt32("samrng2", &aprange);
		msg->FindInt32("samrngsel", &apzone);
		msg->FindInt32("makechans", &tempchanmode);
		msg->FindInt32("samstart", &iapsamstart);
		apsamstart=iapsamstart;
		if (tempzone != -10) apzone=tempzone;
		if (tempchanmode != -10) apchanmode=tempchanmode;
		apsamlen=aprange;
		apsamend=apsamstart+apsamlen;
		sendmessage(7);	// Now send to EDIT
		break;
		
	case SAM_GOMENU: // Menu selected
		msg->FindInt32("samlisttype", &aplisttype);
		msg->FindInt32("samlistnumber", &aplistnumber);
		Domenuops();
		break;

	case FXR_DRAWBAR:	// Update Drawbar on Edit Window
		msg->FindInt16("apbar1", &apslider1);
		msg->FindInt16("apbar2", &apslider2);
		msg->FindInt16("apbar3", &apslider3);
		msg->FindInt16("apbar4", &apslider4);
		msg->FindInt16("apbar5", &apslider);
		msg->FindInt16("apbar6", &apradio1);
		sendmessage(6);
		break;

	case APP_DRAWATTRACT:	// Draw Attractor
		msg->FindInt32("rng", &attrngstr);
		msg->FindInt32("updateattract", &attup);
		if (attup == 1)	sendmessage(8);
		break;

	case ATT_CLOSED:	// Attractor is closed
		attractwin=0;
		break;

	case ALLFX_SETTINGS:	// ALLFX SETTINGS
		msg->FindInt32("listtype", &aplisttype);
		msg->FindInt32("listnumber", &aplistnumber);
		msg->FindInt32("fxtype", &apfxtype);
		msg->FindInt32("fxnumber", &apfxnumber);
		msg->FindInt16("slider1", &apslider1);
		msg->FindInt16("slider2", &apslider2);
		msg->FindInt16("slider3", &apslider3);
		msg->FindInt16("slider4", &apslider4);
		msg->FindInt16("slider", &apslider);
		msg->FindInt16("radio1", &apradio1);
		msg->FindInt16("radio2", &apradio2);
		sendmessage(2);
		break;

	case ALLFX_FXCURRENT:	// New Current Effect
		msg->FindInt32("listtype", &aplisttype);
		msg->FindInt32("listnumber", &aplistnumber);
		if ((aplisttype == 1) && (aplistnumber <= 1))
			{
			if (aplistnumber == 0)	// open EQ7
				{
				if (eq7win == 0)
					{
					eq7window = new EQ7();  // 7 Band EQ
					eq7win = 1;
					}
				apiewmsgtyp = 3;	// request settings from allfx
				apiewtyp = 0;
				} 
			if (aplistnumber == 1) // open EQ20
				{
				if (eq20win == 0)
					{
					eq20window = new EQ20();  // 7 Band EQ
					eq20win = 1;
					}
				apiewmsgtyp = 3;	// request settings from allfx
				apiewtyp = 1;
				}
			BMessage *msg = new BMessage(IAP_REQSET);	// request settings for window
			msg->AddInt16("iewtyp", apiewtyp);
			allfxwindow->PostMessage(msg,allfxwindow);
			delete (msg);
			}
		sendmessage(1);
		break;

	case ALLFX_FXGO:	// ALLFX 'GO' is pressed...
		msg->FindInt32("listtype", &aplisttype);
		msg->FindInt32("listnumber", &aplistnumber);
		if ((aplisttype == 1) && (aplistnumber <= 1))
			{
			if (aplistnumber == 0)	// EQ7
				{
				apiewmsgtyp = 3;	// request settings from allfx
				apiewtyp = 0;
				} 
			if (aplistnumber == 1) // EQ20
				{
				apiewmsgtyp = 3;	// request settings from allfx
				apiewtyp = 1;
				}
			BMessage *msg = new BMessage(IAPGO_REQSET);	// Go pressed request settings for effector
			msg->AddInt16("iewtyp", apiewtyp);
			allfxwindow->PostMessage(msg,allfxwindow);
			delete (msg);
			sendmessage(4);
			}
		else
			{
			sendmessage(4);
			sendmessage(3);
			}
		break;

	case EDIT_EDITGO:	// EDIT GO pressed
		msg->FindInt32("edlisttype", &aplisttype);
		msg->FindInt32("edlistnumber", &aplistnumber);
		msg->FindInt16("edvalue", &apslider1);
		if ((aplisttype == 1) && (aplistnumber <= 1))
			{
			if (aplistnumber == 0)	// EQ7
				{
				apiewmsgtyp = 3;	// request settings from allfx
				apiewtyp = 0;
				} 
			if (aplistnumber == 1) // EQ20
				{
				apiewmsgtyp = 3;	// request settings from allfx
				apiewtyp = 1;
				}
			BMessage *msg = new BMessage(IAPGO_REQSET);	// Go pressed request settings for effector
			msg->AddInt16("iewtyp", apiewtyp);
			allfxwindow->PostMessage(msg,allfxwindow);
			delete (msg);
			//sendmessage(4);
			}
		else
			{
			sendmessage(3);	// Get Settings
			//sendmessage(4);
			}
		break;

	case LOAD_REQUESTDATA:	// Send data to LOAD
		sendmessage(9);
		break;

	case IW_CLOSED:	// IEW closed
		msg->FindInt16("iewtyp", &apiewtyp);
		if (apiewtyp == 0) eq7win = 0;
		if (apiewtyp == 1) eq20win = 0;
		apiewtyp = 100;
		break;

	case IW_NEWVAL:	// New Val in Individual Effects window
		msg->FindInt32("listtype", &aplisttype);
		msg->FindInt32("listnumber", &aplistnumber);
		msg->FindInt32("fxtype", &apfxtype);
		msg->FindInt32("fxnumber", &apfxnumber);
		msg->FindInt16("iewmsgtyp", &apiewmsgtyp);
		msg->FindInt16("iewtyp", &apiewtyp);
		msg->FindInt16("eq0lev", &tmp0);
		msg->FindInt16("eq1lev", &tmp1);
		msg->FindInt16("eq2lev", &tmp2);
		msg->FindInt16("eq3lev", &tmp3);
		msg->FindInt16("eq4lev", &tmp4);
		msg->FindInt16("eq5lev", &tmp5);
		msg->FindInt16("eq6lev", &tmp6);
		msg->FindInt16("eq7lev", &tmp7);
		msg->FindInt16("eq8lev", &tmp8);
		msg->FindInt16("eq9lev", &tmp9);
		msg->FindInt16("eq10lev", &tmp10);
		msg->FindInt16("eq11lev", &tmp11);
		msg->FindInt16("eq12lev", &tmp12);
		msg->FindInt16("eq13lev", &tmp13);
		msg->FindInt16("eq14lev", &tmp14);
		msg->FindInt16("eq15lev", &tmp15);
		msg->FindInt16("eq16lev", &tmp16);
		msg->FindInt16("eq17lev", &tmp17);
		msg->FindInt16("eq18lev", &tmp18);
		msg->FindInt16("eq19lev", &tmp19);
		msg->FindInt16("eq20lev", &tmp20);
		sendmessage(10);
		//sendmessage(1);	// tell edit new current effect
		break;

	case IAL_SET:	// Settings for Individual Effects Window
		msg->FindInt32("listtype", &aplisttype);
		msg->FindInt32("listnumber", &aplistnumber);
		msg->FindInt32("fxtype", &apfxtype);
		msg->FindInt32("fxnumber", &apfxnumber);
		msg->FindInt16("iewmsgtyp", &apiewmsgtyp);
		msg->FindInt16("iewtyp", &apiewtyp);
		msg->FindInt16("eq0lev", &tmp0);
		msg->FindInt16("eq1lev", &tmp1);
		msg->FindInt16("eq2lev", &tmp2);
		msg->FindInt16("eq3lev", &tmp3);
		msg->FindInt16("eq4lev", &tmp4);
		msg->FindInt16("eq5lev", &tmp5);
		msg->FindInt16("eq6lev", &tmp6);
		msg->FindInt16("eq7lev", &tmp7);
		msg->FindInt16("eq8lev", &tmp8);
		msg->FindInt16("eq9lev", &tmp9);
		msg->FindInt16("eq10lev", &tmp10);
		msg->FindInt16("eq11lev", &tmp11);
		msg->FindInt16("eq12lev", &tmp12);
		msg->FindInt16("eq13lev", &tmp13);
		msg->FindInt16("eq14lev", &tmp14);
		msg->FindInt16("eq15lev", &tmp15);
		msg->FindInt16("eq16lev", &tmp16);
		msg->FindInt16("eq17lev", &tmp17);
		msg->FindInt16("eq18lev", &tmp18);
		msg->FindInt16("eq19lev", &tmp19);
		msg->FindInt16("eq20lev", &tmp20);
		sendmessage(11);
		break;

	case IALGO_SET:	// GO pressed Settings for Individual Effects Window
		msg->FindInt32("listtype", &aplisttype);
		msg->FindInt32("listnumber", &aplistnumber);
		msg->FindInt32("fxtype", &apfxtype);
		msg->FindInt32("fxnumber", &apfxnumber);
		msg->FindInt16("iewmsgtyp", &apiewmsgtyp);
		msg->FindInt16("iewtyp", &apiewtyp);
		msg->FindInt16("eq0lev", &tmp0);
		msg->FindInt16("eq1lev", &tmp1);
		msg->FindInt16("eq2lev", &tmp2);
		msg->FindInt16("eq3lev", &tmp3);
		msg->FindInt16("eq4lev", &tmp4);
		msg->FindInt16("eq5lev", &tmp5);
		msg->FindInt16("eq6lev", &tmp6);
		msg->FindInt16("eq7lev", &tmp7);
		msg->FindInt16("eq8lev", &tmp8);
		msg->FindInt16("eq9lev", &tmp9);
		msg->FindInt16("eq10lev", &tmp10);
		msg->FindInt16("eq11lev", &tmp11);
		msg->FindInt16("eq12lev", &tmp12);
		msg->FindInt16("eq13lev", &tmp13);
		msg->FindInt16("eq14lev", &tmp14);
		msg->FindInt16("eq15lev", &tmp15);
		msg->FindInt16("eq16lev", &tmp16);
		msg->FindInt16("eq17lev", &tmp17);
		msg->FindInt16("eq18lev", &tmp18);
		msg->FindInt16("eq19lev", &tmp19);
		msg->FindInt16("eq20lev", &tmp20);
		sendmessage(12);
		break;

	 default:
	 	BApplication::MessageReceived(msg);
	 	break;
	}
}
	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void DDApp::sendmessage(int32 apmessno)
{
if (apmessno == 0) // Operation Complete
	{
	editwindow->PostMessage(APP_DONE,editwindow);
	}

if (apmessno == 1) // new current effect - tell editwindow
	{
	BMessage *msg = new BMessage(APP_CURRENT); // Tell EDIT which effect selected
	msg->AddInt32("aplisttype", aplisttype);
	msg->AddInt32("aplistnumber", aplistnumber);
	editwindow->PostMessage(msg,editwindow);
	delete msg;
	}
	
if (apmessno == 2) // GO on ALLFX, new current effect
	{
	//	send slider vals and mapped FX numbers to Effector 
	BMessage *msg = new BMessage(APP_SETTINGS);
	msg->AddInt32("apfxtype", apfxtype);
	msg->AddInt32("apfxnumber", apfxnumber);
	msg->AddInt16("apslider1", apslider1);
	msg->AddInt16("apslider2", apslider2);
	msg->AddInt16("apslider3", apslider3);
	msg->AddInt16("apslider4", apslider4);
	msg->AddInt16("apslider", apslider);
	msg->AddInt16("apradio1", apradio1);
	msg->AddInt16("apradio2", apradio2);
	samplewindow->PostMessage(msg,samplewindow);
	delete (msg);
	}

if (apmessno == 3)
	{
	if (aplisttype < 20) // If Effect ask ALLFX for FX settings
		{
		allfxwindow->PostMessage(APP_GETSETTINGS,allfxwindow);	// request settings
		}
	else	// not effect
		{
		if (((aplistnumber >= 1) && (aplistnumber <= 3)) && (aplisttype == 22))	// Load & Save
			{
			Domenuops();
			}
		else
			{
			if (aplistnumber == 33) // is it a mono/stereo setting
				{
				apchanmode=aplistnumber;
				if (apslider1 == 3) // Mono
					{
					allfxwindow->PostMessage(APP_MONO,allfxwindow);
					}
				else	// not Mono
					{
					allfxwindow->PostMessage(APP_STEREO,allfxwindow);
					}
				}
			BMessage *msg = new BMessage(APP_SETTINGS);
			msg->AddInt32("apfxtype", aplisttype); // > 20 don't need MAPPER
			msg->AddInt32("apfxnumber", aplistnumber);
			msg->AddInt16("apslider1", apslider1);
			msg->AddInt16("apslider2", 0);
			msg->AddInt16("apslider3", 0);
			msg->AddInt16("apslider4", 0);
			msg->AddInt16("apslider", 256);	// just in case used in the future
			msg->AddInt16("apradio1", 0);
			msg->AddInt16("apradio2", 0);
			samplewindow->PostMessage(msg,samplewindow);
			delete (msg);
			}
		}
	}

if (apmessno == 4) // Tell EDIT about ALLFX GO, which effect started
	{
	BMessage *msg = new BMessage(APP_FXGO);
	msg->AddInt32("aplisttype", aplisttype);
	msg->AddInt32("aplistnumber", aplistnumber);
	editwindow->PostMessage(msg,editwindow);
	delete msg;
	}

if (apmessno == 5) // Tell EDIT a menu has been selected
	{
	if (aplistnumber == 0)
		{
		BMessage *msg = new BMessage(APP_FXGONONEW); // no change to current effect
		msg->AddInt32("aplisttype", aplisttype);
		msg->AddInt32("aplistnumber", aplistnumber);
		editwindow->PostMessage(msg,editwindow);
		delete msg;
		}
	else
		{
		BMessage *msg = new BMessage(APP_FXGO);
		msg->AddInt32("aplisttype", aplisttype);
		msg->AddInt32("aplistnumber", aplistnumber);
		editwindow->PostMessage(msg,editwindow);
		delete msg;
		}
	}

if (apmessno == 6) // Update Drawbar on EDIT
	{
	BMessage *msg = new BMessage(APP_DRAWBAR);
	msg->AddInt16("apbar1", apslider1);
	msg->AddInt16("apbar2", apslider2);
	msg->AddInt16("apbar3", apslider3);
	msg->AddInt16("apbar4", apslider4);
	msg->AddInt16("apbar5", apslider);
	msg->AddInt16("apbar6", apradio1);
	editwindow->PostMessage(msg,editwindow);
	delete (msg);
	}

if (apmessno == 7) // Send new display vals to EDIT
	{
	BMessage *msg = new BMessage(SAM_RNGVALS);
	msg->AddInt32("apcusr", apcusr);
	msg->AddInt32("aprange", aprange);
	msg->AddInt32("apzone", apzone);
	editwindow->PostMessage(msg,editwindow);
	delete (msg);
	}

if (apmessno == 8) // Draw Attractor
	{
	if (attractwin == 1)
		{
		BMessage *msg = new BMessage(APP_DRAWATTRACT);
		msg->AddPointer("appoint", appoint);
		msg->AddInt32("aphalfmemsize", aphalfmemsize);
		msg->AddInt32("aprngstrval", attrngstr);
		msg->AddInt32("aprnglenval", aprange);
		msg->AddInt32("apmakechans", apchanmode);
		attractorwindow->PostMessage(msg,attractorwindow);
		delete (msg);
		}
	}

if (apmessno == 9) // Send Load/Save Data
	{
	BMessage *msg = new BMessage(APP_LOADDATA);	// set to SAVE AS
	msg->AddPointer("appoint", appoint);
	msg->AddInt32("chanmode", apchanmode);
	msg->AddInt32("halfmemsize", aphalfmemsize);
	msg->AddInt32("samstart", apsamstart);
	msg->AddInt32("samend", apsamend);
	msg->AddInt32("samlen", apsamlen);
	loadwindow->PostMessage(msg,loadwindow);
	delete (msg);
	}

if (apmessno == 10) // Send Individual Effects Windows Data
	{
	if (apiewtyp == 0)	//	0=EQ7
		{
		BMessage *msg = new BMessage(IAP_NEWVAL);
		msg->AddInt32("listtype", aplisttype);
		msg->AddInt32("listnumber", aplistnumber);
		msg->AddInt32("fxtype", apfxtype);
		msg->AddInt32("fxnumber", apfxnumber);
		msg->AddInt16("eqmsgtyp", apiewmsgtyp);
		msg->AddInt16("eqtyp", apiewtyp);
		eq7window->PostMessage(msg,eq7window);
		delete (msg);
		}

	if (apiewtyp == 1)	//	1=EQ20
		{
		BMessage *msg = new BMessage(IAP_NEWVAL);
		msg->AddInt32("listtype", aplisttype);
		msg->AddInt32("listnumber", aplistnumber);
		msg->AddInt32("fxtype", apfxtype);
		msg->AddInt32("fxnumber", apfxnumber);
		msg->AddInt16("eqmsgtyp", apiewmsgtyp);
		msg->AddInt16("eqtyp", apiewtyp);
		eq20window->PostMessage(msg,eq20window);
		delete (msg);
		}	

	BMessage *msg = new BMessage(APP_CURRENT); // Tell EDIT new current effect
	msg->AddInt32("aplisttype", aplisttype);
	msg->AddInt32("aplistnumber", aplistnumber);
	editwindow->PostMessage(msg,editwindow);
	delete (msg);
	
	if (apiewmsgtyp == 0)	// update ALLFX window with setting change
		{
		BMessage *msg = new BMessage(IAP_NEWVAL);
		msg->AddInt32("listtype", aplisttype);
		msg->AddInt32("listnumber", aplistnumber);
		msg->AddInt32("fxtype", apfxtype);
		msg->AddInt32("fxnumber", apfxnumber);
		msg->AddInt16("eqmsgtyp", 0);
		msg->AddInt16("iewtyp", apiewtyp);	//	0=EQ7 1=EQ20
		msg->AddInt16("eq0lev", tmp0);
		msg->AddInt16("eq1lev", tmp1);
		msg->AddInt16("eq2lev", tmp2);
		msg->AddInt16("eq3lev", tmp3);
		msg->AddInt16("eq4lev", tmp4);
		msg->AddInt16("eq5lev", tmp5);
		msg->AddInt16("eq6lev", tmp6);
		msg->AddInt16("eq7lev", tmp7);
		msg->AddInt16("eq8lev", tmp8);
		msg->AddInt16("eq9lev", tmp9);
		msg->AddInt16("eq10lev", tmp10);
		msg->AddInt16("eq11lev", tmp11);
		msg->AddInt16("eq12lev", tmp12);
		msg->AddInt16("eq13lev", tmp13);
		msg->AddInt16("eq14lev", tmp14);
		msg->AddInt16("eq15lev", tmp15);
		msg->AddInt16("eq16lev", tmp16);
		msg->AddInt16("eq17lev", tmp17);
		msg->AddInt16("eq18lev", tmp18);
		msg->AddInt16("eq19lev", tmp19);
		msg->AddInt16("eq20lev", tmp20);
		allfxwindow->PostMessage(msg,allfxwindow);
		delete (msg);
		}
	}

if (apmessno == 11) // Send Individual Effects Windows settings
	{
	BMessage *msg = new BMessage(IAP_SET);
	msg->AddInt32("listtype", aplisttype);
	msg->AddInt32("listnumber", aplistnumber);
	msg->AddInt32("fxtype", apfxtype);
	msg->AddInt32("fxnumber", apfxnumber);
	msg->AddInt16("eqmsgtyp", 0);
	msg->AddInt16("iewtyp", apiewtyp);	//	0=EQ7 1=EQ20
	msg->AddInt16("eq0lev", tmp0);
	msg->AddInt16("eq1lev", tmp1);
	msg->AddInt16("eq2lev", tmp2);
	msg->AddInt16("eq3lev", tmp3);
	msg->AddInt16("eq4lev", tmp4);
	msg->AddInt16("eq5lev", tmp5);
	msg->AddInt16("eq6lev", tmp6);
	msg->AddInt16("eq7lev", tmp7);
	msg->AddInt16("eq8lev", tmp8);
	msg->AddInt16("eq9lev", tmp9);
	msg->AddInt16("eq10lev", tmp10);
	msg->AddInt16("eq11lev", tmp11);
	msg->AddInt16("eq12lev", tmp12);
	msg->AddInt16("eq13lev", tmp13);
	msg->AddInt16("eq14lev", tmp14);
	msg->AddInt16("eq15lev", tmp15);
	msg->AddInt16("eq16lev", tmp16);
	msg->AddInt16("eq17lev", tmp17);
	msg->AddInt16("eq18lev", tmp18);
	msg->AddInt16("eq19lev", tmp19);
	msg->AddInt16("eq20lev", tmp20);
	if (apiewtyp == 0)	eq7window->PostMessage(msg,eq7window);	// EQ7
	if (apiewtyp == 1)	eq20window->PostMessage(msg,eq20window);	// EQ20
	delete (msg);
	}

if (apmessno == 12) // Send Individual Effects Windows settings
	{
	BMessage *msg = new BMessage(IAPGO_SET);
	msg->AddInt32("listtype", aplisttype);
	msg->AddInt32("listnumber", aplistnumber);
	msg->AddInt32("fxtype", apfxtype);
	msg->AddInt32("fxnumber", apfxnumber);
	msg->AddInt16("eqmsgtyp", 0);
	msg->AddInt16("iewtyp", apiewtyp);	//	0=EQ7 1=EQ20
	msg->AddInt16("eq0lev", tmp0);
	msg->AddInt16("eq1lev", tmp1);
	msg->AddInt16("eq2lev", tmp2);
	msg->AddInt16("eq3lev", tmp3);
	msg->AddInt16("eq4lev", tmp4);
	msg->AddInt16("eq5lev", tmp5);
	msg->AddInt16("eq6lev", tmp6);
	msg->AddInt16("eq7lev", tmp7);
	msg->AddInt16("eq8lev", tmp8);
	msg->AddInt16("eq9lev", tmp9);
	msg->AddInt16("eq10lev", tmp10);
	msg->AddInt16("eq11lev", tmp11);
	msg->AddInt16("eq12lev", tmp12);
	msg->AddInt16("eq13lev", tmp13);
	msg->AddInt16("eq14lev", tmp14);
	msg->AddInt16("eq15lev", tmp15);
	msg->AddInt16("eq16lev", tmp16);
	msg->AddInt16("eq17lev", tmp17);
	msg->AddInt16("eq18lev", tmp18);
	msg->AddInt16("eq19lev", tmp19);
	msg->AddInt16("eq20lev", tmp20);
	samplewindow->PostMessage(msg,samplewindow);
	delete (msg);
	}

}
	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void DDApp::Notaboutrequested(void)
{
	(new BAlert("Not About Aural illusion",
		"\nIf you notice this notice\n"
		"you will notice this notice\n"
		"is not worth noticing.\n",
		"Doh !"))->Go();
}
	
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void DDApp::AboutRequested(void)
{
	(new BAlert("About Aural illusion",
		"\nAural illusion v4.0\n\n"
		"Copyright (c) Blachford Technology 1996 - 2000\n\n"
		"Alpha 5  In-Completed 24/5/00\n"
		"By Nicholas Blachford",
		"Coolant"))->Go();
}

// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

void DDApp::OpenQuitWindow(void)
{
// be_app->PostMessage(B_QUIT_REQUESTED);
//
// REM the above in and below out for development

	int32 button_index = (new BAlert("Quit Aural illusion?",
		"Quit Aural illusion?\n\n"
		"Are you sure you want to quit?\n\n"
		"All unsaved data will be lost.\n\n",
		"Yes, Quit",
		"No, Don't"))->Go();

	if (button_index == 0)
		{
		be_app->PostMessage(B_QUIT_REQUESTED);
		}

	if (button_index == 1)	{}

}

// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************

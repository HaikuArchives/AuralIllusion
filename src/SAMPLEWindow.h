// SAMPLEWindow.h
// Copyright (c) Blachford Technology 1999
// 28/4/99

#include <Window.h>
#include <View.h>
#include <List.h>


// Predefinitions
class BStringView;
class BMenuItem;


class SAMPLEWindow : public BWindow
{
 public:
 	SAMPLEWindow();
	~SAMPLEWindow(void);

/*****************************************************************/
// Ai v4.0 Globals

int32 wavebuf[15][251];        //  bufs are for calculation
int32 wavetemp[1001];           //  so is wavetemp
int16 complexbuf[65538];

// Window numbers to check if they are open - probably have to be moved
// - some not necessary
//int32  sourcewin,filwin,saveswin,genwin, memwin,
//      quitwin,basicwin,outwin,loopwin,oscwin,wavewin,
//      envwin,rfiltwin,miscwin,ampwin,eq2win,recwin,

// Variable tables

int32 modtype[10];  // ???

int32 result; //  this will store the result of any input
int32 value;  //  so will this

// Other variables

//uint32 playing;   // sample playing = 1 WARNING! Check vars between class vars and globals in .cpp file

uint32 loopmode;  // loop on/off
int32 sourcevar[4]; // ???

int16 *sampoint;		// Sample Pointer
uint32 fullmemsize;		// FULL memory allocated, for sample and undo
uint32 memsize;			// size of sample block, half of fullmemsize
uint32 halfmemsize;			// Half of sample buffer in samples
void *point;			// used for transfer from App
int32 sammemsize;		// used for transfer from App
int32 samhalfmemsize;	// used for transfer from App

int32 makechans;        // no of chans in use
                        // 0=mono all 1=Left 2=Right 3=Both

int32 split;             // Normal=0  Splitview=1

int32 stop;              // ???

uint32  device,devicel;  // ???  May be used for allocating audio

int32 but,xmouse,dir;
uint32 origmouse,firstx,lastx,nx,chngdir,maxchng;

int32 viewlen;           // view length in samples

int32 resetrange;        // changes the range settings when window resized
int32 rangechange;       // changes the method by which the range is drawn
                         // 0=normal 1=calculate

int32 viewheight;       // used for redrawing window
int32 viewwidth;
int32 viewzoom;

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
uint32 done;       // valuse sent to Drawdonebox
int16 drawbarside;// which side is being processed  1=left 2=right

int32 scalelevel;   // value for scale on edit window

int32 position;     // position pointer     NOW CALLED ZONES
int32 positionend;  // position end pointer
int32 positionlen;  // length of position
int32 poside;       // position side

int32 filmod[2][22][260]; // stores for 7 band EQ
int32 filstor[2][22];     // more stores for 7 band EQ

//int32 complextable;  //  0=none;  1=sin;     2=arcsin;
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

//****************************************************************************************************
// More Globals


int32 samfxnumber;
int32 samfxtype;
int16 samslider1;
int16 samslider2;
int16 samslider3;
int16 samslider4;
int16 samslider;
int16 samradio1;
int16 samradio2;

area_id my_area; // memory allocated

int32 samlistnumber;

// Generates Error - Tell Cygnus
//const BRect rect(4,23,793,450);
//

char samtxt[50]; // Test message text

int32 comvals[5][22];

//****************************************************************************************************


  	void MessageReceived(BMessage* msg);

	static int ProduceNextBuffer(void *buffer, int numSamps);

	void Dodisplay(void);
	void Doundo(int32 undo);
	void Doeffect(void); // Calls Below
	void DoStandardEffect(void);
	void DoComplexEffect(void);
	void DoManip1(void);
	void DoManip2(void);
	void DoDualManip(void);
	void DoStereoEffect(void);
	void DoEdit(void);

	void Drawdonebox(uint32 done);
	void Newdrawdonebox(int16 draw1, int16 draw2, int16 draw3, int16 draw4, int16 draw5, int16 draw6);
	void Setcalcvals(void);

	// SAMPLE_fx1.cpp
	void Zerorng(void);								// Zero selected Range
	void Scalerng(void);							// Scale selected range
	void Rescalerng(void);							// ReScale selected range
	void Rescalenoboxrng(void);						// Rescale selected range, but no drawing into box
	void Copyrng(int32 opt);						// Edit operations

	void Arithrng(int32 opt,int32 optb);			// Arithemitic Operations
	void Invertrng(int32 opt,int32 optb);			// Invert + MANIPs
	void Limitrng(int32 opt,int32 optb);			// Limit + MANIPs
	void Distortrng(int32 opt,int32 optb);			// Distort + FX
	void Mathsrng(int32 opt,int32 optb);			// Sin + COMPLEX
	void Cleanrng(int32 opt,int32 optb);			// Clean + MANIPs
	void Capacitrng(int32 opt,int32 optb);			// Capacitance + MANIPs
	void Interrng(int32 opt,int32 optb);			// Interleave DMANIP
	void Phaserng(int32 opt,int32 optb);			// Phaser + FX
	void Flangerng(int32 opt,int32 optb);			// Flange + FX
	void Stutterrng(int32 opt,int32 optb);			// Stutter + DMANIPs
	void Filterrng(int32 opt);						// 7 Band EQ FX
	void Filterbandrng(int32 opt,int32 optb);		// 7 Band EQ MANIPs
	void Filter20rng(int32 opt);					// 20 Band EQ FX
	void Vibraterng(int32 opt,int32 optb);			// Vibrato FX
	void Filtersweeprng(int32 opt,int32 optb);		// Filter sweep MANIPs
	void Basfiltrng(int32 opt,int32 optb);			// Wha??? FX - Experimental


	// SAMPLE_fx2.cpp
	void  Echorng(int32 opt, int32 optb);			// Reverb FX
	void  Delayrng( int32 opt, int32 optb);			// Long Delay FX
	void  Faderng( int32 opt, int32 optb);			// Fade MANIPs
	void  Unorderrng(int32 opt,int32 optb);			// Unorder Samples FX
	void  Tunerng(int32 opt,int32 optb);			// Tune Octave MANIPs
	void  Detunerng(int32 opt,int32 optb);			// Detune FX
	void  Thickenrng(int32 opt,int32 optb);			// Thicken MANIPs
	void  SArithrng(int32 opt,int32 optb);			// Add SFX
	void  SInterrng(int32 opt,int32 optb);			// Interleave SFX
	void  Zerooutrng(int32 opt,int32 optb);			// Zero out MANIPs
	void  Compressrng(int32 opt,int32 optb);		// Compress FX
	void  Sfaderng(int32 opt,int32 optb);			// Stereo Pan SFX
	void  Blockrng(int32 opt,int32 optb);			// Transform Blocks MANIPs
	void  Blurrng(int32 opt,int32 optb);			// 2D Blur FX
	void  Chaosrng(int32 opt,int32 optb);			// Chaos MANIPs
	void  Chaos2rng(int32 opt,int32 optb);			// weird??? MANIPs


	// SAMPLE_fx3.cpp
	void  Strechorng(int32 opt,int32 optb);			// Stereo Reverb SFX
	void  Radrng(int32 opt,int32 optb);				// Rectify and Add DMANIPs
	void  MixDistortrng(int32 opt,int32 optb);		// Mix Distort FX
	void  DelayBackrng(int32 opt,int32 optb);		// Delay MANIPs
	void  DelayMathsrng(int32 opt,int32 optb);		// Delay Maths CFX


 private:
 	BStringView	*messageboxstring;
	BMenuItem	*scaleItem;

	void Sendmess(int32 messno);
	void FrameResized(float width, float height);
	void Drawsample(void);

};

// *********************************************************

class SampleView : public BView
{
 public:
 int32 maxlen;

 	// overridden BView functions
 	SampleView(BRect R);
 	void MouseDown(BPoint point);
	void Draw(BRect updateRect);
	void MessageReceived(BMessage* msg);
	void Tellviewmax(int32 max);
};









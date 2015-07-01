// DDApp.h 
// Copyright (c) Blachford Technology 1999
// 28/4/99

#include <Application.h>

#include "EDIT.h"
#include "SAMPLEWindow.h"
#include "ALLFX.h"
#include "ATTRACT.h"
#include "LOAD.h"
#include "MEMORY.h"
#include "EQ7.h"
#include "EQ20.h"

class DDApp : public BApplication
{
 public:
 	DDApp(void);
	~DDApp(void);

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

uint32 apsamcount;			// counter

area_id my_area;			// memory area allocated



//--------------------

int32 attractwin;



 	void Setupmemory(int32 apmemmemsize);
 	void Domenuops(void);
 	
 	void MessageReceived(BMessage* msg);
 	void AboutRequested(void);
 	void Notaboutrequested(void);
 	void sendmessage(int32 apmessno);
 	void OpenQuitWindow(void);
 	
 private:
 	EDIT*			editwindow;
 	SAMPLEWindow* 	samplewindow;
	ALLFX*			allfxwindow;
	ATTRACT*		attractorwindow;
	LOAD*			loadwindow;
	MEMORY*			memorywindow;
	EQ7*			eq7window;
	EQ20*			eq20window;
};


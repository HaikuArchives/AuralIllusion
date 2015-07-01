// SAMPLEWindowVars.h
// Copyright (c) Blachford Technology 1999
// 3/6/99

// These are used to re-display the sample
// and select ranges



int32 drawchans;			// no of chans in use - same as makechans
							// 0=mono all 1=Left 2=Right 3=Both

int16 z[4100];				// Used to hold display data
int16 zb[4100];

int32 centreL;				// Centre (zero) line/s
int32 centreR;

int32 drawrngbottom;		// bottom of view
int32 drawrngtop;			// top of view
uint32 Xlim;				// Window Length

int32 rngstart;				// Main Range Drawing stuff 
int32 rngend;
int32 rnglen;
int32 rngval;
int32 rnglenval;			// Range length in samples
int32 rngstrval;			// Range start in samples

int32 zonelenval;			// Length of the Zone

int32 curjump;				// sample Jump value
int32 scurjump;				// sample Jump value Left/Right/Stereo

int32 viewstart;			// view start in samples

uint32 drawhalfmemsize;		// Half of sample buffer in samples



int32 drawrngstrt;			// used to draw range in Draw()
int32 drawrngend;

int32 drawzonestrt;			// Zone - Red
int32 drawzoneend;
int32 drawzoneside;

int32 drawloopstrt;			// Loop - Blue
int32 drawloopend;

int32 drawplayline;		// Display as sample is playing
int32 drawoldplayline;	// Remove when time to draw next line



// REDRAW ALL AFTER PLAY HAS COMPLETED
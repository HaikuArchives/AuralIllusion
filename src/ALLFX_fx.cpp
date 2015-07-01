// ALLFX_fx.cpp 
// Copyright (c) Blachford Technology 1999 - 2000
// 28/4/99

//Sets vars for fx

#include "ALLFX.h"

#include <stdio.h>
#include <stdlib.h>


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

// Set Standard FX vars

void ALLFX::Setfxvars(int16 incount)
{
int16 outcount;

outcount = 0; // Standard FX

// Reverb
if (incount == 0)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Predelay");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Deep");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Wide");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Reverb");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=207;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=71;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Echo
if (incount == 1)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Echo");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=9;
allfxvals[outcount][incount][1]=114;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Delay
if (incount == 2)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=61;
allfxvals[outcount][incount][1]=174;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Phase Shift
if (incount == 3)
{
sprintf(allfxtxt[outcount][incount][0],"Shift");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Repeats");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Phase Shift");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "High Repeats takes a VERY long time");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=41;
allfxvals[outcount][incount][1]=175;
allfxvals[outcount][incount][2]=6;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Phaser
if (incount == 4)
{
sprintf(allfxtxt[outcount][incount][0],"Phase");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Length");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Phaser");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=215;
allfxvals[outcount][incount][1]=253;
allfxvals[outcount][incount][2]=125;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Chorus
if (incount == 5)
{
sprintf(allfxtxt[outcount][incount][0],"Phase");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Length");
sprintf(allfxtxt[outcount][incount][3],"Spread");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Chorus");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=77;
allfxvals[outcount][incount][1]=199;
allfxvals[outcount][incount][2]=81;
allfxvals[outcount][incount][3]=79;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Flange
if (incount == 6)
{
sprintf(allfxtxt[outcount][incount][0],"Shift");
sprintf(allfxtxt[outcount][incount][1],"Speed");
sprintf(allfxtxt[outcount][incount][2],"Level");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Up");
sprintf(allfxtxt[outcount][incount][5],"Down");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Flange");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=167;
allfxvals[outcount][incount][1]=150;
allfxvals[outcount][incount][2]=105;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Distortion
if (incount == 7)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Low");
sprintf(allfxtxt[outcount][incount][7],"High");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Distortion");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=158;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Compress
if (incount == 8)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Compress");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=125;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Expand
if (incount == 9)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Expand");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=158;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Noise Gate
if (incount == 10)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Noise Gate");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Enhance
if (incount == 11)
{
sprintf(allfxtxt[outcount][incount][0],"Depth");
sprintf(allfxtxt[outcount][incount][1],"Distort");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Noisy");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Enhance");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=19;
allfxvals[outcount][incount][1]=10;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Resample
if (incount == 12)
{
sprintf(allfxtxt[outcount][incount][0],"Detune");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Up");
sprintf(allfxtxt[outcount][incount][5],"Down");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Resample");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=245;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Detune
if (incount == 13)
{
sprintf(allfxtxt[outcount][incount][0],"Detune");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Up");
sprintf(allfxtxt[outcount][incount][5],"Down");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Detune");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=200;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Fade
if (incount == 14)
{
sprintf(allfxtxt[outcount][incount][0],"Start");
sprintf(allfxtxt[outcount][incount][1],"End");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Fade");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=93;
allfxvals[outcount][incount][1]=176;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Boost
if (incount == 15)
{
sprintf(allfxtxt[outcount][incount][0],"Start");
sprintf(allfxtxt[outcount][incount][1],"End");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Treble");
sprintf(allfxtxt[outcount][incount][5],"Bass");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Boost");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Resolution
if (incount == 16)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Divide");
sprintf(allfxtxt[outcount][incount][5],"Shift");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Resolution");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=52;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Bandwidth
if (incount == 17)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Start");
sprintf(allfxtxt[outcount][incount][5],"End");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Bandwidth");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=16;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Vibrato
if (incount == 18)
{
sprintf(allfxtxt[outcount][incount][0],"Depth?");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Time");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Vibrato");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Wow
if (incount == 19)
{
sprintf(allfxtxt[outcount][incount][0],"Depth");
sprintf(allfxtxt[outcount][incount][1],"Speed");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Wow");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Flutter
if (incount == 20)
{
sprintf(allfxtxt[outcount][incount][0],"Depth");
sprintf(allfxtxt[outcount][incount][1],"Speed");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Flutter");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Alternate
if (incount == 21)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Phase");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Short");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Alternate");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=25;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Quick Time Stretch
if (incount == 22)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Quick Time Stretch");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Ringing
if (incount == 23)
{
sprintf(allfxtxt[outcount][incount][0],"Depth");
sprintf(allfxtxt[outcount][incount][1],"Frequency");
sprintf(allfxtxt[outcount][incount][2],"Trigger Level");
sprintf(allfxtxt[outcount][incount][3],"Slope Sensitivity");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Ringing");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Wha
if (incount == 24)
{
sprintf(allfxtxt[outcount][incount][0],"Depth");
sprintf(allfxtxt[outcount][incount][1],"Speed");
sprintf(allfxtxt[outcount][incount][2],"Bandwidth");
sprintf(allfxtxt[outcount][incount][3],"Maximum");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Wha");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Tape Loop
if (incount == 25)
{
sprintf(allfxtxt[outcount][incount][0],"Head 1");
sprintf(allfxtxt[outcount][incount][1],"Head 2");
sprintf(allfxtxt[outcount][incount][2],"Head 3");
sprintf(allfxtxt[outcount][incount][3],"Decay");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Fixed");
sprintf(allfxtxt[outcount][incount][7],"Variable");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Tape Loop");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Rotary Speaker
if (incount == 26)
{
sprintf(allfxtxt[outcount][incount][0],"Treble Level");
sprintf(allfxtxt[outcount][incount][1],"Bass Level");
sprintf(allfxtxt[outcount][incount][2],"Treble Speed");
sprintf(allfxtxt[outcount][incount][3],"Bass Speed");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Rotary Speaker");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Filter Low Pass
if (incount == 27)
{
sprintf(allfxtxt[outcount][incount][0],"Start");
sprintf(allfxtxt[outcount][incount][1],"End");
sprintf(allfxtxt[outcount][incount][2],"Resonance Level");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Low Q");
sprintf(allfxtxt[outcount][incount][5],"High Q");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Resonant");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Filter Low Pass");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=123;
allfxvals[outcount][incount][1]=169;
allfxvals[outcount][incount][2]=74;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Filter High Pass 
if (incount == 28)
{
sprintf(allfxtxt[outcount][incount][0],"Start");
sprintf(allfxtxt[outcount][incount][1],"End");
sprintf(allfxtxt[outcount][incount][2],"Resonance Level");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Low Q");
sprintf(allfxtxt[outcount][incount][5],"High Q");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Resonant");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Filter High Pass");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=212;
allfxvals[outcount][incount][1]=23;
allfxvals[outcount][incount][2]=222;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Filter Band Pass
if (incount == 29)
{
sprintf(allfxtxt[outcount][incount][0],"Start");
sprintf(allfxtxt[outcount][incount][1],"End");
sprintf(allfxtxt[outcount][incount][2],"Resonance Level");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Low Q");
sprintf(allfxtxt[outcount][incount][5],"High Q");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Resonant");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Filter Band Pass");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=41;
allfxvals[outcount][incount][1]=189;
allfxvals[outcount][incount][2]=125;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Filter Band Cut
if (incount == 30)
{
sprintf(allfxtxt[outcount][incount][0],"Start");
sprintf(allfxtxt[outcount][incount][1],"End");
sprintf(allfxtxt[outcount][incount][2],"Resonance Level");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Low Q");
sprintf(allfxtxt[outcount][incount][5],"High Q");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Resonant");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Filter Band Cut");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=194;
allfxvals[outcount][incount][1]=24;
allfxvals[outcount][incount][2]=87;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Filter Notch Pass
if (incount == 31)
{
sprintf(allfxtxt[outcount][incount][0],"Start");
sprintf(allfxtxt[outcount][incount][1],"End");
sprintf(allfxtxt[outcount][incount][2],"Resonance Level");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Low Q");
sprintf(allfxtxt[outcount][incount][5],"High Q");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Resonant");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Filter Notch Pass");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=29;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=85;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Filter Notch Cut
if (incount == 32)
{
sprintf(allfxtxt[outcount][incount][0],"Start");
sprintf(allfxtxt[outcount][incount][1],"End");
sprintf(allfxtxt[outcount][incount][2],"Resonance Level");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Low Q");
sprintf(allfxtxt[outcount][incount][5],"High Q");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Resonant");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Filter Notch Cut");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=65;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Backwards Reverb
if (incount == 33)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Predelay");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Deep");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Wide");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Backwards Reverb");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=87;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=9;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Reverb Phaser
if (incount == 34)
{
sprintf(allfxtxt[outcount][incount][0],"Reverb");
sprintf(allfxtxt[outcount][incount][1],"Phase");
sprintf(allfxtxt[outcount][incount][2],"Length");
sprintf(allfxtxt[outcount][incount][3],"Level");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Double");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Wide");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Reverb Phaser");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=193;
allfxvals[outcount][incount][1]=212;
allfxvals[outcount][incount][2]=66;
allfxvals[outcount][incount][3]=191;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Old Reverb
if (incount == 35)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Old Reverb");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Reverb Only
if (incount == 36)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Predelay");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Deep");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Wide");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Reverb Only");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "MESSES UP UNDO");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=175;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=51;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Long Delay
if (incount == 37)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Long Delay");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=18;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Multi Tap Delay
if (incount == 38)
{
sprintf(allfxtxt[outcount][incount][0],"Tap 1");
sprintf(allfxtxt[outcount][incount][1],"Tap 2");
sprintf(allfxtxt[outcount][incount][2],"Tap 3");
sprintf(allfxtxt[outcount][incount][3],"Tap 4");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Multi Tap Delay");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=46;
allfxvals[outcount][incount][1]=82;
allfxvals[outcount][incount][2]=85;
allfxvals[outcount][incount][3]=217;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Feedback Delay
if (incount == 39)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Feedback Delay");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=241;
allfxvals[outcount][incount][1]=53;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Bounce Delay
if (incount == 40)
{
sprintf(allfxtxt[outcount][incount][0],"Time");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Bounce Delay");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=185;
allfxvals[outcount][incount][1]=186;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Jump Flange
if (incount == 41)
{
sprintf(allfxtxt[outcount][incount][0],"Phase");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Length");
sprintf(allfxtxt[outcount][incount][3],"Step");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Jump Flange");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=237;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=48;
allfxvals[outcount][incount][3]=74;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Strange Flange
if (incount == 42)
{
sprintf(allfxtxt[outcount][incount][0],"Shift");
sprintf(allfxtxt[outcount][incount][1],"Length");
sprintf(allfxtxt[outcount][incount][2],"Depth");
sprintf(allfxtxt[outcount][incount][3],"Time");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Strange Flange");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=128;
allfxvals[outcount][incount][1]=63;
allfxvals[outcount][incount][2]=52;
allfxvals[outcount][incount][3]=143;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Delay Flange
if (incount == 43)
{
sprintf(allfxtxt[outcount][incount][0],"Shift");
sprintf(allfxtxt[outcount][incount][1],"Speed");
sprintf(allfxtxt[outcount][incount][2],"Level");
sprintf(allfxtxt[outcount][incount][3],"Delay");
sprintf(allfxtxt[outcount][incount][4],"Up");
sprintf(allfxtxt[outcount][incount][5],"Down");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Delay Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Flange");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=104;
allfxvals[outcount][incount][1]=108;
allfxvals[outcount][incount][2]=167;
allfxvals[outcount][incount][3]=84;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=196;
}


// Digital Distortion
if (incount == 44)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Low");
sprintf(allfxtxt[outcount][incount][7],"High");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Digital Distortion");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=150;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Contortion
if (incount == 45)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Low");
sprintf(allfxtxt[outcount][incount][7],"High");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Contortion");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=150;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Mix Contortion
if (incount == 46)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Low");
sprintf(allfxtxt[outcount][incount][7],"High");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Mix Contortion");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=155;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Bandwidth Smooth
if (incount == 47)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Smooth");
sprintf(allfxtxt[outcount][incount][5],"UnSmooth");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Bandwidth Smooth");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=9;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay Vibrato
if (incount == 48)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2],"Speed");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Vibrato");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

}


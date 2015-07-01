// ALLFX_sfx.cpp 
// Copyright (c) Blachford Technology 1999 - 2000
// 28/4/99

//Sets vars for stereofx

#include "ALLFX.h"

#include <stdio.h>
#include <stdlib.h>


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************


// Set Stereo FX vars

void ALLFX::Setstereofxvars(int16 incount)
{
int16 outcount;

outcount = 5; // Stereo Effects


// Stereo Reverb
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

sprintf(allfxboxtxt[outcount][incount][0], "Stereo Reverb");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=77;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Stereo Reverb Only
if (incount == 1)
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

sprintf(allfxboxtxt[outcount][incount][0], "Stereo Reverb Only");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=103;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Stereo Reverb Only Add
if (incount == 2)
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

sprintf(allfxboxtxt[outcount][incount][0], "Stereo Reverb Only Add");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
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


// Stereo Echo
if (incount == 3)
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

sprintf(allfxboxtxt[outcount][incount][0], "Stereo Echo");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
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


// Stereo Delay
if (incount == 4)
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

sprintf(allfxboxtxt[outcount][incount][0], "Stereo Delay");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
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


// Stereo Chorus
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

sprintf(allfxboxtxt[outcount][incount][0], "Stereo Chorus");
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


// Make Stereo
if (incount == 6)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Make Stereo");
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


// Process Stereo
if (incount == 7)
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

sprintf(allfxboxtxt[outcount][incount][0], "Process Stereo");
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


// Remove Common
if (incount == 8)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Remove Common");
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


// Swap Sides Left<->Right
if (incount == 9)
{
sprintf(allfxtxt[outcount][incount][0],"Crosstalk");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Swap Sides Left<->Right");
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


// Powered Compress
if (incount == 10)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Powered Compress");
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


// Powered Expand
if (incount == 11)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Powered Expand");
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


// Cross Fade Left <-> Right
if (incount == 12)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cross Fade Left <-> Right");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Cross Fade Stereo Mono
if (incount == 13)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cross Fade Stereo Mono");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Cross Fade Ping Pong
if (incount == 14)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Maximum Stereo");
sprintf(allfxtxt[outcount][incount][2],"Maximum Mono");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cross Fade Ping Pong");
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


// Pan Manual
if (incount == 15)
{
sprintf(allfxtxt[outcount][incount][0],"Left Start");
sprintf(allfxtxt[outcount][incount][1],"Right Start");
sprintf(allfxtxt[outcount][incount][2],"Left End");
sprintf(allfxtxt[outcount][incount][3],"Right End");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Pan Manual");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Pan Ping Pong
if (incount == 16)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Max Left");
sprintf(allfxtxt[outcount][incount][2],"Max Right");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Pan Ping Pong");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=10;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Pan Mono Left
if (incount == 17)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Pan Mono Left");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Pan Mono Right
if (incount == 18)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Pan Mono Right");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Pan Mono Ping Pong
if (incount == 19)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Max Left");
sprintf(allfxtxt[outcount][incount][2],"Max Right");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Pan Mono Ping Pong");
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


// Pan Reverse Mono
if (incount == 20)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Minimum Left");
sprintf(allfxtxt[outcount][incount][2],"Minimum Right");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Pan Reverse Mono");
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


// Walk
if (incount == 21)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Use Left");
sprintf(allfxtxt[outcount][incount][5],"Use Right");
sprintf(allfxtxt[outcount][incount][6],"Left->Right");
sprintf(allfxtxt[outcount][incount][7],"Right->Left");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Walk");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

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


// Walk Ping Pong
if (incount == 22)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Use Left");
sprintf(allfxtxt[outcount][incount][5],"Use Right");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Walk Ping Pong");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
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


// Walk Cross
if (incount == 23)
{
sprintf(allfxtxt[outcount][incount][0],"Left");
sprintf(allfxtxt[outcount][incount][1],"Right");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Walk Cross");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][6]=256;
}


// Walk Cross Ping Pong
if (incount == 24)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Left");
sprintf(allfxtxt[outcount][incount][2],"Right");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Walk Cross Ping Pong");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][6]=256;
}


// Walk Mono
if (incount == 25)
{
sprintf(allfxtxt[outcount][incount][0],"Left");
sprintf(allfxtxt[outcount][incount][1],"Right");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Left->Right");
sprintf(allfxtxt[outcount][incount][7],"Right->Left");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Walk Mono");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
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


// Walk Mono Ping Pong
if (incount == 26)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Left");
sprintf(allfxtxt[outcount][incount][2],"Right");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Walk Mono Ping Pong");
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


// Left to Stereo
if (incount == 27)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Left to Stereo");
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


// Right to Stereo
if (incount == 28)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Right to Stereo");
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


// Stereo to Mono
if (incount == 29)
{
sprintf(allfxtxt[outcount][incount][0],"Left Level");
sprintf(allfxtxt[outcount][incount][1],"Right Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Stereo to Mono");
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


// Stereo to Left
if (incount == 30)
{
sprintf(allfxtxt[outcount][incount][0],"Left");
sprintf(allfxtxt[outcount][incount][1],"Right");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Stereo to Left");
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


// Stereo to Right
if (incount == 31)
{
sprintf(allfxtxt[outcount][incount][0],"Left");
sprintf(allfxtxt[outcount][incount][1],"Right");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Stereo to Right");
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


// Process Wide Narrow Wide
if (incount == 32)
{
sprintf(allfxtxt[outcount][incount][0],"Max Wide");
sprintf(allfxtxt[outcount][incount][1],"Max Narrow");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Process Wide Narrow Wide");
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


// Process Narrow Wide Narrow
if (incount == 33)
{
sprintf(allfxtxt[outcount][incount][0],"Max Wide");
sprintf(allfxtxt[outcount][incount][1],"Max Narrow");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Process Narrow Wide Narrow");
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


// Process Ping Pong
if (incount == 34)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Max Wide");
sprintf(allfxtxt[outcount][incount][2],"Max Narrow ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Start Wide");
sprintf(allfxtxt[outcount][incount][5],"Start Narrow");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Process Ping Pong");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
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


// Add
if (incount == 35)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Add");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Subtract
if (incount == 36)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Subtract");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Backwards Subtract
if (incount == 37)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Backwards Subtract");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Multiply
if (incount == 38)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Multiply");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=67;
allfxvals[outcount][incount][1]=67;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Divide
if (incount == 39)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Divide");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Backwards Divide
if (incount == 40)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Backwards Divide");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// AND
if (incount == 41)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Positive");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "AND");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// OR
if (incount == 42)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Positive");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "OR");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// XOR
if (incount == 43)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Positive");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "XOR");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Greater
if (incount == 44)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Positive");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Greater");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Lesser
if (incount == 45)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Positive");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Lesser");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Interleave
if (incount == 46)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Interleave");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Modulus
if (incount == 47)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Modulus");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Backwards Modulus
if (incount == 48)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Rescale");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Backwards Modulus");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Stutter
if (incount == 49)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Positive");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Stutter");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

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


// Rectify
if (incount == 50)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Positive");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Full");
sprintf(allfxtxt[outcount][incount][7],"Half");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Rectify");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=0;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Rectify and Add
if (incount == 51)
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

sprintf(allfxboxtxt[outcount][incount][0], "Rectify and Add");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
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


// Within
if (incount == 52)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Within");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
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


// Without
if (incount == 53)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Without");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
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


// Comparator
if (incount == 54)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Comparator");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
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


// Magnitude Difference
if (incount == 55)
{
sprintf(allfxtxt[outcount][incount][0],"Level 1");
sprintf(allfxtxt[outcount][incount][1],"Level 2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Magnitude Difference");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
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

}

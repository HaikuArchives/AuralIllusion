// ALLFX_dman.cpp
// Copyright (c) Blachford Technology 1999 - 2000
// 28/4/99

//Sets vars for dual manips

#include "ALLFX.h"

#include <stdio.h>
#include <stdlib.h>


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************


// Set Dual Manips vars

void ALLFX::Setdualmanipvars(int16 incount)
{
int16 outcount;


outcount = 4; // Dual Manips


// Swap Samples
if (incount == 0)
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

sprintf(allfxboxtxt[outcount][incount][0], "Swap Samples");
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


// Cross Fade
if (incount == 1)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cross Fade");
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


// Reverb Only
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

sprintf(allfxboxtxt[outcount][incount][0], "Reverb Only");
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


// Reverb Only Add
if (incount == 3)
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

sprintf(allfxboxtxt[outcount][incount][0], "Reverb Only Add");
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


// Powered Compress
if (incount == 4)
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
if (incount == 5)
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


// Half Rectify and Add
if (incount == 6)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Low");
sprintf(allfxtxt[outcount][incount][7],"High");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Half Rectify and Add");
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


// Full Rectify and Add
if (incount == 7)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Negative");
sprintf(allfxtxt[outcount][incount][6],"Low");
sprintf(allfxtxt[outcount][incount][7],"High");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Full Rectify and Add");
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


// Add
if (incount == 8)
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
if (incount == 9)
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
if (incount == 10)
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
if (incount == 11)
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

allfxvals[outcount][incount][0]=128;
allfxvals[outcount][incount][1]=128;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Divide
if (incount == 12)
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
if (incount == 13)
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
if (incount == 14)
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
if (incount == 15)
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
if (incount == 16)
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
if (incount == 17)
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
if (incount == 18)
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
if (incount == 19)
{
sprintf(allfxtxt[outcount][incount][0],"Level  1");
sprintf(allfxtxt[outcount][incount][1],"Level  2");
sprintf(allfxtxt[outcount][incount][2],"Length");
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
allfxghosts[outcount][incount][2]=1;
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


// Rectify
if (incount == 20)
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
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Stutter
if (incount == 21)
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


// Modulus
if (incount == 22)
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
if (incount == 23)
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
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Within
if (incount == 24)
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
if (incount == 25)
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
if (incount == 26)
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


// Amplitude Modulation
if (incount == 27)
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

sprintf(allfxboxtxt[outcount][incount][0], "Amplitude Modulation");
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


// Frequency Modulation
if (incount == 28)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Frequency Modulation");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
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


// Pulse Width Modulation
if (incount == 29)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Pulse Width Modulation");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
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


// Triple Modulation
if (incount == 30)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Triple Modulation");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
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


// Remove Common
if (incount == 31)
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

sprintf(allfxboxtxt[outcount][incount][0], "Remove Common");
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
if (incount == 32)
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


// Rectify and Add
if (incount == 33)
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


}


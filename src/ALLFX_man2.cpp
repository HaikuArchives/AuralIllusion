// ALLFX_man2.cpp 
// Copyright (c) Blachford Technology 1999
// 28/4/99

//Sets vars for manips 2

#include "ALLFX.h"

#include <stdio.h>
#include <stdlib.h>


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************


// Set Manips 2 vars

void ALLFX::Setmanip2vars(int16 incount)
{
int16 outcount;


outcount = 3; // Manip 2


// Over
if (incount == 0)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Smooth");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Over");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=68;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Under
if (incount == 1)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Smooth");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Under");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=125;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// In Between
if (incount == 2)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1],"Width ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Smooth");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "In Between");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=85;
allfxvals[outcount][incount][1]=143;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Out Between
if (incount == 3)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1],"Width");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Add");
sprintf(allfxtxt[outcount][incount][5],"Subtract");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Smooth");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Out Between");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=76;
allfxvals[outcount][incount][1]=109;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Limit Low
if (incount == 4)
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

sprintf(allfxboxtxt[outcount][incount][0], "Limit Low");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=193;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Limit High
if (incount == 5)
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

sprintf(allfxboxtxt[outcount][incount][0], "Limit High");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=70;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Add Spikes
if (incount == 6)
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

sprintf(allfxboxtxt[outcount][incount][0], "Add Spikes");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=64;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delete Spikes
if (incount == 7)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Copy");
sprintf(allfxtxt[outcount][incount][5],"Smooth");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delete Spikes");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

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


// Capacitance
if (incount == 8)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Capacitance");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=218;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Replacement
if (incount == 9)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Low");
sprintf(allfxtxt[outcount][incount][5],"High");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Replacement");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=128;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Tear
if (incount == 10)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Tear");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// SwapByteOrder
if (incount == 11)
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

sprintf(allfxboxtxt[outcount][incount][0], "Swap Byte Order");
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


// Delta
if (incount == 12)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Single");
sprintf(allfxtxt[outcount][incount][5],"Double");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delta");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

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


// Square
if (incount == 13)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Inverse");
sprintf(allfxtxt[outcount][incount][6],"Rectify");
sprintf(allfxtxt[outcount][incount][7],"Preserve");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Square");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=194;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Half Square
if (incount == 14)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Inverse");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Half Square");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Square Wave Generator
if (incount == 15)
{
sprintf(allfxtxt[outcount][incount][0],"Wave");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Wave Generator");
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


// 8->16 bit
if (incount == 16)
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

sprintf(allfxboxtxt[outcount][incount][0], "8->16 Bit");
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


// 16->8 bit
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

sprintf(allfxboxtxt[outcount][incount][0], "16->8 Bit");
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


// Transform Blocks
if (incount == 18)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"First");
sprintf(allfxtxt[outcount][incount][2],"Second");
sprintf(allfxtxt[outcount][incount][3],"Third");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Transform Blocks");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][3]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=202;
allfxvals[outcount][incount][2]=16;
allfxvals[outcount][incount][3]=86;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Reverse Single Blocks
if (incount == 19)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Reverse Single Blocks");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=48;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Reverse All Blocks
if (incount == 20)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6],"Single");
sprintf(allfxtxt[outcount][incount][7],"Double");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Reverse All Blocks");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=54;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Skip Blocks
if (incount == 21)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Skip Blocks");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=28;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Repeat Blocks
if (incount == 22)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Repeat Blocks");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=27;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Unorder Samples
if (incount == 23)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Single");
sprintf(allfxtxt[outcount][incount][5],"Double");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Unorder Samples");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=27;
allfxvals[outcount][incount][1]=128;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Unorder Blocks
if (incount == 24)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Single");
sprintf(allfxtxt[outcount][incount][5],"Double");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Unorder Blocks");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=48;
allfxvals[outcount][incount][1]=142;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Zero Alternate
if (incount == 25)
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

sprintf(allfxboxtxt[outcount][incount][0], "Zero Alternate");
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


// Flip Alternate
if (incount == 26)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Flip Alternate");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=14;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Ramdom Amplifier
if (incount == 27)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Random Amplifier");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=44;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Random Filter
if (incount == 28)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6],"Light");
sprintf(allfxtxt[outcount][incount][7],"Heavy");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Random Filter");
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


// Swap Halves
if (incount == 29)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Full");
sprintf(allfxtxt[outcount][incount][5],"Half");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Swap Halves");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=48;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Remove Center
if (incount == 30)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Full");
sprintf(allfxtxt[outcount][incount][5],"Half");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Remove Centre");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=82;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Add Centre
if (incount == 31)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Full");
sprintf(allfxtxt[outcount][incount][5],"Half");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Add Centre");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=62;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Remove Flat
if (incount == 32)
{
sprintf(allfxtxt[outcount][incount][0],"Range");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Full");
sprintf(allfxtxt[outcount][incount][5],"Half");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Remove Flat");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=63;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Keep Flat
if (incount == 33)
{
sprintf(allfxtxt[outcount][incount][0],"Range");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Full");
sprintf(allfxtxt[outcount][incount][5],"Half");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Keep Flat");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=20;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Remove Middle
if (incount == 34)
{
sprintf(allfxtxt[outcount][incount][0],"Range");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Full");
sprintf(allfxtxt[outcount][incount][5],"Half");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Remove Middle");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=20;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Transmogrify
if (incount == 35)
{
sprintf(allfxtxt[outcount][incount][0],"Range");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Centre");
sprintf(allfxtxt[outcount][incount][5],"Bottom");
sprintf(allfxtxt[outcount][incount][6],"Full");
sprintf(allfxtxt[outcount][incount][7],"Half");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Transmogrify");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=128;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Non-Transmogrify
if (incount == 36)
{
sprintf(allfxtxt[outcount][incount][0],"Range");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Centre");
sprintf(allfxtxt[outcount][incount][5],"Bottom");
sprintf(allfxtxt[outcount][incount][6],"Full");
sprintf(allfxtxt[outcount][incount][7],"Half");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Non-Transmogrify");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=223;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Delay Delta
if (incount == 37)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Single");
sprintf(allfxtxt[outcount][incount][5],"Double");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Delta");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=64;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay Backwards Subtract
if (incount == 38)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Backwards Subtract");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=202;
allfxvals[outcount][incount][1]=195;
allfxvals[outcount][incount][2]=195;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay Multiply
if (incount == 39)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Multiply");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=224;
allfxvals[outcount][incount][1]=160;
allfxvals[outcount][incount][2]=160;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Delay Divide
if (incount == 40)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Divide");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=171;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Delay Backwards Divide
if (incount == 41)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Backwards Divide");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=128;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Delay AND
if (incount == 42)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay AND");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=245;
allfxvals[outcount][incount][1]=90;
allfxvals[outcount][incount][2]=194;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Delay OR
if (incount == 43)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay OR");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=15;
allfxvals[outcount][incount][1]=95;
allfxvals[outcount][incount][2]=95;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay XOR
if (incount == 44)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay XOR");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=128;
allfxvals[outcount][incount][1]=100;
allfxvals[outcount][incount][2]=100;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay Rectify
if (incount == 45)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Single");
sprintf(allfxtxt[outcount][incount][5],"Double");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Rectify");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=63;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay Greater
if (incount == 46)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Greater");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=62;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay Lesser
if (incount == 47)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Single");
sprintf(allfxtxt[outcount][incount][5],"Double");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Lesser");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=226;
allfxvals[outcount][incount][1]=152;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay Interleave
if (incount == 48)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Interleave");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=24;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}


// Delay Modulus
if (incount == 49)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Modulus");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=128;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Delay Backwards Modulus
if (incount == 50)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Filter");
sprintf(allfxtxt[outcount][incount][6],"Short");
sprintf(allfxtxt[outcount][incount][7],"Long");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Backwards Modulus");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=128;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=256;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Noise
if (incount == 51)
{
sprintf(allfxtxt[outcount][incount][0],"Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Both");
sprintf(allfxtxt[outcount][incount][5],"Positive");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Noise");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Filtered Noise
if (incount == 52)
{
sprintf(allfxtxt[outcount][incount][0],"Pitch");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Filtered Noise");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=25;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Rumble
if (incount == 53)
{
sprintf(allfxtxt[outcount][incount][0],"Pitch");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"High");
sprintf(allfxtxt[outcount][incount][5],"Low");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Rumble");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=181;
allfxvals[outcount][incount][1]=256;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Chaos
if (incount == 54)
{
sprintf(allfxtxt[outcount][incount][0],"Primer");
sprintf(allfxtxt[outcount][incount][1],"Fine A");
sprintf(allfxtxt[outcount][incount][2],"Fine B");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Chaos");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=64;
allfxvals[outcount][incount][1]=128;
allfxvals[outcount][incount][2]=194;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


// Random
if (incount == 55)
{
sprintf(allfxtxt[outcount][incount][0],"Length");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Short");
sprintf(allfxtxt[outcount][incount][5],"Long");
sprintf(allfxtxt[outcount][incount][6],"Add");
sprintf(allfxtxt[outcount][incount][7],"Subtract");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Random");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], " ");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=256;
allfxvals[outcount][incount][1]=0;
allfxvals[outcount][incount][2]=0;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}


}


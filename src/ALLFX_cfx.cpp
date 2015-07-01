// ALLFX_cfx.cpp 
// Copyright (c) Blachford Technology 1999 - 2000
// 28/4/99

//Sets vars for complex fx

#include "ALLFX.h"

#include <stdio.h>
#include <stdlib.h>


// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

// Set Complex FX vars

void ALLFX::Setcomplexfxvars(int16 incount)
{
int16 outcount;

outcount = 1; // Complex FX

// 1/x
if (incount == 0)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "1/x");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// acos
if (incount == 1)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Acos");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// asin
if (incount == 2)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Asin");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// atan
if (incount == 3)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Atan");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// cos
if (incount == 4)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cos");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// sin
if (incount == 5)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Sin");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// tan
if (incount == 6)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Tan");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// cosh
if (incount == 7)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cosh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// sinh
if (incount == 8)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Sinh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// tanh
if (incount == 9)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Tanh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// acosh
if (incount == 10)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Acosh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// asinh
if (incount == 11)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Asinh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// atanh
if (incount == 12)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Atanh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// sec
if (incount == 13)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Sec");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// cosec
if (incount == 14)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cosec");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// Cot
if (incount == 15)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cot");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// +Sin
if (incount == 16)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "+Sin");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// exp
if (incount == 17)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Exp");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// log
if (incount == 18)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Log");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// log10
if (incount == 19)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Log10");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// expm1
if (incount == 20)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Expm1");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// log1p
if (incount == 21)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Log1p");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// logb
if (incount == 22)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Logb");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// +Log
if (incount == 23)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "+Log");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// sqrt
if (incount == 24)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Sqrt");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// cbrt
if (incount == 25)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Cbrt");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// ceil
if (incount == 26)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Ceil");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// fabs
if (incount == 27)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Fabs");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// floor
if (incount == 28)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Floor");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// significand
if (incount == 29)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Significand");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// j0
if (incount == 30)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "J0");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// j1
if (incount == 31)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "J1");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// y0
if (incount == 32)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Y0");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// y1
if (incount == 33)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Y1");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// erf
if (incount == 34)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Erf");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// erfc
if (incount == 35)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Erfc");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// gamma
if (incount == 36)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Gamma");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// lgamma
if (incount == 37)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Lgamma");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// rint
if (incount == 38)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Rint");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// ilogbf
if (incount == 39)
{
sprintf(allfxtxt[outcount][incount][0]," ");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Ilogbf");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

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

// Delay 1/x
if (incount == 40)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay 1/x");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}

// 	Delay Acos
if (incount == 41)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "	Delay Acos");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}

// Delay Asin
if (incount == 42)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Asin");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=1;
allfxvals[outcount][incount][5]=1;
allfxvals[outcount][incount][6]=256;
}

// Delay Atan
if (incount == 43)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Atan");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Cos
if (incount == 44)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Cos");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Sin
if (incount == 45)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Sin");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Tan
if (incount == 46)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Tan");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Cosh
if (incount == 47)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Cosh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Sinh
if (incount == 48)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Sinh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Tanh
if (incount == 49)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Tanh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Acosh
if (incount == 50)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Acosh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Asinh
if (incount == 51)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Asinh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Atanh
if (incount == 52)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Atanh");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Sec
if (incount == 53)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Sec");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Cosec
if (incount == 54)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Cosec");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Cot
if (incount == 55)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Cot");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay +Sin
if (incount == 56)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay +Sin");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Exp
if (incount == 57)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Exp");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Log
if (incount == 58)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Log");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Log10
if (incount == 59)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Log10");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Expm1
if (incount == 60)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Expm1");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Log1p
if (incount == 61)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Log1p");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Logb
if (incount == 62)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Logb");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay +Log
if (incount == 63)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay +Log");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Sqrt
if (incount == 64)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Sqrt");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Cbrt
if (incount == 65)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Cbrt");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Ceil
if (incount == 66)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Ceil");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Fabs
if (incount == 67)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Fabs");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Floor
if (incount == 68)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Floor");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Significand
if (incount == 69)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Significand");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// 	Delay J0
if (incount == 70)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "	Delay J0");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay J1
if (incount == 71)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay J1");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Y0
if (incount == 72)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Y0");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Y1
if (incount == 73)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Y1");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Erf
if (incount == 74)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Erf");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Erfc
if (incount == 75)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Erfc");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Gamma
if (incount == 76)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Gamma");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Lgamma
if (incount == 77)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Lgamma");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Rint
if (incount == 78)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Rint");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Delay Ilogbf
if (incount == 79)
{
sprintf(allfxtxt[outcount][incount][0],"Delay");
sprintf(allfxtxt[outcount][incount][1],"Level 1");
sprintf(allfxtxt[outcount][incount][2],"Level 2");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4],"Normal");
sprintf(allfxtxt[outcount][incount][5],"Difference");
sprintf(allfxtxt[outcount][incount][6],"Normal");
sprintf(allfxtxt[outcount][incount][7],"Inverted");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Delay Ilogbf");
sprintf(allfxboxtxt[outcount][incount][1], " ");
sprintf(allfxboxtxt[outcount][incount][2], "Best used on simple samples");

allfxghosts[outcount][incount][0]=1;
allfxghosts[outcount][incount][1]=1;
allfxghosts[outcount][incount][2]=1;
allfxghosts[outcount][incount][4]=1;
allfxghosts[outcount][incount][5]=1;
allfxghosts[outcount][incount][6]=1;

allfxvals[outcount][incount][0]=196;
allfxvals[outcount][incount][1]=131;
allfxvals[outcount][incount][2]=131;
allfxvals[outcount][incount][3]=0;
allfxvals[outcount][incount][4]=0;
allfxvals[outcount][incount][5]=0;
allfxvals[outcount][incount][6]=256;
}

// Graphic Equalizer 7 Band
if (incount == 80)
{
sprintf(allfxtxt[outcount][incount][0],"7 Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Graphic Equalizer 7 Band");
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


// Graphic Equalizer 20 Band
if (incount == 81)
{
sprintf(allfxtxt[outcount][incount][0],"20 Level");
sprintf(allfxtxt[outcount][incount][1]," ");
sprintf(allfxtxt[outcount][incount][2]," ");
sprintf(allfxtxt[outcount][incount][3]," ");
sprintf(allfxtxt[outcount][incount][4]," ");
sprintf(allfxtxt[outcount][incount][5]," ");
sprintf(allfxtxt[outcount][incount][6]," ");
sprintf(allfxtxt[outcount][incount][7]," ");
sprintf(allfxtxt[outcount][incount][8],"Mix Level");

sprintf(allfxboxtxt[outcount][incount][0], "Graphic Equalizer 20 Band");
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

}


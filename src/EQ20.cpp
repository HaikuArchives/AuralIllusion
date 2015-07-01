// EQ20.cpp
// Copyright (c) Blachford Technology 1999
// eq20/6/99 

#include <Application.h>
#include <StringView.h>
#include <OS.h>
#include <ScrollBar.h>
#include <Button.h>

#include <stdio.h>
#include <stdlib.h>

#include "EQ20.h"
#include "EQ20Globals.h"
#include "MsgVals.h"

/*****************************************************************/
BView* eq20view;

BStringView*	eq20_0val;
BStringView*	eq20_0string;
char 			eq20_0txt[25];
BStringView*	eq20_1val;
BStringView* 	eq20_1string;
char			eq20_1txt[25];
BStringView*	eq20_2val;
BStringView*	eq20_2string;
char 			eq20_2txt[25];
BStringView*	eq20_3val;
BStringView*	eq20_3string;
char 			eq20_3txt[25];
BStringView*	eq20_4val;
BStringView*	eq20_4string;
char 			eq20_4txt[25];
BStringView*	eq20_5val;
BStringView*	eq20_5string;
char 			eq20_5txt[25];
BStringView*	eq20_6val;
BStringView*	eq20_6string;
char 			eq20_6txt[25];
BStringView*	eq20_7val;
BStringView*	eq20_7string;
char 			eq20_7txt[25];
BStringView*	eq20_8val;
BStringView*	eq20_8string;
char 			eq20_8txt[25];
BStringView*	eq20_9val;
BStringView*	eq20_9string;
char 			eq20_9txt[25];
BStringView*	eq20_10val;
BStringView*	eq20_10string;
char 			eq20_10txt[25];
BStringView*	eq20_11val;
BStringView*	eq20_11string;
char 			eq20_11txt[25];
BStringView*	eq20_12val;
BStringView*	eq20_12string;
char 			eq20_12txt[25];
BStringView*	eq20_13val;
BStringView*	eq20_13string;
char 			eq20_13txt[25];
BStringView*	eq20_14val;
BStringView*	eq20_14string;
char 			eq20_14txt[25];
BStringView*	eq20_15val;
BStringView*	eq20_15string;
char 			eq20_15txt[25];
BStringView*	eq20_16val;
BStringView*	eq20_16string;
char 			eq20_16txt[25];
BStringView*	eq20_17val;
BStringView*	eq20_17string;
char 			eq20_17txt[25];
BStringView*	eq20_18val;
BStringView*	eq20_18string;
char 			eq20_18txt[25];
BStringView*	eq20_19val;
BStringView*	eq20_19string;
char 			eq20_19txt[25];
BStringView*	eq20_20val;
BStringView*	eq20_20string;
char 			eq20_20txt[25];


const BRect rect(200,23,810,228);

//int32 eq20listtype;
//int32 eq20listnumber;
//int32 eq20fxtype;
//int32 eq20fxnumber;
int16 eq20iewmsgtyp;
int16 eq20iewtyp;

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

EQ20::EQ20()
	: BWindow(rect, "20 Band Graphic Equalizer", B_TITLED_WINDOW, B_CURRENT_WORKSPACE)
{
	BView* eq20view = new BView(BRect(0,0,610,205),"eq20view", B_FOLLOW_ALL, B_WILL_DRAW);

	eq20view->SetViewColor(216,216,216); // View is Grey
	eq20view->SetHighColor(255,255,255);
	eq20view->SetLowColor(0,0,0);

	eq20_0val = new BStringView(BRect(572,187,600,203), "eq20_0val","512",  B_WILL_DRAW);
	eq20_0val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_0val);
	eq20_1val = new BStringView(BRect(12,3,35,19), "eq20_1val","256",  B_WILL_DRAW);
	eq20_1val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_1val);
	eq20_2val = new BStringView(BRect(42,3,65,19), "eq20_2val","256",  B_WILL_DRAW);
	eq20_2val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_2val);
	eq20_3val = new BStringView(BRect(72,3,95,19), "eq20_3val","256",  B_WILL_DRAW);
	eq20_3val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_3val);
	eq20_4val = new BStringView(BRect(102,3,125,19), "eq20_4val","256",  B_WILL_DRAW);
	eq20_4val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_4val);
	eq20_5val = new BStringView(BRect(132,3,155,19), "eq20_5val","256",  B_WILL_DRAW);
	eq20_5val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_5val);
	eq20_6val = new BStringView(BRect(162,3,185,19), "eq20_6val","256",  B_WILL_DRAW);
	eq20_6val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_6val);
	eq20_7val = new BStringView(BRect(192,3,215,19), "eq20_7val","256",  B_WILL_DRAW);
	eq20_7val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_7val);
	eq20_8val = new BStringView(BRect(222,3,245,19), "eq20_8val","256",  B_WILL_DRAW);
	eq20_8val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_8val);
	eq20_9val = new BStringView(BRect(252,3,275,19), "eq20_9val","256",  B_WILL_DRAW);
	eq20_9val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_9val);
	eq20_10val = new BStringView(BRect(282,3,305,19), "eq20_10val","256",  B_WILL_DRAW);
	eq20_10val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_10val);
	eq20_11val = new BStringView(BRect(312,3,335,19), "eq20_11val","256",  B_WILL_DRAW);
	eq20_11val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_11val);
	eq20_12val = new BStringView(BRect(342,3,365,19), "eq20_12val","256",  B_WILL_DRAW);
	eq20_12val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_12val);
	eq20_13val = new BStringView(BRect(372,3,395,19), "eq20_13val","256",  B_WILL_DRAW);
	eq20_13val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_13val);
	eq20_14val = new BStringView(BRect(402,3,425,19), "eq20_14val","256",  B_WILL_DRAW);
	eq20_14val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_14val);
	eq20_15val = new BStringView(BRect(432,3,455,19), "eq20_15val","256",  B_WILL_DRAW);
	eq20_15val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_15val);
	eq20_16val = new BStringView(BRect(462,3,485,19), "eq20_16val","256",  B_WILL_DRAW);
	eq20_16val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_16val);
	eq20_17val = new BStringView(BRect(492,3,515,19), "eq20_17val","256",  B_WILL_DRAW);
	eq20_17val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_17val);
	eq20_18val = new BStringView(BRect(522,3,545,19), "eq20_18val","256",  B_WILL_DRAW);
	eq20_18val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_18val);
	eq20_19val = new BStringView(BRect(552,3,575,19), "eq20_19val","256",  B_WILL_DRAW);
	eq20_19val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_19val);
	eq20_20val = new BStringView(BRect(582,3,605,19), "eq20_20val","256",  B_WILL_DRAW);
	eq20_20val->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_20val);

	// eq1 ScrollBars(672,170,600,186)
	eq20_0lev = new EQ20_0(BRect(0,0,0,0));
	eq20view->AddChild(eq20_0lev);
	eq20_1lev = new EQ20_1(BRect(15,20,29,160));
	eq20view->AddChild(eq20_1lev);
	eq20_2lev = new EQ20_2(BRect(45,20,59,160));
	eq20view->AddChild(eq20_2lev);
	eq20_3lev = new EQ20_3(BRect(75,20,89,160));
	eq20view->AddChild(eq20_3lev);
	eq20_4lev = new EQ20_4(BRect(105,20,119,160));
	eq20view->AddChild(eq20_4lev);
	eq20_5lev = new EQ20_5(BRect(135,20,149,160));
	eq20view->AddChild(eq20_5lev);
	eq20_6lev = new EQ20_6(BRect(165,20,179,160));
	eq20view->AddChild(eq20_6lev);
	eq20_7lev = new EQ20_7(BRect(195,20,209,160));
	eq20view->AddChild(eq20_7lev);
	eq20_8lev = new EQ20_8(BRect(195,20,209,160));
	eq20view->AddChild(eq20_8lev);
	eq20_9lev = new EQ20_9(BRect(195,20,209,160));
	eq20view->AddChild(eq20_9lev);
	eq20_10lev = new EQ20_10(BRect(195,20,209,160));
	eq20view->AddChild(eq20_10lev);
	eq20_11lev = new EQ20_11(BRect(195,20,209,160));
	eq20view->AddChild(eq20_11lev);
	eq20_12lev = new EQ20_12(BRect(195,20,209,160));
	eq20view->AddChild(eq20_12lev);
	eq20_13lev = new EQ20_13(BRect(195,20,209,160));
	eq20view->AddChild(eq20_13lev);
	eq20_14lev = new EQ20_14(BRect(195,20,209,160));
	eq20view->AddChild(eq20_14lev);
	eq20_15lev = new EQ20_15(BRect(195,20,209,160));
	eq20view->AddChild(eq20_15lev);
	eq20_16lev = new EQ20_16(BRect(195,20,209,160));
	eq20view->AddChild(eq20_16lev);
	eq20_17lev = new EQ20_17(BRect(195,20,209,160));
	eq20view->AddChild(eq20_17lev);
	eq20_18lev = new EQ20_18(BRect(195,20,209,160));
	eq20view->AddChild(eq20_18lev);
	eq20_19lev = new EQ20_19(BRect(195,20,209,160));
	eq20view->AddChild(eq20_19lev);
	eq20_20lev = new EQ20_20(BRect(195,20,209,160));
	eq20view->AddChild(eq20_20lev);


	eq20_0string = new BStringView(BRect(330,187,390,201), "eq20_0string","Level",  B_WILL_DRAW);
	eq20_0string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_0string);
	eq20_1string = new BStringView(BRect(10,160,39,180), "eq20_1string","Sub",  B_WILL_DRAW);
	eq20_1string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_1string);
	eq20_2string = new BStringView(BRect(40,160,69,180), "eq20_2string","Bass",  B_WILL_DRAW);
	eq20_2string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_2string);
	eq20_3string = new BStringView(BRect(70,160,99,180), "eq20_3string","LMid",  B_WILL_DRAW);
	eq20_3string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_3string);
	eq20_4string = new BStringView(BRect(100,160,129,180), "eq20_4string","Mid",  B_WILL_DRAW);
	eq20_4string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_4string);
	eq20_5string = new BStringView(BRect(130,160,159,180), "eq20_5string","HMid",  B_WILL_DRAW);
	eq20_5string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_5string);
	eq20_6string = new BStringView(BRect(160,160,189,180), "eq20_6string","High",  B_WILL_DRAW);
	eq20_6string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_6string);
	eq20_7string = new BStringView(BRect(190,160,229,180), "eq20_7string","VHigh",  B_WILL_DRAW);
	eq20_7string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_7string);
	eq20_8string = new BStringView(BRect(190,160,229,180), "eq20_8string","VHigh",  B_WILL_DRAW);
	eq20_8string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_8string);
	eq20_9string = new BStringView(BRect(190,160,229,180), "eq20_9string","VHigh",  B_WILL_DRAW);
	eq20_9string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_9string);
	eq20_10string = new BStringView(BRect(190,160,229,180), "eq20_10string","VHigh",  B_WILL_DRAW);
	eq20_10string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_10string);
	eq20_11string = new BStringView(BRect(190,160,229,180), "eq20_11string","VHigh",  B_WILL_DRAW);
	eq20_11string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_11string);
	eq20_12string = new BStringView(BRect(190,160,229,180), "eq20_12string","VHigh",  B_WILL_DRAW);
	eq20_12string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_12string);
	eq20_13string = new BStringView(BRect(190,160,229,180), "eq20_13string","VHigh",  B_WILL_DRAW);
	eq20_13string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_13string);
	eq20_14string = new BStringView(BRect(190,160,229,180), "eq20_14string","VHigh",  B_WILL_DRAW);
	eq20_14string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_14string);
	eq20_15string = new BStringView(BRect(190,160,229,180), "eq20_15string","VHigh",  B_WILL_DRAW);
	eq20_15string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_15string);
	eq20_16string = new BStringView(BRect(190,160,229,180), "eq20_16string","VHigh",  B_WILL_DRAW);
	eq20_16string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_16string);
	eq20_17string = new BStringView(BRect(190,160,229,180), "eq20_17string","VHigh",  B_WILL_DRAW);
	eq20_17string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_17string);
	eq20_18string = new BStringView(BRect(190,160,229,180), "eq20_18string","VHigh",  B_WILL_DRAW);
	eq20_18string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_18string);
	eq20_19string = new BStringView(BRect(190,160,229,180), "eq20_19string","VHigh",  B_WILL_DRAW);
	eq20_19string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_19string);
	eq20_20string = new BStringView(BRect(190,160,229,180), "eq20_20string","VHigh",  B_WILL_DRAW);
	eq20_20string->SetHighColor(0,0,0); // text to Black
	eq20view->AddChild(eq20_20string);

	eq20min = new BButton(BRect(10,179,44,192), "min", "MIN",	new BMessage(EQ20_MIN));
	eq20view->AddChild(eq20min);
	eq20mid = new BButton(BRect(50,179,84,192), "mid", "MID",	new BMessage(EQ20_MID));
	eq20view->AddChild(eq20mid);
	eq20max = new BButton(BRect(90,179,124,192), "max", "MAX",	new BMessage(EQ20_MAX));
	eq20view->AddChild(eq20max);

	// show the window
	AddChild(eq20view);
	Show();
	SetFlags(B_NOT_RESIZABLE | B_NOT_ZOOMABLE);

	eq20changed = 0;

	eq20listtype	= 1;
	eq20listnumber	= 1;
	eq20fxtype		= 1;
	eq20fxnumber	= 81;
}

//====================================================================================================

EQ20::~EQ20(void) // Destructor
{

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void EQ20::Updateeq20(void)	// Scroll bar has changed
{

sprintf(eq20_0txt,"%d ",eq20vals[0]);
sprintf(eq20_1txt,"%d ",eq20vals[1]);
sprintf(eq20_2txt,"%d ",eq20vals[2]);
sprintf(eq20_3txt,"%d ",eq20vals[3]);
sprintf(eq20_4txt,"%d ",eq20vals[4]);
sprintf(eq20_5txt,"%d ",eq20vals[5]);
sprintf(eq20_6txt,"%d ",eq20vals[6]);
sprintf(eq20_7txt,"%d ",eq20vals[7]);
sprintf(eq20_8txt,"%d ",eq20vals[8]);
sprintf(eq20_9txt,"%d ",eq20vals[9]);
sprintf(eq20_10txt,"%d ",eq20vals[10]);
sprintf(eq20_11txt,"%d ",eq20vals[11]);
sprintf(eq20_12txt,"%d ",eq20vals[12]);
sprintf(eq20_13txt,"%d ",eq20vals[13]);
sprintf(eq20_14txt,"%d ",eq20vals[14]);
sprintf(eq20_15txt,"%d ",eq20vals[15]);
sprintf(eq20_16txt,"%d ",eq20vals[16]);
sprintf(eq20_17txt,"%d ",eq20vals[17]);
sprintf(eq20_18txt,"%d ",eq20vals[18]);
sprintf(eq20_19txt,"%d ",eq20vals[19]);
sprintf(eq20_20txt,"%d ",eq20vals[20]);

Lock();
if (eq20changed == 0)	eq20_0val->SetText(eq20_0txt);
if (eq20changed == 1)	eq20_1val->SetText(eq20_1txt);
if (eq20changed == 2)	eq20_2val->SetText(eq20_2txt);
if (eq20changed == 3)	eq20_3val->SetText(eq20_3txt);
if (eq20changed == 4)	eq20_4val->SetText(eq20_4txt);
if (eq20changed == 5)	eq20_5val->SetText(eq20_5txt);
if (eq20changed == 6)	eq20_6val->SetText(eq20_6txt);
if (eq20changed == 7)	eq20_7val->SetText(eq20_7txt);
if (eq20changed == 8)	eq20_8val->SetText(eq20_8txt);
if (eq20changed == 9)	eq20_9val->SetText(eq20_9txt);
if (eq20changed == 10)	eq20_10val->SetText(eq20_10txt);
if (eq20changed == 11)	eq20_11val->SetText(eq20_11txt);
if (eq20changed == 12)	eq20_12val->SetText(eq20_12txt);
if (eq20changed == 13)	eq20_13val->SetText(eq20_13txt);
if (eq20changed == 14)	eq20_14val->SetText(eq20_14txt);
if (eq20changed == 15)	eq20_15val->SetText(eq20_15txt);
if (eq20changed == 16)	eq20_16val->SetText(eq20_16txt);
if (eq20changed == 17)	eq20_17val->SetText(eq20_17txt);
if (eq20changed == 18)	eq20_18val->SetText(eq20_18txt);
if (eq20changed == 19)	eq20_19val->SetText(eq20_19txt);
if (eq20changed == 20)	eq20_20val->SetText(eq20_20txt);

Unlock();
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void EQ20::Updatealleq20(void)	// All Scroll bars have changed
{
int16 temp;

sprintf(eq20_0txt,"%d ",eq20vals[0]);
sprintf(eq20_1txt,"%d ",eq20vals[1]);
sprintf(eq20_2txt,"%d ",eq20vals[2]);
sprintf(eq20_3txt,"%d ",eq20vals[3]);
sprintf(eq20_4txt,"%d ",eq20vals[4]);
sprintf(eq20_5txt,"%d ",eq20vals[5]);
sprintf(eq20_6txt,"%d ",eq20vals[6]);
sprintf(eq20_7txt,"%d ",eq20vals[7]);
sprintf(eq20_8txt,"%d ",eq20vals[8]);
sprintf(eq20_9txt,"%d ",eq20vals[9]);
sprintf(eq20_10txt,"%d ",eq20vals[10]);
sprintf(eq20_11txt,"%d ",eq20vals[11]);
sprintf(eq20_12txt,"%d ",eq20vals[12]);
sprintf(eq20_13txt,"%d ",eq20vals[13]);
sprintf(eq20_14txt,"%d ",eq20vals[14]);
sprintf(eq20_15txt,"%d ",eq20vals[15]);
sprintf(eq20_16txt,"%d ",eq20vals[16]);
sprintf(eq20_17txt,"%d ",eq20vals[17]);
sprintf(eq20_18txt,"%d ",eq20vals[18]);
sprintf(eq20_19txt,"%d ",eq20vals[19]);
sprintf(eq20_20txt,"%d ",eq20vals[20]);

Lock();
eq20_0val->SetText(eq20_0txt);
eq20_1val->SetText(eq20_1txt);
eq20_2val->SetText(eq20_2txt);
eq20_3val->SetText(eq20_3txt);
eq20_4val->SetText(eq20_4txt);
eq20_5val->SetText(eq20_5txt);
eq20_6val->SetText(eq20_6txt);
eq20_7val->SetText(eq20_7txt);
eq20_8val->SetText(eq20_8txt);
eq20_9val->SetText(eq20_9txt);
eq20_10val->SetText(eq20_10txt);
eq20_11val->SetText(eq20_11txt);
eq20_12val->SetText(eq20_12txt);
eq20_13val->SetText(eq20_13txt);
eq20_14val->SetText(eq20_14txt);
eq20_15val->SetText(eq20_15txt);
eq20_16val->SetText(eq20_16txt);
eq20_17val->SetText(eq20_17txt);
eq20_18val->SetText(eq20_18txt);
eq20_19val->SetText(eq20_19txt);
eq20_20val->SetText(eq20_20txt);
temp=eq20vals[0];
eq20_0lev->SetValue(temp);
temp=256-eq20vals[1];
eq20_1lev->SetValue(temp);
temp=256-eq20vals[2];
eq20_2lev->SetValue(temp);
temp=256-eq20vals[3];
eq20_3lev->SetValue(temp);
temp=256-eq20vals[4];
eq20_4lev->SetValue(temp);
temp=256-eq20vals[5];
eq20_5lev->SetValue(temp);
temp=256-eq20vals[6];
eq20_6lev->SetValue(temp);
temp=256-eq20vals[7];
eq20_7lev->SetValue(temp);
temp=256-eq20vals[8];
eq20_8lev->SetValue(temp);
temp=256-eq20vals[9];
eq20_9lev->SetValue(temp);
temp=256-eq20vals[10];
eq20_10lev->SetValue(temp);
temp=256-eq20vals[11];
eq20_11lev->SetValue(temp);
temp=256-eq20vals[12];
eq20_12lev->SetValue(temp);
temp=256-eq20vals[13];
eq20_13lev->SetValue(temp);
temp=256-eq20vals[14];
eq20_14lev->SetValue(temp);
temp=256-eq20vals[15];
eq20_15lev->SetValue(temp);
temp=256-eq20vals[16];
eq20_16lev->SetValue(temp);
temp=256-eq20vals[17];
eq20_17lev->SetValue(temp);
temp=256-eq20vals[18];
eq20_18lev->SetValue(temp);
temp=256-eq20vals[19];
eq20_19lev->SetValue(temp);
temp=256-eq20vals[20];
eq20_20lev->SetValue(temp);
Unlock();
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void EQ20::Minmaxeq20(int32 type)	// Min, Mid or Max clicked
{
if (type == 1)
	{
	eq20vals[1]=0;
	eq20vals[2]=0;
	eq20vals[3]=0;
	eq20vals[4]=0;
	eq20vals[5]=0;
	eq20vals[6]=0;
	eq20vals[7]=0;
	eq20vals[8]=0;
	eq20vals[9]=0;
	eq20vals[10]=0;
	eq20vals[11]=0;
	eq20vals[12]=0;
	eq20vals[13]=0;
	eq20vals[14]=0;
	eq20vals[15]=0;
	eq20vals[16]=0;
	eq20vals[17]=0;
	eq20vals[18]=0;
	eq20vals[19]=0;
	eq20vals[20]=0;
	}
if (type == 2)
	{
	eq20vals[1]=128;
	eq20vals[2]=128;
	eq20vals[3]=128;
	eq20vals[4]=128;
	eq20vals[5]=128;
	eq20vals[6]=128;
	eq20vals[7]=128;
	eq20vals[8]=128;
	eq20vals[9]=128;
	eq20vals[10]=128;
	eq20vals[11]=128;
	eq20vals[12]=128;
	eq20vals[13]=128;
	eq20vals[14]=128;
	eq20vals[15]=128;
	eq20vals[16]=128;
	eq20vals[17]=128;
	eq20vals[18]=128;
	eq20vals[19]=128;
	eq20vals[20]=128;
	}
if (type == 3)
	{
	eq20vals[1]=256;
	eq20vals[2]=256;
	eq20vals[3]=256;
	eq20vals[4]=256;
	eq20vals[5]=256;
	eq20vals[6]=256;
	eq20vals[7]=256;
	eq20vals[8]=256;
	eq20vals[9]=256;
	eq20vals[10]=256;
	eq20vals[11]=256;
	eq20vals[12]=256;
	eq20vals[13]=256;
	eq20vals[14]=256;
	eq20vals[15]=256;
	eq20vals[16]=256;
	eq20vals[17]=256;
	eq20vals[18]=256;
	eq20vals[19]=256;
	eq20vals[20]=256;
	}
Updatealleq20();
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

bool EQ20::QuitRequested(void)
{
BMessage *msg = new BMessage(IW_CLOSED);
msg->AddInt16("iewtyp", 1);	// EQ20 closed
be_app->PostMessage(msg,be_app);
delete (msg);

return (1);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void EQ20::MessageReceived(BMessage* msg)
{
//msg->PrintToStream();
//BWindow::MessageReceived(msg);

switch(msg->what)
	{
	case EQ20_MIN:	// Set sliders to 0
	Minmaxeq20(1);
	break;

	case EQ20_MID:	// Set sliders to 128
	Minmaxeq20(2);
	break;

	case EQ20_MAX:	// Set sliders to 256
	Minmaxeq20(3);
	break;

// Messages from other windows

	case IAP_SET:	// New Settings
	msg->FindInt16("iewmsgtyp", &eq20iewmsgtyp);
//	msg->FindInt32("listtype", &eq20listtype);
//	msg->FindInt32("listnumber", &eq20listnumber);
//	msg->FindInt32("fxtype", &eq20fxtype);
//	msg->FindInt32("fxnumber", &eq20fxnumber);
	msg->FindInt16("iewtyp", &eq20iewtyp);
	if (eq20iewtyp == 1)
		{
		msg->FindInt16("eq0lev", &eq20vals[0]);
		msg->FindInt16("eq1lev", &eq20vals[1]);
		msg->FindInt16("eq2lev", &eq20vals[2]);
		msg->FindInt16("eq3lev", &eq20vals[3]);
		msg->FindInt16("eq4lev", &eq20vals[4]);
		msg->FindInt16("eq5lev", &eq20vals[5]);
		msg->FindInt16("eq6lev", &eq20vals[6]);
		msg->FindInt16("eq7lev", &eq20vals[7]);
		msg->FindInt16("eq8lev", &eq20vals[8]);
		msg->FindInt16("eq9lev", &eq20vals[9]);
		msg->FindInt16("eq10lev", &eq20vals[10]);
		msg->FindInt16("eq11lev", &eq20vals[11]);
		msg->FindInt16("eq12lev", &eq20vals[12]);
		msg->FindInt16("eq13lev", &eq20vals[13]);
		msg->FindInt16("eq14lev", &eq20vals[14]);
		msg->FindInt16("eq15lev", &eq20vals[15]);
		msg->FindInt16("eq16lev", &eq20vals[16]);
		msg->FindInt16("eq17lev", &eq20vals[17]);
		msg->FindInt16("eq18lev", &eq20vals[18]);
		msg->FindInt16("eq19lev", &eq20vals[19]);
		msg->FindInt16("eq20lev", &eq20vals[20]);
		}
	eq20iewtyp = 1;
	Updatealleq20();
	break;

	case IAP_NEWVAL:	// New Val in EQ20
//	msg->FindInt32("listtype", &eq20listtype);
//	msg->FindInt32("listnumber", &eq20listnumber);
//	msg->FindInt32("fxtype", &eq20fxtype);
//	msg->FindInt32("fxnumber", &eq20fxnumber);
	msg->FindInt16("iewtyp", &eq20iewtyp);
	msg->FindInt16("iewmsgtyp", &eq20iewmsgtyp);
	Updateeq20();
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

// OVERRIDES FOR SCROLL BARS 

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_0::EQ20_0(BRect R)
	: BScrollBar(BRect(400,187,560,201),"eq0",NULL,0,1024,B_HORIZONTAL)

{
}
//****************************************************************************************************
void EQ20_0::MessageReceived(BMessage* msg)
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
void EQ20_0::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = eq20num;
eq20vals[0] = eq20num;
eq20changed=0;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_1::EQ20_1(BRect R)
	: BScrollBar(BRect(15,20,29,160),"eq1",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_1::MessageReceived(BMessage* msg)
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
void EQ20_1::ValueChanged(float value)
{
eq20num = (int16)Value();
eq20num = 256 - eq20num;
eq20vals[1] = eq20num;
eq20changed=1;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_2::EQ20_2(BRect R)
	: BScrollBar(BRect(45,20,59,160),"eq2",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_2::MessageReceived(BMessage* msg)
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
void EQ20_2::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[2] = eq20num;
eq20changed=2;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_3::EQ20_3(BRect R)
	: BScrollBar(BRect(75,20,89,160),"eq3",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_3::MessageReceived(BMessage* msg)
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
void EQ20_3::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[3] = eq20num;
eq20changed=3;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_4::EQ20_4(BRect R)
	: BScrollBar(BRect(105,20,119,160),"eq4",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_4::MessageReceived(BMessage* msg)
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
void EQ20_4::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[4] = eq20num;
eq20changed=4;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_5::EQ20_5(BRect R)
	: BScrollBar(BRect(135,20,149,160),"eq5",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_5::MessageReceived(BMessage* msg)
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
void EQ20_5::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[5] = eq20num;
eq20changed=5;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_6::EQ20_6(BRect R)
	: BScrollBar(BRect(165,20,179,160),"eq6",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_6::MessageReceived(BMessage* msg)
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
void EQ20_6::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[6] = eq20num;
eq20changed=6;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 0=slider change 1=Send to Effector 2 settings for window only
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_7::EQ20_7(BRect R)
	: BScrollBar(BRect(195,20,209,160),"eq20",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_7::MessageReceived(BMessage* msg)
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
void EQ20_7::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[7] = eq20num;
eq20changed=7;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_8::EQ20_8(BRect R)
	: BScrollBar(BRect(225,20,239,160),"eq8",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_8::MessageReceived(BMessage* msg)
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
void EQ20_8::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[8] = eq20num;
eq20changed=8;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_9::EQ20_9(BRect R)
	: BScrollBar(BRect(255,20,269,160),"eq9",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_9::MessageReceived(BMessage* msg)
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
void EQ20_9::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[9] = eq20num;
eq20changed=9;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_10::EQ20_10(BRect R)
	: BScrollBar(BRect(285,20,299,160),"eq10",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_10::MessageReceived(BMessage* msg)
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
void EQ20_10::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[10] = eq20num;
eq20changed=10;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_11::EQ20_11(BRect R)
	: BScrollBar(BRect(315,20,329,160),"eq11",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_11::MessageReceived(BMessage* msg)
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
void EQ20_11::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[11] = eq20num;
eq20changed=11;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_12::EQ20_12(BRect R)
	: BScrollBar(BRect(345,20,359,160),"eq12",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_12::MessageReceived(BMessage* msg)
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
void EQ20_12::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[12] = eq20num;
eq20changed=12;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_13::EQ20_13(BRect R)
	: BScrollBar(BRect(375,20,389,160),"eq13",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_13::MessageReceived(BMessage* msg)
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
void EQ20_13::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[13] = eq20num;
eq20changed=13;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_14::EQ20_14(BRect R)
	: BScrollBar(BRect(405,20,419,160),"eq14",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_14::MessageReceived(BMessage* msg)
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
void EQ20_14::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[14] = eq20num;
eq20changed=14;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_15::EQ20_15(BRect R)
	: BScrollBar(BRect(435,20,449,160),"eq15",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_15::MessageReceived(BMessage* msg)
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
void EQ20_15::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[15] = eq20num;
eq20changed=15;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_16::EQ20_16(BRect R)
	: BScrollBar(BRect(465,20,479,160),"eq16",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_16::MessageReceived(BMessage* msg)
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
void EQ20_16::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[16] = eq20num;
eq20changed=16;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_17::EQ20_17(BRect R)
	: BScrollBar(BRect(495,20,509,160),"eq17",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_17::MessageReceived(BMessage* msg)
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
void EQ20_17::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[17] = eq20num;
eq20changed=17;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_18::EQ20_18(BRect R)
	: BScrollBar(BRect(525,20,539,160),"eq18",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_18::MessageReceived(BMessage* msg)
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
void EQ20_18::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[18] = eq20num;
eq20changed=18;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_19::EQ20_19(BRect R)
	: BScrollBar(BRect(555,20,569,160),"eq19",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_19::MessageReceived(BMessage* msg)
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
void EQ20_19::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[19] = eq20num;
eq20changed=19;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************
EQ20_20::EQ20_20(BRect R)
	: BScrollBar(BRect(585,20,599,160),"eq20",NULL,0,256,B_VERTICAL)

{
}
//****************************************************************************************************
void EQ20_20::MessageReceived(BMessage* msg)
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
void EQ20_20::ValueChanged(float value)
{
eq20num = (int32)Value();
eq20num = 256 - eq20num;
eq20vals[20] = eq20num;
eq20changed=20;

BMessage *msg = new BMessage(IW_NEWVAL);
msg->AddInt32("listtype", eq20listtype);
msg->AddInt32("listnumber", eq20listnumber);
msg->AddInt32("fxtype", eq20fxtype);
msg->AddInt32("fxnumber", eq20fxnumber);
msg->AddInt16("iewmsgtyp", 0);	// 
msg->AddInt16("iewtyp", 1);	//	1=EQ20
msg->AddInt16("eq0lev", eq20vals[0]);
msg->AddInt16("eq1lev", eq20vals[1]);
msg->AddInt16("eq2lev", eq20vals[2]);
msg->AddInt16("eq3lev", eq20vals[3]);
msg->AddInt16("eq4lev", eq20vals[4]);
msg->AddInt16("eq5lev", eq20vals[5]);
msg->AddInt16("eq6lev", eq20vals[6]);
msg->AddInt16("eq7lev", eq20vals[7]);
msg->AddInt16("eq8lev", eq20vals[8]);
msg->AddInt16("eq9lev", eq20vals[9]);
msg->AddInt16("eq10lev", eq20vals[10]);
msg->AddInt16("eq11lev", eq20vals[11]);
msg->AddInt16("eq12lev", eq20vals[12]);
msg->AddInt16("eq13lev", eq20vals[13]);
msg->AddInt16("eq14lev", eq20vals[14]);
msg->AddInt16("eq15lev", eq20vals[15]);
msg->AddInt16("eq16lev", eq20vals[16]);
msg->AddInt16("eq17lev", eq20vals[17]);
msg->AddInt16("eq18lev", eq20vals[18]);
msg->AddInt16("eq19lev", eq20vals[19]);
msg->AddInt16("eq20lev", eq20vals[20]);
be_app->PostMessage(msg,be_app);
delete (msg);
}


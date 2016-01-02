// ALLFX.h
// Copyright (c) Blachford Technology 1999
// 28/4/99


#ifndef _ALLFX_H_
#define _ALLFX_H_

#include <Window.h>

// Predefinitions
class BButton;
class BSlider;
class BRadioButton;
class BStringView;
class BListView;
class BScrollView;
class BMenu;
class BMenuField;


class ALLFX : public BWindow
{
public:
	ALLFX(void);
	~ALLFX(void);

	// Global variables

	char allfxtxt[6][84][9][20];
	int16 allfxvals[6][84][7];
	int8 allfxghosts[6][84][7];
//	int16 allfxmaxvals[6][84][4];
	char allfxboxtxt[6][84][3][50];

	// Functions

	void Clickedallfxwindow(int32 mess_no);
	void Updateallfxwindow(int32 mess_no, int32 fxtype, int32 fxnumber);
	void Drawlist(int16 option, int16 listtype);
	int16 Mapper(int16 option, int16 listtype, int16 listnumber);

	void Setallfxvars(void);
	void Setfxvars(int16 incount);
	void Setcomplexfxvars(int16 incount);
	void Setmanip1vars(int16 incount);
	void Setmanip2vars(int16 incount);
	void Setdualmanipvars(int16 incount);
	void Setstereofxvars(int16 incount);

	void Sendgodata(void);
	void Sendiewdata(int32 whichdata);
	void Setmode(int32 viewmode);
	void Setwindoweffect(void);
	void Sendsetmessage(int16 drawlen);

	void MessageReceived(BMessage *message);

	private:
	BButton* fxgo;
	BButton* fxdefault;
	BButton* fxset;

	BSlider* fxlev1;
	BSlider* fxlev2;
	BSlider* fxlev3;
	BSlider* fxlev4;
	BSlider* fxlev;

	BRadioButton* fxadd1a;
	BRadioButton* fxadd1b;
	BStringView*  fxadd1atxt;
	BStringView*  fxadd1btxt;

	BRadioButton* fxadd2a;
	BRadioButton* fxadd2b;
	BStringView*  fxadd2atxt;
	BStringView*  fxadd2btxt;

	BStringView* fxtextgo;
	BStringView* fxtextgob;
	BStringView* fxtextgoc;

	BStringView* fxlevtxt1;
	BStringView* fxlevtxt2;
	BStringView* fxlevtxt3;
	BStringView* fxlevtxt4;
	BStringView* fxlevtxt;

	BListView*	 fxpick;
	BScrollView* fxpickparent;

	BMenu*  fxmenu;
	BMenuField*  fxtypefield;



};

#endif

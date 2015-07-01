// LOAD.h
// Copyright (c) Blachford Technology 1999
// 30/6/99


#ifndef _LOAD_H_
#define _LOAD_H_

#include "Window.h"


class LOAD : public BWindow
{
public:
	LOAD(void);
	~LOAD(void);

	// Global variables
	char loadboxtxt[6][64][3][50];

	// Functions

	void Clickedloadwindow(int32 mess_no);
	void Updateloadwindow(int32 mess_no, int32 loadtype, int32 loadnumber);
	void Drawlist(int16 option, int16 listtype);
	void Setvars(void);
	void Setloadvars(int16 incount);
	void Setsavevars(int16 incount);
	void Loaddata(void);
	void Savedata(void);
	void Updatedonebox(int16 drawmode, int16 drawmax, int16 drawnum);

	void MessageReceived(BMessage *message);

	BFilePanel* loadfilepanel;
//	entry_ref* ref;
	BFilePanel* savefilepanel;
//	entry_ref* directory;

	private:
	BButton* loadgo;
	BButton* loadclose;
	BButton* loaddefault;
	BButton* loadset;

	BRadioButton* loadadd1a;
	BRadioButton* loadadd1b;
	BRadioButton* loadadd1c;
	BRadioButton* loadadd1d;
	BRadioButton* loadadd1e;

	BRadioButton* loadadd2a;
	BRadioButton* loadadd2b;
	BRadioButton* loadadd2c;
	BRadioButton* loadadd2d;
	BRadioButton* loadadd2e;

	BRadioButton* loadrng;
	BRadioButton* loadall;

	BStringView* loadtext1;
	BStringView* loadtext2;
	BStringView* loadtext3;
	BStringView* loadtext4;

	BStringView* loadtextgo;
	BStringView* loadtextgob;
	BStringView* loadtextgoc;

	BListView*	 loadpick;
	BScrollView* loadpickparent;

};

#endif
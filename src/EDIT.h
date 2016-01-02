// EDIT.h
// Copyright (c) Blachford Technology 1999
// 28/4/99

#ifndef _EDIT_H_
#define _EDIT_H_

#include <Window.h>
#include <View.h>

// Predefinitions
class BButton;
class BCheckBox;
class BStringView;
class BRadioButton;
class BSlider;

class EDIT : public BWindow
{
public:
	EDIT(void);
	~EDIT(void);

	void Updateeditwindow(int32 mess_no);
	void MessageReceived(BMessage *message);
	void Drawdrawbar(int16 mode, int16 draw1, int16 draw2, int16 draw3, int16 draw4, int16 draw5);
	//virtual void Draw( BRect updateRect );

	BButton* go;
	BButton* undo;

	BButton* zoomin;
	BButton* zoomout;
	BButton* start;
	BButton* fastback;
	BButton* back;
	BButton* forward;
	BButton* fastforward;
	BButton* end;

	BCheckBox* draw;
	BCheckBox* loop;

	BStringView* messageboxstring;

	BButton* cut;
	BButton* setzone;
	BButton* playview;
	BButton* showrng;
	BButton* rangeall;

	BButton* copy;
	BButton* zoneinto;
	BButton* playrange;
	BButton* showall;
	BButton* zero;

	BButton* pasteinto;
	BButton* zoneover;
	BButton* playall;
	BButton* movezone;
	BButton* rescale;

	BButton* pasteover;
	BButton* lr;
	BButton* rl;
	BButton* playloop;
	BButton* redraw;
	BButton* scale;

	BRadioButton* mono;
	BRadioButton* stereo;
	BRadioButton* right;
	BRadioButton* left;

	BSlider* scaleval;
	BSlider* rate;
	BSlider* mag;

	BStringView* cusrtext;
	BStringView* rangetext;
	BStringView* zonetext;

	BStringView* cusrvaltext;
	BStringView* rangevaltext;
	BStringView* zonevaltext;

};

class ProgressView: public BView
{
	public:

	ProgressView( BRect frame );
	virtual ~ProgressView();

	virtual void Draw( BRect updateRect );
};

#endif

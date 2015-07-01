// ATTRACT.h
// Copyright (c) Blachford Technology 1999
// 7/6/99

#include <Window.h>
#include <View.h>

// Globals defined in ATTRACTVars.h


class ATTRACT : public BWindow
{
public:
 	ATTRACT();
	~ATTRACT(void);
	
	int32 makechans;
	float fheight;
	float fwidth;

	int16 *sampoint;
	int32 halfmemsize;
	int32 rngstrval;
	int32 rnglenval;
	int32 atsamcount;

	void *point;
	int32 asamhalfmemsize;
	int32 asamrngstrval;
	int32 asamrnglenval;
	int32 asammakechans;

// ---------------------------------------------------

	BCheckBox* Lines;
	BCheckBox* Invert;

  	void MessageReceived(BMessage* msg);
	void Dodisplay(void);

 private:

	void Sendmess(int32 messno);
	void FrameResized(float width, float height);
	void Drawsample(void);
	bool QuitRequested(void);
};


//****************************************************************************************************


class AttractView : public BView
{
 public:
 	// overridden BView functions 
 	AttractView(BRect R);
 	
	void Draw(BRect updateRect);
	void MessageReceived(BMessage* msg);
	
};









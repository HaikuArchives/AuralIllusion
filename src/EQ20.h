// EQ20.h
// Copyright (c) Blachford Technology 1999
// 15/9/99

#include <Window.h>
#include <ScrollBar.h>

// ---------------------------------------------------

class EQ20 : public BWindow
{
public:
 	EQ20();
	~EQ20(void);

char memtxt[50]; // Test message text
int16 *mempoint;
int32 memmemsize;
void *memmovepoint;

  	void MessageReceived(BMessage* msg);

 private:

	void Sendmess(int32 messno);
	void Updateeq20(void);
	void Updatealleq20(void);
	bool QuitRequested(void);
	void Minmaxeq20(int32 type);

	BButton* eq20min;
	BButton* eq20mid;
	BButton* eq20max;
	BScrollBar* eq20_0lev;
	BScrollBar* eq20_1lev;
	BScrollBar* eq20_2lev;
	BScrollBar* eq20_3lev;
	BScrollBar* eq20_4lev;
	BScrollBar* eq20_5lev;
	BScrollBar* eq20_6lev;
	BScrollBar* eq20_7lev;
	BScrollBar* eq20_8lev;
	BScrollBar* eq20_9lev;
	BScrollBar* eq20_10lev;
	BScrollBar* eq20_11lev;
	BScrollBar* eq20_12lev;
	BScrollBar* eq20_13lev;
	BScrollBar* eq20_14lev;
	BScrollBar* eq20_15lev;
	BScrollBar* eq20_16lev;
	BScrollBar* eq20_17lev;
	BScrollBar* eq20_18lev;
	BScrollBar* eq20_19lev;
	BScrollBar* eq20_20lev;
};

// *********************************************************

class EQ20_0 : public BScrollBar
{
 public:
 	EQ20_0(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_1 : public BScrollBar
{
 public:
 	EQ20_1(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_2 : public BScrollBar
{
 public:
 	EQ20_2(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_3 : public BScrollBar
{
 public:
 	EQ20_3(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_4 : public BScrollBar
{
 public:
 	EQ20_4(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_5 : public BScrollBar
{
 public:
 	EQ20_5(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_6 : public BScrollBar
{
 public:
 	EQ20_6(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_7 : public BScrollBar
{
 public:
 	EQ20_7(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_8 : public BScrollBar
{
 public:
 	EQ20_8(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_9 : public BScrollBar
{
 public:
 	EQ20_9(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_10 : public BScrollBar
{
 public:
 	EQ20_10(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_11 : public BScrollBar
{
 public:
 	EQ20_11(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_12 : public BScrollBar
{
 public:
 	EQ20_12(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_13 : public BScrollBar
{
 public:
 	EQ20_13(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_14 : public BScrollBar
{
 public:
 	EQ20_14(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_15 : public BScrollBar
{
 public:
 	EQ20_15(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_16 : public BScrollBar
{
 public:
 	EQ20_16(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_17 : public BScrollBar
{
 public:
 	EQ20_17(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_18 : public BScrollBar
{
 public:
 	EQ20_18(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_19 : public BScrollBar
{
 public:
 	EQ20_19(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ20_20 : public BScrollBar
{
 public:
 	EQ20_20(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};


// EQ7.h
// Copyright (c) Blachford Technology 1999
// 15/9/99

#include <Window.h>
#include <ScrollBar.h>

// ---------------------------------------------------

class EQ7 : public BWindow
{
public:
 	EQ7();
	~EQ7(void);

char memtxt[50]; // Test message text
int16 *mempoint;
int32 memmemsize;
void *memmovepoint;

  	void MessageReceived(BMessage* msg);

 private:

	void Sendmess(int32 messno);
	void Updateeq7(void);
	void Updatealleq7(void);
	bool QuitRequested(void);

	BButton* memok;
	BScrollBar* eq1lev;
	BScrollBar* eq2lev;
	BScrollBar* eq3lev;
	BScrollBar* eq4lev;
	BScrollBar* eq5lev;
	BScrollBar* eq6lev;
	BScrollBar* eq7lev;
};

// *********************************************************

class EQ1 : public BScrollBar
{
 public:
 	EQ1(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ2 : public BScrollBar
{
 public:
 	EQ2(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ3 : public BScrollBar
{
 public:
 	EQ3(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ4 : public BScrollBar
{
 public:
 	EQ4(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ5 : public BScrollBar
{
 public:
 	EQ5(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ6 : public BScrollBar
{
 public:
 	EQ6(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};

// *********************************************************

class EQ7s : public BScrollBar
{
 public:
 	EQ7s(BRect R);// overridden BView functions
	void MessageReceived(BMessage* msg);
	virtual void ValueChanged(float value);
};









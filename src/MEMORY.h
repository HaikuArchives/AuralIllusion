// MEMORY.h
// Copyright (c) Blachford Technology 1999
// 7/6/99

#include <Window.h>

// ---------------------------------------------------

class MEMORY : public BWindow
{
public:
 	MEMORY();
	~MEMORY(void);

char memtxt[50]; // Test message text
int16 *mempoint;
int32 memmemsize;
void *memmovepoint;

  	void MessageReceived(BMessage* msg);

 private:

	void Sendmess(int32 messno);
	void Setupmemory(void);
	void Displaymemory(void);
	void Oops(void);
	bool QuitRequested(void);

	BButton* memok;
	BSlider* memlev;
	BRadioButton* small;
	BRadioButton* medium;
	BRadioButton* large;
};









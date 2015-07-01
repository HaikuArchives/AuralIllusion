//      Aural illusion v4.0  Edits 

//      SAMPLE_fxedit.cpp

//      copyright (c) Blachford Technology  21/6/99

#include "SAMPLEWindow.h"

/*****************************************************************/
// Functions

//	

/*****************************************************************/

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::DoEdit(void) // Call Edits
{
done=0;
if (samfxnumber == 0)	// Zero All - Menu option
	{
	Copyrng(0);
	}
if (samfxnumber == 1)	// editcut
	{
	Copyrng(3);
	}
if (samfxnumber == 2)	// editcopy
	{
	Copyrng(4);
	}
if (samfxnumber == 3)	// editpasteinto
	{
	Copyrng(6);
	}
if (samfxnumber == 4)	// editpasteover
	{
	Copyrng(5);
	}
if (samfxnumber == 6)	// editzoneinto
	{
	Copyrng(8);
	}
if (samfxnumber == 7)	// editzoneover
	{
	Copyrng(7);
	}
if (samfxnumber == 8)	// editlr
	{
	Copyrng(1);
	}
if (samfxnumber == 9)	// editrl
	{
	Copyrng(2);
	}
if (samfxnumber == 16)	// editmovezone
	{
	Copyrng(9);
	}
if (samfxnumber == 19)	// editzero
	{
	Zerorng();
	Drawdonebox(0);
	if (makechans==2)
		{
		Drawdonebox(0);
		samstart=samstartb;
		samend=samendb;
		memdivtodo=memdiv+samstart;
		done=0;
		Zerorng();
		}
	}
if (samfxnumber == 20)	// editrescale
	{
	Rescalerng();
	if (makechans==2)
		{
		Drawdonebox(0);
		samstart=samstartb;
		samend=samendb;
		memdivtodo=memdiv+samstart;
		done=0;
		Rescalerng();
		}
	}
if (samfxnumber == 21)	// editscale
	{
	Scalerng();
	if (makechans==2)
		{
		Drawdonebox(0);
		samstart=samstartb;
		samend=samendb;
		memdivtodo=memdiv+samstart;
		done=0;
		Scalerng();
		}
	}
if (samfxnumber == 22)	// editundo
	{
	Doundo(1);
	}
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::Doundo(int32 undo)
{
double bigtemp1;
double bigtemp2;
double bigtemp3;
double bigtemp4;
double bigtemp5;
double bigtemp6;
double bigtemp7;
double bigtemp8;
double bigtempb1;
double bigtempb2;
double bigtempb3;
double bigtempb4;
double bigtempb5;
double bigtempb6;
double bigtempb7;
double bigtempb8;
double *bigpoint;
uint32 smallmemsize;

uint32 umemdiv;
uint32 umemdivtodo;

smallmemsize=memsize >> 2;	// value of memsize in 64 bit words
bigpoint=(double *)sampoint;

umemdiv=smallmemsize/10;
umemdivtodo=umemdiv;

if (undo == 0)	// UNDO - copy to undo buffer
	{
	for (samcount=0;samcount<=smallmemsize;samcount=samcount+8)
		{
		bigtemp1=*(bigpoint+samcount);
		bigtemp2=*(bigpoint+samcount+1);
		bigtemp3=*(bigpoint+samcount+2);
		bigtemp4=*(bigpoint+samcount+3);
		bigtemp5=*(bigpoint+samcount+4);
		bigtemp6=*(bigpoint+samcount+5);
		bigtemp7=*(bigpoint+samcount+6);
		bigtemp8=*(bigpoint+samcount+7);
		*(bigpoint+samcount+smallmemsize)=bigtemp1;
		*(bigpoint+samcount+smallmemsize+1)=bigtemp2;
		*(bigpoint+samcount+smallmemsize+2)=bigtemp3;
		*(bigpoint+samcount+smallmemsize+3)=bigtemp4;
		*(bigpoint+samcount+smallmemsize+4)=bigtemp5;
		*(bigpoint+samcount+smallmemsize+5)=bigtemp6;
		*(bigpoint+samcount+smallmemsize+6)=bigtemp7;
		*(bigpoint+samcount+smallmemsize+7)=bigtemp8;
		}
	}

else if (undo == 1)	// REDO - swap from undo buffer
	{
	for (samcount=0;samcount<=smallmemsize;samcount=samcount+8)
		{
		bigtemp1=*(bigpoint+samcount);
		bigtemp2=*(bigpoint+samcount+1);
		bigtemp3=*(bigpoint+samcount+2);
		bigtemp4=*(bigpoint+samcount+3);
		bigtemp5=*(bigpoint+samcount+4);
		bigtemp6=*(bigpoint+samcount+5);
		bigtemp7=*(bigpoint+samcount+6);
		bigtemp8=*(bigpoint+samcount+7);

		bigtempb1=*(bigpoint+samcount+smallmemsize);
		bigtempb2=*(bigpoint+samcount+smallmemsize+1);
		bigtempb3=*(bigpoint+samcount+smallmemsize+2);
		bigtempb4=*(bigpoint+samcount+smallmemsize+3);
		bigtempb5=*(bigpoint+samcount+smallmemsize+4);
		bigtempb6=*(bigpoint+samcount+smallmemsize+5);
		bigtempb7=*(bigpoint+samcount+smallmemsize+6);
		bigtempb8=*(bigpoint+samcount+smallmemsize+7);

		*(bigpoint+samcount)=bigtempb1;
		*(bigpoint+samcount+1)=bigtempb2;
		*(bigpoint+samcount+2)=bigtempb3;
		*(bigpoint+samcount+3)=bigtempb4;
		*(bigpoint+samcount+4)=bigtempb5;
		*(bigpoint+samcount+5)=bigtempb6;
		*(bigpoint+samcount+6)=bigtempb7;
		*(bigpoint+samcount+7)=bigtempb8;

		*(bigpoint+samcount+smallmemsize)=bigtemp1;
		*(bigpoint+samcount+smallmemsize+1)=bigtemp2;
		*(bigpoint+samcount+smallmemsize+2)=bigtemp3;
		*(bigpoint+samcount+smallmemsize+3)=bigtemp4;
		*(bigpoint+samcount+smallmemsize+4)=bigtemp5;
		*(bigpoint+samcount+smallmemsize+5)=bigtemp6;
		*(bigpoint+samcount+smallmemsize+6)=bigtemp7;
		*(bigpoint+samcount+smallmemsize+7)=bigtemp8;
		}
	}
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// Zero Selected Range

void SAMPLEWindow::Zerorng(void)
{
   for (samcount=samstart;samcount<=samend;samcount++)
     {
     *(sampoint+samcount)=0;
     if (samcount==memdivtodo)
        {
        done++;
        Drawdonebox(done);
        memdivtodo=memdivtodo+memdiv;
        }
     }
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// Scale Selected Range

void SAMPLEWindow::Scalerng(void)
{
int32 temp;
int32 scale;

scale=samslider1*81.92;

   for (samcount=samstart;samcount<=samend;samcount++)
     {
     temp=*(sampoint+samcount);
     temp=temp*scale;
     temp=temp >> 13;
     if (temp>=32766) temp=32766;
     if (temp<=-32766) temp=-32766;
     *(sampoint+samcount)=temp;
     if (samcount==memdivtodo)
        {
        done++;
        Drawdonebox(done);
        memdivtodo=memdivtodo+memdiv;
        }
     }
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// ReScale Selected Range

void SAMPLEWindow::Rescalerng(void)
{
int32 temp;
int32 hival;
int32 loval;
int32 scaleval;

hival=0;
loval=0;
scaleval=0;

for (samcount=samstart;samcount<=samend;samcount++)
	{
	temp=*(sampoint+samcount);
	if (temp>hival) hival=temp;
	if (temp<loval) loval=temp;
	}

temp=~loval;
if (temp>=hival) hival=temp;
hival++;

if (hival>=1)
   {
   scaleval=2147352578/hival;

   for (samcount=samstart;samcount<=samend;samcount++)
     {
     temp=*(sampoint+samcount);
     temp=temp*scaleval;
     temp=temp >> 16;
     if (temp>=32766) temp=32766;
     if (temp<=-32766) temp=-32766;
     *(sampoint+samcount)=temp;
     if (samcount==memdivtodo)
        {
        done++;
        Drawdonebox(done);
        memdivtodo=memdivtodo+memdiv;
        }
     }

   }

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// ReScale Selected Range - no drawing into box

void SAMPLEWindow::Rescalenoboxrng(void)
{
int32 temp;
int32 hival;
int32 loval;
int32 scaleval;

hival=0;
loval=0;
scaleval=0;

   for (samcount=samstart;samcount<=samend;samcount++)
     {
     temp=*(sampoint+samcount);
     if (temp>hival) hival=temp;
     if (temp<loval) loval=temp;
     }

temp=~loval;
if (temp>=hival) hival=temp;
hival++;

if (hival>=1)
   {
   scaleval=2147352578/hival;
   for (samcount=samstart;samcount<=samend;samcount++)
     {
     temp=*(sampoint+samcount);
     temp=temp*scaleval;
     temp=temp >> 16;
     if (temp>=32766) temp=32766;
     if (temp<=-32766) temp=-32766;
     *(sampoint+samcount)=temp;
     }
   }
}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

// Cut Copy & other edit operations

// 0 = Zero All
// 1 = Copy Left to Right
// 2 = Copy Right to Left
// 3 = Cut
// 4 = Copy
// 5 = Paste Over
// 6 = Paste Into
// 7 = Zone Over
// 8 = Zone Into
// 9 = Move Zone

void SAMPLEWindow::Copyrng(int32 opt)
{
int32 copysize;
int32 fullend;
int32 fullstart;
int32 copy;
int32 temp;
int32 zmemdiv;
int32 zmemdivtodo;

if (opt==0)  // Zero All -------------------------------------------------------------
	{
	double bigtemp;
	double *bigpoint;

	*(sampoint)=0;
	*(sampoint+1)=0;
	*(sampoint+2)=0;
	*(sampoint+3)=0;
	bigpoint=(double *)sampoint;
	bigtemp = *(bigpoint);

	done=0;
	fullend=memsize >> 2;
	zmemdiv=fullend / 10;
	zmemdivtodo = zmemdiv;
	for (samcount=0;samcount<=fullend;samcount=samcount+16)
		{
		*(bigpoint+samcount)=bigtemp;
		*(bigpoint+samcount+1)=bigtemp;
		*(bigpoint+samcount+2)=bigtemp;
		*(bigpoint+samcount+3)=bigtemp;
		*(bigpoint+samcount+4)=bigtemp;
		*(bigpoint+samcount+5)=bigtemp;
		*(bigpoint+samcount+6)=bigtemp;
		*(bigpoint+samcount+7)=bigtemp;
		*(bigpoint+samcount+8)=bigtemp;
		*(bigpoint+samcount+9)=bigtemp;
		*(bigpoint+samcount+10)=bigtemp;
		*(bigpoint+samcount+11)=bigtemp;
		*(bigpoint+samcount+12)=bigtemp;
		*(bigpoint+samcount+13)=bigtemp;
		*(bigpoint+samcount+14)=bigtemp;
		*(bigpoint+samcount+15)=bigtemp;
		if (samcount>zmemdivtodo)
			{
			done++;
			Drawdonebox(done);
			zmemdivtodo=zmemdivtodo+zmemdiv;
			}
		}
	done=0;
	}

if (opt==1)  // copy left to right	-------------------------------------------------------------
	{
	fullend=samstartL+samlen;
	copy=samstartR;
	for (samcount=samstartL;samcount<=fullend;samcount++)
		{
		temp=*(sampoint+samcount);
		*(sampoint+copy)=temp;
		copy++;
		}
	}

if (opt==2)  // copy right to left	-------------------------------------------------------------
	{
	fullend=samstartR+samlen;
	copy=samstartL;
	for (samcount=samstartR;samcount<=fullend;samcount++)
		{
		temp=*(sampoint+samcount);
		*(sampoint+copy)=temp;
		copy++;
		}
	}

if (opt==3)  // cut	-------------------------------------------------------------
	{
	if ((makechans==0) || (makechans==2)) fullend=halfmemsize;
	if ((makechans==1) || (makechans==3)) fullend=memsize;
	fullstart=fullend-samlen;
	copy=samstart;
	for (samcount=samend;samcount<=fullend;samcount++)
		{
		temp=*(sampoint+samcount);
		*(sampoint+copy)=temp;
		copy++;
		}

	for (samcount=fullstart;samcount<=fullend;samcount++)	// zero end
		{
		*(sampoint+samcount)=0;
		}

	if (makechans==2) /* second side if stereo */
		{
		samstart=samstartb;
		samend=samendb;
		fullend=memsize;
		fullstart=fullend-samlen;
		copy=samstart;
		for (samcount=samend;samcount<=fullend;samcount++)
			{
			temp=*(sampoint+samcount);
			*(sampoint+copy)=temp;
			copy++;
			}
 
		for (samcount=fullstart;samcount<=fullend;samcount++)
			{
			*(sampoint+samcount)=0;
			}
		}
	}

if (opt==7)  // Zone Over	-------------------------------------------------------------
	{
	if (makechans==0)
		{
		if (poside==0)
			{
			copysize=positionlen;
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize;
			copy=samstart;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			}
		if (poside==1)
			{
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize;
			copy=samstart;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			}
		if (poside==2)
			{
			copysize=positionlen;
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize;
			copy=samstart;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			}
		}
	if (makechans==1)
		{
		if (poside==0)
			{
			copysize=positionlen;
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize;
			copy=samstart;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		if (poside==1)
			{
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize;
			copy=samstart;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		if (poside==2)
			{
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize+halfmemsize;
			copy=samstartR;
			for (samcount=position+halfmemsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		}
	if (makechans==2)
		{
		if (poside==0)
			{
			copysize=positionlen;
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize;
			copy=samstartL;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			copy=samstartR;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		if (poside==1)
			{
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize;
			copy=samstartL;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			copy=samstartR;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		if (poside==2)
			{
			copysize=positionlen;
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize;
			copy=samstartL;
			for (samcount=position;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			fullend=position+copysize+halfmemsize;
			copy=samstartR;
			for (samcount=position+halfmemsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		}
	if (makechans==3)
		{
		copysize=positionlen;
		if (copysize+position>=memsize) copysize=memsize-position;
		fullend=position+copysize;
		copy=samstart;
		for (samcount=position;samcount<=fullend;samcount++)
			{
			temp=*(sampoint+samcount);
			*(sampoint+copy)=temp;
			copy++;
			if (copy>=memsize) samcount=fullend;
			}
		}
	}

if (opt==8)  // Zone Into	-------------------------------------------------------------
	{
	if (makechans==0)
		{
		if (poside==0)
			{
			fullend = halfmemsize-positionlen;	// move area after zone along
			copy=halfmemsize;
			for (samcount=fullend;samcount>samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;	// copy zone from undo buffer
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize+memsize;
			copy=samstart;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			}
		if (poside==1)
			{
			fullend = halfmemsize-positionlen;	// move area after zone along
			copy=halfmemsize;
			for (samcount=fullend;samcount>samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize+memsize;
			copy=samstart;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			}
		if (poside==2)
			{
			fullend = halfmemsize-positionlen;	// move area after zone along
			copy=halfmemsize;
			for (samcount=fullend;samcount>samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;	// copy zone from undo buffer
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize+memsize;
			copy=samstart;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			}
		}
	if (makechans==1)
		{
		if (poside==0)
			{
			fullend = memsize-positionlen;	// move area after zone along
			copy=memsize;
			for (samcount=fullend;samcount>=samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;	// copy zone from undo buffer
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize+memsize;
			copy=samstart;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		if (poside==1)
			{
			fullend = memsize-positionlen;	// move area after zone along
			copy=memsize;
			for (samcount=fullend;samcount>=samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize+memsize;
			copy=samstart;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		if (poside==2)
			{
			fullend = memsize-positionlen;	// move area after zone along
			copy=memsize;
			for (samcount=fullend;samcount>=samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize+memsize+halfmemsize;
			copy=samstart;
			for (samcount=position+memsize+halfmemsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		}
	if (makechans==2)
		{
		if (poside==0)
			{
			fullend = halfmemsize-positionlen;	// move area after zone along
			copy=halfmemsize;
			for (samcount=fullend;samcount>samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;	// copy zone from undo buffer
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize+memsize;
			copy=samstart;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}

			fullstart = samstart+halfmemsize;	// move area after zone along
			fullend = memsize-positionlen;
			copy=memsize;
			for (samcount=fullend;samcount>=fullstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;	// copy zone from undo buffer
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize+memsize;
			copy=samstart+halfmemsize;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
			
		if (poside==1)
			{
			fullend = halfmemsize-positionlen;	// move area after zone along
			copy=halfmemsize;
			for (samcount=fullend;samcount>samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize+memsize;
			copy=samstart;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}
			fullstart = samstart+halfmemsize;	// move area after zone along
			fullend = memsize-positionlen;
			copy=memsize;
			for (samcount=fullend;samcount>=fullstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize+memsize;
			copy=samstart+halfmemsize;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}

		if (poside==2)
			{
			fullend = halfmemsize-positionlen;	// move area after zone along
			copy=halfmemsize;
			for (samcount=fullend;samcount>samstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;	// copy zone from undo buffer
			if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
			fullend=position+copysize+memsize;
			copy=samstart;
			for (samcount=position+memsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=halfmemsize) samcount=fullend;
				}

			fullstart = samstart+halfmemsize;	// move area after zone along
			fullend = memsize-positionlen;
			copy=memsize;
			for (samcount=fullend;samcount>=fullstart;samcount--)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy--;
				}
			copysize=positionlen;
			if (copysize+position>=memsize) copysize=memsize-position;
			fullend=position+copysize+memsize+halfmemsize;
			copy=samstart+halfmemsize;
			for (samcount=position+memsize+halfmemsize;samcount<=fullend;samcount++)
				{
				temp=*(sampoint+samcount);
				*(sampoint+copy)=temp;
				copy++;
				if (copy>=memsize) samcount=fullend;
				}
			}
		}
	if (makechans==3)
		{
		fullend = memsize-positionlen;	// move area after zone along
		copy=memsize;
		for (samcount=fullend;samcount>samstart;samcount--)
			{
			temp=*(sampoint+samcount);
			*(sampoint+copy)=temp;
			copy--;
			}
		copysize=positionlen;	// copy zone from undo buffer
		if (copysize+position>=memsize) copysize=memsize-position;
		fullend=position+copysize+memsize;
		copy=samstart;
		for (samcount=position+memsize;samcount<=fullend;samcount++)
			{
			temp=*(sampoint+samcount);
			*(sampoint+copy)=temp;
			copy++;
			if (copy>=memsize) samcount=fullend;
			}
		}
	}

if (opt==9)  // Move Zone	-------------------------------------------------------------
{
int32 positionend;
int32 newposition;

positionend = position+positionlen;

	if (makechans==0)
		{
		if ((samstart < position) || (samstart > positionend))
			{
			if (poside==0)
				{
				if (samstart < position)	// move area before zone along
					{
					newposition = positionlen+samstart;
					copy=positionend;
					if (copy >= halfmemsize) copy = halfmemsize;
					for (samcount=position;samcount>samstart;samcount--)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy--;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=position+copysize+memsize;
					copy=samstart;
					for (samcount=position+memsize;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=halfmemsize) samcount=fullend;
						}
					}
				else if (samstart > positionend)	// move area after zone along
					{
					newposition = samstart-positionlen;
					copy=position;
					for (samcount=positionend;samcount<samstart;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=position+copysize+memsize;
					copy=newposition;
					for (samcount=position+memsize;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=halfmemsize) samcount=fullend;
						}
					}
				}

			if (poside==1)
				{
				fullend = halfmemsize-positionlen;	// move area after zone along
				copy=halfmemsize;
				for (samcount=fullend;samcount>samstart;samcount--)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy--;
					}

				fullend=memsize;	// Cut on right hand side
				fullstart=fullend-positionlen;
				copy=position;
				for (samcount=positionend;samcount<=fullend;samcount++)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy++;
					}

				for (samcount=fullstart;samcount<=fullend;samcount++)	// zero end
					{
					*(sampoint+samcount)=0;
					}

				copysize=positionlen;	// copy zone from undo buffer
				if (copysize+position>=memsize) copysize=memsize-position;
				fullend=position+copysize+memsize;
				copy=samstart;
				for (samcount=position+memsize;samcount<=fullend;samcount++)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy++;
					if (copy>=halfmemsize) samcount=fullend;
					}
				}

			if (poside==2)
				{
				if (samstart < position)	// move area before zone along
					{
					newposition = positionlen+samstart;
					copy=positionend;
					for (samcount=position;samcount>samstart;samcount--)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy--;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=position+copysize+memsize;
					copy=samstart;
					for (samcount=position+memsize;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=halfmemsize) samcount=fullend;
						}
					}
				else if (samstart > positionend)	// move area after zone along
					{
					newposition = samstart-positionlen;
					copy=position;
					for (samcount=positionend;samcount<samstart;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=position+copysize+memsize;
					copy=newposition;
					for (samcount=position+memsize;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=halfmemsize) samcount=fullend;
						}
					}
				}
			}	// not in zone?
		}	// makechans=0

	if (makechans==1)
		{
		if ((samstart < position) || (samstart > positionend))
			{
			if (poside==0)
				{
				newposition = samstart-positionlen;	// Move area after position on Left hand side
				copy=position;
				for (samcount=positionend;samcount<halfmemsize;samcount++)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy++;
					}

				fullend=halfmemsize;	// Cut on Left hand side
				fullstart=fullend-positionlen;
				for (samcount=fullstart;samcount<=fullend;samcount++)	// Zero end
					{
					*(sampoint+samcount)=0;
					}

				fullend = memsize-positionlen;	// move area after zone along on Right hand side
				copy=memsize;
				for (samcount=fullend;samcount>samstart;samcount--)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy--;
					}

				copysize=positionlen;	// copy zone from undo buffer
				if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
				fullend=position+copysize+memsize;
				copy=samstart;
				for (samcount=position+memsize;samcount<=fullend;samcount++)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy++;
					if (copy>=memsize) samcount=fullend;
					}
				}

			if (poside==1)
				{
				if (samstart < position)
					{
					newposition = positionlen+samstart;
					copy=positionend;
					for (samcount=position;samcount>samstart;samcount--)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy--;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=memsize) copysize=memsize-position;
					fullend=position+copysize+memsize;
					copy=samstart;
					for (samcount=position+memsize;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=memsize) samcount=fullend;
						}
					}
				else if (samstart > positionend)	// move area after zone along
					{
					newposition = samstart-positionlen;
					copy=position;
					for (samcount=positionend;samcount<samstart;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=memsize) copysize=memsize-position;
					fullend=position+copysize+memsize;
					copy=newposition;
					for (samcount=position+memsize;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=memsize) samcount=fullend;
						}
					}
				}

			if (poside==2)
				{
				newposition = position+halfmemsize;
				if (samstart < newposition)	// move area after zone along
					{
					copy=positionend+halfmemsize;
					for (samcount=newposition;samcount>samstart;samcount--)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy--;
						}
					copysize=positionlen;
					if (copysize+position>=memsize) copysize=memsize-position;
					fullend=position+copysize+memsize+halfmemsize;	// copy zone from undo buffer
					fullstart=position+memsize+halfmemsize;
					copy=samstart;
					for (samcount=fullstart;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=memsize) samcount=fullend;
						}
					}
				else if (samstart > (position+halfmemsize))	// move area after zone along
					{
					newposition = samstart-positionlen;
					copy=position+halfmemsize;
					for (samcount=positionend+halfmemsize;samcount<samstart;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=memsize) copysize=memsize-position;
					fullend=position+copysize+memsize+halfmemsize;
					fullstart=position+memsize+halfmemsize;
					copy=newposition;
					for (samcount=fullstart;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=memsize) samcount=fullend;
						}
					}
				}
			}	// not in zone?
		}	// makechans=1


	if (makechans==2)
		{
		if ((poside == 2) || (poside == 0))	//	Both to both
			{
			if ((samstart < position) || (samstart > positionend))
				{
				if (samstart < position)
					{
					newposition = positionlen+samstart;
					copy=positionend;
					for (samcount=position;samcount>samstart;samcount--)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy--;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=position+copysize+memsize;
					copy=samstart;
					for (samcount=position+memsize;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=halfmemsize) samcount=fullend;
						}
					newposition = positionlen+samstart;
					fullstart=position+halfmemsize;
					fullend=samstart+halfmemsize;
					copy=positionend+halfmemsize;
					for (samcount=fullstart;samcount>fullend;samcount--)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy--;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullstart=position+halfmemsize+memsize;
					fullend=position+copysize+memsize+halfmemsize;
					copy=samstart+halfmemsize;
					for (samcount=fullstart;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=memsize) samcount=fullend;
						}
					}

				if (samstart > positionend)
					{
					newposition = samstart-positionlen;
					copy=position;
					for (samcount=positionend;samcount<samstart;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=position+copysize+memsize;
					copy=newposition;
					for (samcount=position+memsize;samcount<fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=halfmemsize) samcount=fullend;
						}
					fullstart=positionend+halfmemsize;
					fullend=samstart+halfmemsize;
					copy=position+halfmemsize;
					for (samcount=fullstart;samcount<fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=position+copysize+memsize+halfmemsize;
					fullstart=position+memsize+halfmemsize;
					newposition=samstart-positionlen;
					copy=newposition+halfmemsize;
					for (samcount=fullstart;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=memsize) samcount=fullend;
						}
					}
				}
			}

		if (poside == 1)	//	both to both
			{
			int32 fullendb;

			fullstart = samstart;
			fullend = position-halfmemsize;
			fullendb = positionend-halfmemsize;

			if ((fullstart < fullend) || (fullstart > fullendb))
				{
				if (fullstart < fullend)
					{
					newposition = positionlen+samstart-halfmemsize;
					copy=positionend-halfmemsize;
					fullstart=position-halfmemsize;
					for (samcount=fullstart;samcount>samstart;samcount--)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy--;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=positionend+halfmemsize;
					fullstart = position+halfmemsize;
					copy=samstart;
					for (samcount=fullstart;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=halfmemsize) samcount=fullend;
						}
					newposition = positionlen+samstart;
					copy=positionend;
					fullstart=position;
					fullend=samstart+halfmemsize;
					for (samcount=fullstart;samcount>fullend;samcount--)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy--;
						}
					copysize=positionlen;	// copy zone from undo buffer
					if (copysize+position>=halfmemsize) copysize=halfmemsize-position;
					fullend=positionend+memsize;
					fullstart = position+memsize;
					copy=samstart+halfmemsize;
					for (samcount=fullstart;samcount<=fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=memsize) samcount=fullend;
						}
					}

				if (fullstart > fullendb)	// both to both
					{
					copy=position-halfmemsize;
					fullstart=positionend-halfmemsize;
					for (samcount=fullstart;samcount<samstart;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						}
					newposition = samstart-positionlen;	// copy zone from undo buffer
					fullstart=position+halfmemsize;
					fullend=positionend+halfmemsize;
					copy=newposition;
					for (samcount=fullstart;samcount<fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=halfmemsize) samcount=fullend;
						}
					copy=position;
					fullstart=positionend;
					fullend=samstart+halfmemsize;
					for (samcount=fullstart;samcount<fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						}
					newposition = samstart-positionlen;	// copy zone from undo buffer
					newposition = newposition+halfmemsize;
					fullstart=position+memsize;
					fullend=positionend+memsize;
					copy=newposition;
					for (samcount=fullstart;samcount<fullend;samcount++)
						{
						temp=*(sampoint+samcount);
						*(sampoint+copy)=temp;
						copy++;
						if (copy>=memsize) samcount=fullend;
						}
					}
				}
			}

		}	// makechans=2

	if (makechans==3)
		{
		if ((samstart < position) || (samstart > positionend))
			{
			if (samstart < position)	// move area before zone along
				{
				newposition = positionlen+samstart;
				copy=positionend;
				for (samcount=position;samcount>samstart;samcount--)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy--;
					}
				copysize=positionlen;	// copy zone from undo buffer
				if (copysize+position>=memsize) copysize=memsize-position;
				fullend=position+copysize+memsize;
				copy=samstart;
				for (samcount=position+memsize;samcount<=fullend;samcount++)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy++;
					if (copy>=memsize) samcount=fullend;
					}
				}
			else if (samstart > positionend)	// move area after zone along
				{
				newposition = samstart-positionlen;
				copy=position;
				for (samcount=positionend;samcount<samstart;samcount++)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy++;
					}
				copysize=positionlen;	// copy zone from undo buffer
				if (copysize+position>=memsize) copysize=memsize-position;
				fullend=position+copysize+memsize;
				copy=newposition;
				for (samcount=position+memsize;samcount<=fullend;samcount++)
					{
					temp=*(sampoint+samcount);
					*(sampoint+copy)=temp;
					copy++;
					if (copy>=memsize) samcount=fullend;
					}
				}
			}
		}	// makechans = 3


	}	// opt=9


}


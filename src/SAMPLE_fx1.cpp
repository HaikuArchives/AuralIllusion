//	  Aural illusion v4.0  Effects & Manipulations 1

//	  SAMPLE_fx1.cpp

//	  Copyright (c) Blachford Technology  30/7/96 - 1999

#include "SAMPLEWindow.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
		
//***************************************************************
// Functions

// Arithrng		   - Arithemitic Operations
// Invertrng		  - Invert + MANIPs
// Limitrng		   - Limit + MANIPs
// Distortrng		 - Distort + FX
// Mathsrng		   - Sin + COMPLEX
// Cleanrng		   - Clean + MANIPs
// Capacitrng		 - Capacitance + MANIPs
// Interrng		   - Interleave DMANIP
// Phaserng		   - Phaser + FX
// Flangerng		  - Flange + FX
// Stutterrng		 - Stutter + DMANIPs
// Filterrng		  - 7 Band EQ FX
// Filterbandrng	 - 7 Band EQ MANIPs
// Filter20rng		- 20 Band EQ FX
// Vibraterng		 - Vibrato FX
// Filtersweeprng	- Filter sweep MANIPs
// Basfiltrng		 - Wha??? FX - Experimental

//***************************************************************
// Arithmetic operations

void SAMPLEWindow::Arithrng(int32 opt,int32 optb)
{
int32 origval;
int32 origvalb;
int32 tempa;
int32 tempb;
int32 maxb;
int32 mula;
int32 mulb;
int32 mixlev;
int32 mixlevb;
int32 scaletyp;
int32 addtyp;
int32 addtypb;

uint32 incount;


mula=samslider1;
mulb=samslider1;
scaletyp=samradio1;
addtyp=samradio2;
addtypb=samradio2;  // greater & lesser only
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1) || (opt==2)) // add - Subtract - Backwards subtract
   {
   incount=position;
   if (makechans==2)
	  {
	  if (poside==0) incount=position;
	  if (poside==1) incount=position-halfmemsize;
	  if (poside==2) incount=position;
	  }
   if (poside==0) maxb=halfmemsize;
   if (poside==1) maxb=memsize;
   if (poside==2) maxb=halfmemsize;
   if (makechans==3) maxb=memsize;

   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 incount++;
	 tempa=*(sampoint+samcount);
	 tempb=*(sampoint+incount);
	 origval=tempa;
	 if (incount>=maxb) tempb=0;
	 tempa=tempa*mula;
	 tempb=tempb*mulb;
	 if (opt==0) tempa=tempa+tempb;
	 if (opt==1) tempa=tempa-tempb;
	 if (opt==2) tempa=tempb-tempa;
	 tempa=tempa >> 9;
	 if (mixlev<256)
		{
		tempa=tempa*mixlev;
		tempa=tempa >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) tempa=origval+tempa;
		if (addtyp==1) tempa=origval-tempa;
		}
	 if (tempa>=32766) tempa=32766;
	 if (tempa<=-32766) tempa=-32766;
	 *(sampoint+samcount)=tempa;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }

  if (scaletyp==1) 
	{
	Rescalerng();
	}
  }

if ((opt==3) || (opt==4) || (opt==5)) // Multiply - Divide - Backwards Divide
   {
   incount=position;
   if (makechans==2)
	  {
	  if (poside==0) incount=position;
	  if (poside==1) incount=position-halfmemsize;
	  if (poside==2) incount=position;
	  }
   if (poside==0) maxb=halfmemsize;
   if (poside==1) maxb=memsize;
   if (poside==2) maxb=halfmemsize;
   if (makechans==3) maxb=memsize;

   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 incount++;
	 tempa=*(sampoint+samcount);
	 tempb=*(sampoint+incount);
	 origval=tempa;
	 if (incount>=maxb) tempb=0;
	 tempa=tempa*mula;
	 tempb=tempb*mulb;
	 if (tempa<=0) tempa=1;
	 if (tempb<=0) tempb=1;
	 if (opt==3)
		{
		tempa=tempa >> 8;
		tempb=tempb >> 8;
		tempa=tempa*tempb;
		tempa=tempa >> 8;
		if (tempa>=32766) tempa=32766;
		if (tempa<=-32766) tempa=-32766;
		}
	 if (opt==4)
		{
		tempa=tempa/tempb;
		tempa=tempa << 12;
		} 
	 if (opt==5)
		{
		tempa=tempb/tempa;
		tempa=tempa << 12;
		}
	 if (mixlev<256)
		{
		tempa=tempa*mixlev;
		tempa=tempa >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) tempa=origval+tempa;
		if (addtyp==1) tempa=origval-tempa;
		}
	 *(sampoint+samcount)=tempa;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }

  if (scaletyp==1) 
	{
	Rescalerng();
	}
  }


if ((opt==6) || (opt==7) || (opt==8)) // AND - OR - XOR
   {
   incount=position;
   if (makechans==2)
	  {
	  if (poside==0) incount=position;
	  if (poside==1) incount=position-halfmemsize;
	  if (poside==2) incount=position;
	  }
   if (poside==0) maxb=halfmemsize;
   if (poside==1) maxb=memsize;
   if (poside==2) maxb=halfmemsize;
   if (makechans==3) maxb=memsize;

   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 incount++;
	 tempa=*(sampoint+samcount);
	 tempb=*(sampoint+incount);
	 if (scaletyp==1) tempb=~tempb; // scaletype used to select +ve or -ve
	 origval=tempa;
	 if (incount>=maxb) tempb=0;
	 tempa=tempa*mula;
	 tempb=tempb*mulb;
	 if (opt==6) tempa=tempa & tempb;
	 if (opt==7) tempa=tempa | tempb;
	 if (opt==8) tempa=tempa ^ tempb;
	 tempa=tempa >> 8;
	 if (mixlev<256)
		{
		tempa=tempa*mixlev;
		tempa=tempa >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) tempa=origval+tempa;
		if (addtyp==1) tempa=origval-tempa;
		}
	 if (tempa>=32766) tempa=32766;
	 if (tempa<=-32766) tempa=-32766;
	 *(sampoint+samcount)=tempa;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
  }

if ((opt==9) || (opt==10)) // Greater - Lesser
   {
   incount=position;
   if (makechans==2)
	  {
	  if (poside==0) incount=position;
	  if (poside==1) incount=position-halfmemsize;
	  if (poside==2) incount=position;
	  }
   if (poside==0) maxb=halfmemsize;
   if (poside==1) maxb=memsize;
   if (poside==2) maxb=halfmemsize;
   if (makechans==3) maxb=memsize;

   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 incount++;
	 tempa=*(sampoint+samcount);
	 tempb=*(sampoint+incount);
 //	if (scaletyp==1) tempb=~tempb;  scaletype used to
															// select +ve or -ve
	 origval=tempa;
	 origvalb=tempb;
	 if (incount>=maxb) tempb=0;
	 tempa=tempa*mula;
	 tempb=tempb*mulb;
	 if (opt==9)
		 {
		 if (scaletyp==0)  // Upper
		   {
		   if (tempa<0)
			 {
			 tempa = (tempa<tempb) ? tempa : tempb;
			 }
		   if (tempa>0)
			 {
			 tempa = (tempa>tempb) ? tempa : tempb;
			 }
		   }
		 if (scaletyp==1)  // Outer
		   {
		   if (tempa<0) tempa=~tempa;
		   if (tempb<0) tempb=~tempb;
		   if (tempa>tempb)
			  {
			  tempa=origval;
			  }
		   else
			  {
			  tempa=origvalb;
			  }
		   }
		 }
	 if (opt==10)
		 {
		 if (scaletyp==0)
		   {
		   if (tempa>0)
			 {
			 tempa = (tempa<tempb) ? tempa : tempb;
			 }
		   if (tempa<0)
			 {
			 tempa = (tempa>tempb) ? tempa : tempb;
			 }
		   }
		 if (scaletyp==1)  // Inner
		   {
		   if (tempa<0) tempa=~tempa;
		   if (tempb<0) tempb=~tempb;
		   if (tempa>tempb)
			  {
			  tempa=origvalb;
			  }
		   else 
			  {
			  tempa=origval;
			  }
		   }
		 }
	 tempa=tempa >> 8;
	 if (mixlev<256)
		{
		tempa=tempa*mixlev;
		tempa=tempa >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtypb==0) tempa=origval+tempa;
		if (addtypb==1) tempa=origval-tempa;
		}
	 if (tempa>=32766) tempa=32766;
	 if (tempa<=-32766) tempa=-32766;
	 *(sampoint+samcount)=tempa;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
  }

if ((opt==11) || (opt==12)) // Modulus - Backwards modulus
   {
   incount=position;
   if (makechans==2)
	  {
	  if (poside==0) incount=position;
	  if (poside==1) incount=position-halfmemsize;
	  if (poside==2) incount=position;
	  }
   if (poside==0) maxb=halfmemsize;
   if (poside==1) maxb=memsize;
   if (poside==2) maxb=halfmemsize;
   if (makechans==3) maxb=memsize;

   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 incount++;
	 tempa=*(sampoint+samcount);
	 tempb=*(sampoint+incount);
	 origval=tempa;
	 if (incount>=maxb) tempb=0;
	 tempa=tempa*mula;
	 tempb=tempb*mulb;
	 if (tempa==0) tempa=1;
	 if (tempb==0) tempb=1;
	 if (opt==11) tempa=tempa%tempb;
	 if (opt==12) tempa=tempb%tempa;
	 tempa=tempa >> 9;
	 if (mixlev<256)
		{
		tempa=tempa*mixlev;
		tempa=tempa >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) tempa=origval+tempa;
		if (addtyp==1) tempa=origval-tempa;
		}
	 if (tempa>=32766) tempa=32766;
	 if (tempa<=-32766) tempa=-32766;
	 *(sampoint+samcount)=tempa;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }

  if (scaletyp==1) 
	{
	Rescalerng();
	}
  }

}

///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
//-----------------------------------------------------------------
// Invert and other MANIP ops

// Invert - half wave - full wave - Flip - Centre - Reverse 
// over - Under - In Between - Out Between

void SAMPLEWindow::Invertrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 addtyp;
int32 mixlev;
int32 mixlevb;
int32 origval;
int32 origvalb;
uint32 incount;
uint32 halfsamend;
int32 hival;
int32 loval;
int32 fix;
int32 loo;
int32 hii;
int32 size;
int32 memdivtodob; // half as big for reversing  

int32 barcount;
int32 midval;
int32 val1=samslider1;
int32 val2=samslider2;

addtyp=samradio1;
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1) || (opt==2) || (opt==3))// Invert - half wave
   {												   //   full wave - Flip
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (opt==0)
		{
		if (temp>0) temp=temp-32766;
		else if (temp<0) temp=temp+32766;
		}
	 if (opt==1)
		{
		if (addtyp==0)
		  {
		  if (temp<0) temp=0;
		  }
		if (addtyp==1)
		  {
		  if (temp>0) temp=0;
		  }
		}
	 if (opt==2)
		{
		if (addtyp==0)
		  {
		  if (temp<0) temp=~temp;
		  }
		if (addtyp==1)
		  {
		  if (temp>0) temp=~temp;
		  }
		}
	 if (opt==3)
		{
		if (temp!=0) temp=~temp;
		}
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if ((opt==1) || (opt==2))
		  {
		  temp=origval+temp;
		  }
		else
		  {
		  if (addtyp==0) temp=origval+temp;
		  if (addtyp==1) temp=origval-temp;
		  }
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

if (opt==4)  // centre
   {
   hival=-32766;
   loval=32766;

   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 if (temp>hival) hival=temp;
	 if (temp<loval) loval=temp;
	 }

	 if (loval<0)
		 {
		 loo=~loval;
		 loo++;
		 }	// loo is the +ve value of -loval
	 else loo=loval;
			
	 if (hival<0)
		 {
		 hii=~hival;
		 hii++;
		 }	// hii is the +ve value of -hival
	 else hii=hival;
			
	 if (hii>loo)
		 {
		 if (loval>=0)
			{
			size=hival-loval;
			size=size >> 1;
			fix=size+loo;  
			}
		 if (loval<0)
			{
			size=hival+loo;
			size=size >> 1;
			fix=size-loo;
			}
		 }

	 else if (hii<loo)
		 {
		 if (hival>0)
			{
			size=hival+loo;
			size=size >> 1;
			fix=loo-size;
			}
		 if (hival<=0)
			{
			size=hii-loo;
			size=size >> 1;
			fix=size+loo;
			}
		 temp=fix;
		 temp=temp << 1;
		 fix=fix-temp;
		 }

		 if (fix>=32767) fix=0;
		 if (fix<=-32767) fix=0;

		 for (samcount=samstart;samcount<=samend;samcount++)
			{
			if (fix!=0)
			  {
			  temp=*(sampoint+samcount);
			  temp=temp-fix;
			  if (temp>=32766) temp=32766;
			  if (temp<=-32766) temp=-32766;
			  *(sampoint+samcount)=temp;
			  }
			if (samcount==memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
  }

if (opt==5) // reverse
   {
   incount=samend;
   halfsamend=samlen >> 1;
   halfsamend=halfsamend+samstart;

	barcount = samstart;
	for (samcount=samstart;samcount<=halfsamend;samcount++)
		{
		barcount = barcount + 2;
		temp=*(sampoint+samcount);
		tempb=*(sampoint+incount);
		origval=temp;
		origvalb=tempb;
		if (mixlev<256)
			{
			tempb=tempb*mixlev;
			tempb=tempb >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtyp==0) tempb=origval+tempb;
			if (addtyp==1) tempb=origval-tempb;

			temp=temp*mixlev;
			temp=temp >> 8;
			origvalb=origvalb*mixlevb;
			origvalb=origvalb >> 8;
			if (addtyp==0) temp=origval+temp;
			if (addtyp==1) temp=origval-temp;
			}
		*(sampoint+samcount)=tempb;
		*(sampoint+incount)=temp;
	 	if (barcount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		incount--;
		}
   }


if ((opt==6) || (opt==7) || (opt==8) || (opt==9)) // Over - Under
   {											 // In Between - Out Between
	 if ((opt==6) || (opt==7))
		{
		hival=val1;
		hival=hival*127;
		loval=~hival;
		}
	 if ((opt==8) || (opt==9))
		{
		midval=val1;
		midval=midval-128;
		midval=midval*256;
		tempb=val2*128;
		hival=midval+tempb;
		if (hival>=32766) hival=32766;
		loval=midval-tempb;
		if (loval<=-32766) loval=-32766;
		}
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (opt==6)
		{
		if (temp>=0)
		   {
		   if (temp<hival) temp=0;
		   }
		if (temp<0)
		   {
		   if (temp>loval) temp=0;
		   }
		}
	 if (opt==7)
		{
		if (temp>=0)
		   {
		   if (temp>hival) temp=0;
		   }
		if (temp<0)
		   {
		   if (temp<loval) temp=0;
		   }
		}
	 if (opt==8)
		{
		if (temp>=midval)
		   {
		   if (temp>=hival) temp=midval;
		   }
		if (temp<=midval)
		   {
		   if (temp<=loval) temp=midval;
		   }
		}
	 if (opt==9)
		{
		if (temp>=midval)
		   {
		   if (temp<=hival) temp=midval;
		   }
		if (temp<=midval)
		   {
		   if (temp>=loval) temp=midval;
		   }
		}
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

}

//-----------------------------------------------------------------
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// Limit and other MANIP ops

// Limit Low - Limit High - Quarter - Half - Double - Quadrauple 

void SAMPLEWindow::Limitrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;

int32 addtyp,addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 incount;
uint16 tempw,tempbw;

int32 val1=samslider1;
int32 val2=samslider2;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1)) // Limit Low - Limit High
   {
	 if (opt==1)
		{
		val1=val1*8;
		}
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 tempb=*(sampoint+samcount+1);
	 origval=temp;
	 if ((opt==0) || (opt==1))
		{
		tempc=tempb-temp;
		if (tempc>0)
		   {
		   if (tempc>=val1)
			  {
			  temp=temp+val1;
			  }
		   }
		if (tempc<0)
		   {
		   tempc=~tempc;
		   if (tempc>=val1)
			  {
			  temp=temp-val1;
			  }
		   }
		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		}
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount+1)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }
  //  Quarter - Half - Double - Quadruple - Square - Half Square
if ((opt==2) || (opt==3) || (opt==4) || (opt==5)
	 || (opt==6) || (opt==7)) 
   {
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (opt==2) temp=temp >> 2;
	 if (opt==3) temp=temp >> 1;
	 if (opt==4) temp=temp << 1;
	 if (opt==5) temp=temp << 2;
	 if (opt==6)  // Square
		{
		if (addtyp==0)
		  {
		  temp=temp*temp;
		  temp=temp >> 16;
		  temp=temp*val1;
		  temp=temp >> 7;
		  if (addtypb==1) 
			{
			if (origval<0) temp=~temp;
			}
		  }
		if (addtyp==1)
		  {
		  if (temp>=1) tempb=32767-temp;
		  if (temp<=1) tempb=-32767-temp;
		  temp=temp*tempb;
		  temp=temp >> 16;
		  temp=temp*val1;
		  temp=temp >> 5;
		  if (addtypb==1)
			{
			if (origval<0) temp=~temp;
			}
		  }
		}

	 if (opt==7)  // Half Square
		{
		if (addtyp==0)
		  {
		  if (temp>0)
		   {
		   temp=temp*temp;
		   temp=temp >> 16;
		   temp=temp*val1;
		   temp=temp >> 7;
		   }
		  }
		if (addtyp==1)
		  {
		  if (temp>0)
		   {
		   tempb=32767-temp;
		   temp=temp*tempb;
		   temp=temp >> 16;
		   temp=temp*val1;
		   temp=temp >> 5;
		   }
		  }
		}

	 if (temp>=32766) temp=32766;
	 if (temp<=-32766) temp=-32766;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

if ((opt==8) || (opt==9)) // SwapByteOrder - Move +/-
   {
	 if (opt==9)
		{
		val1=val1*64;
		}
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (opt==8)  // SwapByteOrder
		{
		tempbw=temp;
		tempw=tempbw;
		tempw=tempw >> 8;
		tempbw=tempbw << 8;
		tempw=tempw+tempbw;
		temp=tempw;
		}
	 if (opt==9)  // Move +/-
		{
		if (addtyp==0) temp=temp+val1;
		if (addtyp==1) temp=temp-val1;
		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		}
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

if (opt==10)  // Blur
   {
   val1 = val1 + 2;
   val2=192/val1;
   if (val2<=0) val2=1;

   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (val1>=1)
	 {
	 if (addtyp==0)
		{
		for (incount=1;incount<=val1;incount++)
		  {
		  if ((samcount+incount) >= samend) temp = 0;
		  else temp=temp+*(sampoint+samcount+incount);
		  }
		}
	 else
		{
		for (incount=1;incount<=val1;incount++)
		  {
		  if ((samcount+incount) >= samend) temp = 0;
		  else temp=temp-*(sampoint+samcount+incount);
		  }
		}
	 temp=temp*val2;
	 temp=temp >> 8;
	 }
	 if (temp>=32766) temp=32766;
	 if (temp<=-32766) temp=-32766;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }
}

//-----------------------------------------------------------------
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// Distort and other Effect ops

// Distort - Contort - Half Distort - Half Contort	

void SAMPLEWindow::Distortrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;

int32 mulo;
int32 muld;
int32 tempo;
int32 tempd;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;
int32 origvala;
int32 incount;

int16 wordval;

int32 val1=samslider1;
int32 val2=samslider2;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1) || (opt==2) || (opt==3))
   {
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;

	 if (opt==0)   // Digital Distortion
		{
		tempb=temp*val1;
		if (addtypb==0)
		  {
		  tempb=tempb>>5;
		  tempb=tempb+temp;
		  }
		if (tempb>=32766) tempb=32766;
		if (tempb<=-32766) tempb=-32766;
		if (addtyp==0) temp=tempb;
		if (addtyp==1) temp=tempb-temp;
		}

	 if (opt==1)   // Digital Contortion
		{
		tempb=temp*val1;
		if (addtypb==0)
		  {
		  tempb=tempb>>5;
		  tempb=tempb+temp;
		  }
		if (addtyp==0) temp=tempb;
		if (addtyp==1) temp=tempb-temp;
		}

	 if (opt==2)   // Digital Half Distortion
		{
		if (temp>=0)
		  {
		  tempb=temp*val1;
		  if (addtypb==0)
			{
			tempb=tempb>>5;
			tempb=tempb+temp;
			}
		  if (tempb>=32766) tempb=32766;
		  if (tempb<=-32766) tempb=-32766;
		  if (addtyp==0) temp=tempb;
		  if (addtyp==1) temp=tempb-temp;
		  }
		}

	 if (opt==3)   // Digital Half Contortion
		{
		if (temp>=0)
		  {
		  tempb=temp*val1;
		  if (addtypb==0)
			{
			tempb=tempb>>5;
			tempb=tempb+temp;
			}
		  if (addtyp==0) temp=tempb;
		  if (addtyp==1) temp=tempb-temp;
		  }
		wordval = temp;
		if (wordval < 0) wordval=~wordval;
		temp = wordval;
		}

	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

if ((opt==4) || (opt==5)) // Resolution - Bandwidth
   {
   if (opt==4)
	 {
	 if (val1<=0) val1=1;
	 if (addtyp==0)
		{
		val1=val1*60;
		}
	 if (addtyp==1)
		{
		val1=val1 >> 5;
		val1=val1+8;
		}
	 }
   origvala=0;
   incount=0;
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (opt==4)  // Resolution
		 {
		 if (addtyp==0)
		   {
		   temp=temp/val1;
		   temp=temp*val1;
		   }
		 if (addtyp==1)
		   {
		   temp=temp >> val1;
		   temp=temp << val1;
		   }
		 }
	 if (opt==5)  // Bandwidth
		 {
		 if (addtyp==0)
		   {
		   if (incount==0)
			 {
			 origvala=origval;
			 incount=val1;
			 }
		   if (incount>=1) temp=origvala;
		   incount--;
		   }
		 if (addtyp==1)
		   {
		   if (incount==0)
			 {

			 if (samcount+val1<samend)
			 	{
			 	origvala=*(sampoint+samcount+val1);
			 	}
			 else origvala=0;

			 incount=val1;
			 }
		   if (incount>=1) temp=origvala;
		   incount--;
		   }
		 }
	 if (temp>=32766) temp=32766;
	 if (temp<=-32766) temp=-32766;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }


if (opt==6)   // Bandwidth Smooth
   {
   origvala=0;
   incount=0;
   tempc=0;
   val1=val1+2;
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (opt==6)  // Bandwidth smooth
		 {
		 if (addtyp==0)
		   {
		   if (incount>=1)
			  {
			  tempc=tempc+tempb;
			  temp=tempc;
			  }
		   else if (incount==0)
			  {
			  tempc=temp;
			 if (samcount+val1<samend)
			 	{
			 	tempb=*(sampoint+samcount+val1);
			 	}
			 else tempb=0;
			  tempb=tempb-temp;
			  tempb=tempb/val1;
			  incount=val1;
			  }
		   incount--;
		   }
		 if (addtyp==1)
		   {
		   if (incount>=1)
			  {
			  tempc=tempc+tempb;
			  temp=tempc;
			  }
		   else if (incount==0)
			  {
			  tempc=temp;
			 if (samcount+val1<samend)
			 	{
			 	tempb=*(sampoint+samcount+val1);
			 	}
			 else tempb=0;
			  tempb=temp-tempb;
			  tempb=tempb/val1;
			  incount=val1;
			  }
		   incount--;
		   }
		 }
	 if (temp>=32766) temp=32766;
	 if (temp<=-32766) temp=-32766;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

if (opt==7) // Enhance 
   {
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (opt==7)	
		{
		tempb=*(sampoint+samcount+1);
		tempb=tempb-temp;
		tempb=tempb*val2;
		if (addtyp==0)
		  {
		  if (tempb>=32766) tempb=32766;
		  if (tempb<=-32766) tempb=-32766;
		  }
		if (addtyp==1)
		  {
		  wordval=tempb;
		  tempb=wordval;
		  }
		tempb=tempb/100;
		tempb=tempb*val1;
		temp=origval+tempb;
		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		}
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

}

///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
//  Complex Maths Operations

//1  1/x
//2  acosf(float x);
//3  asinf(float x);
//4  atanf(float x);
//5  cosf(float x);
//6  sinf(float x);
//7  tanf(float x);
//8  coshf(float x);
//9  sinhf(float x);

//10 tanhf(float x);
//11 acoshf(float x);
//12 asinhf(float x);
//13 atanhf(float x);
//14 sec
//15 cosec
//16 Cot 
//17 +Sin 
//18 expf(float x);
//19 logf(float x);

//20 log10f(float x);
//21 expm1f(float x);
//22 log1pf(float x);
//23 logbf(float x);
//24 +Log 
//25 sqrtf(float x);
//26 cbrtf(float x);
//27 ceilf(float x);
//28 fabsf(float x);
//29 floorf(float x);

//30 significandf(float x);
//31 j0f(float);
//32 j1f(float);
//33 y0f(float);
//34 y1f(float);
//35 erff(float);
//36 erfcf(float);
//37 gammaf(float);
//38 lgammaf(float);
//39 rintf(float x);
//40 ilogbf(float x);  // int output

void SAMPLEWindow::Mathsrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 count;
//int32 calced=0;
int32 origtemp;

float dtemp;
float dtempb;

int32 addtyp,addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 samslider1;
int32 samslider2;
int32 samslider3;
int32 samslider4;

addtyp=samradio1;
addtypb=samradio2;

mixlev=samslider;
mixlevb=256-mixlev;

mixlev=256;

if ((opt>=1) && (opt<=43))
 {


// -----------------------------------------------------------------
//1  1/x
//2  acosf(float x);
//3  asinf(float x);
//4  atanf(float x);
//5  cosf(float x);
//6  sinf(float x);
//7  tanf(float x);
//8  coshf(float x);
//9  sinhf(float x);
// -----------------------------------------------------------------
	 if (opt==1)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=1/dtemp;   // 1/x 
		  dtemp=dtemp*128;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==2)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=acosf(dtemp);   // acosf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==3)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=asinf(dtemp);   // asinf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==4)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=atanf(dtemp);   // atanf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==5)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=cosf(dtemp);   // cosf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==6)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=sinf(dtemp);   // sinf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==7)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=tanf(dtemp);   // tanf
		  dtemp=dtemp*8192;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==8)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=coshf(dtemp);   // coshf
		  dtemp=dtemp*32766;
		  dtemp=dtemp-32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==9)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=sinhf(dtemp);   // sinhf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
//10 tanhf(float x);
//11 acoshf(float x);
//12 asinhf(float x);
//13 atanhf(float x);
//14 sec
//15 cosec
//16 Cot 
//17 +Sin 
//18 expf(float x);
//19 logf(float x);
// -----------------------------------------------------------------
	 if (opt==10)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=tanhf(dtemp);   // tanhf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==11)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.0047948;
		  dtemp=acoshf(dtemp);   // acoshf
		  dtemp=dtemp*4096;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==12)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=asinhf(dtemp);   // asinhf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==13)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=atanhf(dtemp);   // atanhf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==14)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.0047948;
		  dtemp=cos(dtemp);   // sec
		  dtemp=1/dtemp;
		  dtemp=dtemp*512;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==15)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=sin(dtemp);   // cosec
		  dtemp=1/dtemp;
		  dtemp=dtemp*128;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==16)	// COT this is 1/tan
		{
			for (count=0;count<=65535;count++)
			  {
			  temp=count;
			  temp=temp-32767;
			  origval=temp;
			  if (addtypb==1)
			  	{
			  	if (temp>0) temp=32767-temp;
			  	if (temp<0) temp=-32767-temp;
			  	}
			  dtemp=temp;
			  dtemp=dtemp*0.000047948;
			  dtemp=tan(dtemp);  // Cot
			  dtemp=1/dtemp;
			  dtemp=dtemp*64;
			  if (dtemp>=32766) dtemp=32766;
			  if (dtemp<=-32766) dtemp=-32766;
			  temp=dtemp;
			  if (addtypb==1)
			  	{
			  	if (temp>0) temp=32767-temp;
			  	if (temp<0) temp=-32767-temp;
			  	}
			  if (addtyp==1)
				{
   				temp=temp-origval;
 		 		temp=temp >> 1;
				}
			  complexbuf[count]=temp;
			  }
			Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==17)	// + SIN
		{
			for (count=0;count<=65535;count++)
			  {
			  temp=count;
			  temp=temp-32767;
			  origval=temp;
			  if (addtypb==1)
			  	{
			  	if (temp>0) temp=32767-temp;
			  	if (temp<0) temp=-32767-temp;
			  	}
			  dtemp=temp;
			  dtemp=dtemp*0.000047948;
			  dtemp=dtemp+1.57113196;
			  dtemp=sin(dtemp);  // + sin
			  dtemp=dtemp*16383;
			  if (dtemp>=32766) dtemp=32766;
			  if (dtemp<=-32766) dtemp=-32766;
			  temp=dtemp;
			  if (addtypb==1)
			  	{
			  	if (temp>0) temp=32767-temp;
			  	if (temp<0) temp=-32767-temp;
			  	}
			  if (addtyp==1)
				{
   				temp=temp-origval;
 		 		temp=temp >> 1;
				}
			  complexbuf[count]=temp;
			  }
			Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==18)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=expf(dtemp);  // Exponent 
		  dtemp=dtemp*8192;
		  dtemp=dtemp-8192;   // above to below 
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==19)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=logf(dtemp);   // logf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
//20 log10f(float x);
//21 expm1f(float x);
//22 log1pf(float x);
//23 logbf(float x);
//24 +Log 
//25 sqrtf(float x);
//26 cbrtf(float x);
//27 ceilf(float x);
//28 fabsf(float x);
//29 floorf(float x);
// -----------------------------------------------------------------
	 if (opt==20)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=log10f(dtemp);   // log10f 
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==21)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=expm1f(dtemp);   // expmlf 
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==22)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=log1pf(dtemp);   // loglpf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==23)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=logbf(dtemp);   // logbf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==24)	// + LOG
		{
			for (count=0;count<=65535;count++)
			  {
			  temp=count;
			  temp=temp-32767;
			  origval=temp;
			  if (addtypb==1)
			  	{
			  	if (temp>0) temp=32767-temp;
			  	if (temp<0) temp=-32767-temp;
			  	}
			  dtemp=temp;
			  dtemp=dtemp*0.000047948;
			  dtemp=dtemp+1.57113196;
			  dtemp=log(dtemp);  // + Log 
			  dtemp=dtemp*12233;
			  if (dtemp>=32766) dtemp=32766;
			  if (dtemp<=-32766) dtemp=-32766;
			  temp=dtemp;
			  if (addtypb==1)
			  	{
			  	if (temp>0) temp=32767-temp;
			  	if (temp<0) temp=-32767-temp;
			  	}
			  if (addtyp==1)
				{
   				temp=temp-origval;
 		 		temp=temp >> 1;
				}
			  complexbuf[count]=temp;
			  }
			Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==25)	// SQUAREROOT
		{
			for (count=0;count<=65535;count++)
			  {
			  temp=count;
			  temp=temp-32767;
			  origval=temp;
			  if (addtypb==1)
			  	{
			  	if (temp>0) temp=32767-temp;
			  	if (temp<0) temp=-32767-temp;
			  	}
			  dtemp=temp;
			  dtemp=dtemp*0.000047948;
			  if (origval<0)
				 {
				 dtempb=dtemp*2;
				 dtemp=dtemp-dtempb;
				 }
			  dtemp=sqrtf(dtemp);  // Squareroot
			  dtemp=dtemp*25000;
			  if (origtemp<0)
				 {
				 dtempb=dtemp*2;
				 dtemp=dtemp-dtempb;
				 }
			  if (dtemp>=32766) dtemp=32766;
			  if (dtemp<=-32766) dtemp=-32766;
			  temp=dtemp;
			  if (addtypb==1)
			  	{
			  	if (temp>0) temp=32767-temp;
			  	if (temp<0) temp=-32767-temp;
			  	}
			  if (addtyp==1)
				{
   				temp=temp-origval;
 		 		temp=temp >> 1;
				}
			  complexbuf[count]=temp;
			  }
			Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==26)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=cbrtf(dtemp);   // cbrtf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==27)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=ceilf(dtemp);   // ceilf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==28)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=fabsf(dtemp);   // fabsf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==29)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=floorf(dtemp);   // floorf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
//30 significandf(float x);
//31 j0f(float);
//32 j1f(float);
//33 y0f(float);
//34 y1f(float);
//35 erff(float);
//36 erfcf(float);
//37 gammaf(float);
//38 lgammaf(float);
//39 rintf(float x);
//40 ilogbf(float x);  // int output
// -----------------------------------------------------------------
	 if (opt==30)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=significandf(dtemp);   // significantf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==31)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=j0f(dtemp);   // j0f
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==32)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=j1f(dtemp);   // j1f
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==33)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=y0f(dtemp);   // y0f
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==34)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=y1f(dtemp);   // y1f
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==35)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=erff(dtemp);   // erff
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==36)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=erfcf(dtemp);   // erfcf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==37)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=gammaf(dtemp);   // gammaf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==38)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=lgammaf(dtemp);   // lgammaf
		  dtemp=dtemp*32766;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==39)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  dtemp=dtemp*0.000047948;
		  dtemp=rintf(dtemp);   // rintf
		  dtemp=dtemp*16383;
		  if (dtemp>=32766) dtemp=32766;
		  if (dtemp<=-32766) dtemp=-32766;
		  temp=dtemp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------
	 if (opt==40)
		{
		for (count=0;count<=65535;count++)	//	create buffer
		  {
		  temp=count;
		  temp=temp-32767;
		  origval=temp;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  dtemp=temp;
		  temp=ilogbf(dtemp);   // ilogbf
		  if (temp>=32766) temp=32766;
		  if (temp<=-32766) temp=-32766;
		  if (addtypb==1)
		  	{
		  	if (temp>0) temp=32767-temp;
		  	if (temp<0) temp=-32767-temp;
		  	}
		  if (addtyp==1)
			{
   			temp=temp-origval;
	  		temp=temp << 2;
			}
		  complexbuf[count]=temp;
		  }
		Newdrawdonebox(3,0,5,200,200,drawbarside);
			
		for (samcount=samstart;samcount<=samend;samcount++)	// 
		  {
		  temp=*(sampoint+samcount);
		  origval=temp;
		  temp=temp+32767;
		  temp=complexbuf[temp];
		  if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		  *(sampoint+samcount)=temp;
		  if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		  }
		}
// -----------------------------------------------------------------

   }

}

///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// More Manips

// Clean - AddSpikes - DelSpikes - Delta

void SAMPLEWindow::Cleanrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;
int32 origb;
int32 origc;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 spike;
int32 spikeval;
uint32 locheckcount;
uint32 hicheckcount;

int32 val1=samslider1;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if (opt==0)	// Clean
   {
   if (addtypb == 0) hicheckcount = samend-1;
   if (addtypb == 1) hicheckcount = samend-3;
   for (samcount=samstart+1;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;

		 if (addtypb==0)
		   {
		   if (addtyp==0)
			 {
			 tempb=*(sampoint+samcount-1);
			 if (samcount == hicheckcount) tempc=0;
			 else tempc=*(sampoint+samcount+1);
			 temp=tempc-tempb;
			 temp=temp >> 1;
			 temp=tempb+temp;
			 }
		   if (addtyp==1)
			 {
			 tempb=*(sampoint+samcount-1);
			 if (samcount == hicheckcount) tempc=0;
			 else tempc=*(sampoint+samcount+1);
			 temp=tempb-tempc;
			 temp=temp >> 1;
			 temp=origval+temp;
			 }
		   }
		 if (addtypb==1)
		   {
		   if (addtyp==0)
			 {
			 tempb=*(sampoint+samcount-1);
			 if (samcount == hicheckcount) tempc=0;
			 else tempc=*(sampoint+samcount+3);
			 temp=tempc-tempb;
			 temp=temp >> 2;
			 temp=tempb+temp;
			 }
		   if (addtyp==1)
			 {
			 tempb=*(sampoint+samcount-1);
			 if (samcount == hicheckcount) tempc=0;
			 else tempc=*(sampoint+samcount+3);
			 temp=tempb-tempc;
			 temp=temp >> 2;
			 temp=origval+temp;
			 }
		   }

	 if (temp<=-32766) temp=-32766;
	 if (temp>=32766) temp=32766;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		temp=origval+temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

if (opt==1)	// AddSpikes
   {
	spikeval=32766;
	spikeval=spikeval*val1;
	spikeval=spikeval >> 8;
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;

		 tempb=*(sampoint+samcount+1);
		 if (temp>=0)
		   {
		   if (tempb<0) spike=1;
		   }
		 if (temp<=0)
		   {
		   if (tempb>0) spike=2;
		   }
		 if (addtyp==0)
		   {
		   if (spike==1) temp=spikeval;
		   if (spike==2) temp=~spikeval;
		   }
		 if (addtyp==1)
		   {
		   if (spike==1) temp=~spikeval;
		   if (spike==2) temp=spikeval;
		   }
		 spike=0;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }

if (opt==2)	// DelSpikes
   {
   hicheckcount = samend-1;
   for (samcount=samstart+1;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;

		if (addtyp==0) // replace
		  {
		 tempb=*(sampoint+samcount-1);
		 if (samcount == hicheckcount) tempc=0;
		 else tempc=*(sampoint+samcount+1);
		  tempd=tempb;
		  tempb=temp-tempb;
		  tempc=temp-tempc;
		  if (tempb<0) tempb=~tempb;
		  if (tempc<0) tempc=~tempc;
		  if ((tempb>4000) && (tempc>4000)) temp=tempd;
		  }
		if (addtyp==1) // smooth - Doesn't work very well.
		  {
		 tempb=*(sampoint+samcount-1);
		 if (samcount == hicheckcount) tempc=0;
		 else tempc=*(sampoint+samcount+1);
		 origb=tempb;
		 origc=tempc;
		 tempd=tempb;
		 tempb=temp-tempb;
		 tempc=temp-tempc;
		 if (tempb<0) tempb=~tempb;
		 if (tempc<0) tempc=~tempc;
		 if ((tempb>4000) && (tempc>4000)) 
			{
			tempb=origb;
			tempc=origc;
			temp=tempc-tempb;
//			temp=tempb-tempc;	// This adds big spikes
			temp=temp >> 1;
			temp=tempb+temp;
			}
		  }

	 if (temp<=-32766) temp=-32766;
	 if (temp>=32766) temp=32766;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }


if (opt==3)	// Delta 
   {
	hicheckcount = samend-2;
   for (samcount=samstart+1;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;

	 tempb=*(sampoint+samcount+1);
	 origb=tempb;
	 temp=tempb-temp;

	 if (addtyp==1) // Double Delta
		{
		tempb=origb;
		if (samcount == hicheckcount) tempc=0;
		else tempc=*(sampoint+samcount+2);
		tempc=tempc-tempb;
		temp=tempc-temp;
		}

	 if (temp<=-32766) temp=-32766;
	 if (temp>=32766) temp=32766;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}

	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }
}


///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// Strange Manip operations

// Capacitance - Replacement - Tear - Noise

void SAMPLEWindow::Capacitrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;

int32 val;
int32 tot;
int32 num;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int16 wval;

int32 val1=samslider1;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;
num=val1*4;

if ((opt==0) || (opt==1) || (opt==2) || (opt==3))
   {
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 temp=*(sampoint+samcount);
	 origval=temp;
	 if (opt==0)	// Capacitance
		 {
		 val=val1-10;

		 tempb=*(sampoint+samcount+1);
		 tempc=tempb;
		 if (temp>0)
		   {
		   if (tempb<temp)
			 {
			 tot=temp-tempb;
			 tot=tot*val;
			 tot=tot >> 8;
			 tempc=tempb+tot;
			 }
		   }
		 if (temp<0)
		   {
		   if (tempb>temp)
			 {
			 tot=temp-tempb;
			 tot=tot*val;
			 tot=tot >> 8;
			 tempc=tempb-tot;
			 }
		   tot=0;
		   }
		 if (addtyp==0) temp=tempc;
		 if (addtyp==1) temp=tempc-origval;
		 }

	 if (opt==1)	// Replacement
		 {
		 tempb=*(sampoint+samcount+1);
		 if (((temp>=0) && (tempb<=0)) || ((temp<=0) && (tempb>=0)))
			{
			tot=0;
			}
		 if (addtyp==0)
			{
			tot=tot+temp;
			temp=tot;
			temp=temp*val1;
			temp=temp >> 14;
			temp=temp*3;
			}
		 if (addtyp==1)
			{
			tot=temp-tot;
			temp=tot;
			temp=temp*val1;
			temp=temp >> 7;
			}
		 }

	 if (opt==2)	// Tear
		 {
		 tempb=*(sampoint+samcount+1);
		 tempb=tempb-temp;
		 if (tempb>0)
		   {
		   if (tempb>=num)
			 {
			 tempb=temp+num;
			 }
		   }
		 if (tempb<0)
		   {
		   tempb=~tempb;
		   if (tempb>=num)
			 {
			 tempb=temp-num;
			 }
		   }
		 wval=tempb;
		 temp=wval;
		 if (addtyp==1)
		   {
		   if (temp<=-32766) temp=-32766;
		   if (temp>=32766) temp=32766;
		   temp=temp-origval;
		   }
		 }

	 if (opt==3)	// Noise
		{
		temp=rand();
		if (addtyp==1)
		  {
		  temp=temp >> 16;
		  }
		if (addtyp==0)
		  {
		  temp=temp >> 15;
		  temp=temp-32766;
		  }
		temp=temp*val1;
		temp=temp >> 8;
		}

	 if (temp<=-32766) temp=-32766;
	 if (temp>=32766) temp=32766;

	 if ((opt==0) || (opt==2)) *(sampoint+samcount+1)=temp;
	 else *(sampoint+samcount)=temp;

	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}

	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   }
}
//-----------------------------------------------------------------
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// Interleaving DMANIP operations

// Interleave

void SAMPLEWindow::Interrng(int32 opt,int32 optb)
{
int32 origval;
int32 tempa;
int32 tempb;
int32 tempc;
int32 maxb;
int32 mula;
int32 mulb;
int32 val3;
int32 mixlev;
int32 mixlevb;
int32 addtyp;

int32 type;
int32 leavcount=0;
uint32 incount;

val3=samslider3;
mula=samslider1;
mulb=samslider2;
addtyp=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if (opt==0) // Interleave 
   {
   incount=position;
   if (makechans==2)
	  {
	  if (poside==0) incount=position;
	  if (poside==1) incount=position-halfmemsize;
	  if (poside==2) incount=position;
	  }
   if (poside==0) maxb=halfmemsize;
   if (poside==1) maxb=memsize;
   if (poside==2) maxb=halfmemsize;
   if (makechans==3) maxb=memsize;

   type=1;
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 incount++;
	 tempa=*(sampoint+samcount);
	 tempb=*(sampoint+incount);
	 origval=tempa;
	 if (incount>=maxb) tempb=0;
	 tempa=tempa*mula;
	 tempb=tempb*mulb;
	 if (opt==0)		// Interleave
		{
		if (leavcount==0)
		  {
		  leavcount=val3;
		  type=~type;
		  }
		if (type>=1)
		  {
		  tempc=tempa;
		  tempa=tempb;
		  tempb=tempc;
		  }
		leavcount--;
		}
	 tempa=tempa >> 8;
	 tempb=tempb >> 8;
	 if (mixlev<256)
		{
		tempa=tempa*mixlev;
		tempa=tempa >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) tempa=origval+tempa;
		if (addtyp==1) tempa=origval-tempa;
		}
	 *(sampoint+samcount)=tempa;
	 *(sampoint+incount)=tempb;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
  }
}

//-----------------------------------------------------------------
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************

// Phaser and Phase Shift  Effects

void SAMPLEWindow::Phaserng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 incount;
int32 incountb;
int32 incountc;
int32 phcount;
int32 phcountb;
int32 dir;
int32 repcount;
int32 rphcount;
int32 rphcountb;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

val1=val1 << 1;
if (val2==0) val2=1;

incount=0;
incountb=0;
incountc=0;
phcount=0;
phcountb=val1;
rphcount=0;
rphcountb=val1;
dir=0;

if ((opt==0) || (opt==1) || (opt==2))
   {

 if (opt==0)  // Phase Shift
   {
   phcount=val1;
   phcountb=val1 >> 1;
   for (repcount=0;repcount<=val3;repcount++)
	 {
	 for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
//		tempb=*(sampoint+samcount+phcount);
//	 tempc=*(sampoint+samcount+phcountb);
//		if ((samcount+phcount)>=samend)  tempb=0;
//		if ((samcount+phcountb)>=samend) tempc=0;

		if ((samcount+phcount)<samend)
			{
			tempb=*(sampoint+samcount+phcount);
			}
		else tempb=0;
			
		if ((samcount+phcount)<samend)
			{
			tempc=*(sampoint+samcount+phcountb);
			}
		else tempc=0;

		incount++;
		if (val2<=255)
		  {
		  tempb=tempb*val2;
		  tempb=tempb >> 8;
		  tempc=tempc*val2;
		  tempc=tempc >> 8;
		  }
		if (addtypb==0)
		  {
		  if (addtyp==0) temp=temp+tempb;
		  if (addtyp==1) temp=temp-tempb;
		  temp=temp >> 1;
		  }
		if (addtypb==1)
		  {
		  if (addtyp==0) temp=temp+tempb+tempc;
		  if (addtyp==1) temp=temp-tempb-tempc;
		  temp=temp >> 2;
		  }

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

		if (mixlev<256)
		  {
		  temp=temp*mixlev;
		  temp=temp >> 8;
		  origval=origval*mixlevb;
		  origval=origval >> 8;
		  if (addtyp==0) temp=origval+temp;
		  if (addtyp==1) temp=origval-temp;
		  }
		*(sampoint+samcount)=temp;
		}
	 Rescalenoboxrng();
	 Newdrawdonebox(3,0,100,val3,repcount,drawbarside);
	 }
   }

   if (opt==1)  // Phaser
	 {
	 val3=val3 << 10;
	 
	 for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if ((samcount+phcount)<samend)
			{
			tempb=*(sampoint+samcount+phcount);
			}
		else tempb=0;
			
		if ((samcount+phcount)<samend)
			{
			tempc=*(sampoint+samcount+phcountb);
			}
		else tempc=0;


		if (incount==val1)
		  {
		  if (dir==0)
			{
			phcount++;
			phcountb--;
			}
		  if (dir==1)
			{
			phcount--;
			phcountb++;
			}
		  incount=0;
		  }

		if (incountb==val3)
		  {
		  if (dir==0) dir=1;
		  else if (dir==1) dir=0;
		  incount=0;
		  incountb=0;
		  }

		incount++;
		incountb++;
		if (val2<=255)
		  {
		  tempb=tempb*val2;
		  tempb=tempb >> 8;
		  tempc=tempc*val2;
		  tempc=tempc >> 8;
		  }
		if (addtypb==0)
		  {
		  if (addtyp==0) temp=temp+tempb;
		  if (addtyp==1) temp=temp-tempb;
		  temp=temp >> 1;
		  }
		if (addtypb==1)
		  {
		  if (addtyp==0) temp=temp+tempb+tempc;
		  if (addtyp==1) temp=temp-tempb-tempc;
		  temp=temp >> 2;
		  }

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 } 
	 }
   }


   if (opt==2)  // Step Flange
	 {
	 val3=val3 << 10;
	 val4=val4 << 10;
	 for (repcount=0;repcount<=5;repcount++)
		{
	 for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

//		tempb=*(sampoint+samcount+rphcount);
//		tempc=*(sampoint+samcount+rphcountb);
//		if ((samcount+rphcount)>=samend)  tempb=0;
//		if ((samcount+rphcountb)>=samend) tempc=0;

		if ((samcount+rphcount)<samend)
			{
			tempb=*(sampoint+samcount+rphcount);
			}
		else tempb=0;
			
		if ((samcount+rphcount)<samend)
			{
			tempc=*(sampoint+samcount+rphcountb);
			}
		else tempc=0;

		if (incount==val1)
		  {
		  if (dir==0)
			{
			phcount=phcount+1;
			phcountb=phcount-1;
			}
		  if (dir==1)
			{
			phcount=phcount-1;
			phcountb=phcount+1;
			}
		  incount=0;
		  }

		if (incountb==val3)
		  {
		  if (dir==0) dir=1;
		  else if (dir==1) dir=0;
		  incount=0;
		  incountb=0;
		  }

		if (incountc==val4)
		  {
		  rphcount=phcount;
		  rphcountb=phcountb;
		  incountc=0;
		  }

		incount++;
		incountb++;
		incountc++;
		if (val2<=255)
		  {
		  tempb=tempb*val2;
		  tempb=tempb >> 8;
		  tempc=tempc*val2;
		  tempc=tempc >> 8;
		  }
		if (addtypb==0)
		  {
		  if (addtyp==0) temp=temp+tempb;
		  if (addtyp==1) temp=temp-tempb;
		  temp=temp >> 1;
		  }
		if (addtypb==1)
		  {
		  if (addtyp==0) temp=temp+tempb+tempc;
		  if (addtyp==1) temp=temp-tempb-tempc;
		  temp=temp >> 2;
		  }

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 }
	 Rescalenoboxrng();
	 Newdrawdonebox(3,0,100,5,repcount,drawbarside);
	}
   }

 }
}

//-----------------------------------------------------------------
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************

// Flange and Chorus  Effects

void SAMPLEWindow::Flangerng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;
int32 tempe;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 incount;
int32 incountb;
int32 incountc;
int32 phcount;
int32 phcountb;
int32 dir;
int32 repcount;
int32 rphcount;
int32 rphcountb;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

val1=val1 << 1;
if (val2==0) val2=1;

incount=0;
incountb=0;
incountc=0;
phcount=0;
phcountb=val1;
rphcount=0;
rphcountb=val1;
dir=0;


if (opt==0)  //  Strange Flange 
	{
	phcount=val1;
	phcountb=val1 >> 1;
	val4=val4 << 10;
	for (repcount=0;repcount<=5;repcount++)
		{
		for (samcount=samstart;samcount<=samend;samcount++)
			{
			temp=*(sampoint+samcount);
			origval=temp;
//			tempb=*(sampoint+samcount+phcount);
//			tempc=*(sampoint+samcount+phcountb);
//			if ((samcount+phcount)>=samend)  tempb=0;
//			if ((samcount+phcountb)>=samend) tempc=0;

			if ((samcount+phcount)<samend)
				{
				tempb=*(sampoint+samcount+phcount);
				}
			else tempb=0;
				
			if ((samcount+phcount)<samend)
				{
				tempc=*(sampoint+samcount+phcountb);
				}
			else tempc=0;

			if (val3<=255)
			  {
			  tempb=tempb*val3;
			  tempb=tempb >> 8;
			  tempc=tempc*val3;
			  tempc=tempc >> 8;
			  }
			if (addtypb==0)
			  {
			  if (addtyp==0) temp=temp+tempb;
			  if (addtyp==1) temp=temp-tempb;
			  temp=temp >> 1;
			  }
			if (addtypb==1)
			  {
			  if (addtyp==0) temp=temp+tempb+tempc;
			  if (addtyp==1) temp=temp-tempb-tempc;
			  temp=temp >> 2;
			  }

			if (temp>=32766) temp=32766;
			if (temp<=-32766) temp=-32766;

			if (mixlev<256)
			  {
			  temp=temp*mixlev;
			  temp=temp >> 8;
			  origval=origval*mixlevb;
			  origval=origval >> 8;
			  if (addtyp==0) temp=origval+temp;
			  if (addtyp==1) temp=origval-temp;
			  }
			*(sampoint+samcount)=temp;
			}
		Rescalenoboxrng();
		Newdrawdonebox(3,0,42,5,(repcount+1),drawbarside);
		}

	   for (repcount=0;repcount<=5;repcount++)
		 {
		 incount = 0;
		 for (samcount=samstart;samcount<=samend;samcount++)
			{
			temp=*(sampoint+samcount);
			origval=temp;

//			tempb=*(sampoint+samcount+phcount);
//			tempc=*(sampoint+samcount+phcountb);
//			if ((samcount+phcount)>=samend)  tempb=0;
//			if ((samcount+phcountb)>=samend) tempc=0;

			if ((samcount+phcount)<samend)
				{
				tempb=*(sampoint+samcount+phcount);
				}
			else tempb=0;
			
			if ((samcount+phcount)<samend)
				{
				tempc=*(sampoint+samcount+phcountb);
				}
			else tempc=0;

			if (incount==val2)
				{
				if (dir==0)
					{
					phcount++;
					phcountb--;
					}
				if (dir==1)
					{
					phcount--;
					phcountb++;
					}
				incount=0;
				}

			if (incountb==val4)
				{
				if (dir==0) dir=1;
				else if (dir==1) dir=0;
				incount=0;
				incountb=0;
		  		}

			incount++;
			incountb++;
			if (val3<=255)
				{
				tempb=tempb*val3;
				tempb=tempb >> 8;
				tempc=tempc*val3;
				tempc=tempc >> 8;
				}
			if (addtypb==0)
				{
				if (addtyp==0) temp=temp+tempb;
				if (addtyp==1) temp=temp-tempb;
				temp=temp >> 1;
				}
			if (addtypb==1)
				{
				if (addtyp==0) temp=temp+tempb+tempc;
				if (addtyp==1) temp=temp-tempb-tempc;
				temp=temp >> 2;
				}

			if (temp>=32766) temp=32766;
			if (temp<=-32766) temp=-32766;

			if (mixlev<256)
				{
				temp=temp*mixlev;
				temp=temp >> 8;
				origval=origval*mixlevb;
				origval=origval >> 8;
				if (addtyp==0) temp=origval+temp;
				if (addtyp==1) temp=origval-temp;
				}
			*(sampoint+samcount)=temp;
			}
		Rescalenoboxrng();
		Newdrawdonebox(3,50,92,5,(repcount+1),drawbarside);
		}
	}

if (opt==1)  // Chorus
	 {
	 val3=val3 << 10;
	 val4 = val4 + 50;
	 val4=val4 << 3;
	 for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

//		tempb=*(sampoint+samcount+phcount+val4);
//		tempc=*(sampoint+samcount+phcountb);
//		tempd=*(sampoint+samcount+phcount+val4);
//		tempe=*(sampoint+samcount+phcountb+val4);
//		if ((samcount+phcount+val4)>=samend)  tempb=0;
//		if ((samcount+phcountb)>=samend) tempc=0;
//		if ((samcount+phcount+val4)>=samend)  tempd=0;
//		if ((samcount+phcountb+val4)>=samend) tempe=0;

		if ((samcount+phcount+val4)<samend)
			{
			tempb=*(sampoint+samcount+phcount+val4);
			}
		else tempb=0;
			
		if ((samcount+phcount)<samend)
			{
			tempc=*(sampoint+samcount+phcountb);
			}
		else tempc=0;
			
		if ((samcount+phcount+val4)<samend)
			{
			tempd=*(sampoint+samcount+phcountb+val4);
			}
		else tempd=0;
			
		if ((samcount+phcount+val4)<samend)
			{
			tempe=*(sampoint+samcount+phcountb+val4);
			}
		else tempe=0;

		if (incount==val1)
		  {
		  if (dir==0)
			{
			phcount++;
			phcountb--;
			}
		  if (dir==1)
			{
			phcount--;
			phcountb++;
			}
		  incount=0;
		  }

		if (incountb==val3)
		  {
		  if (dir==0) dir=1;
		  else if (dir==1) dir=0;
		  incount=0;
		  incountb=0;
		  }

		incount++;
		incountb++;
		if (val2<=255)
		  {
		  tempb=tempb*val2;
		  tempb=tempb >> 8;
		  tempc=tempc*val2;
		  tempc=tempc >> 8;
		  }
		if (addtypb==0)
		  {
		  if (addtyp==0) temp=temp+tempb+tempd+tempe;
		  if (addtyp==1) temp=temp-tempb+tempd+tempe;
		  temp=temp >> 2;
		  }
		if (addtypb==1)
		  {
		  if (addtyp==0) temp=temp+tempb+tempc-tempe;
		  if (addtyp==1) temp=temp-tempb-tempc-tempe;
		  temp=temp >> 2;
		  }

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 } 
	 }
   }


if ((opt==2) || (opt == 3))  // Thicken - Double Thicken
	 {
	 val1=val1+50;
	 val2=256;
	 val3=250000;
	 val4=1400;
	 for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

//		tempb=*(sampoint+samcount+phcount+val4);
//		tempc=*(sampoint+samcount+phcountb);
//		tempd=*(sampoint+samcount+phcount+val4);
//		tempe=*(sampoint+samcount+phcountb+val4);
//		if ((samcount+phcount+val4)>=samend)  tempb=0;
//		if ((samcount+phcountb)>=samend) tempc=0;
//		if ((samcount+phcount+val4)>=samend)  tempd=0;
//		if ((samcount+phcountb+val4)>=samend) tempe=0;

		if ((samcount+phcount+val4)<samend)
			{
			tempb=*(sampoint+samcount+phcount+val4);
			}
		else tempb=0;
			
		if ((samcount+phcount)<samend)
			{
			tempc=*(sampoint+samcount+phcountb);
			}
		else tempc=0;
			
		if ((samcount+phcount+val4)<samend)
			{
			tempd=*(sampoint+samcount+phcountb+val4);
			}
		else tempd=0;
			
		if ((samcount+phcount+val4)<samend)
			{
			tempe=*(sampoint+samcount+phcountb+val4);
			}
		else tempe=0;

		if (incount==val1)
		  {
		  if (dir==0)
			{
			phcount++;
			phcountb--;
			}
		  if (dir==1)
			{
			phcount--;
			phcountb++;
			}
		  incount=0;
		  }

		if (incountb==val3)
		  {
		  if (dir==0) dir=1;
		  else if (dir==1) dir=0;
		  incount=0;
		  incountb=0;
		  }

		incount++;
		incountb++;

		if (opt==2)
		  {
		  temp=temp+tempb+tempd+tempe;
		  temp=temp >> 2;
		  }
		if (opt==3)
		  {
		  temp=temp+tempb+tempc-tempe;
		  temp=temp >> 2;
		  }

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 } 
	 }
   }

}

///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// Stutter DMANIP operations

// Stutter - Rectify - Amp Mod

void SAMPLEWindow::Stutterrng(int32 opt,int32 optb)
{
int32 origval;
int32 temp;
int32 tempb;
int32 maxb;
int32 mula;
int32 mulb;
int32 mixlev;
int32 mixlevb;
int32 addtyp;
int32 addtypb;

uint32 incount;

mula=samslider1;
mulb=samslider2;
addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1) || (opt==2)) // Stutter - Rectify - Amp mod
   {
   incount=position;
   if (makechans==2)
	  {
	  if (poside==0) incount=position;
	  if (poside==1) incount=position-halfmemsize;
	  if (poside==2) incount=position;
	  }
   if (poside==0) maxb=halfmemsize;
   if (poside==1) maxb=memsize;
   if (poside==2) maxb=halfmemsize;
   if (makechans==3) maxb=memsize;

   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 incount++;
	 temp=*(sampoint+samcount);
	 tempb=*(sampoint+incount);
	 origval=temp;
	 if (incount>=maxb) tempb=0;
	 if (opt==0)		// Stutter
		{
		if (addtyp==0) if (tempb<=0) temp=0;
		if (addtyp==1) if (tempb>=0) temp=0;
		}
	 if (opt==1)		// Rectify
		{
		if (addtypb==0)
		  {
		  if (addtyp==0)
			{
			if (tempb<=0)
			  {
			  if (temp>=1) temp=~temp;
			  }
			if (tempb>=1)
			  {
			  if (temp<=0) temp=~temp;
			  }
			}
		  if (addtyp==1)
			{
			if (tempb>=1)
			  {
			  if (temp>=1) temp=~temp;
			  }
			if (tempb<=0)
			  {
			  if (temp<=0) temp=~temp;
			  }
			}
		  }
		if (addtypb==1)
		  {
		  if (addtyp==0)
			{
			if (tempb>=1)
			  {
			  if (temp<=0) temp=~temp;
			  }
			}
		  if (addtyp==1)
			{
			if (tempb<=0)
			  {
			  if (temp>=1) temp=~temp;
			  }
			}
		  }
		}
	 if (opt==2)		// Amplitude Modulation
		{
		if (addtyp==1) tempb=~tempb;
		temp=temp >> 7;
		temp=temp*tempb;
		temp=temp >> 8;
		if (temp<=-32766) temp=-32766;
		if (temp>=32766) temp=32766;
		}
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (opt==1) temp=origval+temp;  // No addtypeb for opt24
		if (opt!=1)
		  {
		  if (addtypb==0) temp=origval+temp;
		  if (addtypb==1) temp=origval-temp;
		  }
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }

  }
}

// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************
// 7 band EQ MANIPS -

void SAMPLEWindow::Filterbandrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;
int32 tempe;
int32 tempf;
int32 tempg;
int32 temph;
int32 tempi;
int32 tempj;
int32 tempk;
int32 templ;
int32 tempm;
int32 tempn;
int32 tempo;
int32 tempp;

float ftemp;
float ftempb;
float ftempc;
float ftempd;
float ftempe;
float ftempf;
float ftempg;

float fil1;
float fil2;
float fil3;
float fil4;
float fil5;
float fil6;
float fil7;

int32 Count;
int32 Countb;
int32 Countc;
int32 Countd;
int32 Counte;
int32 Countf;
int32 Countg;
int32 Counth;
int32 Counti;
int32 Countj;
int32 Countk;
int32 Countl;
int32 Countm;
int32 Countn;
int32 Counto;
int32 Countp;

int32 fillev;
int32 fildplev;
float filtot;
int32 modno;
int32 repcount;

int32 addtyp;
int32 addtypb;

int32 repno;
int32 doneb;
int32 donec;

modno=1;

addtyp=samradio1;
addtypb=samradio2;

if (opt==0)  // Recreate
 {
   fil1=256;
   fil2=256;
   fil3=256;
   fil4=256;
   fil5=256;
   fil6=256;
   fil7=256;
 }

if (opt==1)  // Loundness
 {
 if (addtyp==0)
   {
   fil1=256;
   fil2=256;
   fil3=128;
   fil4=128;
   fil5=128;
   fil6=256;
   fil7=256;
   }
 if (addtyp==1)
   {
   fil1=256;
   fil2=213;
   fil3=171;
   fil4=128;
   fil5=171;
   fil6=213;
   fil7=256;
   }
 }

if (opt==2)  // UnLoudness
 {
 if (addtyp==0)
   {
   fil1=128;
   fil2=128;
   fil3=256;
   fil4=256;
   fil5=256;
   fil6=128;
   fil7=128;
   }
 if (addtyp==1)
   {
   fil1=128;
   fil2=171;
   fil3=213;
   fil4=256;
   fil5=213;
   fil6=171;
   fil7=128;
   }
 }

if (opt==3)  // Filter Very High
 {
 if (addtyp==0)
   {
   fil1=256;
   fil2=256;
   fil3=256;
   fil4=256;
   fil5=256;
   fil6=256;
   fil7=0;
   }
 if (addtyp==1)
   {
   fil1=0;
   fil2=0;
   fil3=0;
   fil4=0;
   fil5=0;
   fil6=0;
   fil7=256;
   }
 }

if (opt==4)  // Filter High Band
 {
 if (addtyp==0)
   {
   fil1=256;
   fil2=256;
   fil3=256;
   fil4=256;
   fil5=256;
   fil6=0;
   fil7=256;
   }
 if (addtyp==1)
   {
   fil1=0;
   fil2=0;
   fil3=0;
   fil4=0;
   fil5=0;
   fil6=256;
   fil7=0;
   }
 }

if (opt==5)  // Filter High Mid
 {
 if (addtyp==0)
   {
   fil1=256;
   fil2=256;
   fil3=256;
   fil4=256;
   fil5=0;
   fil6=256;
   fil7=256;
   }
 if (addtyp==1)
   {
   fil1=0;
   fil2=0;
   fil3=0;
   fil4=0;
   fil5=256;
   fil6=0;
   fil7=0;
   }
 }

if (opt==6)  // Filter Mid Band 
 {
 if (addtyp==0)
   {
   fil1=256;
   fil2=256;
   fil3=256;
   fil4=0;
   fil5=256;
   fil6=256;
   fil7=256;
   }
 if (addtyp==1)
   {
   fil1=0;
   fil2=0;
   fil3=0;
   fil4=256;
   fil5=0;
   fil6=0;
   fil7=0;
   }
 }

if (opt==7)  // Filter Low Mid
 {
 if (addtyp==0)
   {
   fil1=256;
   fil2=256;
   fil3=0;
   fil4=256;
   fil5=256;
   fil6=256;
   fil7=256;
   }
 if (addtyp==1)
   {
   fil1=0;
   fil2=0;
   fil3=356;
   fil4=0;
   fil5=0;
   fil6=0;
   fil7=0;
   }
 }

if (opt==8)  // Filter Low Band
 {
 if (addtyp==0)
   {
   fil1=256;
   fil2=0;
   fil3=256;
   fil4=256;
   fil5=256;
   fil6=256;
   fil7=256;
   }
 if (addtyp==1)
   {
   fil1=0;
   fil2=256;
   fil3=0;
   fil4=0;
   fil5=0;
   fil6=0;
   fil7=0;
   }
 }

if (opt==9)  // Filter Sub Bass
 {
 if (addtyp==0)
   {
   fil1=0;
   fil2=256;
   fil3=256;
   fil4=256;
   fil5=256;
   fil6=256;
   fil7=256;
   }
 if (addtyp==1)
   {
   fil1=256;
   fil2=0;
   fil3=0;
   fil4=0;
   fil5=0;
   fil6=0;
   fil7=0;
   }
 }

if (opt==10)  // 7 Band EQ
 {
fil1=(float)comvals[0][1];
fil2=(float)comvals[0][2];
fil3=(float)comvals[0][3];
fil4=(float)comvals[0][4];
fil5=(float)comvals[0][5];
fil6=(float)comvals[0][6];
fil7=(float)comvals[0][7];
addtypb = 1;
 }

fildplev=256;
fillev=128;

samcount=samstart;
filtot=fil1+fil2+fil3+fil4+fil5+fil6+fil7;
filtot=filtot*256;
if (filtot == 0) filtot =1;

if (addtypb==0) repno=1;
if (addtypb==1) repno=3;

for (repcount=1;repcount<=repno;repcount++)	 //  do filter a few times 
{
memdivtodo=memdiv+samstart;
samcount=samstart;

while (samcount<=samend)
 {
 for (Count=1;Count<=258;Count++)	 //  copy to main buffer  
   {
   if ((samcount+Count) >= samend) temp=0;
   else temp=*(sampoint+samcount+Count);
   filmod[modno][1][Count]=temp;
   }

 for (Count=1;Count<256;Count=Count+8)	 //  Copy to buffers  // CHANGE TO <= to cause crackles
   {
   Countb=Count+1;
   Countc=Count+2;
   Countd=Count+3;
   Counte=Count+4;
   Countf=Count+5;
   Countg=Count+6;
   Counth=Count+7;

   temp=filmod[modno][1][Count];
   tempb=filmod[modno][1][Countb];
   tempc=filmod[modno][1][Countc];
   tempd=filmod[modno][1][Countd];
   tempe=filmod[modno][1][Counte];
   tempf=filmod[modno][1][Countf];
   tempg=filmod[modno][1][Countg];
   temph=filmod[modno][1][Counth];
   temp=filmod[modno][1][Count];

   filmod[modno][2][Count]=temp;
   filmod[modno][2][Countb]=tempb;
   filmod[modno][2][Countc]=tempc;
   filmod[modno][2][Countd]=tempd;
   filmod[modno][2][Counte]=tempe;
   filmod[modno][2][Countf]=tempf;
   filmod[modno][2][Countg]=tempg;
   filmod[modno][2][Counth]=temph;

   filmod[modno][3][Count]=temp;
   filmod[modno][3][Countb]=tempb;
   filmod[modno][3][Countc]=tempc;
   filmod[modno][3][Countd]=tempd;
   filmod[modno][3][Counte]=tempe;
   filmod[modno][3][Countf]=tempf;
   filmod[modno][3][Countg]=tempg;
   filmod[modno][3][Counth]=temph;

   filmod[modno][4][Count]=temp;
   filmod[modno][4][Countb]=tempb;
   filmod[modno][4][Countc]=tempc;
   filmod[modno][4][Countd]=tempd;
   filmod[modno][4][Counte]=tempe;
   filmod[modno][4][Countf]=tempf;
   filmod[modno][4][Countg]=tempg;
   filmod[modno][4][Counth]=temph;

   filmod[modno][5][Count]=temp;
   filmod[modno][5][Countb]=tempb;
   filmod[modno][5][Countc]=tempc;
   filmod[modno][5][Countd]=tempd;
   filmod[modno][5][Counte]=tempe;
   filmod[modno][5][Countf]=tempf;
   filmod[modno][5][Countg]=tempg;
   filmod[modno][5][Counth]=temph;

   filmod[modno][6][Count]=temp;
   filmod[modno][6][Countb]=tempb;
   filmod[modno][6][Countc]=tempc;
   filmod[modno][6][Countd]=tempd;
   filmod[modno][6][Counte]=tempe;
   filmod[modno][6][Countf]=tempf;
   filmod[modno][6][Countg]=tempg;
   filmod[modno][6][Counth]=temph;

   filmod[modno][7][Count]=temp;
   filmod[modno][7][Countb]=tempb;
   filmod[modno][7][Countc]=tempc;
   filmod[modno][7][Countd]=tempd;
   filmod[modno][7][Counte]=tempe;
   filmod[modno][7][Countf]=tempf;
   filmod[modno][7][Countg]=tempg;
   filmod[modno][7][Counth]=temph;

   filmod[modno][8][Count]=temp;
   filmod[modno][8][Countb]=tempb;
   filmod[modno][8][Countc]=tempc;
   filmod[modno][8][Countd]=tempd;
   filmod[modno][8][Counte]=tempe;
   filmod[modno][8][Countf]=tempf;
   filmod[modno][8][Countg]=tempg;
   filmod[modno][8][Counth]=temph;
	}

   filmod[modno][1][0]=filstor[modno][1] >> 8;
   filmod[modno][2][0]=filstor[modno][2] >> 8;
   filmod[modno][3][0]=filstor[modno][3] >> 8;
   filmod[modno][4][0]=filstor[modno][4] >> 8;
   filmod[modno][5][0]=filstor[modno][5] >> 8;
   filmod[modno][6][0]=filstor[modno][6] >> 8;
   filmod[modno][7][0]=filstor[modno][7] >> 8;

 for (Count=0;Count<=256;Count++)	 //  Increase Resolution  
   {
   filmod[modno][1][Count]=filmod[modno][1][Count] << 8;
   filmod[modno][2][Count]=filmod[modno][2][Count] << 8;
   filmod[modno][3][Count]=filmod[modno][3][Count] << 8;
   filmod[modno][4][Count]=filmod[modno][4][Count] << 8;
   filmod[modno][5][Count]=filmod[modno][5][Count] << 8;
   filmod[modno][6][Count]=filmod[modno][6][Count] << 8;
   filmod[modno][7][Count]=filmod[modno][7][Count] << 8;
   filmod[modno][8][Count]=filmod[modno][8][Count] << 8;
   }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 2 
	 {
	 temp=filmod[modno][2][Count];
	 tempb=filmod[modno][2][Count+2];
	 tempb=tempb-temp;
	 tempb=tempb >> 1;
	 temp=temp+tempb;
	 filmod[modno][2][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 3 
	 {
	 temp=filmod[modno][3][Count];
	 tempb=filmod[modno][3][Count+4];
	 tempb=tempb-temp;
	 tempb=tempb >> 2;
	 temp=temp+tempb;
	 filmod[modno][3][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 4 
	 {
	 temp=filmod[modno][4][Count];
	 tempb=filmod[modno][4][Count+8];
	 tempb=tempb-temp;
	 tempb=tempb >> 3;
	 temp=temp+tempb;
	 filmod[modno][4][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 5 
	 {
	 temp=filmod[modno][5][Count];
	 tempb=filmod[modno][5][Count+16];
	 tempb=tempb-temp;
	 tempb=tempb >> 4;
	 temp=temp+tempb;
	 filmod[modno][5][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 6 
	 {
	 temp=filmod[modno][6][Count];
	 tempb=filmod[modno][6][Count+32];
	 tempb=tempb-temp;
	 tempb=tempb >> 5;
	 temp=temp+tempb;
	 filmod[modno][6][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 7 
	 {
	 temp=filmod[modno][7][Count];
	 tempb=filmod[modno][7][Count+64];
	 tempb=tempb-temp;
	 tempb=tempb >> 6;
	 temp=temp+tempb;
	 filmod[modno][7][Count+1]=temp;
	 }
	 
   filstor[modno][1]=filmod[modno][1][128];
   filstor[modno][2]=filmod[modno][2][128];
   filstor[modno][3]=filmod[modno][3][128];
   filstor[modno][4]=filmod[modno][4][128];
   filstor[modno][5]=filmod[modno][5][128];
   filstor[modno][6]=filmod[modno][6][128];
   filstor[modno][7]=filmod[modno][7][128];

for (Count=0;Count<=128;Count++)	 //  Very High Pass  
   {
   temp=filmod[modno][1][Count];
   tempb=filmod[modno][2][Count];
   temp=temp-tempb;
   filmod[modno][1][Count]=temp;
   }
  
for (Count=0;Count<=128;Count++)	 //  High Pass  
   {
   temp=filmod[modno][2][Count];
   tempb=filmod[modno][3][Count];
   temp=temp-tempb;
   filmod[modno][2][Count]=temp;
   }  
   
for (Count=0;Count<=128;Count++)	 //  High Mid Pass  
   {
   temp=filmod[modno][3][Count];
   tempb=filmod[modno][4][Count];
   temp=temp-tempb;
   filmod[modno][3][Count]=temp;
   }  
   
for (Count=0;Count<=128;Count++)	 //  Mid Pass  
   {
   temp=filmod[modno][4][Count];
   tempb=filmod[modno][5][Count];
   temp=temp-tempb;
   filmod[modno][4][Count]=temp;
   }  
   
for (Count=0;Count<=128;Count++)	 //  Low Mid Pass  
   {
   temp=filmod[modno][5][Count];
   tempb=filmod[modno][6][Count];
   temp=temp-tempb;
   filmod[modno][5][Count]=temp;
   }  
   
for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][6][Count];
   tempb=filmod[modno][7][Count];
   temp=temp-tempb;
   filmod[modno][6][Count]=temp;	 
   }
   
for (Count=0;Count<=128;Count++)	 //  Very Low Pass  
   {
   temp=filmod[modno][7][Count];
   filmod[modno][7][Count]=temp;  
   }

   filstor[modno][7]=filmod[modno][7][128];


for (Count=0;Count<=128;Count++)	 //  Multiply and Add	
	{
	temp=filmod[modno][1][Count];
	ftemp=(float)temp;
	ftemp=ftemp*fil7;

	tempb=filmod[modno][2][Count];
	ftempb=(float)tempb;
	ftempb=ftempb*fil6;

	tempc=filmod[modno][3][Count];
	ftempc=(float)tempc;
	ftempc=ftempc*fil5;

	tempd=filmod[modno][4][Count];
	ftempd=(float)tempd;
	ftempd=ftempd*fil4;

	tempe=filmod[modno][5][Count];
	ftempe=(float)tempe;
	ftempe=ftempe*fil3;

	tempf=filmod[modno][6][Count];
	ftempf=(float)tempf;
	ftempf=ftempf*fil2;

	tempg=filmod[modno][7][Count];
	ftempg=(float)tempg;
	ftempg=ftempg*fil1;

	ftemp=ftemp+ftempb+ftempc+ftempd+ftempe+ftempf+ftempg;
	ftemp=ftemp/filtot;
	if (ftemp>=32767) ftemp=32766;
	if (ftemp<=-32767) ftemp=-32766;
	temp=(int32)ftemp;
	filmod[modno][9][Count]=temp;	// No change to buffer 8
	}

  for (Count=1;Count<=128;Count++)	 // Copy back
	{
	temp=filmod[modno][9][Count];
	temp=temp*fillev;
	temp=temp >> 7;
	if (temp>=32767) temp=32766;
	if (temp<=-32767) temp=-32766;
	*(sampoint+samcount)=temp;
	samcount++;  
	}
  if (samcount>=memdivtodo)
	{
	done++;
	memdivtodo=memdivtodo+memdiv;
	if (repno == 1) donec = done;
	else donec = done /3;
	if (doneb != donec)
		{
		doneb = donec;
		Newdrawdonebox(3,0,97,75,doneb,drawbarside);
		}
	}
  }
  Rescalenoboxrng();
  }

}

///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// 20 band EQ -


void SAMPLEWindow::Filter20rng(int32 opt)
{

int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;
int32 tempe;
int32 tempf;
int32 tempg;
int32 temph;
int32 tempi;
int32 tempj;
int32 tempk;
int32 templ;
int32 tempm;
int32 tempn;
int32 tempo;
int32 tempp;
int32 tempq;
int32 tempr;
int32 temps;
int32 tempt;

float ftemp;
float ftempb;
float ftempc;
float ftempd;
float ftempe;
float ftempf;
float ftempg;
float ftemph;
float ftempi;
float ftempj;
float ftempk;
float ftempl;
float ftempm;
float ftempn;
float ftempo;
float ftempp;
float ftempq;
float ftempr;
float ftemps;
float ftempt;

float fil1;
float fil2;
float fil3;
float fil4;
float fil5;
float fil6;
float fil7;
float fil8;
float fil9;
float fil10;
float fil11;
float fil12;
float fil13;
float fil14;
float fil15;
float fil16;
float fil17;
float fil18;
float fil19;
float fil20;
/*
int32 fil1;
int32 fil2;
int32 fil3;
int32 fil4;
int32 fil5;
int32 fil6;
int32 fil7;
int32 fil8;
int32 fil9;
int32 fil10;
int32 fil11;
int32 fil12;
int32 fil13;
int32 fil14;
int32 fil15;
int32 fil16;
int32 fil17;
int32 fil18;
int32 fil19;
int32 fil20;
*/
int32 Count;
int32 Countb;
int32 Countc;
int32 Countd;
int32 Counte;
int32 Countf;
int32 Countg;
int32 Counth;
int32 Counti;
int32 Countj;
int32 Countk;
int32 Countl;
int32 Countm;
int32 Countn;
int32 Counto;
int32 Countp;

int32 mixlev;
int32 mixlevb;
//int32 Count;
float fillev;
float filtot;
//int32 filtot;

int32 modno;
int32 repcount;

int32 doneb;
int32 donec;

modno=1;

fil1=(float)comvals[1][1];
fil2=(float)comvals[1][2];
fil3=(float)comvals[1][3];
fil4=(float)comvals[1][4];
fil5=(float)comvals[1][5];
fil6=(float)comvals[1][6];
fil7=(float)comvals[1][7];
fil8=(float)comvals[1][8];
fil9=(float)comvals[1][9];
fil10=(float)comvals[1][10];
fil11=(float)comvals[1][11];
fil12=(float)comvals[1][12];
fil13=(float)comvals[1][13];
fil14=(float)comvals[1][14];
fil15=(float)comvals[1][15];
fil16=(float)comvals[1][16];
fil17=(float)comvals[1][17];
fil18=(float)comvals[1][18];
fil19=(float)comvals[1][19];
fil20=(float)comvals[1][20];

fillev=(float)comvals[1][0];
fillev=fillev/256;
fillev==fillev+1;

mixlev=samslider;
mixlevb=256-mixlev;

samcount=samstart;

   filtot=fil1+fil2+fil3+fil4+fil5+fil6+fil7
		  +fil8+fil9+fil10+fil11+fil12+fil13+fil14
		  +fil15+fil16+fil17+fil18+fil19+fil20;
filtot=filtot*256;
if (filtot == 0) filtot =1;

if (opt==0)  // 20 band EQ -
 {

for (repcount=1;repcount<=3;repcount++)	 //  do filter 3 times 
 {
memdivtodo=memdiv+samstart;
samcount=samstart;

while (samcount<=samend)
 {
 for (Count=1;Count<=258;Count++)	 //  copy to main buffer  
   {
   if ((samcount+Count) >= samend) temp=0;
   else temp=*(sampoint+samcount+Count);
   filmod[modno][1][Count]=temp;
   
//   temp=*(sampoint+samcount+Count);
//   filmod[modno][1][Count]=temp;
   }

 for (Count=1;Count<256;Count=Count+8)	 //  Copy to buffers  // CHANGE TO <= to cause crackles
   {
   Countb=Count+1;
   Countc=Count+2;
   Countd=Count+3;
   Counte=Count+4;
   Countf=Count+5;
   Countg=Count+6;
   Counth=Count+7;

   temp=filmod[modno][1][Count];
   tempb=filmod[modno][1][Countb];
   tempc=filmod[modno][1][Countc];
   tempd=filmod[modno][1][Countd];
   tempe=filmod[modno][1][Counte];
   tempf=filmod[modno][1][Countf];
   tempg=filmod[modno][1][Countg];
   temph=filmod[modno][1][Counth];
   temp=filmod[modno][1][Count];

   filmod[modno][2][Count]=temp;
   filmod[modno][2][Countb]=tempb;
   filmod[modno][2][Countc]=tempc;
   filmod[modno][2][Countd]=tempd;
   filmod[modno][2][Counte]=tempe;
   filmod[modno][2][Countf]=tempf;
   filmod[modno][2][Countg]=tempg;
   filmod[modno][2][Counth]=temph;

   filmod[modno][3][Count]=temp;
   filmod[modno][3][Countb]=tempb;
   filmod[modno][3][Countc]=tempc;
   filmod[modno][3][Countd]=tempd;
   filmod[modno][3][Counte]=tempe;
   filmod[modno][3][Countf]=tempf;
   filmod[modno][3][Countg]=tempg;
   filmod[modno][3][Counth]=temph;

   filmod[modno][4][Count]=temp;
   filmod[modno][4][Countb]=tempb;
   filmod[modno][4][Countc]=tempc;
   filmod[modno][4][Countd]=tempd;
   filmod[modno][4][Counte]=tempe;
   filmod[modno][4][Countf]=tempf;
   filmod[modno][4][Countg]=tempg;
   filmod[modno][4][Counth]=temph;

   filmod[modno][5][Count]=temp;
   filmod[modno][5][Countb]=tempb;
   filmod[modno][5][Countc]=tempc;
   filmod[modno][5][Countd]=tempd;
   filmod[modno][5][Counte]=tempe;
   filmod[modno][5][Countf]=tempf;
   filmod[modno][5][Countg]=tempg;
   filmod[modno][5][Counth]=temph;

   filmod[modno][6][Count]=temp;
   filmod[modno][6][Countb]=tempb;
   filmod[modno][6][Countc]=tempc;
   filmod[modno][6][Countd]=tempd;
   filmod[modno][6][Counte]=tempe;
   filmod[modno][6][Countf]=tempf;
   filmod[modno][6][Countg]=tempg;
   filmod[modno][6][Counth]=temph;

   filmod[modno][7][Count]=temp;
   filmod[modno][7][Countb]=tempb;
   filmod[modno][7][Countc]=tempc;
   filmod[modno][7][Countd]=tempd;
   filmod[modno][7][Counte]=tempe;
   filmod[modno][7][Countf]=tempf;
   filmod[modno][7][Countg]=tempg;
   filmod[modno][7][Counth]=temph;

   filmod[modno][8][Count]=temp;
   filmod[modno][8][Countb]=tempb;
   filmod[modno][8][Countc]=tempc;
   filmod[modno][8][Countd]=tempd;
   filmod[modno][8][Counte]=tempe;
   filmod[modno][8][Countf]=tempf;
   filmod[modno][8][Countg]=tempg;
   filmod[modno][8][Counth]=temph;

   filmod[modno][9][Count]=temp;
   filmod[modno][9][Countb]=tempb;
   filmod[modno][9][Countc]=tempc;
   filmod[modno][9][Countd]=tempd;
   filmod[modno][9][Counte]=tempe;
   filmod[modno][9][Countf]=tempf;
   filmod[modno][9][Countg]=tempg;
   filmod[modno][9][Counth]=temph;

   filmod[modno][10][Count]=temp;
   filmod[modno][10][Countb]=tempb;
   filmod[modno][10][Countc]=tempc;
   filmod[modno][10][Countd]=tempd;
   filmod[modno][10][Counte]=tempe;
   filmod[modno][10][Countf]=tempf;
   filmod[modno][10][Countg]=tempg;
   filmod[modno][10][Counth]=temph;

   filmod[modno][11][Count]=temp;
   filmod[modno][11][Countb]=tempb;
   filmod[modno][11][Countc]=tempc;
   filmod[modno][11][Countd]=tempd;
   filmod[modno][11][Counte]=tempe;
   filmod[modno][11][Countf]=tempf;
   filmod[modno][11][Countg]=tempg;
   filmod[modno][11][Counth]=temph;

   filmod[modno][12][Count]=temp;
   filmod[modno][12][Countb]=tempb;
   filmod[modno][12][Countc]=tempc;
   filmod[modno][12][Countd]=tempd;
   filmod[modno][12][Counte]=tempe;
   filmod[modno][12][Countf]=tempf;
   filmod[modno][12][Countg]=tempg;
   filmod[modno][12][Counth]=temph;

   filmod[modno][13][Count]=temp;
   filmod[modno][13][Countb]=tempb;
   filmod[modno][13][Countc]=tempc;
   filmod[modno][13][Countd]=tempd;
   filmod[modno][13][Counte]=tempe;
   filmod[modno][13][Countf]=tempf;
   filmod[modno][13][Countg]=tempg;
   filmod[modno][13][Counth]=temph;

   filmod[modno][14][Count]=temp;
   filmod[modno][14][Countb]=tempb;
   filmod[modno][14][Countc]=tempc;
   filmod[modno][14][Countd]=tempd;
   filmod[modno][14][Counte]=tempe;
   filmod[modno][14][Countf]=tempf;
   filmod[modno][14][Countg]=tempg;
   filmod[modno][14][Counth]=temph;

   filmod[modno][15][Count]=temp;
   filmod[modno][15][Countb]=tempb;
   filmod[modno][15][Countc]=tempc;
   filmod[modno][15][Countd]=tempd;
   filmod[modno][15][Counte]=tempe;
   filmod[modno][15][Countf]=tempf;
   filmod[modno][15][Countg]=tempg;
   filmod[modno][15][Counth]=temph;

   filmod[modno][16][Count]=temp;
   filmod[modno][16][Countb]=tempb;
   filmod[modno][16][Countc]=tempc;
   filmod[modno][16][Countd]=tempd;
   filmod[modno][16][Counte]=tempe;
   filmod[modno][16][Countf]=tempf;
   filmod[modno][16][Countg]=tempg;
   filmod[modno][16][Counth]=temph;

   filmod[modno][17][Count]=temp;
   filmod[modno][17][Countb]=tempb;
   filmod[modno][17][Countc]=tempc;
   filmod[modno][17][Countd]=tempd;
   filmod[modno][17][Counte]=tempe;
   filmod[modno][17][Countf]=tempf;
   filmod[modno][17][Countg]=tempg;
   filmod[modno][17][Counth]=temph;

   filmod[modno][18][Count]=temp;
   filmod[modno][18][Countb]=tempb;
   filmod[modno][18][Countc]=tempc;
   filmod[modno][18][Countd]=tempd;
   filmod[modno][18][Counte]=tempe;
   filmod[modno][18][Countf]=tempf;
   filmod[modno][18][Countg]=tempg;
   filmod[modno][18][Counth]=temph;

   filmod[modno][19][Count]=temp;
   filmod[modno][19][Countb]=tempb;
   filmod[modno][19][Countc]=tempc;
   filmod[modno][19][Countd]=tempd;
   filmod[modno][19][Counte]=tempe;
   filmod[modno][19][Countf]=tempf;
   filmod[modno][19][Countg]=tempg;
   filmod[modno][19][Counth]=temph;

   filmod[modno][20][Count]=temp;
   filmod[modno][20][Countb]=tempb;
   filmod[modno][20][Countc]=tempc;
   filmod[modno][20][Countd]=tempd;
   filmod[modno][20][Counte]=tempe;
   filmod[modno][20][Countf]=tempf;
   filmod[modno][20][Countg]=tempg;
   filmod[modno][20][Counth]=temph;

   filmod[modno][21][Count]=temp;
   filmod[modno][21][Countb]=tempb;
   filmod[modno][21][Countc]=tempc;
   filmod[modno][21][Countd]=tempd;
   filmod[modno][21][Counte]=tempe;
   filmod[modno][21][Countf]=tempf;
   filmod[modno][21][Countg]=tempg;
   filmod[modno][21][Counth]=temph;
   }

/* for (Count=1;Count<=258;Count++)	 //  Copy to buffers  
   {
   temp=filmod[modno][1][Count];
   filmod[modno][2][Count]=temp;
   filmod[modno][3][Count]=temp;
   filmod[modno][4][Count]=temp;
   filmod[modno][5][Count]=temp;
   filmod[modno][6][Count]=temp;
   filmod[modno][7][Count]=temp;
   filmod[modno][8][Count]=temp;
   filmod[modno][9][Count]=temp;
   filmod[modno][10][Count]=temp;
   filmod[modno][11][Count]=temp;
   filmod[modno][12][Count]=temp;
   filmod[modno][13][Count]=temp;
   filmod[modno][14][Count]=temp;
   filmod[modno][15][Count]=temp;
   filmod[modno][16][Count]=temp;
   filmod[modno][17][Count]=temp;
   filmod[modno][18][Count]=temp;
   filmod[modno][19][Count]=temp;
   filmod[modno][20][Count]=temp;
   filmod[modno][21][Count]=temp;
   }*/

   filmod[modno][1][0]=filstor[modno][1] >> 8;
   filmod[modno][2][0]=filstor[modno][2] >> 8;
   filmod[modno][3][0]=filstor[modno][3] >> 8;
   filmod[modno][4][0]=filstor[modno][4] >> 8;
   filmod[modno][5][0]=filstor[modno][5] >> 8;
   filmod[modno][6][0]=filstor[modno][6] >> 8;
   filmod[modno][7][0]=filstor[modno][7] >> 8;
   filmod[modno][8][0]=filstor[modno][8] >> 8;
   filmod[modno][9][0]=filstor[modno][9] >> 8;
   filmod[modno][10][0]=filstor[modno][10] >> 8;
   filmod[modno][11][0]=filstor[modno][11] >> 8;
   filmod[modno][12][0]=filstor[modno][12] >> 8;
   filmod[modno][13][0]=filstor[modno][13] >> 8;
   filmod[modno][14][0]=filstor[modno][14] >> 8;
   filmod[modno][15][0]=filstor[modno][15] >> 8;
   filmod[modno][16][0]=filstor[modno][16] >> 8;
   filmod[modno][17][0]=filstor[modno][17] >> 8;
   filmod[modno][18][0]=filstor[modno][18] >> 8;
   filmod[modno][19][0]=filstor[modno][19] >> 8;
   filmod[modno][20][0]=filstor[modno][20] >> 8;

 for (Count=0;Count<=258;Count++)	 //  Increase Resolution  
   {
   temp=filmod[modno][1][Count];
   filmod[modno][1][Count]=filmod[modno][1][Count] << 8;
   filmod[modno][2][Count]=filmod[modno][2][Count] << 8;
   filmod[modno][3][Count]=filmod[modno][3][Count] << 8;
   filmod[modno][4][Count]=filmod[modno][4][Count] << 8;
   filmod[modno][5][Count]=filmod[modno][5][Count] << 8;
   filmod[modno][6][Count]=filmod[modno][6][Count] << 8;
   filmod[modno][7][Count]=filmod[modno][7][Count] << 8;
   filmod[modno][8][Count]=filmod[modno][8][Count] << 8;
   filmod[modno][9][Count]=filmod[modno][9][Count] << 8;
   filmod[modno][10][Count]=filmod[modno][10][Count] << 8;
   filmod[modno][11][Count]=filmod[modno][11][Count] << 8;
   filmod[modno][12][Count]=filmod[modno][12][Count] << 8;
   filmod[modno][13][Count]=filmod[modno][13][Count] << 8;
   filmod[modno][14][Count]=filmod[modno][14][Count] << 8;
   filmod[modno][15][Count]=filmod[modno][15][Count] << 8;
   filmod[modno][16][Count]=filmod[modno][16][Count] << 8;
   filmod[modno][17][Count]=filmod[modno][17][Count] << 8;
   filmod[modno][18][Count]=filmod[modno][18][Count] << 8;
   filmod[modno][19][Count]=filmod[modno][19][Count] << 8;
   filmod[modno][20][Count]=filmod[modno][20][Count] << 8;
   filmod[modno][21][Count]=filmod[modno][21][Count] << 8;
   }



//1  -1 44
//2  -1 22
//3  -1 14.6
//4  -1 11
//5  -1 8.8
//6  -1 7.3
//7  -1 6.2
//8  -2 5.5
//10 -2 4.4
//12 -2 3.6
//14 -3 3.1
//17 -3 2.6
//20 -4 2.2
//24 -4 1.8
//28 -5 1.57
//33 -6 1.3
//39 -7 1.12
//46 -8 0.96
//54 -10 0.81
//64	 0.68


for (Count=0;Count<=132;Count++)	 //  Filter Buffer 2 -2
	 {
	 temp=filmod[modno][2][Count];
	 tempb=filmod[modno][2][Count+2];
	 tempb=tempb-temp;
	 tempb=tempb/2;
	 temp=temp+tempb;
	 filmod[modno][2][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 3 
	 {
	 temp=filmod[modno][3][Count];
	 tempb=filmod[modno][3][Count+3];
	 tempb=tempb-temp;
	 tempb=tempb/3;
	 temp=temp+tempb;
	 filmod[modno][3][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 4 
	 {
	 temp=filmod[modno][4][Count];
	 tempb=filmod[modno][4][Count+4];
	 tempb=tempb-temp;
	 tempb=tempb/4;
	 temp=temp+tempb;
	 filmod[modno][4][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 5 
	 {
	 temp=filmod[modno][5][Count];
	 tempb=filmod[modno][5][Count+5];
	 tempb=tempb-temp;
	 tempb=tempb/5;
	 temp=temp+tempb;
	 filmod[modno][5][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 6 
	 {
	 temp=filmod[modno][6][Count];
	 tempb=filmod[modno][6][Count+6];
	 tempb=tempb-temp;
	 tempb=tempb/6;
	 temp=temp+tempb;
	 filmod[modno][6][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 7 
	 {
	 temp=filmod[modno][7][Count];
	 tempb=filmod[modno][7][Count+7];
	 tempb=tempb-temp;
	 tempb=tempb/7;
	 temp=temp+tempb;
	 filmod[modno][7][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 8 
	 {
	 temp=filmod[modno][8][Count];
	 tempb=filmod[modno][8][Count+8];
	 tempb=tempb-temp;
	 tempb=tempb/8;
	 temp=temp+tempb;
	 filmod[modno][8][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 9 
	 {
	 temp=filmod[modno][9][Count];
	 tempb=filmod[modno][9][Count+10];
	 tempb=tempb-temp;
	 tempb=tempb/10;
	 temp=temp+tempb;
	 filmod[modno][9][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 10 
	 {
	 temp=filmod[modno][10][Count];
	 tempb=filmod[modno][10][Count+12];
	 tempb=tempb-temp;
	 tempb=tempb/12;
	 temp=temp+tempb;
	 filmod[modno][10][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 11 
	 {
	 temp=filmod[modno][11][Count];
	 tempb=filmod[modno][11][Count+14];
	 tempb=tempb-temp;
	 tempb=tempb/14;
	 temp=temp+tempb;
	 filmod[modno][11][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 12 
	 {
	 temp=filmod[modno][12][Count];
	 tempb=filmod[modno][12][Count+17];
	 tempb=tempb-temp;
	 tempb=tempb/17;
	 temp=temp+tempb;
	 filmod[modno][12][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 13 
	 {
	 temp=filmod[modno][13][Count];
	 tempb=filmod[modno][13][Count+20];
	 tempb=tempb-temp;
	 tempb=tempb/20;
	 temp=temp+tempb;
	 filmod[modno][13][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 14 
	 {
	 temp=filmod[modno][14][Count];
	 tempb=filmod[modno][14][Count+24];
	 tempb=tempb-temp;
	 tempb=tempb/24;
	 temp=temp+tempb;
	 filmod[modno][14][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 15 
	 {
	 temp=filmod[modno][15][Count];
	 tempb=filmod[modno][15][Count+28];
	 tempb=tempb-temp;
	 tempb=tempb/28;
	 temp=temp+tempb;
	 filmod[modno][15][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 16 
	 {
	 temp=filmod[modno][16][Count];
	 tempb=filmod[modno][16][Count+33];
	 tempb=tempb-temp;
	 tempb=tempb/33;
	 temp=temp+tempb;
	 filmod[modno][16][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 17 
	 {
	 temp=filmod[modno][17][Count];
	 tempb=filmod[modno][17][Count+39];
	 tempb=tempb-temp;
	 tempb=tempb/39;
	 temp=temp+tempb;
	 filmod[modno][17][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 18 
	 {
	 temp=filmod[modno][18][Count];
	 tempb=filmod[modno][18][Count+46];
	 tempb=tempb-temp;
	 tempb=tempb/46;
	 temp=temp+tempb;
	 filmod[modno][18][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 19 
	 {
	 temp=filmod[modno][19][Count];
	 tempb=filmod[modno][19][Count+54];
	 tempb=tempb-temp;
	 tempb=tempb/54;
	 temp=temp+tempb;
	 filmod[modno][19][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 20  -64
	 {
	 temp=filmod[modno][20][Count];
	 tempb=filmod[modno][20][Count+64];
	 tempb=tempb-temp;
	 tempb=tempb/62;
	 temp=temp+tempb;
	 filmod[modno][20][Count+1]=temp;
	 }

   filstor[modno][1]=filmod[modno][1][128];
   filstor[modno][2]=filmod[modno][2][128];
   filstor[modno][3]=filmod[modno][3][128];
   filstor[modno][4]=filmod[modno][4][128];
   filstor[modno][5]=filmod[modno][5][128];
   filstor[modno][6]=filmod[modno][6][128];
   filstor[modno][7]=filmod[modno][7][128];
   filstor[modno][8]=filmod[modno][8][128];
   filstor[modno][9]=filmod[modno][9][128];
   filstor[modno][10]=filmod[modno][10][128];
   filstor[modno][11]=filmod[modno][11][128];
   filstor[modno][12]=filmod[modno][12][128];
   filstor[modno][13]=filmod[modno][13][128];
   filstor[modno][14]=filmod[modno][14][128];
   filstor[modno][15]=filmod[modno][15][128];
   filstor[modno][16]=filmod[modno][16][128];
   filstor[modno][17]=filmod[modno][17][128];
   filstor[modno][18]=filmod[modno][18][128];
   filstor[modno][19]=filmod[modno][19][128];
   filstor[modno][20]=filmod[modno][20][128];

for (Count=0;Count<=128;Count++)	 //  Very High Pass  
   {
   temp=filmod[modno][1][Count];
   tempb=filmod[modno][2][Count];
   temp=temp-tempb;
   filmod[modno][1][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Very High Pass  
   {
   temp=filmod[modno][2][Count];
   tempb=filmod[modno][3][Count];
   temp=temp-tempb;
   filmod[modno][2][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Very High Pass  
   {
   temp=filmod[modno][3][Count];
   tempb=filmod[modno][4][Count];
   temp=temp-tempb;
   filmod[modno][3][Count]=temp;
   }
  
for (Count=0;Count<=128;Count++)	 //  High Pass  
   {
   temp=filmod[modno][4][Count];
   tempb=filmod[modno][5][Count];
   temp=temp-tempb;
   filmod[modno][4][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  High Pass  
   {
   temp=filmod[modno][5][Count];
   tempb=filmod[modno][6][Count];
   temp=temp-tempb;
   filmod[modno][5][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  High Pass  
   {
   temp=filmod[modno][6][Count];
   tempb=filmod[modno][7][Count];
   temp=temp-tempb;
   filmod[modno][6][Count]=temp;
   }
   
for (Count=0;Count<=128;Count++)	 //  High Mid Pass  
   {
   temp=filmod[modno][7][Count];
   tempb=filmod[modno][8][Count];
   temp=temp-tempb;
   filmod[modno][7][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  High Mid Pass  
   {
   temp=filmod[modno][8][Count];
   tempb=filmod[modno][9][Count];
   temp=temp-tempb;
   filmod[modno][8][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  High Mid Pass  
   {
   temp=filmod[modno][9][Count];
   tempb=filmod[modno][10][Count];
   temp=temp-tempb;
   filmod[modno][9][Count]=temp;
   }
   
for (Count=0;Count<=128;Count++)	 //  Mid Pass  
   {
   temp=filmod[modno][10][Count];
   tempb=filmod[modno][11][Count];
   temp=temp-tempb;
   filmod[modno][10][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Mid Pass  
   {
   temp=filmod[modno][11][Count];
   tempb=filmod[modno][12][Count];
   temp=temp-tempb;
   filmod[modno][11][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Mid Pass  
   {
   temp=filmod[modno][12][Count];
   tempb=filmod[modno][13][Count];
   temp=temp-tempb;
   filmod[modno][12][Count]=temp;
   }
   
for (Count=0;Count<=128;Count++)	 //  Low Mid Pass  
   {
   temp=filmod[modno][13][Count];
   tempb=filmod[modno][14][Count];
   temp=temp-tempb;
   filmod[modno][13][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Low Mid Pass  
   {
   temp=filmod[modno][14][Count];
   tempb=filmod[modno][15][Count];
   temp=temp-tempb;
   filmod[modno][14][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Low Mid Pass  
   {
   temp=filmod[modno][15][Count];
   tempb=filmod[modno][16][Count];
   temp=temp-tempb;
   filmod[modno][15][Count]=temp;
   }
   
for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][16][Count];
   tempb=filmod[modno][17][Count];
   temp=temp-tempb;
   filmod[modno][16][Count]=temp;	 
   }

for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][17][Count];
   tempb=filmod[modno][18][Count];
   temp=temp-tempb;
   filmod[modno][17][Count]=temp;	 
   }

for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][18][Count];
   tempb=filmod[modno][19][Count];
   temp=temp-tempb;
   filmod[modno][18][Count]=temp;	 
   }

for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][19][Count];
   tempb=filmod[modno][20][Count];
   temp=temp-tempb;
   filmod[modno][19][Count]=temp;	 
   }
   
for (Count=0;Count<=128;Count++)	 //  Very Low Pass  
   {
   temp=filmod[modno][20][Count];
   filmod[modno][20][Count]=temp;  
   }

   filstor[modno][20]=filmod[modno][20][128];


for (Count=0;Count<=128;Count++)	 //  Multiply and Add	
   {
	temp=filmod[modno][1][Count];
	ftemp=(float)temp;
	ftemp=ftemp*fil20;
	  
	tempb=filmod[modno][2][Count];
	ftempb=(float)tempb;
	ftempb=ftempb*fil19;
	  
	tempc=filmod[modno][3][Count];
	ftempc=(float)tempc;
	ftempc=ftempc*fil18;
	  
	tempd=filmod[modno][4][Count];
	ftempd=(float)tempd;
	ftempd=ftempd*fil17;
	  
	tempe=filmod[modno][5][Count];
	ftempe=(float)tempe;
	ftempe=ftempe*fil16;
	  
	tempf=filmod[modno][6][Count];
	ftempf=(float)tempf;
	ftempf=ftempf*fil15;
	  
	tempg=filmod[modno][7][Count];
	ftempg=(float)tempg;
	ftempg=ftempg*fil14;

	temph=filmod[modno][8][Count];
	ftemph=(float)temph;
	ftemph=ftemph*fil13;
	  
	tempi=filmod[modno][9][Count];
	ftempi=(float)tempi;
	ftempi=ftempi*fil12;
	  
	tempj=filmod[modno][10][Count];
	ftempj=(float)tempj;
	ftempj=ftempj*fil11;
	  
	tempk=filmod[modno][11][Count];
	ftempk=(float)tempk;
	ftempk=ftempk*fil10;
	  
	templ=filmod[modno][12][Count];
	ftempl=(float)templ;
	ftempl=ftempl*fil9;
	  
	tempm=filmod[modno][13][Count];
	ftempm=(float)tempm;
	ftempm=ftempm*fil8;
	  
	tempn=filmod[modno][14][Count];
	ftempn=(float)tempn;
	ftempn=ftempn*fil7;

	tempo=filmod[modno][15][Count];
	ftempo=(float)tempo;
	ftempo=ftempo*fil6;
	  
	tempp=filmod[modno][16][Count];
	ftempp=(float)tempp;
	ftempp=ftempp*fil5;
	  
	tempq=filmod[modno][17][Count];
	ftempq=(float)tempq;
	ftempq=ftempq*fil4;
	  
	tempr=filmod[modno][18][Count];
	ftempr=(float)tempr;
	ftempr=ftempr*fil3;
	  
	temps=filmod[modno][19][Count];
	ftemps=(float)temps;
	ftemps=ftemps*fil2;
	  
	tempt=filmod[modno][20][Count];
	ftempt=(float)tempt;
	ftempt=ftempt*fil1;

	ftemp=ftemp+ftempb+ftempc+ftempd+ftempe+ftempf+ftempg
	+ftemph+ftempi+ftempj+ftempk+ftempl+ftempm+ftempn
	+ftempo+ftempp+ftempq+ftempr+ftemps+ftempt;

	ftemp=ftemp/filtot;
	ftemp=ftemp*fillev;

	if (ftemp>=32767) ftemp=32766;
	if (ftemp<=-32767) ftemp=-32766;
	temp=(int32)ftemp;
	filmod[modno][21][Count]=temp;		// No change to buffer 21 
	}

  for (Count=1;Count<=128;Count++)	 // Copy back
	{
	temp=filmod[modno][21][Count];
// 	temp=temp >> 7;
	if (temp>=32767) temp=32766;
	if (temp<=-32767) temp=-32766;
	*(sampoint+samcount)=temp;
	samcount++;
	}
	
  if (samcount>=memdivtodo)
	{
	done++;
	memdivtodo=memdivtodo+memdiv;
	donec = done /3;
	if (doneb != donec)
		{
		doneb = donec;
		Newdrawdonebox(3,0,97,75,doneb,drawbarside);
		}
	}

  }
//  Rescalenoboxrng();
  }
 }

}


///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// 20 band EQ -

/* ORIINAL
void SAMPLEWindow::Filter20rng(int32 opt)
{

int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;
int32 tempe;
int32 tempf;
int32 tempg;
int32 temph;
int32 tempi;
int32 tempj;
int32 tempk;
int32 templ;
int32 tempm;
int32 tempn;
int32 tempo;
int32 tempp;
int32 tempq;
int32 tempr;
int32 temps;
int32 tempt;

int32 fil1;
int32 fil2;
int32 fil3;
int32 fil4;
int32 fil5;
int32 fil6;
int32 fil7;
int32 fil8;
int32 fil9;
int32 fil10;
int32 fil11;
int32 fil12;
int32 fil13;
int32 fil14;
int32 fil15;
int32 fil16;
int32 fil17;
int32 fil18;
int32 fil19;
int32 fil20;

int32 mixlev;
int32 mixlevb;
int32 Count;
int32 fillev;

int32 filtot;
int32 modno;
int32 repcount;

modno=1;

fil1=comvals[1][1];
fil2=comvals[1][2];
fil3=comvals[1][3];
fil4=comvals[1][4];
fil5=comvals[1][5];
fil6=comvals[1][6];
fil7=comvals[1][7];
fil8=comvals[1][8];
fil9=comvals[1][9];
fil10=comvals[1][10];
fil11=comvals[1][11];
fil12=comvals[1][12];
fil13=comvals[1][13];
fil14=comvals[1][14];
fil15=comvals[1][15];
fil16=comvals[1][16];
fil17=comvals[1][17];
fil18=comvals[1][18];
fil19=comvals[1][19];
fil20=comvals[1][20];

fillev=comvals[1][0];

mixlev=samslider;
mixlevb=256-mixlev;

samcount=samstart;

   filtot=fil1+fil2+fil3+fil4+fil5+fil6+fil7
		  +fil8+fil9+fil10+fil11+fil12+fil13+fil14
		  +fil15+fil16+fil17+fil18+fil19+fil20;
if (filtot == 0) filtot =1;

if (opt==0)  // 20 band EQ -
 {

for (repcount=1;repcount<=3;repcount++)	 //  do filter 3 times 
 {
samcount=samstart;

while (samcount<=samend)
 {
 for (Count=1;Count<=258;Count++)	 //  copy to main buffer  
   {
   if ((samcount+Count) >= samend) temp=0;
   else temp=*(sampoint+samcount+Count);
   filmod[modno][1][Count]=temp;
   
//   temp=*(sampoint+samcount+Count);
//   filmod[modno][1][Count]=temp;
   }
   
 for (Count=1;Count<=258;Count++)	 //  Copy to buffers  
   {
   temp=filmod[modno][1][Count];
   filmod[modno][2][Count]=temp;
   filmod[modno][3][Count]=temp;
   filmod[modno][4][Count]=temp;
   filmod[modno][5][Count]=temp;
   filmod[modno][6][Count]=temp;
   filmod[modno][7][Count]=temp;
   filmod[modno][8][Count]=temp;
   filmod[modno][9][Count]=temp;
   filmod[modno][10][Count]=temp;
   filmod[modno][11][Count]=temp;
   filmod[modno][12][Count]=temp;
   filmod[modno][13][Count]=temp;
   filmod[modno][14][Count]=temp;
   filmod[modno][15][Count]=temp;
   filmod[modno][16][Count]=temp;
   filmod[modno][17][Count]=temp;
   filmod[modno][18][Count]=temp;
   filmod[modno][19][Count]=temp;
   filmod[modno][20][Count]=temp;
   filmod[modno][21][Count]=temp;
   }

   filmod[modno][1][0]=filstor[modno][1] >> 8;
   filmod[modno][2][0]=filstor[modno][2] >> 8;
   filmod[modno][3][0]=filstor[modno][3] >> 8;
   filmod[modno][4][0]=filstor[modno][4] >> 8;
   filmod[modno][5][0]=filstor[modno][5] >> 8;
   filmod[modno][6][0]=filstor[modno][6] >> 8;
   filmod[modno][7][0]=filstor[modno][7] >> 8;
   filmod[modno][8][0]=filstor[modno][8] >> 8;
   filmod[modno][9][0]=filstor[modno][9] >> 8;
   filmod[modno][10][0]=filstor[modno][10] >> 8;
   filmod[modno][11][0]=filstor[modno][11] >> 8;
   filmod[modno][12][0]=filstor[modno][12] >> 8;
   filmod[modno][13][0]=filstor[modno][13] >> 8;
   filmod[modno][14][0]=filstor[modno][14] >> 8;
   filmod[modno][15][0]=filstor[modno][15] >> 8;
   filmod[modno][16][0]=filstor[modno][16] >> 8;
   filmod[modno][17][0]=filstor[modno][17] >> 8;
   filmod[modno][18][0]=filstor[modno][18] >> 8;
   filmod[modno][19][0]=filstor[modno][19] >> 8;
   filmod[modno][20][0]=filstor[modno][20] >> 8;

 for (Count=0;Count<=258;Count++)	 //  Increase Resolution  
   {
   temp=filmod[modno][1][Count];
   filmod[modno][1][Count]=filmod[modno][1][Count] << 8;
   filmod[modno][2][Count]=filmod[modno][2][Count] << 8;
   filmod[modno][3][Count]=filmod[modno][3][Count] << 8;
   filmod[modno][4][Count]=filmod[modno][4][Count] << 8;
   filmod[modno][5][Count]=filmod[modno][5][Count] << 8;
   filmod[modno][6][Count]=filmod[modno][6][Count] << 8;
   filmod[modno][7][Count]=filmod[modno][7][Count] << 8;
   filmod[modno][8][Count]=filmod[modno][8][Count] << 8;
   filmod[modno][9][Count]=filmod[modno][9][Count] << 8;
   filmod[modno][10][Count]=filmod[modno][10][Count] << 8;
   filmod[modno][11][Count]=filmod[modno][11][Count] << 8;
   filmod[modno][12][Count]=filmod[modno][12][Count] << 8;
   filmod[modno][13][Count]=filmod[modno][13][Count] << 8;
   filmod[modno][14][Count]=filmod[modno][14][Count] << 8;
   filmod[modno][15][Count]=filmod[modno][15][Count] << 8;
   filmod[modno][16][Count]=filmod[modno][16][Count] << 8;
   filmod[modno][17][Count]=filmod[modno][17][Count] << 8;
   filmod[modno][18][Count]=filmod[modno][18][Count] << 8;
   filmod[modno][19][Count]=filmod[modno][19][Count] << 8;
   filmod[modno][20][Count]=filmod[modno][20][Count] << 8;
   filmod[modno][21][Count]=filmod[modno][21][Count] << 8;
   }



//1  -1 44
//2  -1 22
//3  -1 14.6
//4  -1 11
//5  -1 8.8
//6  -1 7.3
//7  -1 6.2
//8  -2 5.5
//10 -2 4.4
//12 -2 3.6
//14 -3 3.1
//17 -3 2.6
//20 -4 2.2
//24 -4 1.8
//28 -5 1.57
//33 -6 1.3
//39 -7 1.12
//46 -8 0.96
//54 -10 0.81
//64	 0.68


for (Count=0;Count<=132;Count++)	 //  Filter Buffer 2 -2
	 {
	 temp=filmod[modno][2][Count];
	 tempb=filmod[modno][2][Count+2];
	 tempb=tempb-temp;
	 tempb=tempb/2;
	 temp=temp+tempb;
	 filmod[modno][2][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 3 
	 {
	 temp=filmod[modno][3][Count];
	 tempb=filmod[modno][3][Count+3];
	 tempb=tempb-temp;
	 tempb=tempb/3;
	 temp=temp+tempb;
	 filmod[modno][3][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 4 
	 {
	 temp=filmod[modno][4][Count];
	 tempb=filmod[modno][4][Count+4];
	 tempb=tempb-temp;
	 tempb=tempb/4;
	 temp=temp+tempb;
	 filmod[modno][4][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 5 
	 {
	 temp=filmod[modno][5][Count];
	 tempb=filmod[modno][5][Count+5];
	 tempb=tempb-temp;
	 tempb=tempb/5;
	 temp=temp+tempb;
	 filmod[modno][5][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 6 
	 {
	 temp=filmod[modno][6][Count];
	 tempb=filmod[modno][6][Count+6];
	 tempb=tempb-temp;
	 tempb=tempb/6;
	 temp=temp+tempb;
	 filmod[modno][6][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 7 
	 {
	 temp=filmod[modno][7][Count];
	 tempb=filmod[modno][7][Count+7];
	 tempb=tempb-temp;
	 tempb=tempb/7;
	 temp=temp+tempb;
	 filmod[modno][7][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 8 
	 {
	 temp=filmod[modno][8][Count];
	 tempb=filmod[modno][8][Count+8];
	 tempb=tempb-temp;
	 tempb=tempb/8;
	 temp=temp+tempb;
	 filmod[modno][8][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 9 
	 {
	 temp=filmod[modno][9][Count];
	 tempb=filmod[modno][9][Count+10];
	 tempb=tempb-temp;
	 tempb=tempb/10;
	 temp=temp+tempb;
	 filmod[modno][9][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 10 
	 {
	 temp=filmod[modno][10][Count];
	 tempb=filmod[modno][10][Count+12];
	 tempb=tempb-temp;
	 tempb=tempb/12;
	 temp=temp+tempb;
	 filmod[modno][10][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 11 
	 {
	 temp=filmod[modno][11][Count];
	 tempb=filmod[modno][11][Count+14];
	 tempb=tempb-temp;
	 tempb=tempb/14;
	 temp=temp+tempb;
	 filmod[modno][11][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 12 
	 {
	 temp=filmod[modno][12][Count];
	 tempb=filmod[modno][12][Count+17];
	 tempb=tempb-temp;
	 tempb=tempb/17;
	 temp=temp+tempb;
	 filmod[modno][12][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 13 
	 {
	 temp=filmod[modno][13][Count];
	 tempb=filmod[modno][13][Count+20];
	 tempb=tempb-temp;
	 tempb=tempb/20;
	 temp=temp+tempb;
	 filmod[modno][13][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 14 
	 {
	 temp=filmod[modno][14][Count];
	 tempb=filmod[modno][14][Count+24];
	 tempb=tempb-temp;
	 tempb=tempb/24;
	 temp=temp+tempb;
	 filmod[modno][14][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 15 
	 {
	 temp=filmod[modno][15][Count];
	 tempb=filmod[modno][15][Count+28];
	 tempb=tempb-temp;
	 tempb=tempb/28;
	 temp=temp+tempb;
	 filmod[modno][15][Count+1]=temp;
	 }
	 
for (Count=0;Count<=132;Count++)	 //  Filter Buffer 16 
	 {
	 temp=filmod[modno][16][Count];
	 tempb=filmod[modno][16][Count+33];
	 tempb=tempb-temp;
	 tempb=tempb/33;
	 temp=temp+tempb;
	 filmod[modno][16][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 17 
	 {
	 temp=filmod[modno][17][Count];
	 tempb=filmod[modno][17][Count+39];
	 tempb=tempb-temp;
	 tempb=tempb/39;
	 temp=temp+tempb;
	 filmod[modno][17][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 18 
	 {
	 temp=filmod[modno][18][Count];
	 tempb=filmod[modno][18][Count+46];
	 tempb=tempb-temp;
	 tempb=tempb/46;
	 temp=temp+tempb;
	 filmod[modno][18][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 19 
	 {
	 temp=filmod[modno][19][Count];
	 tempb=filmod[modno][19][Count+54];
	 tempb=tempb-temp;
	 tempb=tempb/54;
	 temp=temp+tempb;
	 filmod[modno][19][Count+1]=temp;
	 }

for (Count=0;Count<=132;Count++)	 //  Filter Buffer 20  -64
	 {
	 temp=filmod[modno][20][Count];
	 tempb=filmod[modno][20][Count+64];
	 tempb=tempb-temp;
	 tempb=tempb/62;
	 temp=temp+tempb;
	 filmod[modno][20][Count+1]=temp;
	 }


   filstor[modno][1]=filmod[modno][1][128];
   filstor[modno][2]=filmod[modno][2][128];
   filstor[modno][3]=filmod[modno][3][128];
   filstor[modno][4]=filmod[modno][4][128];
   filstor[modno][5]=filmod[modno][5][128];
   filstor[modno][6]=filmod[modno][6][128];
   filstor[modno][7]=filmod[modno][7][128];
   filstor[modno][8]=filmod[modno][8][128];
   filstor[modno][9]=filmod[modno][9][128];
   filstor[modno][10]=filmod[modno][10][128];
   filstor[modno][11]=filmod[modno][11][128];
   filstor[modno][12]=filmod[modno][12][128];
   filstor[modno][13]=filmod[modno][13][128];
   filstor[modno][14]=filmod[modno][14][128];
   filstor[modno][15]=filmod[modno][15][128];
   filstor[modno][16]=filmod[modno][16][128];
   filstor[modno][17]=filmod[modno][17][128];
   filstor[modno][18]=filmod[modno][18][128];
   filstor[modno][19]=filmod[modno][19][128];
   filstor[modno][20]=filmod[modno][20][128];

for (Count=0;Count<=128;Count++)	 //  Very High Pass  
   {
   temp=filmod[modno][1][Count];
   tempb=filmod[modno][2][Count];
   temp=temp-tempb;
   filmod[modno][1][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Very High Pass  
   {
   temp=filmod[modno][2][Count];
   tempb=filmod[modno][3][Count];
   temp=temp-tempb;
   filmod[modno][2][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Very High Pass  
   {
   temp=filmod[modno][3][Count];
   tempb=filmod[modno][4][Count];
   temp=temp-tempb;
   filmod[modno][3][Count]=temp;
   }
  
for (Count=0;Count<=128;Count++)	 //  High Pass  
   {
   temp=filmod[modno][4][Count];
   tempb=filmod[modno][5][Count];
   temp=temp-tempb;
   filmod[modno][4][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  High Pass  
   {
   temp=filmod[modno][5][Count];
   tempb=filmod[modno][6][Count];
   temp=temp-tempb;
   filmod[modno][5][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  High Pass  
   {
   temp=filmod[modno][6][Count];
   tempb=filmod[modno][7][Count];
   temp=temp-tempb;
   filmod[modno][6][Count]=temp;
   }
   
for (Count=0;Count<=128;Count++)	 //  High Mid Pass  
   {
   temp=filmod[modno][7][Count];
   tempb=filmod[modno][8][Count];
   temp=temp-tempb;
   filmod[modno][7][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  High Mid Pass  
   {
   temp=filmod[modno][8][Count];
   tempb=filmod[modno][9][Count];
   temp=temp-tempb;
   filmod[modno][8][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  High Mid Pass  
   {
   temp=filmod[modno][9][Count];
   tempb=filmod[modno][10][Count];
   temp=temp-tempb;
   filmod[modno][9][Count]=temp;
   }
   
for (Count=0;Count<=128;Count++)	 //  Mid Pass  
   {
   temp=filmod[modno][10][Count];
   tempb=filmod[modno][11][Count];
   temp=temp-tempb;
   filmod[modno][10][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Mid Pass  
   {
   temp=filmod[modno][11][Count];
   tempb=filmod[modno][12][Count];
   temp=temp-tempb;
   filmod[modno][11][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Mid Pass  
   {
   temp=filmod[modno][12][Count];
   tempb=filmod[modno][13][Count];
   temp=temp-tempb;
   filmod[modno][12][Count]=temp;
   }
   
for (Count=0;Count<=128;Count++)	 //  Low Mid Pass  
   {
   temp=filmod[modno][13][Count];
   tempb=filmod[modno][14][Count];
   temp=temp-tempb;
   filmod[modno][13][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Low Mid Pass  
   {
   temp=filmod[modno][14][Count];
   tempb=filmod[modno][15][Count];
   temp=temp-tempb;
   filmod[modno][14][Count]=temp;
   }

for (Count=0;Count<=128;Count++)	 //  Low Mid Pass  
   {
   temp=filmod[modno][15][Count];
   tempb=filmod[modno][16][Count];
   temp=temp-tempb;
   filmod[modno][15][Count]=temp;
   }
   
for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][16][Count];
   tempb=filmod[modno][17][Count];
   temp=temp-tempb;
   filmod[modno][16][Count]=temp;	 
   }

for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][17][Count];
   tempb=filmod[modno][18][Count];
   temp=temp-tempb;
   filmod[modno][17][Count]=temp;	 
   }

for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][18][Count];
   tempb=filmod[modno][19][Count];
   temp=temp-tempb;
   filmod[modno][18][Count]=temp;	 
   }

for (Count=0;Count<=128;Count++)	 //  Low Pass  
   {
   temp=filmod[modno][19][Count];
   tempb=filmod[modno][20][Count];
   temp=temp-tempb;
   filmod[modno][19][Count]=temp;	 
   }
   
for (Count=0;Count<=128;Count++)	 //  Very Low Pass  
   {
   temp=filmod[modno][20][Count];
   filmod[modno][20][Count]=temp;  
   }

   filstor[modno][20]=filmod[modno][20][128];


for (Count=0;Count<=128;Count++)	 //  Multiply and Add	
   {
   
	  temp=filmod[modno][1][Count];
	  temp=temp*fil20;
	  
	  tempb=filmod[modno][2][Count];
	  tempb=tempb*fil19;
	  
	  tempc=filmod[modno][3][Count];
	  tempc=tempc*fil18;
	  
	  tempd=filmod[modno][4][Count];
	  tempd=tempd*fil17;
	  
	  tempe=filmod[modno][5][Count];
	  tempe=tempe*fil16;
	  
	  tempf=filmod[modno][6][Count];
	  tempf=tempf*fil15;
	  
	  tempg=filmod[modno][7][Count];
	  tempg=tempg*fil14;

	  temph=filmod[modno][8][Count];
	  temph=temph*fil13;
	  
	  tempi=filmod[modno][9][Count];
	  tempi=tempi*fil12;
	  
	  tempj=filmod[modno][10][Count];
	  tempj=tempj*fil11;
	  
	  tempk=filmod[modno][11][Count];
	  tempk=tempk*fil10;
	  
	  templ=filmod[modno][12][Count];
	  templ=templ*fil9;
	  
	  tempm=filmod[modno][13][Count];
	  tempm=tempm*fil8;
	  
	  tempn=filmod[modno][14][Count];
	  tempn=tempn*fil7;

	  tempo=filmod[modno][15][Count];
	  tempo=tempo*fil6;
	  
	  tempp=filmod[modno][16][Count];
	  tempp=tempp*fil5;
	  
	  tempq=filmod[modno][17][Count];
	  tempq=tempq*fil4;
	  
	  tempr=filmod[modno][18][Count];
	  tempr=tempr*fil3;
	  
	  temps=filmod[modno][19][Count];
	  temps=temps*fil2;
	  
	  tempt=filmod[modno][20][Count];
	  tempt=tempt*fil1;

	  temp=temp+tempb+tempc+tempd+tempe+tempf+tempg
	  +temph+tempi+tempj+tempk+templ+tempm+tempn
	  +tempo+tempp+tempq+tempr+temps+tempt;

	  temp=temp/filtot;
	  temp=temp >> 8;

	  if (temp>=32767) temp=32766;
	  if (temp<=-32767) temp=-32766;
	  filmod[modno][21][Count]=temp;		// No change to buffer 21 
	  }

  for (Count=1;Count<=128;Count++)	 // Copy back
	{
	temp=filmod[modno][21][Count];
	temp=temp*fillev;
	temp=temp >> 8;
	if (temp>=32767) temp=32766;
	if (temp<=-32767) temp=-32766;
	*(sampoint+samcount)=temp;
	samcount++;
	}

  }
//  Rescalenoboxrng();
  if (makechans!=2) done=repcount << 2;
  if (makechans==2) done=done+2;
  Newdrawdonebox(3,5,100,75,done,drawbarside);
  }
 }

}
*/
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************

// Vibrato and Vibrato Delay  Effects

void SAMPLEWindow::Vibraterng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;

int32 tempb2;
int32 tempb3;
int32 tempb4;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 incount;
int32 incountb;
int32 incountc;
int32 phcount;
int32 phcountb;
int32 dir;
uint32 test;

int32 rphcount;
int32 rphcountb;

int32 val4b;

int32 length;
int32 sublength;

uint32 lensam;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

incount=0;
incountb=0;
incountc=0;
phcount=0;
phcountb=val1;
rphcount=0;
rphcountb=val1;
dir=0;

if ((opt==0) || (opt==1) || (opt==2))
{

if (opt==0)		 //  Vibrato 
	{
	lensam=samend-samstart;
	lensam=lensam/32;
	val1=val1+16;
	val3=val3+1;
	sublength=val3 << 4;
	dir=0;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		origval=*(sampoint+samcount);

		if (samcount>=test)  temp=0;
		else temp=*(sampoint+samcount+phcount);

		if (incount==val1)
			{
			if (dir==0)
				{
				phcount++;
				}
			if (dir==1)
				{
				phcount++;
				}
			test = samend-phcount;
			incount=0;
			}

		if (incountb==sublength)
			{
			if (dir==0)
				{
				val1--;
				}
			if (dir==1)
				{
				val1++;
				}
			incount=0;
			incountb=0;
			if (val1<=3) dir=1;
			if (val1>=19) dir=0;
			}

		incount++;
		incountb++;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			temp=origval+temp;
			}
		*(sampoint+samcount)=temp;
		if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			} 
		}
	}

//-----------------------------------------------------------------

if (opt==1)		 //  Vibrato Delay
	{
	lensam=samend-samstart;
	lensam=lensam/32;

	val2=256;
	val1=val1+16;
	val3=val3+1;
	val3=val3 << 9;
	length=val3;
	sublength=val3/32;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		tempb=*(sampoint+samcount+phcount);
		if ((samcount+phcount)>=samend) tempb=0;
		val4b=val4;
		tempb2=*(sampoint+samcount+phcount+val4b);
		if ((samcount+phcount+val4b)>=samend) tempb2=0;
		val4b=val4b+val4;
		tempb3=*(sampoint+samcount+phcount+val4b);
		if ((samcount+phcount+val4b)>=samend) tempb3=0;
		val4b=val4b+val4;
		tempb4=*(sampoint+samcount+phcount+val4b);
		if ((samcount+phcount+val4b)>=samend) tempb4=0;

		if (incount==val1)
		{
		if (dir==0)
			{
			phcount++;
			phcountb--;
			}
		if (dir==1)
			{
			phcount--;
			phcountb++;
			}
		incount=0;
		}

		if (incountb==sublength)
		{
		if (dir==0)
			{
			val1--;
			}
		if (dir==1)
			{
			val1++;
			}
		incount=0;
		incountb=0;
		if (val1<=3) dir=1;
		if (val1>=19) dir=0;
		}

		incount++;
		incountb++;

		if (val2<=255)
			{
			tempb=tempb*val2;
			tempb=tempb >> 8;
			}

		if (addtyp==0)
			{ 
			temp=tempb+tempb2+tempb3+tempb4;
			temp=temp >> 2;
			}
		if (addtyp==1)
			{
			temp=tempb-tempb2-tempb3-tempb4;
			temp=temp >> 2;
			}

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

		 if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			temp=origval+temp;
			}
		*(sampoint+samcount)=temp;
		if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			} 
		}
	}

//-----------------------------------------------------------------

if (opt==2)  // Alternate
	 {
	 if (addtyp==0) length=val1 << 10;
	 if (addtyp==1) length=val1 << 2;

	 for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if ((samcount+phcount)<samend)
			{
			tempb=*(sampoint+samcount+phcount);
			}
		else tempb=0;
		
		if ((samcount+phcountb)<samend)
			{
			tempc=*(sampoint+samcount+phcountb);
			}
		else tempc=0;

		if (incount==val2)
		  {
		  if (dir==0)
			{
			phcount++;
			phcountb--;
			}
		  if (dir==1)
			{
			phcount--;
			phcountb++;
			}
		  incount=0;
		  }

		if (incountb==length)
		  {
		  if (dir==0) dir=1;
		  else if (dir==1) dir=0;
		  incount=0;
		  incountb=0;
		  }

		incount++;
		incountb++;

		if (addtypb==0)
		  {
		  temp=tempb;
		  }
		if (addtypb==1)
		  {
		  temp=tempb+tempc;
		  temp=temp >> 1;
		  }

	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}
	 *(sampoint+samcount)=temp;
	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 } 
	 }
   }

 }
}
//-----------------------------------------------------------------
///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// Filter Sweep Manips
// Low Pass - High Pass - Band Pass - Band Cut - Notch Pass - Notch Cut

void SAMPLEWindow::Filtersweeprng(int32 opt,int32 optb) // might just be opt
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;
int32 tempe;
int32 tempf;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;

int32 tempval1;
int32 tempval2;
int32 tempval1b;
int32 tempval2b;
int32 repno;
int32 inrepcount;
int32 repcount;
int32 valno;
int32 valdiff;
int32 stepdiff;

int32 stepno;
int32 chngno=-1;

int32 lowpassval;
int32 highpassval;
int32 midpassval;

uint32 testtempval1;
uint32 testtempval2;
uint32 test;
uint32 testres;

val1=val1+3;
val2=val2+3;

if (val3<=0) val3=1;

if (opt == 0)
	{
//	val1=val1 >> 1;
//	val2=val2 >> 1;
	val1=val1+20;
	}

tempval1=val1;
valno=tempval1;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;


if ((opt==0) || (opt==1))   // Low Pass - High Pass
	{
	if (addtyp==0) repno=1;
	if (addtyp==1) repno=2;

	valdiff=val1-val2;
	if (valdiff<0)
		{
		valdiff=~valdiff;
		chngno=1;
		}
	else chngno=-1;
	if (valdiff==0) valdiff=1;
	stepdiff=samlen/valdiff;

	for (repcount=1;repcount<=repno;repcount++)
		{
		stepno=samstart+stepdiff;
		tempval1=val1;
		valno=tempval1;

		test=samstart+1;

		for (inrepcount=1;inrepcount<=2;inrepcount++)
			{
			stepno=samstart+stepdiff;
			tempval1=val1;
			testtempval1=samend-tempval1;
			if (addtypb == 1) testres=samstart+tempval1;
			for (samcount=samstart;samcount<=samend;samcount++)
				{
				if (samcount==stepno)
					{
					tempval1=tempval1+chngno;
					if (tempval1<=0) tempval1=1;
					stepno=stepno+stepdiff;
					testtempval1=samend-tempval1;
					if (addtypb == 1) testres=samstart+tempval1;
					}

				temp=*(sampoint+samcount);
				origval=temp;		  // Low Pass - High Pass

				if (samcount<test)	tempb=0;
				else tempb=*(sampoint+samcount-1);
				if (samcount>testtempval1) tempc=0;
				else tempc=*(sampoint+samcount+tempval1);

				temp=tempc-tempb;
				temp=temp/tempval1;
				temp=tempb+temp;

				if (opt==1) // high pass
					{
					temp=origval-temp;
					temp=temp >> 1;
					}

				if (addtypb==1)  // Resonance
					{
					if (samcount<testres) tempc=0;
					else tempc=*(sampoint+samcount-tempval1);
					tempc=tempc*val3;
					tempc=tempc >> 8;
					temp=temp+tempc;
					temp=temp >> 1;
					}

				if (temp<=-32766) temp=-32766;
				if (temp>=32766) temp=32766;

				if (mixlev<256)
					{
					temp=temp*mixlev;
					temp=temp >> 8;
					origval=origval*mixlevb;
					origval=origval >> 8;
					temp=origval+temp;
					}
				*(sampoint+samcount)=temp;
				}
			Rescalenoboxrng();
			}
		done++;
		Newdrawdonebox(3,0,100,repno,repcount,drawbarside);
		} // repno
	} // opt



if ((opt==2) || (opt==3))   // Band Pass - Band Cut
   {
if (addtyp==0) repno=1;
if (addtyp==1) repno=2;

valdiff=val1-val2;
if (valdiff<0)
  {
  valdiff=~valdiff;
  chngno=1;
  }
else chngno=-1;
if (valdiff==0) valdiff=1;
stepdiff=samlen/valdiff;

test=samstart+1;

for (repcount=1;repcount<=repno;repcount++)
 {
stepno=samstart+stepdiff;
tempval1=val1;
if (tempval1<=0) tempval1=1;
tempval2=tempval1*2;
valno=tempval1;

for (inrepcount=1;inrepcount<=2;inrepcount++)
 {
   stepno=samstart+stepdiff;   // Band Pass - Band Cut
   tempval1=val1;
   if (tempval1<=0) tempval1=1;
   tempval1b=tempval1/val3;
   if (tempval1b==0) tempval1b=1;
   tempval2=tempval1*4;
   tempval2b=tempval2/val3;
   if (tempval2b==0) tempval2b=1;
	testtempval1=samend-tempval1;
	if (addtypb == 1) testres=samstart+tempval1;

for (samcount=samstart;samcount<=samend;samcount++)
	{
	if (samcount==stepno)
		{
		tempval1=tempval1+chngno;
		if (tempval1<=0) tempval1=1;
		tempval2=tempval1 << 2;
		stepno=stepno+stepdiff;
		testtempval1=samend-tempval1;
		testtempval2=samend-tempval2;
		if (addtypb == 1) testres=samstart+tempval2-tempval1;
		}

	temp=*(sampoint+samcount);
	origval=temp;

	if (samcount<test)	tempb=0;
	else tempb=*(sampoint+samcount-1);
	if (samcount>testtempval1) tempc=0;
	else tempc=*(sampoint+samcount+tempval1);

	temp=tempc-tempb;
	temp=temp/tempval1;
	temp=tempb+temp;

	if (samcount>testtempval2) tempc=0;
	else tempc=*(sampoint+samcount+tempval2);

	tempd=tempc-tempb;
	temp=temp/tempval2;
	tempd=tempb+tempd;

	highpassval=origval-temp;
	lowpassval=tempd;
	midpassval=highpassval+lowpassval;  // Mid Cut

	if (opt==2)	//  Mid Pass 
		{
		midpassval=origval-lowpassval;
		midpassval=midpassval-highpassval;
		midpassval=midpassval << 1;
		}

	temp=midpassval;
	temp = temp >> 1;
	if (opt == 2) temp = temp >> 1;

	if (addtypb==1)  // Resonance
		{
		if (samcount<testres) tempc=0;
		else tempc=*(sampoint+samcount-tempval1);
		tempc=tempc*val3;
		tempc=tempc >> 8;
		temp=temp+tempc;
		}

	 if (temp<=-32766) temp=-32766;
	 if (temp>=32766) temp=32766;

	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		temp=origval+temp;
		}
	 *(sampoint+samcount)=temp;
	 }
  Rescalenoboxrng();
  }
  done++;
  Newdrawdonebox(3,0,100,repno,repcount,drawbarside);
 } // repno
} // opt


if ((opt==4) || (opt==5))   // Notch Pass - Notch Cut
   {
if (addtyp==0) repno=1;
if (addtyp==1) repno=2;

valdiff=val1-val2;
if (valdiff<0)
  {
  valdiff=~valdiff;
  chngno=1;
  }
else chngno=-1;
if (valdiff==0) valdiff=1;
stepdiff=samlen/valdiff;

test=samstart+1;

for (repcount=1;repcount<=repno;repcount++)
 {
stepno=samstart+stepdiff;
tempval1=val1;
if (tempval1<=0) tempval1=1;
tempval2=tempval1*2;
valno=tempval1;

for (inrepcount=1;inrepcount<=2;inrepcount++)
	{
	stepno=samstart+stepdiff;   // Band Pass - Band Cut
	tempval1=val1;
	if (tempval1<=0) tempval1=1;
	tempval2=tempval1*2;
	testtempval1=samend-tempval1;
	testtempval2=samend-tempval2;
	if (addtypb == 1) testres=samstart+tempval1;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		if (samcount==stepno)
			{
			tempval1=tempval1+chngno;
			if (tempval1<=0) tempval1=1;
			tempval2=tempval1 << 1;
			stepno=stepno+stepdiff;
			testtempval1=samend-tempval1;
			if (addtypb == 1) testres=samstart+tempval1-tempval1;
			}

		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount<test)	tempb=0;
		else tempb=*(sampoint+samcount-1);
		if (samcount>testtempval1) tempc=0;
		else tempc=*(sampoint+samcount+tempval1);

		temp=tempc-tempb;
		temp=temp/tempval1;
		temp=tempb+temp;

		if (samcount>testtempval2) tempc=0;
		else tempc=*(sampoint+samcount+tempval2);

		tempd=tempc-tempb;
		temp=temp/tempval2;
		tempd=tempb+tempd;

		highpassval=origval-temp;
		lowpassval=tempd;
		midpassval=highpassval+lowpassval;  // Notch Cut

		if (opt==4)	//  Notch Pass 
			{
			midpassval=origval-lowpassval;
			midpassval=midpassval-highpassval;
			midpassval=midpassval << 1;
			}

		temp=midpassval;
		temp = temp >> 1;
		if (opt == 4) temp = temp >> 1;

		if (addtypb==1)  // Resonance
			{
			if (samcount<testres) tempc=0;
			else tempc=*(sampoint+samcount-tempval1);
			tempc=tempc*val3;
			tempc=tempc >> 8;
			temp=temp+tempc;
			}

		if (temp<=-32766) temp=-32766;
		if (temp>=32766) temp=32766;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			temp=origval+temp;
			}
		*(sampoint+samcount)=temp;
		}
  Rescalenoboxrng();
	}
  done++;
  Newdrawdonebox(3,0,100,repno,repcount,drawbarside);
 } // repno
} // opt

}


///***************************************************************************************************
///***************************************************************************************************
///***************************************************************************************************
// Expermental Basic filter used by wha

// wha?	

void SAMPLEWindow::Basfiltrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;
int32 tempe;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;
int32 origvala;
int32 incount;

int16 wordval;

int32 val1=samslider1;
int32 val2=samslider2;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

val1=256-val1;
val1=val1+16;


if (opt==1)   // Basic Fliter
   {
   origvala=0;
   incount=0;
   tempc=0;
   for (samcount=samstart;samcount<=samend;samcount++)
	 {
	 tempe=origval; // inital val of temp from last interation of loop

	 temp=*(sampoint+samcount);
	 temp=temp << 15;
	 origval=temp;
	 
	 if ((samcount-1)>samstart)
	 	{
	 	tempb=*(sampoint+samcount-1);
	 	}
	 else tempb = 0;
	 
	 if ((samcount+1)<samend)
	 	{
	 	tempc=*(sampoint+samcount+1);
	 	}
	 else tempc = 0;
	 
	 tempb=tempb << 15;
	 tempc=tempc << 15;

	 // Basic Lowpass Fliter

	 tempd=tempc-tempb;
	 tempd=tempd/val1;
	 tempd=tempd << 3;
	 temp=tempb+tempd;
	 temp=temp >> 15;

	 if (addtyp==1)  // Basic Highpass Fliter
		 {
		 tempb=tempb >> 1;
		 tempe=tempe >> 1;
		 tempb=tempe-tempb;
		 tempb=tempb >> 16;
		 }

	 if (temp>=32766) temp=32766;
	 if (temp<=-32766) temp=-32766;
	 if (mixlev<256)
		{
		temp=temp*mixlev;
		temp=temp >> 8;
		origval=origval*mixlevb;
		origval=origval >> 8;
		if (addtyp==0) temp=origval+temp;
		if (addtyp==1) temp=origval-temp;
		}

	 *(sampoint+samcount)=temp;
	 if (addtyp==1)
		{
		if ((samcount+1)>samstart) *(sampoint+samcount-1)=tempb;
		}

	 if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,5,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
	 }
   Rescalenoboxrng();
   }

}
//-----------------------------------------------------------------
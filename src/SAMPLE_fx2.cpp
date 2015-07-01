//				Aural illusion v4.0	Effects & Manipulations Part 2 

//				SAMPLE_fx2.cpp

//			copyright (c) Blachford Technology	15/5/97 - 1999

#include "SAMPLEWindow.h"
//#include <math.h>
#include <stdlib.h>
		
//***************************************************************
// Functions

// Echorng				- Reverb FX
// Delayrng			- Long Delay FX
// Faderng				- Fade MANIPs
// Unorderrng		- Unorder Samples FX
// Tunerng				- Tune Octave MANIPs
// Detunerng			- Detune FX
// Thickenrng		- Thicken MANIPs
// SArithrng			- Add SFX
// SInterrng			- Interleave SFX
// Zerooutrng		- Zero out MANIPs
// Compressrng		- Compress FX
// Sfaderng			- Stereo Pan SFX
// Blockrng			- Transform Blocks MANIPs
// Blurrng				- 2D Blur FX
// Chaosrng			- Chaos MANIPs
// Chaos2rng			- weird??? MANIPs

//***************************************************************

// Echo and Delay Effects

// Reverb - Echo - Delay - Bounce - Backwards Reverb - Reverb Phaser

void	SAMPLEWindow::Echorng(int32 opt, int32 optb)
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
int32 phcountc;
int32 phcountd;
int32 phcounte;
int32 phcountf;
int32 phcountg;
int32 phcounth;

int32 phcounti;
int32 phcountj;
int32 phcountk;
int32 phcountl;
int32 phcountm;
int32 phcountn;
int32 phcounto;
int32 phcountp;

int32 dir;

int32 rphcount;
int32 rphcountb;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;

int32 startvalb;
int32 startvalc;
int32 startvald;
int32 startvale;
int32 startvalf;
int32 startvalg;
int32 startvalh;

int32 startvali;
int32 startvalj;
int32 startvalk;
int32 startvall;
int32 startvalm;
int32 startvaln;
int32 startvalo;
int32 startvalp;

int32 predelay;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if (val2==0) val2=1;

incount=0;
incountb=0;
incountc=0;

rphcount=0;
rphcountb=val1;
dir=0;


 if (opt==0)	// Reverb
		{

predelay=val3 << 6;

if (addtyp==0)
{
 if (addtypb==0)
		{
		phcountb=val1 * 67;
		phcountc=val1 * 33;
		phcountd=val1 * 27;
		phcounte=val1 * 55;
		phcountf=val1 * 44;
		phcountg=val1 * 30;
		phcounth=val1 * 24;
		}

 if (addtypb==1)
		{
		phcountb=val1 * 167;
		phcountc=val1 * 123;
		phcountd=val1 * 98;
		phcounte=val1 * 63; 
		phcountf=val1 * 49;
		phcountg=val1 * 35;
		phcounth=val1 * 14;
		}

		phcountb=phcountb+predelay;
		phcountc=phcountc+predelay;
		phcountd=phcountd+predelay;
		phcounte=phcounte+predelay;
		phcountf=phcountf+predelay;
		phcountg=phcountg+predelay;
		phcounth=phcounth+predelay;

		startvalb=samstart+phcountb;
		startvalc=samstart+phcountc;
		startvald=samstart+phcountd;
		startvale=samstart+phcounte;
		startvalf=samstart+phcountf;
		startvalg=samstart+phcountg;
		startvalh=samstart+phcounth;

			for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount>startvalb)
			{
			tempb=*(sampoint+samcount-phcountb);
			}
		else tempb=0;
			
		if (samcount>startvalc)
			{
			tempc=*(sampoint+samcount-phcountc);
			}
		else tempc=0;
			
		if (samcount>startvald)
			{
			tempd=*(sampoint+samcount-phcountd);
			}
		else tempd=0;
			
		if (samcount>startvale)
			{
			tempe=*(sampoint+samcount-phcounte);
			}
		else tempe=0;
			
		if (samcount>startvalf)
			{
			tempf=*(sampoint+samcount-phcountf);
			}
		else tempf=0;
			
		if (samcount>startvalg)
			{
			tempg=*(sampoint+samcount-phcountg);
			}
		else tempg=0;
			
		if (samcount>startvalh)
			{
			temph=*(sampoint+samcount-phcounth);
			}
		else temph=0;
		
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph;

		tempb=tempb*val2;
		tempb=tempb >> 11;

		tempb=tempb*195;
		tempb=tempb >> 8;

		temp=temp+tempb;

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

		if (makechans!=2) done=done+2;
		if (makechans==2) done++;
		if (makechans!=2) done=done+2;
		if (makechans==2) done++;
}

else	// addtyp==1
	{
 if (addtypb==0)
		{
		phcountb=val1 * 67;
		phcountc=val1 * 55;
		phcountd=val1 * 43;
		phcounte=val1 * 33;
		phcountf=val1 * 30;
		phcountg=val1 * 27;
		phcounth=val1 * 24;

		phcounti=val1 * 73;
		phcountj=val1 * 70;
		phcountk=val1 * 51;
		phcountl=val1 * 52;
		phcountm=val1 * 36;
		phcountn=val1 * 28;
		phcounto=val1 * 21;
		phcountp=val1 * 18;
		}

 if (addtypb==1)
		{
		phcountb=val1 * 167;
		phcountc=val1 * 123;
		phcountd=val1 * 98;
		phcounte=val1 * 63; 
		phcountf=val1 * 49;
		phcountg=val1 * 35;
		phcounth=val1 * 14;

		phcounti=val1 * 154;
		phcountj=val1 * 136;
		phcountk=val1 * 85;
		phcountl=val1 * 71;
		phcountm=val1 * 52;
		phcountn=val1 * 44;
		phcounto=val1 * 32;
		phcountp=val1 * 23;
		}

		phcountb=phcountb+predelay;
		phcountc=phcountc+predelay;
		phcountd=phcountd+predelay;
		phcounte=phcounte+predelay;
		phcountf=phcountf+predelay;
		phcountg=phcountg+predelay;
		phcounth=phcounth+predelay;

		phcounti=phcounti+predelay;
		phcountj=phcountj+predelay;
		phcountk=phcountk+predelay;
		phcountl=phcountl+predelay;
		phcountm=phcountm+predelay;
		phcountn=phcountn+predelay;
		phcounto=phcounto+predelay;
		phcountp=phcountp+predelay;

		startvalb=samstart+phcountb;
		startvalc=samstart+phcountc;
		startvald=samstart+phcountd;
		startvale=samstart+phcounte;
		startvalf=samstart+phcountf;
		startvalg=samstart+phcountg;
		startvalh=samstart+phcounth;

		startvali=samstart+phcounti;
		startvalj=samstart+phcountj;
		startvalk=samstart+phcountk;
		startvall=samstart+phcountl;
		startvalm=samstart+phcountm;
		startvaln=samstart+phcountn;
		startvalo=samstart+phcounto;
		startvalp=samstart+phcountp;

			for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount>startvalb)
			{
			tempb=*(sampoint+samcount-phcountb);
			}
		else tempb=0;
			
		if (samcount>startvalc)
			{
			tempc=*(sampoint+samcount-phcountc);
			}
		else tempc=0;
			
		if (samcount>startvald)
			{
			tempd=*(sampoint+samcount-phcountd);
			}
		else tempd=0;
			
		if (samcount>startvale)
			{
			tempe=*(sampoint+samcount-phcounte);
			}
		else tempe=0;
			
		if (samcount>startvalf)
			{
			tempf=*(sampoint+samcount-phcountf);
			}
		else tempf=0;
			
		if (samcount>startvalg)
			{
			tempg=*(sampoint+samcount-phcountg);
			}
		else tempg=0;
			
		if (samcount>startvalh)
			{
			temph=*(sampoint+samcount-phcounth);
			}
		else temph=0;
		
		if (samcount>startvali)
			{
			tempi=*(sampoint+samcount-phcounti);
			}
		else tempi=0;
		
		if (samcount>startvalj)
			{
			tempj=*(sampoint+samcount-phcountj);
			}
		else tempj=0;
		
		if (samcount>startvalk)
			{
			tempk=*(sampoint+samcount-phcountk);
			}
		else tempk=0;
		
		if (samcount>startvall)
			{
			templ=*(sampoint+samcount-phcountl);
			}
		else templ=0;
		
		if (samcount>startvalm)
			{
			tempm=*(sampoint+samcount-phcountm);
			}
		else tempm=0;
		
		if (samcount>startvaln)
			{
			tempn=*(sampoint+samcount-phcountn);
			}
		else tempn=0;
		
		if (samcount>startvalo)
			{
			tempo=*(sampoint+samcount-phcounto);
			}
		else tempo=0;
		
		if (samcount>startvalp)
			{
			tempp=*(sampoint+samcount-phcountp);
			}
		else tempp=0;
		
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph
		+tempi+tempj+tempk+templ+tempm+tempn+tempo+tempp;

		tempb=tempb*val2;
		tempb=tempb >> 12;

		tempb=tempb*182;
		tempb=tempb >> 8;

		temp=temp+tempb;

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
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	}

}



 if (opt==1)	// Echo
	{
	phcount=val1 << 10 ;
	phcountb=val1 << 9 ;

	startvalb=samstart+phcount;
	startvalc=samstart+phcountb;

	incount = samstart;
	for (samcount=samend;samcount>samstart;samcount--)
		{
		if (samcount<=0) samcount=samstart;

		temp=*(sampoint+samcount);
		origval=temp;
//		tempb=*(sampoint+samcount-phcount);
//		tempc=*(sampoint+samcount-phcountb);
		
//		if (samcount<=startvalb) tempb=0;
//		if (samcount<=startvalc) tempc=0;

		if (samcount>startvalb) tempb=*(sampoint+samcount-phcount);
		else tempb=0;
		if (samcount>startvalc) tempc=*(sampoint+samcount-phcountb);
		else tempc=0;

		incount++;
		tempb=tempb*val2;
		tempb=tempb >> 7;
		tempc=tempc*val2;
		tempc=tempc >> 7;

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
		if (incount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,95,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Newdrawdonebox(3,100,100,100,100,drawbarside);
	}


if (opt==2)	// Delay
	{
	phcount=val1 << 6 ;
	phcountb=val1 << 5 ;

	startvalb=samstart+phcount;
	startvalc=samstart+phcountb;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
//		tempb=*(sampoint+samcount-phcount);
//		tempc=*(sampoint+samcount-phcountb);

//		if (samcount<=startvalb) tempb=0;
//		if (samcount<=startvalc) tempc=0;

		if (samcount>startvalb)	tempb=*(sampoint+samcount-phcount);
		else tempb=0;
		if (samcount>startvalc) tempc=*(sampoint+samcount-phcountb);
		else tempc=0;

		tempb=tempb*val2;
		tempb=tempb >> 7;
		tempc=tempc*val2;
		tempc=tempc >> 7;

//		tempb=tempb >> 1;
//		tempc=tempc >> 1; 
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
		if (samcount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,95,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Newdrawdonebox(3,100,100,100,100,drawbarside);
	}


 if (opt==3)	// Bounce
	{
	phcount=val1 << 1;
	phcount=phcount+2200;
	phcountb=phcount-512;

	startvalb=samstart+phcount;
	startvalc=samstart+phcountb;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
//		tempb=*(sampoint+samcount-phcount);
//		tempc=*(sampoint+samcount-phcountb);

//		if (samcount<=startvalb) tempb=0;
//		if (samcount<=startvalc) tempc=0;

		if (samcount>startvalb)
			{
			tempb=*(sampoint+samcount-phcount);
			}
		else tempb=0;
		if (samcount>startvalc)
			{
			tempc=*(sampoint+samcount-phcountb);
			}
		else tempc=0;

		incount++;
		tempb=tempb*val2;
		tempb=tempb >> 7;
		tempc=tempc*val2;
		tempc=tempc >> 7;

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
		if (samcount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,95,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Newdrawdonebox(3,95,100,100,100,drawbarside);
	}


if (opt==4)	// Backwards Reverb
{

predelay=val3 << 6;

if (addtyp==0)
	{
	if (addtypb==0)
		{
		phcountb=val1 * 67;
		phcountc=val1 * 33;
		phcountd=val1 * 27;
		phcounte=val1 * 55;
		phcountf=val1 * 44;
		phcountg=val1 * 30;
		phcounth=val1 * 24;
		}

	 if (addtypb==1)
		{
		phcountb=val1 * 167;
		phcountc=val1 * 123;
		phcountd=val1 * 98;
		phcounte=val1 * 63; 
		phcountf=val1 * 49;
		phcountg=val1 * 35;
		phcounth=val1 * 14;
		}

	phcountb=phcountb+predelay;
	phcountc=phcountc+predelay;
	phcountd=phcountd+predelay;
	phcounte=phcounte+predelay;
	phcountf=phcountf+predelay;
	phcountg=phcountg+predelay;
	phcounth=phcounth+predelay;

	startvalb=samend-phcountb;
	startvalc=samend-phcountc;
	startvald=samend-phcountd;
	startvale=samend-phcounte;
	startvalf=samend-phcountf;
	startvalg=samend-phcountg;
	startvalh=samend-phcounth;

	incount = samstart;
	for (samcount=samend;samcount>samstart;samcount--)
		{
		incount++;
		temp=*(sampoint+samcount);
		origval=temp;

		tempb=*(sampoint+samcount+phcountb);
		tempc=*(sampoint+samcount+phcountc);
		tempd=*(sampoint+samcount+phcountd);

		tempe=*(sampoint+samcount+phcounte);
		tempf=*(sampoint+samcount+phcountf);
		tempg=*(sampoint+samcount+phcountg);
		temph=*(sampoint+samcount+phcounth);

		if (samcount>=startvalb) tempb=0;
		if (samcount>=startvalc) tempc=0;
		if (samcount>=startvald) tempd=0;
		if (samcount>=startvale) tempe=0;
		if (samcount>=startvalf) tempf=0;
		if (samcount>=startvalg) tempg=0;
		if (samcount>=startvalh) temph=0;

		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph;

		tempb=tempb*val2;
		tempb=tempb >> 11;

		tempb=tempb*195;
		tempb=tempb >> 8;

		temp=temp+tempb;

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
		if (incount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	//		Rescalenoboxrng();
	}

if (addtyp==1)
	{
 if (addtypb==0)
		{
		phcountb=val1 * 67;
		phcountc=val1 * 55;
		phcountd=val1 * 43;
		phcounte=val1 * 33;
		phcountf=val1 * 30;
		phcountg=val1 * 27;
		phcounth=val1 * 24;

		phcounti=val1 * 73;
		phcountj=val1 * 70;
		phcountk=val1 * 51;
		phcountl=val1 * 52;
		phcountm=val1 * 36;
		phcountn=val1 * 28;
		phcounto=val1 * 21;
		phcountp=val1 * 18;
		}

 if (addtypb==1)
		{
		phcountb=val1 * 167;
		phcountc=val1 * 123;
		phcountd=val1 * 98;
		phcounte=val1 * 63; 
		phcountf=val1 * 49;
		phcountg=val1 * 35;
		phcounth=val1 * 14;

		phcounti=val1 * 154;
		phcountj=val1 * 136;
		phcountk=val1 * 85;
		phcountl=val1 * 71;
		phcountm=val1 * 52;
		phcountn=val1 * 44;
		phcounto=val1 * 32;
		phcountp=val1 * 23;
		}

		phcountb=phcountb+predelay;
		phcountc=phcountc+predelay;
		phcountd=phcountd+predelay;
		phcounte=phcounte+predelay;
		phcountf=phcountf+predelay;
		phcountg=phcountg+predelay;
		phcounth=phcounth+predelay;

		phcounti=phcounti+predelay;
		phcountj=phcountj+predelay;
		phcountk=phcountk+predelay;
		phcountl=phcountl+predelay;
		phcountm=phcountm+predelay;
		phcountn=phcountn+predelay;
		phcounto=phcounto+predelay;
		phcountp=phcountp+predelay;

		startvalb=samend-phcountb;
		startvalc=samend-phcountc;
		startvald=samend-phcountd;
		startvale=samend-phcounte;
		startvalf=samend-phcountf;
		startvalg=samend-phcountg;
		startvalh=samend-phcounth;

		startvali=samend-phcounti;
		startvalj=samend-phcountj;
		startvalk=samend-phcountk;
		startvall=samend-phcountl;
		startvalm=samend-phcountm;
		startvaln=samend-phcountn;
		startvalo=samend-phcounto;
		startvalp=samend-phcountp;

	incount = samstart;
	for (samcount=samend;samcount>samstart;samcount--)
		{
		incount++;
		temp=*(sampoint+samcount);
		origval=temp;

		tempb=*(sampoint+samcount+phcountb);
		tempc=*(sampoint+samcount+phcountc);
		tempd=*(sampoint+samcount+phcountd);
		tempe=*(sampoint+samcount+phcounte);
		tempf=*(sampoint+samcount+phcountf);
		tempg=*(sampoint+samcount+phcountg);
		temph=*(sampoint+samcount+phcounth);

		tempi=*(sampoint+samcount+phcounti);
		tempj=*(sampoint+samcount+phcountj);
		tempk=*(sampoint+samcount+phcountk);
		templ=*(sampoint+samcount+phcountl);
		tempm=*(sampoint+samcount+phcountm);
		tempn=*(sampoint+samcount+phcountn);
		tempo=*(sampoint+samcount+phcounto);
		tempp=*(sampoint+samcount+phcountp);


		if (samcount>=startvalb) tempb=0;
		if (samcount>=startvalc) tempc=0;
		if (samcount>=startvald) tempd=0;
		if (samcount>=startvale) tempe=0;
		if (samcount>=startvalf) tempf=0;
		if (samcount>=startvalg) tempg=0;
		if (samcount>=startvalh) temph=0;

		if (samcount>=startvali) tempi=0;
		if (samcount>=startvalj) tempj=0;
		if (samcount>=startvalk) tempk=0;
		if (samcount>=startvall) templ=0;
		if (samcount>=startvalm) tempm=0;
		if (samcount>=startvaln) tempn=0;
		if (samcount>=startvalo) tempo=0;
		if (samcount>=startvalp) tempp=0;
		
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph
		+tempi+tempj+tempk+templ+tempm+tempn+tempo+tempp;

		tempb=tempb*val2;
		tempb=tempb >> 12;

		tempb=tempb*182;
		tempb=tempb >> 8;

		temp=temp+tempb;

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
		if (incount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	}

//	Rescalenoboxrng();
}


if (opt==5)	// Reverb Phaser
	{
	val3=val3 << 10;	//	Phase Length 
	phcount=0;
	phcountb=0;

	startvalb=samend-phcount;
	startvalc=samend-phcountb;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount<startvalb) tempb=*(sampoint+samcount+phcount);
		else tempb=0;
		if (samcount<startvalc) tempc=*(sampoint+samcount+phcountb);
		else tempc=0;

		if (incount==val2)	//	Phase		
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

		if (incountb==val3)	//	Length		
			{
			if (dir==0) dir=1;
			else if (dir==1) dir=0;
			incount=0;
			incountb=0;
			}

		incount++;
		incountb++;

		if (addtyp==0)
			{
			temp=temp+tempb;
			temp=temp >> 1;
			}
		if (addtyp==1)
			{
			temp=temp+tempb+tempc;
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
			Newdrawdonebox(3,0,50,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			} 
		}

	if (addtypb==0)
		{
		phcountb=val1 * 67;
		phcountc=val1 * 33;
		phcountd=val1 * 27;
		phcounte=val1 * 55;
		phcountf=val1 * 44;
		phcountg=val1 * 30;
		phcounth=val1 * 24;
		}

	if (addtypb==1)
		{
		phcountb=val1 * 167;
		phcountc=val1 * 123;
		phcountd=val1 * 98;
		phcounte=val1 * 63; 
		phcountf=val1 * 49;
		phcountg=val1 * 35;
		phcounth=val1 * 14;
		}

	startvalb=samstart+phcountb;
	startvalc=samstart+phcountc;
	startvald=samstart+phcountd;
	startvale=samstart+phcounte;
	startvalf=samstart+phcountf;
	startvalg=samstart+phcountg;
	startvalh=samstart+phcounth;

	memdivtodo=memdiv+samstart;
	done=0;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount>startvalb) tempb=*(sampoint+samcount-phcountb);
		else tempb=0;
		if (samcount>startvalc) tempc=*(sampoint+samcount-phcountc);
		else tempc=0;
		if (samcount>startvald) tempd=*(sampoint+samcount-phcountd);
		else tempd=0;
		if (samcount>startvale) tempe=*(sampoint+samcount-phcounte);
		else tempe=0;
		if (samcount>startvalf) tempf=*(sampoint+samcount-phcountf);
		else tempf=0;
		if (samcount>startvalg) tempg=*(sampoint+samcount-phcountg);
		else tempg=0;
		if (samcount>startvalh) temph=*(sampoint+samcount-phcounth);
		else temph=0;
		
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph;

		tempb=tempb*val2;
		tempb=tempb >> 11;

		tempb=tempb*195;
		tempb=tempb >> 8;

		temp=temp+tempb;

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
			Newdrawdonebox(3,50,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	//		Rescalenoboxrng();
	}

}


//-----------------------------------------------------------------

// Delay Effects

// Long Delay -

void	SAMPLEWindow::Delayrng( int32 opt, int32 optb)
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
int32 phcountc;
int32 phcountd;
int32 phcounte;

int32 dir;

int32 rphcount;
int32 rphcountb;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;

int32 startvalb;
int32 startvalc;
int32 startvald;
int32 startvale;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if (val2==0) val2=1;

incount=0;
incountb=0;
incountc=0;

rphcount=0;
rphcountb=val1;
dir=0;

if ((opt==0) || (opt==1) || (opt==2))
	{
// Long delay - Multi tap delay - Feedback Loop


if (opt==0)	// Long Delay
	{
	phcount=val1 << 11 ;
	phcountb=val1 << 10 ;

	startvalb=samstart+phcount;
	startvalc=samstart+phcountb;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		
//		tempb=*(sampoint+samcount-phcount);
//		tempc=*(sampoint+samcount-phcountb);

//		if (samcount<=startvalb) tempb=0;
//		if (samcount<=startvalc) tempc=0;

		if (samcount>startvalb) tempb=*(sampoint+samcount-phcount);
		else tempb=0;
		if (samcount>startvalc) tempc=*(sampoint+samcount-phcountb);
		else tempc=0;

		incount++;
		if (val2<=255)
			{
			tempb=tempb*val2;
			tempb=tempb >> 8;
			tempc=tempc*val2;
			tempc=tempc >> 8;
			}
		tempb=tempb >> 1;
		tempc=tempc >> 1; 
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
		if (samcount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,95,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	}


 if (opt==1)	// Multi Tap Delay
	{
	if (addtypb==0)
		{
		phcountb=val1 << 4 ;
		phcountc=val2 << 4 ;
		phcountd=val3 << 4 ;
		phcounte=val4 << 4 ;
		}

	if (addtypb==1)
		{
		phcountb=val1 << 8 ;
		phcountc=val2 << 8 ;
		phcountd=val3 << 8 ;
		phcounte=val4 << 8 ;
		}

	startvalb=samstart+phcountb;
	startvalc=samstart+phcountc;
	startvald=samstart+phcountd;
	startvale=samstart+phcounte;

	incount = samstart;
	for (samcount=samend;samcount>samstart;samcount--)
		{
		incount++;
		if (samcount<=0) samcount=samstart;

		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount>startvalb)
			{
			tempb=*(sampoint+samcount-phcountb);
			}
		else tempb=0;
			
		if (samcount>startvalc)
			{
			tempc=*(sampoint+samcount-phcountc);
			}
		else tempc=0;
			
		if (samcount>startvald)
			{
			tempd=*(sampoint+samcount-phcountd);
			}
		else tempd=0;
			
		if (samcount>startvale)
			{
			tempe=*(sampoint+samcount-phcounte);
			}
		else tempe=0;

		if (addtyp==0) temp=temp+tempb+tempc+tempd+tempe;
		if (addtyp==1) temp=temp-tempb+tempc-tempd+tempe;
		temp=temp/5;

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
		if (incount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,95,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Newdrawdonebox(3,95,100,100,100,drawbarside);
	}


 if (opt==2)	// Feedback Loop
	{
	val1=val1+16;
	phcount=val1 << 2;
	phcountb=phcount >> 1;
	val2=val2+400;
	startvalb=samstart+phcount;
	startvalc=samstart+phcountb;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount>startvalb)
			{
			tempb=*(sampoint+samcount-phcount);
			}
		else tempb=0;
			
		if (samcount>startvalc)
			{
			tempc=*(sampoint+samcount-phcountb);
			}
		else tempc=0;

		incount++;
			tempb=tempb*val2;
			tempb=tempb >> 8;
			tempc=tempc*val2;
			tempc=tempc >> 8;

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
		if (samcount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,95,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	done++;
	Newdrawdonebox(3,95,100,75,done,drawbarside);
	}
}
}

//-----------------------------------------------------------------
// Fading Effects
// Fade - Boost
// Fade In - Fade Out

void	SAMPLEWindow::Faderng( int32 opt, int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;

int32 val1;
int32 val2;
int32 val3;
int32 val4;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 tempval1;

int32 valdiff;
int32 stepdiff;

int32 stepno;
int32 chngno=-1;

int32 startvalb;
int32 startvalc;


if ((opt==0) || (opt==1))		// Fade - Boost EFFECTS
{

val1=samslider1;
val2=samslider2;
val3=samslider3;
val4=samslider4;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if (opt==0)		// Fade
	{
	valdiff=val1-val2;
	if (valdiff<0)
		{
		valdiff=~valdiff;
		chngno=1;
		}
	else chngno=-1;
	if (valdiff==0) valdiff=1;
	stepdiff=samlen/valdiff;

	stepno=samstart+stepdiff;
	tempval1=val1;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		if (samcount==stepno)
			{
			tempval1=tempval1+chngno;
			stepno=stepno+stepdiff;
			}

		temp=*(sampoint+samcount);
		origval=temp;

		temp=temp * tempval1;
		temp=temp >> 8;

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
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			} 
		}
	}


if (opt==1)		// Boost
	{

	valdiff=val1-val2;
	if (valdiff<0)
		{
		valdiff=~valdiff;
		chngno=1;
		}
	else chngno=-1;
	if (valdiff==0) valdiff=1;
	stepdiff=samlen/valdiff;

	stepno=samstart+stepdiff;
	tempval1=val1;

	startvalb=samstart+1;
	startvalc=samend-2;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		if (samcount==stepno)
			{
			tempval1=tempval1+chngno;
			stepno=stepno+stepdiff;
			}

		temp=*(sampoint+samcount);
		origval=temp;

//		tempb=*(sampoint+samcount-1);		// high pass filter
//		tempc=*(sampoint+samcount+2);

		if (samcount>startvalb)
			{
			tempb=*(sampoint+samcount-1);
			}
		else tempb=0;
			
		if (samcount<startvalc)
			{
			tempc=*(sampoint+samcount+2);
			}
		else tempc=0;
		
		temp=tempc-tempb;
		temp=temp >> 1;
		temp=tempb+temp;
		if (addtyp==0)
			{
			temp=origval-temp;
			temp=temp >> 1;
			}

		temp=temp * tempval1;
		temp=temp/85;
		temp=temp+origval;
		temp=temp >> 2;

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
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			} 
		}
	Rescalenoboxrng();
	}
}

if ((opt==2) || (opt==3))		// Fade In - Fade Out MANIPS
{

if (opt==2)
	{
	val1=0;
	val2=256;
	}

if (opt==3)
	{
	val1=256;
	val2=0;
	}

if ((opt==2) || (opt==3))
	{
	valdiff=val1-val2;
	if (valdiff<0)
		{
		valdiff=~valdiff;
		chngno=1;
		}
	else chngno=-1;
	if (valdiff==0) valdiff=1;
	stepdiff=samlen/valdiff;

	stepno=samstart+stepdiff;
	tempval1=val1;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		if (samcount==stepno)
			{
			tempval1=tempval1+chngno;
			stepno=stepno+stepdiff;
			}

		temp=*(sampoint+samcount);
		origval=temp;

		temp=temp * tempval1;
		temp=temp >> 8;

		if (temp<=-32766) temp=-32766;
		if (temp>=32766) temp=32766;

		*(sampoint+samcount)=temp;
		if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			} 
		}
	}
}

}

//-----------------------------------------------------------------
// Disordered Effects
// Unorder Samples - Unorder Blocks

void	SAMPLEWindow::Unorderrng(int32 opt,int32 optb)
{
int32 temp;

int32 tempa;
int32 tempb;
int32 tempc;
int32 tempd;
int32 tempe;
int32 tempf;
int32 tempg;
int32 temph;

int32 addtyp;
int32 addtypb;
int32 mixlev;

int32 origval;

int32 repno;
int32 repcount;
int32 count;

int32 val1=samslider1;
int32 val2=samslider2;

int32 val1b;
int32 val1c;
int32 val2b;
int32 counttest;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;	// not used

if (val1<=0) val1=1;
if (val2<=0) val2=1;

val2b=256-val2;

if (addtyp==0) repno=0;
if (addtyp==1) repno=1;

if ((opt==0) || (opt==1))
		{

if (opt==0)			// Unorder Samples
		{
		
		for (repcount=0;repcount<=repno;repcount++)
			{
		val1c=val1*8;

		for (samcount=samstart;samcount<samend;samcount=samcount+val1c)
			{

		for (count=1;count<257;count++)
				{
				tempa=*(sampoint+samcount+count);
				val1b=val1;
				if ((samcount+count+val1b) >= samend) tempb = 0;
				else tempb=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempc = 0;
				else tempc=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempd = 0;
				else tempd=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempe = 0;
				else tempe=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempf = 0;
				else tempf=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempg = 0;
				else tempg=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) temph = 0;
				else temph=*(sampoint+samcount+count+val1b);

				temp=tempa*val2;
				temp=temp >> 8;
				origval=tempa*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1;
				temp=tempd*val2;
				temp=temp >> 8;
				origval=tempb*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempc*val2;
				temp=temp >> 8;
				origval=tempc*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=temph*val2;
				temp=temp >> 8;
				origval=tempd*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempe*val2;
				temp=temp >> 8;
				origval=tempe*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempb*val2;
				temp=temp >> 8;
				origval=tempf*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempg*val2;
				temp=temp >> 8;
				origval=tempg*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempf*val2;
				temp=temp >> 8;
				origval=temph*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				counttest=val1*7;
				counttest=counttest+count+1;
				counttest=counttest+samcount;
				if (counttest>=samend)
		{
		count=257;
		samcount=samend;
		}
				if (count>=val1) count=257;
				}
		if (samcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		}
		}


if (opt==1)			// Unorder Blocks
		{
		
		for (repcount=0;repcount<=repno;repcount++)
			{
		val1=val1 << 6;
		val1c=val1*8;

		for (samcount=samstart;samcount<samend;samcount=samcount+val1c)
			{

		for (count=1;count<16385;count++)
				{
				if ((samcount+count) >= samend) tempa = 0;
				else tempa=*(sampoint+samcount+count);
				val1b=val1;
				if ((samcount+count+val1b) >= samend) tempb = 0;
				else tempb=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempc = 0;
				else tempc=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempd = 0;
				else tempd=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempe = 0;
				else tempe=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempf = 0;
				else tempf=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempg = 0;
				else tempg=*(sampoint+samcount+count+val1b);
				val1b=val1b+val1;
				if ((samcount+count+val1b) >= samend) tempg = 0;
				else temph=*(sampoint+samcount+count+val1b);

				temp=tempa*val2;
				temp=temp >> 8;
				origval=tempa*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1;
				temp=tempd*val2;
				temp=temp >> 8;
				origval=tempb*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempc*val2;
				temp=temp >> 8;
				origval=tempc*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=temph*val2;
				temp=temp >> 8;
				origval=tempd*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempe*val2;
				temp=temp >> 8;
				origval=tempe*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempb*val2;
				temp=temp >> 8;
				origval=tempf*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempg*val2;
				temp=temp >> 8;
				origval=tempg*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				val1b=val1b+val1;
				temp=tempf*val2;
				temp=temp >> 8;
				origval=temph*val2b;
				origval=origval >> 8;
				if (addtypb==0) temp=origval+temp;
				if (addtypb==1) temp=origval-temp;
				if ((samcount+count+val1b)>= samend){}
				else *(sampoint+samcount+count+val1b)=temp;

				counttest=val1*7;
				counttest=counttest+count+1;
				counttest=counttest+samcount;
				if (counttest>=samend)
		{
		count=16385;
		samcount=samend;
		}
				if (count>=val1) count=16385;
				}
		if (samcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		}
		}

	}
}

//-----------------------------------------------------------------
// Manips Tuning Operations

// Tune Octave - Tune 2 Octaves

void	SAMPLEWindow::Tunerng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempcount;
int32 tempsam;
int32 doneb;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

int32 Incount=0;
int32 temp1;
int32 temp2;
int32 temp3;
int32 ref;
int32 samlenb;
int32 barcount;

uint32 samcountb=samstart;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1) || (opt==2) || (opt==3) || (opt==4))
	{
	if (addtyp==0)
		{
		for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		if (opt==0)		// Tune 2 Octaves Up
			{
			if (samcountb>=samend) temp=0;
			else temp=*(sampoint+samcountb);
			if (samcountb<samend)
				{
				if (samcountb >= samend) tempb = 0;
				else tempb=*(sampoint+samcountb);
				}
			else tempb=0;
			samcountb=samcountb+4;
			}
			
		if (opt==1)		// Tune Octave Up
			{
			if (samcountb>=samend) temp=0;
			else temp=*(sampoint+samcountb);
			if (samcountb<samend)
				{
				if (samcountb >= samend) tempb = 0;
				else tempb=*(sampoint+samcountb);
				}
			else tempb=0;
			samcountb=samcountb+2;
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
		if (samcount>=memdivtodo)
			{
			done++;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}	
		}

	if (opt==2)		// Tune Note Up
		{
		Incount=0;
		ref=0;
		for(samcount=samstart;samcount<=samend;samcount++)
			{
			Incount++;
			if (Incount==8)
				{
				if ((samcount+ref-1) >= samend) tempb =0;
				else temp1=*(sampoint+samcount+ref-1);
				if ((samcount+ref+2) >= samend) temp2 =0;
				else temp2=*(sampoint+samcount+ref+2);
				temp1=temp1 << 8;
				temp2=temp2 << 8;
				temp2=temp2-temp1;
				temp2=temp2 >> 1;
				temp2=temp2+temp1;
				temp2=temp2 >> 8;
				temp3=temp2;
				*(sampoint+samcount-1)=temp3;
				ref++;
				Incount=0;
				}
			if ((samcount+ref) >= samend) *(sampoint+samcount)=0;
			else *(sampoint+samcount)=*(sampoint+samcount+ref);

			if (samcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		}
			

	if (opt==3)		// Tune Semitone Up
		{
		Incount=0;
		ref=0;
		for(samcount=samstart;samcount<=samend;samcount++)
			{
			Incount++;
			if (Incount==17)
				{
				if ((samcount+ref-1) >= samend) tempb =0;
				else temp1=*(sampoint+samcount+ref-1);
				if ((samcount+ref+2) >= samend) temp2 =0;
				else temp2=*(sampoint+samcount+ref+2);
				temp1=temp1 << 8;
				temp2=temp2 << 8;
				temp2=temp2-temp1;
				temp2=temp2 >> 1;
				temp2=temp2+temp1;
				temp2=temp2 >> 8;
				temp3=temp2;
				*(sampoint+samcount-1)=temp3;
				ref++;
				Incount=0;
				}
			if ((samcount+ref) >= samend) *(sampoint+samcount)=0;
			else *(sampoint+samcount)=*(sampoint+samcount+ref);
			
			if (samcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo-memdiv;
				}
			}
		}
			

	if (opt==4)		// Tune 1/8 Note Up
		{
		Incount=0;
		ref=0;
		for(samcount=samstart;samcount<=samend;samcount++)
			{
			Incount++;
			if (Incount==71)
				{
				if ((samcount+ref-1) >= samend) tempb =0;
				else temp1=*(sampoint+samcount+ref-1);
				if ((samcount+ref+2) >= samend) temp2 =0;
				else temp2=*(sampoint+samcount+ref+2);
				temp1=temp1 << 8;
				temp2=temp2 << 8;
				temp2=temp2-temp1;
				temp2=temp2 >> 1;
				temp2=temp2+temp1;
				temp2=temp2 >> 8;
				temp3=temp2;
				*(sampoint+samcount-1)=temp3;
				ref++;
				Incount=0;
				}

			if ((samcount+ref) >= samend) *(sampoint+samcount)=0;
			else *(sampoint+samcount)=*(sampoint+samcount+ref);
			if (samcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo-memdiv;
				}
			}
		}
	}
}

if (addtyp==1)
	{
	if (opt==0)		// Tune 2 Octaves Down
		{
		barcount = samstart;
		for (samcount=samend;samcount>samstart;samcount--)
			{
			barcount++;
			tempsam=samstart+1;
			if (samcount>tempsam) samcount--;
			tempcount=samcount-samstart;
			tempcount=tempcount >> 1;
			tempcount=tempcount+samstart;
			if (tempcount>=samend) temp=0;
			else temp=*(sampoint+tempcount);
			if ((tempcount+1)>=samend) tempb=0;
			else tempb=*(sampoint+tempcount+1);
			tempc=tempb-temp;
			tempc=tempc >> 1;
			tempc=tempc+temp;
			*(sampoint+samcount)=temp;
			*(sampoint+samcount+1)=tempc;
			if (barcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,0,50,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		
		barcount = samstart;
//		done=0;
		for (samcount=samend;samcount>samstart;samcount--)
			{
			barcount = samstart;
			tempsam=samstart+1;
			if (samcount>tempsam) samcount--;
			tempcount=samcount-samstart;
			tempcount=tempcount >> 1;
			tempcount=tempcount+samstart;
			if (tempcount>=samend) tempcount=samend-1;
			temp=*(sampoint+tempcount);
			tempb=*(sampoint+tempcount+1);
			tempc=tempb-temp;
			tempc=tempc >> 1;
			tempc=tempc+temp;
			*(sampoint+samcount)=temp;
			*(sampoint+samcount+1)=tempc;
			if (barcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,50,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		}
	}

	if (opt==1)		// Tune Octave Down
		{
		barcount = samstart;
		for (samcount=samend;samcount>samstart;samcount--)
			{
			barcount++;
			tempsam=samstart+1;
			if (samcount>tempsam) samcount--;
			tempcount=samcount-samstart;
			tempcount=tempcount >> 1;
			tempcount=tempcount+samstart;
			if (tempcount>=samend) tempcount=samend-1;
			temp=*(sampoint+tempcount);
			tempb=*(sampoint+tempcount+1);
			tempc=tempb-temp;
			tempc=tempc >> 1;
			tempc=tempc+temp;
			*(sampoint+samcount)=temp;
			*(sampoint+samcount+1)=tempc;
			if (barcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		}

	if (opt==2)		// Tune Note Down
		{
		barcount = samstart;
		samlenb=samlen >> 3;
		Incount=0;
		for(samcount=samend;samcount>samstart;samcount--)
			{
			barcount++;
			Incount++;
			if (Incount==8)
				{
				samlenb--;
				Incount=0;
				}
			origval=*(sampoint+samcount);
			temp=*(sampoint+samcount-samlenb);
			if ((samcount-samlenb) <=samstart) temp=0;
				if (mixlev<256)
				{
				temp=temp*mixlev;
				temp=temp >> 8;
				origval=origval*mixlevb;
				origval=origval >> 8;
				temp=origval+temp;
				}
			*(sampoint+samcount)=temp;
			if (barcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		}

	if (opt==3)		// Tune Semitone Down
		{
		barcount = samstart;
		samlenb=samlen/17;
		Incount=0;
		for(samcount=samend;samcount>samstart;samcount--)
			{
			barcount++;
			Incount++;
			if (Incount==17)
				{
				samlenb--;
				Incount=0;
				}
			origval=*(sampoint+samcount);
			temp=*(sampoint+samcount-samlenb);
			if ((samcount-samlenb) <=samstart) temp=0;
				if (mixlev<256)
				{
				temp=temp*mixlev;
				temp=temp >> 8;
				origval=origval*mixlevb;
				origval=origval >> 8;
				temp=origval+temp;
				}
			*(sampoint+samcount)=temp;
			if (barcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		}

	if (opt==4)		// Tune 1/8 Note Down
		{
		barcount = samstart;
		samlenb=samlen/71;
		Incount=0;
		memdivtodo=samend-memdiv;
		for(samcount=samend;samcount>samstart;samcount--)
			{
			barcount++;
			Incount++;
			if (Incount==71)
				{
				samlenb--;
				Incount=0;
				}
			origval=*(sampoint+samcount);
			temp=*(sampoint+samcount-samlenb);
			if ((samcount-samlenb) <=samstart) temp=0;
				if (mixlev<256)
				{
				temp=temp*mixlev;
				temp=temp >> 8;
				origval=origval*mixlevb;
				origval=origval >> 8;
				temp=origval+temp;
				}
			*(sampoint+samcount)=temp;
			if (barcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,5,100,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}
		}
}


//-----------------------------------------------------------------
// Effects - Detuning Operations

// Detune - Resample

void	SAMPLEWindow::Detunerng(int32 opt,int32 optb)
{
int32 temp;
int32 doneb;

int32 valtemp;
int32 mixlevb;
int32 origval;

int32 Incount=0;
int32 barcount;
uint32 test;
uint32 dir;

int32 ref;
int32 samlenb;
int32 repcount;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;
int32 addtyp=samradio1;
int32 addtypb=samradio2;
int32 mixlev=samslider;

// 0=Old Flange	1=Old Delay Flange
// 2=resample 3=detune	addtyp 0=up 1=down

//printf("val1 %d\n",val1);


if ((opt==0) || (opt==1))	// Old Flange - Old Delay Flange
{
valtemp=256-val1;
valtemp=valtemp << 2;
valtemp=valtemp+250;
val2=261-val2; 
val2=val2 << 1;

if (opt==1)	//	Delay Flange only
	{
	for (repcount=0;repcount<=4;repcount++)
		{
		ref = val4;
		test = samstart+ref;
		for (samcount=samstart;samcount<=samend;samcount++)
			{
			origval = *(sampoint+samcount);
			if (samcount <= test) temp=0;
			else temp=*(sampoint+samcount-ref);
			temp=temp * mixlev;
			temp = temp >> 8;
			if (addtypb == 0) temp=origval+temp;
			if (addtypb == 1) temp=origval-temp;
			temp = temp >> 1;
			*(sampoint+samcount)=temp;
			}
		Rescalenoboxrng();
		}
	}


for (repcount=0;repcount<=4;repcount++)	// Both
	{
	Incount=0;
	test=samend;
	if (addtyp == 0)	// start up
		{
		ref=val2;
		dir = 0;
		}
	if (addtyp == 1)	// Start down
		{
		ref=10;
		dir = 1;
		}

	for(samcount=samstart;samcount<=samend;samcount++)
		{
		Incount++;
		if (Incount==valtemp)
			{
			if (dir == 1) ref++;
			if (dir == 0) ref--;
			if ((ref >= val2) || (ref < 10))
				{
				if (dir == 1) dir=0;
				else if (dir == 0) dir=1;
				}
			test=samstart+ref;
			Incount=0;
			}
		origval=*(sampoint+samcount);
		if (samcount<=test) temp=0;
		else temp=*(sampoint+samcount-ref);

		temp=temp*val3;
		temp=temp >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		temp=temp >> 1;

		*(sampoint+samcount)=temp;
		}
	Rescalenoboxrng();
	Newdrawdonebox(3,0,100,4,repcount,drawbarside);
	}
}	// opt = 0 or 1


if ((opt==2) || (opt==3))// Resample/Dutune Up/Down
	{
	if (addtyp==0)	// Up
		{
		valtemp=256-val1;
		valtemp=valtemp+7;
		Incount=0;
		ref=0;
		test=samend;

		for(samcount=samstart;samcount<=samend;samcount++)
			{
			Incount++;
			if (Incount==valtemp)
				{
				ref++;
				test=samend-ref;
				Incount=0;
				}
			origval=*(sampoint+samcount+memsize);
			if (samcount>=test) temp=0;
			else temp=*(sampoint+samcount+ref);

			if (mixlev<256)
				{
				temp=temp*val2;
				temp=temp >> 8;
				origval=origval*val3;
				origval=origval >> 8;
				temp=origval+temp;
				}

			*(sampoint+samcount)=temp;

			if (samcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,0,95,75,done,drawbarside);
				memdivtodo=memdivtodo+memdiv;
				}
			}	// samcount
		}	// add typ = 0

	if (addtyp==1)	// Down
		{
		valtemp=256-val1;
		valtemp=valtemp+7;
		samlenb=samlen/valtemp;
		Incount=0;
		memdivtodo=samend-memdiv;
		test=samstart+samlenb;
		barcount=samstart;
		for(samcount=samend;samcount>samstart;samcount--)
			{
			barcount++;
			Incount++;
			if (Incount==valtemp)
				{
				samlenb--;
				test=samstart+samlenb;
				Incount=0;
				}
			origval=*(sampoint+samcount+memsize);
			if (samcount<=test) temp=0;
			else temp=*(sampoint+samcount-samlenb);

			if (opt==3)
				{
				temp=temp*val2;
				temp=temp >> 8;
				origval=origval*val3;
				origval=origval >> 8;
				temp=origval+temp;
				temp=temp >> 1;
				}
			*(sampoint+samcount)=temp;

			if (barcount>=memdivtodo)
				{
				done++;
				Newdrawdonebox(3,0,95,75,done,drawbarside);
				memdivtodo=memdivtodo-memdiv;
				}
			}
		}
	Newdrawdonebox(3,95,100,100,100,drawbarside);
	Rescalenoboxrng();
	}	// opt = 2 or 3


}

//-----------------------------------------------------------------
// Manips - Thickening Operations

// 7-Thicken - 8-Double Thicken

void	SAMPLEWindow::Thickenrng(int32 opt,int32 optb)
{
int32 temp;
int32 doneb;

int32 valtemp;
int32 mixlevb;
int32 origval;

int32 Incount=0;
int32 ref;
int32 samlenb;

int32 val1=samslider1;

int32 addtyp=samradio1;
int32 addtypb=samradio2;
int32 mixlev=samslider;
mixlevb=256-mixlev;


if ((opt==0) || (opt==1))
		{

		if ((opt==0) || (opt==1))	// Thicken - Double Thicken
			{
			valtemp=256-val1;
			valtemp=valtemp+80;

			if (opt==11) valtemp=valtemp+6;	// opt == 11 ???

				Incount=0;
				ref=0;

				for(samcount=samstart;samcount<=samend;samcount++)
					{
					Incount++;
					if (Incount==valtemp)
						{
						ref++;
						Incount=0;
						}
					origval=*(sampoint+samcount);
					if ((samcount+ref)>=samend) temp=0;
					else temp=*(sampoint+samcount+ref);

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

					if (makechans!=2)
					{
					if (samcount==memdivtodo)
							{
							done++;
							if (opt==0) doneb=done;
							if (opt==1) doneb=done >> 1;
							Drawdonebox(doneb);
							memdivtodo=memdivtodo+memdiv;
							}
					}
					if (makechans==2)
					{
					if (samcount==memdivtodo)
							{
							done++;
							if (opt==0) doneb=done >> 1;
							if (opt==1) doneb=done >> 2;
							Drawdonebox(doneb);
							memdivtodo=memdivtodo+memdiv;
							}
						}

					}
				Rescalenoboxrng();
			}


		if (opt==0)	// Double Thicken only
			{
			valtemp=256-val1;
			valtemp=valtemp+80;

				samlenb=samlen/valtemp;
				Incount=0;
				memdivtodo=samend-memdiv;
				for(samcount=samend;samcount>samstart;samcount--)
					{
					Incount++;
					if (Incount==valtemp)
						{
						samlenb--;
						Incount=0;
						}
					origval=*(sampoint+samcount);
					if ((samcount-samlenb) <=samstart) temp=0;
					else temp=*(sampoint+samcount-samlenb);

					temp=temp*mixlev;
					temp=temp >> 8;
					origval=origval*mixlevb;
					origval=origval >> 8;
					if (addtyp==0)	temp=origval+temp;
					if (addtyp==1)	temp=origval-temp;

					*(sampoint+samcount)=temp;

					if (makechans!=2)
					{
					if (samcount<=memdivtodo)
							{
							done++;
							if (opt==0) doneb=done;
							if (opt==1) doneb=done >> 1;
							Drawdonebox(doneb);
							memdivtodo=memdivtodo-memdiv;
							}
					}
					if (makechans==2)
					{
					if (samcount<=memdivtodo)
							{
							done++;
							if (opt==0) doneb=done >> 1;
							if (opt==1) doneb=done >> 2;
							Drawdonebox(doneb);
							memdivtodo=memdivtodo-memdiv;
							}
						}

					}
				Rescalenoboxrng();
			}

		}
}

//-----------------------------------------------------------------
// Stereo Arithmetic operations

void	SAMPLEWindow::SArithrng(int32 opt,int32 optb)
{
int32 tempa;
int32 tempb;

int32 mula;
int32 mulb;
int32 mixlev;
int32 mixlevb;

int32 addtyp;
int32 addtypb;

int32 origvall;
int32 origvalr;
int32 tempal;
int32 tempbl;
int32 tempar;
int32 tempbr;

mula=samslider1;
mulb=samslider2;
addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1) || (opt==2)) // Add - Subtract - Backwards Subtract
{
for (samcount=samstart;samcount<=samend;samcount++)
	{
	tempa=*(sampoint+samcount);
	tempb=*(sampoint+samcount+halfmemsize);
	origvall=tempa;
	origvalr=tempb;
	tempal=tempa;
	tempbl=tempb;
	tempar=tempb;
	tempbr=tempa;
			
	tempal=tempal*mula;
	tempbl=tempbl*mulb;

	tempar=tempar*mula;
	tempbr=tempbr*mulb;

	if (opt==0)
		{
		tempal=tempal+tempbl;
		tempar=tempar+tempbr;
		}
	if (opt==1)
		{
		tempal=tempal-tempbl;
		tempar=tempar-tempbr;
		}
	if (opt==2)
		{
		tempal=tempbl-tempal;
		tempar=tempbr-tempar;
		}
	tempal=tempal >> 9;
	tempar=tempar >> 9;

	if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

	if (tempal>=32766) tempal=32766;
	if (tempal<=-32766) tempal=-32766;

	if (tempar>=32766) tempar=32766;
	if (tempar<=-32766) tempar=-32766;

	*(sampoint+samcount)=tempal;
	*(sampoint+samcount+halfmemsize)=tempar;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	}
if (addtyp==1)
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
}


if ((opt==3) || (opt==4) || (opt==5)) // Multiply - Divide - Backwards Divide
{
for (samcount=samstart;samcount<=samend;samcount++)
	{
	tempa=*(sampoint+samcount);
	tempb=*(sampoint+samcount+halfmemsize);
	origvall=tempa;
	origvalr=tempb;
	if ((opt==4) || (opt==5))
		{
		if (tempa==0) tempa=1;
		if (tempb==0) tempb=1;
		}
	tempal=tempa;
	tempbl=tempb;
	tempar=tempb;
	tempbr=tempa;
			
	tempal=tempal*mula;
	tempbl=tempbl*mulb;

	tempar=tempar*mula;
	tempbr=tempbr*mulb;

	if (opt==3)
		{
		tempal=tempal >> 8;
		tempbl=tempbl >> 8;
		tempal=tempal*tempbl;
		tempal=tempal >> 8;
		if (tempal>=32766) tempal=32766;
		if (tempal<=-32766) tempal=-32766;

		tempar=tempar >> 8;
		tempbr=tempbr >> 8;
		tempar=tempar*tempbr;
		tempar=tempar >> 8;
		if (tempar>=32766) tempar=32766;
		if (tempar<=-32766) tempar=-32766;
		}
	if (opt==4)
		{
		if (tempbl == 0) tempbl=1;
		tempal=tempal/tempbl;
		tempal=tempal << 12;

		if (tempbr == 0) tempbr=1;
		tempar=tempar/tempbr;
		tempar=tempar << 12;
		}
	if (opt==5)
		{
		if (tempal == 0) tempal=1;
		tempal=tempbl/tempal;
		tempal=tempal << 12;

		if (tempar == 0) tempar=1;
		tempar=tempbr/tempar;
		tempar=tempar << 12;
		}

	if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

	*(sampoint+samcount)=tempal;
	*(sampoint+samcount+halfmemsize)=tempar;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	}
if (addtyp==1)
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
}


if ((opt==6) || (opt==7) || (opt==8))	// AND - OR - XOR
{
for (samcount=samstart;samcount<=samend;samcount++)
	{
	tempa=*(sampoint+samcount);
	tempb=*(sampoint+samcount+halfmemsize);
	origvall=tempa;
	origvalr=tempb;
	tempal=tempa;
	tempbl=tempb;
	tempar=tempb;
	tempbr=tempa;
			
	tempal=tempal*mula;
	tempbl=tempbl*mulb;

	tempar=tempar*mula;
	tempbr=tempbr*mulb;

	if (addtypb==1)
		{
		tempbl=~tempbl;
		tempbr=~tempbr;
		}

	if (opt==6)
		{
		tempal=tempal & tempbl;
		tempar=tempar & tempbr;
		}
	if (opt==7)
		{
		tempal=tempal | tempbl;
		tempar=tempar | tempbr;
		}
	if (opt==8)
		{
		tempal=tempal ^ tempbl;
		tempar=tempar ^ tempbr;
		}
	tempal=tempal >> 8;
	tempar=tempar >> 8;

	if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

	*(sampoint+samcount)=tempal;
	*(sampoint+samcount+halfmemsize)=tempar;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	}
}


if ((opt==9) || (opt==10))		// Greater - Lesser
{
for (samcount=samstart;samcount<=samend;samcount++)
	{
	tempa=*(sampoint+samcount);
	tempb=*(sampoint+samcount+halfmemsize);
	origvall=tempa;
	origvalr=tempb;
	tempal=tempa;
	tempbl=tempb;
	tempar=tempb;
	tempbr=tempa;
			
	tempal=tempal*mula;
	tempbl=tempbl*mulb;

	tempar=tempar*mula;
	tempbr=tempbr*mulb;

	if (addtypb==1)
		{
		tempbl=~tempbl;
		tempbr=~tempbr;
		}

	if (opt==9)
		{
		if (tempal<=0)
			{
			tempal = (tempal<tempbl) ? tempal : tempbl;
			}
		if (tempal>=0)
			{
			tempal = (tempal>tempbl) ? tempal : tempbl;
			}

		if (tempar<=0)
			{
			tempar = (tempar<tempbr) ? tempar : tempbr;
			}
		if (tempar>=0)
			{
			tempar = (tempar>tempbr) ? tempar : tempbr;
			}
		}

	if (opt==10)
		{
		if (tempal>=0)
			{
			tempal = (tempal<tempbl) ? tempal : tempb;
			}
		if (tempal<=0)
			{
			tempal = (tempal>tempbl) ? tempal : tempbl;
			}

		if (tempar>=0)
			{
			tempar = (tempar<tempbr) ? tempar : tempbr;
			}
		if (tempar<=0)
			{
			tempar = (tempar>tempbr) ? tempar : tempbr;
			}
		}
	tempal=tempal >> 8;
	tempar=tempar >> 8;

	if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

	*(sampoint+samcount)=tempal;
	*(sampoint+samcount+halfmemsize)=tempar;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	}
}


if ((opt==11) || (opt==12))		// Modulus - Backwards Modulus
{
for (samcount=samstart;samcount<=samend;samcount++)
	{
	tempa=*(sampoint+samcount);
	tempb=*(sampoint+samcount+halfmemsize);
	origvall=tempa;
	origvalr=tempb;
	if (tempa==0) tempa=1;
	if (tempb==0) tempb=1;
	tempal=tempa;
	tempbl=tempb;
	tempar=tempb;
	tempbr=tempa;
			
	tempal=tempal*mula;
	tempbl=tempbl*mulb;

	tempar=tempar*mula;
	tempbr=tempbr*mulb;

	if (addtypb==1)
		{
		tempbl=~tempbl;
		tempbr=~tempbr;
		}

	if (opt==11)
		{
		if (tempbl == 0) tempbl=1;
		tempal=tempal%tempbl;
		if (tempbr == 0) tempbr=1;
		tempar=tempar%tempbr;
		}

	if (opt==12)
		{
		if (tempal == 0) tempal=1;
		tempal=tempbl%tempal;
		if (tempar == 0) tempar=1;
		tempar=tempbr%tempar;
		}
	tempal=tempal >> 8;
	tempar=tempar >> 8;

	if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

	*(sampoint+samcount)=tempal;
	*(sampoint+samcount+halfmemsize)=tempar;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	}

if (addtyp==1)
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
}

}

//-----------------------------------------------------------------
// Interleaving SFX operations

// 11				14		15		16
// Interleave - Stutter - Rectify - Swap Samples

void	SAMPLEWindow::SInterrng(int32 opt,int32 optb)
{
int32 origval;

int32 tempa;
int32 tempb;
int32 tempc;

int32 origvall;
int32 origvalr;
int32 tempal;
int32 tempbl;
int32 tempar;
int32 tempbr;

int32 mula;
int32 mulb;
int32 val3;
int32 mixlev;
int32 mixlevb;
int32 addtyp;
int32 addtypb;

int32 type;
int32 leavcount=0;
uint32 incount;

val3=samslider3;
mula=samslider1;
mulb=samslider2;
addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1) || (opt==2) || (opt==3) || (opt==4))
{
if (opt==0)	// Interleave
	{
	incount=position;
	type=1;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		incount++;
		tempa=*(sampoint+samcount);
		tempb=*(sampoint+samcount+halfmemsize);
		origval=tempa;
		tempa=tempa*mula;
		tempb=tempb*mulb;
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
	*(sampoint+samcount+halfmemsize)=tempb;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	}
}


// Stutter - Rectify - Swap Samples - Amplitude Modulation

if ((opt==1) || (opt==2) || (opt==3) || (opt==4))
{
for (samcount=samstart;samcount<=samend;samcount++)
	{
	tempa=*(sampoint+samcount);
	tempb=*(sampoint+samcount+halfmemsize);
	origvall=tempa;
	origvalr=tempb;
	tempal=tempa;
	tempbl=tempb;
	tempar=tempb;
	tempbr=tempa;

	if (opt==1)
		{
		if (addtyp==0) if (tempbl<=0) tempal=0;
		if (addtyp==1) if (tempbl>=0) tempal=0;

		if (addtyp==0) if (tempbr<=0) tempar=0;
		if (addtyp==1) if (tempbr>=0) tempar=0;
		}

	if (opt==2)
		{
		if (addtypb==0)
			{
			if (addtyp==0)
				{
				if (tempbl<=0)
					{
					if (tempal>=1) tempal=~tempal;
					}
				if (tempbl>=1)
					{
					if (tempal<=0) tempal=~tempal;
					}
				}
			if (addtyp==1)
				{
				if (tempbl>=1)
					{
					if (tempal>=1) tempal=~tempal;
					}
				if (tempbl<=0)
					{
					if (tempal<=0) tempal=~tempal;
					}
				}
			}
		if (addtypb==1)
			{
			if (addtyp==0)
				{
				if (tempbl>=1)
					{
					if (tempal<=0) tempal=~tempal;
					}
				}
			if (addtyp==1)
				{
				if (tempbl<=0)
					{
					if (tempal>=1) tempal=~tempal;
					}
				}
			}
		if (addtypb==0)
			{
			if (addtyp==0)
				{
				if (tempbr<=0)
					{
					if (tempar>=1) tempar=~tempar;
					}
				if (tempbr>=1)
					{
					if (tempar<=0) tempar=~tempar;
					}
				}
			if (addtyp==1)
				{
				if (tempbr>=1)
					{
					if (tempar>=1) tempar=~tempar;
					}
				if (tempbr<=0)
					{
					if (tempar<=0) tempar=~tempar;
					}
				}
			}
		if (addtypb==1)
			{
			if (addtyp==0)
				{
				if (tempbr>=1)
					{
					if (tempar<=0) tempar=~tempar;
					}
				}
			if (addtyp==1)
				{
				if (tempbr<=0)
					{
					if (tempar>=1) tempar=~tempar;
					}
				}
			}
		}

	if (opt==3)
		{
		tempal=tempbl;
		tempar=tempbr;
		if (mula >= 1)
			{
			tempb = tempbr;
			tempc = tempbl;
			tempb = tempb * mula;
			tempb = tempb >> 8;
			tempc = tempc * mula;
			tempc = tempc >> 8;
			tempal = tempal + tempb;
			tempar = tempar + tempc;
			tempal = tempal >> 1;
			tempar = tempar >> 1;
			}
		}

	if (opt==4)		// Amplitude Modulation
		{
		tempal=tempal*tempbl;
		tempal=tempal >> 15;
		if (addtyp==1)
			{
			if ((origvall<0) && (tempal>0))	tempal=~tempal;
			if ((origvall>0) && (tempal<0))	tempal=~tempal;
			}
		if (tempal>=32766) tempal=32766;
		if (tempal<=-32766) tempal=-32766;

		tempar=tempar*tempbr;
		tempar=tempar >> 15;
		if (addtyp==1)
			{
			if ((origvalr<0) && (tempar>0))	tempar=~tempar;
			if ((origvalr>0) && (tempar<0))	tempar=~tempar;
			}
		if (tempar>=32766) tempar=32766;
		if (tempar<=-32766) tempar=-32766;
		}

	if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

	*(sampoint+samcount)=tempal;
	*(sampoint+samcount+halfmemsize)=tempar;
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
// Zero Out MANIP

void	SAMPLEWindow::Zerooutrng(int32 opt,int32 optb)
{

if (opt==0)
{
 done=0;
 if (makechans==0)
		{
		memdiv=halfmemsize/10;
		memdivtodo=memdiv;
		for (samcount=0;samcount<=halfmemsize;samcount++)
			{
			if (samcount<samstart) *(sampoint+samcount)=0;
			if (samcount==samstart) samcount=samend+1;
			if (samcount>samend)		*(sampoint+samcount)=0;
			if (samcount>=memdivtodo)
		{
		done=samcount/memdiv;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			}
		}
 if (makechans==1)
		{
		memdiv=halfmemsize/10;
		memdivtodo=memdiv;
		for (samcount=halfmemsize;samcount<=memsize;samcount++)
			{
			if (samcount<samstart) *(sampoint+samcount)=0;
			if (samcount==samstart) samcount=samend+1;
			if (samcount>samend)		*(sampoint+samcount)=0;
			if (samcount>=memdivtodo)
		{
		done=samcount/memdiv;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			}
		}
 if (makechans==2)
		{
		memdiv=memsize/10;
		memdivtodo=memdiv;
		for (samcount=0;samcount<=halfmemsize;samcount++)
			{
			if (samcount<samstart) *(sampoint+samcount)=0;
			if (samcount==samstart) samcount=samend+1;
			if (samcount>samend)		*(sampoint+samcount)=0;
			if (samcount>=memdivtodo)
		{
		done=samcount/memdiv;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			}
		for (samcount=halfmemsize;samcount<=memsize;samcount++)
			{
			if (samcount<samstartb) *(sampoint+samcount)=0;
			if (samcount==samstartb) samcount=samendb+1;
			if (samcount>samendb)		*(sampoint+samcount)=0;
			if (samcount>=memdivtodo)
		{
		done=samcount/memdiv;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			}
		}
 if (makechans==3)
		{
		memdiv=memsize/10;
		memdivtodo=memdiv;
		for (samcount=0;samcount<=memsize;samcount++)
			{
			if (samcount<samstart) *(sampoint+samcount)=0;
			if (samcount==samstart) samcount=samend+1;
			if (samcount>samend)		*(sampoint+samcount)=0;
			if (samcount>=memdivtodo)
		{
		done=samcount/memdiv;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			}
		}
}
}

//-----------------------------------------------------------------
// Effects Compress - Expand

// 17=Compress - 18=Expand


void	SAMPLEWindow::Compressrng(int32 opt,int32 optb)
{
int32 temp;

double dtemp;
double dtempb;
int32 calced=0;
int32 count;
int32 origtemp;

int32 addtyp,addtypb;
int32 mixlev;
int32 mixlevb;
int32 origval;

addtyp=samradio1;
addtypb=samradio2;

mixlev=samslider1;
mixlevb=256-mixlev;

if ((opt==0) || (opt==1))
		{

 if (samlen>=80000)
		{
		for (samcount=samstart;samcount<=samend;samcount++)
			{
			temp=*(sampoint+samcount);
			temp=temp*99;		// scale vals down to avoid clipping
			temp=temp/100;
			origval=temp;

		if (opt==0) // compress
			{
			if (calced == 1)
				{
				temp=temp+32767;
				temp=complexbuf[temp];
				}
			else if (calced == 0)
				{
				Drawdonebox(1);
				for (count=0;count<=65535;count++)
					{
					temp=count;
					temp=temp-32767;
					origtemp=temp;
					dtemp=temp;
					dtemp=dtemp/20855.66374;
					if (origtemp<0)
							{
							dtempb=dtemp*2;
							dtemp=dtemp-dtempb;
							}
					dtemp=sqrt(dtemp);	// Squareroot
					dtemp=dtemp*25000;
					if (origtemp==0) dtemp=0;
					if (origtemp<0)
							{
							dtempb=dtemp*2;
							dtemp=dtemp-dtempb;
							}
					if (dtemp>=32766) dtemp=32766;
					if (dtemp<=-32766) dtemp=-32766;
					temp=dtemp;
					complexbuf[count]=temp;
					}
				calced=1;
				temp=origval;
				temp=temp+32767;
				temp=complexbuf[temp];
				}
			}

		if (opt==1)		// expand
			{
			if (calced == 1)
				{
				temp=temp+32767;
				temp=complexbuf[temp];
				}
			else if (calced == 0)
				{
				Drawdonebox(1);
				for (count=0;count<=65535;count++)
					{
					temp=count;
					temp=temp-32767;
					dtemp=temp;
					dtemp=dtemp/20855.66374;
					dtemp=tan(dtemp);		// tan
					dtemp=dtemp*2048;
					if (dtemp>=32766) dtemp=32766;
					if (dtemp<=-32766) dtemp=-32766;
					temp=dtemp;
					complexbuf[count]=temp;
					}
				calced=1;
				temp=origval;
				temp=temp+32767;
				temp=complexbuf[temp];
				}
			}

		if (mixlev<256)	// mixlev = val1
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
	}		// samlen



 if (samlen <80000)
		{
		for (samcount=samstart;samcount<=samend;samcount++)
			{
			temp=*(sampoint+samcount);

			temp=temp*99;		// scale vals down to avoid clipping
			temp=temp/100;
			origval=temp;
			dtemp=temp;
			dtemp=dtemp/20855.66374;

		if (opt==0)		//	Compress
			{
			if (origval<0)
				{
				dtempb=dtemp*2;
				dtemp=dtemp-dtempb;
				}
			dtemp=sqrt(dtemp);	// sqrt
			dtemp=dtemp*25000;
			if (origval==0) dtemp=0;
			if (origval<0)
				{
				dtempb=dtemp*2;
				dtemp=dtemp-dtempb;
				}
			}

		if (opt==1)		//	Expand
			{
			dtemp=tan(dtemp);		// tan
			dtemp=dtemp*2048;	
			}

		if (dtemp>=32766) dtemp=32766;
		if (dtemp<=-32766) dtemp=-32766;
		temp=dtemp;

		if (mixlev<256)	// mixlev = val1
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
	} // samlen


	}
}

//-----------------------------------------------------------------
// Stereo Pan Operations

void	SAMPLEWindow::Sfaderng(int32 opt,int32 optb)
{
int32 tempa;
int32 tempb;
int32 mixlev;
int32 mixlevb;

int32 val1;
int32 val2;
int32 val3;
int32 val4;
int32 addtyp;
int32 addtypb;

int32 origvall;
int32 origvalr;
int32 tempal;
int32 tempbl;
int32 tempar;
int32 tempbr;

int32 tempval1;

int32 valdiff;
int32 stepdiff;
int32 stepno;
int32 chngno=-1;

int32 tempval1b;

int32 valdiffb;
int32 stepdiffb;
int32 stepnob;
int32 chngnob=-1;

int32 pos=1;
int32 neg=-1;

val1=samslider1;
val2=samslider2;
val3=samslider3;
val4=samslider4;
addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

 // Pan - Pan Left - Pan Right

if ((opt==0) || (opt==1) || (opt==2))
	{

	if (opt==1)	//	Pan Left
		{
		val1=256;
		val2=256;
		val3=256;
		val4=0;
		}

	if (opt==2)	//	Pan Right
		{
		val1=256;
		val2=0;
		val3=256;
		val4=256;
		}

	valdiff=val1-val2;
	if (valdiff<0)
		{
		valdiff=~valdiff;
		chngno=1;
		}
	else chngno=-1;
	if (valdiff==0) valdiff=1;
	stepdiff=samlen/valdiff;
	stepno=samstart+stepdiff;
	tempval1=val1;

	valdiffb=val3-val4;
	if (valdiffb<0)
		{
		valdiffb=~valdiffb;
		chngnob=1;
		}
	else chngnob=-1;
	if (valdiffb==0) valdiffb=1;
	stepdiffb=samlen/valdiffb;
	stepnob=samstart+stepdiffb;
	tempval1b=val3;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		tempa=*(sampoint+samcount);
		tempb=*(sampoint+samcount+halfmemsize);
		origvall=tempa;
		origvalr=tempb;
		tempal=tempa;
		tempar=tempb;

	if (samcount==stepno)
		{
		tempval1=tempval1+chngno;
		stepno=stepno+stepdiff;
		}
	tempal=tempal * tempval1;
	tempal=tempal >> 8;

	if (samcount==stepnob)
		{
		tempval1b=tempval1b+chngnob;
		stepnob=stepnob+stepdiffb;
		}
	tempar=tempar * tempval1b;
	tempar=tempar >> 8;

	if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

	if (tempal>=32766) tempal=32766;
	if (tempal<=-32766) tempal=-32766;

	if (tempar>=32766) tempar=32766;
	if (tempar<=-32766) tempar=-32766;

	*(sampoint+samcount)=tempal;
	*(sampoint+samcount+halfmemsize)=tempar;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	}
}


if (opt==3)		//	Pan Ping Pong
	{
if (val3<=0) val3=1;
val3=val3 << 9;
val4=val3;

	valdiff=val1-val2;
	if (valdiff<0)
		{
		valdiff=~valdiff;
		chngno=pos;
		chngnob=neg;
		}
	else
		{
		chngno=neg;
		chngnob=pos;
		}
	if (valdiff==0) valdiff=1;
	stepdiff=val4/valdiff;
	stepno=samstart+stepdiff;
	tempval1=val1;
	tempval1b=val2;

		for (samcount=samstart;samcount<=samend;samcount++)
			{
			tempa=*(sampoint+samcount);
			tempb=*(sampoint+samcount+halfmemsize);
			origvall=tempa;
			origvalr=tempb;
			tempal=tempa;
			tempar=tempb;

			if (samcount==stepno)
		{
		if (samcount>=val4)
			{
			val4=val4+val3;

			if (chngno==pos)
				{
				chngno=neg;
				chngnob=pos;
				}
			else if (chngno==neg)
				{
				chngno=pos;
				chngnob=neg;
				}
			}
		tempval1=tempval1+chngno;
		tempval1b=tempval1b+chngnob;
		stepno=stepno+stepdiff;
		}

			tempal=tempal * tempval1;
			tempal=tempal >> 8;
			tempar=tempar * tempval1b;
			tempar=tempar >> 8;

			if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

			if (tempal>=32766) tempal=32766;
			if (tempal<=-32766) tempal=-32766;

			if (tempar>=32766) tempar=32766;
			if (tempar<=-32766) tempar=-32766;

			*(sampoint+samcount)=tempal;
			*(sampoint+samcount+halfmemsize)=tempar;
			if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			}
		}


 //	Cross Fade Right Left
 //	Cross Fade Left Right

if ((opt==4) || (opt==5))
	{

	if (opt==4)		//	Cross Fade Right Left
		{
		val1=256;
		val2=0;
		val3=0;
		val4=256;
		}

	if (opt==5)		//	Cross Fade Mono
		{
		if (addtyp==0)
				{
				val1=256;
				val2=256;
				val3=0;
				val4=256;
				}
		if (addtyp==1)
				{
				val1=256;
				val2=256;
				val3=256;
				val4=0;
				}
		}

	valdiff=val1-val2;
	if (valdiff<0)
		{
		valdiff=~valdiff;
		chngno=1;
		}
	else chngno=-1;
	if (valdiff==0) valdiff=1;
	stepdiff=samlen/valdiff;
	stepno=samstart+stepdiff;
	tempval1=val1;

	valdiffb=val3-val4;
	if (valdiffb<0)
		{
		valdiffb=~valdiffb;
		chngnob=1;
		}
	else chngnob=-1;
	if (valdiffb==0) valdiffb=1;
	stepdiffb=samlen/valdiffb;
	stepnob=samstart+stepdiffb;
	tempval1b=val3;

		for (samcount=samstart;samcount<=samend;samcount++)
			{
			tempa=*(sampoint+samcount);
			tempb=*(sampoint+samcount+halfmemsize);
			origvall=tempa;
			origvalr=tempb;
			tempal=tempa;
			tempar=tempb;
			tempbl=tempb;
			tempbr=tempa;

			if (samcount==stepno)
		{
		tempval1=tempval1+chngno;
		stepno=stepno+stepdiff;
		}
			tempal=tempal * tempval1;
			tempal=tempal >> 8;
			tempar=tempar * tempval1;
			tempar=tempar >> 8;

			if (samcount==stepnob)
		{
		tempval1b=tempval1b+chngnob;
		stepnob=stepnob+stepdiffb;
		}
			tempbl=tempbl * tempval1b;
			tempbl=tempbl >> 8;
			tempbr=tempbr * tempval1b;
			tempbr=tempbr >> 8;

			tempal=tempal+tempbl;
			tempal=tempal >> 1;
			tempar=tempar+tempbr;
			tempar=tempar >> 1;

			if (mixlev<256)
		{
		tempal=tempal*mixlev;
		tempal=tempal >> 8;
		origvall=origvall*mixlevb;
		origvall=origvall >> 8;
		if (addtypb==0) tempal=origvall+tempal;
		if (addtypb==1) tempal=origvall-tempal;

		tempar=tempar*mixlev;
		tempar=tempar >> 8;
		origvalr=origvalr*mixlevb;
		origvalr=origvalr >> 8;
		if (addtypb==0) tempar=origvalr+tempar;
		if (addtypb==1) tempar=origvalr-tempar;
		}

			if (tempal>=32766) tempal=32766;
			if (tempal<=-32766) tempal=-32766;

			if (tempar>=32766) tempar=32766;
			if (tempar<=-32766) tempar=-32766;

			*(sampoint+samcount)=tempal;
			*(sampoint+samcount+halfmemsize)=tempar;
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
// Block MANIPS


// 60 Transform Blocks		X
// 61 Reverse Single Blocks	X
// 62 Reverse All Blocks			X
// 63 Skip Blocks					X
// 64 Repeat Blocks			X
// 65 Flip Alternate			X
// 67 Auto Stutter				X


void	SAMPLEWindow::Blockrng(int32 opt,int32 optb)
{

int32 temp;
int32 tempb;
int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;

int32 origval;
int32 origvalb;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;

int32 val1b;
int32 val1c;
int32 val2b;
int32 val1d;
int32 val1e;

int32 incount;
int32 memdivtodo;

int32 blockstart;
int32 outcount;
int32 halfsamend;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if (val1<=0) val1=1;
if (val2<=0) val2=1;

val2b=256-val2;

if ((opt==0) || (opt==1) || (opt==2) || (opt==3) || (opt==4) 
 || (opt==5) || (opt==6))
	{

if (opt==0)			// Transform Blocks
{
 if (addtyp==0) val1=val1 << 1;
 if (addtyp==1) val1=val1 << 5;

 val1b=samstart;
 val1c=val1b+val1;
 val1d=val1c+val1;
 val1e=val1d+val1;

		for (samcount=samstart;samcount<=samend;samcount++)
			{
			temp=*(sampoint+samcount);
			if ((samcount>=val1b) && (samcount<val1c)) temp=temp*val2;
			if ((samcount>=val1c) && (samcount<val1d)) temp=temp*val3;
			if ((samcount>=val1d) && (samcount<val1e)) temp=temp*val4;
			temp=temp >> 8;

			if (mixlev<256)
		{
		tempb=tempb*mixlev;
		tempb=tempb >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		if (addtypb==0) temp=origvalb+temp;
		if (addtypb==1) temp=origvalb-temp;
		}
			*(sampoint+samcount)=temp;
			if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			if (samcount==val1e)
		{
		val1b=val1e;
		val1c=val1b+val1;
		val1d=val1c+val1;
		val1e=val1d+val1;
		}
			}
}


if (opt==1)			// Reverse Single Blocks
{
 if (addtyp==0) val1=val1 << 3;
 if (addtyp==1) val1=val1 << 7;
 val1b=val1/2;
 val1c=val1b+samstart;
 incount=samstart+val1;
 blockstart=samstart;

for (outcount=samstart;outcount<=samend;outcount++)
{

 if (incount<samend)
		{
		for (samcount=blockstart;samcount<=val1c;samcount++)
			{
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

		temp=temp*mixlev;
		temp=temp >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}
			*(sampoint+samcount)=tempb;
			*(sampoint+incount)=temp;
			if (samcount>=memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			incount--;
			}
		}

	blockstart=blockstart+val1;
	val1c=blockstart+val1b;
	incount=blockstart+val1;
	outcount=incount;
	}
}


if (opt==2)			// Reverse All Blocks --------------
{
 if (addtyp==0) val1=val1 << 3;
 if (addtyp==1) val1=val1 << 7;
 val1b=val1/2;
 val1c=val1b+samstart;
 incount=samstart+val1;
 blockstart=samstart;

 // Reverse Individual Blocks

for (outcount=samstart;outcount<=samend;outcount++)
{

 if (incount<samend)
		{
		for (samcount=blockstart;samcount<=val1c;samcount++)
			{
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

		temp=temp*mixlev;
		temp=temp >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}
			*(sampoint+samcount)=tempb;
			*(sampoint+incount)=temp;
			if (samcount>=memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			incount--;
			}
		}

	blockstart=blockstart+val1;
	val1c=blockstart+val1b;
	incount=blockstart+val1;
	outcount=incount;
	}

 // Reverese Sample

 incount=samend;
 halfsamend=samlen >> 1;
 halfsamend=halfsamend+samstart;

 for (samcount=samstart;samcount<=halfsamend;samcount++)
		{
		temp=*(sampoint+samcount);
		tempb=*(sampoint+incount);
		*(sampoint+samcount)=tempb;
		*(sampoint+incount)=temp;
		incount--;
		}


if (addtypb==1) // Double
{
 val1=val1*1.3;
 val1b=val1/2;
 val1c=val1b+samstart;
 incount=samstart+val1;
 blockstart=samstart;

 // Reverse Individual Blocks

for (outcount=samstart;outcount<=samend;outcount++)
{

 if (incount<samend)
		{
		for (samcount=blockstart;samcount<=val1c;samcount++)
			{
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

		temp=temp*mixlev;
		temp=temp >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}
			*(sampoint+samcount)=tempb;
			*(sampoint+incount)=temp;
			if (samcount>=memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			incount--;
			}
		}

	blockstart=blockstart+val1;
	val1c=blockstart+val1b;
	incount=blockstart+val1;
	outcount=incount;
	}

 // Reverse Sample

 incount=samend;
 halfsamend=samlen >> 1;
 halfsamend=halfsamend+samstart;

 for (samcount=samstart;samcount<=halfsamend;samcount++)
		{
		temp=*(sampoint+samcount);
		tempb=*(sampoint+incount);
		*(sampoint+samcount)=tempb;
		*(sampoint+incount)=temp;
		incount--;
		}

 val1=samslider1;		// re-read original
 if (addtyp==0) val1=val1 << 3;
 if (addtyp==1) val1=val1 << 7;
 val1b=val1/2;
 val1c=val1b+samstart;
 incount=samstart+val1;
 blockstart=samstart;

 // Reverse Individual Blocks

for (outcount=samstart;outcount<=samend;outcount++)
{

 if (incount<samend)
		{
		for (samcount=blockstart;samcount<=val1c;samcount++)
			{
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

		temp=temp*mixlev;
		temp=temp >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		if (addtypb==0) temp=origval+temp;
		if (addtypb==1) temp=origval-temp;
		}
			*(sampoint+samcount)=tempb;
			*(sampoint+incount)=temp;
			if (samcount>=memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			incount--;
			}
		}

	blockstart=blockstart+val1;
	val1c=blockstart+val1b;
	incount=blockstart+val1;
	outcount=incount;
	}

 // Reverse Sample

 incount=samend;
 halfsamend=samlen >> 1;
 halfsamend=halfsamend+samstart;

 for (samcount=samstart;samcount<=halfsamend;samcount++)
		{
		temp=*(sampoint+samcount);
		tempb=*(sampoint+incount);
		*(sampoint+samcount)=tempb;
		*(sampoint+incount)=temp;
		incount--;
		}
}
}
 //											---------------------------------


if (opt==3)			// Skip Blocks
{
 if (addtyp==0) val1=val1 << 3;
 if (addtyp==1) val1=val1 << 7;

 incount=samstart;
 val1c=incount+val1;

		for (samcount=samstart;samcount<=samend;samcount++)
			{
			temp=*(sampoint+samcount);
			if (incount >= samend)
				{
				tempb=0;
				samcount == samend;
				}
			else tempb=*(sampoint+incount);
			origvalb=tempb;
			temp=tempb;		// May be a bug ???
			if (mixlev<256)
		{
		tempb=tempb*mixlev;
		tempb=tempb >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		if (addtypb==0) temp=origvalb+temp;
		if (addtypb==1) temp=origvalb-temp;
		}
			*(sampoint+samcount)=temp;
			if (samcount>=memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			incount++;
			if (incount==val1c)
		{
		incount=incount+val1;
		val1c=incount+val1;
		}
			}
}


if (opt==4)			// Repeat Blocks
{
 if (addtyp==0) val1=val1 << 3;
 if (addtyp==1) val1=val1 << 7;
 blockstart=samstart;
 val1c=samstart+val1;
 incount=val1c;
 val1d=val1c+val1;

for (outcount=samstart;outcount<=samend;outcount++)
{

 if (val1d<=samend)
		{
		for (samcount=blockstart;samcount<=val1c;samcount++)
			{
			temp=*(sampoint+samcount);
			if (incount >= samend)
				{
				tempb=0;
				samcount == samend;
				}
			else tempb=*(sampoint+incount);
			origvalb=tempb;
			if (mixlev<256)
		{
		tempb=tempb*mixlev;
		tempb=tempb >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		if (addtypb==0) temp=origvalb+temp;
		if (addtypb==1) temp=origvalb-temp;
		}
			*(sampoint+incount)=temp;
			if (samcount>=memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			incount++;
			}
		}

	blockstart=blockstart+val1+val1;
	val1c=blockstart+val1;
	incount=val1c;
	outcount=incount;
	val1d=val1c+val1;
	}
}


if (opt==5)			// Flip Alternate
{
 if (addtyp==0) val1=val1 << 3;
 if (addtyp==1) val1=val1 << 7;

 val1b=samstart+val1;
 val1c=val1b+val1;

		for (samcount=samstart;samcount<=samend;samcount++)
			{
			temp=*(sampoint+samcount);
			if (samcount>=val1b)temp=~temp; 
			if (mixlev<256)
		{
		tempb=tempb*mixlev;
		tempb=tempb >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		if (addtypb==0) temp=origvalb+temp;
		if (addtypb==1) temp=origvalb-temp;
		}
			*(sampoint+samcount)=temp;
			if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			if (samcount==val1c)
		{
		val1b=val1c+val1;
		val1c=val1b+val1;
		}
			}
}


if (opt==6)			// Auto Stutter
{
 if (addtyp==0) val1=val1 << 3;
 if (addtyp==1) val1=val1 << 7;
 blockstart=samstart;
 val1c=samstart+val1;
 incount=val1c;
 val1d=val1c+val1;

for (outcount=samstart;outcount<=samend;outcount++)
{

 if (val1d<=samend)
		{
		for (samcount=blockstart;samcount<=val1c;samcount++)
			{
			temp=0;
			tempb=*(sampoint+incount);
			origvalb=tempb;
			if (mixlev<256)
		{
		tempb=tempb*mixlev;
		tempb=tempb >> 8;
		origvalb=origvalb*mixlevb;
		origvalb=origvalb >> 8;
		temp=origvalb;
		}
			*(sampoint+incount)=temp;
			if (samcount>=memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
			incount++;
			}
		}

	blockstart=blockstart+val1+val1;
	val1c=blockstart+val1;
	incount=val1c;
	outcount=incount;
	val1d=val1c+val1;
	}
}

}
}

//-----------------------------------------------------------------
// Noisy MANIPS


// 59 Filtered Noise
// 66 2D Blur
// 68 Random
// 69 Random Amplifier	
// 70 Random Filter				
// 71 Rumble

void	SAMPLEWindow::Blurrng(int32 opt,int32 optb)
{

int32 temp;

int32 tempa1;
int32 tempa2;
int32 tempa3;
int32 temp1;
int32 temp2;
int32 temp3;
int32 tempb1;
int32 tempb2;
int32 tempb3;

uint32 testa;
uint32 testb;

int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;

int32 origval;
int32 incount;

int32 val1=samslider1;
int32 val2;
int32 val3;
int32 val4;

int32 val1b;
int32 val1c;

int32 memdivtodo;
int32 repno;
int32 repcount;

int32 tempb;
int32 tempc;
int32 tempd;
int32 tempe;
int32 tempf;

int32 tempval1;
int32 tempval2;
int32 tempval1b;
int32 tempval2b;

int32 inrepcount;

int32 valno;
int32 valdiff;
int32 stepdiff;

int32 stepno;
int32 chngno=-1;

int32 lowpassval;
int32 highpassval;
int32 midpassval;

int32 lenval;
int32 sftno;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if (val1<=0) val1=1;


if (opt==0)		// Filtered Noise
{

for (samcount=samstart;samcount<=samend;samcount++)
	{
	temp=rand();
	*(sampoint+samcount)=temp;
	}

val1=260-samslider1;
val1=val1 >> 1;
val2=val1;
val3=6;
val4=256;

tempval1=val1;
valno=tempval1;

addtyp=1;
addtypb=1;
mixlev=samslider;
mixlevb=256-mixlev;

repno=2;
chngno=-1;
valdiff=1;
stepdiff=samlen/valdiff;

for (repcount=1;repcount<=repno;repcount++)
	{
	stepno=samstart+stepdiff;
	tempval1=val1;
	if (tempval1<=0) tempval1=1;
	tempval2=tempval1*2;
	valno=tempval1;

	for (inrepcount=1;inrepcount<=2;inrepcount++)
		{
		stepno=samstart+stepdiff;		// Band Pass - Band Cut
		tempval1=val1;
		if (tempval1<=0) tempval1=1;
		tempval1b=tempval1*0.166;
		if (tempval1b==0) tempval1b=1;
		tempval2=tempval1*2;
		tempval2b=tempval2*0.166;
		if (tempval2b==0) tempval2b=1;
		for (samcount=samstart;samcount<=samend;samcount++)
			{
			if (samcount==stepno)
				{
				tempval1=tempval1+chngno;
				if (tempval1<=0) tempval1=1;
				tempval1b=tempval1*0.166;
				if (tempval1b==0) tempval1b=1;
				tempval2=tempval1*2;
				tempval2b=tempval2*0.166;
				if (tempval2b==0) tempval2b=1;
				stepno=stepno+stepdiff;
				}

			temp=*(sampoint+samcount);
			origval=temp;

			if (samcount == samstart) tempb=0;
			else tempb=*(sampoint+samcount-1);
			if (samcount<=0) tempb=0;
			if ((samcount+tempval1)>=samend) tempc=0;
			else tempc=*(sampoint+samcount+tempval1);
			temp=tempc-tempb;
			temp=temp/tempval1b;
			temp=tempb+temp;

			if ((samcount+tempval1)>=samend) tempc=0;
			else tempc=*(sampoint+samcount+tempval2);
			tempd=tempc-tempb;
			tempd=tempd/tempval2b;
			tempd=tempb+tempd;

			highpassval=origval-temp;
			lowpassval=tempd;
			midpassval=highpassval+lowpassval;	// Notch Cut

			//	Notch Pass
			midpassval=origval-lowpassval;
			midpassval=midpassval-highpassval;
			midpassval=midpassval << 1;

			temp=midpassval;

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
		}	// inrepno
	}	// repno
}	// opt

if (opt==1)			// 2D Blur
{
val1=260-samslider1;	// may be a BUG!!!
if (addtyp==1) val1=val1 << 5;

if (addtypb==0) repno=0;
if (addtypb==1) repno=2;

for (repcount=0;repcount<=repno;repcount++)
	{
//	val1b=samstart+val1;
//	val1c=samend-val1;

	testa = samstart+val1+1;
	testb = samend-val1-1;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		if ((samcount > testa) && (samcount < testb))
			{
			tempa1=*(sampoint+samcount-val1-1);
			tempa2=*(sampoint+samcount-val1);
			tempa3=*(sampoint+samcount-val1+1);
			temp1=*(sampoint+samcount-1);
			temp2=*(sampoint+samcount);
			temp3=*(sampoint+samcount+1);
			tempb1=*(sampoint+samcount+val1-1);
			tempb2=*(sampoint+samcount+val1);
			tempb3=*(sampoint+samcount+val1+1);
			}
		else
			{
			tempa1=0;
			tempa2=0;
			tempa3=0;
			temp=0;
			temp=0;
			temp=0;
			tempb1=0;
			tempb2=0;
			tempb3=0;
			}

//		if (samcount<=val1b)
//			{
//			tempa1=0;
//			tempa2=0;
//			tempa3=0;
//			}
//		if (samcount>=val1c)
//			{
//			tempb1=0;
//			tempb2=0;
//			tempb3=0;
//			}

		temp=tempa1+tempa2+tempa3+temp1+temp2+temp3+tempb1+tempb2+tempb3;
		temp=temp/9;

		*(sampoint+samcount)=temp;
		if (samcount==memdivtodo)
			{
			done++;
			if (done>9) done=9; 
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}
}


if (opt==2)			// Random
{
if (addtyp==0) val1=val1 << 1;
if (addtyp==1) val1=val1 << 5;

incount=samstart+val1;
temp=rand();

for (samcount=samstart;samcount<=samend;samcount++)
	{
	*(sampoint+samcount)=temp;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	if (samcount==incount)
		{
		incount=incount+val1;
		temp=rand();
		}
	}
}


if (opt==3)			// Random Amplifier
{
if (addtyp==0) val1=val1 << 1;
if (addtyp==1) val1=val1 << 5;

incount=samstart+val1;
tempb=rand();
tempb=tempb >> 16;

for (samcount=samstart;samcount<=samend;samcount++)
	{
	temp=*(sampoint+samcount);
	temp=temp*tempb;
	temp=temp >> 15;
	*(sampoint+samcount)=temp;
	if (samcount==memdivtodo)
		{
		done++;
		Newdrawdonebox(3,5,100,75,done,drawbarside);
		memdivtodo=memdivtodo+memdiv;
		}
	if (samcount==incount)
		{
		incount=incount+val1;
		tempb=rand();
		tempb=tempb >> 16;
		}
	}
}


if (opt==4)		// Random Filter
{
lenval=samslider1; // read length
if (addtyp==0) lenval=lenval << 3;
if (addtyp==1) lenval=lenval << 7;

if (addtypb==0) repno=1;
if (addtypb==1) repno=2;

temp=rand();
temp=temp >> 26;
if (temp<0) temp=~temp;
temp=temp+20;

val1=temp;
val2=val1;
val3=1;
val4=256;

tempval1=val1;
valno=tempval1;

mixlev=samslider;
mixlevb=256-mixlev;

chngno=-1;
valdiff=1;
stepdiff=lenval;
repno=1;

for (repcount=1;repcount<=repno;repcount++)
	{
	stepno=samstart+stepdiff;
	tempval1=val1;
	if (tempval1<=0) tempval1=1;
	tempval2=tempval1 << 1;
	valno=tempval1;

	for (inrepcount=1;inrepcount<=2;inrepcount++)
		{
		stepno=samstart+stepdiff;		// Band Pass - Band Cut
		tempval1=val1;
		if (tempval1<=0) tempval1=1;
		tempval1b=tempval1;
		if (tempval1b==0) tempval1b=1;
		tempval2=tempval1 << 2;
		tempval2b=tempval2;
		if (tempval2b==0) tempval2b=1;
		for (samcount=samstart;samcount<=samend;samcount++)
			{
			if (samcount==stepno)
				{
				temp=rand();
				temp=temp >> 26;
				if (temp<0) temp=~temp;
				temp=temp+20;
				val1=temp;
				tempval1=val1;
				if (tempval1<=0) tempval1=1;
//				tempval1b=tempval1/val3;
				tempval1b=tempval1;
				if (tempval1b==0) tempval1b=1;
				stepno=stepno+stepdiff;
				}

			temp=*(sampoint+samcount);
			origval=temp;

			if (samcount<=0) tempb=0;
			if ((samcount+tempval1)>=samend) tempc=0;
			else tempc=*(sampoint+samcount+tempval1);
			temp=tempc-tempb;
			temp=temp/tempval1b;
			temp=tempb+temp;

			if ((samcount+tempval2)>=samend) tempc=0;
			else tempc=*(sampoint+samcount+tempval2);
			tempd=tempc-tempb;
			tempd=tempd/tempval2b;
			tempd=tempb+tempd;

			highpassval=origval-temp;
			lowpassval=tempd;
			midpassval=highpassval+lowpassval;	// Mid Pass
			midpassval=origval-lowpassval;
			midpassval=midpassval-highpassval;
			midpassval=midpassval << 1;

			temp=midpassval;

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
	}	// repno
}	// opt


if (opt==5)		// Rumble
{
for (samcount=samstart;samcount<=samend;samcount++)
	{
	temp=rand();
	*(sampoint+samcount)=temp;
	}

val1=316-samslider1;
val1=val1 >> 1;
val2=val1;
val4=256;

tempval1=val1;
valno=tempval1;

mixlev=samslider;
mixlevb=256-mixlev;

chngno=-1;
valdiff=1;
stepdiff=samlen/valdiff;
repno=2;

for (repcount=1;repcount<=repno;repcount++)
	{
	stepno=samstart+stepdiff;
	tempval1=val1;
	if (tempval1<=0) tempval1=1;
	valno=tempval1;

	for (inrepcount=1;inrepcount<=2;inrepcount++)
		{
		stepno=samstart+stepdiff;
		tempval1=val1;
		if (addtyp == 0) tempval1b=tempval1 * 0.166;
		else tempval1b=tempval1;
		if (tempval1b==0) tempval1b=1;
		for (samcount=samstart;samcount<=samend;samcount++)
			{
			if (samcount==stepno)
				{
				tempval1=tempval1+chngno;
				if (tempval1<=0) tempval1=1;
				if (addtyp == 0) tempval1b=tempval1 * 0.166;
				else tempval1b=tempval1;
				if (tempval1b==0) tempval1b=1;
				stepno=stepno+stepdiff;
				}

			temp=*(sampoint+samcount);
			origval=temp;
			if (samcount == samstart) tempb=0;
			else tempb=*(sampoint+samcount-1);
			if ((samcount+tempval1)>=samend) tempc=0;
			else tempc=*(sampoint+samcount+tempval1);
			temp=tempc-tempb;
			temp=temp/tempval1b;
			temp=tempb+temp;

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
	}	// repno
}	// opt

}

//-----------------------------------------------------------------
// Manips - Chaotic Operations

// 1-Chaos	2-Delta Delay 3-Swap Halves 4-Remove Middle 
// 5-Remove Flat 6 7 8 9 10

void	SAMPLEWindow::Chaosrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;

int32 phcount;
int32 phcountb;
int32 doneb;
int32 test;

int32 valtemp;
int32 mixlevb;
int32 origval;

int32 Incount=0;
int32 ref;
int32 samlenb;

double chaosval;
double chaosvalout;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;

int32 addtyp=samradio1;
int32 addtypb=samradio2;
int32 mixlev=samslider;
mixlevb=256-mixlev;

if (opt==1)	// Chaos
		{
		temp=val1;
		tempb=val2 << 8;
		tempc=val3 << 16;
		temp=temp+tempb+tempc;
		temp=temp+178000;

		chaosval=temp;
		chaosval=chaosval/17777216;

		for (samcount=samstart;samcount<=samend;samcount++)
			{
			temp=*(sampoint+samcount);
			origval=temp;
			chaosval=chaosval*chaosval;
			chaosval=chaosval*2;
			chaosval=chaosval-1;
			chaosvalout=chaosval*32766;
			temp=chaosvalout;
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

 if (opt==2)	// Delta Delay
	{
	phcount=val1+2;
	phcountb=phcount << 1;
	if (addtypb==1)
		{
		phcount=phcount << 6;
		phcountb=phcount << 1;
		}
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		tempb=*(sampoint+samcount+phcount);
		tempc=*(sampoint+samcount+phcountb);
		if ((samcount+phcount)>=samend)	tempb=0;
		if ((samcount+phcountb)>=samend) tempc=0;

		temp=tempb-temp;
		if (addtyp==1)					// UnDelta
			{
			tempb=*(sampoint+samcount+phcount);
			tempc=tempc-tempb;
			temp=tempc-temp;
			temp=temp >> 1;
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==3)	// Swap Halves
	{
	tempb=val1 << 7;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		if (addtyp==0)
			{
			if (temp>=1)
				{
				temp=temp-tempb;
				}
			else if (temp<=-1)
				{
				temp=temp+tempb;
				}
			}
		if (addtyp==1)
			{
			if (temp>=1)
				{
				temp=temp-tempb;
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
			if (addtypb==0) temp=origval+temp;
			if (addtypb==1) temp=origval-temp;
			}
		*(sampoint+samcount)=temp;
		if (samcount==memdivtodo)
			{
			done++;
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==4)	// Remove Centre
	{
	tempb=val1 << 6;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp==0)
			{
			if (temp>=1)
				{
				temp=temp-tempb;
				if (temp<=0) temp=0;
				}
			if (temp<=-1)
				{
				temp=temp+tempb;
				if (temp>=0) temp=0;
				}
			}
		if (addtyp==1)
			{
			if (temp>=1)
				{
				temp=temp-tempb;
				if (temp<=0) temp=0;
				}
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==5)	// Remove Flat
	{
	tempc=val1 << 3;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		tempb=*(sampoint+samcount+1);

		if (addtyp==0)
			{
			test=tempb-temp;
			if (test<0) test=~test;
			if (test<=tempc) temp=0;
			}

		if (addtyp==1)
			{
			if ((temp>=1) && (tempb>=1))
				{
				test=tempb-temp;
				if (test<0) test=~test;
				if (test<=tempc) temp=0;
				}
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==6)	// Transmogrify
	{
	tempc=val1 << 3;
		for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		tempb=*(sampoint+samcount+1);

		if (addtypb==0)
			{
			if (temp<0) temp=~temp;
			if (tempb<0) tempb=~tempb;
			test=tempb-temp;
			if (test<0) test=~test;
			if (addtyp==0) temp=temp-16384;
			if (test<=tempc) temp=0;
			if (addtyp==1) temp=temp-16384;
			}

		if (addtypb==1)
			{
			if (temp<0) temp=0;
			if (tempb<0) tempb=0;
			test=tempb-temp;
			if (test<0) test=~test;
			if (addtyp==0) temp=temp-16384;
			if (test<=tempc) temp=0;
			if (addtyp==1) temp=temp-16384;
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==7)	// Add Centre
	{
	tempb=val1 << 7;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp==0)
			{
			if (temp>=1)
				{
				temp=temp+tempb;
				if (addtypb==0) temp=temp >> 1; //	Effected samples only
				}
			if (temp<=-1)
				{
				temp=temp-tempb;
				if (addtypb==0) temp=temp >> 1;
				}
			}
		else	// Upper only
			{
			if (temp>=1)
				{
				temp=temp+tempb;
				if (addtypb==0) temp=temp >> 1;
				}
			}

		if (addtypb==1) temp=temp >> 1;	//	All Samples

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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}


}

//-----------------------------------------------------------------
// Manips - MoreChaotic Operations

//	7 8 9 10

void	SAMPLEWindow::Chaos2rng(int32 opt,int32 optb)
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

int32 testb;
int32 testc;
int32 testd;
int32 teste;
int32 testf;
int32 testg;
int32 testh;
int32 testi;
int32 testj;
int32 testk;
int32 testl;
int32 testm;
int32 testn;
int32 testo;
int32 testp;
int32 testq;

int32 phcount;
int32 phcountb;
int32 phcountc;
int32 phcountd;
int32 phcounte;
int32 phcountf;
int32 phcountg;
int32 phcounth;
int32 phcounti;

int32 doneb;
int32 test;

int32 valtemp;
int32 mixlevb;
int32 origval;

int32 Incount=0;
int32 ref;
int32 samlenb;

double chaosval;
double chaosvalout;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;

int32 addtyp=samradio1;
int32 addtypb=samradio2;
int32 mixlev=samslider;
mixlevb=256-mixlev;

 if (opt==7)	// Strange Delay
	{
	phcount=val1+1;
	if (addtypb==1)
		{
		phcount=phcount+256;
		}

		phcountb=phcount;				// 1
		phcountc=phcount << 1;		// 2
		phcountd=phcountc + phcount;	// 3
		phcounte=phcount << 2;		// 4
		phcountf=phcounte + phcount;	// 5
		phcountg=phcount * 6;			// 6
		phcounth=phcount * 7;			// 7
		phcounti=phcount << 3;		// 8

	testb = samend-phcountb;
	testc = samend-phcountc;
	testd = samend-phcountd;
	teste = samend-phcounte;
	testf = samend-phcountf;
	testg = samend-phcountg;
	testh = samend-phcounth;
	testi = samend-phcounti;
	
	testj = samstart+phcountb;
	testk = samstart+phcountc;
	testl = samstart+phcountd;
	testm = samstart+phcounte;
	testn = samstart+phcountf;
	testo = samstart+phcountg;
	testp = samstart+phcounth;
	testq = samstart+phcounti;

			for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount<testb)	tempb=*(sampoint+samcount+phcountb);
		else tempb=0;
		if (samcount<testc)	tempc=*(sampoint+samcount+phcountc);
		else tempc=0;
		if (samcount<testd)	tempd=*(sampoint+samcount+phcountd);
		else tempd=0;
		if (samcount<teste)	tempe=*(sampoint+samcount+phcounte);
		else tempe=0;
		if (samcount<testf)	tempf=*(sampoint+samcount+phcountf);
		else tempf=0;
		if (samcount<testg)	tempg=*(sampoint+samcount+phcountg);
		else tempg=0;
		if (samcount<testh)	temph=*(sampoint+samcount+phcounth);
		else temph=0;
		if (samcount<testi)	tempi=*(sampoint+samcount+phcounti);
		else tempi=0;
		if (samcount>testj) tempj=*(sampoint+samcount-phcountb);
		else tempj=0;
		if (samcount>testk) tempk=*(sampoint+samcount-phcountc);
		else tempk=0;
		if (samcount>testl) templ=*(sampoint+samcount-phcountd);
		else templ=0;
		if (samcount>testm) tempm=*(sampoint+samcount-phcounte);
		else tempm=0;
		if (samcount>testn) tempn=*(sampoint+samcount-phcountf);
		else tempn=0;
		if (samcount>testo) tempo=*(sampoint+samcount-phcountg);
		else tempo=0;
		if (samcount>testp) tempp=*(sampoint+samcount-phcounth);
		else tempp=0;
		if (samcount>testq) tempq=*(sampoint+samcount-phcounti);
		else tempq=0;
		
/*
		tempb=tempb * 256;
		tempc=tempc * 243;
		tempd=tempd * 230;
		tempe=tempe * 204;
		tempf=tempf * 179;
		tempg=tempg * 154;
		temph=temph * 102;
		tempi=tempi * 51;
		tempj=tempj * 256;
		tempk=tempk * 243;
		templ=templ * 230;
		tempm=tempm * 204;
		tempn=tempn * 179;
		tempo=tempo * 154;
		tempp=tempp * 102;
		tempq=tempq * 51;

		tempb=tempb >> 8;
		tempc=tempc >> 8;
		tempd=tempd >> 8;
		tempe=tempe >> 8;
		tempf=tempf >> 8;
		tempg=tempg >> 8;
		temph=temph >> 8;
		tempi=tempi >> 8;
		tempj=tempj >> 8;
		tempk=tempk >> 8;
		templ=templ >> 8;
		tempm=tempm >> 8;
		tempn=tempn >> 8;
		tempo=tempo >> 8;
		tempp=tempp >> 8;
		tempq=tempq >> 8;
*/

		if (addtyp==0)
			{
			temp=+tempb+tempc+tempd+tempe+tempf+tempg+temph+tempi
					+tempj+tempk+templ+tempm+tempn+tempo+tempp+tempq;
			temp=temp >> 4;
			}
		else
			{
			temp=-tempb+tempc-tempd+tempe-tempf+tempg-temph+tempi
					-tempj+tempk-templ+tempm-tempn+tempo-tempp+tempq;
			temp=temp >> 4;
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==8)	// Stranger Delay
	{
	phcount=val1+1;
	if (addtypb==1)
		{
		phcount=phcount+256;
		}

	phcountb=phcount;				// 1
	phcountc=phcount << 1;		// 2
	phcountd=phcountc + phcount;	// 3
	phcounte=phcount << 2;		// 4
	phcountf=phcounte + phcount;	// 5
	phcountg=phcount << 3;		// 6
	phcounth=phcountg+ phcount;	// 7
	phcounti=phcount << 4;		// 8

	testb = samend-phcountb;
	testc = samend-phcountc;
	testd = samend-phcountd;
	teste = samend-phcounte;
	testf = samend-phcountf;
	testg = samend-phcountg;
	testh = samend-phcounth;
	testi = samend-phcounti;
		
	testj = samstart+phcountb;
	testk = samstart+phcountc;
	testl = samstart+phcountd;
	testm = samstart+phcounte;
	testn = samstart+phcountf;
	testo = samstart+phcountg;
	testp = samstart+phcounth;
	testq = samstart+phcounti;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (samcount<testb)	tempb=*(sampoint+samcount+phcountb);
		else tempb=0;
		if (samcount<testc)	tempc=*(sampoint+samcount+phcountc);
		else tempc=0;
		if (samcount<testd)	tempd=*(sampoint+samcount+phcountd);
		else tempd=0;
		if (samcount<teste)	tempe=*(sampoint+samcount+phcounte);
		else tempe=0;
		if (samcount<testf)	tempf=*(sampoint+samcount+phcountf);
		else tempf=0;
		if (samcount<testg)	tempg=*(sampoint+samcount+phcountg);
		else tempg=0;
		if (samcount<testh)	temph=*(sampoint+samcount+phcounth);
		else temph=0;
		if (samcount<testi)	tempi=*(sampoint+samcount+phcounti);
		else tempi=0;
		if (samcount>testj) tempj=*(sampoint+samcount-phcountb);
		else tempj=0;
		if (samcount>testk) tempk=*(sampoint+samcount-phcountc);
		else tempk=0;
		if (samcount>testl) templ=*(sampoint+samcount-phcountd);
		else templ=0;
		if (samcount>testm) tempm=*(sampoint+samcount-phcounte);
		else tempm=0;
		if (samcount>testn) tempn=*(sampoint+samcount-phcountf);
		else tempn=0;
		if (samcount>testo) tempo=*(sampoint+samcount-phcountg);
		else tempo=0;
		if (samcount>testp) tempp=*(sampoint+samcount-phcounth);
		else tempp=0;
		if (samcount>testq) tempq=*(sampoint+samcount-phcounti);
		else tempq=0;

		if (addtyp==0)
			{
			temp=+tempb+tempc+tempd+tempe+tempf+tempg+temph+tempi
					+tempj+tempk+templ+tempm+tempn+tempo+tempp+tempq;
			temp=temp >> 4;
			}
		else
			{
			temp=-tempb+tempc-tempd+tempe-tempf+tempg-temph+tempi
					-tempj+tempk-templ+tempm-tempn+tempo-tempp+tempq;
			temp=temp >> 4;
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==9)	// Keep Flat
		{
		tempc=val1 << 3;
		for (samcount=samstart;samcount<=samend;samcount++)
			{
		temp=*(sampoint+samcount);
		origval=temp;
		tempb=*(sampoint+samcount+1);

		if (addtyp==0)
			{
			test=tempb-temp;
			if (test<0) test=~test;
			if (test>tempc) temp=0;
			}

		if (addtyp==1)
			{
			if ((temp>=1) && (tempb>=1))
				{
				test=tempb-temp;
				if (test<0) test=~test;
				if (test>tempc) temp=0;
				}
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==10)	// Non-Transmogrify?
	{
	tempc=val1 << 3;
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		tempb=*(sampoint+samcount+1);

		if (addtypb==0)
			{
			if (temp<0) temp=~temp;
			if (tempb<0) tempb=~tempb;
			test=tempb-temp;
			if (test<0) test=~test;
			if (addtyp==0) temp=temp-16384;
			if (test>tempc) temp=0;
			if (addtyp==1) temp=temp-16384;
			}

		if (addtypb==1)
			{
			if (temp<0) temp=0;
			if (tempb<0) tempb=0;
			test=tempb-temp;
			if (test<0) test=~test;
			if (addtyp==0) temp=temp-16384;
			if (test>tempc) temp=0;
			if (addtyp==1) temp=temp-16384;
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	Rescalenoboxrng();
	Drawdonebox(10);
	}

 if (opt==11)	// Remove Middle
		{
		if (addtyp==0)
			{
			tempc=val1 << 1;
			tempd=val1 << 2;
			tempc=tempd+tempc;
			tempc=tempc >> 1;
			tempc=tempc + 128;
			tempd=32767-tempc;
			}
		else
			{
			tempc=256-val1;
			tempc=tempc << 1;
			tempd=tempc << 2;
			tempc=tempd+tempc;
			tempc=tempc >> 1;
			tempc=tempc + 128;
			tempd=32767-tempc;
			}
			for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		tempb=*(sampoint+samcount+1);

		if (addtyp==0)	// Remove
			{
			if (addtypb==0)
				{
				test=tempb-temp;
				if (test<0) test=~test;
				if ((test>tempc) && (test<tempd)) temp=0;
				}
			else
				{
				if ((temp>=1) && (tempb>=1))
					{
					test=tempb-temp;
					if (test<0) test=~test;
					if ((test>tempc) && (test<tempd)) temp=0;
					}
				}
			}
		else					//	Keep
			{
			if (addtypb==0)
				{
				test=tempb-temp;
				if (test<0) test=~test;
				if ((test<tempc) || (test>tempd)) temp=0;
				}
			else
				{
				if ((temp>=1) && (tempb>=1))
					{
					test=tempb-temp;
					if (test<0) test=~test;
					if ((test<tempc) || (test>tempd)) temp=0;
					}
				}
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
			if (done>=9) done=9;
			Newdrawdonebox(3,5,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
		Rescalenoboxrng();
		Drawdonebox(10);
	}

}

//-----------------------------------------------------------------

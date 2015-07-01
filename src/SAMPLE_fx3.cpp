//		Aural illusion v4.0  Effects & Manipulations Part 3 

//		SAMPLE_fx3.cpp

//		copyright (c) Blachford Technology  15/5/97

#include "SAMPLEWindow.h"

////*************************************************************
// Functions

// Stereochorng			- Stereo Reverb SFX
// Rarrng				- Rectify and Add DMANIPs
// MixDistortrng		- Mix Distort FX
// DelayBackrng			- Delay and X MANIPs

////*************************************************************

///*************************************************************************************************
///*************************************************************************************************
///*************************************************************************************************

// Stereo Reverb

void  SAMPLEWindow::Strechorng(int32 opt,int32 optb)
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

int32 hsamcount;

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

int32 phcount2;
int32 phcountb2;
int32 phcountc2;
int32 phcountd2;
int32 phcounte2;
int32 phcountf2;
int32 phcountg2;
int32 phcounth2;

int32 phcounti2;
int32 phcountj2;
int32 phcountk2;
int32 phcountl2;
int32 phcountm2;
int32 phcountn2;
int32 phcounto2;
int32 phcountp2;

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

int32 startvalb2;
int32 startvalc2;
int32 startvald2;
int32 startvale2;
int32 startvalf2;
int32 startvalg2;
int32 startvalh2;

int32 startvali2;
int32 startvalj2;
int32 startvalk2;
int32 startvall2;
int32 startvalm2;
int32 startvaln2;
int32 startvalo2;
int32 startvalp2;

int32 predelay;
int32 predelay2;	// remove
int32 hsamstart;

int32 fsamstart  = samstart+memsize;
int32 fhsamstart = samstart+memsize+halfmemsize;
int32 fsamcount;
int32 fhsamcount;

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


 if (opt==1)  // Stereo Reverb
	{

predelay=val3 * 68;

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

	phcountb2=val1 * 64;
	phcountc2=val1 * 56;
	phcountd2=val1 * 41;
	phcounte2=val1 * 32;
	phcountf2=val1 * 28;
	phcountg2=val1 * 25;
	phcounth2=val1 * 23;

	phcounti2=val1 * 74;
	phcountj2=val1 * 71;
	phcountk2=val1 * 54;
	phcountl2=val1 * 50;
	phcountm2=val1 * 39;
	phcountn2=val1 * 26;
	phcounto2=val1 * 22;
	phcountp2=val1 * 17;
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

	phcountb2=val1 * 164;
	phcountc2=val1 * 126;
	phcountd2=val1 * 95;
	phcounte2=val1 * 64; 
	phcountf2=val1 * 47;
	phcountg2=val1 * 37;
	phcounth2=val1 * 13;

	phcounti2=val1 * 151;
	phcountj2=val1 * 139;
	phcountk2=val1 * 87;
	phcountl2=val1 * 74;
	phcountm2=val1 * 48;
	phcountn2=val1 * 43;
	phcounto2=val1 * 31;
	phcountp2=val1 * 25;
	}

	hsamstart=samstart+halfmemsize;

	phcountb=phcountb+predelay; // Left
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

	startvali=hsamstart+phcounti;
	startvalj=hsamstart+phcountj;
	startvalk=hsamstart+phcountk;
	startvall=hsamstart+phcountl;
	startvalm=hsamstart+phcountm;
	startvaln=hsamstart+phcountn;
	startvalo=hsamstart+phcounto;
	startvalp=hsamstart+phcountp;



	phcountb2=phcountb2+predelay;  // Right
	phcountc2=phcountc2+predelay;
	phcountd2=phcountd2+predelay;
	phcounte2=phcounte2+predelay;
	phcountf2=phcountf2+predelay;
	phcountg2=phcountg2+predelay;
	phcounth2=phcounth2+predelay;

	phcounti2=phcounti2+predelay;
	phcountj2=phcountj2+predelay;
	phcountk2=phcountk2+predelay;
	phcountl2=phcountl2+predelay;
	phcountm2=phcountm2+predelay;
	phcountn2=phcountn2+predelay;
	phcounto2=phcounto2+predelay;
	phcountp2=phcountp2+predelay;


	startvalb2=hsamstart+phcountb2;
	startvalc2=hsamstart+phcountc2;
	startvald2=hsamstart+phcountd2;
	startvale2=hsamstart+phcounte2;
	startvalf2=hsamstart+phcountf2;
	startvalg2=hsamstart+phcountg2;
	startvalh2=hsamstart+phcounth2;

	startvali2=samstart+phcounti2;
	startvalj2=samstart+phcountj2;
	startvalk2=samstart+phcountk2;
	startvall2=samstart+phcountl2;
	startvalm2=samstart+phcountm2;
	startvaln2=samstart+phcountn2;
	startvalo2=samstart+phcounto2;
	startvalp2=samstart+phcountp2;


		 
	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);	  // Left
		origval=temp;
		hsamcount=samcount+halfmemsize;

		if (samcount < startvalb) tempb = 0;
		else tempb=*(sampoint+samcount-phcountb);
		if (samcount < startvalc) tempc = 0;
		else tempc=*(sampoint+samcount-phcountc);
		if (samcount < startvald) tempd = 0;
		else tempd=*(sampoint+samcount-phcountd);
		if (samcount < startvale) tempe = 0;
		else tempe=*(sampoint+samcount-phcounte);
		if (samcount < startvalf) tempf = 0;
		else tempf=*(sampoint+samcount-phcountf);
		if (samcount < startvalg) tempg = 0;
		else tempg=*(sampoint+samcount-phcountg);
		if (samcount < startvalh) temph = 0;
		else temph=*(sampoint+samcount-phcounth);

		if (hsamcount < startvali) tempi = 0;
		else tempi=*(sampoint+hsamcount-phcounti);
		if (hsamcount < startvalj) tempj = 0;
		else tempj=*(sampoint+hsamcount-phcountj);
		if (hsamcount < startvalk) tempk = 0;
		else tempk=*(sampoint+hsamcount-phcountk);
		if (hsamcount < startvall) templ = 0;
		else templ=*(sampoint+hsamcount-phcountl);
		if (hsamcount < startvalm) tempm = 0;
		else tempm=*(sampoint+hsamcount-phcountm);
		if (hsamcount < startvaln) tempn = 0;
		else tempn=*(sampoint+hsamcount-phcountn);
		if (hsamcount < startvalo) tempo = 0;
		else tempo=*(sampoint+hsamcount-phcounto);
		if (hsamcount < startvalp) tempp = 0;
		else tempp=*(sampoint+hsamcount-phcountp);
	
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph
		+tempi+tempj+tempk+templ+tempm+tempn+tempo+tempp;

		tempb=tempb*val2;
		tempb=tempb >> 11;

		temp=temp+tempb;
		temp = temp >> 1;

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

		temp=*(sampoint+samcount+halfmemsize);  //  Right
		origval=temp;

		if (hsamcount < startvalb2) tempb = 0;
		else tempb=*(sampoint+hsamcount-phcountb2);
		if (hsamcount < startvalc2) tempc = 0;
		else tempc=*(sampoint+hsamcount-phcountc2);
		if (hsamcount < startvald2) tempd = 0;
		else tempd=*(sampoint+hsamcount-phcountd2);
		if (hsamcount < startvale2) tempe = 0;
		else tempe=*(sampoint+hsamcount-phcounte2);
		if (hsamcount < startvalf2) tempf = 0;
		else tempf=*(sampoint+hsamcount-phcountf2);
		if (hsamcount < startvalg2) tempg = 0;
		else tempg=*(sampoint+hsamcount-phcountg2);
		if (hsamcount < startvalh2) temph = 0;
		else temph=*(sampoint+hsamcount-phcounth2);

		if (samcount < startvali2) tempi = 0;
		else tempi=*(sampoint+samcount-phcounti2);
		if (samcount < startvalj2) tempj = 0;
		else tempj=*(sampoint+samcount-phcountj2);
		if (samcount < startvalk2) tempk = 0;
		else tempk=*(sampoint+samcount-phcountk2);
		if (samcount < startvall2) templ = 0;
		else templ=*(sampoint+samcount-phcountl2);
		if (samcount < startvalm2) tempm = 0;
		else tempm=*(sampoint+samcount-phcountm2);
		if (samcount < startvaln2) tempn = 0;
		else tempn=*(sampoint+samcount-phcountn2);
		if (samcount < startvalo2) tempo = 0;
		else tempo=*(sampoint+samcount-phcounto2);
		if (samcount < startvalp2) tempp = 0;
		else tempp=*(sampoint+samcount-phcountp2);
	
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph
		+tempi+tempj+tempk+templ+tempm+tempn+tempo+tempp;

		tempb=tempb*val2;
		tempb=tempb >> 11;

		temp=temp+tempb;
		temp = temp >> 1;

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
		*(sampoint+samcount+halfmemsize)=temp;

		if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	if (makechans!=2) done=done+4;
	if (makechans==2) done=done+2;
	if (makechans!=2) done=done+2;
	if (makechans==2) done++;
	}

// -------------------------------------------------------------------------------------

 if (opt==2)  // Stereo Reverb? Only
	{

predelay=val3 * 68;

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

	phcountb2=val1 * 64;
	phcountc2=val1 * 56;
	phcountd2=val1 * 41;
	phcounte2=val1 * 32;
	phcountf2=val1 * 28;
	phcountg2=val1 * 25;
	phcounth2=val1 * 23;

	phcounti2=val1 * 74;
	phcountj2=val1 * 71;
	phcountk2=val1 * 54;
	phcountl2=val1 * 50;
	phcountm2=val1 * 39;
	phcountn2=val1 * 26;
	phcounto2=val1 * 22;
	phcountp2=val1 * 17;
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

	phcountb2=val1 * 164;
	phcountc2=val1 * 126;
	phcountd2=val1 * 95;
	phcounte2=val1 * 64; 
	phcountf2=val1 * 47;
	phcountg2=val1 * 37;
	phcounth2=val1 * 13;

	phcounti2=val1 * 151;
	phcountj2=val1 * 139;
	phcountk2=val1 * 87;
	phcountl2=val1 * 74;
	phcountm2=val1 * 48;
	phcountn2=val1 * 43;
	phcounto2=val1 * 31;
	phcountp2=val1 * 25;
	}

	hsamstart=samstart+halfmemsize;

	phcountb=phcountb+predelay; // Left
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


	startvalb=fsamstart+phcountb;
	startvalc=fsamstart+phcountc;
	startvald=fsamstart+phcountd;
	startvale=fsamstart+phcounte;
	startvalf=fsamstart+phcountf;
	startvalg=fsamstart+phcountg;
	startvalh=fsamstart+phcounth;

	startvali=fhsamstart+phcounti;
	startvalj=fhsamstart+phcountj;
	startvalk=fhsamstart+phcountk;
	startvall=fhsamstart+phcountl;
	startvalm=fhsamstart+phcountm;
	startvaln=fhsamstart+phcountn;
	startvalo=fhsamstart+phcounto;
	startvalp=fhsamstart+phcountp;



	phcountb2=phcountb2+predelay;  // Right
	phcountc2=phcountc2+predelay;
	phcountd2=phcountd2+predelay;
	phcounte2=phcounte2+predelay;
	phcountf2=phcountf2+predelay;
	phcountg2=phcountg2+predelay;
	phcounth2=phcounth2+predelay;

	phcounti2=phcounti2+predelay;
	phcountj2=phcountj2+predelay;
	phcountk2=phcountk2+predelay;
	phcountl2=phcountl2+predelay;
	phcountm2=phcountm2+predelay;
	phcountn2=phcountn2+predelay;
	phcounto2=phcounto2+predelay;
	phcountp2=phcountp2+predelay;


	startvalb2=fhsamstart+phcountb2;
	startvalc2=fhsamstart+phcountc2;
	startvald2=fhsamstart+phcountd2;
	startvale2=fhsamstart+phcounte2;
	startvalf2=fhsamstart+phcountf2;
	startvalg2=fhsamstart+phcountg2;
	startvalh2=fhsamstart+phcounth2;

	startvali2=fsamstart+phcounti2;
	startvalj2=fsamstart+phcountj2;
	startvalk2=fsamstart+phcountk2;
	startvall2=fsamstart+phcountl2;
	startvalm2=fsamstart+phcountm2;
	startvaln2=fsamstart+phcountn2;
	startvalo2=fsamstart+phcounto2;
	startvalp2=fsamstart+phcountp2;


		 
	for (samcount=samstart;samcount<=samend;samcount++)
		{
//		temp=*(sampoint+samcount);	  // Left
//		origval=temp;
		hsamcount=samcount+halfmemsize;
		fsamcount=samcount+memsize;
		fhsamcount=samcount+memsize+halfmemsize;

		if (fsamcount < startvalb) tempb = 0;
		else tempb=*(sampoint+fsamcount-phcountb);
		if (fsamcount < startvalc) tempc = 0;
		else tempc=*(sampoint+fsamcount-phcountc);
		if (fsamcount < startvald) tempd = 0;
		else tempd=*(sampoint+fsamcount-phcountd);
		if (fsamcount < startvale) tempe = 0;
		else tempe=*(sampoint+fsamcount-phcounte);
		if (fsamcount < startvalf) tempf = 0;
		else tempf=*(sampoint+fsamcount-phcountf);
		if (fsamcount < startvalg) tempg = 0;
		else tempg=*(sampoint+fsamcount-phcountg);
		if (fsamcount < startvalh) temph = 0;
		else temph=*(sampoint+fsamcount-phcounth);

		if (fhsamcount < startvali) tempi = 0;
		else tempi=*(sampoint+fhsamcount-phcounti);
		if (fhsamcount < startvalj) tempj = 0;
		else tempj=*(sampoint+fhsamcount-phcountj);
		if (fhsamcount < startvalk) tempk = 0;
		else tempk=*(sampoint+fhsamcount-phcountk);
		if (fhsamcount < startvall) templ = 0;
		else templ=*(sampoint+fhsamcount-phcountl);
		if (fhsamcount < startvalm) tempm = 0;
		else tempm=*(sampoint+fhsamcount-phcountm);
		if (fhsamcount < startvaln) tempn = 0;
		else tempn=*(sampoint+fhsamcount-phcountn);
		if (fhsamcount < startvalo) tempo = 0;
		else tempo=*(sampoint+fhsamcount-phcounto);
		if (fhsamcount < startvalp) tempp = 0;
		else tempp=*(sampoint+fhsamcount-phcountp);
	
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph
		+tempi+tempj+tempk+templ+tempm+tempn+tempo+tempp;

		tempb=tempb*val2;
		temp=tempb >> 12;

//		temp=temp+tempb;
//		temp = temp >> 1;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

/*		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			temp=origval+temp;
			}*/
		*(sampoint+samcount)=temp;

//		temp=*(sampoint+samcount+halfmemsize);  //  Right
//		origval=temp;

		if (fhsamcount < startvalb2) tempb = 0;
		else tempb=*(sampoint+fhsamcount-phcountb2);
		if (fhsamcount < startvalc2) tempc = 0;
		else tempc=*(sampoint+fhsamcount-phcountc2);
		if (fhsamcount < startvald2) tempd = 0;
		else tempd=*(sampoint+fhsamcount-phcountd2);
		if (fhsamcount < startvale2) tempe = 0;
		else tempe=*(sampoint+fhsamcount-phcounte2);
		if (fhsamcount < startvalf2) tempf = 0;
		else tempf=*(sampoint+fhsamcount-phcountf2);
		if (fhsamcount < startvalg2) tempg = 0;
		else tempg=*(sampoint+fhsamcount-phcountg2);
		if (fhsamcount < startvalh2) temph = 0;
		else temph=*(sampoint+fhsamcount-phcounth2);

		if (fsamcount < startvali2) tempi = 0;
		else tempi=*(sampoint+fsamcount-phcounti2);
		if (fsamcount < startvalj2) tempj = 0;
		else tempj=*(sampoint+fsamcount-phcountj2);
		if (fsamcount < startvalk2) tempk = 0;
		else tempk=*(sampoint+fsamcount-phcountk2);
		if (fsamcount < startvall2) templ = 0;
		else templ=*(sampoint+fsamcount-phcountl2);
		if (fsamcount < startvalm2) tempm = 0;
		else tempm=*(sampoint+fsamcount-phcountm2);
		if (fsamcount < startvaln2) tempn = 0;
		else tempn=*(sampoint+fsamcount-phcountn2);
		if (fsamcount < startvalo2) tempo = 0;
		else tempo=*(sampoint+fsamcount-phcounto2);
		if (fsamcount < startvalp2) tempp = 0;
		else tempp=*(sampoint+fsamcount-phcountp2);
	
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph
		+tempi+tempj+tempk+templ+tempm+tempn+tempo+tempp;

		tempb=tempb*val2;
		temp=tempb >> 12;

//		temp=temp+tempb;
//		temp = temp >> 1;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

/*		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			temp=origval+temp;
			}*/
		*(sampoint+samcount+halfmemsize)=temp;

		if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	if (makechans!=2) done=done+4;
	if (makechans==2) done=done+2;
	if (makechans!=2) done=done+2;
	if (makechans==2) done++;
	}

// -------------------------------------------------------------------------------------

 if (opt==3)  // Reverb Only
	{

predelay=val3 * 68;

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

	phcountb2=val1 * 64;
	phcountc2=val1 * 56;
	phcountd2=val1 * 41;
	phcounte2=val1 * 32;
	phcountf2=val1 * 28;
	phcountg2=val1 * 25;
	phcounth2=val1 * 23;

	phcounti2=val1 * 74;
	phcountj2=val1 * 71;
	phcountk2=val1 * 54;
	phcountl2=val1 * 50;
	phcountm2=val1 * 39;
	phcountn2=val1 * 26;
	phcounto2=val1 * 22;
	phcountp2=val1 * 17;
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

	phcountb2=val1 * 164;
	phcountc2=val1 * 126;
	phcountd2=val1 * 95;
	phcounte2=val1 * 64; 
	phcountf2=val1 * 47;
	phcountg2=val1 * 37;
	phcounth2=val1 * 13;

	phcounti2=val1 * 151;
	phcountj2=val1 * 139;
	phcountk2=val1 * 87;
	phcountl2=val1 * 74;
	phcountm2=val1 * 48;
	phcountn2=val1 * 43;
	phcounto2=val1 * 31;
	phcountp2=val1 * 25;
	}

	hsamstart=samstart+halfmemsize;

	phcountb=phcountb+predelay; // Left
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


	startvalb=fsamstart+phcountb;
	startvalc=fsamstart+phcountc;
	startvald=fsamstart+phcountd;
	startvale=fsamstart+phcounte;
	startvalf=fsamstart+phcountf;
	startvalg=fsamstart+phcountg;
	startvalh=fsamstart+phcounth;

	startvali=samstart+phcounti;
	startvalj=samstart+phcountj;
	startvalk=samstart+phcountk;
	startvall=samstart+phcountl;
	startvalm=samstart+phcountm;
	startvaln=samstart+phcountn;
	startvalo=samstart+phcounto;
	startvalp=samstart+phcountp;



	phcountb2=phcountb2+predelay;  // Right
	phcountc2=phcountc2+predelay;
	phcountd2=phcountd2+predelay;
	phcounte2=phcounte2+predelay;
	phcountf2=phcountf2+predelay;
	phcountg2=phcountg2+predelay;
	phcounth2=phcounth2+predelay;

	phcounti2=phcounti2+predelay;
	phcountj2=phcountj2+predelay;
	phcountk2=phcountk2+predelay;
	phcountl2=phcountl2+predelay;
	phcountm2=phcountm2+predelay;
	phcountn2=phcountn2+predelay;
	phcounto2=phcounto2+predelay;
	phcountp2=phcountp2+predelay;


	startvalb2=samstart+phcountb2;
	startvalc2=samstart+phcountc2;
	startvald2=samstart+phcountd2;
	startvale2=samstart+phcounte2;
	startvalf2=samstart+phcountf2;
	startvalg2=samstart+phcountg2;
	startvalh2=samstart+phcounth2;

	startvali2=fsamstart+phcounti2;
	startvalj2=fsamstart+phcountj2;
	startvalk2=fsamstart+phcountk2;
	startvall2=fsamstart+phcountl2;
	startvalm2=fsamstart+phcountm2;
	startvaln2=fsamstart+phcountn2;
	startvalo2=fsamstart+phcounto2;
	startvalp2=fsamstart+phcountp2;


		 
	for (samcount=samstart;samcount<=samend;samcount++)
		{
//		temp=*(sampoint+samcount);	  // Left
//		origval=temp;
		hsamcount=samcount+halfmemsize;
		fsamcount=samcount+memsize;
		fhsamcount=samcount+memsize+halfmemsize;

		if (fsamcount < startvalb) tempb = 0;
		else tempb=*(sampoint+fsamcount-phcountb);
		if (fsamcount < startvalc) tempc = 0;
		else tempc=*(sampoint+fsamcount-phcountc);
		if (fsamcount < startvald) tempd = 0;
		else tempd=*(sampoint+fsamcount-phcountd);
		if (fsamcount < startvale) tempe = 0;
		else tempe=*(sampoint+fsamcount-phcounte);
		if (fsamcount < startvalf) tempf = 0;
		else tempf=*(sampoint+fsamcount-phcountf);
		if (fsamcount < startvalg) tempg = 0;
		else tempg=*(sampoint+fsamcount-phcountg);
		if (fsamcount < startvalh) temph = 0;
		else temph=*(sampoint+fsamcount-phcounth);

		if (samcount < startvali) tempi = 0;
		else tempi=*(sampoint+samcount-phcounti);
		if (samcount < startvalj) tempj = 0;
		else tempj=*(sampoint+samcount-phcountj);
		if (samcount < startvalk) tempk = 0;
		else tempk=*(sampoint+samcount-phcountk);
		if (samcount < startvall) templ = 0;
		else templ=*(sampoint+samcount-phcountl);
		if (samcount < startvalm) tempm = 0;
		else tempm=*(sampoint+samcount-phcountm);
		if (samcount < startvaln) tempn = 0;
		else tempn=*(sampoint+samcount-phcountn);
		if (samcount < startvalo) tempo = 0;
		else tempo=*(sampoint+samcount-phcounto);
		if (samcount < startvalp) tempp = 0;
		else tempp=*(sampoint+samcount-phcountp);
	
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph
		+tempi+tempj+tempk+templ+tempm+tempn+tempo+tempp;

		tempb=tempb*val2;
		temp=tempb >> 12;

//		temp=temp+tempb;
//		temp = temp >> 1;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

/*		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			temp=origval+temp;
			}*/
		*(sampoint+samcount)=temp;

//		temp=*(sampoint+samcount+halfmemsize);  //  Right
//		origval=temp;

		if (fsamcount < startvalb2) tempb = 0;
		else tempb=*(sampoint+fsamcount-phcountb2);
		if (fsamcount < startvalc2) tempc = 0;
		else tempc=*(sampoint+fsamcount-phcountc2);
		if (fsamcount < startvald2) tempd = 0;
		else tempd=*(sampoint+fsamcount-phcountd2);
		if (fsamcount < startvale2) tempe = 0;
		else tempe=*(sampoint+fsamcount-phcounte2);
		if (fsamcount < startvalf2) tempf = 0;
		else tempf=*(sampoint+fsamcount-phcountf2);
		if (fsamcount < startvalg2) tempg = 0;
		else tempg=*(sampoint+fsamcount-phcountg2);
		if (fsamcount < startvalh2) temph = 0;
		else temph=*(sampoint+fsamcount-phcounth2);

		if (samcount < startvali2) tempi = 0;
		else tempi=*(sampoint+samcount-phcounti2);
		if (samcount < startvalj2) tempj = 0;
		else tempj=*(sampoint+samcount-phcountj2);
		if (samcount < startvalk2) tempk = 0;
		else tempk=*(sampoint+samcount-phcountk2);
		if (samcount < startvall2) templ = 0;
		else templ=*(sampoint+samcount-phcountl2);
		if (samcount < startvalm2) tempm = 0;
		else tempm=*(sampoint+samcount-phcountm2);
		if (samcount < startvaln2) tempn = 0;
		else tempn=*(sampoint+samcount-phcountn2);
		if (samcount < startvalo2) tempo = 0;
		else tempo=*(sampoint+samcount-phcounto2);
		if (samcount < startvalp2) tempp = 0;
		else tempp=*(sampoint+samcount-phcountp2);
	
		tempb=tempb+tempc+tempd+tempe+tempf+tempg+temph
		+tempi+tempj+tempk+templ+tempm+tempn+tempo+tempp;

		tempb=tempb*val2;
		temp=tempb >> 12;

//		temp=temp+tempb;
//		temp = temp >> 1;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;

/*		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			temp=origval+temp;
			}*/
		*(sampoint+samcount+halfmemsize)=temp;

		if (samcount==memdivtodo)
			{
			done++;
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			memdivtodo=memdivtodo+memdiv;
			}
		}
	if (makechans!=2) done=done+4;
	if (makechans==2) done=done+2;
	if (makechans!=2) done=done+2;
	if (makechans==2) done++;
	}

// -------------------------------------------------------------------------------------


}


///*************************************************************************************************
///*************************************************************************************************
///*************************************************************************************************

void  SAMPLEWindow::Radrng(int32 opt,int32 optb)
{
int32 incount;
int32 maxb;
int32 tempa;
int32 tempb;
int32 origval;
int32 addtyp;
int32 addtypb;
int32 mixlev;
int32 mixlevb;
int32 mula;
int32 mulb;

mula=samslider1;
mulb=samslider2;
addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if ((opt==1) || (opt==2)) // Full Rectify and Add - Half Rectify and Add
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

	  if (opt==1)  // Full Rectify and Add
			{
			if (addtyp == 0)  //  +ve 
			  {
			  if (addtypb == 0)  //  A->B
				  {
				  if ((tempa>0) && (tempb<0)) tempb=~tempb;
				  else if ((tempa<0) && (tempb>0)) tempb=~tempb;
				  tempa=tempa+tempb;
				  }
			  else					//  B->A
				  {
				  if ((tempa>0) && (tempb<0)) tempa=~tempa;
				  else if ((tempa<0) && (tempb>0)) tempa=~tempa;
				  tempa=tempa+tempb;
				  }
			  }
			else  // addtyp == 1  -ve
			  {
				if (addtypb == 0)
				  {
				  if ((tempa>0) && (tempb<0)) tempb=~tempb;
				  else if ((tempa<0) && (tempb>0)) tempb=~tempb;
				  tempa=tempa-tempb;
				  }
				else
				  {
				  if ((tempa>0) && (tempb<0)) tempa=~tempa;
				  else if ((tempa<0) && (tempb>0)) tempa=~tempa;
				  tempa=tempa-tempb;
				  }
			  }
			tempa=tempa >> 1;
			}

	  if (opt==2)  // Half Rectify and Add
			{
			if (addtyp == 0)  //  +ve 
			  {
			  if (addtypb == 0)  //  A->B
				  {
				  if ((tempa>0) && (tempb<0)) tempb=0;
				  if ((tempa<0) && (tempb>0)) tempb=~tempb;
				  tempa=tempa+tempb;
				  }
			  else					//  B->A
				  {
				  if ((tempa>0) && (tempb<0)) tempa=0;
				  if ((tempa<0) && (tempb>0)) tempa=~tempa;
				  tempa=tempa+tempb;
				  }
			  }
			else  // addtyp == 1  -ve
			  {
				if (addtypb == 0)
				  {
				  if ((tempa>0) && (tempb<0)) tempb=0;
				  if ((tempa<0) && (tempb>0)) tempb=~tempb;
				  tempa=tempa-tempb;
				  }
				else
				  {
				  if ((tempa>0) && (tempb<0)) tempa=0;
				  if ((tempa<0) && (tempb>0)) tempa=~tempa;
				  tempa=tempa-tempb;
				  }
			  }
			tempa=tempa >> 2;
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
	  if (tempa>=32766) tempa=32766;
	  if (tempa<=-32766) tempa=-32766;
	  *(sampoint+samcount)=tempa;
	  if (samcount==memdivtodo)
		  {
		  done++;
		  Newdrawdonebox(3,0,100,75,done,drawbarside);
		  memdivtodo=memdivtodo+memdiv;
		  }
	  }

  }
}

///*************************************************************************************************
///*************************************************************************************************
///*************************************************************************************************
// Mix Distort and other Effect

// Mix Distort 

void  SAMPLEWindow::MixDistortrng(int32 opt,int32 optb)
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

int32 reps;
int32 repcount;

int16 wordval;

int32 val1=samslider1;
int32 val2=samslider2;

addtyp=samradio1;
addtypb=samradio2;
mixlev=samslider;
mixlevb=256-mixlev;

if (opt==1)	// (Mix) Distortion
	{
	val1=val1+1;

	for (samcount=samstart;samcount<=samend;samcount++)
	  {
	  temp=*(sampoint+samcount);
	  origval=temp;

		 if (addtypb==1)
			{
			reps=2;
			}
		 else  // addtyp==0
			{
			reps=0;
			}

		 for (repcount=0;repcount<=reps;repcount++)
			{
			origval=temp;
			tempb=temp*val1;

  //		 if (addtypb==0)
  //			{	 
			  tempb=tempb>>6;
			  tempb=tempb+temp;
  //			}

			if (tempb>=32766) tempb=32766;
			if (tempb<=-32766) tempb=-32766;

			muld=origval;
			if (temp<0) muld=~muld;
			mulo=32768-muld;

			tempo=temp*mulo;
			tempo=tempo >> 15;

			tempd=tempb*muld;
			tempd=tempd >> 15;

			if (addtyp==0) temp=tempo+tempd;
			if (addtyp==1) temp=tempd-tempo;  

 //		temp = temp >> 1;
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
		  Newdrawdonebox(3,0,100,75,done,drawbarside);
		  memdivtodo=memdivtodo+memdiv;
		  }
	  }
	}

//-----------------------------------------------------------------------

if (opt==2)	// Mix Contortion
	{
val1=val1+1;

	for (samcount=samstart;samcount<=samend;samcount++)
	  {
	  temp=*(sampoint+samcount);
	  origval=temp;

		 if (addtypb==1)
			{
			reps=2;
			}
		 else  // addtyp==0
			{
			reps=0;
			}

		 for (repcount=0;repcount<=reps;repcount++)
			{
			val1=val1+1;
			val1=val1 << 2;
			origval=temp;
			tempb=temp*val1;

			if (addtypb==0)
			  {
			  tempb=tempb>>6;
			  tempb=tempb+temp;
			  }  

			if (tempb>=32766) tempb=32766;
			if (tempb<=-32766) tempb=-32766;

			muld=origval;
			if (temp<0) muld=~muld;
			mulo=32768-muld;

			tempo=temp*mulo;
			tempo=tempo >> 15;

			tempd=tempb*muld;
			tempd=tempd >> 15;

			if (addtyp==0) temp=tempo+tempd;
			if (addtyp==1) temp=tempd-tempo;  

 //		temp = temp >> 1;
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
		  Newdrawdonebox(3,0,100,75,done,drawbarside);
		  memdivtodo=memdivtodo+memdiv;
		  }
	  }
	}

//-----------------------------------------------------------------------

if (opt==3)
	{
val1=val1+1;

	for (samcount=samstart;samcount<=samend;samcount++)
	  {
	  temp=*(sampoint+samcount);
	  origval=temp;

	  if (opt==3)	// Half Distort (Mix)
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
		  Newdrawdonebox(3,0,100,75,done,drawbarside);
		  memdivtodo=memdivtodo+memdiv;
		  }
	  }
	}

//-----------------------------------------------------------------------

if (opt==4)	// Half Contort (Mix)
	{
val1=val1+1;

	for (samcount=samstart;samcount<=samend;samcount++)
	  {
	  temp=*(sampoint+samcount);
	  origval=temp;

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
		  Newdrawdonebox(3,0,100,75,done,drawbarside);
		  memdivtodo=memdivtodo+memdiv;
		  }
	  }
	}
}

///*************************************************************************************************
///*************************************************************************************************
///*************************************************************************************************
// Manips - Delay Operations

//	0	Fliter Delta Delay

void  SAMPLEWindow::DelayBackrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;

uint32 phcount;
uint32 phcountb;
int32 doneb;
int32 test;

int32 valtemp;
int32 mixlevb;
int32 origval;

int32 Incount=0;
int32 ref;
int32 samlenb;
int32 shortcount;

uint32 locheckcount;
uint32 hicheckcount;

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

//-----------------------------------------------------------------------

 if (opt==0)  // Filter Delay Delta
  	{
  	phcount=val1+2;
  	phcountb=phcount << 1;

  	if (addtyp==1)	// long
  	  {
  	  phcount=phcount << 6;
  	  phcountb=phcount << 1;
  	  }

//if (addtypb==0)
//	{
//	locheckcount = samend-phcount;
//	hicheckcount = samend-phcountb;
//	}
//else // addtyp==1
//	{
	locheckcount = samstart+phcount;
	hicheckcount = samstart+phcountb;
//	}

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

//		if (addtyp == 0)
//			{
//			tempb=*(sampoint+samcount+phcount);
//			tempc=*(sampoint+samcount+phcountb);
//			if ((samcount+phcount)>=samend)  tempb=0;
//			if ((samcount+phcountb)>=samend) tempc=0;
//			if (samcount >= locheckcount) tempb=0;
//			else tempb=*(sampoint+samcount+phcount);
//			if (samcount >= hicheckcount) tempc=0;
//			else tempc=*(sampoint+samcount+phcountb);

//			temp=tempb-temp;
//			if (addtypb==1)		 			 // UnDelta 
//			 	{
//		 		tempb=*(sampoint+samcount+phcount);
//			 	tempc=tempc-tempb;
//			 	temp=tempc-temp;
//			 	temp=temp >> 1;
//		 		}
//		 	}

//		if (addtyp == 1)
//			{
//			tempb=*(sampoint+samcount+phcount);
//			tempc=*(sampoint+samcount+phcountb);
//			if ((samcount+phcount)>=samend)  tempb=0;
//			if ((samcount+phcountb)>=samend) tempc=0;
			if (samcount >= locheckcount) tempb=*(sampoint+samcount-phcount);
			else tempb=0;
			if (samcount >= hicheckcount) tempc=*(sampoint+samcount-phcountb);
			else tempc=0;

			temp=tempb-temp;
			if (addtypb==1)		 			 // Double
			 	{
			 	tempc=tempc-tempb;
			 	temp=tempc-temp;
			 	temp=temp >> 1;
		 		}
//		 	}

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==1)  // Delay Delta
  	{
  	phcount=val1+2;
  	phcountb=phcount << 1;
	locheckcount = samend-phcount;
	hicheckcount = samend-phcountb;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		if (samcount >= locheckcount) tempb=0;
		else tempb=*(sampoint+samcount+phcount);
		if (samcount >= hicheckcount) tempc=0;
		else tempc=*(sampoint+samcount+phcountb);
		tempb = tempb * val2;
		if (tempb == 0) tempb = 256;
		tempb = tempb >> 8;
		tempc = tempc * val3;
		if (tempc == 0) tempc = 256;
		tempc = tempc >> 8;
		if (addtypb == 0)	// Add
			{
			temp=tempb+temp;
			if (addtyp==1)		// Double
			 	{
			 	tempc=tempc+tempb;
			 	temp=tempc+temp;
		 		temp=temp >> 1;
			 	}
			temp=temp >> 1;
			}
		if (addtypb == 1)	// Subtract
			{
			temp=tempb-temp;
			if (addtyp==1)		// Double
			 	{
			 	tempc=tempc-tempb;
			 	temp=tempc-temp;
		 		temp=temp >> 1;
			 	}
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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------
/*
if (opt==2)	//	Delay Sin
	{
	int32 count;
	float dtemp;

	phcount=val1+2;
	phcount=phcount << 2;	// Long

	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}
/*
 if (opt==2) 
  	{

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}*/



 if (opt==2)  // Delay Backwards Subtract
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}
		
		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;
		temp=tempb-temp;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==3)  // Delay Multiply
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}

		if (temp == 0) temp = 1;
		if (tempb == 0) tempb = 1;

		temp=temp*val2;
		temp=temp >> 8;
		if (addtyp == 1)	temp=temp >> 2;	// MAX 64
		if (addtyp == 0)	// if filter selected ignore val3
			{
			tempb=tempb*val3;
			tempb=tempb >> 8;
			}
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		temp=temp*tempb;
		temp=temp >> 8;
		if (temp == 0) temp = 1;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==4)  // Delay Divide
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}

		if (temp == 0) temp = 1;
		if (tempb == 0) tempb = 1;
		temp=temp*val2;
		tempb=tempb*val3;
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		temp=temp/tempb;
		temp=temp << 12;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==5)  // Delay Backwards Divide
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}

		if (temp == 0) temp = 1;
		if (tempb == 0) tempb = 1;
		temp=temp*val2;
		tempb=tempb*val3;
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		temp=tempb/temp;
		temp=temp << 12;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==6)  // Delay AND
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}

		if (temp == 0) temp = -1;
		if (tempb == 0) tempb = -1;
		temp=temp*val2;
		tempb=tempb*val3;
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		temp=temp & tempb;
		temp=temp >> 8;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==7)  // Delay OR
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}

		if (temp == 0) temp = 1;
		if (tempb == 0) tempb = 1;
		temp=temp*val2;
		if (addtyp == 1)
			{
			if (val3 < 128) val3 = 128;
			}
		tempb=tempb*val3;
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		temp=temp | tempb;
		if (addtyp == 0) temp=temp >> 8;
		if (addtyp == 1) temp=temp >> 6;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==8)  // Delay XOR
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}

		if (temp == 0) temp = 1;
		if (tempb == 0) tempb = 1;
		temp=temp*val2;
		tempb=tempb*val3;
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		temp=temp ^ tempb;
		temp=temp >> 8;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==9)  // Delay Rectify
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}
  	phcountb = phcount << 1;
	locheckcount = samend-phcount;
	hicheckcount = samend-phcountb;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		if (samcount >= locheckcount) tempb=0;
		else tempb=*(sampoint+samcount+phcount);

		if (addtyp == 0)
			{
			if ((temp > 0) && (tempb <= 0)) temp = ~temp;
			if ((temp < 0) && (tempb >= 0)) temp = ~temp;
			}

		if (addtyp == 1)
			{
			if (samcount >= hicheckcount) tempc=0;
			else tempc=*(sampoint+samcount+phcountb);
			tempb = tempb + tempc;
			if ((temp > 0) && (tempb <= 0)) temp = ~temp;
			if ((temp < 0) && (tempb >= 0)) temp = ~temp;
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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	}

//-----------------------------------------------------------------------

 if (opt==10)  // Delay Greater
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}
		
		temp=temp*val2;
		tempb=tempb*val3;
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		   if (temp<0)
			 {
			 temp = (temp<tempb) ? temp : tempb;
			 }
		   if (temp>0)
			 {
			 temp = (temp>tempb) ? temp : tempb;
			 }
		temp=temp >> 8;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==11)  // Delay Lesser
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}
  	phcountb = phcount << 1;
	locheckcount = samend-phcount;
	hicheckcount = samend-phcountb;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;
		if (samcount >= locheckcount) tempb=0;
		else tempb=*(sampoint+samcount+phcount);
		
		temp=temp*val2;
		tempb=tempb*val3;

		if (temp>0)
			{
			temp = (temp<tempb) ? temp : tempb;
			}
		if (temp<0)
			{
			temp = (temp>tempb) ? temp : tempb;
			}

		if (addtyp==1)		// Double
			{
			if (tempb>0)
				{
				tempb = (tempb<tempc) ? tempb : tempc;
				}
			if (tempb<0)
				{
				tempb = (tempb>tempc) ? tempb : tempc;
				}
			if (temp>0)
				{
				temp = (temp<tempb) ? temp : tempb;
				}
			if (temp<0)
				{
				temp = (temp>tempb) ? temp : tempb;
				}
		 	}

		temp=temp >> 8;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==12)  // Delay interleave
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			temp=temp*val2;
			temp=temp >> 8;
			tempb=tempb*val3;
			tempb=tempb >> 8;
			if (shortcount == 1)	// swap
				{
				temp=*(sampoint+samcount)=tempb;
				if (samcount >= locheckcount) {}
				else *(sampoint+samcount+phcount)=temp;
				shortcount = 0;
				}
			else // shortcount = 0
				{
				shortcount = 1;
				}
			}

		if (addtyp == 1)	// Filter  // DISABLED - does it make any difference?
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			temp=temp*val2;
			temp=temp >> 8;
			tempb=tempb*val3;
			tempb=tempb >> 8;
			if (shortcount == 1)	// swap
				{
				*(sampoint+samcount)=tempb;
				if (samcount <= hicheckcount) {}
				else *(sampoint+samcount-phcount)=temp;
				shortcount = 0;
				}
			else // shortcount = 0
				{
				shortcount = 1;
				}
			}

/*		if (mixlev<256)
		 	{
		 	temp=temp*mixlev;
		 	temp=temp >> 8;
		 	origval=origval*mixlevb;
		 	origval=origval >> 8;
		 	if (addtypb==0) temp=origval+temp;
		 	if (addtypb==1) temp=origval-temp;
		 	}
		*(sampoint+samcount)=temp;*/
  	  if (samcount==memdivtodo)
		 {
		 done++;
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	}

//-----------------------------------------------------------------------

 if (opt==13)  // Delay Modulus
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}

		if (temp == 0) temp = 1;
		if (tempb == 0) tempb = 1;
		temp=temp*val2;
		tempb=tempb*val3;
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		temp=temp%tempb;
		if (addtyp == 0) temp=temp >> 9;
		if (addtyp == 1) temp=temp >> 5;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}

//-----------------------------------------------------------------------

 if (opt==14)  // Delay Backwards Modulus
  	{
  	phcount=val1+2;
  	if (addtypb==1)
  		{
  		phcount=phcount << 2;	// Long
  		phcount=phcount + 256;
  		}

	locheckcount = samend-phcount;
	hicheckcount = samstart+phcount;

	for (samcount=samstart;samcount<=samend;samcount++)
		{
		temp=*(sampoint+samcount);
		origval=temp;

		if (addtyp == 0)	// Normal
			{
			if (samcount >= locheckcount) tempb=0;
			else tempb=*(sampoint+samcount+phcount);
			}

		if (addtyp == 1)	// Filter
			{
			if (samcount <= hicheckcount) tempb=0;
			else tempb=*(sampoint+samcount-phcount);
			}

		if (temp == 0) temp = 1;
		if (tempb == 0) tempb = 1;
		temp=temp*val2;
		tempb=tempb*val3;
		if (temp == 0) temp = 256;
		if (tempb == 0) tempb = 256;
		temp=tempb%temp;
		if (addtyp == 0) temp=temp >> 9;
		if (addtyp == 1) temp=temp >> 5;

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
		 Newdrawdonebox(3,0,100,75,done,drawbarside);
		 memdivtodo=memdivtodo+memdiv;
		 }
		}
  	  Rescalenoboxrng();
  	  Newdrawdonebox(3,95,100,200,200,drawbarside);
  	}


}

///*************************************************************************************************
///*************************************************************************************************
///*************************************************************************************************

// COMPLEX - Delay Operations

//	0	Fliter Delay 

void  SAMPLEWindow::DelayMathsrng(int32 opt,int32 optb)
{
int32 temp;
int32 tempb;
int32 tempc;
int32 tempd;

uint32 phcount;
uint32 phcountb;
int32 doneb;
int32 test;

int32 valtemp;
int32 mixlevb;
int32 origval;

int32 Incount=0;
int32 ref;
int32 samlenb;
int32 shortcount;

uint32 locheckcount;
uint32 hicheckcount;

int32 count;
float dtemp;
float dtempb;

int32 val1=samslider1;
int32 val2=samslider2;
int32 val3=samslider3;
int32 val4=samslider4;
int32 addtyp=samradio1;
int32 addtypb=samradio2;
int32 mixlev=samslider;
mixlevb=256-mixlev;

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
//-----------------------------------------------------------------------

if (opt==1)	//	Delay 1/x
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
			}
		*(sampoint+samcount)=temp;
		if (samcount==memdivtodo)
			{
			done++;
			memdivtodo=memdivtodo+memdiv;
			Newdrawdonebox(3,0,100,75,done,drawbarside);
			//             mode, start, end, max, val, side,
			}
		}
	Rescalenoboxrng();
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==2)	//	Delay acosf
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==3)	//	Delay asinf
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==4)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==5)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==6)	//	Delay Sin
	{

	phcount=val1+2;
	phcount=phcount << 2;	// Long
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==7)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==8)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		dtemp=temp;
		if (dtemp>=32766) dtemp=32766;
		if (dtemp<=-32766) dtemp=-32766;
		temp=dtemp;
		  dtemp=dtemp*0.000047948;
		  dtemp=coshf(dtemp);   // coshf
		  dtemp=dtemp*32766;
		  dtemp=dtemp-32766;
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==9)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------

if (opt==10)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==11)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==12)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==13)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==14)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==15)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==16)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==17)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==18)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==19)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------

if (opt==20)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==21)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		dtemp=temp;
		if (dtemp>=32766) dtemp=32766;
		if (dtemp<=-32766) dtemp=-32766;
		temp=dtemp;
		  dtemp=dtemp*0.000047948;
		  dtemp=expm1f(dtemp);   // expmlf 
		  dtemp=dtemp*32766;
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==22)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==23)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==24)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==25)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
			  if (origval<0)
				 {
				 dtempb=dtemp*2;
				 dtemp=dtemp-dtempb;
				 }
		if (dtemp>=32766) dtemp=32766;
		if (dtemp<=-32766) dtemp=-32766;
		temp=dtemp;
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==26)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==27)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==28)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==29)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------

if (opt==30)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==31)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==32)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==33)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==34)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==35)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==36)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==37)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==38)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==39)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
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
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

if (opt==40)	//	Delay 
	{

	phcount=val1+2;
	phcount=phcount << 2;
	hicheckcount = samstart+phcount;

	for (count=0;count<=65535;count++)	//	create buffer
		{
		temp=count;
		temp=temp-32767;
		origval=temp;
		if (addtypb==1)	// Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		dtemp=temp;
		  temp=ilogbf(dtemp);   // ilogbf
		  if (temp>=32766) temp=32766;
		  if (temp<=-32766) temp=-32766;
		if (addtypb==1)	// 	Invert
			{
			if (temp>0) temp=32767-temp;
			if (temp<0) temp=-32767-temp;
			}
		if (addtyp==1)	// diff
			{
			temp=temp-origval;
 			temp=temp << 2;
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

		if (samcount <= hicheckcount) tempb=0;	// filter
		else tempb=*(sampoint+samcount-phcount);

		temp=temp*val2;
		if (temp == 0) temp = 256;
		temp=temp >> 8;
		tempb=tempb*val3;
		if (tempb == 0) tempb = 256;
		tempb=tempb >> 8;

		if (temp>=32766) temp=32766;
		if (temp<=-32766) temp=-32766;
		  
		temp=tempb-temp;

		if (mixlev<256)
			{
			temp=temp*mixlev;
			temp=temp >> 8;
			origval=origval*mixlevb;
			origval=origval >> 8;
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
	Newdrawdonebox(3,95,100,200,200,drawbarside);
	}

//-----------------------------------------------------------------------

}

///*************************************************************************************************
///*************************************************************************************************
///*************************************************************************************************


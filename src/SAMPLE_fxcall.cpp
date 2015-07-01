//      Aural illusion v4.0  Effects & Manipulations Part 3 

//      SAMPLE_fxcall.cpp

//      copyright (c) Blachford Technology  21/6/99

#include "SAMPLEWindow.h"

/*****************************************************************/
// Functions

//	Dummy Functions

//	Doeffect
//	DoStandardEffect
//	DoComplexEffect
//	DoManip1
//	DoManip2
//	DoDualManip
//	DoStereoEffect

/*****************************************************************/

// ****************************************************************************************************
// ****************************************************************************************************
// ****************************************************************************************************

/*
// DUMMY FUNCTIONS - Rem out when not in use

	// SAMPLE_fx1.cpp
	
	void SAMPLEWindow::Arithrng(int32 opt,int32 optb) {};			// Arithemitic Operations
	void SAMPLEWindow::Invertrng(int32 opt,int32 optb) {};			// Invert + MANIPs
	void SAMPLEWindow::Limitrng(int32 opt,int32 optb) {};			// Limit + MANIPs
	void SAMPLEWindow::Distortrng(int32 opt,int32 optb) {};			// Distort + FX
	void SAMPLEWindow::Mathsrng(int32 opt,int32 optb) {};			// Sin + COMPLEX
	void SAMPLEWindow::Cleanrng(int32 opt,int32 optb) {};			// Clean + MANIPs
	void SAMPLEWindow::Capacitrng(int32 opt,int32 optb) {};			// Capacitance + MANIPs
	void SAMPLEWindow::Interrng(int32 opt,int32 optb) {};			// Interleave DMANIP
	void SAMPLEWindow::Phaserng(int32 opt,int32 optb) {};			// Phaser + FX
	void SAMPLEWindow::Flangerng(int32 opt,int32 optb) {};			// Flange + FX
	void SAMPLEWindow::Stutterrng(int32 opt,int32 optb) {};			// Stutter + DMANIPs
	void SAMPLEWindow::Filterrng(int32 opt) {};						// 7 Band EQ FX
	void SAMPLEWindow::Filterbandrng(int32 opt,int32 optb) {};		// 7 Band EQ MANIPs
	void SAMPLEWindow::Filter20rng(int32 opt) {};					// 20 Band EQ FX
	void SAMPLEWindow::Vibraterng(int32 opt,int32 optb) {};			// Vibrato FX
	void SAMPLEWindow::Filtersweeprng(int32 opt,int32 optb) {};		// Filter sweep MANIPs
	void SAMPLEWindow::Basfiltrng(int32 opt,int32 optb) {};			// Wha??? FX - Experimental
	
	// SAMPLE_fx2.cpp
	void  SAMPLEWindow::Echorng(int32 opt, int32 optb) {};			// Reverb FX
	void  SAMPLEWindow::Delayrng( int32 opt, int32 optb) {};		// Long Delay FX
	void  SAMPLEWindow::Faderng( int32 opt, int32 optb) {};			// Fade MANIPs
	void  SAMPLEWindow::Unorderrng(int32 opt,int32 optb) {};		// Unorder Samples FX
	void  SAMPLEWindow::Tunerng(int32 opt,int32 optb) {};			// Tune Octave MANIPs
	void  SAMPLEWindow::Detunerng(int32 opt,int32 optb) {};			// Detune FX
	void  SAMPLEWindow::Thickenrng(int32 opt,int32 optb) {};		// Thicken MANIPs
	void  SAMPLEWindow::SArithrng(int32 opt,int32 optb) {};			// Add SFX
	void  SAMPLEWindow::SInterrng(int32 opt,int32 optb) {};			// Interleave SFX
	void  SAMPLEWindow::Zerooutrng(int32 opt,int32 optb) {};		// Zero out MANIPs
	void  SAMPLEWindow::Compressrng(int32 opt,int32 optb) {};		// Compress FX
	void  SAMPLEWindow::Sfaderng(int32 opt,int32 optb) {};			// Stereo Pan SFX
	void  SAMPLEWindow::Blockrng(int32 opt,int32 optb) {};			// Transform Blocks MANIPs
	void  SAMPLEWindow::Blurrng(int32 opt,int32 optb) {};			// 2D Blur FX
	void  SAMPLEWindow::Chaosrng(int32 opt,int32 optb) {};			// Chaos MANIPs
	void  SAMPLEWindow::Chaos2rng(int32 opt,int32 optb) {};			// weird??? MANIPs
	
	// SAMPLE_fx3.cpp
	void  SAMPLEWindow::Strechorng(int32 opt,int32 optb) {};		// Stereo Reverb SFX
	void  SAMPLEWindow::Radrng(int32 opt,int32 optb) {};			// Rectify and Add DMANIPs
	void  SAMPLEWindow::MixDistortrng(int32 opt,int32 optb) {};		// Mix Distort FX
*/


//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::Doeffect(void)
{
Setcalcvals();

if ((samfxtype == 20) && (samfxnumber == 22))	{}
else	Doundo(0);

done=0;

if (samfxtype == 0)		DoStandardEffect();
if (samfxtype == 1)		DoComplexEffect();
if (samfxtype == 2)		DoManip1();
if (samfxtype == 3)		DoManip2();
if (samfxtype == 4)		DoDualManip();
if (samfxtype == 5)		DoStereoEffect();
if ((samfxtype == 20) || (samfxtype == 22))	DoEdit();
}
//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::DoStandardEffect(void) // Call Standard Effects
{
drawbarside = 0;
if (makechans==2)  drawbarside = 1;
// Start Standard Effects ****************************************************** 


    if (samfxnumber<=31)
     {
     if (samfxnumber<=15)
      {
      if (samfxnumber<=7)
       {
       if (samfxnumber<=3)
        {
        if (samfxnumber<=1)
          {
          if (samfxnumber==0)
		      {
		      Echorng(0,samfxnumber);    //  Reverb  
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Echorng(0,samfxnumber);
				}
		      }
          else
		      {
		      Echorng(1,samfxnumber);    //  Echo  
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Echorng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=2)
          {
          if (samfxnumber==2)    //  Delay  
 		     {
		      Echorng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Echorng(2,samfxnumber);
				}
		      }
          else    //  Phase Shift  
		      {
		      Phaserng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				done=0;
				Phaserng(0,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=4)
        {
        if (samfxnumber<=5)
          {
          if (samfxnumber==4)    //  Phaser  
		      {
		      Phaserng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Phaserng(1,samfxnumber);
				}
		      }
          else    //  Chorus  
		      {
		      Flangerng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Flangerng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=6)
          {
          if (samfxnumber==6)    //  Flanger  
		      {
		      Detunerng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				Detunerng(0,samfxnumber);
				}
		      }
          else    //  (Mix) Distortion 
		      {
		      MixDistortrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				MixDistortrng(1,samfxnumber);
				}
		      }
          }
        }
       }

      if ((samfxnumber>=8) && (samfxnumber<=15))
       {
       if (samfxnumber<=11)
        {
        if (samfxnumber<=9)
          {
          if (samfxnumber==8)    //  Compress  
		      {
		      Compressrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Compressrng(0,samfxnumber);
				}
		      }
          else    //  Expand  
		      {
		      Compressrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Compressrng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=10)
          {
          if (samfxnumber==10)    //  Noise Gate  
              {
              
              }
          else    //  Enhance  
		      {
		      Distortrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Distortrng(7,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=12)
        {
        if (samfxnumber<=13)
          {
          if (samfxnumber==12)    //  Resample  
		      {
		      Detunerng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Detunerng(2,samfxnumber);
				}
		      }
          else    //  Detune  
		      {
		      Detunerng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Detunerng(3,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=14)
           {
          if (samfxnumber==14)    //  Fade  
		      {
		      Faderng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Faderng(0,samfxnumber);
				}
		      }
          else    //  Boost  
		      {
		      Faderng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Faderng(1,samfxnumber);
				}
		      }
         }
        }
       }
      }

     if (samfxnumber>=16)
      {
      if (samfxnumber<=23)
       {
       if (samfxnumber<=19)
        {
        if (samfxnumber<=17)
          {
          if (samfxnumber==16)    //  Resolution  
		      {
		      Distortrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Distortrng(4,samfxnumber);
				}
		      }
          else    //  Bandwidth  
		      {
		      Distortrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Distortrng(5,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=18) 
          {
          if (samfxnumber==18)    //  Vibrato  
		      {
		      Vibraterng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Vibraterng(0,samfxnumber);
				}
		      }
          else   // wow
              {
              
              }
          }
         }
       if (samfxnumber>=20)
        {
        if (samfxnumber<=21)
          {
          if (samfxnumber==20)   // Flutter
              {
              
              }
          else    //  Alternate  
		      {
		      Vibraterng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Vibraterng(2,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=22)
          {
          if (samfxnumber==22)   // quick time stretch
              {
              
              }
          else   // Ringing
              {
              
              }          
          }
        }
       }

      if (samfxnumber>=24)
       {
       if (samfxnumber<=27)
        {
        if (samfxnumber<=25)
          {
          if (samfxnumber==24)    //  Wha  
              {
		      Basfiltrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Basfiltrng(1,samfxnumber);
				}
              }
          else    //  Tape Loop  
		      {
		      
		      }
          }
        if (samfxnumber>=26)
          {
          if (samfxnumber==26)    //  Rotary Speaker  
              {
              
              }
          else    //  Filter Low Pass  
			{
			Filtersweeprng(0,samfxnumber);
			if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filtersweeprng(0,samfxnumber);
				}
			}
          }
         }
       if (samfxnumber>=28)
        {
        if (samfxnumber<=29)
          {
          if (samfxnumber==28)    //  Filter High Pass  
		     {
		     Filtersweeprng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filtersweeprng(1,samfxnumber);
				}
		     }
          else    //  Filter Band Pass  
		      {
		      Filtersweeprng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filtersweeprng(2,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=30)
          {
          if (samfxnumber==30)    //  Filter Band Cut  
		      {
		      Filtersweeprng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filtersweeprng(3,samfxnumber);
				}
		      }
          else    //  Filter Notch Pass  
		      {
		      Filtersweeprng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filtersweeprng(4,samfxnumber);
				}
		      }
          }
        }
       }
      }
     }

    if (samfxnumber>=32)
     {
     if (samfxnumber<=47)
      {
      if (samfxnumber<=39)
       {
       if (samfxnumber<=35)
        {
        if (samfxnumber<=33) 
          {
          if (samfxnumber==32)    //  Filter Notch Cut 
		      {
		      Filtersweeprng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filtersweeprng(5,samfxnumber);
				}
		      }
          else     //  Backwards Reverb  
		      {
		      Echorng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Echorng(4,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=34)
          {
          if (samfxnumber==34)    //  Reverb-Phaser  
		      {
		      Echorng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Echorng(5,samfxnumber);
				}
		      }
          else   // Old Reverb
		      {
		      
		      }
          }
         }
       if (samfxnumber>=36) 
        {
        if (samfxnumber<=37)
          {
          if (samfxnumber==36)   // reverb only
              {
              Strechorng(3,0);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Strechorng(3,0);
				}
              }
          else    //  Long Delay  
              {
              Delayrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Delayrng(0,samfxnumber);
				}
              }
          }
        if (samfxnumber>=38)
          {
          if (samfxnumber==38)    //  Multi Tap Delay  
		      {
		      Delayrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Delayrng(1,samfxnumber);
				}
		      }
          else    //  Feedback Delay
		      {
		      Delayrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Delayrng(2,samfxnumber);
				}
		      }
          }
        }
       }
      if (samfxnumber>=40)
       {
       if (samfxnumber<=43)
        {
        if (samfxnumber<=41)
          {
          if (samfxnumber==40)    //  Bounce Delay
		      {
		      Echorng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Echorng(3,samfxnumber);
				}
		      }
          else    //  Jump Flange  
		      {
		      done=0;
		      Phaserng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Phaserng(2,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=42)
          {
          if (samfxnumber==42)    //  Strange Flange  
		      {
		      Flangerng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Flangerng(0,samfxnumber);
				}
		      }
          else    //  Delay Flange  
		      {
		      Detunerng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Detunerng(1,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=44)
        {
        if (samfxnumber<=45)
          {
          if (samfxnumber==44)    //  Distortion  
		      {
		      Distortrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Distortrng(0,samfxnumber);
				}
		      }
          else    //  Contortion  
		      {
		      Distortrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Distortrng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=46)
          {
          if (samfxnumber==46)    // Mix Contortion? 
		      {
		      MixDistortrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				MixDistortrng(2,samfxnumber);
				}
		      }
          else    //  Bandwidth Smooth  
		      {
		      Distortrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Distortrng(6,samfxnumber);
				}
 		      }
          }
        }
       }
      }

     if (samfxnumber>=48)
      {
      if (samfxnumber<=55)
       {
       if (samfxnumber<=51)
        {
        if (samfxnumber<=49)
          {
          if (samfxnumber==48)    //  Vibrato Delay  
		      {
		      Vibraterng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Vibraterng(1,samfxnumber);
				}
		      }
          else	//
		      {
		      
		      }
          }
        if (samfxnumber>=50)
          {
          if (samfxnumber==50)   //
              {
              
              }
          else   // 51
              {
              
              }
          }
        }
       if (samfxnumber>=52)
        {
        if (samfxnumber<=53)
          {
          if (samfxnumber==52) //
              {
              
              }
          else   // 53
              {
              
              }
          }
        if (samfxnumber>=54)
          {
          if (samfxnumber==54) //
              {
              
              }
          else   // 55
              {
              
              }
          }
        }
       }

      if (samfxnumber>=56)
       {
       if (samfxnumber<=59)
        {
        if (samfxnumber<=57)
          {
          if (samfxnumber==56)   //
              {
              
              }
          else   // 57
              {
              
              }
          }
        if (samfxnumber>=58)
          {
          if (samfxnumber==58)   //
              {
              
              }
          else   // 59
              {
              
              }
          }
         }
       if (samfxnumber>=60)
        {
        if (samfxnumber<=61)
          {
          if (samfxnumber==60)   //
              {
              
              }
          else   // 61
              {
              
              }
          }
        if (samfxnumber>=62)
          {
          if (samfxnumber==62)   //
              {
              
              }
          else   // 63
              {
              
              }
          }
        }
       }
      }
     }

// End Standard Effects ***************************************************


}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::DoComplexEffect(void) // Call Complex Effects
{
drawbarside = 0;
if (makechans==2)  drawbarside = 1;

// Start Complex Effects *******************************************

   if (samfxnumber<=31)
     {
     if (samfxnumber<=15)
      {
      if (samfxnumber<=7)
       {
       if (samfxnumber<=3)
        {
        if (samfxnumber<=1)
          {
          if (samfxnumber==0)    //  1/x
		      {
		      Mathsrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(1,samfxnumber);
				}
		      }
          else   //     acos
		      {
		      Mathsrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(2,samfxnumber);
				}
		      } 
          }
        if (samfxnumber>=2)
          {
          if (samfxnumber==2)     //  asin
		      {
		      Mathsrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(3,samfxnumber);
				}
		      }
          else   //     atan
		      {
		      Mathsrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(4,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=4)
        {
        if (samfxnumber<=5)
          {
          if (samfxnumber==4)    //  cos
		      {
		      Mathsrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(5,samfxnumber);
				}
		      }
          else   //     sin
		      {
		      Mathsrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(6,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=6)
          {
          if (samfxnumber==6)     //  tan
              {
		      Mathsrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(7,samfxnumber);
				}
		      }
          else     //     cosh
		      {
		      Mathsrng(8,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(8,samfxnumber);
				}
		      }
          }
        }
       }

      if (samfxnumber>=8)
       {
       if (samfxnumber<=11)
        {
        if (samfxnumber<=9)
          {
          if (samfxnumber==8)      //  sinh
              {
		      Mathsrng(9,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(9,samfxnumber);
				}
		      }
          else     //     tanh
		      {
		      Mathsrng(10,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(10,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=10)
          {
          if (samfxnumber==10)      //  acosh
		      {
		      Mathsrng(11,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(11,samfxnumber);
				}
		      }
          else   //     asinh
		      {
		      Mathsrng(12,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(12,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=12)
        {
        if (samfxnumber<=13)
          {
          if (samfxnumber==12)      //  atanh
		      {
		      Mathsrng(13,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(13,samfxnumber);
				}
		      }
          else     //     sec
		      {
		      Mathsrng(14,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(14,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=14)
           {
          if (samfxnumber==14)  // cosec
		      {
		      Mathsrng(15,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(15,samfxnumber);
				}
		      }
          else  // 15	Cot
		      {
		      Mathsrng(16,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(16,samfxnumber);
				}
		      }
         }
        }
       }
      }

     if (samfxnumber>=16)
      {
      if (samfxnumber<=23)
       {
       if (samfxnumber<=19)
        {
        if (samfxnumber<=17)
          {
          if (samfxnumber==16)   //	+Sin
              {
              Mathsrng(17,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(17,samfxnumber);
				}
              }
          else    //	exp
              {
              Mathsrng(18,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(18,samfxnumber);
				}
              }
          }
        if (samfxnumber>=18) 
          {
          if (samfxnumber==18)  // log
              {
              Mathsrng(19,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(19,samfxnumber);
				}
              }
          else   // log10
              {
              Mathsrng(20,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(20,samfxnumber);
				}
              }
          }
         }
       if (samfxnumber>=20)
        {
        if (samfxnumber<=21)
          {
          if (samfxnumber==20)  //	expm1
              {
              Mathsrng(21,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(21,samfxnumber);
				}
              }
          else   // 	log1p
              {
              Mathsrng(22,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(22,samfxnumber);
				}
              }
          }
        if (samfxnumber>=22)
          {
          if (samfxnumber==22)  //	logb
              {
              Mathsrng(23,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(23,samfxnumber);
				}
              }
          else   // 	+Log
              {
              Mathsrng(24,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(24,samfxnumber);
				}
              }
          }
        }
       }

      if (samfxnumber>=24)
       {
       if (samfxnumber<=27)
        {
        if (samfxnumber<=25)
          {
          if (samfxnumber==24)  //	sqrt
              {
              Mathsrng(25,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(25,samfxnumber);
				}
              }
          else   // 	cbrt
              {
              Mathsrng(26,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(26,samfxnumber);
				}
              }
          }
        if (samfxnumber>=26)
          {
          if (samfxnumber==26)  //	ceil
              {
              Mathsrng(27,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(27,samfxnumber);
				}
              }
          else   // 	fabs
              {
              Mathsrng(28,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(28,samfxnumber);
				}
              }
          }
         }
       if (samfxnumber>=28)
        {
        if (samfxnumber<=29)
          {
          if (samfxnumber==28)  //	floor
              {
              Mathsrng(29,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(29,samfxnumber);
				}
              }
          else   // 	significand
              {
              Mathsrng(30,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(30,samfxnumber);
				}
              }
          }
        if (samfxnumber>=30)
          {
          if (samfxnumber==30)  //	j0
              {
              Mathsrng(31,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(31,samfxnumber);
				}
              }
          else   // 	j1
              {
              Mathsrng(32,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(32,samfxnumber);
				}
              }
          }
        }
       }
      }
     }

    if ((samfxnumber>=32) && (samfxnumber<=63))
     {
     if (samfxnumber<=47)
      {
      if (samfxnumber<=39)
       {
       if (samfxnumber<=35)
        {
        if (samfxnumber<=33) 
          {
          if (samfxnumber==32)  //	y0
              {
              Mathsrng(33,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(33,samfxnumber);
				}
              }
          else   // 	y1
              {
              Mathsrng(34,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(34,samfxnumber);
				}
              }
          }
        if (samfxnumber>=34)
          {
          if (samfxnumber==34)  //	erf
              {
              Mathsrng(35,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(35,samfxnumber);
				}
              }
          else   // 	erfc
              {
              Mathsrng(36,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(36,samfxnumber);
				}
              }
          }
         }
       if (samfxnumber>=36) 
        {
        if (samfxnumber<=37)
          {
          if (samfxnumber==36)  //	gamma
              {
              Mathsrng(37,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(37,samfxnumber);
				}
              }
          else   // 	lgamma
              {
              Mathsrng(38,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(38,samfxnumber);
				}
              }
          }
        if (samfxnumber>=38)
          {
          if (samfxnumber==38)  //	rint
              {
              Mathsrng(39,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Mathsrng(39,samfxnumber);
				}
              }
          else   // 	ilogbf
              {
              DelayMathsrng(40,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(40,samfxnumber);
				}
              }
          }
        }
       }
      if (samfxnumber>=40)
       {
       if (samfxnumber<=43)
        {
        if (samfxnumber<=41)
          {
          if (samfxnumber==40)  //	Delay 1/x
              {
              DelayMathsrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(1,samfxnumber);
				}
              }
          else   //	Delay acos
              {
              DelayMathsrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(2,samfxnumber);
				}
              }
          }
        if (samfxnumber>=42)
          {
          if (samfxnumber==42)  //	Delay asin
              {
              DelayMathsrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(3,samfxnumber);
				}
              }
          else   // 	Delay atan
              {
              DelayMathsrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(4,samfxnumber);
				}
              }
          }
         }
       if (samfxnumber>=44)
        {
        if (samfxnumber<=45)
          {
          if (samfxnumber==44)  //	Delay cos
              {
              DelayMathsrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(5,samfxnumber);
				}
              }
          else   // 	Delay sin
              {
              DelayMathsrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(6,samfxnumber);
				}
              }
          }
        if (samfxnumber>=46)
          {
          if (samfxnumber==46)  //	Delay tan
              {
              DelayMathsrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(7,samfxnumber);
				}
              }
          else   // 	Delay cosh
              {
              DelayMathsrng(8,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(8,samfxnumber);
				}
              }
          }
        }
       }
      }

     if (samfxnumber>=48)
      {
      if (samfxnumber<=55)
       {
       if (samfxnumber<=51)
        {
        if (samfxnumber<=49)
          {
          if (samfxnumber==48)  //	Delay sinh
              {
              DelayMathsrng(9,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(9,samfxnumber);
				}
              }
          else   // 	Delay tanh
              {
              DelayMathsrng(10,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(10,samfxnumber);
				}
              }
          }
        if (samfxnumber>=50)
          {
          if (samfxnumber==50)  //	Delay acosh
              {
              DelayMathsrng(11,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(11,samfxnumber);
				}
              }
          else   // 	Delay asinh
              {
              DelayMathsrng(12,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(12,samfxnumber);
				}
              }
          }
        }
       if (samfxnumber>=52)
        {
        if (samfxnumber<=53)
          {
          if (samfxnumber==52)  //	Delay atanh
              {
              DelayMathsrng(13,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(13,samfxnumber);
				}
              }
          else   // 	Delay sec
              {
              DelayMathsrng(14,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(14,samfxnumber);
				}
              }
          }
        if (samfxnumber>=54)
          {
          if (samfxnumber==54)  //	Delay cosec
              {
              DelayMathsrng(15,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(15,samfxnumber);
				}
              }
          else   // 	Delay Cot
              {
              DelayMathsrng(16,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(16,samfxnumber);
				}
              }
          }
        }
       }

      if (samfxnumber>=56)
       {
       if (samfxnumber<=59)
        {
        if (samfxnumber<=57)
          {
          if (samfxnumber==56)  //	Delay +Sin
              {
              DelayMathsrng(17,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(17,samfxnumber);
				}
              }
          else   // 	Delay exp
              {
              DelayMathsrng(18,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(18,samfxnumber);
				}
              }
          }
        if (samfxnumber>=58)
          {
          if (samfxnumber==58)  //	Delay log
              {
              DelayMathsrng(19,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(19,samfxnumber);
				}
              }
          else   // 	Delay log10
              {
              DelayMathsrng(20,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(20,samfxnumber);
				}
              }
          }
         }
       if (samfxnumber>=60)
        {
        if (samfxnumber<=61)
          {
          if (samfxnumber==60)  //	Delay expm
              {
              DelayMathsrng(21,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(21,samfxnumber);
				}
              }
          else   // 	Delay log1p
              {
              DelayMathsrng(22,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(22,samfxnumber);
				}
              }
          }
        if (samfxnumber>=62)
          {
          if (samfxnumber==62)  //	Delay logb
              {
              DelayMathsrng(23,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(23,samfxnumber);
				}
              }
          else   // 	Delay +Log
              {
              DelayMathsrng(24,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(24,samfxnumber);
				}
              }
          }
        }
       }
      }
     }

if ((samfxnumber<=79) && (samfxnumber>=64))
      {
      if (samfxnumber<=71)
       {
       if (samfxnumber<=67)
        {
        if (samfxnumber<=65)
          {
          if (samfxnumber==64)    //	Delay sqrt
		      {
		      DelayMathsrng(25,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(25,samfxnumber);
				}
		      }
          else   //	Delay cbrt
		      {
		      DelayMathsrng(26,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(26,samfxnumber);
				}
		      } 
          }
        if (samfxnumber>=66)
          {
          if (samfxnumber==66)     //	Delay ceil
		      {
		      DelayMathsrng(27,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(27,samfxnumber);
				}
		      }
          else   //	Delay fabs
		      {
		      DelayMathsrng(28,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(28,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=68)
        {
        if (samfxnumber<=69)
          {
          if (samfxnumber==68)    //	Delay floor
		      {
		      DelayMathsrng(29,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(29,samfxnumber);
				}
		      }
          else   //	Delay significand
		      {
		      DelayMathsrng(30,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(30,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=70)
          {
          if (samfxnumber==70)     //	Delay j0
              {
		      DelayMathsrng(31,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(31,samfxnumber);
				}
		      }
          else     //	Delay j1
		      {
		      DelayMathsrng(32,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(32,samfxnumber);
				}
		      }
          }
        }
       }

      if (samfxnumber>=72)
       {
       if (samfxnumber<=75)
        {
        if (samfxnumber<=73)
          {
          if (samfxnumber==72)      //	Delay y0
              {
		      DelayMathsrng(33,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(33,samfxnumber);
				}
		      }
          else     //	Delay y1
		      {
		      DelayMathsrng(34,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(34,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=74)
          {
          if (samfxnumber==74)      //	Delay erf
		      {
		      DelayMathsrng(35,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(35,samfxnumber);
				}
		      }
          else   //	Delay erfc
		      {
		      DelayMathsrng(36,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(36,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=76)
        {
        if (samfxnumber<=77)
          {
          if (samfxnumber==76)      //	Delay gamma
		      {
		      DelayMathsrng(37,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(37,samfxnumber);
				}
		      }
          else     //	Delay lgamma
		      {
		      DelayMathsrng(38,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(38,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=78)
           {
          if (samfxnumber==78)  //	Delay rint
		      {
		      DelayMathsrng(39,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(39,samfxnumber);
				}
		      }
          else  //	Delay ilogbf
		      {
		      DelayMathsrng(40,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayMathsrng(40,samfxnumber);
				}
		      }
         }
        }
       }
      }

	if (samfxnumber==80)  //	7 Band Graphic Equalizer
      {
      Filterbandrng(10,samfxnumber);
      if (makechans==2)
        {
		drawbarside = 2;
        samstart=samstartb;
        samend=samendb;
        memdivtodo=memdiv+samstart;
		done=0;
        Filterbandrng(10,samfxnumber);
        }
      }
  if (samfxnumber==81)  //	20 Band Graphic Equalizer
      {
      Filter20rng(0);
      if (makechans==2)
        {
		drawbarside = 2;
        samstart=samstartb;
        samend=samendb;
        memdivtodo=memdiv+samstart;
		done=0;
        Filter20rng(0);
        }
      }

}

// End COMPLEX Effects ***************************************************



//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::DoManip1(void) // Call Manips 1
{
drawbarside = 0;
if (makechans==2)  drawbarside = 1;

// Start Manipulations 1 **************************************************

   if (samfxnumber<=31)
     {
     if (samfxnumber<=15)
      {
      if (samfxnumber<=7)
       {
       if (samfxnumber<=3)
        {
        if (samfxnumber<=1)
          {
          if (samfxnumber==0)    //  Invert  
		      {
		      Invertrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(0,samfxnumber);
				}
		      }
          else   //       Half Wave Rectify  
		      {
		      Invertrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=2)
          {
          if (samfxnumber==2)    //  Full Wave Rectify  
		      {
		      Invertrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(2,samfxnumber);
				}
		      }
          else        //  Flip  
		      {
		      Invertrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(3,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=4)
        {
        if (samfxnumber<=5)
          {
          if (samfxnumber==4)    //  Centre  
		      {
		      Invertrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(4,samfxnumber);
				}
		      }
          else        //  Reverse  
		      {
		      Invertrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(5,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=6)
          {
          if (samfxnumber==6)    //  Clean  
		      {
		      Cleanrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Cleanrng(0,samfxnumber);
				}
		      }
          else   //       Thicken  
		      {
		      Flangerng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Flangerng(2,samfxnumber);
				}
		      }
          }
        }
       }

      if (samfxnumber>=8)
       {
       if (samfxnumber<=11)
        {
        if (samfxnumber<=9)
          {
          if (samfxnumber==8)    //  Double Thicken  
		      {
		      Flangerng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Flangerng(3,samfxnumber);
				}
		      }
          else   //       Distort + 
              {
              
              } 
          }
        if (samfxnumber>=10)
          {
          if (samfxnumber==10)    //  Distort -  
              {
              
              }
          else        //  Quarter Value  
		      {
		      Limitrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(2,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=12)
        {
        if (samfxnumber<=13)
          {
          if (samfxnumber==12)    //  Half Value  
		      {
		      Limitrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(3,samfxnumber);
				}
		      }
          else        //  Double Value  
		      {
		      Limitrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(4,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=14)
           {
          if (samfxnumber==14)    //  Quadruple Value  
		      {
		      Limitrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(5,samfxnumber);
				}
		      }
          else        //  Fade In  
		      {
		      Faderng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Faderng(2,samfxnumber);
				}
		      }
         }
        }
       }
      }

     if (samfxnumber>=16)
      {
      if (samfxnumber<=23)
       {
       if (samfxnumber<=19)
        {
        if (samfxnumber<=17)
          {
          if (samfxnumber==16)    //  Fade Out  
		      {
		      Faderng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Faderng(3,samfxnumber);
				}
		      }
          else        //  Recreate  
		      {
		      Filterbandrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(0,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=18) 
          {
          if (samfxnumber==18)    //  Loudness  
		      {
		      Filterbandrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(1,samfxnumber);
				}
		      }
          else        //  UnLoudness  
		      {
		      Filterbandrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(2,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=20)
        {
        if (samfxnumber<=21)
          {
          if (samfxnumber==20)    //  Filter Very High  
		      {
		      Filterbandrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(3,samfxnumber);
				}
		      }
          else        //  Filter High Band  
		      {
		      Filterbandrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(4,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=22)
          {
          if (samfxnumber==22)    //  Filter High Mid  
		      {
		      Filterbandrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(5,samfxnumber);
				}
		      }
          else        //  Filter Mid Band  
		      {
		      Filterbandrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(6,samfxnumber);
				}
		      }
          }
        }
       }

      if (samfxnumber>=24)
       {
       if (samfxnumber<=27)
        {
        if (samfxnumber<=25)
          {
          if (samfxnumber==24)    //  Filter Low Mid  
		      {
		      Filterbandrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(7,samfxnumber);
				}
		      }
          else        //  Filter Low Band  
		      {
		      Filterbandrng(8,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(8,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=26)
          {
          if (samfxnumber==26)    //  Filter Sub Bass  
		      {
		      Filterbandrng(9,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Filterbandrng(9,samfxnumber);
				}
		      }
          else        //  Tune 2 Octaves  
		      {
		      Tunerng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Tunerng(0,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=28)
        {
        if (samfxnumber<=29)
          {
          if (samfxnumber==28)    //  Tune Octave  
		      {
		      Tunerng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Tunerng(1,samfxnumber);
				}
		      }
          else        //  Tune Note  
		      {
		      Tunerng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Tunerng(2,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=30)
          {
          if (samfxnumber==30)    //  Tune Semitone  
		      {
		      Tunerng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Tunerng(3,samfxnumber);
				}
		      }
          else        //  Tune 1/8 Note  
		      {
		      Tunerng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Tunerng(4,samfxnumber);
				}
		      }
          }
        }
       }
      }
     }

    if (samfxnumber>=32)
     {
     if (samfxnumber<=47)
      {
      if (samfxnumber<=39)
       {
       if (samfxnumber<=35)
        {
        if (samfxnumber<=33) 
          {
          if (samfxnumber==32)    //  Zero Out  
		      {
		      Zerooutrng(0,samfxnumber);
		      }
          else        //  Move +/-  
		      {
		      Limitrng(9,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(9,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=34)
          {
          if (samfxnumber==34)    //  Blur Filter
		      {
		      Limitrng(10,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(10,samfxnumber);
				}
		      }
          else        //  2D Blur Filter
		      {
		      Blurrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blurrng(1,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=36) 
        {
        if (samfxnumber<=37)
          {
          if (samfxnumber==36)    // Auto Stutter  
		      {
		      Blockrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blockrng(6,samfxnumber);
				}
		      }
          else        // Strange Delay   
		      {
		      Chaos2rng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaos2rng(7,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=38)
          {
          if (samfxnumber==38)    // Stranger Delay   
		      {
		      Chaos2rng(8,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaos2rng(8,samfxnumber);
				}
		      }
          else   // Variable Half Wave Rectify
              {
              
              }
          }
        }
       }
      if (samfxnumber>=40)
       {
       if (samfxnumber<=43)
        {
        if (samfxnumber<=41)
          {
          if (samfxnumber==40)    //   Variable Full Wave Rectify
		      {
		      
		      }
          else        //  Half Distortion  
		      {
//		      Distortrng(2,samfxnumber);
		      MixDistortrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
//				Distortrng(2,samfxnumber);
		      MixDistortrng(3,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=42)
          {
          if (samfxnumber==42) // Half Contortion 
              {
//              Distortrng(3,samfxnumber);
		      MixDistortrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
//				Distortrng(3,samfxnumber);
		      MixDistortrng(4,samfxnumber);
				}
              }
          else   // Smooth Ends 
              {
              
              } 
          }
         }
       if (samfxnumber>=44)
        {
        if (samfxnumber<=45)
          {
          if (samfxnumber==44) //
              {
              
              }
          else   //
              {
              
              } 
          }
        if (samfxnumber>=46)
          {
          if (samfxnumber==46) //
              {
              
              }
          else   //
              {
              
              } 
          }
        }
       }
      }

     if (samfxnumber>=48)
      {
      if (samfxnumber<=55)
       {
       if (samfxnumber<=51)
        {
        if (samfxnumber<=49)
          {
          if (samfxnumber==48) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=50)
          {
          if (samfxnumber==50) //
              {
              
              }
          else   // 
              {
              
              }
          }
        }
       if (samfxnumber>=52)
        {
        if (samfxnumber<=53)
          {
          if (samfxnumber==52) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=54)
          {
          if (samfxnumber==54) //
              {
              
              }
          else   // 
              {
              
              }
          }
        }
       }

      if (samfxnumber>=56)
       {
       if (samfxnumber<=59)
        {
        if (samfxnumber<=57)
          {
          if (samfxnumber==56) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=58)
          {
          if (samfxnumber==58) //
              {
              
              }
          else   // 
              {
              
              }
          }
         }
       if (samfxnumber>=60)
        {
        if (samfxnumber<=61)
          {
          if (samfxnumber==60) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=62)
          {
          if (samfxnumber==62) //
              {
              
              }
          else   // 
              {
              
              }
          }
        }
       }
      }
     }

// End MANIPS 1 ***************************************************

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::DoManip2(void) // Call Manips 2
{
drawbarside = 0;
if (makechans==2)  drawbarside = 1;

// Start Manipulations 2 **************************************************

   if (samfxnumber<=31)
     {
     if (samfxnumber<=15)
      {
      if (samfxnumber<=7)
       {
       if (samfxnumber<=3)
        {
        if (samfxnumber<=1)
          {
          if (samfxnumber==0)    //  Over  
		      {
		      Invertrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(6,samfxnumber);
				}
		      }
          else        //  Under  
		      {
		      Invertrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(7,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=2)
          {
          if (samfxnumber==2)    //  In Between  
		      {
		      Invertrng(8,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(8,samfxnumber);
				}
		      }
          else        //  Out Between  
		      {
		      Invertrng(9,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Invertrng(9,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=4)
        {
        if (samfxnumber<=5)
          {
          if (samfxnumber==4)    //  Limit Low  
		      {
		      Limitrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(0,samfxnumber);
				}
		      }
          else        //  Limit High  
		      {
		      Limitrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=6)
          {
          if (samfxnumber==6)    //  Add Spikes  
		      {
		      Cleanrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Cleanrng(1,samfxnumber);
				}
		      }
          else        //  Delete Spikes  
		      {
		      Cleanrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Cleanrng(2,samfxnumber);
				}
		      }
          }
        }
       }

      if (samfxnumber>=8)
       {
       if (samfxnumber<=11)
        {
        if (samfxnumber<=9)
          {
          if (samfxnumber==8)    //  Capacitance  
		      {
		      Capacitrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Capacitrng(0,samfxnumber);
				}
		      }
          else        //  Replacement  
		      {
		      Capacitrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Capacitrng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=10)
          {
          if (samfxnumber==10)    //  Tear  
		      {
		      Capacitrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Capacitrng(2,samfxnumber);
				}
		      }
          else        //  Swap Byte Order  
		      {
		      Limitrng(8,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				//Drawdonebox(8);
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(8,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=12)
        {
        if (samfxnumber<=13)
          {
          if (samfxnumber==12)    //  Delta  
		      {
		      Cleanrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Cleanrng(3,samfxnumber);
				}
		      }
          else       //  Square  
		      {
		      Limitrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(6,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=14)
           {
          if (samfxnumber==14)    //  Half Square  
		      {
		      Limitrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Limitrng(7,samfxnumber);
				}
		      }
          else   // 
              {
              
              }
         }
        }
       }
      }

     if (samfxnumber>=16)
      {
      if (samfxnumber<=23)
       {
       if (samfxnumber<=19)
        {
        if (samfxnumber<=17)
          {
          if (samfxnumber==16)    // 8->16 bit
              {
              
              }
          else   // 16->8 bit
              {
              
              }
          }
        if (samfxnumber>=18) 
          {
          if (samfxnumber==18)    //  Transform Blocks  
              {
              Blockrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blockrng(0,samfxnumber);
				}
              }
          else        //  Reverse Single Blocks 
		      {
		      Blockrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blockrng(1,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=20)
        {
        if (samfxnumber<=21)
          {
          if (samfxnumber==20)     //  Reverse All Blocks  
		      {
		      Blockrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blockrng(2,samfxnumber);
				}
		      }
          else        //  Skip Blocks  
		      {
		      Blockrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blockrng(3,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=22)
          {
          if (samfxnumber==22)    //  Repeat Blocks
		      {
		      Blockrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blockrng(4,samfxnumber);
				}
		      }
          else          //  Unorder Samples 
		      {
		      Unorderrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Unorderrng(0,samfxnumber);
				}
		      }
          }
        }
       }

      if (samfxnumber>=24)
       {
       if (samfxnumber<=27)
        {
        if (samfxnumber<=25)
          {
          if (samfxnumber==24)     //  Unorder Blocks  
		      {
		      Unorderrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Unorderrng(1,samfxnumber);
				}
		      }
          else        // Zero Alternate
		      {
		      
		      }
          }
        if (samfxnumber>=26)
          {
          if (samfxnumber==26)   //  Flip Alternate 
              {
              Blockrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blockrng(5,samfxnumber);
				}
              }
          else        //  Random Amplifier
		      {
		      Blurrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blurrng(3,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=28)
        {
        if (samfxnumber<=29)
          {
          if (samfxnumber==28)      //  Random Filter 
		      {
		      Blurrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blurrng(4,samfxnumber);
				}
		      }
          else         // Swap Halves  
		      {
		      Chaosrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaosrng(3,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=30)
          {
          if (samfxnumber==30)    // Remove Centre (not vocal)  
		      {
		      Chaosrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaosrng(4,samfxnumber);
				}
		      }
          else        // Add Centre  
		      {
		      Chaosrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaosrng(7,samfxnumber);
				}
		      }
          }
        }
       }
      }
     }

    if (samfxnumber>=32)
     {
     if (samfxnumber<=47)
      {
      if (samfxnumber<=39)
       {
       if (samfxnumber<=35)
        {
        if (samfxnumber<=33) 
          {
          if (samfxnumber==32)    // Remove Flat  
		      {
		      Chaosrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaosrng(5,samfxnumber);
				}
		      }
          else        // Keep Flat   
		      {
		      Chaos2rng(9,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaos2rng(9,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=34)
          {
          if (samfxnumber==34)    // Remove Middle  
		      {
		      Chaos2rng(11,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaos2rng(11,samfxnumber);
				}
		      }
          else        // Transmogrify  
		      {
		      Chaosrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaosrng(6,samfxnumber);
				}
		      }
          }
         }
       if (samfxnumber>=36) 
        {
        if (samfxnumber<=37)
          {
          if (samfxnumber==36)    // Non-Transmogrify  
		      {
		      Chaos2rng(10,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaos2rng(10,samfxnumber);
				}
		      }
          else        // Delay Delta 
		      {
		      DelayBackrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				DelayBackrng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=38)
          {
          if (samfxnumber==38)     // Delay Back Subtract
		      {
		      DelayBackrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(2,samfxnumber);
				}
		      }
          else   // Delay Multiply
              {
              DelayBackrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(3,samfxnumber);
				}
              }
          }
        }
       }
      if (samfxnumber>=40)
       {
       if (samfxnumber<=43)
        {
        if (samfxnumber<=41)
          {
          if (samfxnumber==40)   // Delay Divide
              {
              DelayBackrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(4,samfxnumber);
				}
              }
          else   // Delay Back Divide
              {
              DelayBackrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(5,samfxnumber);
				}
              }
          }
        if (samfxnumber>=42)
          {
          if (samfxnumber==42)   // Delay AND
              {
              DelayBackrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(6,samfxnumber);
				}
              }
          else   // Delay OR
              {
              DelayBackrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(7,samfxnumber);
				}
              }
          }
         }
       if (samfxnumber>=44)
        {
        if (samfxnumber<=45)
          {
          if (samfxnumber==44)   // Delay XOR
              {
              DelayBackrng(8,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(8,samfxnumber);
				}
              }
          else   // Delay Rectify
              {
              DelayBackrng(9,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(9,samfxnumber);
				}
              }
          }
        if (samfxnumber>=46)
          {
          if (samfxnumber==46)   // Delay Greater
              {
              DelayBackrng(10,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(10,samfxnumber);
				}
              }
          else   // Delay Lesser
              {
              DelayBackrng(11,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(11,samfxnumber);
				}
              }
          }
        }
       }
      }

     if (samfxnumber>=48)
      {
      if (samfxnumber<=55)
       {
       if (samfxnumber<=51)
        {
        if (samfxnumber<=49)
          {
          if (samfxnumber==48)   // Delay Interleave
              {
              DelayBackrng(12,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(12,samfxnumber);
				}
              }
          else   // Delay Modulus
              {
              DelayBackrng(13,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(13,samfxnumber);
				}
              }
          }
        if (samfxnumber>=50)
          {
          if (samfxnumber==50)   // Delay Back Modulus
              {
              DelayBackrng(14,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
			    DelayBackrng(14,samfxnumber);
				}
              }
          else   //  Noise  
              {
              Capacitrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Capacitrng(3,samfxnumber);
				}
              }
          }
        }
       if (samfxnumber>=52)
        {
        if (samfxnumber<=53)
          {
          if (samfxnumber==52)    //  Filtered Noise  
		      {
		      Blurrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blurrng(0,samfxnumber);
				}
		      }
          else        //  Rumble  
		      {
		      Blurrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blurrng(5,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=54)
          {
          if (samfxnumber==54)    //  Chaos  
		      {
		      Chaosrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Chaosrng(1,samfxnumber);
				}
		      }
          else        //  Random  
		      {
		      Blurrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Blurrng(2,samfxnumber);
				}
		      }
          }
        }
       }

      if (samfxnumber>=56)
       {
       if (samfxnumber<=59)
        {
        if (samfxnumber<=57)
          {
          if (samfxnumber==56)    //
		      {
		      
		      }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=58)
          {
          if (samfxnumber==58) //
              {
              
              }
          else   // 
              {
              
              }
          }
         }
       if (samfxnumber>=60)
        {
        if (samfxnumber<=61)
          {
          if (samfxnumber==60) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=62)
          {
          if (samfxnumber==62) //
              {
              
              }
          else   // 
              {
              
              }
          }
        }
       }
      }
     }

// End Manipulations 2 ***************************************************

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::DoDualManip(void) // Call DualManips
{
drawbarside = 0;
if (makechans==2)  drawbarside = 1;

// Start Dual Manipulations //********************************************

   if (samfxnumber<=31)
     {
     if (samfxnumber<=15)
      {
      if (samfxnumber<=7)
       {
       if (samfxnumber<=3)
        {
        if (samfxnumber<=1)
          {
          if (samfxnumber==0)    //  Swap Samples  
		     {
		     
		     }
          else        //  Cross fade  
		     {
		     
		     }
          }
        if (samfxnumber>=2)
          {
          if (samfxnumber==2)   // Reverb Only
		     {
		     
		     }
          else      // Reverb Only Add
		     {
		     
		     }
          }
         }
       if (samfxnumber>=4)
        {
        if (samfxnumber<=5)
          {
          if (samfxnumber==4)     //  Powered Compress  
		     {
		     
		     }
          else        //  Powered Expand  
		     {
		     
		     }
          }
        if (samfxnumber>=6)
          {
          if (samfxnumber==6)    //  Half Rectify and Add  
		     {
		     Radrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Radrng(2,samfxnumber);
				}
		     }
          else        //  Full Rectify and Add  
		     {
		     Radrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Radrng(1,samfxnumber);
				}
		     }
          }
        }
       }

      if (samfxnumber>=8)
       {
       if (samfxnumber<=11)
        {
        if (samfxnumber<=9)
          {
          if (samfxnumber==8)     //  Add  
		      {
		      Arithrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(0,samfxnumber);
				}
		      }
	      else        //  Subtract  
		      {
		      Arithrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(1,samfxnumber);
				}
		      }
          }
        if (samfxnumber>=10)
          {
          if (samfxnumber==10)     //  Backwards Subtract  
		     {
		     Arithrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(2,samfxnumber);
				}
		     }
          else        //  Multiply  
		     {
		     Arithrng(3,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(3,samfxnumber);
				}
		     }
          }
         }
       if (samfxnumber>=12)
        {
        if (samfxnumber<=13)
          {
          if (samfxnumber==12)     //  Divide  
		     {
		     Arithrng(4,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(4,samfxnumber);
				}
		     }
          else        //  Backwards Divide  
		     {
		     Arithrng(5,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(5,samfxnumber);
				}
		     }
          }
        if (samfxnumber>=14)
           {
          if (samfxnumber==14)     //  AND  
		     {
		     Arithrng(6,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(6,samfxnumber);
				}
		     }
          else        //  OR  
		     {
		     Arithrng(7,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(7,samfxnumber);
				}
		     }
         }
        }
       }
      }

     if (samfxnumber>=16)
      {
      if (samfxnumber<=23)
       {
       if (samfxnumber<=19)
        {
        if (samfxnumber<=17)
          {
          if (samfxnumber==16)    //  XOR  
		     {
		     Arithrng(8,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(8,samfxnumber);
				}
		     }
          else        //  Greater  
		     {
		     Arithrng(9,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(9,samfxnumber);
				}
		     }
          }
        if (samfxnumber>=18) 
          {
          if (samfxnumber==18)    //  Lesser  
		     {
		     Arithrng(10,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(10,samfxnumber);
				}
		     }
          else        //  Interleave  
		     {
		     Interrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Interrng(0,samfxnumber);
				}
		     }
          }
         }
       if (samfxnumber>=20)
        {
        if (samfxnumber<=21)
          {
          if (samfxnumber==20)    //  Rectify  
		     {
		     Stutterrng(1,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Stutterrng(1,samfxnumber);
				}
		     }
          else        //  Stutter  
		     {
		     Stutterrng(0,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Stutterrng(0,samfxnumber);
				}
		     }
          }
        if (samfxnumber>=22)
          {
          if (samfxnumber==22)    //  Modulus  
		     {
		     Arithrng(11,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(11,samfxnumber);
				}
		     }
          else        //  Backwards Modulus  
		     {
		     Arithrng(12,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Arithrng(12,samfxnumber);
				}
		     }
          }
        }
       }

      if (samfxnumber>=24)
       {
       if (samfxnumber<=27)
        {
        if (samfxnumber<=25)
          {
          if (samfxnumber==24)    // Within
              {
              
              }
          else   // Without
              {
              
              }
          }
        if (samfxnumber>=26)
          {
          if (samfxnumber==26)    //  Comparator
		     {
		     
		     }
          else        //  Amplitude Modulation  
		     {
		     Stutterrng(2,samfxnumber);
		      if (makechans==2)
				{
				drawbarside = 2;
				samstart=samstartb;
				samend=samendb;
				memdivtodo=memdiv+samstart;
				done=0;
				Stutterrng(2,samfxnumber);
				}
		     }
          }
         }
       if (samfxnumber>=28)
        {
        if (samfxnumber<=29)
          {
          if (samfxnumber==28)    //  Frequency Modulation  
		     {
		     
		     }
          else       //  Pulse Width Modulation  
		     {
		     
		     }
          }
        if (samfxnumber>=30)
          {
          if (samfxnumber==30) //  Triple Modulation  
              {
              
              }
          else   //  Remove Common
              {
              
              }
          }
        }
       }
      }
     }

    if (samfxnumber>=32)
     {
     if (samfxnumber<=47)
      {
      if (samfxnumber<=39)
       {
       if (samfxnumber<=35)
        {
        if (samfxnumber<=33) 
          {
          if (samfxnumber==32) //  Magnitude Difference
              {
              
              }
          else   //  Rectify and Add
              {
              
              }
          }
        if (samfxnumber>=34)
          {
          if (samfxnumber==34) //
              {
              
              }
          else   // 
              {
              
              }
          }
         }
       if (samfxnumber>=36) 
        {
        if (samfxnumber<=37)
          {
          if (samfxnumber==36) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=38)
          {
          if (samfxnumber==38) //
              {
              
              }
          else   // 
              {
              
              }
          }
        }
       }
      if (samfxnumber>=40)
       {
       if (samfxnumber<=43)
        {
        if (samfxnumber<=41)
          {
          if (samfxnumber==40) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=42)
          {
          if (samfxnumber==42) //
              {
              
              }
          else   // 
              {
              
              }
          }
         }
       if (samfxnumber>=44)
        {
        if (samfxnumber<=45)
          {
          if (samfxnumber==44) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=46)
          {
          if (samfxnumber==46) //
              {
              
              }
          else   // 
              {
              
              }
          }
        }
       }
      }

     if (samfxnumber>=48)
      {
      if (samfxnumber<=55)
       {
       if (samfxnumber<=51)
        {
        if (samfxnumber<=49)
          {
          if (samfxnumber==48) //
              {
              
              }
          else   //
              {
              
              } 
          }
        if (samfxnumber>=50)
          {
          if (samfxnumber==50) //
              {
              
              }
          else   // 
              {
              
              }
          }
        }
       if (samfxnumber>=52)
        {
        if (samfxnumber<=53)
          {
          if (samfxnumber==52) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=54)
          {
          if (samfxnumber==54) //
              {
              
              }
          else   //
              {
              
              } 
          }
        }
       }

      if (samfxnumber>=56)
       {
       if (samfxnumber<=59)
        {
        if (samfxnumber<=57)
          {
          if (samfxnumber==56) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=58)
          {
          if (samfxnumber==58) //
              {
              
              }
          else   // 
              {
              
              }
          }
         }
       if (samfxnumber>=60)
        {
        if (samfxnumber<=61)
          {
          if (samfxnumber==60) //
              {
              
              }
          else   // 
              {
              
              }
          }
        if (samfxnumber>=62)
          {
          if (samfxnumber==62) //
              {
              
              }
          else   //
              {
              
              } 
          }
        }
       }
      }
     }

// End Dual Manips ************************************************

}

//****************************************************************************************************
//****************************************************************************************************
//****************************************************************************************************

void SAMPLEWindow::DoStereoEffect(void) // Call Stereo Effects 
{
drawbarside = 0;

// Start Stereo Effects  ******************************************************

   if (samfxnumber<=31)
     {
     if (samfxnumber<=15)
      {
      if (samfxnumber<=7)
       {
       if (samfxnumber<=3)
        {
        if (samfxnumber<=1)
          {
          if (samfxnumber==0)  // Stereo Reverb
              {
              Strechorng(1,0);
              }
          else   //  Stereo Reverb Only
              {
              Strechorng(2,0);
              }
          }
        if (samfxnumber>=2)
          {
          if (samfxnumber==2) //  Stereo Reverb Only Add
              {
              
              }
          else        //  Stereo Echo
		      {
		      
		      }
          }
         }
       if (samfxnumber>=4)
        {
        if (samfxnumber<=5)
          {
          if (samfxnumber==4)    //	Stereo Delay
		      {
		      
		      }
          else        //	Stereo Chorus
		      {
		      
		      }
          }
        if (samfxnumber>=6)
          {
          if (samfxnumber==6)    //  Make Stereo
		      {
		      
		      }
          else        //   Process Stereo
		      {
		      
		      }
          }
        }
       }

      if (samfxnumber>=8)
       {
       if (samfxnumber<=11)
        {
        if (samfxnumber<=9)
          {
          if (samfxnumber==8)    //   Remove Common
		      {
		      
		      }
          else        //  Swap Sides Left<->Right
		      {
		      SInterrng(3,samfxnumber);
		      }
          }
        if (samfxnumber>=10)
          {
          if (samfxnumber==10)    //  Powered Compress
		      {
		      
		      }
          else        //  Powered Expand
		      {
		      
		      }
          }
         }
       if (samfxnumber>=12)
        {
        if (samfxnumber<=13)
          {
          if (samfxnumber==12)    //  Cross Fade Left<->Right
		      {
		      Sfaderng(4,samfxnumber);
		      }
          else        //  Cross Fade Stereo Mono
		      {
		      Sfaderng(5,samfxnumber);
		      }
          }
        if (samfxnumber>=14)
           {
          if (samfxnumber==14)    //  Cross Fade Ping Pong
		      {
		      
		      }
          else        //  Pan Manual
		      {
		      Sfaderng(0,samfxnumber);
		      }
         }
        }
       }
      }

     if (samfxnumber>=16)
      {
      if (samfxnumber<=23)
       {
       if (samfxnumber<=19)
        {
        if (samfxnumber<=17)
          {
          if (samfxnumber==16)    //  Pan Ping Pong
		      {
		      Sfaderng(3,samfxnumber);
		      }
          else        //  Pan Mono Left
		      {
		      Sfaderng(1,samfxnumber);
		      }
          }
        if (samfxnumber>=18) 
          {
          if (samfxnumber==18)    //  Pan Mono Right
		      {
		      Sfaderng(2,samfxnumber);
		      }
          else        //  Pan Mono Ping Pong
		      {
		      
		      }
          }
         }
       if (samfxnumber>=20)
        {
        if (samfxnumber<=21)
          {
          if (samfxnumber==20)    //  Pan Reverse Mono
		      {
		      
		      }
          else        //  Walk
		      {
		      
		      }
          }
        if (samfxnumber>=22)
          {
          if (samfxnumber==22)    //  Walk Ping Pong
		      {
		      
		      }
          else        //  Walk Cross
		      {
		      
		      }
          }
        }
       }

      if (samfxnumber>=24)
       {
       if (samfxnumber<=27)
        {
        if (samfxnumber<=25)
          {
          if (samfxnumber==24)    //  Walk Cross Ping Pong
		      {
		      
		      }
          else        //  Walk Mono
		      {
		      
		      }
          }
        if (samfxnumber>=26)
          {
          if (samfxnumber==26)    //  Walk Mono Ping Pong
		      {
		      
		      }
          else        //  Left to Stereo
		      {
		      
		      }
          }
         }
       if (samfxnumber>=28)
        {
        if (samfxnumber<=29)
          {
          if (samfxnumber==28)    //  Right to Stereo
		      {
		      
		      }
          else        //  Stereo to Mono
		      {
		      
		      }
          }
        if (samfxnumber>=30)
          {
          if (samfxnumber==30)    //  Stereo to Left
		      {
		      
		      }
          else        //  Stereo to Right
		      {
		      
		      }
          }
        }
       }
      }
     }

    if (samfxnumber>=32)
     {
     if (samfxnumber<=47)
      {
      if (samfxnumber<=39)
       {
       if (samfxnumber<=35)
        {
        if (samfxnumber<=33) 
          {
          if (samfxnumber==32)    //  Process Wide Narrow Wide
		      {
		      
		      }
          else        //  Process Narrow Wide Narrow
		      {
		      
		      }
          }
        if (samfxnumber>=34)
          {
          if (samfxnumber==34)    //  Process Ping Pong
		      {
		      
		      }
          else        //  Add
		      {
		      SArithrng(0,samfxnumber);
		      }
          }
         }
       if (samfxnumber>=36) 
        {
        if (samfxnumber<=37)
          {
          if (samfxnumber==36) //	Subtract
              {
              SArithrng(1,samfxnumber);
              }
          else   // 	Backwards Subtract
              {
              SArithrng(2,samfxnumber);
              }
          }
        if (samfxnumber>=38)
          {
          if (samfxnumber==38) //	Multiply
              {
              SArithrng(3,samfxnumber);
              }
          else   // 	Divide
              {
              SArithrng(4,samfxnumber);
              }
          }
        }
       }
      if (samfxnumber>=40)
       {
       if (samfxnumber<=43)
        {
        if (samfxnumber<=41)
          {
          if (samfxnumber==40) //	Backwards Divide
              {
              SArithrng(5,samfxnumber);
              }
          else   // 	AND
              {
              SArithrng(6,samfxnumber);
              }
          }
        if (samfxnumber>=42)
          {
          if (samfxnumber==42) //	OR
              {
              SArithrng(7,samfxnumber);
              }
          else   // 	XOR
              {
              SArithrng(8,samfxnumber);
              }
          }
         }
       if (samfxnumber>=44)
        {
        if (samfxnumber<=45)
          {
          if (samfxnumber==44) //	Greater
              {
              SArithrng(9,samfxnumber);
              }
          else   // 	Lesser
              {
              SArithrng(10,samfxnumber);
              }
          }
        if (samfxnumber>=46)
          {
          if (samfxnumber==46) //	Interleave
              {
              SInterrng(0,samfxnumber);
              }
          else   // 	Modulus
              {
              SArithrng(11,samfxnumber);
              }
          }
        }
       }
      }

     if (samfxnumber>=48)
      {
      if (samfxnumber<=55)
       {
       if (samfxnumber<=51)
        {
        if (samfxnumber<=49)
          {
          if (samfxnumber==48) //	Backwards Modulus
              {
              SArithrng(12,samfxnumber);
              }
          else   // 	Stutter
              {
              SInterrng(1,samfxnumber);
              }
          }
        if (samfxnumber>=50)
          {
          if (samfxnumber==50) //	Rectify
              {
              SInterrng(2,samfxnumber);
              }
          else   // 	Rectify and Add
              {
              
              }
          }
        }
       if (samfxnumber>=52)
        {
        if (samfxnumber<=53)
          {
          if (samfxnumber==52) //	Within
              {
              
              }
          else   // 	Without
              {
              
              }
          }
        if (samfxnumber>=54)
          {
          if (samfxnumber==54) //	Comparator
              {
              
              }
          else   // 	Magnitude Difference
              {
              
              }
          }
        }
       }

      if (samfxnumber>=56)
       {
       if (samfxnumber<=59)
        {
        if (samfxnumber<=57)
          {
          if (samfxnumber==56) //	
              {
              
              }
          else   // 	
              {
              
              }
          }
        if (samfxnumber>=58)
          {
          if (samfxnumber==58) //	
              {
              
              }
          else   // 	
              {
              
              }
          }
         }
       if (samfxnumber>=60)
        {
        if (samfxnumber<=61)
          {
          if (samfxnumber==60) //	
              {
              
              }
          else   // 	
              {
              
              }
          }
        if (samfxnumber>=62)
          {
          if (samfxnumber==62) //	
              {
              
              }
          else   // 	
              {
              
              }
          }
        }
       }
      }
     }

// End Stereo Effects *************************************************** 
}
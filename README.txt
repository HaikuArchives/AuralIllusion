Aural illusion v4.0


					Quick Docs

***********************************************

The History of Aural illusion 

A long time ago in a country far far away...

I once wrote a program called Aural illusion for the Amiga,  this was released and sold
commercally.
This was a 16 bit Audio editor and processor, which was unusual as the Amiga only had 8 bit sound.

Aural illusion was then enhanced and updated and it became v2.0 which was also released.
Then I got bored writing effects and inspired by an article in Future Music I wrote
a Modular Synthesizer called Aural Synthetica, this too was before PC Synthersizer 
programs appeared on the PC.

These programs were both later given away on the cover of Amiga Computing magazine.
Both were also released under the GPL and can be found at:
http://www.blachford.freeuk.com

Then I decided Aural illusion being my first C program of any size was getting messy and was
due a re-write so I set about writing Aural illusion v3.0 from Scratch.
This was a much cleaner design with many more effects and a much improved user interface.
This project was stopped and started many times and eventually when 80% complete was
abandoned in favor of a BeOS version.

The BeOS version had many, many Effects added to it and had to be largely re-structured 
as it was now being written in C++.  Anyone looking at the source will see I'm not expert at C++ :-(


You know how they say how you should go out and do stuff because the world wont come to you?
How like, you shouldn't wait beside the phone because it's never going to ring?
Well, it did and after an interview consisting of drinking and going to restraunts I got a Job in Holland.

The one thing you find when you get a full time job programming is that when you get home the last thing you to do is start programming,  So Aural illusion v4.0 by this time largely complete was put on hold and pretty much sat there until I finally decided that it would be better out there doing nothing than sitting here doing nothing.
So Aural illusion is now being released as Open Source software.  It is not being released under the GPL as I





***********************************************
						BUGS
Set Font size
Zone display
Some zone copying ops may leak into wrong area?
Loading/Saving - 
- File Name - when saving these are F*cked up something rotton
- glitchs
- resolution problem.
bottom line of sample display
Some filter FX louder on right hand side
Range display sometimes fouls up, shows area before rage and refuses to show area after.

***********************************************
						TODO
Loop Window
Record Window

DMAN - Powered Expand (use a zone to Expand an area)
DMAN - Powered Compress (use a zone to compress an area)

Audio Playback Mono/Stereo + display
Audio Record Mono/Stereo + display

Zone Move - Finish
Zone Display - Debug
Load - AIFF / WAV / AU / SAFF / IFF
Save - AIFF / WAV / AU / SAFF / IFF

Copy/Paste to/from clipboard
Record Window
Loop Window/Display

Progress Display (Done in many cases)
Effects Defaults (Done in many cases)
Attractor Display - Finish (Probably needs a BeBitmap or something like that,
too slow to draw dynamically).


Messages - Best used on Simple sound / any sound

***********************************************
Aural illusion Jr	Full	TODO

Some FX:
Reverse
Echo
Fade In
Fade Out
Centre
Move +/-
Auto Stutter
SwapByteOrder
Noise
Chaos

Add
Multiply
AND
OR

***********************************************
Aural illusion v4.1	Full	TODO - subject to change at any time for no apparent reason

I feel the need, the need, for speed - remove int-uint compares
Convert EQs to FP ???
More FX
Wave Generator window with note, octave etc.
Frequency Spectrum Display (RT ?)

***********************************************

***********************************************



16th July 1999		35189 lines
17th september 1999	48867
1st October 1999		50474

N.Blachford 1/7/99

A lot if this isn't working yet and what is working is riddled with bugs!
There are something like 250 Effects selectable but only about 175 will do anything and a lot of them crash due to reading illegal addresses, this isn't difficut to fix, I've already fixed quite a few.  A large number of currently present effects will be removed prior to v4.0 release but will reappear later.

--

To create a sound select Manips 2 on the Effects window
Then scroll down, select Chaos and press either of the GO buttons
You can also select Noise but you need to move the Level slider up before selecting GO.
Random also creates sounds.



----------------

SAMPLE DISPLAY
Zone display is buggy.
Resizing after a zoom can cause display to jump.
Menus:
ZERO ALL - Zeros the sample buffer - very quickly.
OPEN - opens a 16 bit stereo audio file, if a normal file loads in as garbage try Manips 2 - SwapByteOrder.
SAVE - does nothing
SAVE - Saves a 16 bit stereo audio file. r4.5 can no longer read these for some reason so load them into BamBam for playback. NOTE: SAVING currently trashes the sample and undo buffers, you will *have* to reload after saving.
SAVE AS - not working.
ABOUT - Display About box
QUIT - quits instantly - will display box at release.
temp1 - temp5  - not working.
Attractor Display - Opens window, see below

EDITS
GO - Executes current effect
UNDO/REDO - un/redoes it.  NOTE changing the range/view/view mode does not effect what is un/redone.  
>< - Zoom in - to cursr
< > - Zoom Out
|< - Show Start
<< Backwards through view fast
< Backwards through view
> Forwards through view fast
>> Forwards through view fast
>| Show End
Loop - not working
Progress - This tends to lie! Only some effects use this properly.

Set Zone - Sets the current range as a Zone
Zone Over - Copies the current zone over the data at the current cursr / start of range.
Zone Into - Copies the current zone Into the data at the current cursr / start of range.
Zone Move - Moves the current zone Into the data at the current cursr / start of range.

Cut - Cuts current range - NOTE this does NOT move any data to the clipboard.
Copy/PasteOver/Paste Into - not working.

Play View/Range/All/Loop - not working, you have to save and play in BamBam!

Show Range - Shows current range
Show All - Shows entire sample.
Range All - Selects the current view as a range
Redraw - Redraws display & attractor if present.

L>R - Copies range Left to right
R>L - Copies range Right to Left
Zero - Zeros range
Rescale (scales range to max vol possible without distortion)
Scale (Scales range to value set in % slider)

Scale Level x% - used by above
PlayRate xxKHz - not working.
Magnify - magnifies display, has no effect on audio.
Left/Right/Stereo/Mono - selects display mode, in Mono mode the left channel is the first half.

WORKING EFFECTS:
NOTE effecta-effectq means the 2 and all in between are working


STANDARD EFFECTS:
Reverb
Echo
Delay
Phase Shift - don't set Repeats too high - can be very slow.
Phaser
Chorus
Flange
Distortion
Compress 
Expand
Enhance
Fade
Resolution
Bandwidth
Alternate
Filter Low Pass
Filter High Pass
Filter Band Pass
Filter Band Cut
Filter Notch Pass
Filter Notch Cut
Backwards Reverb
Reverb Phaser
Long Delay
Multi-Tap Delay
Feedback Delay
Bounce Delay
Jump Flange
Digital Distortion
Contortion
Mix Contortion
Bandwidth Smooth

COMPLEX EFFECTS
1/x
acos
asin
atan
cos
sin
tan
cosh
sinh
tanh
acosh
asinh
atanh
sec
cosec
Cot
+Sin
exp
log
log10
expm1
log1p
logb
+Log
sqrt
cbrt
ceil
fabs
floor
significand
j0
j1
y0
y1
erf
erfc
gamma
lgamma
rint
ilogbf

MANIPS 1
Invert-Reverse
Quarter Value - Fade Out
Tune - Select Down.
Zero Out
More +/- Don't know!
Auto Stutter
Half Distortion
Half Contortion

MANIPS 2
Over - Add Spikes
Capacitance - Half Square
Transofrm Blocks - Reverse All Blocks
Unorder Samples
Filp Alternate
Random Amplifier
Swap Halves ?
Remove Centre
Add Centre
Remove Flat
Keep Flat
Remove Middle
Transmogrify
Non-Transmogrify
Delay-Delta (Keep Delay at 0)
Noise (move level above zero to create something)
Chaos
Random

DUAL EFFECTS
NOTE - select a zone and a different range, dual uses both as inputs and places output into range. 
Powered Compress - Backwards Modulus
Amplitude modulation

STEREO EFFECTS
NOTE - 
Swap Sides
Cross Fade Left<->Right
Pan Manual
Pan Ping Pong
Add
Subtract
Backwards Subtract
Multiply
AND
OR
XOR
Greater
Lesser
Interleave
Modulus
Stutter
Rectify


ATTRACTOR DISPLAY
LINES - selects between lines and points
INVERT - inverts display.
NOTE: This is SLOW! a max of 25000 points can be drawn or 50000 lines, you normally need much less.  This is redrawn everytime a range is selected or an effect/edit is completed.
Use Pulse to see if it has completed.  If a number of redraws are to be done they willl be done in order, the program can become very erratic if this happens.

COOL DISPLAYS WITH THE ATTRACTOR
select a range of 25000 samples then use Manips 2 - Chaos.
This draws a perfect curve but sounds just like noise!
Use Manip 1 - Reverse and the curve is rotated 90 degrees.
Undo the reverse then change the Mix Level to 128 and press GO again (not redo).
weird enough?  now press GO again...  changing the Add/Subtract and Mix level produces variations.

Setting Chaos with different values for the sliders will produce the same curve which still sounds like noise but the waveform is different, try ANDing 2 of them together.
For some real fun fade in one and fade out the other then OR them (remember to set the level sliders to 256), it will draw a strange shape but I couldn't program an animation like that!!!



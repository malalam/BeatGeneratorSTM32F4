# BeatGeneratorSTM32F4

##Programmable Beat Generator for the STM32F4 Discovery Board
- Application files in Copatone SPA-32 Folder
  - Refer to the following files for implementation details: `accel.c`,`playback.c`,`speaker.c`,`main`,`lab4p2.c`,`lab4p3.c` and the corresponding header files.   
  
## How it works:
- Load the files onto STM32F4 Discovery Board using (https://www.keil.com/demo/eval/arm.htm)[Keil IDE].
- After loading, should see a signal that the board is now recording in the Keil IDE (note: can use the onboard button to reset timer and start recording again).
- Shake the board for the desired beat for 8 seconds.
- Board will immediately start playing the beat generated using built 

# BeatGeneratorSTM32F4

##Programmable Beat Generator for the STM32F4 Discovery Board
- Application files in Copatone SPA-32 Folder
  - Refer to the following files for implementation details: `accel.c`,`playback.c`,`speaker.c`,`main`,`lab4p2.c`,`lab4p3.c` and the corresponding header files.   
  
## How it works:
- Load the files onto STM32F4 Discovery Board using [Keil IDE](https://www.keil.com/demo/eval/arm.htm).
- After loading, should see a signal that the board is now recording in the Keil IDE (note: can use the onboard button to reset timer and start recording again).
- Shake the board for the desired beat for 8 seconds.
- Board will immediately start playing the beat generated through the audio jack.
- The generated 8 second beat will continue to replay until stopped using the onboard button. 
- To generate a new beat, simply press the onboard button again and the timer will reset. 

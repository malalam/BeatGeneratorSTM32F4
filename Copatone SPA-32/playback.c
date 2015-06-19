#include <stdio.h>
#include <stdlib.h>
#define ARM_MATH_CM4
#include <arm_math.h>
#include <math.h>

#include "stm32f4xx.h"
#include "speaker.h"

extern volatile uint32_t msTicks;



void playSample(int volume){
	static int frequency = 500;
	uint32_t initialT = msTicks;
	int16_t audio_sample;
	printf("play %i, at %i\n", volume, msTicks);
	
	//STATIC LED FLAG = 0
	
	if(frequency ==3000){
		while (initialT + 88 > msTicks){
			send_to_speaker(volume*(-.3f));
			float t = msTicks / 1000.0; // calculate time -- SysTick is configured for 0.1 ms
			audio_sample = (int16_t) 30 + (.8f*volume*(.3f + arm_sin_f32(frequency*t))); // calculate one sample for the speaker
			// the CMSIS arm_sin_f32 function from arm_math.h is typically faster than sin() from math.h
			send_to_speaker(audio_sample);	// send one audio sample to the audio output
		}
	}
		
	else{
		while (initialT + 150 > msTicks){
			float t = msTicks / 1000.0; // calculate time -- SysTick is configured for 0.1 ms
			audio_sample = (int16_t) (volume*arm_sin_f32(frequency*t)); // calculate one sample for the speaker
			// the CMSIS arm_sin_f32 function from arm_math.h is typically faster than sin() from math.h
			send_to_speaker(audio_sample);	// send one audio sample to the audio output
		}
	}
		
	if(frequency == 500) frequency = 3000;
	else frequency = 500;
}


void playArray(int *arr, int size){
  uint32_t lastPlay = msTicks;
	int count = 0;
	while(1){
		if( lastPlay + 250 <= msTicks){
			lastPlay = msTicks;
			printf("calling %i", count);
			playSample(arr[count]);
			count++;
			if (count >=size) count = 0;  //if at end of arr, loopback
		
		}//endif
		else {send_to_speaker(0);}
		
	
	} //end while

}

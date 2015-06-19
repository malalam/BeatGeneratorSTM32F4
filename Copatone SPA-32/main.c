#include <stdio.h>
#include <stdlib.h>

#include "stm32f4xx.h"
#include "tm_stm32f4_lis302dl_lis3dsh.h"

#include "accel.h"
#include "speaker.h"
#include "playback.h"



volatile uint32_t msTicks = 0;                      /* counts 1ms timeTicks       */

// SysTick Handler (Interrupt Service Routine for the System Tick interrupt)
void SysTick_Handler(void){
  msTicks++;
}

// initialize the system tick 
void InitSystick(void){
	SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
  if (SysTick_Config(SystemCoreClock / 1000)) { /* SysTick 1 msec interrupts  */
    while (1);                                  /* Capture error              */
  }
}

int32_t main( void ) {
	printf("#  1\n");
//	InitLEDPins();  //LED off intitally
	uint32_t msPrev = 0;
	TM_LIS302DL_LIS3DSH_t init_axes_data;
	TM_LIS302DL_LIS3DSH_t axes_data;
	int orig_magnitude;
	int magnitude;
	
	int sound_data[32];	//holds value used every 250ms for a total of 8 seconds of beats
	int accel_magnitude_sum = 0;	//current sum used in calculating average
	int num_samples = 0;
	
	SystemInit();
	InitSystick();
	
	/* Initialize LIS302DL */
  TM_LIS302DL_LIS3DSH_Init(TM_LIS3DSH_Sensitivity_2G, TM_LIS3DSH_Filter_50Hz);
	TM_LIS302DL_LIS3DSH_ReadAxes(&init_axes_data);
	orig_magnitude = get_magnitude( &init_axes_data );
	
	
	//wait 2 seconds before getting beat data
	int countin = 1;
	uint32_t countintimer ;
	
	while (1) {
		if (msTicks >= 500 && countin ==1 ) {printf("#  2\n"); countin++;}
		if (msTicks >= 100 && countin ==2 ) {printf("#  3\n"); countin++;}
		if (msTicks >= 1500 && countin ==3 ) {printf("#  4\n"); countin++;}
		if (msTicks >= 2000) {
			break;
		}
	}

	//main loop for loading beat array
	while (1) {
		
		if ((msTicks - msPrev) >= 25) {
			//IF (NUM SAMPLES % 8 == 0) SET LED ON
		if (num_samples%8 ==0) printf("\n## [ %i ] ##,  ", (num_samples%32/8 +1));
			TM_LIS302DL_LIS3DSH_ReadAxes(&axes_data);
			magnitude = get_computed_magnitude( &axes_data, orig_magnitude );
			
			accel_magnitude_sum += magnitude;
			++num_samples;
			msPrev = msTicks;
			
			//after any multiple of 4 readings have been taken
			if (num_samples%4 == 0) {
				//TURN LED OFF
				sound_data[ num_samples/4 - 1] = accel_magnitude_sum/4;	//set current beat to average sensor data
				accel_magnitude_sum = 0;	//reset sum to 0	
				
				//wait for remaining 150ms of 250ms cycle
				while (1) {
					if ((msTicks - msPrev) >= 150) {
						msPrev = msTicks;
						break;
					}
				}
				
				printf( " %d", sound_data[ num_samples/4 - 1] );	
			}
		}
		
		//if 128 samples gathered, 8 seconds of data is recorded, end loop
		if ( num_samples >= 128 ) {
			break;
		}
	}
	
	printf( "\n\n" );
	convert_array_for_audio( sound_data, 32 );
	for (int i=0; i<32; ++i) {
		printf( "%d\n", sound_data[i] );
	}
	
	init_speaker();
	playArray( sound_data, 32 );

}

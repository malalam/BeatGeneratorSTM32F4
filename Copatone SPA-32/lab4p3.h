#ifndef LAB4_P3
#define LAB4_P3

#include "tm_stm32f4_lis302dl_lis3dsh.h"
#define ARM_MATH_CM4
#include "arm_math.h"

#define N_SAMPLES 10

float get_pitch_deg( TM_LIS302DL_LIS3DSH_t accel_data );
float get_roll_deg( TM_LIS302DL_LIS3DSH_t accel_data );

float returnSensorPitchAverage( float sample );
float returnSensorRollAverage( float sample );

void initSensorReadings( void );

#endif

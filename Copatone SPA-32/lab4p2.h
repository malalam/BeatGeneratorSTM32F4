#ifndef LAB4_P2
#define LAB4_P2

#include "tm_stm32f4_lis302dl_lis3dsh.h"
#define ARM_MATH_CM4
#include "arm_math.h"

float get_pitch( TM_LIS302DL_LIS3DSH_t accel_data );
float get_roll( TM_LIS302DL_LIS3DSH_t accel_data );
void print_val_in_degrees( float p, float r );

#endif

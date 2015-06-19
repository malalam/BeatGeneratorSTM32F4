#ifndef ACCEL_LIB
#define ACCEL_LIB

#include "tm_stm32f4_lis302dl_lis3dsh.h"

int get_magnitude( TM_LIS302DL_LIS3DSH_t *accel_data );
int get_computed_magnitude( TM_LIS302DL_LIS3DSH_t *accel_data, int orig_magnitude );
void convert_array_for_audio( int *sound_data, int array_len );
	
#endif

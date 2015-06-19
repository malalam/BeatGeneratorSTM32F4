#include <math.h>
#include <stdlib.h>

#include "accel.h"

//used for getting initial magnitude
int get_magnitude( TM_LIS302DL_LIS3DSH_t *accel_data ) {
	return sqrt( accel_data->X*accel_data->X + accel_data->Y*accel_data->Y + accel_data->Z*accel_data->Z );
}

//subtracts initial magnitude to obtain how fast sensor is moving
int get_computed_magnitude( TM_LIS302DL_LIS3DSH_t *accel_data, int orig_magnitude ) {
	return abs( sqrt( accel_data->X*accel_data->X + accel_data->Y*accel_data->Y + accel_data->Z*accel_data->Z ) - orig_magnitude );
}

//convert values for use by audio engine

void convert_array_for_audio( int *sound_data, int array_len ) {
	for (int i=0; i<array_len; ++i) {
		if ( (sound_data[i] <= 50) ) {
			sound_data[i] = 0;
		}
		else {
			sound_data[i] = (int)(sound_data[i]*2.8f);
		}
	}
}

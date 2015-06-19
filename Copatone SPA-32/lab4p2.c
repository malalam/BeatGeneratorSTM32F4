#include "lab4p2.h"
#include <stdio.h>
#include <math.h>


//sets value of pitch and roll in radians using accelerometer data
float get_pitch( TM_LIS302DL_LIS3DSH_t accel_data )
{
	float p = atan2(-accel_data.X, sqrt( accel_data.Y*accel_data.Y + accel_data.Z*accel_data.Z ) );
	return p;
}

float get_roll( TM_LIS302DL_LIS3DSH_t accel_data )
{
	float r = atan2( accel_data.Y, accel_data.Z );
	return r;
}

//gets two values in radians and prints out value in degrees
void print_val_in_degrees( float p, float r )
{
	float pitch_deg = p*180/PI;
	float pitch_roll = r*180/PI;
	printf( "Pitch: %f\t\tRoll: %f\n", pitch_deg, pitch_roll );
}

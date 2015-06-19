#include "lab4p3.h"
#include <stdio.h>
#include <math.h>

float sensor_readings_pitch[N_SAMPLES];
float sensor_readings_roll[N_SAMPLES];
static int num_readings = 0;

//sets value of pitch and roll in radians using accelerometer data
float get_pitch_deg( TM_LIS302DL_LIS3DSH_t accel_data )
{
	float p = atan2(-accel_data.X, sqrt( accel_data.Y*accel_data.Y + accel_data.Z*accel_data.Z ) );
	return p*180/PI;
}

float get_roll_deg( TM_LIS302DL_LIS3DSH_t accel_data )
{
	float r = atan2( accel_data.Y, accel_data.Z );
	++num_readings;
	return r*180/PI;
}

float returnSensorPitchAverage( float sample ) {
	int flag = 0;
	float array_sum = 0;
	if (num_readings < N_SAMPLES) {
		sensor_readings_pitch[num_readings] = sample;
	}
	else {
		sensor_readings_pitch[num_readings%N_SAMPLES] = sample;
	}
	for (int i=0; i<N_SAMPLES; ++i) {
		if (i<num_readings) {
			array_sum += sensor_readings_pitch[i];
		}
		else {
			flag = i;
			break;
		}
	}
	if (flag == 0) {
		return array_sum/N_SAMPLES;
	}
	else {
		return array_sum/flag;
	}
}
	
float returnSensorRollAverage( float sample ) {
	int flag = 0;
	float array_sum = 0;
	if (num_readings < N_SAMPLES) {
		sensor_readings_roll[num_readings] = sample;
	}
	else {
		sensor_readings_roll[num_readings%N_SAMPLES] = sample;
	}
	for (int i=0; i<N_SAMPLES; ++i) {
		if (i<num_readings) {
			array_sum += sensor_readings_roll[i];
		}
		else {
			flag = i;
			break;
		}
	}
	if (flag == 0) {
		return array_sum/N_SAMPLES;
	}
	else {
		return array_sum/flag;
	}
}
	
void initSensorReadings() {
	for ( int i=0; i<N_SAMPLES; ++i ) {
		sensor_readings_pitch[i] = 0;
		sensor_readings_roll[i] = 0;
	}
}

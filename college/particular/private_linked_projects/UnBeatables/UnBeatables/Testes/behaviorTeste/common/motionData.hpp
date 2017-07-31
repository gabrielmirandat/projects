/*
* Struct to save relevant motion information in shared memory.
*/
typedef struct {

    float x_vel;
    float y_vel;
    float theta;
    float turn_time;	
    
} motionData;
#include <iostream>
#include "mpu9150.h"
#include "SignalHandler.h"

using namespace std;

Sensors::MPU9150 imu( 1 );

#define A_GAIN        6.103515625e-05
#define IMUPI_G_GAIN  0.030487804878049
#define IMUPI_M_GAIN  0.3001221001221001

int main()
{
    int ret;

    // Wake up the IMU
    imu.Sleep( false );

    short whoami = imu.WhoAmI();
    cout << "Who Am I: 0x" << hex << whoami << endl;

    try
    {
        SignalHandler sigHandler;

        // Register signal handler to handle kill signal
        sigHandler.SetupSignalHandlers();

        while( !sigHandler.GotExitSignal() )
        {
            if( imu.DataReady() )
            {
                float accel_x = imu.GetAccelerometerX() * A_GAIN;
                float accel_y = imu.GetAccelerometerY() * A_GAIN;
                float accel_z = imu.GetAccelerometerZ() * A_GAIN;
                cout << "Accel X: " << accel_x
                     << " | Accel Y: " << accel_y
                     << " | Accel Z: " << accel_z << endl;
            }
            usleep( 1000 );
        }

        ret = EXIT_SUCCESS;
    }
    catch(SignalException& e)
    {
        cerr << "SignalException: " << e.what() << endl;
        ret = EXIT_FAILURE;
    }

    return ret;
}


#include <iostream>
#include "mpu9150.h"
#include "SignalHandler.h"

using namespace std;

Sensors::MPU9150 imu( 1 );

int main()
{
    int ret;

    // Wake up the IMU
    imu.WakeUp();

    short whoami = imu.WhoAmI();
    cout << "Who Am I: 0x" << hex << whoami << endl;

    try
    {
        SignalHandler sigHandler;

        // Register signal handler to handle kill signal
        sigHandler.SetupSignalHandlers();

        while( !sigHandler.GotExitSignal() )
        {
            short accel_x = imu.GetAccelerometerX();
            cout << "Accel X: " << hex << accel_x << endl;
            usleep( 10000 );
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


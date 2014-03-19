#include <iostream>
#include "mpu9150.h"

using namespace std;

int main()
{
    Sensors::MPU9150 imu(1);

    // Wake up the IMU
    uint8_t whoami = imu.WhoAmI();
    cout << "Who Am I: 0x" << hex << whoami << endl;

    return 0;
}


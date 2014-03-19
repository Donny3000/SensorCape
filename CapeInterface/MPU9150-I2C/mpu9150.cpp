#include "mpu9150.h"

using namespace Sensors;

MPU9150::MPU9150(const __u8 bus, const __u16 address)
{
    I2CInterface::Instance()->OpenI2CInterface( bus );
    I2CInterface::Instance()->SetDeviceAddress( address );
}

MPU9150::~MPU9150()
{
}

void MPU9150::WakeUp()
{
    // Clear the 'sleep' bit
    I2CInterface::Instance()->write8(MPU9150_PWR_MGMT_1, 0);
}

__u8 MPU9150::WhoAmI()
{
    return I2CInterface::Instance()->read8(MPU9150_WHO_AM_I);
}

__u16 MPU9150::GetAccelerometerX()
{
    return (I2CInterface::Instance()->read8(MPU9150_ACCEL_XOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_ACCEL_XOUT_L);
}

__u16 MPU9150::GetAccelerometerY()
{
    return (I2CInterface::Instance()->read8(MPU9150_ACCEL_YOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_ACCEL_YOUT_L);
}

__u16 MPU9150::GetAccelerometerZ()
{
    return (I2CInterface::Instance()->read8(MPU9150_ACCEL_ZOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_ACCEL_ZOUT_L);
}

__u16 MPU9150::GetGyroscopeX()
{
    return (I2CInterface::Instance()->read8(MPU9150_GYRO_XOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_GYRO_XOUT_L);
}

__u16 MPU9150::GetGyroscopeY()
{
    return (I2CInterface::Instance()->read8(MPU9150_GYRO_YOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_GYRO_YOUT_L);
}

__u16 MPU9150::GetGyroscopeZ()
{
    return (I2CInterface::Instance()->read8(MPU9150_GYRO_ZOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_GYRO_ZOUT_L);
}

__u16 MPU9150::GetCompassX()
{
    return (I2CInterface::Instance()->read8(MPU9150_CMPS_XOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_CMPS_XOUT_L);
}

__u16 MPU9150::GetCompassY()
{
    return (I2CInterface::Instance()->read8(MPU9150_CMPS_YOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_CMPS_YOUT_L);
}

__u16 MPU9150::GetCompassZ()
{
    return (I2CInterface::Instance()->read8(MPU9150_CMPS_ZOUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_CMPS_ZOUT_L);
}

__u16 MPU9150::GetTemp()
{
    return (I2CInterface::Instance()->read8(MPU9150_TEMP_OUT_H) << 8) |
            I2CInterface::Instance()->read8(MPU9150_TEMP_OUT_L);
}

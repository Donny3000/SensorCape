#include "I2CInterface.h"

namespace Sensors
{
    std::string IntToHex(int i)
    {
        std::stringstream s;
        s << std::hex << std::showbase << i;
        return s.str();
    }

    //! Global object for invalid address exceptions
    static BadAddress InvalidDeviceAddress;

    /*!
     * \brief I2CInterface::Instance - This function is called to create an
     *        instance of the I2CInterface Class. Calling the constuctor
     *        publicly is not allowed. The constructor is private and is only
     *        called by this Instance function.
     * \return Pointer to the single I2CInterface object.
     */
    I2CInterface *I2CInterface::Instance()
    {
        static I2CInterface instance;
        return &instance;
    }

    I2CInterface::I2CInterface() :
        mPreviousAddr(0)
    {
    }

    I2CInterface::~I2CInterface()
    {
        closeConnection();
    }

    bool I2CInterface::OpenI2CInterface(const __u8 busNum)
    {
        if( mFile )
            return true;

        mDevice = "/dev/i2c-" + std::to_string(busNum);
        mFile = open(mDevice.c_str(), O_RDWR);
        if(mFile < 0)
        {
            std::cerr << "Failed to open I2C device" << mDevice << std::endl;
            return false;
        }

        return true;
    }

    bool I2CInterface::closeConnection()
    {
        if( mFile )
        {
            if(close(mFile) < 0)
                return false;
            mFile = 0;
        }

        return true;
    }

    bool I2CInterface::SetDeviceAddress(const __u16 address)
    {
        if(address == 0)
            throw InvalidDeviceAddress;
        if(address == mPreviousAddr)
            return true;

        if(ioctl(mFile, I2C_SLAVE, address) < 0)
        {
            std::cerr << "Failed to get IOCTL interface for I2C device" << mDevice << std::endl;
            return false;
        }
        else
        {
            return true;
        }
    }

    __s32 I2CInterface::read8(const __u16 deviceAddr, const __u8 reg)
    {
        __s32 res = -1;

        if( SetDeviceAddress( deviceAddr ) )
        {
            mRead8Mutex.lock();
            if((res = i2c_smbus_read_byte_data(mFile, reg)) < 0)
                std::cerr << "Failed to read from i2c address " << IntToHex(reg) << std::endl;
            else
                res &= 0xFF;
            mRead8Mutex.unlock();
        }

        return res;
    }

    __s32 I2CInterface::write8(const __u16 deviceAddr, const __u8 reg, __u8 data)
    {
        __s32 res = -1;

        if( SetDeviceAddress( deviceAddr ) )
        {
            mWrite8Mutex.lock();
            if((res = i2c_smbus_write_byte_data(mFile, reg, data)) < 0)
                std::cerr << "Failed to write to i2c address " << IntToHex(reg) << std::endl;
            mWrite8Mutex.unlock();
        }

        return res;
    }

    __s32 I2CInterface::read16(const __u16 deviceAddr, const __u8 reg)
    {
        __s32 res = -1;

        if( SetDeviceAddress( deviceAddr ) )
        {
            mRead16Mutex.lock();
            if((res = i2c_smbus_read_word_data(mFile, reg)) < 0)
                std::cerr << "Failed to read from i2c address " << IntToHex(reg) << std::endl;
            else
                res &= 0xFFFF;
            mRead16Mutex.unlock();
        }

        return res;
    }

    __s32 I2CInterface::write16(const __u16 deviceAddr, const __u8 reg, __u16 data)
    {
        __s32 res = -1;

        if( SetDeviceAddress( deviceAddr ) )
        {
            mWrite16Mutex.lock();
            if((res = i2c_smbus_write_word_data(mFile, reg, data)) < 0)
                std::cerr << "Failed to write to i2c address " << IntToHex(reg) << std::endl;
            mWrite16Mutex.unlock();
        }

        return res;
    }

} /* namespace Sensors */

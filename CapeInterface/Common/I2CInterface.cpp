#include "I2CInterface.h"

namespace Sensors
{
    std::string IntToHex(int i)
    {
        std::stringstream s;
        s << std::hex << std::showbase << i;
        return s.str();
    }

    //! Global static pointer used to ensure a single instance of the class
    I2CInterface *I2CInterface::mI2CInterfaceInstance = nullptr;

    /*!
     * \brief I2CInterface::Instance - This function is called to create an
     *        instance of the I2CInterface Class. Calling the constuctor
     *        publicly is not allowed. The constructor is private and is only
     *        called by this Instance function.
     * \return Pointer to the single I2CInterface object.
     */
    I2CInterface *I2CInterface::Instance()
    {
        if( !mI2CInterfaceInstance )
            mI2CInterfaceInstance = new I2CInterface();

        return mI2CInterfaceInstance;
    }

    I2CInterface::I2CInterface() :
        mAddressSet(false)
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
        if(ioctl(mFile, I2C_SLAVE, address) < 0)
        {
            std::cerr << "Failed to get IOCTL interface for I2C device" << mDevice << std::endl;
            mAddressSet = false;
        }
        else
        {
            mAddressSet = true;
        }

        return mAddressSet;
    }

    __s8 I2CInterface::read8(const __u8 reg)
    {
        __s8 res = -1;

        if( mAddressSet )
        {
            if((res = i2c_smbus_read_byte_data(mFile, reg)) < 0)
                std::cerr << "Failed to read from i2c address " << IntToHex(reg) << std::endl;
            else
                res &= 0xFF;
        }

        return res;
    }

    __s32 I2CInterface::write8(const __u8 reg, __u8 data)
    {
        __s32 res = -1;

        if( mAddressSet )
        {
            if((res = i2c_smbus_write_byte_data(mFile, reg, data)) < 0)
                std::cerr << "Failed to write to i2c address " << IntToHex(reg) << std::endl;
        }

        return res;
    }

    __s16 I2CInterface::read16(const __u8 reg)
    {
        __s16 res = -1;

        if( mAddressSet )
        {
            if((res = i2c_smbus_read_word_data(mFile, reg)) < 0)
                std::cerr << "Failed to read from i2c address " << IntToHex(reg) << std::endl;
            else
                res &= 0xFFFF;
        }

        return res;
    }

    __s32 I2CInterface::write16(const __u8 reg, __u16 data)
    {
        __s32 res = -1;

        if( mAddressSet )
        {
            if((res = i2c_smbus_write_word_data(mFile, reg, data)) < 0)
                std::cerr << "Failed to write to i2c address " << IntToHex(reg) << std::endl;
        }

        return res;
    }

} /* namespace Sensors */

#ifndef I2CINTERFACE_H
#define I2CINTERFACE_H

#include <iostream>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>

namespace Sensors
{
    /*!
     * \brief IntToHex - Basic function to turn intergers into hexadecimal strings
     * \param i Integer to convert
     * \return std::string of texified integer
     */
    std::string IntToHex(int i);

    /*!
     * \brief The I2CInterface class - This class provides an I2C interface to
     *        a device on an I2C bus. This class is implemented as a singleton
     *        so that only one object has read/write access to the I2C bus.
     */
    class I2CInterface
    {
        public:
            static I2CInterface* Instance();
            bool OpenI2CInterface(const __u8 busNum);

            //! Set the device to read/write to/from
            //! \param address - The address of the device on the bus
            bool SetDeviceAddress(const __u16 address);

            //! Basic methods to read/write data to/from a device on the bus
            //! \{
            __s32 read8(const __u8 reg);
            __s32 write8(const __u8 reg, __u8 data);
            __s32 read16(const __u8 reg);
            __s32 write16(const __u8 reg, __u16 data);
            //! \}

            static I2CInterface *mI2CInterfaceInstance;

        private:
            //! Since this is a singleton, we hide the constuctors and assignment operators
            //! \{
            I2CInterface();
            virtual ~I2CInterface();
            //! \}

            bool closeConnection();

            //! Begin private member variable declarations
            bool                mAddressSet;
            int                 mFile;
            std::string         mDevice;
    };

} /* namespace Sensors */

#endif // I2CINTERFACE_H

/*
 * i2c.h
 *
 *  Created on: Mar 17, 2014
 *      Author: Donald R. Poole, Jr.
 */

#ifndef I2C_H_
#define I2C_H_

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
     * Class: I2C - Class to read/write to an I2C bus device
     *
     * \param bus - The I2C bus number to instantiate a session on
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
            __s8 read8(const __u8 reg);
            __s32 write8(const __u8 reg, __u8 data);
            __s16 read16(const __u8 reg);
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
#endif /* I2C_H_ */

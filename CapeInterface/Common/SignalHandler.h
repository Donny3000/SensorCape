#ifndef __SIGNALHANDLER_H__
#define __SIGNALHANDLER_H_

#include <stdexcept>
#include <signal.h>
#include <errno.h>

using std::runtime_error;

class SignalException : public runtime_error
{
    public:
        SignalException(const std::string& _message) :
            std::runtime_error(_message) {}
};

class SignalHandler
{
    public:
        SignalHandler();
        ~SignalHandler();

        static bool GotExitSignal();
        static void SetExitSignal(bool _bExitSignal);

        void SetupSignalHandlers();
        static void ExitSignalHandler(int _ignored);

    protected:
        static bool mbGotExitSignal;
};
#endif

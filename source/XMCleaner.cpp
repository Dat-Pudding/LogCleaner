#include "Core.h"

int main(int argc, char* argv[])
{
    XMCleaner::Core app;
    if (app.Init())
    {
        if (app.Run(argc, argv))
        {
            app.Stop();
            return 0;
        }
        else
        {
            XMCleaner::Messenger messenger;
            messenger.ErrorMsg_Generic();
            return 1;
        }
    }
}

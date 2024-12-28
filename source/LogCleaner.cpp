#include "Core.h"

int main(int argc, char* argv[])
{
    XMCleaner app;
    if (app::Core.Init())
    {
       if (app::Core.Run(argc, argv[]))
       {
           app::Core.Stop();
           return 0;
       }
       else
       {
           app::Messenger.ErrorMsg_Generic();
           return 1;
       }
    }
}

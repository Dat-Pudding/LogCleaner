namespace XMCleaner
{
public:
    class Core
    {
    public:
        bool Init();
        bool Run(int, char*);
        void Stop();
    }
    class IO_Utility
    {
    
    }
    class Messenger
    {
    public:
        void ErrorMsg_TooFewArgs();
        void ErrorMsg_IdenticalIO();
        void ErrorMsg_BadMode(std::string);
        void ErrorMsg_BadPath();
        void ErrorMsg_BadOutput(std::string);
        void ErrorMsg_BadDefaultOutput();
        void ErrorMsg_Generic();

        void StatusMsg_Searching(std::string);
        void StatusMsg_Checking(unsigned int);
        void StatusMsg_Saving(unsigned int);
        void StatusMsg_Finished();
    }
    class Converter
    {
        class HashLog
        {
            class ToCSV 
            {
            public:
                Convert();
            private:
                SymbolToSpace();
                EqualiseSpaces();
                SpaceToComma();
        
                class Polisher
                {
                public:
                    Polish();
                private:
                    const std::string phrase1
                };
            }!
        };
    };
};
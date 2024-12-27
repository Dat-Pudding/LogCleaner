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
                std::string Convert(std::string&);
                static std::string outputLine;
                static int counter;
            private:
                void SymbolToSpace(std::string&);
                void EqualiseSpaces(std::string&);
                void SpaceToComma(std::string&);

                const char space = ' ';
                const char openBracket = '[';
                const char closeBracket = ']';
                const char comma = ',';
                
                class Polisher
                {
                public:
                    void Polish(std::string&);
                private:
                    void RemovePhrase(std::string&, std::smatch&, std::regex&);

                    const std::string phrase1 = ",speed,10s/60s/15m";
                    const std::string phrase2 = ",H/s,max";
                    const std::string phrase3 = ",H/s";
                };
            }!
        };
    };
};
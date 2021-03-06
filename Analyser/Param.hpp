#ifndef PARAM_HPP
#define PARAM_HPP

#include <map>
#include <string>

static const char* s_pKeyDatabase       = "-D"; //SQLite file
static const char* s_pKeyChangedFile    = "-F"; //Changed File List
static const char* s_pKeyOutputFile     = "-O"; //Output File List

class Param
{
public:
    Param();
    ~Param();

    bool LoadParam(int a_Argc, char** a_pArgv);
    std::string GetValue(const char* a_Arg);
private:
    bool HasAllRequiredArgs();

    std::map<std::string, std::string> m_Values;
};

#endif


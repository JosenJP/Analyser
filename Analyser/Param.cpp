#include "Param.hpp"
#include <algorithm>

const int HEADER_LEN = 2;
const int REQUIRE_ARGUEMENT_NUM = 2;

Param::Param()
{
}

Param::~Param()
{
}

bool Param::LoadParam(int a_Argc, char** a_pArgv)
{
    bool l_IsValid = true;

    if (a_Argc < REQUIRE_ARGUEMENT_NUM + 1)
    {
        return false;
    }

    for (int i = 1; i < a_Argc; i++)
    {
        std::string l_StrParam = std::string(a_pArgv[i]);

        std::string l_Header = l_StrParam.substr(0, HEADER_LEN);
        std::string l_Value = l_StrParam.substr(HEADER_LEN, l_StrParam.size());

        std::transform(l_Header.begin(), l_Header.end(), l_Header.begin(), ::toupper);

        if (l_Header.compare(s_pKeyDatabase) == 0) //SQLite Database
        {
            m_Values[s_pKeyDatabase] = l_Value;
        }
        else if (l_Header.compare(s_pKeyChangedFile) == 0) //Changed file list
        {
            m_Values[s_pKeyChangedFile] = l_Value;
        }
        else if (l_Header.compare(s_pKeyOutputFile) == 0) //Output file list
        {
            m_Values[s_pKeyOutputFile] = l_Value;
        }
        else
        {
            l_IsValid = false;
        }
    }

    if (!HasAllRequiredArgs())
    {
        l_IsValid = false;
    }

    return l_IsValid;
}

bool Param::HasAllRequiredArgs()
{
    bool l_HasAllRequiredArgs = false;

    if ((m_Values.end() != m_Values.find(s_pKeyDatabase)) &&
        (m_Values.end() != m_Values.find(s_pKeyChangedFile)))
    {
        l_HasAllRequiredArgs = true;
    }

    return l_HasAllRequiredArgs;
}


std::string Param::GetValue(const char* a_Arg)
{
    std::map<std::string, std::string>::iterator l_It = m_Values.find(a_Arg);
    if (m_Values.end() != l_It)
    {
        return l_It->second;
    }

    return "";
}


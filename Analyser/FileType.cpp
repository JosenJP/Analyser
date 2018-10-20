#include <algorithm>

#include "FileType.hpp"

const char* EXTENSION_CPP = ".cpp";
const char* EXTENSION_C = ".c";
const char* EXTENSION_H = ".h";
const char* EXTENSION_HPP = ".hpp";

FileType FileChecker::Check(const char* a_File)
{
    FileType l_FileType = FileType::UnKnow;

    if (CheckExtension(a_File, EXTENSION_CPP) ||
        CheckExtension(a_File, EXTENSION_C))
    {
        l_FileType = FileType::CPP;
    }
    else if (CheckExtension(a_File, EXTENSION_H) ||
             CheckExtension(a_File, EXTENSION_HPP))
    {
        l_FileType = FileType::Header;
    }
    else
    {
        //The other files shuold be similar to the relationship between CPP and project.
        l_FileType = FileType::CPP;
    }

    return l_FileType;
}

bool FileChecker::CheckExtension(const char* a_pFileName, const char* a_pExtension)
{
    std::size_t l_FileLen = strlen(a_pFileName);
    std::size_t l_ExtensionLen = strlen(a_pExtension);

    std::string l_FileName(a_pFileName);
    std::transform(l_FileName.begin(), l_FileName.end(), l_FileName.begin(), ::tolower);
    std::size_t l_Found = l_FileName.find(a_pExtension, l_FileLen - l_ExtensionLen, l_ExtensionLen);

    if (std::string::npos != l_Found)
    {
        return true;
    }

    return false;
}


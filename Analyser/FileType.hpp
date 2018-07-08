#ifndef FILE_TYPE_HPP
#define FILE_TYPE_HPP
#include <string>

enum FileType
{
    UnKnow  = 0,
    Header  = 1,
    CPP     = 2
};

class FileChecker
{
public:
    static FileType Check(const char* a_File);
    static bool CheckExtension(const char* a_pFileName, const char* a_pExtension);
};

#endif // !FILE_TYPE_HPP



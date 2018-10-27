#ifndef FILE_TYPE_HPP
#define FILE_TYPE_HPP
#include <string>

enum FileType
{
    UnKnown = 0,
    Header  = 1,
    CPP     = 2,
    Rc      = 3
};

extern const char* EXTENSION_CPP;
extern const char* EXTENSION_C;
extern const char* EXTENSION_H;
extern const char* EXTENSION_HPP;
extern const char* EXTENSION_RC;

class FileChecker
{
public:
    static FileType Check(const char* a_File);
    static bool CheckExtension(const char* a_pFileName, const char* a_pExtension);
};

#endif // !FILE_TYPE_HPP



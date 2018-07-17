#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <list>
#include <string>

class FileReader
{
public:
     void Read(std::string a_File, std::list<std::string>& a_rFileList);

private:
    std::string GetFileName(std::string a_File);
};

#endif // !FILE_READER_HPP


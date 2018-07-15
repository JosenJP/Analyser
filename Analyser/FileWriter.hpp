#ifndef FILE_WRITER_HPP
#define FILE_WRITER_HPP

#include <list>
#include <string>

class FileWriter
{
public:
    void WriteList(std::string a_FilePath, const std::list<std::string>& a_rStrList);

};

#endif // !FILE_WRITER_HPP



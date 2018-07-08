#include <fstream>
#include "FileReader.hpp"

static const int MAX_FILE_NAME_LEN = 500;

void FileReader::Read(std::string a_File, std::list<std::string>& a_rFileList)
{
    a_rFileList.clear();

    std::ifstream l_File;
    l_File.open(a_File, std::fstream::in);
    char l_FileName[MAX_FILE_NAME_LEN];
    memset(l_FileName, 0, sizeof(l_FileName));

    if (!l_File.is_open())
    {
        return;
    }

    while (!l_File.eof())
    {
        l_File.getline(l_FileName, sizeof(l_FileName));

        a_rFileList.push_back(l_FileName);
    }

}

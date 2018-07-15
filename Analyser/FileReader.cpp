#include <fstream>
#include <algorithm>
#include <iostream>
#include "FileReader.hpp"

static const int MAX_FILE_NAME_LEN = 500;

void FileReader::Read(std::string a_File, std::list<std::string>& a_rFileList)
{
    a_rFileList.clear();

    std::ifstream l_File;
    try
    {
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

            std::string l_LowerFileName(l_FileName);
            std::transform(l_LowerFileName.begin(), l_LowerFileName.end(), l_LowerFileName.begin(), ::tolower);

            a_rFileList.push_back(l_LowerFileName);
        }
    }
    catch (const std::exception& a_rEx)
    {
        std::cout << a_rEx.what() << std::endl;
    }

    if (l_File.is_open())
    {
        l_File.close();
    }
}

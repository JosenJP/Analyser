#include <fstream>
#include <iostream>

#include "FileWriter.hpp"

void FileWriter::WriteList(std::string a_FilePath, const std::list<std::string>& a_rStrList)
{
    std::ofstream l_OuputFile;
    try
    {
        l_OuputFile.open(a_FilePath, std::fstream::out | std::fstream::trunc);


        for (std::string l_File : a_rStrList)
        {
            l_OuputFile << l_File << std::endl;
        }
    }
    catch (const std::exception& a_rEx)
    {
        std::cout << a_rEx.what() << std::endl;
    }

    if (l_OuputFile.is_open())
    {
        l_OuputFile.close();
    }
}


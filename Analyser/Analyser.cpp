#include <iostream>
#include <string>
#include <memory>
#include "Life.hpp"
#include "TableFactory.hpp"
#include "Calculator.hpp"
#include "Timer.hpp"
#include "Param.hpp"
#include "FileReader.hpp"
#include "TblSQLite.hpp"

void PrintUsage(void)
{
    std::cout << "Usage: Analyser.exe -D<DBFilePath> -F<SourceCodeFileList>"    << std::endl
        << "Currently, the tool supports SQLite Database."                      << std::endl
        << "Example: Analyser.exe -DD:\\SQLite.db -FD:\\ChangedFileList.txt"    << std::endl;
}

int main(int a_Argc, char** a_pArgv)
{
    Life l_Life; //The DB will be release in the destructor of Life object.
    Timer l_Timer;
    Param l_Param;
    FileReader l_FileReader;

    if (!l_Param.LoadParam(a_Argc, a_pArgv))
    {
        PrintUsage();
        return 0;
    }

    std::unique_ptr<Calculator> l_pCalculator = std::unique_ptr<Calculator>(new Calculator());
    //Calculator* l_pCalculator = new Calculator();

    //Set SQLite Database
    std::string l_DBPath = l_Param.GetValue(s_pKeyDatabase);
    TableFactory::SetDBPath(l_DBPath);

    //Load the changed file list
    std::string l_File = l_Param.GetValue(s_pKeyChangedFile);
    std::list<std::string> l_TargetFiles = {};
    l_FileReader.Read(l_File, l_TargetFiles);

    l_Timer.Start();
    std::set<std::string> l_ProjList = l_pCalculator->Process(l_TargetFiles);
    l_Timer.End();
    l_Timer.Duration();

    for (std::string l_Proj : l_ProjList)
    {
        std::cout << l_Proj << std::endl;
    }

    ////Memory Testing
    //delete l_pCalculator;
    //l_ProjList.clear();
    //TblSQLite::FreeDB();

    return 0;
}


#include "Life.hpp"
#include "TblSQLite.hpp"

Life::Life()
{
}

Life::~Life()
{
    TblSQLite::FreeDB();
}

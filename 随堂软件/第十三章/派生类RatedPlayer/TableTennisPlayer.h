#ifndef TABLETENNISPLAYER_H_
#define TABLETENNISPLAYER_H_
#include <iostream>
#include<string>

using namespace std;

class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;

public:
    TableTennisPlayer(const string& fn = "none", const string& ln = "none", bool ht = false);
    void Name()const;
    bool HasTable()const { return hasTable; };
    void ResetTable(bool v) { hasTable = v; };

};
#endif

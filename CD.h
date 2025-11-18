#ifndef CD_H
#define CD_H

#include <string>
#include <iostream>

using namespace std;

class CD {
private:
    string title;
    string artist;
    string upc;
    int releaseYear;

public:
    CD(string t, string a, string u, int year);
    string getUpc() const;
    string getTitle() const;
    void printInfo() const;
};

#endif // CD_H
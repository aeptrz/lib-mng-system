#include "CD.h"

CD::CD(string t, string a, string u, int year)
    : title(t), artist(a), upc(u), releaseYear(year) {}

string CD::getUpc() const {
    return upc;
}

string CD::getTitle() const {
    return title;
}

void CD::printInfo() const {
    cout << "Title: " << title
         << " | Artist: " << artist
         << " | UPC: " << upc
         << " | Year: " << releaseYear
         << endl;
}
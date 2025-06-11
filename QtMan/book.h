#ifndef BOOK_H
#define BOOK_H
#include "resource.h"

class book : public Resource
{

    string m_pubHouse;
    string m_category;

public:
    book();
    book(const string& title, const string& author, int pages, const Time& pubYear, bool availability , const string& pubHouse, const string & category);

    void setPubHouse(const string & pubHouse);


};

#endif // BOOK_H

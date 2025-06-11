#ifndef RESOURCE_H
#define RESOURCE_H

#include<string>
#include<stdexcept>
#include<iostream>
using namespace std;

class Time{};

class Resource
{

    string m_title;
    string m_author;
    int m_pages;
    // Time m_pubYear;
    bool m_availability;


public:

    Resource() = default;
    Resource(const string& title, const string& author, int pages, const Time& pubYear, bool availability );

    //setter functions

    virtual void setTitle(const string& title) = 0;
    virtual void setAuthor(const string & author) = 0;
    virtual void setPages(int pages) = 0;
    virtual void setPubYear(const Time & pubYear) = 0;
    virtual void setAvailability(const bool& availability) = 0;

    //getter functions

    virtual const string& getTitle() const = 0;
    virtual const string& getAuthor() const = 0;
    virtual const int& getPages() const = 0;
    virtual const Time& getPubYear() const = 0;
    virtual const bool& getAvailability() const = 0;


    virtual ~Resource() = default;
};

#endif // RESOURCE_H

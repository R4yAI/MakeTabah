#ifndef LIBRARY_H
#define LIBRARY_H
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

#include "resource.h"


//In the library constructor, we use set methods (eg: setResources(

class Library
{

    string m_Name;
    vector<Resource*> m_Resources;
    unordered_map<int, Resource*> Resources; //for fast lookups and search





public:
    Library();
    Library(const vector<Resource*> resources); //Construct the Library object with a resources vector returned by the load() function that will deserialize the resources objects from the file (retrieve them each time the user loggs in)
};

#endif // LIBRARY_H

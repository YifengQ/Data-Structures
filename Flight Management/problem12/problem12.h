/**
 @author Yifeng Qin
 @data 3/6/18
*/
#include <string>
#include <iostream>

typedef std::string City;
const City NO_CITY = "NO_CITY";

class listCity;
class map;

class Node
{
    friend class listCity;
    friend class map;

private:

    Node( std::string place, Node* ptr);
    std::string n_city;
    bool visited;
    Node* next;

};

class listCity
{

public:

    listCity();

    bool getVaildDest(std::string);

    void setName(std::string);

    void setMap(std::string, std::string);

    bool getVisited(std::string);

protected:

    Node* top[40];
    Node* cityList[40];
    int total;
    Node* tryNext[40];
};

class map : public listCity
{

public:

    bool check(City, City);

    void setVisited(City);

    void resetVisited();

    City getNextCity(City);

};













#include <string>
#include <iostream>
#include <utility>
#include <list>

typedef std::string City;
const City NO_CITY = "NO_CITY";

class Cities;
class map;

class Node
{
  private:
  
     Node( std::string place, int , int ,Node* ptr);
     std::string n_city;
     int fNumber;
     int fCost;
     bool visited;
     Node* next;
     friend class Cities;
     friend class map;
};

class Cities
{
  protected:
  
    Node* top[40];
    Node* cityList[40];
    Node* tryNext[40];
    int total;
    
  public:

    Cities();

    bool getVaildDest(std::string);

    void setName(std::string);

    void setMap(std::string, std::string , int, int);

    bool getVisited(std::string);
};

class map : public Cities
{
  private:

  public:

    void markVisited(City);

    void resetVisited();

    std::pair<int,int> getNextCity( City, City& );

    bool check(City, City);

    void traverse(std::list<City>, std::list<int>, std::list <int>);
    
};














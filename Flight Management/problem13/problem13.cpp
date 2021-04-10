#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <utility>
#include <string>
#include "problem13.h"

///////////////Node Implementation/////////////////////////////

/**
 * Parametrized Constructor
 * @breif sets the base values for the city when called
 * @param place
 * @param ptr
 * @return none
 * @pre takes in the city name, and sets the base cases
 * @post will have created a Node off that city with base cases
 */
Node::Node(std::string place, int number, int cost, Node* ptr) {

    n_city = place;
    visited = false;
    next = ptr;
    fNumber = number;
    fCost = cost;
}

///////////////Cities Implementation////////////////////////////

/**
 * Default
 * @param none
 * @return none
 * @pre called to make a default city
 * @post will have created a default city
 */
Cities::Cities() {
total = 0;

    for(int i = 0; i < 40; i++) {
        cityList[i] = top[i] = NULL;
    }
}

/**
 * @brief Checks if the city named entered is one of the cities that the company serves.
 * @param dest , name of city
 * @return validDest, which is a bool value that tells the program if the city entered is valid
 * @pre Takes in a city string to test the validity
 * @post Will give a bool value based on the validity of the city name
 */
bool Cities::getVaildDest(std::string dest)
{
bool valid = false;
bool loop = false;
int index = 0;

    while( index < total && !loop ){

        if( dest == cityList[index]->n_city ){

            valid = true;
            loop = true;
        }
    
    index++;
    }

return valid;
}

/**
 * @brief It is going to set the name for the city
 * @param name , name of city
 * @return void
 * @pre Is going to take in a city name to set it
 * @post Will have set the name of the city to cityList
 */
void Cities::setName(std::string name) {

    if( cityList[total] == NULL ){

        cityList[total] = top[total] = new Node( name, 0, 0, NULL );

        total++;
    }
}

/**
 * @brief Will set the names of the cities for the neighboring cities in the flightFile.txt
 * @param origin
 * @param dest
 * @return void
 * @pre Will take in both city names to set to the cityList
 * post Will set the city names to the CityList
 */

void Cities::setMap(std::string origin, std::string dest, int number, int cost )
{
bool loop = false;
int index = 0;

    while( index < total && !loop ){

        if( origin == cityList[index]->n_city ){

              top[index]->next = new Node( dest, number, cost, NULL );
              top[index] = top[index]->next;

              loop = true;
        }

    index++;
    }
}

/**
Default constructor
@pre:
@post:
@param:
@return:
**/
bool Cities::getVisited(std::string n_city)
{
bool loop = false;
int index = 0;

    while( index < total && !loop ){

        if( n_city  == cityList[index]->n_city ){

          loop = true;
        }

        index++;
    }

return cityList[index-1]->visited;
}

/////////////map Implementation////////////////////

/**
 * @brief When finding the cities, this function is called to set a flag, so it doesn't come back to this city. When we visit this city it will get a value of true, meaning that this city has been cisited.
 * @param CityVisited
 * @return void
 * @pre Takes in a string to find the city in the list
 * @post Will loop through the names of the cities to find the city and then will set that cities private member ,visited, to true.
 */

void map::markVisited(City CityVisited)
{
int index = 0;
bool loop = false;

    while( index < total && !loop ){

    if( CityVisited == cityList[index]->n_city ){

          cityList[index]->visited = true;

          loop = true;
    }

    index++;
    }
}

/**
 * @breif is going to reset all the cities visited variable to false to check again for wrong and new paths.
 * @param none
 * @return void
 * @pre none
 * @post resets the bools of all the cities
 */

void map::resetVisited()
{
    for( int i = 0; i < total; i++ ){

    cityList[i]->visited = false;
    }
}

/**
 * @breif gets the next available city, will save also into the trNext array
 * @param t_city
 * @return the city
 * @pre Takes in a city to get next
 * @post Will check if the cities are equal and if the have already been cisited. IF all is true it will return that city. If not the will return NO_CITY
 */

std::pair<int,int> map::getNextCity( City palce, City &nextCity ) {

/// initialize variable
int index = 0;
bool loop = false;
City tempName;
std::pair<int,int> flightInfo = std::make_pair( 0,0 );

nextCity = NO_CITY;

while( index < total && !loop ) {

    if( palce == cityList[index]->n_city ) {

        tryNext[index] = cityList[index];

        Node* temp = cityList[index]->next;

        while( !loop && temp != NULL ) {

            tempName = temp->n_city;

            if( !getVisited( tempName )) {

                nextCity = tempName;
                flightInfo.first = temp->fNumber;
                flightInfo.second = temp->fCost;
                loop = true;
            }

            temp = temp->next;
        }
    }

    index++;
}

return flightInfo;
}

/**
 * @breif It is going to check if there is a path between the to cities.
 * @param origin
 * @param dest
 * @return bool
 * @pre to check if there is a path between cities
 * @post marks cities visited every run through. If there it gets NO_CITY it will pop
 */
bool map::check( City origin, City dest ) {
    
std::list<City> cityStack;
std::list<int> fNumber;
std::list<int> fCost;
City nextCity;
std::pair<int,int> flightInfo;


resetVisited();

cityStack.push_back( origin );
    markVisited( origin );
fNumber.push_back( 0 );
fCost.push_back( 0 );


City topCity = cityStack.front();

/// begin loop
while( !cityStack.empty() && (topCity != dest  )) {

    /// get the next city adjacent to top city
    flightInfo = getNextCity( topCity, nextCity );

    /// check if next city is valid, NO_CITY
    if( nextCity == NO_CITY ) {

        cityStack.pop_back(); ///< backtrack
        fNumber.pop_back(); ///< backtrack
        fCost.pop_back(); ///< backtrack
    }
    else {

        /// push next city onto stack, mark as visited
        cityStack.push_back( nextCity );
        markVisited( nextCity );
        fNumber.push_back( flightInfo.first );
        fCost.push_back( flightInfo.second );

    }


    if( !cityStack.empty() ) {

        topCity = cityStack.back();
    }

    }

    if( !cityStack.empty() ) {


        traverse( cityStack, fNumber, fCost );
    }

return !cityStack.empty();
}

/**
 * @breif prints out all the data for the flights
 * @param flight
 * @param fNumber
 * @param fCost
 * @return void
 * @pre take in flights
 * @post prints the right info for the flights
 */
void map::traverse( std::list<City> flight, std::list<int> fNumber, std::list<int> fCost ) {

std::ofstream log3;///opens the log3 to record the cities it goes too.
log3.open("log3.txt", std::ofstream::out | std::ofstream::app);
int totalCost = 0;

fNumber.pop_front();
fCost.pop_front();

    while( flight.front() != flight.back() ) {

        std::cout << "Flight #" << fNumber.front() << " from " << flight.front();

        log3 << "Flight #" << fNumber.front() << " from " << flight.front();
        flight.pop_front();

        std::cout << " to " << flight.front() << "\t" <<  " Cost: $" << fCost.front() << std::endl;
        log3 << " to " << flight.front() << "\t" <<  " Cost: $" << fCost.front() << std::endl;
        totalCost += fCost.front();

        fNumber.pop_front();
    }

std::cout << "Total Cost" << " ......... " << "$" << totalCost << std::endl << std::endl;
log3.close();
}



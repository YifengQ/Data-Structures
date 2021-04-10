/**
 @author Yifeng Qin
 @data 3/6/18
*/

#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include "problem12.h"

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
Node::Node(std::string place, Node* ptr){

    n_city = place;
    next = ptr;
    visited = false;
}

///////////////listCity Implementation////////////////////////////

/**
 * Default
 * @param none
 * @return none
 * @pre called to make a default city
 * @post will have created a default city
 */
listCity::listCity(){
    total = 0;

    for(int i = 0; i < 40; i++){

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
bool listCity::getVaildDest(std::string dest){

    bool validDest = false;
    bool loop = false;
    int i = 0;

    while( i < total && !loop ){

        if( dest == cityList[i]->n_city ){

            validDest = true;
            loop = true;
        }

        i++;
    }

    return validDest;
}

/**
 * @brief It is going to set the name for the city
 * @param name , name of city
 * @return void
 * @pre Is going to take in a city name to set it
 * @post Will have set the name of the city to cityList
 */
void listCity::setName(std::string name){

    if( cityList[total] == NULL ){

        cityList[total] = top[total] = new Node( name, NULL );

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
void listCity::setMap(std::string origin, std::string dest){

    bool loop = false;
    int i = 0;

    while( i < total && !loop ){

        if( origin == cityList[i]->n_city ){

            top[i]->next = new Node( dest, NULL );
            top[i] = top[i]->next;

            loop = true;
        }

        i++;
    }
}

/**
 * @brief Will get the bool value of that city
 * @param n_city
 * @return bool
 * @pre Will take in a city name to find the city
 * @post Will loop through the names of the cities to find the city and then will give the bool value of that city.
 */
bool listCity::getVisited(std::string n_city){

    bool loop = false;
    int i = 0;

    while( i < total && !loop ){

        if( n_city  == cityList[i]->n_city ){

            loop = true;
        }

        i++;
    }

    return cityList[i-1]->visited;
}

/////////////Map Implementation////////////////////

/**
 * @breif It is going to check if there is a path between the to cities.
 * @param origin
 * @param dest
 * @return bool
 * @pre to check if there is a path between cities
 * @post marks cities visited every run through. If there it gets NO_CITY it will pop
 */
bool map::check(City origin, City dest)
{
    std::ofstream log2;///opens the log2 to record the cities it goes too.
    log2.open("log2.txt", std::ofstream::out | std::ofstream::app);

    std::stack<City> cityStack;

    resetVisited();

    cityStack.push( origin );
    setVisited( origin );

    City topCity = cityStack.top();

    while( !cityStack.empty() && (topCity != dest  ))
    {

        City nextCity = getNextCity( topCity );

        if( nextCity == NO_CITY ){

            cityStack.pop();
        }
        else{

            cityStack.push( nextCity );
            setVisited( nextCity );
        }

        if( !cityStack.empty() ){

            topCity = cityStack.top();
            log2 << "city: " << topCity << std::endl;
        }

    }
    log2.close();
    return !cityStack.empty();
}

/**
 * @brief When finding the cities, this function is called to set a flag, so it doesn't come back to this city. When we visit this city it will get a value of true, meaning that this city has been cisited.
 * @param CityVisited
 * @return void
 * @pre Takes in a string to find the city in the list
 * @post Will loop through the names of the cities to find the city and then will set that cities private member ,visited, to true.
 */
void map::setVisited(City CityVisited){

    int i = 0;
    bool loop = false;

    while( i < total && !loop ){

        if( CityVisited == cityList[i]->n_city ){

            cityList[i]->visited = true;
            loop = true;
        }

        i++;
    }
}

/**
 * @breif is going to reset all the cities visited variable to false to check again for wrong and new paths.
 * @param none
 * @return void
 * @pre none
 * @post resets the bools of all the cities
 */
void map::resetVisited(){

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
City map::getNextCity(City t_city)
{
    int i = 0;
    bool loop = false;

    City nextCity = NO_CITY;
    City tempCity;

    while( i < total && !loop ){

        if( t_city == cityList[i]->n_city ){

            tryNext[i] = cityList[i];

            Node* temp = cityList[i]->next;

            while( !loop && temp != NULL ){

                tempCity = temp->n_city;

                if( !getVisited( tempCity )){

                    nextCity = tempCity;
                    loop = true;
                }

                temp = temp->next;

            }
        }

        i++;
    }

    return nextCity;
}






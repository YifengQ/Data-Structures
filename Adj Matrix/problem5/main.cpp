#include <iostream>
#include <fstream>
#include <list>
#include "Graph.h"

#define numCities 28
#define numFlights 32

using namespace std;

int getOriginNumber(string [], const string &, int);

int getDestNumber(string [], const string &, int);

bool getValidDest(string, string[]);

int getOrigin(string [], string);

int getDest(string [], string);

int main()
{
    // create the graph given in above fugure
    int test = 0;
    int test1 = 0;

    string cities[numCities];
    string start[numFlights];
    string end [numFlights];

    ifstream cityFile, neighbors, request;
    string place, origin, dest;
    cityFile.open("cityFile.txt");
    neighbors.open("flightFile.txt");
    request.open("requestFile.txt");

    while(!cityFile.eof()){

        getline( cityFile, place, '\n' ); ///< get the next city

        cities[test++] = place;
    }

    while(!neighbors.eof()) {

        getline( neighbors, origin, ',' ); ///< get next line
        neighbors.get();
        getline( neighbors, dest, '\n' ); ///< get next line
        start[test1] = origin;
        end[test1] = dest;
        test1++;

    }///< end loop

    Graph g(numFlights);

    for (int i = 0; i < numFlights; ++i) {

        int destination = getDestNumber(cities, end[i], numCities);
        int org = getOriginNumber(cities, start[i], numCities);
        g.addEdge(org, destination);
    }


/// prime loop
    getline( request, origin, ',' );
    request.get();
    getline( request, dest, '\n' );

    //cout<< "Origin: " << origin << " Dest: " << dest << endl;
    /// begin loop

    while( request.good() ) {

        /// first check if flight is not possible, else continue
        if( !getValidDest(dest, cities ) ) {
            cout << "Request is to fly from " << origin << " to " << dest << "." << endl;
            cout << "Sorry. prob11 does not serve " << dest << "." << endl << endl;

        }
        else {

            /// check if there is a valid path
            bool check = g.isReachable(getOrigin(cities, origin), getDest(cities, dest));

            /// check if valid then print result
            if( check ) {

                cout << "Request is to fly from " << origin << " to " << dest << "." << endl;
                cout << "HPAir flies from " << origin << " to " << dest << "." << endl << endl;
            }
            else {

                cout << "Request is to fly from " << origin << " to " << dest << "." << endl;
                cout << "Sorry. HPAir does not fly from " << origin << " to " << dest << "." << endl << endl;

            }

        }

        /// get next
        getline( request, origin, ',' );
        request.get();
        getline( request, dest, '\n' );

    }

    cityFile.close();
    neighbors.close();
    request.close();
    return 0;
}

int getOriginNumber(string orig[], const string &data ,int a){

    for (int i = 0; i < a ; ++i) {

        if(orig[i] == data)
            return i;

    }

    return 0;
}

int getDestNumber(string dest[], const string &data, int a){

    for (int i = 0; i < a ; ++i) {

        if(dest[i] == data)
            return i;

    }

    return 0;
}

bool getValidDest(string dest, string cities[]){

    for (int i = 0; i < numCities; ++i) {

        if(cities[i] == dest)
            return true;
    }

    return false;
}

int getOrigin(string origin[], string ori){

    for (int i = 0; i < numCities; ++i) {

        if(origin[i] == ori)
            return i;
    }

    return 0;
}

int getDest(string dest[], string des){

    for (int i = 0; i < numCities; ++i) {

        if(dest[i] == des)
            return i;
    }

    return 0;
}
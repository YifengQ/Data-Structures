/**
 @author Yifeng Qin
 @data 3/6/18
*/

#include "problem11.h"
#include <fstream>

using namespace std;

int main() {

    /// variables
    ifstream city, neighbors, request;
    ofstream log1;
    char cityFile[15] = "cityFile.txt";
    char flightFile[15] = "flightFile.txt";
    char requestFile[20] = "requestFile.txt";
    string place, origin, dest;
    map prob11;
    bool check = false;

    ///clear files
    log1.clear();
    city.clear();
    neighbors.clear();
    request.clear();

    ///open files
    city.open( cityFile );
    neighbors.open( flightFile );
    request.open( requestFile );

    cout << "Question 11" << endl;

    while( !city.eof() ) {
        getline( city, place, '\n' ); ///< get the next city
        prob11.setName( place );

        //std::cout<< "City Name: " << place << std::endl;
    }



    /// begin loop
    while( !neighbors.eof() ) {

        getline( neighbors, origin, ',' ); ///< get next line
        neighbors.get();
        getline( neighbors, dest, '\n' ); ///< get next line
        prob11.setMap( origin, dest );
        //cout<< "Origin: " << origin << " Dest: " << dest << endl;

    }///< end loop

    //cout<< "Origin: " << origin << " Dest: " << dest << endl;
    /// open request flight for later use


    /// process data flight

    /// prime loop
    getline( request, origin, ',' );
    request.get();
    getline( request, dest, '\n' );

    //cout<< "Origin: " << origin << " Dest: " << dest << endl;
    /// begin loop

    while( request.good() ) {

        /// first check if flight is not possible, else continue
        if( !prob11.getVaildDest( dest ) ) {
            cout << "Request is to fly from " << origin << " to " << dest << "." << endl;
            cout << "Sorry. prob11 does not serve " << dest << "." << endl << endl;

        }
        else {

            /// check if there is a valid path
            check = prob11.check( origin, dest );

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

        check = false; 
    }

    return 0;
}



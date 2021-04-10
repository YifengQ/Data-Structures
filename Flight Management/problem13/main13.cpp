/// header files


#include <iostream>
#include <fstream>
#include <string>
#include "problem13.h"
using namespace std;


int main() {

    /// initialize variables
    ifstream r_city, r_flight, r_request;
    ofstream log3;
    char cityFile[20] =  "cityFile.txt" ;
    char flightFile[20] = "flightFile.txt";
    char requestFile[20] = "requestFile.txt";
    string place, origin, dest;
    map prob13;
    bool valid = false;
    int flightNumber, flightCost;
    

    

    /// print title
    cout << "===============" << endl;
    cout << "Extra Credit" << endl;
    cout << "===============" << endl << endl;
    

    /// read in city file
    log3.clear();
    r_city.clear();
    r_flight.clear();
    r_request.clear();

    r_city.open( cityFile );
    r_flight.open( flightFile );
    r_request.open( requestFile );

    
    while( !r_city.eof() ) {

        getline( r_city, place, '\n' );
        prob13.setName( place );
    }
    
    while( !r_flight.eof() ) {

        getline( r_flight, origin, ',' );
        r_flight.get();
        getline( r_flight, dest, '\t' );
        r_flight >> flightNumber >> flightCost;
        r_flight.ignore( 5, '\n' );

        prob13.setMap( origin, dest, flightNumber, flightCost );

    }


    /// prime loop
    getline( r_request, origin, ',' );
    r_request.get();
    getline( r_request, dest, '\n' );

    while( r_request.good() ) {

        cout << "Request is to fly from " << origin << " to " << dest << "." << endl;
        
        if( !prob13.getVaildDest( dest ) ) {

            cout << "Sorry. prob13 does not serve " << dest << "." << endl << endl;

        }
        else {

            
            valid = prob13.check( origin, dest );

            
            if( !valid ) {

                cout << "Sorry. prob13 does not fly from " << origin << " to " << dest << "." << endl << endl;

            }

        }
 
        getline( r_request, origin, ',' );
        r_request.get();
        getline( r_request, dest, '\n' );

        valid = false; 
    }

        log3.close();

    return 0;
}


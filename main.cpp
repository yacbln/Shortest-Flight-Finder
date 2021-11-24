
#include "graph.h"
#include "airport.h"
#include "route.h"

#include <iostream>

int main(){
    
    Airport* ORD = new Airport (3830, "O'hare Airport", "Chicago", "USA", 41.9786, -87.9048 ); 

    Airport* CDG = new Airport (1381, "Charles Degaulle", "Paris", "France", 49.012798, 2.55 ); 

    Route* ORDtoCDG = new Route (ORD, CDG); 

    cout << "Distance from ORD to CDG is " << ORDtoCDG->getRouteDistance() << " miles.";  

   return 0;
}
#pragma once 

#include "airport.h"
#include <utility>

using namespace std; 

/*class wrapping important info about a route between a source and destination airport */ 
class Route {

public:

// custom constructor
Route(Airport* sourceAirport, Airport* destinationAirport); 

// custom destructor since we need to manually delete member variables of type "Airport"
~Route(); 

// Using "Haversine" formula to calculate the distance between two airports based on their longitude and latitude 
double calculateRouteDistance  (Airport* sourceAirport , Airport* destinationAirport); 

//getters
// pair.first ==> source airport*   pair.second ==> destination airport*
pair <Airport*, Airport*> getRouteAirports ();

double getRouteDistance();


private: 
Airport* _sourceAirport; 
Airport* _destinationAirport; 

// THIS WILL BE THE WEIGHT OF OUR GRAPH EDGE
double _routeDistance; 

};
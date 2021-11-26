#pragma once
#include "airport.h"
#include "route.h"
#include "fileio.h"

#include <vector>
#include <list>
#include <string>
// #include <unordered_map>

using std::vector; 
using std::list; 
using std::string; 
// using std::unordered_map; 

class Graph {

    public:

    // constuctor of graph from Airports and Routes datasets
    Graph(const string& airportsDatasetName , const string& routesDatasetName); 
    // in our case: airportsDataSetName = "airports_clean" 
    // routesDatasetName = "routes_clean"
    
    // destructor that deallocates all vertices and edges
    ~Graph(); 


    
    //helper functions
    // This function populates the adjacency list based on Routes dataset
    void connectVertices (const string& routesDatasetName);
    
    //This function assign a route to an airport
    void addEdge (Airport* sourceAirport, Route* outGoingRoute); 

    private:

    vector<Airport*> V ; 
    list<Route*>* Adj; 
    



        
};
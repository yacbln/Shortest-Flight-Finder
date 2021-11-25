#include "graph.h"

#include <utility>

using std::pair;

using namespace FileIO;


// custom constuctor: build the whole graph based on airports and routes datasets
Graph::Graph(const string& airportsDatasetName , const string& routesDatasetName){

//load 
V = FileIO::loadAirports (airportsDatasetName); 

//set the length of adjacency list equal to number of vertices (airports)
Adj = new list<Route*>[V->size()]; 

// construct edges
connectVertices (routesDatasetName); 

}

// custom deconstructor
Graph::~Graph(){

// deallocate edges
for (list<Route*> routeList: *Adj ){

   for (Route* route: routeList){
      delete route; 
   }
   routeList.clear(); // clear all content and set size of list to 0
   std::list<Route*>().swap(routeList); // set list capacity to 0 
}

delete[]  Adj;

//deallocate vertices
for (Airport* airport: *V){
    delete airport; 
}
V->clear(); 
V->shrink_to_fit(); // shrink vector to capacity 0
}


// This helper function connects all airports (vertices) that have a connecting route (edge) 
void Graph::connectVertices (const string& routesDatasetName) {

vector<Route*>* routes = FileIO::loadRoutes (routesDatasetName);

for (Route* route: *routes)
   addEdge (route->getRouteAirports().first , route); 

}


// This helper function connects two airports with and edge (a route)
void Graph::addEdge (Airport* sourceAirport, Route* outGoingRoute){

// since the IDs of airports are unique, incrementing by 1 and starts from 0, we will use them to
// represent index of an airport in the adjacency list

Adj[sourceAirport->getAirportID()].push_back (outGoingRoute);

}
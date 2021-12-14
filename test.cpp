#include "graph.h"
#include "route.h"
#include "airport.h"
#include "fileio.h"
#include "drawUtils/cs225/catch/catch.hpp"
#include <iostream>
#include "shortestPathVisualizer.h"
#include "drawUtils/cs225/PNG.h"


using namespace std;

TEST_CASE("Simple Distance Check","[weight=1]"){
    Airport* ORD = new Airport (3830, "O'hare Airport", "Chicago", "USA", 41.9786, -87.9048 );
    
    Airport* CDG = new Airport (1381, "Charles Degaulle", "Paris", "France", 49.012798, 2.55 );
    
    Route* ORDtoCDG = new Route (ORD, CDG);
    
    int dist = ORDtoCDG->getRouteDistance();
    REQUIRE((4138 == dist));
    
    delete ORD;
    delete CDG;
    delete ORDtoCDG;
}

TEST_CASE("Route Class Works","[weight=1]"){
    std::vector<Airport*> airports = FileIO::loadAirports("airports_clean.csv");
    
    std::vector<Route*> routes = FileIO::loadRoutes("routes_clean.csv", airports);
    Airport* source = routes[6]->getRouteAirports().first;
    Airport* destination = routes[6]->getRouteAirports().second;
    REQUIRE(source->getAirportID() == 4029);
    REQUIRE(destination->getAirportID() == 6969);


}

TEST_CASE("Graph node neighbor works","[weight=1]"){
    Graph* graph = new Graph( "airports_clean.csv" , "routes_clean.csv");
    Airport* airport79 = graph->getAirportWithID(79); // airport with ID 79
    vector<Airport*> outNeighbors = graph->getOutNeighbors(airport79);
    REQUIRE(outNeighbors.size() == 3);
    REQUIRE(outNeighbors[0]->getAirportID() == 3830);
    
    delete graph;
}
TEST_CASE("Visualization works","[weight=1]"){
    Graph* graph = new Graph( "airports_clean.csv" , "routes_clean.csv");
    
    vector<Airport*> mapAirports;
    
    mapAirports.push_back(graph->getAirportWithID(3361)) ; // must show in Sydney
    mapAirports.push_back(graph->getAirportWithID(210)) ; // must show in algier
    mapAirports.push_back(graph->getAirportWithID(3364)) ; // must show in Beijing
    mapAirports.push_back(graph->getAirportWithID(820)) ; // must show in Johannesburg
    mapAirports.push_back(graph->getAirportWithID(1382)) ; // must show in Paris
    mapAirports.push_back(graph->getAirportWithID(3830)) ; // must show in chicago
    
    
    Image map = drawShortestPath(mapAirports);
    
    map.writeToFile("map.png");
    
    delete graph;
}
TEST_CASE("BFS Test","[weight=1]"){
    Graph* graph = new Graph( "airports_clean.csv" , "routes_clean.csv");
    REQUIRE(6033 == graph->BFS().size());
    //There are 6033 airports, so if BFS works it should have 6033 airports.
    
    delete graph;
}

TEST_CASE("Dijkstra Test No Path", "[weight=1]") {
    Graph* graph = new Graph( "airports_clean.csv" , "routes_clean.csv");
    Airport* ORD = graph->getAirportWithID(3830);
    Airport* XYZ = graph->getAirportWithID(1381); // this airport is standalone ie has no routes 
    
    REQUIRE(graph->Dijkstra(ORD, XYZ).empty() == true); // vector should be empty (no path)
    
    delete graph;
}

TEST_CASE("Dijkstra Test Path Exist", "[weight=1]") {
    Graph* graph = new Graph( "airports_clean.csv" , "routes_clean.csv");
    Airport* ORD = graph->getAirportWithID(3830);
    //Airport* BEIJ = graph->getAirportWithID(3364); 
    Airport* CDG = graph->getAirportWithID(1382);
    Airport* ALG = graph->getAirportWithID(210);

    /* Checked distances they are accurate */
    // Route route1(ORD,BEIJ);
    // Route route2(ORD, CDG); 
    // cout << route1.getRouteDistance()<< " "<< route2.getRouteDistance() <<"\n";
    
    vector<Airport*> airports = graph->Dijkstra(ORD, ALG);

    cout << "depart at --> ";
    for (Airport* airport: airports) {
        cout<<airport->getAirportName() <<" --> ";
    }
    cout << "arrived";
    REQUIRE(airports.front()->getAirportID() == 3830);
    REQUIRE(airports.back()->getAirportID() == 210);
    delete graph;
}

TEST_CASE("Airports close together") {
    Graph* graph = new Graph( "airports_clean.csv" , "routes_clean.csv");
    Airport* ORD = graph->getAirportWithID(3830);
    Airport* ATL = graph->getAirportWithID(3682);

    vector<Airport*> airports = graph->Dijkstra(ORD, ATL);
    REQUIRE(airports.size() == 2);
    REQUIRE(airports.front()->getAirportID() == 3830);
    REQUIRE(airports.back()->getAirportID() == 3682);
    
    delete graph;
}

TEST_CASE("Check if greater") {
    Airport* ORD = new Airport (3830, "O'hare Airport", "Chicago", "USA", 41.9786, -87.9048 );
    
    Airport* CDG = new Airport (1381, "Charles Degaulle", "Paris", "France", 49.012798, 2.55 );
    
    Route ORDtoCDG(ORD, CDG);
    
    Airport* AER = new Airport(2965, "Sochi International Airport", "Sochi", "Russia", 43.449902, 39.9566);
    Airport* ASF = new Airport(2966, "Astrakhan Airport", "Astrakhan", "Russia", 46.2832984924, 48.0063018799);
    Route r(AER, ASF);
    REQUIRE(ORDtoCDG > r);
    
    delete ORD;
    delete CDG;
    delete AER;
    delete ASF;
}

TEST_CASE("Priority Queue") {
    Airport* ORD = new Airport (3830, "O'hare Airport", "Chicago", "USA", 41.9786, -87.9048 );

    Airport* CDG = new Airport (1381, "Charles Degaulle", "Paris", "France", 49.012798, 2.55 );

    Route ORDtoCDG(ORD, CDG);

    Airport* AER = new Airport(2965, "Sochi International Airport", "Sochi", "Russia", 43.449902, 39.9566);
    Airport* ASF = new Airport(2966, "Astrakhan Airport", "Astrakhan", "Russia", 46.2832984924, 48.0063018799);
    Route r(AER, ASF);

    priority_queue<Route, vector<Route>, std::greater<Route>> pq;
    pq.push(ORDtoCDG);
    pq.push(r);
    REQUIRE(r == pq.top());
    pq.pop();
    REQUIRE(ORDtoCDG == pq.top());

    delete ORD;
    delete CDG;
    delete AER;
    delete ASF;
}
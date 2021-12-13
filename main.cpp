#include "graph.h"
#include "airport.h"
#include "route.h"
#include "fileio.h"
#include "shortestPathVisualizer.h"

#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::endl;

int main(int argc, char** argv){
    if(argc != 3)   //argv[0] is "./main"
    {
        cout << "You must enter 2 separate airport keys" << endl;
        return 1;
    }

    Graph graph("airports_clean.csv", "routes_clean.csv");
    Airport* start = graph.getAirportWithID(std::stoul(argv[1]));
    Airport* fin = graph.getAirportWithID(std::stoul(argv[2]));
    if(start == 0 || fin == 0)
    {
        cout << "Please enter valid airport IDs, these can be looked up as the first column of the airport csv" << endl;
    }

    vector<Airport*> ports = graph.Dijkstra(start, fin);

    //draw map
    Image map = drawShortestPath(ports);
    map.writeToFile("map.png");

    return 0;
}
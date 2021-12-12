#include "graph.h"

using std::priority_queue;
using std::map;

/*
 * This includes the Dijkstra functions for the graph
 */

vector<unsigned> Graph::Dijkstra(Airport* start, Airport* dest)
{
    //auto comp = []
    priority_queue<Route*, vector<Route*>, std::greater<Route*>> pq;
    
    map<unsigned, double> dist;
    map<unsigned, int> prev; // mapping two IDs together
    
    for (Airport* a : V) {
        dist[a->getAirportID()] = std::numeric_limits<double>::max();
        prev[a->getAirportID()] = -1;
    }
    dist[start->getAirportID()] = 0;
    return vector<unsigned>();
}

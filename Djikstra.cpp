#include "graph.h"

using std::priority_queue;
using std::map;

/*
 * This includes the Dijkstra functions for the graph
 */

vector<Airport*> Graph::Dijkstra(Airport* start, Airport* dest)
{
    vector<Airport*> path; // to return
    priority_queue<Route*, vector<Route*>, std::greater<Route*>> pq;
    
    map<unsigned, double> dist;
    map<unsigned, unsigned> prev; // mapping two IDs together
    
    for (Airport* a : V) {
        dist[a->getAirportID()] = std::numeric_limits<double>::infinity();
    }
    dist[start->getAirportID()] = 0;
    
    vector<Airport*> neighbours = getOutNeighbors(start);
    
    for (Airport* a : neighbours) {
        pq.push(Adj[airportMap[a->getAirportID()].second]);
    }
    
    vector<Airport*> labeled;
    
    while (!pq.empty()) {
        Route* r = pq.top();
        pq.pop();
        
        labeled.push_back(r->getRouteAirports().second);
        
        if (r.getRouteDistance() < dist[r.getRouteAirports().second->getAirporttID()]) {
            
        }
    }
    return path;
}

#include "graph.h"

using std::priority_queue;
using std::map;

/*
 * This includes the Dijkstra functions for the graph
 */

//vector<Airport*> Graph::Dijkstra(Airport* start, Airport* dest)
//{
//    vector<Airport*> path; // to return
//    priority_queue<Route, vector<Route>, std::greater<Route>> pq;
//
//    map<unsigned, double> dist;
//    map<unsigned, unsigned> prev; // mapping two IDs together
//
//    for (Airport* a : V) {
//        dist[a->getAirportID()] = std::numeric_limits<double>::infinity();
//    }
//    dist[start->getAirportID()] = 0;
//
//    // get list of outgoing routes from airport (start) and push every route to pq
//    list<Route*> outGoingRoutes = this->getOutRoutes(start);
//    
//    for (Route* route : outGoingRoutes) {
//        pq.push(*route);
//    }
//
//    vector<Airport*> labeled;
//
//    while (!pq.empty()) {
//        Route r = pq.top();
//        pq.pop();
//
//        labeled.push_back(r.getRouteAirports().first);
//
//        if (r.getRouteDistance() < dist[r.getRouteAirports().second->getAirportID()]) {
//            dist[r.getRouteAirports().second->getAirportID()] = dist[r.getRouteAirports().first->getAirportID()]
//                    + r.getRouteDistance();
//            prev[r.getRouteAirports().second->getAirportID()] = r.getRouteAirports().first->getAirportID();
//
//            for (Airport* a : getOutNeighbors(r.getRouteAirports().second)) {
//                if (std::find(labeled.begin(), labeled.end(), r.getRouteAirports().second) == labeled.end()) {
//                    pq.push(Route(r.getRouteAirports().second, a));
//                }
//            }
//        }
//    }
//
//    if (dist[dest->getAirportID()] == std::numeric_limits<double>::infinity()) {
//        return path;
//    }
//
//    while (dist[dest->getAirportID()] != 0) {
//        path.push_back(dest);
//        dest = getAirportWithID(prev[dest->getAirportID()]);
//    }
//    path.push_back(dest);
//    std::reverse(path.begin(), path.end());
//    return path;
//}

//vector<Airport*> Graph::Dijkstra(Airport* start, Airport* dest) // This is the weird one
//{
//    vector<Airport*> path; // to return
//    priority_queue<Route, vector<Route>, std::greater<Route>> pq;
//
//    map<unsigned, double> dist;
//    map<unsigned, unsigned> prev; // mapping two IDs together
//
//    for (Airport* a : V) {
//        dist[a->getAirportID()] = std::numeric_limits<double>::infinity();
//    }
//    dist[start->getAirportID()] = 0;
//
//    // get list of outgoing routes from airport (start) and push every route to pq
//    list<Route*> outGoingRoutes = this->getOutRoutes(start);
//
//    pq.push(Route(start, start));
//    for (Route* route : outGoingRoutes) {
//        pq.push(*route);
//    }
//
//    vector<Airport*> labeled;
//
//    while (!pq.empty()) {
//        Route r = pq.top();
//        pq.pop();
//
//        labeled.push_back(r.getRouteAirports().first);
//
//        if (*(r.getRouteAirports().first) == *dest) {
//            break;
//        }
//
//        if (dist[r.getRouteAirports().first->getAirportID()] + r.getRouteDistance() < dist[r.getRouteAirports().second->getAirportID()]) {
//            dist[r.getRouteAirports().second->getAirportID()] = dist[r.getRouteAirports().first->getAirportID()]
//                                                                + r.getRouteDistance();
//            prev[r.getRouteAirports().second->getAirportID()] = r.getRouteAirports().first->getAirportID();
//
//            for (Airport* a : getOutNeighbors(r.getRouteAirports().second)) {
//                if (std::find(labeled.begin(), labeled.end(), r.getRouteAirports().second) == labeled.end()) {
//                    pq.push(Route(r.getRouteAirports().second, a));
//                }
//            }
//        }
//    }
//
//    if (dist[dest->getAirportID()] == std::numeric_limits<double>::infinity()) {
//        return path;
//    }
//
//    while (dist[dest->getAirportID()] != 0) {
//        path.push_back(dest);
//        dest = getAirportWithID(prev[dest->getAirportID()]);
//    }
//    path.push_back(dest);
//    std::reverse(path.begin(), path.end());
//    return path;
//}

vector<Airport*> Graph::Dijkstra(Airport* start, Airport* dest) {
    map<unsigned, double> dist;
    map<unsigned, unsigned> prev; // mapping two IDs together
    
    unsigned destID = dest->getAirportID();
    std::vector<unsigned> solution;
    unsigned curID = destID;

    while (curID != 99999) {
        map<unsigned, unsigned>::iterator lookup = prev.find(curID);
        if (lookup == prev.end() ||
            dist[curID] == std::numeric_limits<double>::infinity())
        {
            solution = vector<unsigned> ();
            break;
        }
        unsigned prevID = prev[curID];
        solution.push_back(prevID);
        curID = prevID;
    }
    reverse(solution.begin(), solution.end());

    vector<Airport*> output;
    for (unsigned i = 0; i < solution.size(); i++) {
        for (unsigned j = 0; j < V.size(); j++) {
            if (V[j]->getAirportID() == solution[i] || V[j]->getAirportID() == 99999) {
                output.push_back(V[j]);
                break;
            }
        }
    }
    
    output.push_back(dest);
    return output;
}

#include <iostream>
#include <fstream>
#include <vector>
#include "airport.h"
#include "route.h"

namespace FileIO {
    std::vector<Airport*>* loadAirports(const std::string& airport_filename);
    
    std::vector<Route*>* loadRoutes(const std::string& route_filename);
}
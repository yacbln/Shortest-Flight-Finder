#include <iostream>
#include <fstream>
#include <vector>
#include "airport.h"
#include "route.h"
#include "dataset.h"

namespace FileIO {
    std::vector<Airport*> loadAirports(const std::string& airport_filename);
    
    std::vector<Route*> loadRoutes(const std::string& route_filename, const std::string& airport_filename);
}
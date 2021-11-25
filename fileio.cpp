#include "fileio.h"

using std::getline;
using std::string;
using std::vector;
using std::ifstream;

namespace FileIO {
    vector<Airport*> loadAirports(const std::string& airport_filename) {
        vector<Airport*> airports;
        ifstream my_file(airport_filename);
        vector<string> line;
        
        if (my_file.isOpen()) {
            while (getline(my_file, line, "\n")) {
                unsigned id = std::stoul(line[0]);
                string name = line[1];
                string city = line[2];
                string country = line[3];
                double latitude = std::stod(line[4]);
                double longitude = std::stod(line[5]);
                
                Airport* a = new Airport(id, name, city, country, latitude, longitude);
                airports.push_back(a);
            }
        }
    }

    vector<Route*> loadRoutes(const std::string& route_filename) {
        /* Might have to overload extraction operator somewhere else (maybe create a dataset class?)
        to map the airport to its attributes and then create the routes
         */
    }
    
}
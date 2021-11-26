#include "fileio.h"

using std::getline;
using std::string;
using std::vector;
using std::ifstream;

namespace FileIO {
    vector<Airport*> loadAirports(const string& airport_filename) {
        vector<Airport*> airports;
        ifstream my_file(airport_filename);
        vector<string> line;
        
        if (my_file.isOpen()) {
            while (getline(my_file, line, "\n")) {
                unsigned id = std::stoul(line[0]);
                string name = line[1];
                string city = line[2];
                string country = line[3];
                double latitude = std::stod(line[6]);
                double longitude = std::stod(line[7]);
                
                Airport* a = new Airport(id, name, city, country, latitude, longitude);
                airports.push_back(a);
            }
        }

        return airports; 
    }

    vector<Route*> loadRoutes(const std::string& route_filename, const std::string& airport_filename) {
        /* Might have to overload extraction operator somewhere else (maybe create a dataset class?)
        to map the airport to its attributes and then create the routes
         */
        vector<Route*> routes;
        ifstream airport_file(airport_filename);
        Dataset set;
        airport_file >> set;
        vector<vector<string>> data = set.GetData();

        ifstream my_file(route_filename);
        vector<string> line;
        if (my_file.isOpen()) {
            while (getline(my_file, line, "\n")) {
                for (const auto& vec : data) {
                    if (line[2] == vec[4]) {
                        unsigned src_id = std::stoul(line[0]);
                        string src_name = vec[1];
                        string src_city = vec[2];
                        string src_country = vec[3];
                        double src_latitude = std::stod(vec[6]);
                        double src_longitude = std::stod(vec[7]);

                        Airport* source = new Airport(src_id, src_name, src_city,
                                                      src_country, src_latitude, src_longitude);

                        for (const auto& vec : data) {
                            if (line[4] == vec[4]) {
                                unsigned dest_id = std::stoul(line[0]);
                                string dest_name = vec[1];
                                string dest_city = vec[2];
                                string dest_country = vec[3];
                                double dest_latitude = std::stod(vec[6]);
                                double dest_longitude = std::stod(vec[7]);

                                Airport* destination = new Airport(dest_id, dest_name, dest_city,
                                                                   dest_country, dest_latitude, dest_longitude);
                                Route* r = new Route(source, destination);
                                routes.push_back(r);
                            }
                        }
                    }
                }
            }
        }
        return routes;
    }
    
}
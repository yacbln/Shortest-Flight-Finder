#include "airport.h"


Airport::Airport(unsigned id, string name, string city, string country, 
double latitude, double longitude): _id(id), _name(name), 
_city(city), _country(country), _latitude (latitude), 
_longitude(longitude) {

};


//getters 

unsigned Airport::getAirportID(){

    return _id;
}


double getAirportLatitude(){

    return _latitude;
} 

double getAirportLongitude(){

    return _longitude;
} 
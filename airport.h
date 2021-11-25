#pragma once 

#include <string>

using namespace std;

/* This class wraps info about an airport */ 
class Airport {

public:
     // custom constructor 
     Airport(unsigned id, string name, string city, string country, double latitude, double longitude);


     //put getters if needed  
     unsigned getAirportID(); 
     double getAirportLatitude(); 
     double getAirportLongitude();

private:     

  unsigned _id; 
  string _name; 
  string _city; 
  string _country; 
  double _latitude; 
  double _longitude; 


 };
#pragma once 

#include <string>

using namespace std;

/* This class wraps info about an airport */ 
 class Airport {

public: 

const unsigned _id; 
const string _name; 
const string _city; 
const string _country; 
const double _latitude; 
const double _longitude; 


// custom constructor 
Airport(unsigned id, string name, string city, string country, double latitude, double longitude);

 };
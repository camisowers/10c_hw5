#pragma once
#include <string>
#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>
using std::string;

/*
	The Appointment class stores the string values for the inputted decription, date and time.
	It also has read and write functions input and and output data from the files.
*/
class Appointment
{
public:		
	Appointment();			//default constructor

	void read(std::ifstream& fin);			//read data from file
	void write(std::ofstream& fout);		//write data to file
		
private:
	string description;
	string date;
	string time;
};


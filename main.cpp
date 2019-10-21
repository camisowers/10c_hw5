/*
	HW #5
	Cameron Sowers
	UID: 404766299
	Collaborators: Gaurav Gulati

	Honesty Pledge:
	"I pledge that I have neither given nor received unauthorized assistance on this assignment."

*/


#include "Appointment.h"
#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::cout;

int main()
{
	ifstream fin;			//create ifstream object
	ofstream fout;			//create ofstream object

	fin.open("appt_data.txt");		//open existing file with stored data

	if (fin.fail())			//if fail to be able to fead from file
	{
		std::runtime_error fout_error("Could not read file.");			//decribe error	
		throw fout_error;												//exit function
	}

	Appointment data;			
	data.read(fin);						//read from file using fin object
	fout.open("Appointments.txt");		//create new file
	data.write(fout);					//write to file using fout object

	fin.close();			//close file
	fout.close();			//close file

	return 0;
}
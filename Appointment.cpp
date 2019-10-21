#include "Appointment.h"


//default constructor
Appointment::Appointment() : description(" "), date(" "), time(" ") {}

/*
	The read() function reads line by line the strings in the file and sets them to be the corresponding variables in the Appointment class.
	@param: ifstream& fin
	@return: N/A
*/
void Appointment::read(std::ifstream& fin)
{
	string in_desc;
	getline(fin, in_desc);			//reads first line and assigns to description variable
	if (in_desc == "")				//if there is no description -> logic error
	{
		std::logic_error no_desc("No description.");			//describe the error
		throw no_desc;											//exits function
	}	
	else							//decription exists
	{
		description = in_desc;		//set descrption to be the inputted string
	}


	string in_date;					//reads second line and assigns to date variable
	getline(fin, in_date);
	if (in_date.size() != 8)		//if string is not in the correct format with size 8 -> logic error
	{
		std::logic_error bad_date("Date is not formatted correctly - MM/DD/YY");		//describe error
		throw bad_date;																	//exits function
	}								//correct format
	else 
	{	
		date = in_date;				//set date to be the inputted string
	}


	string in_time;					//reads third line and assigns to time variable
	getline(fin, in_time);
	if (in_time.size() != 5)		//if string is not in the correct format with size 5 -> logic error
	{
		std::logic_error bad_time("Time is not formatted correctly - HH:MM");			//describe error
		throw bad_time;																	//exits function
	}
	else							//correct format
	{
		time = in_time;				//set time to be inputted string
	}

}

/*
	The write() function outputs (in a new format) the Appointment member fields description, date and time to a new file.
	@param: ofstream& fout
	@return: N/A
*/
void Appointment::write(std::ofstream& fout)
{
	fout << date << " - " << description << " at " << time << "\n";				//new format
	if (fout.fail())				//if outputting to file fails -> runtime error
	{
		std::runtime_error fout_error("Could not write to file.");				//decribe error	
		throw fout_error;														//exit function
	}
}

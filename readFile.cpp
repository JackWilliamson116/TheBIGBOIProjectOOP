#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string fileName;							//A string that stores the filename that the user wants to open
	cout << "Enter the circuit file name: ";
	cin >> fileName;							//Takes what the user inputs and setes it to the string fileName

	ifstream testStream(fileName);				//Creates an ifstream called testStream
	vector<string> fileContents;				//A vector that will hold each line of the text file

	while (testStream.good())					//While we are not at the end of the file...
	{
		string tempstring = "";					//A temporary string that holds that line of the file
		getline(testStream, tempstring);		//Get the current line of the file and put it into the temporary variable
		fileContents.push_back(tempstring);		//Add the temporary string to the array
	}

	testStream.close();							//Close the file
												//At this point, the vector has each line of the file that was selected


	if (fileContents.size() == 0)				//Check if the file actually exists. This prevents crashes.
	{
		cerr << "Not a valid circuit file! Check the name?" << endl;
		return -1;
	}
	else										//Only using an else statement here to make sure fileValidTest goes out of scope
	{
		size_t fileValidTest = (fileContents.at(0)).find("CIRCUIT");	//Look for the word "CIRCUIT" in the first line of the file to check for validity
		if (fileValidTest == string::npos)								//Was the word found? If not run this
		{
			cerr << "Not a valid circuit file!" << endl;
			return 1;
		}
	}
	//At this point, the file has been confirmed as valid


	for (int i = 1; i < fileContents.size(); i++)						//Go through each line of the circuit file, starting at 1
	{
		size_t thingToMake = (fileContents.at(i)).find("INPUT");
		if (thingToMake != string::npos)							//If the current line has the keyword INPUT, do this
		{
			cout << "INPUT DETECTED" << endl;



		}

		thingToMake = (fileContents.at(i)).find("OUTPUT");			//If the current line has the keyword OUTPUT, do this
		if (thingToMake != string::npos)
		{
			cout << "OUTPUT DETECTED" << endl;
		}

		thingToMake = (fileContents.at(i)).find("AND");			//If the current line has the keyword AND (AND gate, NAND gate), do this
		if (thingToMake != string::npos)
		{
			if ((fileContents.at(i)).at(0) == 'N')			//NAND gate
			{
				cout << "NAND DETECTED" << endl;
			}
			else											//AND gate 
			{
				cout << "AND DETECTED" << endl;
			}
			
		}

		thingToMake = (fileContents.at(i)).find("OR");			//If the current line has the keyword OR (OR gate, NOR gate, XOR gate, XNOR gate), do this
		if (thingToMake != string::npos)
		{
			if ((fileContents.at(i)).at(0) == 'X')			//XOR or XNOR gate
			{
				if ((fileContents.at(i)).at(1) == 'N')			//XNOR gate
				{
					cout << "XNOR DETECTED" << endl;
				}
				else											//XOR gate 
				{
					cout << "XOR DETECTED" << endl;
				}
			}
			else											//AND gate 
			{
				if ((fileContents.at(i)).at(0) == 'N')			//NOR gate
				{
					cout << "NOR DETECTED" << endl;
				}
				else											//OR gate 
				{
					cout << "OR DETECTED" << endl;
				}
			}
		}

		thingToMake = (fileContents.at(i)).find("NOT");			//If the current line has the keyword NOT, do this
		if (thingToMake != string::npos)
		{
			cout << "NOT DETECTED" << endl;
		}

		thingToMake = (fileContents.at(i)).find("INVERT");			//If the current line has the keyword INVERT, do this
		if (thingToMake != string::npos)
		{
			cout << "INVERT DETECTED" << endl;
		}
	}
	//At this point, all wire and gate objects should have been created.



	return 0;


}
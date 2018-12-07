#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <queue>
#include <stdlib.h>
#include "Circuit.h"



using namespace std;

int main() {

	circuit c;
	//priority_queue<event> q;
	//q.push(NULL);
	string fileName;												//A string that stores the filename that the user wants to open
	cout << "Enter the circuit file name: ";
	cin >> fileName;												//Takes what the user inputs and setes it to the string fileName

	ifstream testStream(fileName);					//Creates an ifstream called testStream
	vector<string> fileContents;						//A vector that will hold each line of the text file

	while (testStream.good())								//While we are not at the end of the file...
	{
		string tempstring = "";								//A temporary string that holds that line of the file
		getline(testStream, tempstring);			//Get the current line of the file and put it into the temporary variable
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
		if (fileValidTest == string::npos)														//Was the word found? If not run this
		{
			cerr << "Not a valid circuit file!" << endl;
			return 1;
		}
	}
	//At this point, the file has been confirmed as valid


	for (int i = 1; i < fileContents.size(); i++)									//Go through each line of the circuit file, starting at 1
	{
		size_t thingToMake = (fileContents.at(i)).find("INPUT");
		if (thingToMake != string::npos)														//If the current line has the keyword INPUT, do this
		{
			cout << "INPUT DETECTED" << endl;

			string temporaryWorkingString = (fileContents.at(i)).substr(5, string::npos);		//A string that contains everything but the begining word, input

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have the name for our wire at the beginging of temporaryWorkingString.
			
			string nameOfTheWire = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				nameOfTheWire = nameOfTheWire + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have stored the name of the wire (which we assume is the thing after the word "input") into its own string.

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire number remaining.

			stringstream wireNumberStringStream(temporaryWorkingString);
			int tempWireNum;
			wireNumberStringStream >> tempWireNum;

			//JACK - wirecharacter is now a string...
			/*if (c.doesNotExist(tempWireNum))										//if the wire does not already exist
			{
				wire* w = new wire(tempWireNum);									//create the wire
				cout << tempWireNum << " wire created " << wireCharacter << endl;
				c.insertWire(wireCharacter, w);										//then add it to the map
				cout << "wire added to map " << endl;
			}*/

		}

		thingToMake = (fileContents.at(i)).find("OUTPUT");			//If the current line has the keyword OUTPUT, do this
		if (thingToMake != string::npos)
		{
			string temporaryWorkingString = (fileContents.at(i)).substr(6, string::npos);		//A string that contains everything but the begining word, output

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have the name for our wire at the beginging of temporaryWorkingString.

			string nameOfTheWire = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				nameOfTheWire = nameOfTheWire + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have stored the name of the wire (which we assume is the thing after the word "input") into its own string.

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire number remaining.

			stringstream wireNumberStringStream(temporaryWorkingString);
			int tempWireNum;
			wireNumberStringStream >> tempWireNum;

			//JACK - wirecharacter is now a string...
			/*if (c.doesNotExist(tempWireNum)) {
				wire* w = new wire(tempWireNum);
				cout << tempWireNum << " wire created" << wireCharacter << endl;
				c.insertWire(wireCharacter, w);
				cout << "wire added to map" << endl;
			}*/

		}

		thingToMake = (fileContents.at(i)).find("AND");			//If the current line has the keyword AND (AND gate, NAND gate), do this
		if (thingToMake != string::npos)
		{
			string temporaryWorkingString = (fileContents.at(i)).substr(4, string::npos);
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing.

			string gateDelayTimeString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				gateDelayTimeString = gateDelayTimeString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//The string gateDelayTimeString at this point should be holding the time + the letters "ns"

			stringstream delayTimeStringStream(gateDelayTimeString);

			int delayTime;
			delayTimeStringStream >> delayTime;							//We have taken the delayTime


			//Get the first number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining.

			string theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int firstWire;
			stringstream theFirstWireStringStream(theWireNumberString);
			theFirstWireStringStream >> firstWire;								//firstWire is now the first wire number


			//Get the second Number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining (last 2)

			theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int secondWire;
			stringstream theSecondWireStringStream(theWireNumberString);
			theSecondWireStringStream >> secondWire;


			//Get the third Number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining (last 1)

			theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int thirdWire;
			stringstream theThirdWireStringStream(theWireNumberString);
			theThirdWireStringStream >> thirdWire;


			if (c.doesNotExist(thirdWire)) {
				wire* w = new wire(thirdWire);
				c.makeExtraWire(w);
				cout << "extra output wire created" << endl;
			}

			if ((fileContents.at(i)).at(0) == 'N')			//NAND gate
			{
				cout << "NAND DETECTED" << endl;
				c.createGateConnection(c.getWire(firstWire), c.getWire(secondWire), c.getWire(thirdWire), delayTime, NAND);

			}
			else											//AND gate
			{
				cout << "AND DETECTED" << endl;

				c.createGateConnection(c.getWire(firstWire), c.getWire(secondWire), c.getWire(thirdWire), delayTime, AND);
			}

		}

		thingToMake = (fileContents.at(i)).find("OR");			//If the current line has the keyword OR (OR gate, NOR gate, XOR gate, XNOR gate), do this
		if (thingToMake != string::npos)
		{

			string temporaryWorkingString = fileContents.at(i);

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))					//We dont care about the gate type for this part. Ignore it.
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);							//Remove those extra spaces after whatever the first word was.
			}


			string gateDelayTimeString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				gateDelayTimeString = gateDelayTimeString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//The string gateDelayTimeString at this point should be holding the time + the letters "ns"

			stringstream delayTimeStringStream(gateDelayTimeString);

			int delayTime;
			delayTimeStringStream >> delayTime;							//We have taken the delayTime


																		//Get the first number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining.

			string theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int firstWire;
			stringstream theFirstWireStringStream(theWireNumberString);
			theFirstWireStringStream >> firstWire;								//firstWire is now the first wire number
																				//Get the second Number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining (last 2)

			theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int secondWire;
			stringstream theSecondWireStringStream(theWireNumberString);
			theSecondWireStringStream >> secondWire;


			//Get the third Number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining (last 1)

			theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int thirdWire;
			stringstream theThirdWireStringStream(theWireNumberString);
			theThirdWireStringStream >> thirdWire;



			if (c.doesNotExist(thirdWire)) {
				wire* w = new wire(thirdWire);
				c.makeExtraWire(w);
				cout << "extra output wire created" << endl;
			}

			if ((fileContents.at(i)).at(0) == 'X')				//XOR or XNOR gate
			{
				if ((fileContents.at(i)).at(1) == 'N')			//XNOR gate
				{
					cout << "XNOR DETECTED" << endl;
					c.createGateConnection(c.getWire(firstWire), c.getWire(secondWire), c.getWire(thirdWire), delayTime, XNOR);
				}
				else											//XOR gate
				{
					cout << "XOR DETECTED" << endl;
					c.createGateConnection(c.getWire(firstWire), c.getWire(secondWire), c.getWire(thirdWire), delayTime, XOR);
				}
			}
			else											//AND gate
			{
				if ((fileContents.at(i)).at(0) == 'N')			//NOR gate
				{
					cout << "NOR DETECTED" << endl;
					c.createGateConnection(c.getWire(firstWire), c.getWire(secondWire), c.getWire(thirdWire), delayTime, NOR);
				}
				else											//OR gate
				{
					cout << "OR DETECTED" << endl;
					c.createGateConnection(c.getWire(firstWire), c.getWire(secondWire), c.getWire(thirdWire), delayTime, OR);
				}
			}
		}

		thingToMake = (fileContents.at(i)).find("NOT");			//If the current line has the keyword NOT, do this
		if (thingToMake != string::npos)
		{
			string temporaryWorkingString = fileContents.at(i);

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))					//We dont care about the gate type for this part. Ignore it.
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);							//Remove those extra spaces after whatever the first word was.
			}


			string gateDelayTimeString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				gateDelayTimeString = gateDelayTimeString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//The string gateDelayTimeString at this point should be holding the time + the letters "ns"

			stringstream delayTimeStringStream(gateDelayTimeString);

			int delayTime;
			delayTimeStringStream >> delayTime;							//We have taken the delayTime


																		//Get the first number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining.

			string theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int firstWire;
			stringstream theFirstWireStringStream(theWireNumberString);
			theFirstWireStringStream >> firstWire;								//firstWire is now the first wire number
																				//Get the second Number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining (last 2)

			theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int secondWire;
			stringstream theSecondWireStringStream(theWireNumberString);
			theSecondWireStringStream >> secondWire;

			if (c.doesNotExist(secondWire)) {
				wire* w = new wire(secondWire);
				c.makeExtraWire(w);
				cout << "extra output wire created" << endl;
			}
			//Note that there is NOT a third wire because a NOT gate only takes in 2 wires...

			cout << "NOT DETECTED" << endl;
			c.createGateConnection(c.getWire(firstWire), c.getWire(firstWire), c.getWire(secondWire), delayTime, NAND);
		}

		thingToMake = (fileContents.at(i)).find("INVERT");			//If the current line has the keyword INVERT, do this
		if (thingToMake != string::npos)
		{
			string temporaryWorkingString = fileContents.at(i);

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))					//We dont care about the gate type for this part. Ignore it.
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);							//Remove those extra spaces after whatever the first word was.
			}


			string gateDelayTimeString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				gateDelayTimeString = gateDelayTimeString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//The string gateDelayTimeString at this point should be holding the time + the letters "ns"

			stringstream delayTimeStringStream(gateDelayTimeString);

			int delayTime;
			delayTimeStringStream >> delayTime;							//We have taken the delayTime


																		//Get the first number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining.

			string theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int firstWire;
			stringstream theFirstWireStringStream(theWireNumberString);
			theFirstWireStringStream >> firstWire;								//firstWire is now the first wire number
																				//Get the second Number
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have removed all of the random spacing and should have only the wire numbers remaining (last 2)

			theWireNumberString = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				theWireNumberString = theWireNumberString + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//Put the full wire number into a string called theWireNumberString

			int secondWire;
			stringstream theSecondWireStringStream(theWireNumberString);
			theSecondWireStringStream >> secondWire;

			if (c.doesNotExist(secondWire)) {
				wire* w = new wire(secondWire);
				c.makeExtraWire(w);
				cout << "extra output wire created" << endl;
			}
			//Note that there is NOT a third wire because a NOT gate only takes in 2 wires...

			cout << "INVERT DETECTED" << endl;
			c.createGateConnection(c.getWire(firstWire), c.getWire(firstWire), c.getWire(secondWire), delayTime, NAND);
		}
	}
	//At this point, all wire and gate objects should have been created.



	ifstream vectorStream(fileName.substr(0, (fileName.length() - 4)) + "_v.txt");				//Creates an ifstream called vectorStream.
	vector<string> vectorContents;							//A vector that will hold each line of the text file
	while (vectorStream.good())									//While we are not at the end of the file...
	{
		string tempstring = "";										//A temporary string that holds that line of the file
		getline(vectorStream, tempstring);				//Get the current line of the file and put it into the temporary variable
		vectorContents.push_back(tempstring);			//Add the temporary string to the array
	}
	vectorStream.close();												//Close the file



	if (vectorContents.size() == 0)				//Check if the file actually exists. This prevents crashes.
	{
		cerr << "Not a valid vector file! Check the name? It should be " << fileName.substr(0, (fileName.length() - 4)) + "_v.txt" << endl;
		return -1;
	}
	else										//Only using an else statement here to make sure fileValidTest goes out of scope
	{
		size_t fileValidTest = (vectorContents.at(0)).find("VECTOR");				//Look for the word "VECTOR" in the first line of the file to check for validity
		if (fileValidTest == string::npos)																	//Was the word found? If not run this
		{
			cerr << "Not a valid vector file!" << endl;
			return 1;
		}
	}
	//At this point, the file has been confirmed as valid


	for (int i = 1; i < vectorContents.size(); i++)						//Go through each line of the vector file, starting at 1
	{
		if ((vectorContents.at(i)).size() != 0)									//We need to ignore the blank lines that were so painfully put in
		{
			cout << "Iteration number is " << i << endl;

			//wireName = (vectorContents.at(i)).at(6);
			string temporaryWorkingString = fileContents.at(i);

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))					//We dont care about the gate type for this part. Ignore it.
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);							//Remove those extra spaces after whatever the first word was.
			}

			string wireName = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				wireName = wireName + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have stored the name of the wire (which we assume is the thing after the word "input") into its own string.

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);							//Remove those extra spaces
			}

			string timeStringTemp = "";
			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) != ' '))
			{
				timeStringTemp = timeStringTemp + temporaryWorkingString.at(0);
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);
			}
			//At this point, we have stored the wire number into a string

			int wireTime;
			stringstream timeStringStringStream(timeStringTemp);
			timeStringStringStream >> wireTime;

			while ((temporaryWorkingString.length() != 0) && (temporaryWorkingString.at(0) == ' '))
			{
				temporaryWorkingString = temporaryWorkingString.substr(1, string::npos);							//Remove those extra spaces
			}

			char state = temporaryWorkingString.at(0);

			

			state = (vectorContents.at(i)).at((vectorContents.at(i)).size() - 1);					//This little bundle of confusion gets the last character in the line to determine the wire state.

			string timeAndStateString = (vectorContents.at(i)).substr(8, 2);							//We are creating a string that contains only the time portion of the original string.

			cout << "Time and state string claims to be " << timeAndStateString << endl;

			stringstream theTimeStringStream(timeAndStateString);													//Create a stringstream object that will turn the time string into an int

			theTimeStringStream >> wireTime;																							//Put whatever is stored in the stringstream into the int

			cout << "The wireTimeValue is " << wireTime << endl;
			
			//c.makeEvent(c.getWire(wireName), wireTime, c.setWireValue(state));		//here						//At this point, we have everything we need from each line of the vector file. We just need to make the gates and add them to however we are going to add them.

			cout << "event added" << endl;
		}
	}
	c.simulate();
	return 0;
}


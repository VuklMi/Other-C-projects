// Michaela Vuklisevicova
// Use of map data structure to create efficient look-up method using a phone number data field for a file with 50,000 records.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <map>
using namespace std;


int main() {
	ifstream myFile;
	myFile.open("usdata50000C.csv", ifstream::in);
	if (myFile) {
		cout << "file open." << endl;
		
		map<string, int> mapPhones;
		string lineOfFile;
		stringstream ss;
		int cursorLocation = 0;

		//****** store the data *****//
		while (getline(myFile, lineOfFile)) {
			// skip the line with heading (gets executed only once)
			if (!cursorLocation) {
				cursorLocation = myFile.tellg();
				continue;
			}

			//obtain the phone number
			ss << lineOfFile;
			string phoneNumber;
			// phone number is after the 8th comma
			for (int i = 0; i < 9; i++) {
				getline(ss, phoneNumber, ',');
			}

			// store in map
			mapPhones.insert(pair<string, int>(phoneNumber, cursorLocation));

			// clear the sstream
			ss.clear();
			ss.str("");

			cursorLocation = myFile.tellg();
		}

		// display the map (testing purposes)
		/*
		for (map<string,int>::iterator it = mapPhones.begin(); it != mapPhones.end(); ++it)
			cout << it->first << " => " << it->second << '\n';
		*/


		//***** search for the record    ****//
		// user input
		myFile.clear();
		string userInput;
		for (int i = 0; i < 10; i++) {
			cout << endl << "Enter your phone number in format: 123-456-7890" << endl;
			getline(cin, userInput);
			if (true) { // function for evaluating valid format of phone number
				string lineOfFile;
				// find the phone number in the list and read the cursor value

				int cursorLocation = 0;
				(mapPhones.find(userInput) == mapPhones.end()) ? cursorLocation = 0 : cursorLocation = mapPhones.find(userInput)->second;
				if (cursorLocation) {
					myFile.seekg(cursorLocation);
					getline(myFile, lineOfFile);
					cout << "User's info:" << endl << lineOfFile << endl;

				}
				else {
					cout << "Phone number does not exist." << endl;
				}
			}
			else {
				cout << "Invalid format." << endl;
			}
		}
		// close the file
		myFile.close();
	}

	else {
		cout << "File failed to open." << endl;
	}
} // end main

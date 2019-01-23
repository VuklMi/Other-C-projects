// Michaela Vuklisevicova 
// Parking Machine - parking fee calculator

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// function prototype
double calculateCharges (double hours);

int main()
{
  //variables
  char buf[100];
  double time = 0.0;
  
  // user's/console input
  cout << "Enter the total hours parked in the parking garage in terms of hours." << endl;
  cout << "For example, 1 hour and 30 minutes is 1.5 hours." << endl;
  cout << "Hours parked: ";
  cin >> buf;				// storing the input into a buffer
  cin.ignore(1000, 10);
  time = atof(buf);			// transfering the values from buffer into the double variable
	
  
  // console output
  cout << endl;
  cout << "Hours		Charges" << endl;
  // for Charges value - calling the value returning function - it will print
  // out the returned value
  cout << time << "		$ " << calculateCharges(time) << endl; 
  
} // main

// function definition
double calculateCharges(double hours)
{
  // variables
  int counter = 0;
  double fee = 0.00;
  
  // when parked under 3 hours - fee is flat rate: 2.00 USD
  if (hours <= 3.00 && hours >= 0.01) fee = 2.00;
  // maximum daily fee is 10.00 USD, and that occurs when car is parked 19 hours or more
  else if (hours >= 19) fee = 10.00;
  // for every extra hour after the first 3 hours, fee increases by 0.50 USD
  else
  {
	  fee = 2.00;						            // flat rate for under 3 hours
	  hours = hours - 3.00;			        // remaining hours
    for(int i = 1; i < hours; i++)	  // checking how many hours extra after the first 3 hours were exceeded	 
    {
      fee += 0.50;					          // fee increases by 0.50 per hour
      counter++;					            // counter for finding out how many full extra hours the car was parked
    } // for
    // after all full extra hours were added, checking for minutes (decimal digits)
    // fee increases for the little extra depending how many minutes the car was parked
    if (hours - counter > 0) fee += 0.5*(hours-counter); // 0.5 is the hourly rate times the decimal portion which stands for minutes (parts of the hour)
  } // else

  cout.setf(ios::fixed|ios::showpoint);  //formatting: max two decimal points for cent values
  cout << setprecision(2);
  
  // returning the value of fee back to the main for output
  return fee;		
} // calculateCharge

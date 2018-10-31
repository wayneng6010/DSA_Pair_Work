// Question3

#include "iostream"
#include <stdlib.h> 
#include <iomanip>// setprecision

//declaring array variable
int grades[20] = { 16, 2, 77, 40, 64, 34, 12, 42, 63, 12, 55, 73, 21, 42, 15, 99, 46, 32, 10, 7 };
double prices[10];
double amps[16] = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1, 11.1, 12.1, 13.1, 14.1, 15.1, 16.1 };
int dist[15] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10, 11, 12, 13, 14, 15 };


using namespace std;

int main()
{
	//Prices
	double price;
	//loop to allow user enter the price 
		for (int i = 0; i < 10; i++) {
			cout << "Enter price " << (i + 1) << ": ";
			cin >> price;
			prices[i] = price;
		}
	
	{
		//diplay value from first, third and seventh element of each array
		//Grades
		cout << "\nGrades" << "\n";
		cout << "Value from First, Third, Seventh: " << grades[0] << ", " << grades[2] << ", " << grades[6] << "\n";

		//Prices
		cout << "\nPrices" << "\n";
		cout << "Value from First, Third, Seventh: " << setprecision(2) << fixed << prices[0] << ", " << prices[2] << ", " << prices[6] << "\n";

		//Amps
		cout << "\nAmps" << "\n";
		cout << "Value from First, Third, Seventh: " << amps[0] << ", " << amps[2] << ", " << amps[6] << "\n";

		//Dist
		cout << "\nDist" << "\n";
		cout << "Value from First, Third, Seventh: " << dist[0] << ", " << dist[2] << ", " << dist[6] << "\n";

		//Write a for loop that can be used to display values for the complete array declared above. 
		cout << "\nGrades Array (20): ";
		for (int i = 0; i < 20; i++) {
			cout << grades[i] << "  ";
		}
		cout << "\nPrices Array (10): ";
		for (int i = 0; i < 10; i++) {
			cout << setprecision(2) << fixed << prices[i] << "  ";
		}
		cout << "\nAmps Array (16): ";
		for (int i = 0; i < 16; i++) {
			cout << amps[i] << "  ";
		}
		cout << "\nDist Array (15): ";
		for (int i = 0; i < 15; i++) {
			cout << dist[i] << "  ";
		}

		cout << endl;
	}

}

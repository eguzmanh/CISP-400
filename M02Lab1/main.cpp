#include "../std_lib_facilities.h"

int main()
{
	double num = 0.0, smallest = 10000000, largest = -10000000, convertedVal = 0.0, sumOfVal = 0.0;
	string  unit = "  "; //1m==100cm, 1in==2.54cm, 1ft==12in
	int numberOfVals = 0, convertedUnit=4;
	vector<double> valsEntered{};

	cout << "Please enter a number and unit in (cm,in,ft or m): ";

	while(cin >> num >> unit)
	{
		if (unit == "cm") convertedUnit = 0;
		else if (unit == "in") convertedUnit = 1;
		else if (unit == "ft") convertedUnit = 2;
		else if (unit == "m") convertedUnit = 3;
		else cout << "Invalid unit\n";

		if(num < smallest || num == 10000000)
		{
				smallest = num;
				cout << num << unit <<" The smallest so far.\n";
		}
		if(num > largest || num == -10000000)
		{
				largest = num;
				cout << num << unit <<" The largest so far.\n";
		}
		else
			cout << "The value entered: " << num << endl;

		switch (convertedUnit)
		{
			case 0:
				convertedVal = num / 100;
				cout << convertedVal << " meter(s).\n";
				numberOfVals++;
				sumOfVal += convertedVal;
				valsEntered.push_back(convertedVal);
				break;

			case 1:
				convertedVal = num * 0.0254;
				cout << convertedVal << " meter(s).\n";
				numberOfVals++;
				sumOfVal += convertedVal;
				valsEntered.push_back(convertedVal);
				break;

			case 2:
				convertedVal = num * 0.3048;
				cout << convertedVal << " meter(s).\n";
				numberOfVals++;
				sumOfVal += convertedVal;
				valsEntered.push_back(convertedVal);
				break;

			case 3: cout << num << " meter(s).\n";
				numberOfVals++;
				sumOfVal += convertedVal;
				valsEntered.push_back(convertedVal);
				break;

			default:
				cout << "Invalid unit\n";

		}
	}
	cout << "The smallest value entered: " << smallest << endl;
	cout << "The largest value entered: " << largest << endl;
	cout << "The number of values entered: " << numberOfVals << endl;
	cout << "The total sum of the values entered in meters: " << sumOfVal << endl;
	sort(valsEntered.begin(), valsEntered.end());
	cout << "Values entered: ";

	for(auto i : valsEntered) cout << i << " ";

	return 0;
}

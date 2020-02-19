#include <iostream>
#include <string>

using namespace std;

int main()
{
string unit = "cm";


cout << "The unit as a string: " << unit << endl;

int  convertedUnit=0;

convertedUnit=stoi(unit,nullptr,10);
cout << "The unit as a string: " << convertedUnit << endl;

return 0;
}

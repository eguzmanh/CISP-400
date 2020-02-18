#include "Chrono.h"
///using namespace Chrono; //this prevents having to use Chrono::

int main()
{
    Chrono::Date d1;
    cout << "default: " << d1 << endl;  ///use overloaded <<

    Chrono::Date d2{2019, Chrono::Month::dec, 31};
    cout << "today: " << d2 << endl;

    try
    {
        Chrono::Date d3{2018, Chrono::Month::feb, 99};
    }
    catch(Chrono::Date::Invalid)
    {
        cout << "Invalid date!" << endl;
    }
    Chrono::Date d4;

      cout << "Type a date (Y, M, D): ";
      cin >> d4;  ///use overloaded >>

      if(!cin)
      {
          cout << "Format error." << endl;
          cin.clear();  ///clear fail flag
          cin.ignore(256, '\n');  ///clear read buffer
      }

      ///use overloaded == and !=
      if(d4 == d2)
      {
          cout << "That IS today's date!" << endl;
      }
      else if(d4 != d2)
      {
          cout << "That is NOT today's date!" << endl;
      }

      d2.add_day();
      cout << "Tomorrow's date: " << d2 << endl;
  }

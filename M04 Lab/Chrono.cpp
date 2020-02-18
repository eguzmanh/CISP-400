#include "Chrono.h"

Date::Date():y{2001},m{Month::jan},d{1}
   {}

//int Date::nDays(Month m)
//bool Date::is_valid(int y, Month m, int d)
//void Date::add_day()


int Date::nDays(Month m) { // fix indentation
       int days_in_month;
       switch (m)
       {
           case Month::feb: // the length of February varies
               days_in_month = 28;  //ignore leap year for now
               break;
           case Month::apr: case Month::jun: case Month::sep: case Month::nov:
               days_in_month = 30; // the rest have 30 days
               break;
           default:
               days_in_month = 31; // most months have 31 days
       }
       return days_in_month;
   }

   bool Date::is_valid(int y, Month m, int d)
   {
       // assume that y is valid
       if (d<=0) return false; // d must be positive
       if (m < Month::jan || Month::dec < m) return false;
       if (nDays(m) < d) return false;
       return true;
   }

Month operator++(Month& m)	// prefix increment operator
{
	// “wrap around”:
	m = (m==Month::dec) ? Month::jan : Month(m+1);
	return m;
}

Month operator+(const Month& m, int nMonths)	// addition
   {
       int mInt = (int)m + nMonths - 1; ///-1 to align with [0...11] for mod
       mInt %= 12;  // “wrap around”
       return Month(mInt + 1);  ///+1 to align back with [1..12]
   }

   Month operator+=(Month& m, int nMonths)	// addition
   {
    /*   int mInt = (int)m + nMonths - 1; ///-1 to align with [0...11] for mod
       mInt %= 12;  // “wrap around”
       m = Month(mInt + 1); ///+1 to align back with [1..12]
*/
       m = m + nMonths
       return m;
   }


bool operator==(const Date& a, const Date& b)
{
		return a.year()==b.year()
		&& a.month()==b.month()
		&& a.day()==b.day();
}

bool operator!=(const Date& a, const Date& b) { return !(a==b); }

ostream& operator<<(ostream& os, const Date& d)
  {
      return os << '(' << d.year()
      << ',' << int(d.month())
      << ',' << d.day() << ')';
  }

  istream& operator>>(istream& is, Date& dd)
   {
       int y, m, d;
       char ch1, ch2, ch3, ch4;
       is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
       if (!is) return is;
       if (ch1!= '(' || ch2!=',' || ch3!=',' || ch4!=')')
       { // oops: format error
           is.clear(ios_base::failbit); // set the fail bit
           return is;
       }
       dd = Date(y, Month(m),d); // update dd
       return is;
   }

   void Date::add_day()
       {
           d++;
           if(d > nDays(m))
           {
               d = 1;
               //overloaded operators
               //m = m + 1; this is optional
               //m += 1;    this is optional we could use them
               ++m;
               if(m == Month::jan) y++;
           }
       }

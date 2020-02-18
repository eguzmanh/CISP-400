#ifndef YOUR_MOMMA
#define YOUR_MOMMA

#include "../std_lib_facilities.h"

enum Class Month {
  jan=1, feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Date // uses Month
{
public:
    class Invalid{};
    Date(int y, Month m, int d);

    Date(); // default constructor

    int day() const {return d;}
    Month month() const{return m;}   //refering to the Month class
    int year() const {return y;}     //const in front of curly braces makes the function constant
                                    //Month& month() const{return m;} can actually change value
    void add_day(int n);

  private:
    int y;
    Month m;
    int d;

    bool is_valid(int y, Month m, int d);
    int nDays(Month m);
}

#endif

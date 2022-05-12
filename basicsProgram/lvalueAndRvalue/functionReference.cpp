//**************************
// Author:  yh
// Time:    2021/12/15
//**************************
#include <iostream>

using namespace std;
struct Date
{
    short Month;
    short Day;
    short Year;
};

// Create a date of the form DDDYYYY (day of year, year)
// from a Date.
long DateOfYear(const Date& date )
{
    static int cDaysInMonth[] = {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    long dateOfYear = 0;

    // Add in days for months already elapsed.
    for ( int i = 0; i < date.Month - 1; ++i )
        dateOfYear += cDaysInMonth[i];

    // Add in days for this month.
    dateOfYear += date.Day;

    // Check for leap year.
    if ( date.Month > 2 &&
         (( date.Year % 100 != 0 || date.Year % 400 == 0 ) &&
          date.Year % 4 == 0 ))
        dateOfYear++;

    // Add in year.
    dateOfYear *= 10000;
    dateOfYear += date.Year;

    return dateOfYear;
}

int getDayOfYear()
{
    Date date{ 12, 15, 2021 };
    long dateOfYear = DateOfYear(date);
    std::cout << dateOfYear << std::endl;
    return dateOfYear;
}

class Point
{
public:
// Define "accessor" functions as
//  lvalueAndRvalue types.
    unsigned& x();
    unsigned& y();
private:
// Note that these are declared at class scope:
    unsigned obj_x;
    unsigned obj_y;
};

unsigned& Point :: x()
{
    return obj_x;
}
unsigned& Point :: y()
{
    return obj_y;
}

int main()
{
    Point ThePoint;
// Use x() and y() as l-values.
    ThePoint.x() = 7;
    ThePoint.y() = 9;

// Use x() and y() as r-values.
    cout << "x = " << ThePoint.x() << "\n"
         << "y = " << ThePoint.y() << "\n";
}

// File:  MyDate.cpp   

#include "MyDate.h"

   // This class does not have any constructors (yet)
   MyDate::MyDate()
   {

   }

   void MyDate::setMonth ( int m )
   {
    if ( m >= 1 && m <= 12 )
      month = m;
    else
      month = 1;
   }

   void MyDate::setDay ( int d )
   {
    static int MaxDayCount[] = {0, 31, 28, 31, 30, 31, 30,
      31, 31, 30, 31, 30, 31 };

    if ( month >= 1 && month <= 12 && d >= 1 &&
         d <= MaxDayCount[month] )
      day = d;
    else
      day = 1;
   }

   void MyDate::setYear ( int y )
   {
     if ( y >= 0 && y <= 99 )
       year = 2000 + y;
     else
       year = y;
   }

   // note this is unsafe since length of buf is never verified
   char* MyDate::toStr (char* buf)
   {
     static char* Months[] = { "NoMonth", 
        "January",   "February", "March",    "April", 
        "May",       "June",     "July",     "August", 
        "September", "October",  "November", "December" };

     // for MDY format
     //sprintf ( buf, "%s %d, %d", Months[month], day, year );

     // for mm/DD/YYYY format
     sprintf ( buf, "%02d/%02d/%d", month, day, year);

     return buf;
   }


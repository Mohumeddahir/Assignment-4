/*
 *this program is intended to create a guessing 
 *game by the computer to guess the birthday of 
 *individual till we get the right answer
 *author: Khalid
 *date : oct 20, 2019.
 *course : CSCI160.
*/
 
#include "calendar.hpp"
#include <iostream>
  using std :: cout;
  using std :: cin;
  using std :: endl;
  using std :: string;
/*
 *a month is a number between 1 and 12. 
 *getting the month of the year as an integer and return 
 *it inform of a string or return an empty string 
 *if the input is not within the range.
*/
string month_to_string(int month){
   if (month == 1)
      return "January";
   else if (month == 2)
	  return "february";
   else if (month == 3)
	  return "March";
   else if (month == 4)
	  return "April";
   else if (month == 5)
	  return "May";
   else if (month == 6)
	  return "June";
   else if (month == 7)
	  return "July";
   else if (month == 8)
	  return "August";
   else if (month == 9) 
	  return "September";
   else if (month == 10)
	  return "October";
   else if (month ==11)
	  return "November";
   else if (month == 12)
	  return "December";
   else 
	  return "";
}
// determines if the given year is a leap year and
// returns true if it is a leap or else false.
bool is_leap_year(int year){
     if (year%4==0 && year%100 != 0){
        
        return true;
     }
     else if (year%100 == 0 && year%400 == 0){
             return true;
     }
     else {
         return false;
     }
       
}
/*
 *determines the number of days in a month.if the month is 
 *equal two,then this value is checked in to comfirm if it is a leap
 *year or returns nothing if the value is out of range.
*/
int num_days_in_month(int month, int year) {
    switch(month){
     case 1:
     case 3:
     case 5:
     case 7:
     case 8:
     case 10:
     case 12:
         month = 31;
         break;
     case 4:
     case 6:
     case 9:
     case 11:
         month = 30;
         break;
     default:
             if(is_leap_year(year)){
	   			month = 29;
     		}else{
                month = 28;
             } 

       
   }
     
     return month;
 
}
/*
 *the computer makes an interactive guessing game to determine your 
 *birthday and continous until the computer gets the the month and
 *the actual day of the month.if the player was born in february,
 *the computer will ask the player what year he was born with the 
 *possibilty of an extra day in the month if it is a leap year.
*/
void guess_my_birthday(){	
  //declaring the variables 
	string my_string;
	int min = 1;
    int max = 12;
    bool correct_guess = false;
    int guess;
    string month;
    string junk;
    int year;
    bool right_guess = false;
    //counting the number of iteration.
	int guess_count = 0;
     //determing the correct month
	while(!correct_guess)
	{
		guess = (max + min)/2;
		cout << "is your birthday in " << month_to_string(guess)
		<<" yes or no: ";
		cin >> my_string; 
		if(my_string == "yes")
		{
			correct_guess = true;
		}
		if(my_string == "no")
		{
			cout <<"is your month after this month? yes or no: ";
      	  	cin >> my_string;
			getline(cin, junk);
			if(my_string == "no")
      	   	{
       		 	max = guess-1;
       	   	}
            	 
           	if(my_string == "yes")
           	{ 
              	min = guess + 1;
           	}
           	if(max==min)
           	{
             	correct_guess=true;
           	}
		}
		guess_count++ ;  	 
	} 
	guess = (max + min)/2;
	month = month_to_string(guess);
	if (month == "february"){
		cout <<"what year were you born? ";
		cin >> year;
	}
	string junk2;
	int min1 = 1;
	int maxmonth = num_days_in_month(guess, year);
	int guess2;
          
    //determining the correct day   
	while (!right_guess){
                
		guess2 = (maxmonth + min1)/2;
		cout << "is your birthday on " << month << " "
		<< guess2 << "? yes or no:";
		cin >> my_string;
                
		if(my_string == "yes"){
			right_guess = true;
		}
                
		if (my_string == "no"){
			cout << "is your birthday after this day yes or no:";
			cin>> my_string;
			getline(cin, junk2);
			if(my_string == "yes"){
				min1 = guess2 + 1;
			}
			if(my_string == "no"){ 
				maxmonth = guess2 - 1;  
			}
                     
			if(maxmonth == min1){
				right_guess = true;
				guess2 = maxmonth;
			}
		}
            
            guess_count++;
	}
                 
             
   cout << "it took " << guess_count << " guesses to find your birthday, which is "
    << month << " " << guess2 << endl;
          
}
 // calling the void function which contains all other function
 // in the main function for execution.
       
//int main() { guess_my_birthday();cout << "All done!\n";return 0;}




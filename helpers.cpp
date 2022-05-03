#include "include.h"

std::string get_file()
   {
       int count = 0;
       std::string _file;
       std::cout << "Please enter the file name.\n-> ";
       std::cin >> _file;
       std::ifstream file;
       file.open(_file);
       while(file.fail())
       {
          count++;
          std::cout<< "It seems that that file does not exist please try again\n-> ";
          std::cin >> _file;
          file.open(_file);
          if(!file.fail())
          {
              file.clear();
          }
          if(count == 4)
           {
               std::cout << "It seems that you are having trouble opening a file, would you like to exit the program?\nPlease enter yes or no\n-> ";
               bool _enter = enter();
               if(_enter)
               {
                   _file = "nofile";
                   return _file;
               }
               count = 0;
           }
       }
       return _file;
   };

   bool enter()
    {
   bool return_value;
   std::string yes_no;
   bool reprompt = false;
       while(!reprompt) // this is the first instance of input validation which only accepts yes or Yes or No or no and will keep prompting until valid
       {
           if(std::cin.fail()) std::cin.ignore(100,'\n'); // ignores the flag on the error
           std::cin >> yes_no;
           if(yes_no =="yes" || yes_no =="Yes")// the logic below compares the string to the 4 possible values, and then returns true or false to either enter the if statement or skip to the else statement in the main function
           {
               reprompt = true;
               return_value = true;
           }
           else if (yes_no =="no" || yes_no =="No")
           {
               reprompt = true;
               return_value = false;
           }
           else
           {
               std::cout<<"Please enter yes or no only\n-> ";
           }
       }
   return return_value;
} 

int path()
{
    std::cout<< "With the data that has been provided, we can run three different test on the data \n";
    std::cout<< "Option one will find the most fuel efficient route but will not maximize people served \n";
    std::cout<< "Option two will find the route that serves the most people but will not maximize fuel \n";
    std::cout<< "Option three will cover the most area for 12 gallons of gas \n";
    std::cout << "Please type in the interger 1,2,3 to choose the path you would like to choose \n";
    int decision;
    std::cin >> decision;
    while(std::cin.fail()) // only allows the user to enter a number of 1,2,3. acts as simple input validation 
    {
        std::cin.clear();// clears flag from cin.ignore() and ignores new data on each iteration 
        std::cin.ignore(250 , '\n');
        std::cout << "It Seems like you didn't provide a propper choice, please try again";
        std::cin >> decision;
    }
    std::cout<<"Before return ";
    return decision;

}
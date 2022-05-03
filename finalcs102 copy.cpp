#include<iostream>
#include <fstream>
int const SIZE = 7;
// visitedalres a struct galled Car with 3 members 
struct Car
{
    double gallons;
    int people;
    int visited;
};
struct return_value //visitedlares a struct with three members

{
    int x;
    int y;
    double value;
};
std::string getfile()
{
    std::string file;
    std::cout<< "What is the name of the file ?";
    std::cin >> file;
    return file;
}
/*
greet_user_return_name()
asks the user for their name
@param none  
@return std::string name 
*/
std::string greet_user_return_name()
{
    std::string name;
    std::cout<< "Hello, this program is designed to take your data and find the best route possible based on what you would like to see like maximizing people served or minimzing gasoline used.\n";
    std::cout<<"We kindly ask you to provide your name \n";
    std::cin >> name;
    return name;    
}
/*
enter_program_returns_bool(std::string name)
asks the user if they would like to enter the program
@param std::string name  
@return bool return_value 
*/
bool enter_program_returns_bool(std::string name)
{
    bool return_value;
    std::string yes_no;
    std::cout<< "Hello, " + name + " would you like to try our progam out? \n";
    std::cout<<"Please enter yes or no: \n";
    bool reprompt = false;
        while(!reprompt) // this is the first instance of input validation which only accepts yes or Yes or No or no and will keep prompting until valid
        {
            std::cin.ignore(100, '\n'); // ignores the flag on the error 
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
                std::cout<<"Please enter yes or no only\n";
            }
        }
    return return_value;
}
/*
recheck_user() 
asks the user if they would like to rerun the program
@param none 
@return bool retry 
*/
bool recheck_user() 
{
    std::cout << "Would you like to try the program out again? Please enter Yes or No.\n";
    std::string yes_no;
    bool retry;
    bool reprompt = false;
        while(!reprompt) // handels user errors and takes in string value and converts to bool
        {
            std::cin.ignore(100, '\n'); // simple input validation for accepting only yes and no
            std::cin >> yes_no;
            if(yes_no =="yes" || yes_no =="Yes")
            {
                reprompt = true;
                retry = true;
               
            }
            else if (yes_no =="no" || yes_no =="No")
            {
                reprompt = true;
                retry = false;
            }
            else
            {
                std::cout<<"Please enter yes or no only\n";
            }
        }
        return retry;
}

//get data put in array
/*
which_Car()
shows the user the three routes that can be ran all with diffrent outcomes 
@param none
@return int path 
*/
int which_Car()
{
    
    std::cout<< "With the data that has been provided, we can run three different test on the data \n";
    std::cout<< "Option one will find the most fuel efficient route but will not maximize people served \n";
    std::cout<< "Option two will find the route that serves the most people but will not maximize fuel \n";
    std::cout<< "Option three will cover the most area for 12 gallons of gas \n";
    std::cout << "Please type in the interger 1,2,3 to choose the path you would like to choose \n";
    int path;
    std::cin >> path;
    while(std::cin.fail()) // only allows the user to enter a number of 1,2,3. acts as simple input validation 
    {
        std::cin.clear();// clears flag from cin.ignore() and ignores new data on each iteration 
        std::cin.ignore(250 , '\n');
        std::cout << "It Seems like you didn't provide a propper choice, please try again";
        std::cin >> path;
    }
    std::cout<<"Before return ";
    return path;

}

/*
return_value functions 
these 8 function all work very similarly, they check all the spaces around the current position of a 2-D matrix
they return a return_value struct. it checks the values in the matrix and makes sure it doesn't go out of bounds 
@param return_value and Car **matrix (pointer to pointer which points to Matrix)
main point is to get the gallons from the matrix and assign the way variable to the postion of the value being returned and if its in the matrix
@return struct return_value 
*/
return_value up(return_value way, Car** matrix)
{
    if((way.x-1 >= 0 && way.x < SIZE && way.y >= 0 && way.y < SIZE ))
    {
        way.x = way.x-1;
        way.value = matrix[way.x][way.y].gallons;
    } else
    {
        way.value = -1;
    }
    return way;
    
};
return_value up_right(return_value way, Car **matrix)
{
    if((way.x-1 >= 0 && way.x < SIZE && way.y >= 0 && way.y+1 < SIZE ))
    {
        way.x = way.x-1;
        way.y = way.y+1;
        way.value = matrix[way.x][way.y].gallons;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value up_left(return_value way, Car** matrix)
{
    if((way.x-1 >= 0 && way.x < SIZE && way.y-1 >= 0 && way.y < SIZE ))
    {
        way.x = way.x-1;
        way.y = way.y-1;
        way.value = matrix[way.x][way.y].gallons;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value right(return_value way, Car** matrix)
{
    if((way.x >= 0 && way.x+1 < SIZE && way.y >= 0 && way.y < SIZE ))
    {
        way.y = way.y+1;
        way.value = matrix[way.x][way.y].gallons;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value right_down(return_value way, Car **matrix)
{
    if((way.x >= 0 && way.x+1 < SIZE && way.y >= 0 && way.y+1 < SIZE ))
    {
        way.x = way.x+1;
        way.y = way.y+1;
        way.value = matrix[way.x][way.y].gallons;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value down(return_value way, Car **matrix)
{
    if((way.x >= 0 && way.x+1 < SIZE && way.y >=0 && way.y < SIZE ))
    {
        way.x = way.x+1;
        way.value = matrix[way.x][way.y].gallons;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value down_left(return_value way, Car** matrix)
{
    if((way.x >= 0 && way.x+1 < SIZE && way.y-1 >= 0 && way.y < SIZE ))
    {
        way.x = way.x+1;
        way.y = way.y-1;
        way.value = matrix[way.x][way.y].gallons;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value left(return_value way, Car** matrix)
{
    if((way.x-1 >= 0 && way.x < SIZE && way.y >= 0 && way.y < SIZE ))
    {
        way.y = way.y-1;
        way.value =  matrix[way.x][way.y].gallons;
    } else
    {
        way.value = -1;
    }
    return way;
};


/*
return_value functions (only difference is it seraches for people value in matrix )
these 8 function all work very similarly, they check all the spaces around the current position of a 2-D matrix
they return a return_value struct. it checks the values in the matrix and makes sure it doesn't go out of bounds 
@param return_value and Car **matrix (pointer to pointer which points to Matrix)
main point is to get the people from the matrix and assign the way variable to the postion of the value being returned and if its in the matrix
@return struct return_value 
*/
return_value up_people(return_value way, Car** matrix)
{
    if((way.x-1 >= 0 && way.x < SIZE && way.y >= 0 && way.y < SIZE ))
    {
        way.x = way.x-1;
        way.value = matrix[way.x][way.y].people;
    } else
    {
        way.value = -1;
    }
    return way;
    
};
return_value up_right_people(return_value way, Car **matrix)
{
    if((way.x-1 >= 0 && way.x < SIZE && way.y >= 0 && way.y+1 < SIZE ))
    {
        way.x = way.x-1;
        way.y = way.y+1;
        way.value = matrix[way.x][way.y].people;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value up_left_people(return_value way, Car** matrix)
{
    if((way.x-1 >= 0 && way.x < SIZE && way.y-1 >= 0 && way.y < SIZE ))
    {
        way.x = way.x-1;
        way.y = way.y-1;
        way.value = matrix[way.x][way.y].people;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value right_people(return_value way, Car** matrix)
{
    if((way.x >= 0 && way.x+1 < SIZE && way.y >= 0 && way.y < SIZE ))
    {
        way.y = way.y+1;
        way.value = matrix[way.x][way.y].people;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value right_down_people(return_value way, Car **matrix)
{
    if((way.x >= 0 && way.x+1 < SIZE && way.y >= 0 && way.y+1 < SIZE ))
    {
        way.x = way.x+1;
        way.y = way.y+1;
        way.value = matrix[way.x][way.y].people;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value down_people(return_value way, Car **matrix)
{
    if((way.x >= 0 && way.x+1 < SIZE && way.y >=0 && way.y < SIZE ))
    {
        way.x = way.x+1;
        way.value = matrix[way.x][way.y].people;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value down_left_people(return_value way, Car** matrix)
{
    if((way.x >= 0 && way.x+1 < SIZE && way.y-1 >= 0 && way.y < SIZE ))
    {
        way.x = way.x+1;
        way.y = way.y-1;
        way.value = matrix[way.x][way.y].people;
    } else
    {
        way.value = -1;
    }
    return way;
};
return_value left_people(return_value way, Car** matrix)
{
    if((way.x-1 >= 0 && way.x < SIZE && way.y >= 0 && way.y < SIZE ))
    {
        way.y = way.y-1;
        way.value =  matrix[way.x][way.y].people;
    } else
    {
        way.value = -1;
    }
    return way;
};
//maximixing people
void main2(return_value &position,Car** matrix,double &gas)
{
   return_value temp;
   gas = gas - matrix[0][0].gallons;
   matrix[0][0].visited =1;
    while(gas > 0)
    {
    temp = position;
    temp.value = 0;
    return_value leftt = left_people(position, matrix);
    return_value rightt = right_people(position, matrix);
    return_value upp = up_people(position, matrix);
    return_value downn = down_people(position, matrix);
    return_value down_leftt = down_left_people(position, matrix);
    return_value right_downn = right_down_people(position, matrix);
    return_value up_rightt = up_right_people(position, matrix);
    return_value up_leftt = up_left_people(position, matrix);
    if((rightt.value > temp.value ))
    {
        if(rightt.value != -1)
        {
            if(matrix[rightt.x][rightt.y].visited != 1)
            {
            temp = rightt;
            }
        }
    }
    if((upp.value > temp.value ))
    {
        if( (upp.value != -1))
        {
            if(matrix[upp.x][upp.y].visited != 1)
            {
            temp = upp;
            }
        }
        
    }
     if((downn.value > temp.value))
    {
        if(downn.value != -1 )
        {
            if(matrix[downn.x][downn.y].visited != 1)
            {
        temp = downn;
            }
        }
    }
     if((down_leftt.value > temp.value ))
    {
        if(down_leftt.value != -1)
        {
            if(matrix[down_leftt.x][down_leftt.y].visited != 1)
            {
        temp = down_leftt;
            }
        }
    }
     if((right_downn.value > temp.value ))
    {
        if(right_downn.value != -1 )
        {
            if(matrix[right_downn.x][right_downn.y].visited != 1)
            {
                temp = right_downn;
            }
        }
    }
     if((up_rightt.value > temp.value))
    {
        if(up_rightt.value != -1)
        {
            if(matrix[up_rightt.x][up_rightt.y].visited != 1)
            {
                temp = up_rightt;
            }
        }
    }
     if((up_leftt.value  > temp.value))
    {
        if(up_leftt.value != -1 )
        {
            if(matrix[up_leftt.x][up_leftt.y].visited != 1)
            {
        temp = up_leftt;
            }
        }
    }
    if((gas - matrix[temp.x][temp.y].gallons) >= 0)
    {
        gas = gas - matrix[temp.x][temp.y].gallons ;
        matrix[temp.x][temp.y].visited = 1; 
    }
    else 
    {
        return;
    }
    position.x = temp.x;
    position.y = temp.y;
    }
}

void print(Car** matrix)
{
  for(int y = 0; y < SIZE; y++)
{
    for(int j =0; j < SIZE; j++)
    {
        std::cout<< "[" << matrix[y][j].gallons;
        std::cout << " ";
        std::cout<< matrix[y][j].people;
        std::cout << " ";
        std::cout<< matrix[y][j].visited << "], "  ; 
    }
    std::cout << "\n";
}
}
void print_map(Car** matrix)
{   
    for(int i =0; i < SIZE; i++)
    {
        for(int j =0; j < SIZE; j++)
        {
            
            if(matrix[i][j].visited == 0)
            {
                std::cout<< " * ";
            }
            else if(matrix[i][j].visited == 1)
            {
                std::cout << " ~ " ;
            }
        }
        std::cout<<"\n";
    }
}
// for minimizing gas
/*
main1 functions()
This function finds all possible paths and then picks the best path. Once the path is picked it changes the value in the matrix so we know
where to print. It also updates the temp postion on each iteration so it knows were to search text. Lastly it changes the gas value so we know when we are out of gas
@param return_value and Car **matrix and gas
@return: none
*/
void main1(return_value &position,Car** matrix,double &gas)
{
    gas = gas - matrix[0][0].gallons;
    matrix[0][0].visited = 1;
    return_value temp;
    while(gas > 0)
    {
    temp = position;
    temp.value = 10000;
    return_value leftt = left(position, matrix);
    return_value rightt = right(position, matrix);
    return_value upp = up(position, matrix);
    return_value downn = down(position, matrix);
    return_value down_leftt = down_left(position, matrix);
    return_value right_downn = right_down(position, matrix);
    return_value up_rightt = up_right(position, matrix);
    return_value up_leftt = up_left(position, matrix);
    if((rightt.value < temp.value ))
    {
        if(rightt.value != -1)
        {
            if(matrix[rightt.x][rightt.y].visited != 1)
            {
                temp = rightt;
            }
        }
    }
    if((upp.value < temp.value ))
    {
        if( (upp.value != -1))
        {
            if(matrix[upp.x][upp.y].visited != 1)
            {
                temp = upp;
            }
        }
    }
     if((downn.value < temp.value))
    {
        if(downn.value != -1 )
        {
            if(matrix[downn.x][downn.y].visited != 1)
            {
                temp = downn;
            }
        }
    }
     if((down_leftt.value< temp.value ))
    {
        if(down_leftt.value != -1)
        {
            if(matrix[down_leftt.x][down_leftt.y].visited != 1)
            {
                temp = down_leftt;
            }
        }
    }
     if((right_downn.value < temp.value ))
    {
        if(right_downn.value != -1 )
        {
            if(matrix[right_downn.x][right_downn.y].visited != 1)
            {
                temp = right_downn;
            }
        }
    }
     if((up_rightt.value < temp.value))
    {
        if(up_rightt.value != -1)
        {
            if(matrix[up_rightt.x][up_rightt.y].visited != 1)
            {
                temp = up_rightt;
            }
        }
    }
     if((up_leftt.value  < temp.value))
    {
        if(up_leftt.value != -1 )
        {
            if(matrix[up_leftt.x][up_leftt.y].visited != 1)
            {
                temp = up_leftt;
            }
        }
    }
    
    gas = gas - matrix[temp.x][temp.y].gallons;
    if(gas > 0)
    {
        matrix[temp.x][temp.y].visited = 1;
    } else
    {
        gas = gas + matrix[temp.x][temp.y].gallons;
        return;
    }
    position.x = temp.x;
    position.y = temp.y;
    }
}

void say_goodbye(std::string name)
{
    std::cout << "Thank you " << name  << " for using our program! We hope you enjoyed it and found it to be usefull";
}

int main()
{
    std::string name = greet_user_return_name();
    bool enter_program = enter_program_returns_bool(name);
while(enter_program)
{
    std::string file_name = getfile(); 
    std::ifstream in_file;
    in_file.open(file_name); // this part of the loop gets the txt file name and reprompts until a valid file is entered
    while (in_file.fail())
    {
       std::cout<<"Sorry that file did not work please try again !\n";
       std::string file_name = getfile();
        in_file.open(file_name);
       if(!in_file.fail()){
         in_file.clear();
       }
    }

    Car** matrix = new Car*[SIZE]; // visitedlares pointer to a pointer with dynamic memory
    for(int i = 0; i < SIZE;i++)
    {
        matrix[i] = new Car[SIZE];
    }
    for(int i = 0; i < SIZE; i++)
    {
        for(int j =0; j < SIZE; j++)
        {
            in_file >> matrix[i][j].gallons;
            in_file >> matrix[i][j].people ;
            matrix[i][j].visited = 0;    
        }
    }
    int path_to_take;
    path_to_take = which_Car(); // gets the path to take
    std::cout << "Path taken " << path_to_take << "\n";
   
    if(path_to_take == 1)
    {
    return_value beginning; // assigns the first position of the struct tp [0,0] and then runs the functions to execute the program
    beginning.x =0;
    beginning.y=0;
        double gas;
        gas = 12;
        beginning.value = matrix[0][0].gallons;
        main1(beginning,matrix,gas);
        print(matrix);
        std::cout << "Amount of gas left over "<<gas << " gallons\n";
        print_map(matrix);
        gas = 0;
        delete[] matrix; // deletes the dynamic memory to limit the chance of data leaks 
    }
    else if(path_to_take == 2)
    {
    return_value beginning;
        beginning.x =0;
        beginning.y=0;
        beginning.value = matrix[0][0].people;
        double gas;
        gas = 12;
        main2(beginning,matrix,gas);
        print(matrix);
        std::cout << "Amount of gas left over "<<gas << " gallons \n";
        print_map(matrix);
        gas = 0;
        //std::cout<<"beginning values " << beginning.x <<" " << beginning.x << " " << beginning.value << "\n";
         delete[] matrix;
    }
    else
    {
        return_value beginning; 
	    beginning.x =0;
       beginning.y=0;
       beginning.value = matrix[0][0].people;
       double gas;
       gas = 12;
       main2(beginning,matrix,gas);
       print(matrix);
       std::cout << "Amount of area left to cover "<<gas << "\n";
       print_map(matrix);
       gas = 0;

    }
    
    
    enter_program = recheck_user(); // checks the user one last time and then says good bye
    if(enter_program == false)
    {
        say_goodbye(name);
        return 0;
    }
}
std::cout << "We are sorry that that you couldnt find any purpose in our program but we will be here when you need it.";
    
}
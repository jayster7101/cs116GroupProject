#include "helpers.h"

 int main()
 {

     std::string _file = get_file();
     std::ifstream in_file;
    in_file.open(_file);

    Node** matrix = new Node*[SIZE]; // visitedlares pointer to a pointer with dynamic memory
    for(int i = 0; i < SIZE;i++)
    {
        matrix[i] = new Node[SIZE];
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
 }
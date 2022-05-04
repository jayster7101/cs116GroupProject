#include "helpers.h"

 int main()
 {
     int SIZE = 5;
     Node** matrix = new Node*[SIZE];
    std::string _file = get_file();
    read_line(_file, matrix);

    std::cout << matrix[0][0].get_gallons();



 }
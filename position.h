#ifndef POSITION_H
#define POSITION_H
/**
 * could use template class
 * would need to change the double of value to type T
 * this would be smart since we are looking at two different type
 * 
 * 
 *  @note 
 *  Instead of making 8 different functions
 *  you can make one and pass is the +1 or -1 to search positions 
 *  would be a template function because the type being modified -> value 
 *  would be of type int or double and wouldn't want to perform wrong opperation
 * 
 */

int SIZE; // ONLY USED FOR DEVELOPMENT 

template <typename T>
class Position
{
    public:
    Position<T> get_value(); // will be used to get the value wether it be int or double

    Position<T> next_s(int, int, Node**);
    Position<T> next_g(int, int, Node**);

    int get_x() const;
    int get_y() const;

    private:
    int x;
    int y;
    T value; // change to T if creating a template class
};

/**
 * @warning when calling this function, be sure to initialize 
 * 
 * @tparam T 
 * @param x 
 * @param y 
 * @return Position<T> 
 */
template<typename T>
Position<T> Position<T>::next_s(int x, int y, Node** matrix) // when passing in x and y values,  call function like this Position<type>next( <current x position +- # >, <current y position +- #>, T)
{
    if( ( x >= 0 ) && ( x < SIZE ) && ( y >= 0 ) && (y < SIZE ) ) // if in bounds of array continue 
    {
        this->x = x; // change 
        this->y = y;
        this->value = matrix[x][y].get_served();
    }
    else
    {
        this->value = -1;
    }
    return this;
}

template<typename T>
Position<T> Position<T>::next_g(int x, int y, Node** matrix) // when passing in x and y values,  call function like this Position<type>next( <current x position +- # >, <current y position +- #>, T)
{
    if( ( x >= 0 ) && ( x < SIZE ) && ( y >= 0 ) && (y < SIZE ) ) // if in bounds of array continue 
    {
        this->x = x; // change 
        this->y = y;
        this->value = matrix[x][y].get_gallons();
    }
    else
    {
        this->value = -1; // means that no spot exists , x and y coordinates will be the same from which parent node calls, each iteration of algo will have parent node, which is the previous selected node 
    }
    return this; // returns a position type with new data or returns the parent node aka prevous iteration nodes x and y values, but will have value set to -1
}

#endif

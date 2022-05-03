#ifndef Node_H
#define Node_H
class Node
{
    public:
    Node();
    Node(double, int);
    void set_gallons(double);
    double get_gallons() const;
    void set_served(int);
    int get_served()const;
    void set_visited(int);
    int get_visited()const;

    private:
    double gallons;
    int served;
    int visited;
};
#endif
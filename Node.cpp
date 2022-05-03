#include "include.h"
    Node::Node()
    {
        visited = 0;
    }
    Node::Node(double _gallons, int _served)
    {
        gallons = _gallons;
        served = _served;
        visited = 0;
    }
    void Node::set_gallons(double _gallons)
    {
        gallons = _gallons;
    }
    double Node::get_gallons() const
    {
        return gallons;
    }
    void Node::set_served(int _served)
    {
        served = _served;
    }
    int Node::get_served()const
    {
        return served;
    }
    void Node::set_visited(int _visited)
    {
        visited = _visited;
    }
    int Node::get_visited()const
    {
        return visited;
    } 
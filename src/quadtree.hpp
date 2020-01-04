#ifndef QUADTREE_HPP
#define QUADTREE_HPP
#include <vector>
#include <iostream>
#include "quadnode.hpp"
#include "quadnode.cpp"

class Quadtree
{   
public:
    std::vector<Point> points;
    void read_points();

    Quadtree(); 
    ~Quadtree();
};

#endif
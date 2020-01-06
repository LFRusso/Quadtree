#ifndef QUADTREE_HPP
#define QUADTREE_HPP
#include <vector>
#include <iostream>
#include <string>
#include "quadnode.hpp"

class Quadtree
{   
public:
    int width, length;

    double x1{0}, x2{0}, y1{0}, y2{0};
    Quadnode* quadnode;
    std::vector<Point> points;
    int no_points{0};

    void read_from_table(std::string filename);
    void read_from_matrix(std::string filename);

    void visualize(std::ofstream &data);

    void start();
    void query(int val);
};

#endif
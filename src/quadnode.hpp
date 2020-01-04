#ifndef QUADNODE_HPP
#define QUADNODE_HPP
#include "point.h"
#include <vector>

class Quadnode
{
public:
    int x1, x2, y1, y2;
    int max_content = 50;
    int content= 0;
    std::vector<Point> points;

    Quadnode* sw;
    Quadnode* se;
    Quadnode* nw;
    Quadnode* ne;

    bool isleaf = true;
    
    void insert(Point point);

    void divide();

    void querry();

    bool contains(Point point);

    Quadnode(int x1, int x2, int y1, int y2);
    ~Quadnode();
};

#endif
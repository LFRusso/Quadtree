#ifndef QUADNODE_HPP
#define QUADNODE_HPP

#include <SFML/Graphics.hpp>
#include <fstream>
#include "point.h"
#include <vector>

class Quadnode
{
public:
    double x1, x2, y1, y2;
    int max_content = 2;
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

    void draw(sf::RenderWindow &window);
    void view(std::ofstream &data);

    Quadnode(double x1, double x2, double y1, double y2);
    ~Quadnode();
};

#endif
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "quadtree.hpp"

void Quadtree::start()
{
    quadnode = new Quadnode(x1 - 10, x2 + 10, y1 - 10, y2 + 10);   
    for(int i=0; i< this->no_points; i++)
    {
        quadnode->insert(points[i]);
    }
}

void Quadtree::read_from_table(std::string filename)
{     
    std::ifstream file;
    file.open(filename);
    double x, y;
    Point point;

    if (!file)
    {
        std::cout << "\nError opening file.\n";
        return;
    }

    while(file >> x >> y)
    {
        if(x<x1){x1 = x;}
        if(x>x2){x2 = x;}
        if(y<y1){y1 = y;}
        if(y>y2){y2 = y;}

        point.x = x;
        point.y = y;
        this->points.push_back(point);
        no_points++;
    }
    file.close();
}

void Quadtree::read_from_matrix(std::string filename)
{

}

void Quadtree::visualize(std::ofstream &data)
{
    quadnode->view(data);
}
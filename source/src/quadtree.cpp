#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "quadtree.hpp"

void Quadtree::start()
{   
    std::cout << "Building quadtree\n";
    quadnode = new Quadnode(x1 - 10, x2 + 10, y1 - 10, y2 + 10);   
    for(int i=0; i< this->no_points; i++)
    {
        quadnode->insert(points[i]);
    }
    std::cout << "Quadtree built successfully\n";
}

void Quadtree::read_from_table(std::string filename)
{     
    std::ifstream file;
    file.open(filename);
    
    double x, y;
    Point point;

    if (!file)
    {
        std::cout << "\nError reading file.\n";
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

void Quadtree::read_labeled(std::string filename)
{
    this->labeled = true;
    std::ifstream file;
    file.open(filename);
    
    double x, y;
    std::string label;
    Point point;

    if (!file)
    {
        std::cout << "\nError reading file.\n";
        return;
    }
    while(file >> x >> y >> label)
    {
        if(x<x1){x1 = x;}
        if(x>x2){x2 = x;}
        if(y<y1){y1 = y;}
        if(y>y2){y2 = y;}

        point.x = x;
        point.y = y;
        point.label = label;
        this->points.push_back(point);
        no_points++;
    }
    file.close();
}

void Quadtree::read_from_matrix(std::string filename){}

void Quadtree::visualize()
{
    std::ofstream data;
    data.open("./output/rects.dat");
    quadnode->view(data);
    data.close();
}

void Quadtree::query(int val)
{   
    std::ofstream file;
    switch(val)
    {
    case 0:
        std::cout << "Querying for points separation\n";
        file.open("./output/distances.dat");
        quadnode->query_distances(file, labeled);
        file.close();
        std::cout << "Finished querying\n";
        break;
    
    default:
        break;
    }
}
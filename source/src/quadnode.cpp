#include <iostream>
#include <fstream>
#include <cmath>
#include "quadnode.hpp"
#include "point.h"

void Quadnode::insert(Point point)
{ 
    if(this->contains(point))
    {
        if(isleaf){
            if(content >= max_content)
            { 
                this->divide();
                sw->insert(point);
                nw->insert(point);
                ne->insert(point);
                se->insert(point);
            } else {
                content++;
                points.push_back(point);
            }
        } else
        {
            sw->insert(point);
            nw->insert(point);
            ne->insert(point);
            se->insert(point);
        }
    }
}

bool Quadnode::contains(Point point)
{
    if(point.x >= this->x1 and point.x < this->x2 and
    point.y >= this->y1 and point.y < this->y2)
    {
        return true;
    } else {
        return false;
    }
}

void Quadnode::divide()
{
    isleaf = false;
    
    sw = new Quadnode(x1, x1 + ((x2-x1)/2), y1, y1 + ((y2-y1)/2));
    nw = new Quadnode(x1, x1 + ((x2-x1)/2), y1 + ((y2-y1)/2), y2);
    ne = new Quadnode(x1 + ((x2-x1)/2), x2, y1 + ((y2-y1)/2), y2);
    se = new Quadnode(x1 + ((x2-x1)/2), x2, y1, y1 + ((y2-y1))/2);

    for(int i=0; i < max_content; i++)
    {
        sw->insert(points[i]);
        nw->insert(points[i]);
        ne->insert(points[i]);
        se->insert(points[i]);
    }
    this->points.clear();
}

void Quadnode::view(std::ofstream &data)
{

    data << x1 << " " << x2 << " " << y1 << " " << y2 <<"\n";
    if(!isleaf)
    {
        sw->view(data);
        se->view(data);
        nw->view(data);
        ne->view(data);
    }
}

void Quadnode::query_distances(std::ofstream &file)
{   
    if(isleaf)
    {
        for(int i=0; i < content; i++)
        {
            for(int j= i+1; j < content; j++)
            {
                file << points[i].x << " " << points[i].y << " " << points[j].x << " " << points[j].y << " " << this->distance(points[i], points[j]) << "\n";
            }
        }
    } else {
        sw->query_distances(file);
        se->query_distances(file);
        nw->query_distances(file);
        ne->query_distances(file);
    }
}

double Quadnode::distance(Point point1, Point point2)
{
    return pow(pow(point1.x-point2.x, 2) + pow(point1.y - point2.y,2),0.5);
}

Quadnode::Quadnode(double x1, double x2, double y1, double y2)
{  
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}

Quadnode::~Quadnode(){}
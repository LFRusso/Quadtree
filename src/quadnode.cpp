#include <iostream>
#include "quadnode.hpp"
#include "point.h"

Quadnode::Quadnode(int x1, int x2, int y1, int y2)
{  
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
};

Quadnode::~Quadnode(){};


void Quadnode::insert(Point point)
{ 
    if(this->contains(point))
    {
        this->content++;
        if(this->content > this->max_content)
        {
            this->divide();
            sw->insert(point);
            nw->insert(point);
            ne->insert(point);
            se->insert(point);

        } else {
            this->points.push_back(point);
        }
    }
};

bool Quadnode::contains(Point point)
{
    if(point.x >= this->x1 and point.x <= this->x2 and
    point.y >= this->y1 and point.y <= this->y2)
    {
        return true;
    } else {
        return false;
    }
};

void Quadnode::divide()
{
    this->isleaf = false;

    sw = new Quadnode(x1, int((x2-x1)/2), y1, int((y2-y1)/2));
    nw = new Quadnode(x1, int((x2-x1)/2), int((y2-y1)/2), y2);
    ne = new Quadnode(int((x2-x1)/2), x2, int((y2-y1)/2), y2);
    se = new Quadnode(int((x2-x1)/2), x2, y1, int((y2-y1))/2);

    for(int i=0; i<=3; i++)
    {
        sw->insert(this->points[i]);
        nw->insert(this->points[i]);
        ne->insert(this->points[i]);
        se->insert(this->points[i]);
    }
    this->points.clear();
};

void Quadnode::querry()
{

};
#include <iostream>
#include <fstream>
#include "src/quadtree.hpp"

Quadtree quadtree;
std::string datafile;

int start()
{
    quadtree.read_from_table(datafile);
    quadtree.start();
    quadtree.query(0);
    quadtree.visualize();
    return 0;
}

int main(){
    std::cin >> datafile;
    start();
    return 0;
}
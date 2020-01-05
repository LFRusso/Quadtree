#include <iostream>
#include <fstream>
#include "src/quadtree.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main(){
    Quadtree quadtree;
    quadtree.read_from_table("table.dat");
    quadtree.start();
    std::ofstream data;
    data.open("rects.dat");
    quadtree.visualize(data);
    data.close();
    return 0;
}
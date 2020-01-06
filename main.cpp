#include <iostream>
#include <fstream>
#include "src/quadtree.hpp"

int main(){

    // Setting up quadtree from dataset
    Quadtree quadtree;
    quadtree.read_from_table("table.dat"); // change input file name here 
    quadtree.start();

    // Rectangles output file
    quadtree.visualize();

    // Query for something in the quadtree
    quadtree.query(0); // 0 = points separation

    return 0;
}
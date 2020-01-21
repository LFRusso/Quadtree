#include <iostream>
#include <fstream>
#include "src/quadtree.hpp"

Quadtree quadtree;
std::string datafile;
bool enable_labels{false};

int start()
{
    if(enable_labels)
    {
        quadtree.read_labeled(datafile);
    } else {
        quadtree.read_from_table(datafile);
    }

    quadtree.start();
    quadtree.query(0);
    quadtree.visualize();
    return 0;
}

int main(){
    std::cin >> datafile >> enable_labels;
    if(!enable_labels){
        std::cout << "falso" << std::endl;
    }
    start();
    return 0;
}
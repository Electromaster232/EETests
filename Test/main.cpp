//
//  main.cpp
//  Test
//
//  Created by Adam Gilbert (student HH) on 11/30/22.
//

#include <iostream>
#include <sstream>

#include "test1.hpp"
#include "test407.hpp"
#include "test154.hpp"

int main(int argc, char *argv[])
{
    //std::cout << argc << std::endl;
    if (argc < 3){
        std::cout << "Please specify Test # to Run" << std::endl;
        return 1;
    }
    
    // Convert argv(s) to int or long
    std::istringstream ss(argv[1]);
    std::istringstream sv(argv[2]);
    //std::cout << argv[2];
    //std::cout << "test";
    int x;
    std::string y;
    ss >> x;
    sv >> y;
    //std::cout << y;
    
    switch(x){
        case 1:
            test1(std::stoll(y));
            break;
        case 407:
            test407(std::stoi(y));
            break;
        case 154:
            test154(y);
            break;
        default:
            std::cout << "Please specify a valid test" << std::endl;
            break;
    }
    return 2;
}

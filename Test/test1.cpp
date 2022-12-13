//
//  test1.cpp
//  EETests
//
//  Created by Adam Gilbert (student HH) on 12/2/22.
//

#include "test1.hpp"

int test1(unsigned long long last){
        
      std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        
      
      // not including that number
      last--;

      // find sum of all numbers divisible by 3 or 5
        
        auto x = last / 3;
        auto sumThree   =  3 * x * (x + 1) / 2;
        x = last / 5;
        auto sumFive    =  5 * x * (x + 1) / 2;

      // however, those numbers divisible by 3 AND 5 will be counted twice
        x = last/15;
        auto sumFifteen = 15 * x * (x + 1) / 2;
      
      std::cout << (sumThree + sumFive - sumFifteen) << ",";
      std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
      
    std::chrono::duration<double, std::milli> time_span = (t2 - t1);
        
        std::cout << time_span.count() << std::endl;
        
    

    return 0;
}

//
//  main.cpp
//  introduction_to_the_design_and_analysis_of_algorithms
//
//  Created by pengsida on 16/9/20.
//  Copyright © 2016年 pengsida. All rights reserved.
//

#include <iostream>
//#include "gcd.h"
//#include "graph_algorithm.h"
#include "brute_force.h"
#include "hanoi.h"

int main()
{
    brute_force test;
    vector<int> A;
    A.push_back(1);
    A.push_back(0);
    A.push_back(1);
    A.push_back(0);
    A.push_back(1);
    A.push_back(0);
    A.push_back(1);
    test.solution_3_14(A);
    for(size_t i = 0; i < A.size(); ++i)
        cout << A[i] << ' ';
    cout << endl;
    return 0;
}



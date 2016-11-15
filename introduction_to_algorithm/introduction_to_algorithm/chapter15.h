//
//  chapter15.h
//  introduction_to_algorithm
//
//  Created by pengsida on 2016/11/15.
//  Copyright © 2016年 pengsida. All rights reserved.
//

#ifndef chapter15_h
#define chapter15_h

#include <iostream>
#include <vector>

using namespace std;

class dp_algorithm
{
    vector<vector<int>> assemble_line(vector<vector<int>> cost_time, vector<vector<int>> move_time, vector<int> enter_time, vector<int> exit_time, int num)
    {
        vector<vector<int>> finish_time;
        finish_time.push_back(vector<int>());
        finish_time.push_back(vector<int>());
        vector<vector<int>> line;
        line.push_back(vector<int>());
        line.push_back(vector<int>());
        finish_time[0].push_back(cost_time[0][0]+enter_time[0]);
        finish_time[1].push_back(cost_time[1][0]+enter_time[1]);
        for(int i=1; i < num; ++i)
        {
            if(finish_time[0][i-1] <= finish_time[1][i-1] + move_time[1][i-1])
            {
                finish_time[0].push_back(finish_time[0][i-1] + cost_time[0][i-1]);
                line[0].push_back(0);
            }
            else
            {
                finish_time[0].push_back(finish_time[1][i-1] + move_time[1][i-1] + cost_time[0][i-1]);
                line[0].push_back(1);
            }
            
            if(finish_time[1][i-1] <= finish_time[0][i-1] + move_time[0][i-1])
            {
                finish_time[1].push_back(finish_time[1][i-1] + cost_time[1][i]);
                line[1].push_back(1);
            }
            else
            {
                finish_time[1].push_back(finish_time[0][i-1] + move_time[0][i-1] + cost_time[1][i]);
                line[1].push_back(0);
            }
        }
        
        if((finish_time[0][num-1] + exit_time[0]) <= (finish_time[1][num-1] + exit_time[1]))
        {
            line[0].push_back(0);
            line[1].push_back(0);
        }
        else
        {
            line[0].push_back(1);
            line[1].push_back(1);
        }
        return line;
    }
};

#endif /* chapter15_h */

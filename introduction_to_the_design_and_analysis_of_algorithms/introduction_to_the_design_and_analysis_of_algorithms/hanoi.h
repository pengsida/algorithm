//
//  hanoi.h
//  introduction_to_the_design_and_analysis_of_algorithms
//
//  Created by pengsida on 16/9/28.
//  Copyright © 2016年 pengsida. All rights reserved.
//

#ifndef hanoi_h
#define hanoi_h

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class hanoi
{
private:
    typedef size_t size_type;
    typedef stack<size_t> stack;
    typedef vector<stack> vector;
    
    static stack initial(size_type size)
    {
        stack tmp;
        for(size_t i = size; i >= 1; --i)
            tmp.push(i);
        return tmp;
    }
    
    static void transfer(stack& from, stack& to)
    {
        to.push(from.top());
        from.pop();
    }
    
    static void show(stack& cur)
    {
        while(!cur.empty())
        {
            cout << cur.top() << endl;
            cur.pop();
        }
    }
    
public:
    void hanoi_without_recursion(size_type size)
    {
        vector solution;
        solution.push_back(initial(size));
        solution.push_back(stack());
        solution.push_back(stack());
        size_t order = 0;
        while(solution[1].size() != size && solution[2].size() != size)
        {
            size_t next = order;
            ++next;
            if(next == 3)
                next = 0;
            solution[next].push(solution[order].top());
            solution[order].pop();
            if(solution[1].size() == size || solution[2].size() == size)
                break;
            size_t tmp = next;
            if(next == 0)
                next = 1;
            else if(next == 1)
                next = 2;
            else
                next = 0;
            if(solution[order].empty())
                transfer(solution[next], solution[order]);
            else if(solution[next].empty())
                transfer(solution[order], solution[next]);
            else
            {
                if(solution[order].top() < solution[next].top())
                    transfer(solution[order], solution[next]);
                else
                    transfer(solution[next], solution[order]);
            }
            order = tmp;
        }
        if(!solution[1].empty())
            show(solution[1]);
        else
            show(solution[2]);
    }
    
    void hanoi_with_recursion(int n, char a, char b, char c)
    {
        if(n >= 1)
        {
            hanoi_with_recursion(n-1, a, c, b);
            cout << a << " --> " << c;
            hanoi_with_recursion(n-1, b, a, c);
        }
    }
};


#endif /* hanoi_h */

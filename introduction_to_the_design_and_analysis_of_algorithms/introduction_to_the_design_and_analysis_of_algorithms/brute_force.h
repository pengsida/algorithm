//
//  brute_force.h
//  introduction_to_the_design_and_analysis_of_algorithms
//
//  Created by pengsida on 16/9/22.
//  Copyright © 2016年 pengsida. All rights reserved.
//

#ifndef brute_force_h
#define brute_force_h

#include <vector>

using namespace std;


struct edge
{
    size_t to;
    int weight;
};

class brute_force
{
private:
    typedef size_t size_type;
    typedef vector<vector<edge>> graph;
    
private:
    template<typename DataType>
    class less_brute_force
    {
    public:
        bool operator()(const DataType& x, const DataType& y)
        {
            return x < y;
        }
    };
    
    template<typename DataType>
    void swap(DataType& x, DataType& y)
    {
        DataType tmp = x;
        x = y;
        y = tmp;
    }
    
public:
    // 选择算法不是稳定的
    template<typename T, typename Compare = less_brute_force<T>>
    void selection_sort(vector<T>& A)
    {
        const size_type size = A.size();
        for(size_type i = 0; i < size - 1; ++i)
        {
            size_type min = i;
            for(size_type j = i + 1; j < size; ++j)
                if(Compare()(A[j], A[min]))
                    min = j;
            if(min != i)
                swap(A[min], A[i]);
        }
    }
    
    // 冒泡排序是稳定的
    template<typename T, typename Compare = less_brute_force<T>>
    void bubble_sort(vector<T> A)
    {
        const size_type size = A.size();
        for(size_type i = 0; i < size - 1; ++i)
            for(size_type j = 0; j < size - 1 - i; ++j)
                if(Compare()(A[j+1], A[j]))
                    swap(A[j+1], A[j]);
    }
    
    bool is_circle_3_1_5(const graph& g) const
    {
        const size_type size = g.size();
        size_type times = 0;
        size_t index = 0;
        size_t last_index = 0;
        while(times < size)
        {
            if(g[index].size() != 2)
                return false;
            size_t next_index = 0;
            for(size_t i = 0; i < g[index].size(); ++i)
                if(g[index][i].to != last_index)
                {
                    next_index = g[index][i].to;
                    break;
                }
            last_index = index;
            size_t j = 0;
            for(j = 0; j < g[next_index].size(); ++j)
                if(g[next_index][j].to == last_index)
                    break;
            if(j == g[next_index].size())
                return false;
            if(next_index == 0)
                return true;
            ++times;
        }
        return false;
    }
    
    bool is_star_3_1_5(const graph& g) const
    {
        size_t star_center = 0;
        if(g[star_center].empty())
            return false;
        if(g[star_center].size() == 1)
            star_center = g[star_center][0].to;
        if(g[star_center].size() != g.size() - 1)
            return false;
        for(size_t i = 0; i < g[star_center].size(); ++i)
        {
            size_t point_to = g[star_center][i].to;
            if(point_to == star_center)
                return false;
            if(g[point_to].size() != 1)
                return false;
            if(g[point_to][0].to != star_center)
                return false;
        }
        return true;
    }
    
    bool is_complete_3_1_5(const graph& g) const
    {
        const size_type size = g.size();
        for(size_type i = 0; i < size; ++i)
        {
            if(g[i].size() != g.size() - 1)
                return false;
            for(size_type j = 0; j < g[i].size(); ++j)
                if(g[i][j].to == i)
                    return false;
        }
        return true;
    }
    
    void solution_3_14(vector<int>& A)
    {
        int index = 0;
        for(size_type i = 0; i < A.size(); ++i)
        {
            if(A[i] == 0)
            {
                swap(A[i], A[index]);
                ++index;
            }
        }
    }
    
    template<typename T>
    int sequential_search_2(const vector<T>& A, const T key)
    {
        const size_type size = A.size();
        for(size_type i = 0; i < size; ++i)
            if(A[i] == key)
                return (int)i;
        return -1;
    }
};


#endif /* brute_force_h */

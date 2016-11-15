//
//  graph_algorithm.h
//  introduction_to_the_design_and_analysis_of_algorithms
//
//  Created by pengsida on 16/9/20.
//  Copyright © 2016年 pengsida. All rights reserved.
//

#ifndef graph_algorithm_h
#define graph_algorithm_h
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct edge
{
    size_t to;
    int weight;
    
    bool operator==(const edge& rhs) const{return to == rhs.to;}
};

class Graph
{
private:
    typedef size_t node_num;
    typedef size_t size_type;
    typedef size_t TIME;
    
    enum COLOR
    {
        WHITE,
        GRAY,
        BLACK
    };
    
private:
    void deepth_first_search_aux(size_type cur_vertex, TIME& time, vector<TIME>& start_time, vector<TIME>& finish_time, vector<COLOR>& color, vector<node_num>& prev) const
    {
        color[cur_vertex] = GRAY;
        ++time;
        start_time[cur_vertex] = time;
        size_type size = graph[cur_vertex].size();
        for(size_type i = 0; i < size; ++i)
            if(color[graph[cur_vertex][i].to] == WHITE)
            {
                prev[graph[cur_vertex][i].to] = cur_vertex;
                deepth_first_search_aux(cur_vertex, time, start_time, finish_time, color, prev);
            }
        color[cur_vertex] = BLACK;
        ++time;
        finish_time[cur_vertex] = time;
    }
    
    vector<TIME> topological_sort_dfs() const
    {
        vector<COLOR> color(graph.size(), WHITE);
        vector<node_num> prev(graph.size(), -1);
        vector<TIME> start_time(graph.size(), 0);
        vector<TIME> finish_time(graph.size(), 0);
        TIME time = 0;
        const size_type size = graph.size();
        for(size_type i = 0; i < size; ++i)
            if(color[i] == WHITE)
                deepth_first_search_aux(i, time, start_time, finish_time, color, prev);
        return finish_time;
    }
    
public:
//    广度优先搜索，用于发现可从s到达的所有顶点，并计算s到所有可达顶点之间的距离
    // 下面只适合无权图
    void breadth_first_search(node_num start) const
    {
        vector<COLOR> color(graph.size(), WHITE);
        vector<int> distance(graph.size(), INT_MAX);
        vector<node_num> prev(graph.size(), -1);
        color[start] = GRAY;
        distance[start] = 0;
        queue<node_num> Q;
        Q.push(start);
        while(!Q.empty())
        {
            node_num from = Q.front();
            Q.pop();
            size_type size = graph[from].size();
            for(size_type i = 0; i < size; ++i)
            {
                node_num to = graph[from][i].to;
                if(color[to] == WHITE)
                {
                    color[to] = GRAY;
                    distance[to] = distance[from] + 1;
                    prev[to] = from;
                    Q.push(to);
                }
            }
            color[from] = BLACK;
        }
    }
    
    // 深度优先搜索，就是尽可能深地搜索一个图。
    // 在最新发现的顶点，如果它还有以此为起点而未探测到的边，就沿此边探测下去
    // 当一个顶点的所有边都已被探寻过后，搜索将回溯到还有未探寻的连接顶点的顶点
    // 当源顶点的所有边都被探寻了，则选择一个新源顶点，重复上述过程
    // 下面的算法中使用了时间戳，对推算深度优先搜索的进行情况由很大的帮助
    // 深度优先算法非递归可以用stack实现
    void deepth_first_search() const
    {
        vector<COLOR> color(graph.size(), WHITE);
        vector<node_num> prev(graph.size(), -1);
        vector<TIME> start_time(graph.size(), 0);
        vector<TIME> finish_time(graph.size(), 0);
        TIME time = 0;
        const size_type size = graph.size();
        for(size_type i = 0; i < size; ++i)
            if(color[i] == WHITE)
                deepth_first_search_aux(i, time, start_time, finish_time, color, prev);
    }
    
    // 拓扑排序只能用于有向无回路图
    // 一个图的拓扑排序可以看成是图中所有顶点沿水平线排列而成的一个序列，使得所有的有向边均从左指向右
    void topological_sort() const
    {
        vector<TIME> finish_time = topological_sort_dfs();
        set<pair<TIME, node_num>, greater<TIME>> result;
        const size_type size = finish_time.size();
        for(size_type i = 0; i < size; ++i)
            result.insert({finish_time[i], i});
    }
    
    // 强连通分支：一个最大的顶点集合，对于集合中的每一对顶点u和v都是互相可达的
    
    
private:
    //图的表示，理解表法
    vector<vector<edge>> graph;
};

#endif /* graph_algorithm_h */

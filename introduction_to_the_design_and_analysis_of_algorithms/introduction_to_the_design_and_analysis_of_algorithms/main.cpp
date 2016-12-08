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
//#include "brute_force.h"
//#include "hanoi.h"

void merge(int a[],int n,int b[],int m,int c[])
{
    int i,j,l,z;
    int test;
    for(i=0;i<n;i++)
        c[i]=a[i];
    for(test = 0; test < 10; ++test)
        printf("%d ", c[test]);
    printf("\n");
    for(i=0;i<m;i++)
    {
        z=0;
        for(j=i;j<i+n;j++)
        {
            if(b[i]>=c[j]&&b[i]<=c[j+1])//将b[i]插入到c数组中它该在的位置
            {
                for(l=i+n+1;l>j;l--)
                    c[l]=c[l-1];
                c[j+1]=b[i];
                for(test = 0; test < 10; ++test)
                    printf("%d ", c[test]);
                printf("\n");
                z = 1;
            }
            else if(b[i] < c[j])
            {
                for(l=i+n+1;l>j;l--)
                    c[l]=c[l-1];
                c[j]=b[i];
                for(test = 0; test < 10; ++test)
                    printf("%d ", c[test]);
                printf("\n");
                z = 1;
            }
        
            if(z) //用z来计数，如果插入好了就break，到下一个b[i]，如果在这个j没插入，j继续走
                break;
        }
        if(!z)
            c[n+i]=b[i];
    }
}

int main()
{
    int a[5] = {1,3,5,7,9};
    int b[5] = {2,4,6,8,18};
    int c[10] = {0};
    int i = 0;
    for(i = 0; i < 10; ++i)
        printf("%d ", c[i]);
    printf("\n");
    merge(a, 5, b, 5, c);
    for(i = 0; i < 10; ++i)
        printf("%d ", c[i]);
    return 0;
}



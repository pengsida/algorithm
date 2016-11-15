//
//  gcd.h
//  introduction_to_the_design_and_analysis_of_algorithms
//
//  Created by pengsida on 16/9/20.
//  Copyright © 2016年 pengsida. All rights reserved.
//

#ifndef gcd_h
#define gcd_h
#include <utility>

struct gcd_false{};
struct gcd_true{};

template<typename T>
struct IsInteger
{
    typedef gcd_false is_integer;
};

template<>
struct IsInteger<int>
{
    typedef gcd_true is_integer;
};

template<typename T>
class gcd
{
private:
    std::pair<T, bool> gcd_best_aux(T m, T n, gcd_true)
    {
        while(n != 0)
        {
            T tmp = m % n;
            m = n;
            n = tmp;
        }
        return std::pair<T, bool>(m, true);
    }
    
    std::pair<T, bool> gcd_best_aux(T m, T n, gcd_false)
    {
        return std::pair<T, bool>(T(), false);
    }
    
    std::pair<std::pair<T, T>, bool> gcd_extension_aux(T m, T n, gcd_true)
    {
        int last_x = 1, last_y = 0;
        int cur_x = 0, cur_y = 1;
        while(n != 0)
        {
            int tmp = m % n;
            int result = m / n;
            m = n;
            n = tmp;
            int aux = cur_x;
            cur_x = last_x - cur_x * result;
            last_x = aux;
            aux = cur_y;
            cur_y = last_y - cur_y * result;
            last_y = aux;
        }
        return std::pair<std::pair<int, int>, bool>({last_x, last_y}, true);
    }
    
    std::pair<std::pair<T, T>, bool> gcd_extension_aux(T m, T n, gcd_false)
    {
        return std::pair<std::pair<T, T>, bool>({T(),T()}, false);
    }
    
    std::pair<std::pair<T, T>, bool> diophantus_equation_aux(T a, T b, T c, gcd_true)
    {
        int d = gcd_best(gcd_best(a, b).first, c).first;
        a /= d;
        b /= d;
        c /= d;
        std::pair<std::pair<T, T>, bool> tmp = gcd_extension(a, b);
        return std::pair<std::pair<T, T>, bool>({tmp.first.first * c, tmp.first.second * c}, true);
    }
    
    std::pair<std::pair<T, T>, bool> diophantus_equation_aux(T a, T b, T c, gcd_false)
    {
        return std::pair<std::pair<T, T>, bool>({T(), T()}, false);
    }
    
public:
    std::pair<T, bool> gcd_best(T m, T n)
    {
        typedef typename IsInteger<T>::is_integer is_integer;
        return gcd_best_aux(m, n, is_integer());
    }
    
    std::pair<std::pair<T, T>, bool> gcd_extension(T m, T n)
    {
        typedef typename IsInteger<T>::is_integer is_integer;
        return gcd_extension_aux(m, n, is_integer());
    }
    
    std::pair<std::pair<T, T>, bool> diophantus_equation(T a, T b, T c)
    {
        typedef typename IsInteger<T>::is_integer is_integer;
        return diophantus_equation_aux(a, b, c, is_integer());
    }
};


#endif /* gcd_h */

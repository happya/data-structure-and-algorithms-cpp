//
// Created by yyi on 2020/2/22.
//

#ifndef FASTEXP_NUMBEREXP_H
#define FASTEXP_NUMBEREXP_H

/**
 * fast exponent: check each bit of exp, then decide if should multiply base^ i (ith bit)
 * and for each shift, update the current base^i
 * Time complexity: O(logN)
 */
#include <iostream>
class NumberExp {
public:
    NumberExp(int base, int exp){
        int cur = base;
        int res = 1;
        int N = exp;
        while(N){
            // if this bit is 1, multiply cur
            if(N & 1)
                res *= cur;
            // prepare for the next cur for next higher bit
            cur *= cur;
            N >>= 1;
        }
        std::cout<<base<<"^"<<exp<<"="<<res<<std :: endl;
    }
};


#endif //FASTEXP_NUMBEREXP_H

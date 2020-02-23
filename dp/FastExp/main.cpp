#include <iostream>

#include "NumberExp.h"
void testNumberExp(int base, int exp){
    auto numberExp = new NumberExp(base, exp);
    delete numberExp;
}
int main() {
    testNumberExp(2, 8);
    testNumberExp(3, 10);
}

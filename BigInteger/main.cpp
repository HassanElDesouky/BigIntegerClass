//
//  main.cpp
//  BigInteger
//
//  Created by Hassan El Desouky on 12/5/18.
//  Copyright © 2018 Hassan El Desouky. All rights reserved.
//

#include <iostream>
#include <string>
#include "BigInteger.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    string s1 = "100000000000000000000000012";
    string s2 = "10000000000000000000000018";
    BigInteger b1(s1), b2(s2);
    BigInteger b3 = b1*b2;
    cout << b3.getSNumber() << endl;
    return 0;
}

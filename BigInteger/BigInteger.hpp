//
//  BigInteger.hpp
//
//
//  Created by Hassan El Desouky on 12/2/18.
//  Copyright © 2018 Hassan El Desouky. All rights reserved.
//

#ifndef BigInteger_hpp
#define BigInteger_hpp

#include <stdio.h>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

//const long long MAX = 1000000000000000;

class BigInteger {
public:
    BigInteger(int maximum_length);
    BigInteger(string sNumber);
    void setMaximumLength(int maximum_length);
    void setSNumber(string sNumber);
    int getMaximumLength();
    string getSNumber();
    int length()const;
    BigInteger operator + (const BigInteger& b)const;
    BigInteger operator * (const BigInteger& b)const;
    bool operator == (const BigInteger& b)const;
    bool operator != (const BigInteger& b)const;
    bool operator <= (const BigInteger& b)const;
    bool operator < (const BigInteger& b)const;
    bool operator > (const BigInteger& b)const;
    bool operator >= (const BigInteger& b)const;
    ~BigInteger();
private:
    int maximum_length;
    string sNumber;
};

#endif /* BigInteger_hpp */

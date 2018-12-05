//
//  BigInteger.cpp
//  PST
//
//  Created by Hassan El Desouky on 12/2/18.
//  Copyright © 2018 Hassan El Desouky. All rights reserved.
//
#include <string>
#include "BigInteger.hpp"

using namespace std;

BigInteger:: BigInteger(int maximum_length) {
    this -> maximum_length = maximum_length;
}

BigInteger:: BigInteger(string sNumber) {
    this -> sNumber = sNumber;
}

void BigInteger:: setMaximumLength(int maximum_length) {
    this -> maximum_length = maximum_length;
}

void BigInteger:: setSNumber(string sNumber) {
    this -> sNumber = sNumber;
}

int BigInteger:: getMaximumLength() {
    return maximum_length;
}

string BigInteger:: getSNumber() {
    return sNumber;
}

int BigInteger:: length() const {
    return (int) sNumber.length();
}

BigInteger:: ~BigInteger() {
    //cout << "Destructor\n";
}

BigInteger BigInteger:: operator+(const BigInteger &b) const {
    string s1 = this-> sNumber, s2 = b.sNumber, sSum = "";
    
    if (s1.length() > s2.length()) {
        swap(s1, s2);
    }
    
    int s1Length = (int) s1.length(), s2Length = (int) s2.length(), iCarry = 0;
    
    reverse(s1.begin(), s1.end()); reverse(s2.begin(), s2.end());
    
    for (int i = 0; i < s1Length; i++) {
        int sum = (s1[i] - 48) + (s2[i] - 48) + iCarry;
        sSum.push_back(sum % 10 + 48);
        iCarry = sum / 10;
    }
    for (int i = s1Length; i < s2Length; i++) {
        int sum = (s2[i] - 48) + iCarry;
        sSum.push_back((sum % 10) + 48);
        iCarry = sum / 10;
    }
    if (iCarry != 0) {
        sSum.push_back(iCarry + 48);
    }
    
    reverse(sSum.begin(), sSum.end());
    
    return BigInteger(sSum);
}

BigInteger BigInteger:: operator*(const BigInteger &b) const {
    string s1 = this-> sNumber, s2 = b.sNumber, sResult = "";
    int s1Length = (int) s1.length(), s2Length = (int) s2.length();
    
    const int MAX = 10005;
    int iProduct[MAX];
    
    reverse(s1.begin(), s1.end()); reverse(s2.begin(), s2.end());
    
    memset(iProduct, 0, sizeof(iProduct));
    
    for (int i = 0; i < s1Length; i++) {
        for (int j = 0; j < s2Length; j++) {
            iProduct[i + j] += (s1[i] - 48) * (s2[j] - 48);
        }
    }
    for (int i = 0; i < MAX; i++) {
        iProduct[i + 1] += iProduct[i] / 10;
        iProduct[i] %= 10;
    }
    int i = MAX - 1;
    while (i > 0 && iProduct[i] == 0) {
        i--;
    }
    for (; i >= 0; i--) {
        sResult.append(to_string(iProduct[i]));
    }
    return BigInteger(sResult);
}

bool BigInteger:: operator==(const BigInteger &b) const {
    string s1 = this-> sNumber, s2 = b.sNumber;
    int s1Length = (int) s1.length(), s2Length = (int) s2.length();
    bool isEqual = false;
    if (s1Length == s2Length) {
        for (int i = 0; i < s1Length; i++) {
            if (s1[i] == s2[i]) {
                isEqual = true;
                continue;
            } else {
                isEqual = false;
                break;
            }
        }
        return isEqual;
    } else {
        return isEqual;
    }
}

bool BigInteger:: operator!=(const BigInteger &b) const {
    string s1 = this-> sNumber, s2 = b.sNumber;
    int s1Length = (int) s1.length(), s2Length = (int) s2.length();
    bool isNotEqual = true;
    if (s1Length != s2Length) {
        for (int i = 0; i < s1Length; i++) {
            if (s1[i] != s2[i]) {
                isNotEqual = true;
                continue;
            } else {
                isNotEqual = false;
                break;
            }
        }
        return isNotEqual;
    } else {
        return isNotEqual;
    }
    
}

bool BigInteger:: operator<=(const BigInteger &b) const {
    string s1 = this-> sNumber, s2 = b.sNumber;
    int s1Length = (int) s1.length(), s2Length = (int) s2.length();
    bool isLessOrEqual = false;
    if (s1Length == s2Length || s1Length < s2Length) {
        for (int i = 0; i < s2Length; i++) {
            if (s1[i] == s2[i] || s1[i] < s2[i]) {
                isLessOrEqual = true;
                continue;
            } else {
                isLessOrEqual = false;
                break;
            }
        }
        return isLessOrEqual;
    } else {
        return isLessOrEqual;
    }
}

bool BigInteger:: operator>=(const BigInteger &b) const {
    string s1 = this-> sNumber, s2 = b.sNumber;
    int s1Length = (int) s1.length(), s2Length = (int) s2.length();
    bool isMoreOrEqual = false;
    if (s1Length == s2Length || s1Length > s2Length) {
        for (int i = 0; i < s1Length; i++) {
            if (s1[i] == s2[i] || ((s1[i] - 48) > (s2[i] - 48))) {
                isMoreOrEqual = true;
                continue;
            } else {
                isMoreOrEqual = false;
                break;
            }
        }
        return isMoreOrEqual;
    } else {
        return isMoreOrEqual;
    }
}

bool BigInteger:: operator<(const BigInteger &b) const {
    string s1 = this-> sNumber, s2 = b.sNumber;
    int s1Length = (int) s1.length(), s2Length = (int) s2.length();
    bool isLess = false;
    if (s1Length < s2Length) {
        isLess = true;
        return isLess;
    } else {
        for (int i = 0; i < s2Length; i++) {
            if (s1[i] < s2[i]) {
                isLess = true;
                continue;
            } else {
                isLess = false;
                break;
            }
        }
        return isLess;
    }
}

bool BigInteger:: operator>(const BigInteger &b) const {
    string s1 = this-> sNumber, s2 = b.sNumber;
    int s1Length = (int) s1.length(), s2Length = (int) s2.length();
    bool isMore = false;
    if (s1Length > s2Length) {
        isMore = true;
        return isMore;
    } else {
        for (int i = 0; i < s2Length; i++) {
            if (s1[i] < s2[i]) {
                isMore = true;
                continue;
            } else {
                isMore = false;
                break;
            }
        }
        return isMore;
    }
}


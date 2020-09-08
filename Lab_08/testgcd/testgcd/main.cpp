//
//  main.cpp
//  testgcd
//
//  Created by Sarah Xiao on 3/27/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

int greatestCommonDivisor(int x, int y) {
    while (y != 0) {
        int temp = x % y;
        x = y;
        cout << x << endl;
        y = temp;
        cout << y << endl;
    }
    return x;
}

int main () {
    int p = greatestCommonDivisor(42, 30);
    cout << p;
}

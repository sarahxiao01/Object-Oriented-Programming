//
//  main.cpp
//  rec08
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
        y = temp;
    }
    return x;
}

class Rational {
    friend ostream& operator<<(ostream& os, const Rational& rhs){
        os << rhs.num << '/' << rhs.denom;
            return os;
        }

    friend istream& operator>>(istream& is, Rational& rhs){
        int up, down;
        char sign;
        is >> up >> sign >> down;
        rhs.num = up;
        rhs.denom = down;
        rhs.normalize();
        return is;
    }
    
    friend bool operator==(const Rational& lhs, const Rational& rhs){
        if (lhs.num == rhs.num && lhs.denom == rhs.denom) {
            return true;
    }
        return false;
        }
    friend bool operator<(const Rational& lhs, const Rational& rhs) {
        int ltop = lhs.num * rhs. denom;
        int rtop = rhs.num * lhs. denom;
        return (ltop - rtop < 0);
    }
    
public:
    Rational(int numer = 0, int denomer = 1): num(numer), denom(denomer) { normalize();}
    
    Rational& operator+=(const Rational& rhs){
        int newnum = num * rhs.denom + rhs.num * denom;
        int newdenom = denom * rhs.denom;
        num = newnum;
        denom = newdenom;
        normalize();
        return *this;
    }

//pre
    Rational& operator++(){
        *this += 1;
        return *this;
    }
//post
    Rational operator++(int dummy){
        Rational copy(*this);
        num += denom;
        return copy;
    }
    explicit operator bool() const{
        return !(num == 0);
    }

private:
    int num;
    int denom;
        void normalize() {
        if (denom < 0 && num < 0 ) {
            num *= -1;
            denom *= -1;
        }
        else if (denom < 0 && num > 0 ){
            num *= -1;
            denom *= -1;
        }
        int n = abs(num);
        int m = abs(denom);
        int p = greatestCommonDivisor(n, m);
        num /= p;
        denom /= p;
    }
        
};
        
    Rational operator+(Rational& lhs, const Rational& rhs){
        Rational mysum= lhs;
        mysum += rhs;
        return mysum;
    }

//pre
    Rational& operator--(Rational& rhs){
        rhs += -1;
        return rhs;
    }
//post
    Rational operator--(Rational& rhs, int dummy){
        Rational copy(rhs);
        rhs += -1;
        return copy;
    }
        
    bool operator!=(const Rational& lhs, const Rational& rhs){
        return !(lhs == rhs);
    }
        
    bool operator>(const Rational& lhs, const Rational& rhs){
        return !((lhs < rhs) || (lhs == rhs) );
    }

    bool operator<=(const Rational& lhs, const Rational& rhs){
        return ( (lhs < rhs) || (lhs == rhs) );
    }

    bool operator>=(const Rational& lhs, const Rational& rhs){
        return !( lhs < rhs);
    }


int main() {
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;    // Implement as member
    cout << "a = " << a << endl;
    
    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // How does this manage to work?
    // It does NOT require writing another == operator.
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
//    cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;


    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : "
         << (twoFifths < threeHalves) << endl;
    cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;
}

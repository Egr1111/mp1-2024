#pragma once

#include "iostream"
using namespace std;

class Rac {
    private:
        int chis;
        int znam;
    public:
        void get(int c, int z) {
            chis = c;
            znam = z;
        }
        Rac plus(Rac s1, Rac s2);
        Rac minus(Rac s1, Rac s2);
        Rac del(Rac s1, Rac s2);
        Rac umn(Rac s1, Rac s2);
        Rac plusMinus(Rac s1, Rac s2, string act);
        void printRac(Rac s) {
            cout << s.chis << "\n-\n" << s.znam << "\n\n";
        }
        void sokr(Rac s3);
        
};
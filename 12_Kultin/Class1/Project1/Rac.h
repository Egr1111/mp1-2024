#pragma once

#include "iostream"
using namespace std;

template <typename l>
class Rac {
    private:
        l chis;
        l znam;
    public:
        void get(int c, int z) {
            chis = c;
            znam = z;
        }
        void plus(Rac s2);
        void minus(Rac s2);
        void del(Rac s2);
        void umn(Rac s2);
        void plusMinus(Rac s2, string act);
        void printRac(Rac s) {
            cout << s.chis << "\n-\n" << s.znam << "\n\n";
        }
        Rac& operator=(const Rac&);
        void sokr(l chl3, l znm3);
        
};

template <typename l>
void Rac<l>::plusMinus(Rac<l> s2, string act) {
    int chl2 = s2.chis;
    int znm2 = s2.znam;
    int chl3, znm3;

    if (znam != znm2) {
        int mx = (znam > znm2) ? znam : znm2;
        int mn = (znam < znm2) ? znam : znm2;

        if ((mx % mn) == 0) {
            if (mx == znam) chl2 = chl2 * (mx / mn);
            else chis = chis * (mx / mn);
            if (act == "+")
                chl3 = chis + chl2;
            else
                chl3 = chis - chl2;
            znm3 = mx;

        }
        else {
            chis = chis * znm2;
            chl2 = chl2 * znam;
            if (act == "+")
                chl3 = chis + chl2;
            else
                chl3 = chis - chl2;
            znm3 = znam * znm2;
        }
    }
    else {
        if (act == "+")
            chl3 = chis + chl2;
        else
            chl3 = chis - chl2;

        znm3 = znam;
    }
    chis = chl3;
    znam = znm3;
}

template <typename l>
void Rac<l>::sokr(l chl, l znm) {
    int chl3 = chl;
    int znm3 = znm;
    if (chl3 % znm3 != 0 && znm3 % chl3 != 0) {
        int vver = (chl3 > znm3) ? int(floor((chl3 / 2)) + 1) : int(floor((znm3 / 2)) + 1);
        int n = 2;
        while (n != vver) {
            while (chl3 % n == 0 && znm3 % n == 0)
            {
                chl3 /= n;
                znm3 /= n;
            }
            n++;
        }
    }
    else {
        if (chl3 % znm3 == 0) {
            chl3 = chl3 / znm3;
            znm3 = 1;
        }
        else
        {
            znm3 = znm3 / chl3;
            chl3 = 1;
        }
    }
    chis = chl3;
    znam = znm3;

}

template <typename l>
void Rac<l>::plus(Rac<l> s2) {

    plusMinus(s2, "+");
    sokr(chis, znam);

}

template <typename l>
void Rac<l>::minus(Rac<l> s2) {

    plusMinus(s2, "-");
    sokr(chis, znam);
}

template<typename l>
void Rac<l>::del(Rac<l> s2) {
    this->get(chis * s2.znam, znam * s2.chis);
    sokr(chis, znam);
}

template <typename l>
void Rac<l>::umn(Rac<l> s2) {

    this->get(chis * s2.chis, znam * s2.znam);
    sokr(chis, znam);
}

template <typename l>
Rac<l>&Rac<l>::operator=(const Rac& s2) {
    chis = s2.chis;
    znam = s2.znam;

    return *this;

}



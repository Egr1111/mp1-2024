#include "Rac.h";
#include "cmath";

Rac Rac::plusMinus(Rac s1, Rac s2, string act) {
    int chl1 = s1.chis;
    int chl2 = s2.chis;
    int znm1 = s1.znam;
    int znm2 = s2.znam;
    int chl3, znm3;
    Rac s3;
    if (znm1 != znm2) {
            int mx = (znm1 > znm2) ? znm1 : znm2;
            int mn = (znm1 < znm2) ? znm1 : znm2;

            if ((mx % mn) == 0) {
                if (mx == znm1) chl2 = chl2 * (mx / mn);
                else chl1 = chl1 * (mx / mn);
                chl3 = chl1 + chl2;
                znm3 = mx;

            }
            else {
                chl1 = chl1 * znm2;
                chl2 = chl2 * znm1;
                if (act == "+")
                    chl3 = chl1 + chl2;
                else
                    chl3 = chl1 - chl2;
                znm3 = znm1 * znm2;
            }
        }
        else {
            if (act == "+")
                chl3 = chl1 + chl2;
            else
                chl3 = chl1 - chl2;

            znm3 = znm1;
        }
    s3.get(chl3, znm3);

    return s3;
}


void Rac::sokr(Rac s3) {
    int chl3 = s3.chis;
    int znm3 = s3.znam;
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
    s3.get(chl3, znm3);

}


Rac Rac::plus(Rac s1, Rac s2) {

    Rac s3 = plusMinus(s1, s2, "+");
    sokr(s3);

    return s3;
}
Rac Rac::minus(Rac s1, Rac s2) {

    Rac s3 = plusMinus(s1, s2, "-");
    sokr(s3);

    return s3;
}
Rac Rac::del(Rac s1, Rac s2) {
    Rac s3;

    int chl3 = s1.chis * s2.znam;
    int znm3 = s1.znam * s2.chis;

    s3.get(chl3, znm3);

    sokr(s3);

    return s3;

}
Rac Rac::umn(Rac s1, Rac s2) {
    Rac s3;

    int chl3 = s1.chis * s2.chis;
    int znm3 = s1.znam * s2.znam;

    s3.get(chl3, znm3);
    sokr(s3);

    return s3;
}





#include <bits/stdc++.h>

using namespace std;
//Ham tinh UCLN
inline int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}
class PhanSo{
private:
    int iTu, iMau;
    void RutGon()
    {
        int g = GCD(iTu, iMau);
        iTu /= g;
        iMau /= g;
        if (iMau < 0) {
            iMau *= -1;
            iTu *= -1;
        }
    }
public:
    PhanSo();
    PhanSo(int Tu, int Mau);
    PhanSo operator+ (const PhanSo &a);
    PhanSo operator- (const PhanSo &a);
    PhanSo operator* (const PhanSo &a);
    PhanSo operator/ (const PhanSo &a);
    bool operator == (const PhanSo &a);
    bool operator != (const PhanSo &a);
    bool operator >= (const PhanSo &a);
    bool operator <= (const PhanSo &a);
    bool operator > (const PhanSo &a);
    bool operator < (const PhanSo &a);

    friend istream& operator >> (istream &in, PhanSo &ps);
    friend ostream& operator << (ostream &out, const PhanSo &ps);
};
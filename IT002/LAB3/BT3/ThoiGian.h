#include <bits/stdc++.h>

using namespace std;

class ThoiGian{
private:
    int iGio, iPhut, iGiay;
public:
    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay);
    int TinhGiay() const;
    void TinhLaiGio(int Giay);
    ThoiGian operator+ (int Giay);
    ThoiGian operator- (int Giay);
    ThoiGian operator+ (const ThoiGian &a);
    ThoiGian operator- (const ThoiGian &a);
    ThoiGian& operator++();
    ThoiGian& operator--();
    bool operator == (const ThoiGian &a);
    bool operator != (const ThoiGian &a);
    bool operator >= (const ThoiGian &a);
    bool operator <= (const ThoiGian &a);
    bool operator > (const ThoiGian &a);
    bool operator < (const ThoiGian &a);

    friend istream& operator >> (istream& in, ThoiGian &a);
    friend ostream& operator << (ostream& out, const ThoiGian &a);
};
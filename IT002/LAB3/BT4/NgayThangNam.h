#include <bits/stdc++.h> 

using namespace std;

//Trong bai nay minh mac dinh thang 2 co 28 ngay (khong co nam nhuan)
//Mang days[i] luu tru so ngay co trong thang i
inline int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class NgayThangNam{
private:
    int iNgay, iThang, iNam;
public:
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay);
    int TongNgay() const; //Ham tinh tong so ngay 
    void TinhNgay(int Ngay);
    NgayThangNam operator+ (int Ngay);
    NgayThangNam operator- (int Ngay);
    NgayThangNam operator+ (const NgayThangNam &a);
    NgayThangNam operator- (const NgayThangNam &a);
    NgayThangNam& operator++();
    NgayThangNam& operator--();
    bool operator == (const NgayThangNam &a);
    bool operator != (const NgayThangNam &a);
    bool operator >= (const NgayThangNam &a);
    bool operator <= (const NgayThangNam &a);
    bool operator > (const NgayThangNam &a);
    bool operator < (const NgayThangNam &a);

    friend istream& operator >> (istream& in, NgayThangNam &a);
    friend ostream& operator << (ostream& out, const NgayThangNam &a);
};
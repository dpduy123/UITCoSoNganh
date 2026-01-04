#include "tamgiac.h" 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    TamGiac ABC;
    ABC.Nhap();
    double angle, d;
    cin >> angle >> d;
    double dx, dy;
    angle = angle * 3.14 / 180;
    dx = d * cos(angle);
    dy = d * sin(angle);
    ABC.TinhTien(dx, dy);
    ABC.Xuat();
    return 0;
}
/* 
    Environment: VSCode
    Mở terminal: 
        Dùng lệnh g++ main.cpp -o main để biên dịch 
        Lệnh ./main để chạy chương trình 
*/
#include "dagiac.h" 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    DaGiac ABC;
    ABC.Nhap();
    ABC.Xuat();

    ABC.TinhTien(1, 1);
    cout << "Da giac sau khi tinh tien la: " << "\n";
    ABC.Xuat();

    ABC.PhongTo(2);
    cout << "Da giac sau khi phong to la: " << "\n";
    ABC.Xuat();

    ABC.ThuNho(2);
    cout << "Da giac sau khi thu nho la: " << "\n"; 
    ABC.Xuat();

    ABC.Quay(180);
    cout << "Da giac sau khi quay 180 do la: " << "\n"; 
    ABC.Xuat();
    return 0;
}
/* 
    Environment: VSCode
    Mở terminal: 
        Dùng lệnh g++ main.cpp -o main để biên dịch 
        Lệnh ./main để chạy chương trình 
*/
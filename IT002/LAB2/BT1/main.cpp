#include "diem.h"

using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Diem A;
    A.Nhap();
    A.Xuat();
    cout << "Hoanh do cua diem A la: " << A.GetHoanhDo() << "\n";
    cout << "Tung do cua diem A la: " << A.GetTungDo() << "\n";
    cout << "Nhap Hoanh Do ban muon dat vao A: " << "\n";
    int x, y, dx, dy;
    cin >> x;
    A.SetHoanhDo(x);
    A.Xuat();
    cout << "Nhap Tung Do ban muon dat vao A: " << "\n";
    cin >> y;
    A.SetTungDo(y);
    A.Xuat();
    cout << "Nhap do dai hoanh do va tung do ma ban muon tinh tien: " << "\n";
    cin >> dx >> dy;
    A.TinhTien(dx, dy);
    cout << "Diem A sau khi tinh tien la: ";
    A.Xuat();
    return 0;
}
/* 
    Environment: VSCode
    Mở terminal: 
        Dùng lệnh g++ main.cpp -o main để biên dịch 
        Lệnh ./main để chạy chương trình 
*/
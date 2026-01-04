#include "dagiac.h" 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    DaGiac ABC;
    ABC.Nhap();
    cout << ABC.tinhDienTich() << "\n";
    return 0;
}
/* 
    Environment: VSCode
    Mở terminal: 
        Dùng lệnh g++ main.cpp -o main để biên dịch 
        Lệnh ./main để chạy chương trình 
*/
#include "diem.h"

int n, x, k;
double d;
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Diem A;
    A.Nhap();
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> x;
        if (x == 1) {
            A.NhanDoi();
        }
        if (x == 2) {
            A = Diem(0, 0);
        }
        if (x == 3) {
            cin >> k >> d;
            if (k == 0) {
                A.TinhTienX(d);
            }
            else A.TinhTienY(d);
        }
    }
    A.Xuat();
    return 0;
}
/* 
    Environment: VSCode
    Mở terminal: 
        Dùng lệnh g++ main.cpp -o main để biên dịch 
        Lệnh ./main để chạy chương trình 
*/
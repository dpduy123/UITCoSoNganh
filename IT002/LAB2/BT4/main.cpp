#include "thisinh.h"

int n;
ThiSinh a[1000001];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << "Nhập số thí sinh: ";
    cin >> n;
    int TongDiem = -1, id = -1;
    // Input thông tin các thí sinh
    for (int i = 1; i <= n; i++) 
    {
        cout << "Thí sinh thứ " << i << ":\n";
        a[i].Nhap();
        //Tìm thí sinh có tổng điểm cao nhất:
        if (TongDiem < a[i].Tong()) {
            TongDiem = a[i].Tong();
            id = i;
        }
    }
    //Tìm thí sinh có tổng điểm lớn hơn 15 
    cout << "Thí sinh có tổng điểm lớn hơn 15 là: " << "\n";
    for (int i = 1; i <= n; i++) 
    {
        if (a[i].Tong() > 15) {
            a[i].Xuat();
            cout << "\n";
        }
    }
    cout << "Thí sinh có tổng điểm cao nhất là: " << "\n";
    a[id].Xuat();
    cout << "Với tổng điểm là " << TongDiem << "\n";
    return 0;
}
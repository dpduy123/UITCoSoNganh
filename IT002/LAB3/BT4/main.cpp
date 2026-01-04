#include "NgayThangNam.h"

int main()
{
    NgayThangNam a, b;
   
    //Input
    cout << "Nhap ngay thang nam a\n";
    cin >> a;
    cout << "Nhap ngay thang nam b\n";
    cin >> b;

    //Check cac toan tu + -
    cout << "Ngay thang nam a + ngay thang nam b la: " << a + b << "\n";
    cout << "Ngay thang nam a - Ngay thang nam b la: " << a - b << "\n";
    cout << "Ngay thang nam a sau khi +30 ngay la: "<< a + 30 << "\n";
    cout << "Ngay thang nam b sau khi -15 ngay la: "<< b - 15 << "\n";

    //Check cac toan tu so sanh
    cout << "So sanh ==: " << (a == b ? "True" : "False") << "\n";
    cout << "So sanh !=: " << (a != b ? "True" : "False") << "\n";
    cout << "So sanh >=: " << (a >= b ? "True" : "False") << "\n";
    cout << "So sanh <=: " << (a <= b ? "True" : "False") << "\n";
    cout << "So sanh > : " << (a > b ? "True" : "False") << "\n";
    cout << "So sanh < : " << (a < b ? "True" : "False") << "\n";
    
    return 0;
}
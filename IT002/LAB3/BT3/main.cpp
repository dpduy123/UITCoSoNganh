#include "ThoiGian.h"

int main()
{
    ThoiGian a, b;
   
    //Input
    cout << "Nhap thoi gian a\n";
    cin >> a;
    cout << "Nhap thoi gian b\n";
    cin >> b;

    //Check cac toan tu + -
    cout << "Thoi gian a + thoi gian b la: " << a + b << "\n";
    cout << "Thoi gian a - thoi gian b la: " << a - b << "\n";
    cout << "Thoi gian a sau khi +30 giay la: "<< a + 30 << "\n";
    cout << "Thoi gian b sau khi -15 giay la: "<< b - 15 << "\n";
    
    //Check cac toan tu so sanh
    cout << "So sanh ==: " << (a == b ? "True" : "False") << "\n";
    cout << "So sanh !=: " << (a != b ? "True" : "False") << "\n";
    cout << "So sanh >=: " << (a >= b ? "True" : "False") << "\n";
    cout << "So sanh <=: " << (a <= b ? "True" : "False") << "\n";
    cout << "So sanh > : " << (a > b ? "True" : "False") << "\n";
    cout << "So sanh < : " << (a < b ? "True" : "False") << "\n";
    
    return 0;
}
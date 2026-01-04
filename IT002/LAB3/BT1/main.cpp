#include "PhanSo.h"

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;
    cout << "Nhap phan so thu hai:\n";
    cin >> ps2;

    cout << "Tong hai phan so: " << ps1 + ps2 << "\n";
    cout << "Hieu hai phan so: " << ps1 - ps2 << "\n";
    cout << "Tich hai phan so: " << ps1 * ps2 << "\n";
    cout << "Thuong hai phan so: " << ps1 / ps2 << "\n";

    cout << "So sanh ==: " << (ps1 == ps2 ? "True" : "False") << "\n";
    cout << "So sanh !=: " << (ps1 != ps2 ? "True" : "False") << "\n";
    cout << "So sanh >=: " << (ps1 >= ps2 ? "True" : "False") << "\n";
    cout << "So sanh <=: " << (ps1 <= ps2 ? "True" : "False") << "\n";
    cout << "So sanh > : " << (ps1 > ps2 ? "True" : "False") << "\n";
    cout << "So sanh < : " << (ps1 < ps2 ? "True" : "False") << "\n";
    
    return 0;
}

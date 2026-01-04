#include "SoPhuc.h" 

int main()
{
    SoPhuc a, b;
    //Input
    cout << "Nhap so phuc thu nhat:\n";
    cin >> a;
    cout << "Nhap so phuc thu hai:\n";
    cin >> b;

    //Kiem tra cac toan tu + - * /
    cout << "Tong hai so phuc la: " << a + b << "\n";
    cout << "Hieu hai so phuc la: " << a - b << "\n";
    cout << "Tich hai so phuc la: " << a * b << "\n";
    cout << "Thuong hai so phuc la: " << a / b << "\n";

    //Kiem Tra cac toan tu so sanh
    if (a == b) {
        cout << "Hai so phuc nay bang nhau" << "\n";
    }
    else if (a != b) cout << "Hai so phuc nay khac nhau" << "\n";
    return 0;
}
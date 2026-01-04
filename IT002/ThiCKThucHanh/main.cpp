#include "chai.h" 
#include "hinhtru.h"
#include "hinhcau.h"
#include "hinhhopchunhat.h"

Chai* ds[10001];
int n, type[10001];
signed main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> type[i];
        if (type[i] == 1) {
            double r, h;
            cin >> r >> h;
            ds[i] = new HinhTru(r, h);
        }
        if (type[i] == 2) {
            double l, w, h;
            cin >> l >> w >> h;
            ds[i] = new HinhHopChuNhat(l, w, h);
        }
        if (type[i] == 3) {
            double r;
            cin >> r;
            ds[i] = new HinhCau(r);
        }
    }
    double sum = 0.00;
    for (int i = 1; i <= n; i++) 
    {
        sum = sum + ds[i]->DienTich();
    }
    cout << "Tong dien tich cac chai: " << sum << "\n";

    double x, y, z;
    double a, b, c;
    for (int i = 1; i <= n; i++) {
        if (type[i] == 1) {
            x = x + ds[i]->LuongRuou();
            a = ds[i]->TyLeRuou();
        }
        if (type[i] == 2) {
            y = y + ds[i]->LuongRuou();
            b = ds[i]->TyLeRuou();
        }
        if (type[i] == 3) {
            z = z + ds[i]->LuongRuou();
            c = ds[i]->TyLeRuou();
        }
    }
    cout << "Ty le ruou con dong lai cua chai hinh tru: " << fixed << setprecision(2) << a << "\n";
    cout << "Ty le ruou con dong lai cua chai hinh cau: " << fixed << setprecision(2) << c << "\n";
    cout << "Ty le ruou con dong lai cua chai hinh hop chu nhat: " << fixed << setprecision(2) << b << "\n";

    cout << "Luong ruou cuoi cung con dong lai tren mat dat khi Chi Pheo dap cac chai: " << x + y + z << "\n";

    cout << "So luong hoa no: " << "\n";
    return 0;
}
/*
3
2 2 3 5
3 4
1 1 1
*/
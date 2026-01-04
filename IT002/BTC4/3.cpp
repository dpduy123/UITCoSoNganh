#include <bits/stdc++.h> 
using namespace std;

int luth(int x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	int t = luth(x, n / 2);
	t = (t * t);
	if (n & 1) t = t * x;
	return t;
}
class DonThuc {
private:
	int a, b;
public: 
	DonThuc() {a = 0; b = 0;}
	DonThuc(int _a, int _x, int _b) {a = _a; b = _b;}

	void Nhap()
	{
		cin >> a >> b;
	}

	void Xuat() {
		cout << "P(x) = " << a << "x^" << b << "\n";
	}

	int val(int x) 
	{
		return a * luth(x, b);
	}

	DonThuc DaoHam() {
		DonThuc X;
		X.b = b - 1;
		X.a = b * a;
		return X;
	}	

	DonThuc Tong(DonThuc X) {
		DonThuc Y;
		Y.a = a + X.a;
		Y.b = b;
		return Y;
	}
};

signed main() {

	DonThuc X, Y;
	cout << "Nhập đơn thức thứ nhất: " << "\n";
	X.Nhap();
	cout << "Nhập đơn thức thứ hai: " << "\n";
	Y.Nhap();

	DonThuc Z = X;
	Z = Z.Tong(Y);
	cout << "Tong hai don thuc la: " << "\n";
	Z.Xuat();
	return 0;
}
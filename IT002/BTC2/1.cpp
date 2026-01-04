#include <bits/stdc++.h> 

#define int long long 
#define pii pair <int,int> 
#define st first 
#define nd second 
#define vi vector <int> 
#define vpii vector <pii> 
#define pb push_back 
#define lb lower_bound 
#define ub upper_bound 
#define FILE ""
#define trii pair <pii, int> 
using namespace std;

const int oo = 1e18;
const int base = 311;
const int mod = 998244353;
const int N = 333;

struct Phanso{
	int tu, mau;

};

int gcd(int a, int b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
Phanso Rutgon(Phanso a) 
{
	Phanso c = a;
	c.tu = a.tu / gcd(a.tu, a.mau);
	c.mau = a.mau / gcd(a.tu, a.mau);
	return c;

}
Phanso Cong(Phanso a, Phanso b) 
{
	Phanso c;
	c.mau = a.mau * b.mau;
	c.tu = a.mau * b.tu + b.mau * a.tu;
	return Rutgon(c);
}
Phanso Tru(Phanso a, Phanso b) 
{
	Phanso c;
	c.mau = a.mau * b.mau;
	c.tu = -a.mau * b.tu + b.mau * a.tu;
	return Rutgon(c);
}
Phanso Nhan(Phanso a, Phanso b) 
{
	Phanso c;
	c.mau = a.mau * b.mau;
	c.tu = a.tu * b.tu;
	return Rutgon(c);
}
Phanso Chia(Phanso a, Phanso b) 
{
	Phanso c;
	c.mau = a.mau * b.tu;
	c.tu = b.mau * a.tu;
	return Rutgon(c);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Phanso a, b;
	cout << "Nhap tu so phan so thu nhat: " << "\n";
	cin >> a.tu;
	cout << "Nhap mau so phan so thu nhat: " << "\n";
	cin >> a.mau;
	cout << "Nhap tu so phan so thu hai: " << "\n";
	cin >> b.tu;
	cout << "Nhap mau so phan so thu hai: " << "\n";
	cin >> b.mau;

	Phanso Tong = Cong(a, b), Hieu = Tru(a, b), Tich = Nhan(a, b), Thuong = Chia(a, b);

	cout << "Tong hai phan so la: " << Tong.tu << '/' << Tong.mau << "\n";
	cout << "Hieu hai phan so la: " << Hieu.tu << '/' << Hieu.mau << "\n";
	cout << "Tich hai phan so la: " << Tich.tu << '/' << Tich.mau<< "\n";
	cout << "Thuong hai phan so la: " << Thuong.tu << '/' << Thuong.mau << "\n";
	return 0;
}
/*
From Benq: 
	int overflow?
	array bounds?
	Special Cases (n = 1?)
	Do something instead of nothing and stay organized 
	WRITE STUFF DOWN 
	DON'T GET STUCK ON ONE APPROACH 
*/

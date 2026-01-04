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

struct Student{
	string ID, name, gender;
	double x, y, z;
}a;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout << "Nhap MSSV: ";
	getline(cin, a.ID);
	cout << "Nhap ho va ten hoc sinh: " << "\n";
	getline(cin, a.name);
	cout << "Nhap gioi tinh: ";
	getline(cin, a.gender);
	cout << "Nhap diem toan: ";
	cin >> a.x;
	cout << "Nhap diem ly: ";
	cin >> a.y;
	cout << "Nhap diem hoa: ";
	cin >> a.z;

	cout << "Thong tin chi tiet hoc sinh" << "\n";
	cout << "MSSV: " << a.ID << "\n";
	cout << "Ho va ten: " << a.name << "\n";
	cout << "Gioi tinh: " << a.gender << "\n";
	cout << "Diem Toan: " << a.x << "\n";
	cout << "Diem Ly: " << a.y << "\n";
	cout << "Diem hoa: " << a.z << "\n";
	cout << "Diem trung binh: " << (double) (a.x + a.y + a.z) / 3 << "\n";
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

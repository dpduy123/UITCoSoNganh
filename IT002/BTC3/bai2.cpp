#include <bits/stdc++.h> 

using namespace std;

const double pi = 3.14159265359;
class DuongTron{
private:
	double toadotam;
	double bankinh;
public: 
	DuongTron(double r) {
		bankinh = r;
	}
	double chuvi(){
		return pi * 2 * bankinh;
	}
	double dientich()
	{
		return pi * bankinh * bankinh;
	}
};
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	double r;
	cout << "Nhập bán kình đường tròn: ";
	cin >> r;
	DuongTron O(r);
	cout << "Chu vi đường tròn là: " << O.chuvi() << "\n";
	cout << "Diện tích đường tròn là: " << O.dientich() << "\n";
	return 0;
}
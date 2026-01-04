#include <bits/stdc++.h> 

using namespace std;

const double pi = 3.14159265359;
class Point{
public: 
	double x, y;
	Point (int _x, int _y) {
		x = _x; y = _y; 
	}
};
double distance(Point &a, Point &b) 
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	double x, y;

	cout << "Nhập tọa độ điểm A (x y): " << "\n";
	cin >> x >> y;
	Point a(x, y);

	cout << "Nhập tọa độ điểm B (x y): " << "\n";
	cin >> x >> y;
	Point b(x, y);
	cout << "Khoảng cách 2 điểm A và B là: " << distance(a, b)<< "\n";
	return 0;
}
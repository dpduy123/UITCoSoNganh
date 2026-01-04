#include <bits/stdc++.h> 

using namespace std;

class student{
private:
	string name;
	double toan;
	double van;
public: 
	student(string n, double math, double lite) {
		name = n;
		toan = math;
		van = lite;
	}

	double Diemtrungbinh()
	{
		return (toan + van) / 2;
	}
	string Xeploai() {
		double average = Diemtrungbinh();
		if (average >= 8) return "Gioi";
		if (average >= 6.5) return "Kha";
		if (average >= 5) return "Trung Binh";
		return "Yeu";
	}
	void display(){
		cout << "Ho va ten: " << name << "\n";
		cout << "Diem toan: " << toan << "\n";
		cout << "Diem van: " << van << "\n";
		cout << "Diem trung binh: " << Diemtrungbinh() << "\n";
		cout << "Xep loai: " << Xeploai() << "\n";
	}
};
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string name;
	double toan, van;
	// Nhập thông tin học sinh
    cout << "Nhap ho ten hoc sinh: ";
    getline(cin, name);
    
    cout << "Nhap diem toan: ";
    cin >> toan;
    
    cout << "Nhap diem van: ";
    cin >> van;

    student a(name, toan, van);

    a.display();
	return 0;
}
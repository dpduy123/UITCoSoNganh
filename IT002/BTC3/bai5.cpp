
#include<iostream>
#include<string>
using namespace std;
class cHocSinh {
	string masv, gioitinh, hoten;
	int namsinh;
	double diemtb;
public:
	cHocSinh() {};
	~cHocSinh() {};
	void Nhap() {
		cout << "ma sinh vien: "; cin >> masv;
		cin.ignore();
		cout << "Ten cua sinh vien: "; getline(cin, hoten);
		cout << "Gioi tinh: "; cin >> gioitinh;
		cout << "Nam sinh: "; cin >> namsinh;
		cout << "Diem trung binh: "; cin >> diemtb;
	}
	void SoSanhDiem(cHocSinh x) {
		if (diemtb > x.diemtb) {
			cout << "Hoc sinh mot co diem cao hon hoc sinh hai";
		}
		else if (diemtb == x.diemtb) {
			cout << "hai hoc sinh co diem bang nhau" << endl;
		}
		else {
			cout << "Diem hoc sinh hai lon hon diem hoc sinh mot"<<endl;
		}
	}
	void SoSanhTuoi(cHocSinh x) {
		if (namsinh > x.namsinh) {
			cout << "Hoc sinh 1 nho tuoi hon hoc sinh 2";
		}
		else if (namsinh == x.namsinh) {
			cout << "Hoc sinh 1 bang tuoi hoc sinh hai" << endl;
		}
		else cout << "Hoc sinh 1 lon tuoi hon hoc sinh 2"<<endl;

	}
	void Xuat() {
		cout << "ma sinh vien: " << masv<<endl;
		cout << "Ho ten sinh vien: " << hoten<<endl;
		cout << "Gioi tinh: " << gioitinh << endl;
		cout << "nam sinh:" << namsinh << endl;
		cout << "diem trung binh:" << diemtb<<endl;
	}


};
int main() {
	cHocSinh x1, x2;
	cout << "Hoc sinh 1: "<<endl;
	x1.Nhap();
	cout << "hoc sinh 2: " << endl;
	x2.Nhap();
	cout << "thong tin cua hoc sinh 1:" << endl;
	x1.Xuat();
	cout << "thong tin cua sinh vien 2:" << endl;
	x2.Xuat();
	x1.SoSanhDiem(x2);
	x1.SoSanhTuoi(x2);
	return 0;
	

}
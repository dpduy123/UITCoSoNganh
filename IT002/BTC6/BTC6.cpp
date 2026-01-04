#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp cơ sở NhanVien
class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string soDienThoai;
    string email;
    double luongCoBan;

public:
    NhanVien(string ma, string ten, int tuoi, string sdt, string email, double luong)
        : maNV(ma), hoTen(ten), tuoi(tuoi), soDienThoai(sdt), email(email), luongCoBan(luong) {}

    virtual double tinhLuong() = 0; // Phương thức ảo thuần túy để tính lương
    virtual void xuatThongTin() {
        cout << "Ma NV: " << maNV << ", Ho Ten: " << hoTen << ", Tuoi: " << tuoi
             << ", SDT: " << soDienThoai << ", Email: " << email;
    }

    double getLuongCoBan() { return luongCoBan; }
};

// Lớp LapTrinhVien (kế thừa từ NhanVien)
class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    LapTrinhVien(string ma, string ten, int tuoi, string sdt, string email, double luong, int overtime)
        : NhanVien(ma, ten, tuoi, sdt, email, luong), soGioOvertime(overtime) {}

    double tinhLuong() override {
        return luongCoBan + soGioOvertime * 200000;
    }

    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << ", So gio OT: " << soGioOvertime << ", Luong: " << tinhLuong() << endl;
    }
};

// Lớp KiemChungVien (kế thừa từ NhanVien)
class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;

public:
    KiemChungVien(string ma, string ten, int tuoi, string sdt, string email, double luong, int soLoi)
        : NhanVien(ma, ten, tuoi, sdt, email, luong), soLoiPhatHien(soLoi) {}

    double tinhLuong() override {
        return luongCoBan + soLoiPhatHien * 50000;
    }

    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << ", So loi phat hien: " << soLoiPhatHien << ", Luong: " << tinhLuong() << endl;
    }
};

// Hàm tính lương trung bình của toàn bộ nhân viên
double tinhLuongTrungBinh(const vector<NhanVien*>& danhSachNV) {
    double tongLuong = 0;
    for (NhanVien* nv : danhSachNV) {
        tongLuong += nv->tinhLuong();
    }
    return tongLuong / danhSachNV.size();
}

// Hàm liệt kê danh sách nhân viên có lương thấp hơn lương trung bình
void lietKeNhanVienLuongThapHonTB(const vector<NhanVien*>& danhSachNV, double luongTB) {
    cout << "Danh sach nhan vien co luong thap hon muc luong trung binh:\n";
    for (NhanVien* nv : danhSachNV) {
        if (nv->tinhLuong() < luongTB) {
            nv->xuatThongTin();
        }
    }
}

int main() {
    vector<NhanVien*> danhSachNV;
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int loaiNV;
        cout << "Nhap loai nhan vien (1 - Lap trinh vien, 2 - Kiem chung vien): ";
        cin >> loaiNV;

        string ma, ten, sdt, email;
        int tuoi, overtime, soLoi;
        double luongCoBan;
        cout << "Nhap ma NV: "; cin >> ma;
        cout << "Nhap ho ten: "; cin.ignore(); getline(cin, ten);
        cout << "Nhap tuoi: "; cin >> tuoi;
        cout << "Nhap so dien thoai: "; cin >> sdt;
        cout << "Nhap email: "; cin >> email;
        cout << "Nhap luong co ban: "; cin >> luongCoBan;

        if (loaiNV == 1) {
            cout << "Nhap so gio overtime: "; cin >> overtime;
            danhSachNV.push_back(new LapTrinhVien(ma, ten, tuoi, sdt, email, luongCoBan, overtime));
        } else if (loaiNV == 2) {
            cout << "Nhap so loi phat hien: "; cin >> soLoi;
            danhSachNV.push_back(new KiemChungVien(ma, ten, tuoi, sdt, email, luongCoBan, soLoi));
        }
    }

    cout << "\nDanh sach nhan vien:\n";
    for (NhanVien* nv : danhSachNV) {
        nv->xuatThongTin();
    }

    double luongTrungBinh = tinhLuongTrungBinh(danhSachNV);
    cout << "\nLuong trung binh cua cong ty: " << luongTrungBinh << endl;

    lietKeNhanVienLuongThapHonTB(danhSachNV, luongTrungBinh);

    // Giải phóng bộ nhớ
    for (NhanVien* nv : danhSachNV) {
        delete nv;
    }

    return 0;
}

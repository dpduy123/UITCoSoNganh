#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp cơ sở NhanVien
class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luongCoBan;

public:
    NhanVien(string ten, string ngay, double luong)
        : hoTen(ten), ngaySinh(ngay), luongCoBan(luong) {}

    virtual double tinhLuong() = 0; // Phương thức ảo thuần túy
    virtual void xuatThongTin() {
        cout << "Ho Ten: " << hoTen << ", Ngay Sinh: " << ngaySinh << ", Luong: " << tinhLuong() << endl;
    }

    string getHoTen() { return hoTen; }
};

// Lớp NhanVienVanPhong
class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
    double troCap;

public:
    NhanVienVanPhong(string ten, string ngay, double luong, int ngayLam, double troCap)
        : NhanVien(ten, ngay, luong), soNgayLamViec(ngayLam), troCap(troCap) {}

    double tinhLuong() override {
        return luongCoBan + soNgayLamViec * 200000 + troCap;
    }

    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << "Bo phan: Van Phong, So Ngay Lam Viec: " << soNgayLamViec << ", Tro Cap: " << troCap << endl;
    }
};

// Lớp NhanVienSanXuat
class NhanVienSanXuat : public NhanVien {
private:
    int soSanPham;

public:
    NhanVienSanXuat(string ten, string ngay, double luong, int sanPham)
        : NhanVien(ten, ngay, luong), soSanPham(sanPham) {}

    double tinhLuong() override {
        return luongCoBan + soSanPham * 2000;
    }

    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << "Bo phan: San Xuat, So San Pham: " << soSanPham << endl;
    }
};

// Lớp NhanVienQuanLy
class NhanVienQuanLy : public NhanVien {
private:
    double heSoChucVu;
    double thuong;

public:
    NhanVienQuanLy(string ten, string ngay, double luong, double heSo, double thuong)
        : NhanVien(ten, ngay, luong), heSoChucVu(heSo), thuong(thuong) {}

    double tinhLuong() override {
        return luongCoBan * heSoChucVu + thuong;
    }

    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << "Bo phan: Quan Ly, He So Chuc Vu: " << heSoChucVu << ", Thuong: " << thuong << endl;
    }
};

// Hàm tính tổng lương của công ty
double tinhTongLuong(const vector<NhanVien*>& danhSachNV) {
    double tongLuong = 0;
    for (NhanVien* nv : danhSachNV) {
        tongLuong += nv->tinhLuong();
    }
    return tongLuong;
}

// Hàm tìm kiếm nhân viên theo họ tên
void timKiemNhanVien(const vector<NhanVien*>& danhSachNV, const string& hoTen) {
    bool found = false;
    for (NhanVien* nv : danhSachNV) {
        if (nv->getHoTen() == hoTen) {
            nv->xuatThongTin();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay nhan vien co ten: " << hoTen << endl;
    }
}

int main() {
    vector<NhanVien*> danhSachNV;
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int loaiNV;
        cout << "Nhap loai nhan vien (1 - Van Phong, 2 - San Xuat, 3 - Quan Ly): ";
        cin >> loaiNV;

        string ten, ngaySinh;
        double luongCoBan;
        cout << "Nhap ho ten: "; cin.ignore(); getline(cin, ten);
        cout << "Nhap ngay sinh: "; getline(cin, ngaySinh);
        cout << "Nhap luong co ban: "; cin >> luongCoBan;

        if (loaiNV == 1) {
            int soNgayLam;
            double troCap;
            cout << "Nhap so ngay lam viec: "; cin >> soNgayLam;
            cout << "Nhap tro cap: "; cin >> troCap;
            danhSachNV.push_back(new NhanVienVanPhong(ten, ngaySinh, luongCoBan, soNgayLam, troCap));
        } else if (loaiNV == 2) {
            int soSanPham;
            cout << "Nhap so san pham: "; cin >> soSanPham;
            danhSachNV.push_back(new NhanVienSanXuat(ten, ngaySinh, luongCoBan, soSanPham));
        } else if (loaiNV == 3) {
            double heSoChucVu, thuong;
            cout << "Nhap he so chuc vu: "; cin >> heSoChucVu;
            cout << "Nhap thuong: "; cin >> thuong;
            danhSachNV.push_back(new NhanVienQuanLy(ten, ngaySinh, luongCoBan, heSoChucVu, thuong));
        }
    }

    cout << "\nThong tin nhan vien:\n";
    for (NhanVien* nv : danhSachNV) {
        nv->xuatThongTin();
    }

    double tongLuong = tinhTongLuong(danhSachNV);
    cout << "\nTong luong cua cong ty: " << tongLuong << endl;

    string hoTenTimKiem;
    cout << "\nNhap ho ten nhan vien can tim: ";
    cin.ignore();
    getline(cin, hoTenTimKiem);
    timKiemNhanVien(danhSachNV, hoTenTimKiem);

    // Giải phóng bộ nhớ
    for (NhanVien* nv : danhSachNV) {
        delete nv;
    }

    return 0;
}

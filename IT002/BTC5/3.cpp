#include <bits/stdc++.h>

class DaThuc {
private:
    std::vector<double> he_so; // Danh sách hệ số của đa thức

public:
    // Khởi tạo đa thức bậc 0
    DaThuc() {
        he_so.push_back(0); // Đa thức bậc 0
    }

    // Khởi tạo đa thức bậc n bất kỳ
    DaThuc(const std::vector<double>& hs) : he_so(hs) {}

    // Tính giá trị đa thức tại x
    double gia_tri(double x) const {
        double ket_qua = 0;
        for (size_t i = 0; i < he_so.size(); ++i) {
            ket_qua += he_so[i] * pow(x, i);
        }
        return ket_qua;
    }

    // Định nghĩa toán tử <<
    friend std::ostream& operator<<(std::ostream& os, const DaThuc& dt) {
        for (size_t i = 0; i < dt.he_so.size(); ++i) {
            if (dt.he_so[i] != 0) {
                if (i > 0) os << " + ";
                if (i == 0) os << dt.he_so[i];
                else if (i == 1) os << dt.he_so[i] << "x";
                else os << dt.he_so[i] << "x^" << i;
            }
        }
        return os;
    }

    // Định nghĩa toán tử >>
    friend std::istream& operator>>(std::istream& is, DaThuc& dt) {
        int n;
        std::cout << "Nhập bậc của đa thức: ";
        is >> n;
        dt.he_so.resize(n + 1);
        std::cout << "Nhập các hệ số từ bậc 0 đến bậc " << n << ": ";
        for (int i = 0; i <= n; ++i) {
            is >> dt.he_so[i];
        }
        return is;
    }

    // Định nghĩa toán tử +
    DaThuc operator+(const DaThuc& other) const {
        DaThuc ket_qua;
        size_t max_len = std::max(he_so.size(), other.he_so.size());
        ket_qua.he_so.resize(max_len, 0);
        for (size_t i = 0; i < max_len; ++i) {
            if (i < he_so.size()) ket_qua.he_so[i] += he_so[i];
            if (i < other.he_so.size()) ket_qua.he_so[i] += other.he_so[i];
        }
        return ket_qua;
    }

    // Định nghĩa toán tử -
    DaThuc operator-(const DaThuc& other) const {
        DaThuc ket_qua;
        size_t max_len = std::max(he_so.size(), other.he_so.size());
        ket_qua.he_so.resize(max_len, 0);
        for (size_t i = 0; i < max_len; ++i) {
            if (i < he_so.size()) ket_qua.he_so[i] += he_so[i];
            if (i < other.he_so.size()) ket_qua.he_so[i] -= other.he_so[i];
        }
        return ket_qua;
    }
};

signed main() {
    DaThuc dt1, dt2;

    // Nhập đa thức thứ nhất
    std::cin >> dt1;
    std::cout << "Đa thức 1: " << dt1 << std::endl;

    // Nhập đa thức thứ hai
    std::cin >> dt2;
    std::cout << "Đa thức 2: " << dt2 << std::endl;

    // Tính tổng của hai đa thức
    DaThuc tong = dt1 + dt2;
    std::cout << "Tổng: " << tong << std::endl;

    // Tính hiệu của hai đa thức
    DaThuc hieu = dt1 - dt2;
    std::cout << "Hiệu: " << hieu << std::endl;

    // Tính giá trị của đa thức tại x
    double x;
    std::cout << "Nhập giá trị x: ";
    std::cin >> x;
    std::cout << "Giá trị của đa thức 1 tại x: " << dt1.gia_tri(x) << std::endl;
    std::cout << "Giá trị của đa thức 2 tại x: " << dt2.gia_tri(x) << std::endl;

    return 0;
}

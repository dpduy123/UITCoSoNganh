#include <iostream>
#include <vector>
#include <iomanip>

class DaThuc {
private:
    std::vector<double> heSo; // Lưu trữ các hệ số của đa thức

public:
    // Khởi tạo đa thức với bậc n
    DaThuc(int bac = 0) {
        heSo.resize(bac + 1, 0.0); // Khởi tạo hệ số bằng 0
    }

    // Nhập đa thức
    void nhapDaThuc() {
        int bac;
        std::cout << "Nhập bậc của đa thức: ";
        std::cin >> bac;
        heSo.resize(bac + 1);
        std::cout << "Nhập các hệ số (từ bậc cao nhất đến bậc thấp nhất):\n";
        for (int i = bac; i >= 0; --i) {
            std::cout << "a[" << i << "] = ";
            std::cin >> heSo[i];
        }
    }

    // Xuất đa thức
    void xuatDaThuc() const {
        for (int i = heSo.size() - 1; i >= 0; --i) {
            if (heSo[i] != 0) {
                if (i != heSo.size() - 1 && heSo[i] > 0) {
                    std::cout << "+";
                }
                std::cout << std::fixed << std::setprecision(2) << heSo[i];
                if (i > 0) {
                    std::cout << "x";
                    if (i > 1) {
                        std::cout << "^" << i;
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    // Tính giá trị của đa thức tại x
    double giaTriDaThuc(double x) const {
        double giaTri = 0.0;
        for (int i = 0; i < heSo.size(); ++i) {
 signed main()
 {
    return 0;
 }

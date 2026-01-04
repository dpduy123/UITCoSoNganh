#include <bits/stdc++.h> 

class MaTran {
private:
    std::vector<std::vector<int>> data; // Dữ liệu ma trận
    int m, n; // Số dòng và số cột

public:
    // Constructor tạo ma trận ngẫu nhiên
    MaTran(int rows, int cols) : m(rows), n(cols) {
        data.resize(m, std::vector<int>(n));
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = rand() % 100; // Giá trị ngẫu nhiên từ 0 đến 99
            }
        }
    }

    // Constructor nhập ma trận
    MaTran() : m(0), n(0) {}

    void nhap() {
        std::cout << "Nhập số dòng: ";
        std::cin >> m;
        std::cout << "Nhập số cột: ";
        std::cin >> n;
        data.resize(m, std::vector<int>(n));
        std::cout << "Nhập ma trận:\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << "Nhập phần tử [" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    // Operator cộng hai ma trận
    MaTran operator+(const MaTran& other) const {
        if (m != other.m || n != other.n) {
            throw std::invalid_argument("Hai ma trận phải cùng kích thước để cộng.");
        }
        MaTran result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Operator nhân hai ma trận
    MaTran operator*(const MaTran& other) const {
        if (n != other.m) {
            throw std::invalid_argument("Số cột của ma trận thứ nhất phải bằng số dòng của ma trận thứ hai.");
        }
        MaTran result(m, other.n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < other.n; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Xuất ma trận
    friend std::ostream& operator<<(std::ostream& os, const MaTran& mt) {
        for (int i = 0; i < mt.m; ++i) {
            for (int j = 0; j < mt.n; ++j) {
                os << mt.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};
int main() {
    // Tạo hai ma trận từ bàn phím
    MaTran mt1, mt2;
    mt1.nhap();

    std::cout << "Ma trận 1:\n" << mt1 << std::endl;

    mt2.nhap();
    std::cout << "Ma trận 2:\n" << mt2 << std::endl;

    // Cộng hai ma trận
    try {
        MaTran tong = mt1 + mt2;
        std::cout << "Tổng hai ma trận:\n" << tong << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    // Nhân hai ma trận
    try {
        MaTran tich = mt1 * mt2;
        std::cout << "Tích hai ma trận:\n" << tich << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

class cBook {
private:
    std::string maSach;
    std::string tenSach;
    int namXuatBan;
    int tongSoTrang;

public:
    // Thiết lập thông tin sách
    void setInfo(const std::string& ma, const std::string& ten, int nam, int trang) {
        maSach = ma;
        tenSach = ten;
        namXuatBan = nam;
        tongSoTrang = trang;
    }

    // Nhập thông tin sách từ bàn phím
    void nhapSach() {
        std::cout << "Nhập mã sách: ";
        std::cin >> maSach;
        std::cin.ignore(); // Để xóa ký tự newline
        std::cout << "Nhập tên sách: ";
        std::getline(std::cin, tenSach);
        std::cout << "Nhập năm xuất bản: ";
        std::cin >> namXuatBan;
        std::cout << "Nhập tổng số trang: ";
        std::cin >> tongSoTrang;
    }

    // Xuất thông tin sách ra màn hình
    void xuatSach() const {
        std::cout << "Mã sách: " << maSach << ", Tên sách: " << tenSach
                  << ", Năm xuất bản: " << namXuatBan << ", Tổng số trang: "
                  << tongSoTrang << std::endl;
    }

    // Truy vấn và cập nhật thông tin
    void capNhatThongTin() {
        std::cout << "Cập nhật thông tin sách:\n";
        std::cout << "Nhập tên sách mới: ";
        std::cin.ignore();
        std::getline(std::cin, tenSach);
        std::cout << "Nhập năm xuất bản mới: ";
        std::cin >> namXuatBan;
        std::cout << "Nhập tổng số trang mới: ";
        std::cin >> tongSoTrang;
    }

    // Lấy năm xuất bản
    int getNamXuatBan() const {
        return namXuatBan;
    }
};

class cListBook {
private:
    std::vector<cBook> danhSachSach;

public:
    // Nhập danh sách các đối tượng sách
    void nhapDanhSachSach() {
        int n;
        std::cout << "Nhập số lượng sách: ";
        std::cin >> n;
        danhSachSach.resize(n);
        for (int i = 0; i < n; ++i) {
            std::cout << "Nhập thông tin sách thứ " << i + 1 << ":\n";
            danhSachSach[i].nhapSach();
        }
    }

    // Xuất danh sách các đối tượng sách
    void xuatDanhSachSach() const {
        std::cout << "Danh sách sách:\n";
        for (const auto& sach : danhSachSach) {
            sach.xuatSach();
        }
    }

    // Cho biết sách nào được xuất bản gần đây nhất
    void sachXuatBanGanDayNhat() const {
        if (danhSachSach.empty()) {
            std::cout << "Danh sách sách rỗng." << std::endl;
            return;
        }

        const cBook* sachGanDayNhat = &danhSachSach[0];
        for (const auto& sach : danhSachSach) {
            if (sach.getNamXuatBan() > sachGanDayNhat->getNamXuatBan()) {
                sachGanDayNhat = &sach;
            }
        }
        std::cout << "Sách được xuất bản gần đây nhất:\n";
        sachGanDayNhat->xuatSach();
    }
};

signed main() {
    cListBook listBook;

    // Nhập danh sách sách
    listBook.nhapDanhSachSach();

    // Xuất danh sách sách
    listBook.xuatDanhSachSach();

    // Tìm sách được xuất bản gần đây nhất
    listBook.sachXuatBanGanDayNhat();

    return 0;
}

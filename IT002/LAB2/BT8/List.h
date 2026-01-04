#include <bits/stdc++.h>

using namespace std;

class List {
private:
    double* arr;             // Con trỏ quản lý mảng
    unsigned int size;       // Kích thước của list
    unsigned int capacity;   // Dung lượng tối đa của list

    void resize() {          // Hàm thay đổi kích thước mảng
        capacity *= 2;
        double* newArr = new double[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
public:
    List() : size(0), capacity(1) { // Khởi tạo list rỗng
        arr = new double[capacity];
    }
    ~List() { // Destructor để giải phóng bộ nhớ
        delete[] arr;
    }
    void add(double x) { // Thêm phần tử vào list
        if (size == capacity) {
            resize();
        }
        arr[size++] = x;
    }
    void removeFirst(double x) { // Xóa phần tử đầu tiên có giá trị x
        for (unsigned int i = 0; i < size; ++i) {
            if (arr[i] == x) {
                for (unsigned int j = i; j < size - 1; ++j) {
                    arr[j] = arr[j + 1];
                }
                --size;
                return;
            }
        }
    }
    void removeAll(double x) { // Xóa tất cả các phần tử có giá trị x
        unsigned int i = 0;
        while (i < size) {
            if (arr[i] == x) {
                removeFirst(x);
            } else {
                ++i;
            }
        }
    }
    void update(unsigned int index, double y) { // Cập nhật phần tử tại index
        if (index < size) {
            arr[index] = y;
        }
    }

    void print() const { // In danh sách
        cout << "[";
        for (unsigned int i = 0; i < size; ++i) {
            cout << fixed << std::setprecision(2) << arr[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << std::endl;
    }
};
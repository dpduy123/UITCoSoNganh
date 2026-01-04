#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstdlib>   
#include <ctime>     

using namespace std;

class cArray {
private:
    vector<int> arr; 

public:
    // Constructor tạo lập mảng gồm n số nguyên ngẫu nhiên
    cArray(int n, int min_val = -100, int max_val = 100) {
        srand(time(0)); // Khởi tạo bộ sinh số ngẫu nhiên
        for (int i = 0; i < n; i++) {
            arr.push_back(min_val + rand() % (max_val - min_val + 1));
        }
    }

    //  xuất mảng ra màn hình
    void output() {
        cout << "Array: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    // tìm số âm lớn nhất
    int negative_max() {
        int largest_negative = -1e9; // Giá trị rất nhỏ
        bool found_negative = false;

        for (int num : arr) {
            if (num < 0 && num > largest_negative) {
                largest_negative = num;
                found_negative = true;
            }
        }
        return found_negative ? largest_negative : 0; // Trả về 0 nếu không có số âm
    }

    //  đếm lần xuất hiện của một số nguyên x
    int nb_app(int x) {
        int count = 0;
        for (int num : arr) {
            if (num == x) {
                count++;
            }
        }
        return count;
    }

    //  kiểm tra mảng có giảm dần hay không
    bool decreasing() {
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    //  sắp xếp mảng tăng dần
    void sort_arr() {
        sort(arr.begin(), arr.end());
    }
};

// Hàm main để kiểm tra các chức năng của lớp cArray
int main() {
    int pt ;
    cout << "nhập số phần tử cho mảng: " ; 
    cin >> pt ; //
    cArray myArray(pt); // Tạo mảng ngẫu nhiên gồm 10 số nguyên
    myArray.output();

    int largest_negative = myArray.negative_max();
    if (largest_negative != 0) {
        cout << "Số âm lớn nhất:" << largest_negative << endl;
    } else {
        cout << "Không có số âm trong mảng: " << endl;
    }

    int x ;
    cout << "Đếm lần xuất hiện của một số nguyên x: " ;
    cin >> x ;
    cout << "Sự xuất hiện của " << x << ": " << myArray.nb_app(x) << endl;

    if (myArray.decreasing()) {
        cout << "Mảng đang giảm." << endl;
    } else {
        cout << "Mảng không giảm dần." << endl;
    }

    myArray.sort_arr();
    cout << "Mảng sau khi sắp xếp theo thứ tự tăng dần ";
    myArray.output();

    return 0;
}
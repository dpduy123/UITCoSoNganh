#include "List.h" 

signed main()
{
    List myList;
    int n;
    double x, y;
    while (true) {
        cin >> n;
        if (n == -1) {
            break; // Nhảy đến B3
        }
        switch (n) {
            case 0:
                cin >> x;
                myList.add(x);
                break;
            case 1:
                cin >> x;
                myList.removeFirst(x);
                break;
            case 2:
                cin >> x;
                myList.removeAll(x);
                break;
            case 3:
                cin >> x >> y;
                myList.update(static_cast<unsigned int>(x), y);
                break;
            default:
                break;
        }
    }
    // B3: In danh sách hiện tại
    myList.print();
    return 0;
}
/* 
    Environment: VSCode
    Mở terminal: 
        Dùng lệnh g++ main.cpp -o main để biên dịch 
        Lệnh ./main để chạy chương trình 
*/

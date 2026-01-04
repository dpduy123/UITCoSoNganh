// Yêu cầu 1: Tạo chữ viết tắt từ tên đầy đủ của doanh nghiệp
void getAbbreviation(char *name, char *abbre)
{
    int abbreIndex = 0; // Theo dõi vị trí trong chuỗi viết tắt

    // Lặp lại qua từng ký tự của tên
    for (int i = 0; i < strlen(name); i++) {
        // Thêm ký tự đầu tiên hoặc ký tự sau dấu cách
        if (i == 0 || name[i - 1] == ' ') {
            abbre[abbreIndex++] = name[i];
        }
    }
    abbre[abbreIndex] = '\0'; // Kết thúc chuỗi
}
// Yêu cầu 2: Xác định loại lệnh
CommandType getCommandType(char *command) 
{
    // So sánh lệnh với các từ khóa được xác định trước
    if (strncmp(command, "Register", 8) == 0)
        return REGISTER;
    if (strncmp(command, "Alter", 5) == 0)
        return ALTER;
    if (strncmp(command, "Show", 4) == 0)
        return SHOW;
    if (strncmp(command, "Delete", 6) == 0)
        return DELETE;
    if (strncmp(command, "Quit", 4) == 0)
        return QUIT;

    return INVALID; // Trả về INVALID nếu không tìm thấy kết quả khớp
}
// Yêu cầu 3: Xác định cấu trúc để lưu trữ thông tin chi tiết về doanh nghiệp
typedef struct
{
    int booth_index;   // Chỉ số gian hàng
    char name[50];     // Tên đầy đủ của doanh nghiệp
    char abbre[10];    // Tên viết tắt 
    int itemValue;     // Giá trị của vật phẩm
    int itemWeight;    // Khối lượng của vật phẩm
} Enterprise;
// Yêu cầu 4: In thông tin chi tiết của một doanh nghiệp cụ thể
void printEnterpriseDetails(Enterprise e)
{
    printf("||%d||%s||%s||%d||%d||\n", 
           e.booth_index, e.name, e.abbre, e.itemValue, e.itemWeight);
}
// Yêu cầu 5: Tạo ra một doanh nghiệp có giá trị cụ thể
void createEnterprise(Enterprise *e, int booth_index, int itemValue, int itemWeight, char *name, char *abbre)
{
    e->booth_index = booth_index;
    e->itemValue = itemValue;
    e->itemWeight = itemWeight;
    strcpy(e->name, name);  // Sao chép tên doanh nghiệp 
    strcpy(e->abbre, abbre); // Sao chép tên viết tắt của doanh nghiệp
}
// Yêu cầu 6: Đăng ký gian hàng cho doanh nghiệp
void registerEnterprise(int map[MAX_ROW][MAX_COLUMN], Enterprise enterpriseArray[MAX_ENTERPRISE],
						char *name, int booth, int itemValue, int itemWeight, int *out_booth, char *out_abbre)
	{
    // Tạo tên viết tắt từ tên đầy đủ và gán vào out_abbre
    getAbbreviation(name, out_abbre);

    // Nếu booth không được chỉ định (booth = -1), tính toán chỉ số gian hàng mặc định
    if (booth == -1) {
        int abbreLen = 0;  // Tính độ dài của tên viết tắt thủ công
        while (out_abbre[abbreLen] != '\0') {
            abbreLen++;
        }
        booth = (abbreLen * 30) % 26;  // Công thức tính booth

        // Tìm một gian hàng trống
        while (map[booth / MAX_COLUMN][booth % MAX_COLUMN] == Registered) {
            booth = (booth + 1) % (MAX_ROW * MAX_COLUMN);  // Duyệt tìm booth trống
        }
    }

    // Kiểm tra trạng thái gian hàng
    if (map[booth / MAX_COLUMN][booth % MAX_COLUMN] == Empty) {
        // Đăng ký gian hàng nếu trống
        map[booth / MAX_COLUMN][booth % MAX_COLUMN] = Registered;  // Cập nhật trạng thái

        // Tìm doanh nghiệp trống trong mảng và tạo mới
        for (int i = 0; i < MAX_ENTERPRISE; i++) {
            if (enterpriseArray[i].booth_index == -1) {  // Doanh nghiệp chưa có booth
                enterpriseArray[i].booth_index = booth;
                enterpriseArray[i].itemValue = itemValue;
                enterpriseArray[i].itemWeight = itemWeight;
                strcpy(enterpriseArray[i].name, name);
                strcpy(enterpriseArray[i].abbre, out_abbre);
                break;
            }
        }

        // Gán giá trị thành công vào out_booth
        *out_booth = booth + 200;

    } else {
        // Gán giá trị thất bại vào out_booth
        *out_booth = booth + 100;
    }
}				
// Yêu cầu 7: Hiển thị bản đồ gian hàng và trạng thái
void showMap(int map[MAX_ROW][MAX_COLUMN], Enterprise enterpriseArray[MAX_ENTERPRISE])
{
    for (int i = 0; i < MAX_ROW; i++) {
        printf("|");
        for (int j = 0; j < MAX_COLUMN; j++) {
            printf("%d|", map[i][j]); // In trạng thái của từng gian hàng
        }
        printf("\n");
    }
}
// Yêu cầu 8: Hiển thị chỉ mục gian hàng dựa trên trạng thái của chúng
void showIndexOfStatus(int map[MAX_ROW][MAX_COLUMN], Status status)
{
    printf("Index[");
    int count = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            if (map[i][j] == status) {
                if (count > 0) {
                    printf(", ");
                }
                printf("%d", i * MAX_COLUMN + j);
                count++;
            }
        }
    }
    printf("]\n");
}
// Yêu cầu 9: Hiển thị tổng số gian hàng có trạng thái cụ thể
void showTotalOfStatus(Enterprise enterpriseArray[MAX_ENTERPRISE], Status status)
{
    int total = 0;
    for (int i = 0; i < MAX_ENTERPRISE; i++) {
        if ((status == Registered && enterpriseArray[i].booth_index != -1) || 
            (status == Empty && enterpriseArray[i].booth_index == -1)) {
            total++;
        }
    }
    printf("Total: %d\n", total);
}
// Yêu cầu 10: Hiển thị chi tiết các gian hàng trong phạm vi được chỉ định
void showIndexBracket(int map[MAX_ROW][MAX_COLUMN], Enterprise enterpriseArray[MAX_ENTERPRISE], int start, int end)
{
    if (end == -1) end = start;
    for (int i = start; i <= end; i++) {
        int row = i / MAX_COLUMN;
        int col = i % MAX_COLUMN;
        printf("Index %d: ", i);
        if (map[row][col] == Empty) {
            printf("NONE\n");
        } else {
            for (int j = 0; j < MAX_ENTERPRISE; j++) {
                if (enterpriseArray[j].booth_index == i) {
                    printEnterpriseDetails(enterpriseArray[j]);
                    break;
                }
            }
        }
    }
}
// Yêu cầu 11: Xử lý lệnh "Show" và gọi hàm thích hợp
void handleShowCommand(int map[MAX_ROW][MAX_COLUMN], Enterprise enterpriseArray[MAX_ENTERPRISE], char *command)
{
    if (strcmp(command, "Show map") == 0) {
        showMap(map, enterpriseArray);
    } else if (strcmp(command, "Show &0") == 0) {
        showIndexOfStatus(map, Empty);
    } else if (strcmp(command, "Show &1") == 0) {
        showIndexOfStatus(map, Registered);
    } else if (strcmp(command, "Show #0") == 0) {
        showTotalOfStatus(enterpriseArray, Empty);
    } else if (strcmp(command, "Show #1") == 0) {
        showTotalOfStatus(enterpriseArray, Registered);
    }
}
// Yêu cầu 12: Thay đổi việc chỉ định gian hàng cho một doanh nghiệp cụ thể
void alterEnterprise(int map[MAX_ROW][MAX_COLUMN], Enterprise enterpriseArray[MAX_ENTERPRISE], char *abbre,
					 int registerBooth, int newBooth, int *out_booth, char *out_abbre)
{
    // Duyệt qua danh sách doanh nghiệp để tìm doanh nghiệp cần thay đổi
    for (int i = 0; i < MAX_ENTERPRISE; i++) {
        if (strcmp(enterpriseArray[i].abbre, abbre) == 0 && enterpriseArray[i].booth_index == registerBooth) {
            // Sao chép tên viết tắt ra out_abbre
            strcpy(out_abbre, abbre);
            // Nếu newBooth không được chỉ định (-1), tìm gian hàng mới tự động
            if (newBooth == -1) {
                newBooth = (registerBooth + 1) % (MAX_ROW * MAX_COLUMN); // Bắt đầu từ gian hàng kế tiếp
                while (map[newBooth / MAX_COLUMN][newBooth % MAX_COLUMN] == Registered) { // Nếu gian hàng đã đăng ký
                    newBooth = (newBooth + 1) % (MAX_ROW * MAX_COLUMN);
                }
            }
            // Kiểm tra trạng thái của newBooth
            if (map[newBooth / MAX_COLUMN][newBooth % MAX_COLUMN] == Empty) { // Nếu gian hàng trống
                // Cập nhật trạng thái của mảng gian hàng
                map[registerBooth / MAX_COLUMN][registerBooth % MAX_COLUMN] = Empty; // Gian hàng cũ trống
                map[newBooth / MAX_COLUMN][newBooth % MAX_COLUMN] = Registered;      // Gian hàng mới đã đăng ký
                // Cập nhật thông tin trong enterpriseArray
                enterpriseArray[i].booth_index = newBooth;
                // Gán giá trị thành công vào out_booth
                *out_booth = newBooth + 200;
                return; // Thoát khỏi hàm
            } else {
                // Gán giá trị thất bại (gian hàng mới không trống) vào out_booth
                *out_booth = registerBooth + 100;
                return; // Thoát khỏi hàm
            }
        }
    }
    // Nếu không tìm thấy doanh nghiệp phù hợp
    *out_booth = registerBooth + 100; // Gán giá trị thất bại
}
// Yêu cầu 13: Xóa doanh nghiệp khỏi hệ thống
void deleteEnterprise(int map[MAX_ROW][MAX_COLUMN], Enterprise enterpriseArray[MAX_ENTERPRISE], char *abbre, int booth, int *totalEmpty)
{
    for (int i = 0; i < MAX_ENTERPRISE; i++) {
        // Xác định doanh nghiệp bằng tên viết tắt và chỉ số gian hàng
        if (strcmp(enterpriseArray[i].abbre, abbre) == 0 && enterpriseArray[i].booth_index == booth) {
            map[booth / MAX_COLUMN][booth % MAX_COLUMN] = Empty;  // Đánh dấu gian hàng là trống
            enterpriseArray[i].booth_index = -1;                 // Đặt lại thông tin doanh nghiệp
            strcpy(enterpriseArray[i].name, "");
            strcpy(enterpriseArray[i].abbre, "");
            enterpriseArray[i].itemValue = 0;
            enterpriseArray[i].itemWeight = 0;
            break;
        }
    }
    // Tính toán lại tổng những gian hàng trống
    *totalEmpty = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            if (map[i][j] == Empty) {
                (*totalEmpty)++;
            }
        }
    }
}
// Yêu cầu 14: Xử lý lệnh và gọi hàm có liên quan
void handleCommand(char *command, int map[MAX_ROW][MAX_COLUMN], Enterprise enterpriseArray[MAX_ENTERPRISE], CommandType *commandType)
{
    *commandType = getCommandType(command); 
     switch (*commandType) {
        case REGISTER: {
            char name[50];
            int booth, itemValue, itemWeight;
            int out_booth;
            char out_abbre[10];
            sscanf(command, "Register [%[^]]] [%d] [%d] [%d]", name, &itemValue, &itemWeight, &booth);

            if (booth == 0) booth = -1;

            registerEnterprise(map, enterpriseArray, name, booth, itemValue, itemWeight, &out_booth, out_abbre);

            if (out_booth >= 200) {
                printf("Đăng ký thành công cho %s ở gian hàng %d.\n", out_abbre, out_booth);
            } else {
                printf("Đăng ký thất bại.\n");
            }
            break;
        }
        case ALTER: {
             // Lệnh thay đổi
            char abbre[10];
            int registerBooth, newBooth;
            int out_booth;
            char out_abbre[10];
            sscanf(command, "Alter [%[^]]] [%d] [%d]", abbre, &registerBooth, &newBooth);
            alterEnterprise(map, enterpriseArray, abbre, registerBooth, newBooth, &out_booth, out_abbre);

            if (out_booth >= 200) {
                printf("Chuyển đổi thành công cho %s sang gian hàng %d.\n", out_abbre, out_booth);
            } else {
                printf("Chuyển đổi thất bại.\n");
            }
            break;
        }
        case SHOW:{
            // Lệnh hiển thị
            handleShowCommand(map, enterpriseArray, command);
            break;
        }    
        case DELETE: {
            // Lệnh xoá
            char abbre[10];
            int booth;
            int totalEmpty;

            sscanf(command, "Delete [%[^]]] [%d]", abbre, &booth);

            deleteEnterprise(map, enterpriseArray, abbre, booth, &totalEmpty);

            printf("Xóa thành công. Tổng số gian hàng trống: %d\n", totalEmpty);
            break;
        }
        case QUIT:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lệnh không hợp lệ.\n");
            break;
    }
}
// Yêu cầu 15: Tối ưu hóa các mục thu thập được bằng thuật toán knapsack
int knapsack(int map[MAX_ROW][MAX_COLUMN], Enterprise enterpriseArray[MAX_ENTERPRISE],
			  int maxWeight)
			 
{
     if (maxWeight <= 0) return 0;
    int maxValue = 0;
    for (int i = 0; i < MAX_ENTERPRISE; i++) {
        if (enterpriseArray[i].booth_index != -1 && enterpriseArray[i].itemWeight <= maxWeight) {
            int val = enterpriseArray[i].itemValue + knapsack(map, enterpriseArray, maxWeight - enterpriseArray[i].itemWeight);
            if (val > maxValue) maxValue = val;
        }
    }
    return maxValue;
}

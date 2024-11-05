#include <stdio.h>

int t;  // Số lượng test cases

int main() {
    scanf("%d", &t);  // Đọc số lượng test cases

    for (int tc = 0; tc < t; ++tc) {  // Lặp qua từng test case
        int n;
        scanf("%d", &n);  // Nhập số lượng rồng trong test case hiện tại

        int a[300001] = {0};  // Mảng đếm số lần xuất hiện của mỗi chiều dài gậy 2^a[i]

        // Đếm số lượng mỗi chiều dài gậy
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);  // Nhập giá trị `a[i]`
            ++a[x];  // Tăng biến đếm tại vị trí `a[x]` để lưu số lần xuất hiện của độ dài gậy này
        }
        
        long long res = 0;  // Biến lưu số cách chọn 3 cây gậy hợp lệ
        int sum = 0;  // Tổng các cây gậy đã duyệt qua
        
        // Xét qua từng chiều dài có thể
        for (int i = 0; i <= n; ++i) {
            long long cnt = a[i];  // Số cây gậy có cùng chiều dài `2^i`

            // Nếu có ít nhất 3 cây gậy cùng chiều dài, ta tính số cách chọn 3 cây gậy từ `cnt`
            if (cnt >= 3)
                res += cnt * (cnt - 1) * (cnt - 2) / 6;  // Số tổ hợp C(cnt, 3)

            // Nếu có ít nhất 2 cây gậy cùng chiều dài và số cây khác (tổng `sum`) thì tính tổ hợp
            if (cnt >= 2)
                res += cnt * (cnt - 1) / 2 * sum;  // Số tổ hợp C(cnt, 2) * sum, kết hợp với các cây gậy đã duyệt

            // Cập nhật tổng `sum` với số cây gậy có chiều dài `2^i`
            sum += cnt;
        }
        
        printf("%lld\n", res);  // In kết quả cho mỗi test case
    }

    return 0;
}

#include <stdio.h>
#include <math.h>
#define ll long long

int main() {
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);  // Nhập vào vị trí kho báu `x`, vị trí chìa khóa `y` và giới hạn sức lực `k`

    int time = 0;  // Biến lưu số giây ít nhất cần thiết

    if (x < y) {
        time += x;  // Nếu kho báu nằm ở vị trí nhỏ hơn chìa khóa, Đạt cần di chuyển đến kho báu trước, mất `x` giây
        
        // Tính khoảng cách từ kho báu đến chìa khóa
        if ((y - x) > k) {  
            // Nếu khoảng cách từ kho báu đến chìa khóa lớn hơn `k`, Đạt chỉ có thể khiêng kho báu tối đa `k` bước
            time += k;  // Di chuyển kho báu `k` bước về phía chìa khóa
            time += 2 * (y - (x + k));  // Khoảng cách còn lại phải đi thêm, mất gấp đôi số giây do phải đi lại hai lần
        } else {
            // Nếu khoảng cách từ kho báu đến chìa khóa nhỏ hơn hoặc bằng `k`
            time += (y - x);  // Di chuyển trực tiếp kho báu từ `x` đến `y`, mất `y - x` giây
        }
    } else {
        // Nếu kho báu nằm ở vị trí lớn hơn hoặc bằng chìa khóa
        time += x;  // Đạt chỉ cần đi đến vị trí kho báu, mất `x` giây
    }

    printf("%d", time);  // In ra số giây ít nhất cần thiết để mở khóa kho báu
    return 0;
}

#include <stdio.h> 
#define ll long long

int main() {
    int n; 
    scanf("%d", &n);  // Nhập số nguyên n từ người dùng
    
    n--;  // Giảm n đi 1, để thuận tiện tính toán tổng cho n - 1 (theo cách tính tổng dãy số)

    // Tính tổng từ 1 đến n, sử dụng công thức tổng dãy số: (n * (n + 1)) / 2
    ll sum = 1ll * n * (n + 1) / 2;  // Sử dụng 1ll để đảm bảo tính toán chính xác với số lớn

    // In kết quả tổng
    printf("%lld", sum);  // In ra giá trị của tổng A

    return 0;  // Kết thúc chương trình
}

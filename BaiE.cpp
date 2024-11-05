#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// Hàm kiểm tra một số nguyên n có phải là số nguyên tố hay không
int kt(int n) {
    if (n < 4) return n > 1;  // 2, 3 là số nguyên tố
    int x = sqrt(n);  // Tính căn bậc hai của n để giảm số lần lặp
    for (int i = 2; i <= x; ++i) {  // Kiểm tra từ 2 đến căn bậc hai
        if (n % i == 0) return 0;  // Nếu n chia hết cho i thì n không phải là số nguyên tố
    }
    return 1;  // n là số nguyên tố
}

int main() {
    long long n;  
    scanf("%lld", &n);  
    int d = 0;  // Biến đếm số có đúng 9 ước số
    // Số có 9 ước là số nguyên tố mũ 8 hoặc tích bình phương của 2 số nguyên tố
    // Đếm các số có căn bậc 8 là số nguyên tố
    for (int i = 2; (long long)powl(i, 8) <= n; ++i) {  
        if (kt(i)) ++d;  // Nếu i là số nguyên tố, tăng đếm
    }
    int x = sqrt(n);  // Tính căn bậc hai của n
    int y = sqrt(x);  // Tính căn bậc 4 của n
    // Đếm các số là tích bình phương của 2 số nguyên tố
    for (int i = 2; i <= y; ++i) {  // Duyệt qua các số từ 2 đến y
        if (kt(i)) {  // Nếu i là số nguyên tố
            for (int j = x / i; j > i; --j) {  // Duyệt các số q
                if (kt(j)) ++d;  // Nếu j là số nguyên tố, tăng đếm
            }
        }
    }
    printf("%d", d);  // In ra số lượng số có đúng 9 ước số
    return 0;  // Kết thúc chương trình
}

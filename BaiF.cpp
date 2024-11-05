#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    int T = 1; // Biến T để lưu số lượng bộ test, ở đây T được đặt là 1 vì chỉ có một bộ test.
    //scanf ("%d", &T);
    while (T--)
    {
        int n, d = -2e9, l = 1, r;
        scanf ("%d", &n); // Nhập số lượng bức tường
        int a[n + 2]; // Mảng a lưu chiều cao của các bức tường
        for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]); // Nhập chiều cao các bức tường vào mảng a
        r = n; // r là chỉ số của bức tường bên phải, bắt đầu từ cuối mảng
        while (l < r) // Lặp khi chỉ số l vẫn nhỏ hơn chỉ số r
        {
            // Tính diện tích bể nước giữa hai bức tường tại vị trí l và r
            // d = max(d, min(a[l], a[r]) * (r - l))
            // fmin(a[l], a[r]) lấy chiều cao của bức tường thấp hơn trong hai bức tường a[l] và a[r]
            // (r - l) là khoảng cách giữa hai bức tường
            // fmax được sử dụng để cập nhật giá trị lớn nhất của d
            d = fmax(fmin(a[l], a[r]) * (r - l), d);
            // Di chuyển chỉ số l hoặc r để tìm các diện tích lớn hơn
            if (a[l] < a[r]) ++l; // Nếu chiều cao của bức tường bên trái nhỏ hơn, tăng l để dịch vào giữa
            else --r; // Nếu chiều cao của bức tường bên phải nhỏ hơn hoặc bằng, giảm r để dịch vào giữa
        }
        printf ("%d", d); // In ra diện tích lớn nhất của bể nước
    }
}

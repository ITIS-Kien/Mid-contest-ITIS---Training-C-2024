#include<stdio.h>
#include<math.h>
#define ll long long

int main(){
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld %lld", (a + b) * (a + b), a * a + b * b);
}

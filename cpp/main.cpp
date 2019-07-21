#include <cstdio>
#include <cstring>
#include <map>
#pragma warning(disable : 4996)

using namespace std;
typedef long long int lli;
char table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmopqrstuvwxyz.,?!\"'~+-*/ ";
map<char, int> codeof;
char plain[10000];
lli pow(lli, lli, lli);
lli gcd(lli, lli);
bool exist(char);
void fcode(void);
int main() {
	lli p, q, e;
	printf("Welcome to KASCII RSA encoder!\n\n");
	printf("Enter the value of p, q, e (p and q must NEVER be revealed.): \n");
	scanf("%lld %lld %lld", &p, &q, &e);
	lli n = p * q;
	fcode();
	printf("Encryption key created: (%lld, %lld)\n", n, e);
	printf("Enter the plain text: \n");
	getchar();
	fgets(plain, sizeof(plain), stdin);
	int len = strlen(plain);//
	for (int i = 0; i < len; i++) {
		if (exist(plain[i])) {
			int C = (int) pow(plain[i], e, n);
			printf("%c", table[C]);
		}
		else {
			printf("%c", plain[i]);
		}
	}

	return 0;
}
lli pow(lli bs, lli pw, lli md) {
	lli ans = 1;
	for (int i = 0; i < pw; i++) {
		ans *= bs;
		ans %= md;
	}
	return ans;
}
lli gcd(lli a, lli b) {
	return b ? gcd(b, a % b) : a;
}
void fcode(void) {
	for (char c = 'A'; c <= 'Z'; c++) codeof[c] = c - 'A';
	for (char c = 'a'; c <= 'z'; c++) codeof[c] = c - 'a';
	codeof['.'] = 52;
	codeof[','] = 53;
	codeof['?'] = 54;
	codeof['!'] = 55;
	codeof['"'] = 56;
	codeof['\''] = 57;
	codeof['~'] = 58;
	codeof['+'] = 59;
	codeof['-'] = 60;
	codeof['*'] = 61;
	codeof['/'] = 62;
	codeof[' '] = 63;
}
bool exist(char c) {
	if (codeof.find(c) != codeof.end()) return true;
	return false;
}

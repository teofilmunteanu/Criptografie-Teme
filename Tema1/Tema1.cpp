#include<iostream>
using namespace std;

struct x {
	long long u, v;
};

struct divisor {
	x uv;
	unsigned long long d;
};

divisor CMMDC(unsigned long long a, unsigned long long b)
{
	unsigned long long r, q;
	long long aux;
	x xa = { 1,0 }, xb = { 0,1 };
	divisor cmmdc;
	do
	{
		r = a % b;
		q = a / b;
		aux = xb.u;
		xb.u = xa.u - q * xb.u;
		xa.u = aux;
		aux = xb.v;
		xb.v = xa.v - q * xb.v;
		xa.v = aux;
		a = b;
		b = r;
	} while (r != 0);
	cmmdc.d = a;
	cmmdc.uv.u = xa.u;
	cmmdc.uv.v = xa.v;
	return cmmdc;
}

int main()
{
	unsigned long long a, n, ap, bp;
	cin >> a >> n;

	divisor X = CMMDC(a, n);
	cout << "Inversul unui numar in Z"<<n<<":" << X.uv.u;
}

#include <bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000

double func(double x)
{
	return x*x*x - 5*x + 3;
}

void regulaFalsi(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "Your a & b must be more than zero when multiplied.\n";
		return;
	}

	double c = a;

	c = (a*func(b) - b*func(a)) / (func(b) - func(a));
	cout << "a         b      f(a)        f(b)      c         f(c)" << endl;
	cout << a << "         " << b << "      " << func(a) << "          " << func(b) << "      " << c << "      " << func(c) << endl;

	for (int i = 0; i < MAX_ITER; i++)
	{
		if (fabs(func(c)) < 0.001)
			break;

		else if (func(c) * func(a) < 0)
			b = c;
		else
			a = c;

		c = (a * func(b) - b * func(a)) / (func(b) - func(a));
		cout << a << "   " << b << "   " << func(a) << "      " << func(b) << "      " << c << "      " << func(c) << endl;
	}

	cout << "value of root is : " << c;
}

int main()
{
	double a = 0, b = 1;
	regulaFalsi(a, b);
	return 0;
}

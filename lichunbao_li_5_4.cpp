#include <iostream>
using namespace std;
#define N 9

void fun(char op[], int sum, int prevadd, int a[], int i)
{
	if (i == N) {
		if (sum == 100) {
			cout << " " << a[0];
			for (int j = 1; j < N; j++) {
				if (op[j] != ' ')
					cout << op[j];
				cout << a[j];
			}
			cout << "=100" << endl;
		}
		return;
	}
	op[i] = '+';
	sum += a[i];
	fun(op, sum, a[i], a, i + 1);
	sum -= a[i];

	op[i] = '-';
	sum -= a[i];
	fun(op, sum, -a[i], a, i + 1);
	sum += a[i];

	op[i] = ' ';
	sum -= prevadd;
	int tmp;
	if (prevadd > 0)
		tmp = prevadd * 10 + a[i];
	else {
		tmp = prevadd * 10 - a[i];
	}
	sum += tmp;
	fun(op, sum, tmp, a, i + 1);
	sum -= tmp;
	sum += prevadd;
}


int main()
{
	int a[N];
	char op[N];
	for (int i = 0; i < N; i++) {
		a[i] = i + 1;
	}
	cout << "result: "<<endl;
	fun(op, a[0], a[0], a, 1);
	cin >> a[1];
	return 0;
}
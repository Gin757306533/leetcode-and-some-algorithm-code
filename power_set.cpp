#include <iostream>
using namespace std;
#define N 100
void display(int a[], int n, int x[]) {
	cout << " {";
	for (int i = 0; i < n; i++) {
		if (x[i] == 1) {
			cout << a[i];
		}
	}
	cout << "} ";
}

void dfs(int a[], int n, int i, int x[]) {
	if (i >=n) {
		display(a, n, x);
	}
	else {
		x[i] = 0; dfs(a, n, i + 1, x);
		x[i] = 1; dfs(a, n, i + 1, x);
	}
}


int main()
{
	int a[] = { 1,2,3 };
	int n = sizeof(a) / sizeof(a[0]);
	int x[N];
	memset(x, 0, sizeof(x));
	cout << "result: " << endl;
	dfs(a, n, 0, x);
	cout << endl;
	cin >> n;
	return 0;
}
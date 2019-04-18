#include <bits/stdc++.h>

using namespace std;

int mdc (int a, int b)
{
	if (b == 0) return a;
	return mdc (b, a%b);
}

int mmc (int a, int b)
{

	return b*(a/mdc (b, a));
}

int main ()
{
	int N, L, i, m, r = 0;
	scanf ("%d %d", &N, &L);
	int n[N];
	for (i = 0; i < N; i++) scanf ("%d", &(n[i]));
	m = n[0];
	for (i = 1; i < N; i++) m = mmc (m, n[i]);
	r = (mdc (m, L/m))*(L/m);
	if (L/mmc(m, r) != 1) r = r*(L/r);
	printf ("%d\n", r);
	return 0;
}

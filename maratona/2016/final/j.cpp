#include <bits/stdc++.h>

int main ()
{
	long long int i, j, n, t;
	scanf ("%lld", &n);
	for (t = n; t > 2; t--)
	{
	    int finish = false;
		for (i = 2; i*i <= t; i ++)
		{
			if (t%i == 0) break;
		}
		if (i*i > t)break;
	}
	printf ("%lld\n", t);
	return 0;
}


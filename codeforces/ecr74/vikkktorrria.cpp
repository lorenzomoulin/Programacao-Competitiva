#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	long long x, y;
	for (int i = 0; i < t; i++)
	{
		cin >> x;
		cin >> y;
		if (x - y == 1)
			cout << "NO" << endl;
		else
		{
			for (int j = 0; j <= x-y; j++)//ищем простое число
			{
				bool pr = true;//по дефолту оно простое
				for (int k = 2; k <= sqrt(j); k++)
				{
					if (j%k == 0)//если на чото делится то нет
						pr = false;
				}
				if (pr == true)
				{
					bool check = false;
					for (int m = 1; m*j < x-y && check==false; m++)
					{
						if ((x - y) % m == 0)
						{
							cout << "YES" << endl;
							goto link;
							check = true;
						}
					}
					if (check == false)
					{
						cout << "NO" << endl;
					}
				}
				
			}
		}
	link:;
	}
	return 0;
}

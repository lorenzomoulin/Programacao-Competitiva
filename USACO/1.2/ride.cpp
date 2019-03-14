/*
ID: lorenzo11
LANG: C++11
TASK: ride
*/
#include <iostream>
#include <fstream>
#include <cstring>
#define MOD 47
using namespace std;

int main(int argc, char const *argv[])
{
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	string a, b;
	fin >> a >> b;
	int ap =1 ,bp = 1;
	for (int i = 0; i < a.size(); i++){
		ap = (ap * (a[i] - 'A' + 1)) % MOD;
	}
	for (int i = 0; i < b.size(); i++){
		bp = (bp * (b[i] - 'A' + 1)) % MOD;
	}
	if (ap == bp)
		fout << "GO\n";
	else
		fout << "STAY\n";
	return 0;
}
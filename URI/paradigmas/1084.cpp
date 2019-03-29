#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define pf pop_front()
#define debug(a) for(int j = 0; j< a.size(); j++)cout<<a[j];cout<<endl;
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true){
		int n, d;
		cin >> n >> d;
		if (!n && !d) break;

		deque<char> seq;
		vector<char> res;
		FOR(i, n){
			char a;
			cin >> a;
			seq.pb(a);
		}
		FOR(i, d){
			if(seq.front() - '0' < seq[1] - '0'){
				seq.pf;
			}	
			else if(seq.front() - '0' > seq[1] - '0'){
				char a;
				a = seq.front();
				seq.pf, seq.pf;
				seq.push_front(a);
			}
			else {
				char a = seq.front();
				seq.pf;
				res.pb(a);
			}
			debug(seq);
			cout << "res\n";
			debug(res);
		}
		cout << "seq\n";
		debug(seq);
		FOR(i, seq.size()){
			res.pb(seq[i]);
		}
		FOR(i, n - d){
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}

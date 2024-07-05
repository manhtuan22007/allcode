#include<bits/stdc++.h>
using namespace std;

#define name ""
#define sz(x) (int)x.size()
#define ll long long
#define int long long


int32_t main()
{
	if(fopen(name".inp" , "r")){
		freopen(name".inp" , "r" , stdin);
		freopen(name".out" , "w" , stdout);
	}
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	int res = 0;
	while(t--){
		int n;
		cin >> n;
		while(n != 1){
			int x = sqrt(n);
			if(x == 1) {
				if(n != 1) ++res;
				break;
			}
			n = x;
			++res;
		}
		cout << res << "\n";
	}
}





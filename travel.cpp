#include<bits/stdc++.h>
using namespace std;

#define name ""
#define sz(x) (int)x.size()
#define ll long long
#define int long long

const int maxn = 2e5 + 10;

int n , c[maxn] , t[maxn] , st[maxn << 2] , lazy[maxn << 2];

void build(int id , int l , int r){
	if(l == r){
		st[id] = t[l] - c[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	st[id] = min(st[id * 2] , st[id * 2 + 1]);
}

void down(int id){
	int t = lazy[id];
	st[id * 2] += t , st[id * 2 + 1] += t;
	lazy[id * 2] += t , lazy[id * 2 + 1] += t;
	lazy[id] = 0;
}

void update(int id , int l , int r , int u , int v , int val){
	if(l > v || r < u) return;
	if(u <= l && r <= v){
		st[id] += val;
		lazy[id] += val;
		return;
	}
	int mid = (l + r) / 2;
	down(id);
	update(id * 2 , l , mid , u , v , val);
	update(id * 2 + 1 , mid + 1 , r , u , v , val);
	st[id] = min(st[id * 2] , st[id * 2 + 1]);
}

int get(int id , int l , int r , int u , int v){
	if(l > v || r < u) return 1e18;
	if(u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	down(id);
	return min(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
}
int32_t main()
{
	if(fopen(name".inp" , "r")){
		freopen(name".inp" , "r" , stdin);
		freopen(name".out" , "w" , stdout);
	}
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> c[i] >> t[i];
		c[i] += c[i - 1];
		t[i] += t[i - 1];
	}
	build(1 , 1 , n);
	int cost = 0;
	for(int i = 1 ; i <= n ; i ++){
		update(1 , 1 , n , i , n , c[i - 1] - t[i - 1]);
		if(get(1 , 1 , n , i , n) >= 0){
			if(t[n] - c[n] - t[i - 1] + c[i - 1] + cost >= 0){
				return cout << i , 0;
			}
		}
		update(1 , 1 , n , i , n , t[i - 1] - c[i - 1]);
		if(t[i] - c[i] < 0) cost += t[i] - c[i];
	}
	cout << -1;
}





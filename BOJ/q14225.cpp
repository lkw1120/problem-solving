#include<bits/stdc++.h>
#define MAX 2000001
using namespace std;
bool check[MAX] = {false};
vector<int> v;
int N,S,ans;
void solve(int n, int sum) {
	check[sum] = true;
	if (n == N) return ;
	solve(n+1, sum);
	solve(n+1, sum+v[n]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>S;
		v.push_back(S);
	}
	solve(0,0);
	for(int i=1;i<MAX;i++) {
		if(!check[i]) {
			ans = i;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
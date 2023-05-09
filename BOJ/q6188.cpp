#include<bits/stdc++.h>
using namespace std;
int arr[100000] = {0};
int N,C,E,B1,B2,ans;
void solve(int n) {
	queue<pair<int,int>> q;
	q.push({arr[n],1});
	while(!q.empty()) {
		int p = q.front().first;
		int d = q.front().second;
		q.pop();
		if(p == 0) {
			ans = d;
			break;
		}
		else {
			q.push({arr[p],d+1});
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>C;
	for(int i=0;i<C;i++) {
		cin>>E>>B1>>B2;
		arr[B1] = arr[B2] = E;
	}
	for(int i=1;i<=N;i++) {
		solve(i);
		cout<<ans<<"\n";
	}
	return 0;
}
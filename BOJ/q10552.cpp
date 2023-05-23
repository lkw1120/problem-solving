#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int ch[MAX] = {0};
bool visited[MAX] = {false};
int N,M,P,A,B,ans;
void solve(int n) {
	if(visited[n]) {
		ans = -1;
		return ;
	}
	if(ch[n]) {
		ans++;
		visited[n] = true;
		solve(ch[n]);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>P;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		if(!ch[B]) ch[B] = A;
	}
	solve(P);
	cout<<ans<<"\n";
	return 0;
}
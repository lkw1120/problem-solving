#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
bool visited[MAX] = {false};
int stone[MAX] = {0};
int N,S,ans;
void jump(int s) {
	visited[s] = true;
	if(s + stone[s] <= N) {
		jump(s + stone[s]);
	}
	if(s - stone[s] > 0) {
		jump(s - stone[s]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>stone[i];
	}
	cin>>S;
	jump(S);
	ans = 0;
	for(int i=1;i<=N;i++) {
		if(visited[i]) ans++;
	}
	cout<<ans<<"\n";
	return 0;	
}
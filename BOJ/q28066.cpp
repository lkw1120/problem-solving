#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++) {
		q.push(i+1);
	}
	while(true) {
		if(q.size() <= K) {
			ans = q.front();
			break;
		}
		else {
			q.push(q.front());
			q.pop();
			for(int i=0;i<K-1;i++) {
				q.pop();
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
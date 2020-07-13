#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin>>M;
			pq.push(-M);
			if(pq.size() > N) {
				pq.pop();
			}
		}
	}
	ans = -pq.top();
	cout<<ans<<"\n";
    return 0;
}
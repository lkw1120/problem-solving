#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int N,X;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	while(N--) {
		cin>>X;
		if(X > 0) {
			pq.push(X);
		}
		else {
			if(pq.empty()) {
				pq.push(0);
			}
			cout<<pq.top()<<"\n";
			pq.pop();
		}
	}
	return 0;
}
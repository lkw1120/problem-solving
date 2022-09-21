#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<>> pq;
int N,X;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>X;
		if(X == 0) {
			if(!pq.empty()) {
				cout<<pq.top()<<"\n";
				pq.pop();
			}
			else {
				cout<<0<<"\n";
			}
		}
		else {
			pq.push(X);
		}
	}
	return 0;	
}
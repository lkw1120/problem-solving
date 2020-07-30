#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq_min;
priority_queue<int,vector<int>,less<int>> pq_max;
int T,M,N,median;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--) {
		cin>>M;
		cout<<M/2+M%2<<"\n";
		median = 0;
		for(int i=1;i<=M;i++) {
			cin>>N;
			if(!median) {
				median = N;
			}
			else {
				if(N < median) {
					pq_max.push(N);
				}
				else {
					pq_min.push(N);	
				}
			}
			if(i%2) { 
				if(pq_min.size() < pq_max.size()) {
					pq_min.push(median);
				}
				else {
					pq_max.push(median);
				}
				if(pq_min.size() < pq_max.size()) {
					median = pq_max.top();
					pq_max.pop();
				}
				else {
					median = pq_min.top();
					pq_min.pop();
				}		
				cout<<median<<" ";
			}
			if(!(i%20)) cout<<"\n";
		}
		cout<<"\n";
		while(!pq_min.empty()) pq_min.pop();
		while(!pq_max.empty()) pq_max.pop();
	}
	return 0;
}
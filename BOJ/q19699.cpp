#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
bool isPrime[MAX] = {false};
vector<int> v,p;
int N,M,H;
void preload() {
	fill(isPrime,isPrime+MAX,true);
	for(int i=2;i<=sqrt(MAX);i++) {
		if(isPrime[i]) {
			for(int j=i+i;j<MAX;j+=i) {
				isPrime[j] = false;	
			}
		}
	}
}
void solve(int sum, int n, int m) {
	if(m == M) {
		if(isPrime[sum]) {
			p.push_back(sum);
			isPrime[sum] = false;
		}
		return ;
	}
	for(int i=n;i<N;i++) {
		solve(sum+v[i],i+1,m+1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>H;
		v.push_back(H);
	}
	solve(0,0,0);
	if(p.empty()) {
		cout<<-1<<"\n";	
	}
	else {
		sort(p.begin(),p.end());
		for(auto item: p) {
			cout<<item<<" ";	
		}
		cout<<"\n";
	}
	return 0;	
}
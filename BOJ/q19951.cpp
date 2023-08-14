#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+2;
int arr[MAX] = {0};
int cache[MAX] = {0};
int N,M,A,B,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	for(int i=1;i<=M;i++) {
		cin>>A>>B>>K;
		cache[A]+=K;
		cache[B+1]-=K;
	}
	int n = 0;
	for(int i=1;i<=N;i++) {
		n+=cache[i];
		cache[i] = n;
	}
	for(int i=1;i<=N;i++) {
		cout<<arr[i]+cache[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
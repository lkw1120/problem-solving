#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5+1;
ll arr[MAX] = {0};
ll L[MAX] = {0};
ll R[MAX] = {0};
ll N,idx,dist;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	for(int i=2;i<=N;i++) {
		cin>>L[i];
		L[i]+=L[i-1];
	}
	for(int i=1;i<N;i++) {
		cin>>R[i];
	}
	for(int i=N-1;i>0;i--) {
		R[i]+=R[i+1];	
	}
	idx = dist = LONG_MAX;
	for(int i=1;i<=N;i++) {
		if(L[i]+arr[i]+R[i] < dist) {
			dist = L[i]+arr[i]+R[i];
			idx = i;
		}
	}
	cout<<idx<<" "<<dist<<"\n";
	return 0;
}
#include<bits/stdc++.h>
#define MAX 1000001
typedef long long ll;
using namespace std;
ll sum[MAX] = {0};
ll T,N;
void preload() {
	for(int i=1;i<MAX;i++) {
		for(int j=1;j*i<MAX;j++) {
			sum[i*j]+=i;
		}
		sum[i]+=sum[i-1];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<sum[N]<<"\n";
	}
	return 0;	
}
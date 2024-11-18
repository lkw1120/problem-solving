#include<bits/stdc++.h>
using namespace std;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<=N;i++) {
		for(int j=i;j<=N;j++) {
			for(int k=j;k<=N;k++) {
				if(i*i+j*j == k*k) ans++;
			}
		}
	}
	ans+=(M-2)*(N+1);
	cout<<ans<<"\n";
    return 0;
}
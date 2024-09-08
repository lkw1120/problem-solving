#include<bits/stdc++.h>
using namespace std;
int arr[1002];
int N,M,S,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>S;
        arr[S] = 1;
    }
    ans = INT_MAX;
    for(int i=1;i<=1000;i++) {
		if(arr[i] == 1) {
		    continue;
		}
		for(int j=i;j<=1000;j++) {
			if(arr[j] == 1) {
			    continue;
			}
			for(int k=j;k<=1001;k++) {
				if(arr[k] == 1) {
				    continue;
				}
				ans = min(ans,abs(N-i*j*k));
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
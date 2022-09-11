#include<bits/stdc++.h>
#define MAX 5001
using namespace std;
int arr[MAX] = {0};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	ans = 0;
	for(int i=2;i<=N;i++) {
		M = arr[i]-arr[1];
		bool flag = false;
		for(int j=2;j<=N;j++) {
			if(arr[j] != 0) {
				if(arr[j]%M == 1) {
					flag = true;
					arr[j] = 0;
				}
			}
		}
		if(flag) ans++;
	}
	cout<<ans<<"\n";
	return 0;	
}
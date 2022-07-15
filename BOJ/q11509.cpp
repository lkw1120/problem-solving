#include<bits/stdc++.h>
#define MAX 1000002
using namespace std;
int arr[MAX] = {0};
int N,H,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	ans = 0;
	for(int i=0;i<N;i++) {
		cin>>H;
		if(arr[H+1] == 0) {
			ans++;
		}
		else {
			arr[H+1]--;
		}
		arr[H]++;
	}
	cout<<ans<<"\n";
	return 0;
}
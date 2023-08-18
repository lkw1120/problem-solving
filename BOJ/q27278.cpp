#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5+1;
int arr[MAX] = {0};
int N,M,P,R,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	ans = 0;
	for(int i=0;i<M;i++) {
		cin>>P>>R>>C;
		int x = C/arr[N];
		int y = C%arr[N];
		if(arr[P-1] < y) x++;
		if(P < R) {
			ans = max(ans,x*arr[N]+arr[R-1]);
		}
		else {
			ans = max(ans,x*arr[N]+arr[P-1]+arr[N]-(arr[P-1]-arr[R-1]));
		}
	}
	cout<<ans<<"\n";
	return 0;
}
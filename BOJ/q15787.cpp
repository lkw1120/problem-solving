#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
set<int> st;
int N,M,A,B,X,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		cin>>A>>B;
		if(A < 3) {
			cin>>X;	
		}
		switch(A) {
			case 1:
				arr[B]|=(1<<(X-1));
				break;
			case 2:
				arr[B]&=~(1<<(X-1));
				break;
			case 3:
				arr[B]<<=1;
				arr[B]&=((1<<20)-1);
				break;
			case 4:
				arr[B]>>=1;
				break;
			default:
				break;
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		if(st.count(arr[i]) == 0) {
			st.insert(arr[i]);
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
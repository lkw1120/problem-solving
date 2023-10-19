#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e9+1;
const int MIN = -(1e9+1);
int arr[11];
int N,A,B,C,D;
int mmax,mmin;
void dfs(int a, int b, int c, int d, int sum, int idx) {
    if (idx == N) {
		mmax = max(mmax,sum);
		mmin = min(mmin,sum);
		return ;
    }
    if(a < A) {
		dfs(a+1,b,c,d,sum+arr[idx],idx+1);
	}
    if(b < B) {
		dfs(a,b+1,c,d,sum-arr[idx],idx+1);
	}
    if(c < C) {
		dfs(a,b,c+1,d,sum*arr[idx],idx+1);
	}
	if(d < D) {
		dfs(a,b,c,d+1,sum/arr[idx],idx+1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr[i];	
	}
	cin>>A>>B>>C>>D;
	mmax = MIN;
	mmin = MAX;
	dfs(0,0,0,0,arr[0],1);
	cout<<mmax<<"\n";
	cout<<mmin<<"\n";
    return 0;
}

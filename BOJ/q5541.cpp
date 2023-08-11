#include<bits/stdc++.h>
using namespace std;
int arr[5003][5003] = {0};
int N,M,A,B,X,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B>>X;
		arr[A][B]++;
		arr[A][B+1]--;
		arr[A+X+1][B]--;
		arr[A+X+2][B+1]++;
		arr[A+X+1][B+X+2]++;
		arr[A+X+2][B+X+2]--;
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			arr[i][j]+=arr[i-1][j];	
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			arr[i][j]+=arr[i][j-1];	
		}
	}
    for(int k=1;k<N;k++) {
        for(int i=1,j=N-k+1;j<=N;i++,j++) {
            arr[i][j]+=arr[i-1][j-1];
        }
    }
    for(int k=1;k<N;k++) {
        for(int i=k,j=1;i<=N;i++,j++) {
            arr[i][j]+=arr[i-1][j-1];
        }
    }
	ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=i;j++) {
			if(arr[i][j]) ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
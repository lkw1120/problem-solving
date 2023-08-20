#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int dp[MAX][6] = {0};
int N,A,B,cnt,grade;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
        cin>>A>>B;
        dp[i][A] = dp[i-1][A]+1;
        if(A != B) {
            dp[i][B] = dp[i-1][B]+1;
        }
    }
	cnt = grade = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=5;j++) {
			if(cnt < dp[i][j]) {
				cnt = dp[i][j];
				grade = j;
			}
		}
	}
    cout<<cnt<<" "<<grade<<"\n";
	return 0;
}
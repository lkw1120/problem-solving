#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
string str,bomb,ans;
char stk[MAX] = {};
int N,M,P;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>str>>bomb;
	N = str.size();
	M = bomb.size();
	P = 0;
	for(int i=0;i<N;i++) {
		stk[P++] = str[i];
		if(bomb[M-1] == str[i]) {
			bool check = true;
			for(int j=0;j<M;j++) {
				if(bomb[M-j-1]!=stk[P-j-1]) {
					check = false;
					break;
				}
			}
			if(check) P-=M;
		}
	}
	if(P == 0) {
		ans = "FRULA";
	}
	else {
		for(int i=0;i<P;i++) {
			ans+=stk[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
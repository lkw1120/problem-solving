#include<bits/stdc++.h>
using namespace std;
int check[26] = {0};
string A,B;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>A>>B;
	ans = 0;
	if(A.size() == B.size()) {
		for(int i=0;i<A.size();i++) {
			check[A[i]-'A']++;
			check[B[i]-'A']--;
		}
		for(int i=0;i<26;i++) {
			if(check[i] != 0) ans = -1;	
		}
		if(ans == 0) {
			int a,b;
			a = b = A.size()-1;
			while(a >= 0 && b >= 0) {
				if(A[a] == B[b]) {
					a--; b--;	
				}
				else {
					a--;
					ans++;
				}
			}
		}
	}
	else {
		ans = -1;
	}
	cout<<ans<<"\n";
	return 0;
}
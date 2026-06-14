#include<bits/stdc++.h>
using namespace std;
int A,B,C,X,Y,Z,ans;
int main () {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B>>C;
	X = A;
	Y = B;
	Z = C;
	ans = 0;
	while(true) {
		if(A%2 || B%2 || C%2) {
			break;
		}
		if(0 < ans && X == A && Y == B && Z == C) {
			ans = -1;
			break;
		}
		int a,b,c;
		a = A/2, b = B/2, c = C/2;
		A = b+c, B = a+c, C = a+b;
		ans++;
	}
	cout<<ans<<"\n";
    return 0; 
}
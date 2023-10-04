#include<bits/stdc++.h>
using namespace std;
int N,R1,R2,C1,C2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>R1>>C1>>R2>>C2;
	int len,r,c;
	len = 2*N-1;
	r = R1;
	for(int i=0;i<R2-R1+1;i++) {
		c = C1;
		for(int j=0;j<C2-C1+1;j++) {
			int x = r%len;
			int y = c%len;
			int dist = abs((N-1)-x)+abs((N-1)-y);
			if(dist < N) {
				cout<<(char)('a'+(dist%26));
			}
			else {
				cout<<".";
			}
			c++;
		}
		cout<<"\n";
		r++;
	}
	return 0;
}
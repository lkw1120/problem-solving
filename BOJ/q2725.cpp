#include<bits/stdc++.h>
using namespace std;
int res[1001];
int C,N;
int gcd(int a, int b) {
    int t;
	while(b) {
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}
void preload() {
	res[1] = 3;
	for(int i=2;i<=1000;i++) {
		int cnt = 0;
		for(int j=1;j<i;j++) {
			if(gcd(i,j) == 1)
				cnt++;
		}
		res[i] = res[i-1] + 2*cnt;
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    preload();
    cin>>C;
    while(C--) {
        cin>>N;
        cout<<res[N]<<"\n";
    }
    return 0;
}
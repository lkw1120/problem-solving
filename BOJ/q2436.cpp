#include<bits/stdc++.h>
using namespace std;
int A,B,X;
int gcd(int a, int b) {
	int c;
    while(b!=0){
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>A>>B;
    B/=A;
    for(int i=1;i*i<=B;i++) {
        if(B%i == 0 && gcd(i,B/i) == 1) {
            X = i;
        }
    }
    cout<<A*X<<" "<<A*(B/X)<<"\n";
    return 0;
}
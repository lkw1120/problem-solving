#include<bits/stdc++.h>
using namespace std;
int N,M,P,ans;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>P;
    int x1,x2,x3,y1,y2,y3;
    x1 = 0, y1 = 0;
    x2 = N, y2 = M;
    x3 = P, y3 = 0;
    double area = abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))*1/2.0;
    int cnt = 0;
    cnt+=gcd(abs(x2-x1),abs(y2-y1));
    cnt+=gcd(abs(x3-x2),abs(y3-y2));
    cnt+=gcd(abs(x1-x3),abs(y1-y3));
    ans = area-cnt/2.0+1;
    cout<<ans<<"\n";
    return 0;
}
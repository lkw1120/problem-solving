#include<bits/stdc++.h>
using namespace std;
long long power(int a, int b, int c) {
    if(b == 1) return a;
    else {
        long long tmp = power(a,b/2,c);
        if(b%2) 
            return ((tmp*tmp)%c*a)%c;
        else
            return (tmp*tmp)%c;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    long long ans;
    int A,B,C;
    cin>>A>>B>>C;
    ans = power(A%C,B,C);
    cout<<ans<<"\n";
    return 0;
}
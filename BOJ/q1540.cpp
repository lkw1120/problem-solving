#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int n,m;
    n = sqrt(N);
    ans = (n-1)*n*(2*n-1)/6;
    m = N-n*n;
    int tmp = 0;
    for(int i=m;i>0;i--) {
        ans+=tmp;
        tmp = (tmp+1)%n;
    }
    cout<<ans<<"\n";
    return 0;
}
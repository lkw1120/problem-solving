#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v1.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v1[i];
    }
    cin>>M;
    v2.resize(M);
    for(int i=0;i<M;i++) {
        cin>>v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int n,m;
    ans = n = m = 0;
    while(n < N && m < M) {
        if(v1[n] <= v2[m]) {
            ans++;
            n++;
            m++;
        }
        else {
            m++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
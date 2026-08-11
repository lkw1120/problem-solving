#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
vector<bool> check;
int N,M,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    v.resize(N);
    check.resize(N,true);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        A--;
        B--;
        if(v[A] <= v[B]) {
            check[A] = false;
        }
        if(v[B] <= v[A]) {
            check[B] = false;
        }
    }
    for(int i=0;i<N;i++) {
        if(check[i]) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> h;
ll N,H;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>H;
        h.push_back(H);
    }
    ll tmp = 0;
    bool flag = true;
    for(int i=0;i<N;i++) {
        if(h[i]-1 >= tmp) {
            h[i]--;
        } 
        else if(h[i] < tmp) {
            flag = false;
            break;
        }
        tmp = h[i];
    }
    if(flag) {
        cout<<"Yes"<<"\n";
    }
    else {
        cout<<"No"<<"\n";
    }
    return 0;
}
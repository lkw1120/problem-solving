#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v,vv;
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=2;i<=sqrt(N);i++) {
        while(N%i == 0) {
            N/=i;
            v.push_back(i);
        }
    }
    if(1 < N) v.push_back(N);
    int size = v.size();
    if(size == 1) {
        cout<<-1<<"\n";
    }
    else {
        for(int i=0;i<size;i+=2) {
            if(i == size-1) {
                vv.back()*=v[i];
            }
            else {
                vv.push_back(v[i]*v[i+1]);
            }
        }
        for(auto item: vv) {
            cout<<item<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
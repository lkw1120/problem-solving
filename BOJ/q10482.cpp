#include<bits/stdc++.h>
using namespace std;
bool isPrime[32001];
vector<pair<int,int>> v;
int N,X,ans;
void prime() {
    fill(isPrime,isPrime+32001,true);
    isPrime[2] = true;
    for(int i=2;i*i<32001;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j<32001;j++) {
                isPrime[i*j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prime();
    cin>>N;
    while(N--) {
        v.clear();
        cin>>X;
        for(int i=2;i<=X/2;i++) {
            if(isPrime[i] && isPrime[X-i]) {
                v.push_back({i,X-i});
            }
        }
        int size = v.size();
        cout<<X<<" has "<<size<<" representation(s)"<<"\n";
        for(auto [a,b]:v) {
            cout<<a<<"+"<<b<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
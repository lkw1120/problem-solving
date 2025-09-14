#include<bits/stdc++.h>
using namespace std;
vector<int> v,vv;
int A,B,N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    N = B-A+1;
    v.resize(N);
    for(int i=1;i<=B;i++) {
        int tmp = (A+i-1)/i*i;
        if(B < tmp) continue;
        for(int j=tmp;j<=B;j+=i) {
            v[j-A]++;
        }
    }
    M = 0;
    for(auto item: v) { 
        M = max(M,item);
    }
    for(int i=0;i<N;i++) {
        if(v[i] == M) {
            vv.push_back(A+i);
        }
    }
    int size = vv.size();
    cout<<M<<" "<<size<<"\n";
    for(auto item: vv) {
        cout<<item<<"\n";
    }
    return 0;
}
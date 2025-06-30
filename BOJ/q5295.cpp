#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    if(3 <= N) {
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int size = v.size();
        for(int i=0;i<size;i++) {
            for(int j=i+1;j<size;j++) {
                ll a,b;
                a = v[j]-v[i];
                b = v[j]+a;
                if(binary_search(v.begin(),v.end(),b)) {
                    cout<<"Sequence is not 3-free. Witness: ";
                    cout<<v[i]<<","<<v[j]<<","<<b<<"."<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"Sequence is 3-free."<<"\n";
    return 0;
}
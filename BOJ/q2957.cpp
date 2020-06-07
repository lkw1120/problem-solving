#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> mp;
map<int,int>::iterator lower;
map<int,int>::iterator upper;
int N,n;
ll C, depth;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    mp.insert({0,-1});
    mp.insert({300001,-1});
    cin>>N;
    C = depth = 0;
    for(int i=0;i<N;i++) {
        cin>>n;
        lower = (--mp.lower_bound(n));
        upper = (mp.upper_bound(n));
        depth = max(lower->second,upper->second)+1;
        mp.insert({n,depth});
        C+=depth;
        cout<<C<<"\n";
    }
    return 0;
}
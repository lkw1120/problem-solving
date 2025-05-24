#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<10;i++) {
        v.push_back(i);
    }
    int hello,world;
    hello = world = 0;
    do {
        int h,e,l,o,w,r,d;
        h = v[0];
        e = v[1];
        l = v[2];
        o = v[3];
        w = v[4];
        r = v[5];
        d = v[6];
        if(h == 0 || w == 0) continue;
        hello = h*10000 + e*1000 + l*110 + o;
        world = w*10000 + o*1000 + r*100 + l*10 + d;
        if(hello + world == N) break;
    } while(next_permutation(v.begin(),v.end()));
    if(hello + world == N) {
        cout<<"  "<<hello<<"\n";
        cout<<"+ "<<world<<"\n";
        cout<<"-------"<<"\n";
        cout<<setw(7)<<N<<"\n";
    }
    else {
        cout<<"No Answer"<<"\n";
    }
    return 0;
}
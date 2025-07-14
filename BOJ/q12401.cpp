#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int T,N,S,P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        v.clear();
        cin>>N>>S>>P;
        v.resize(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        int a,b;
        a = b = 0;
        for(auto item: v) {
            int x = (item+2)/3;
            if(P <= x) {
                a++;
            }
            else if(2 <= item && item <= 28) {
                int y = (item+4)/3;
                if(P <= y) {
                    b++;
                }
            }
        }
        ans = a+min(S,b);
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}
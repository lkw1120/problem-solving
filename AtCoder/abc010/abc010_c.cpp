#include<bits/stdc++.h>
using namespace std;
int txa,tya,txb,tyb;
int T,V,n,x,y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>txa>>tya>>txb>>tyb>>T>>V;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x>>y;
        double d1 = sqrt((x-txa)*(x-txa)+(y-tya)*(y-tya));
        double d2 = sqrt((txb-x)*(txb-x)+(tyb-y)*(tyb-y));
        if(d1+d2 <= T*V) {
            cout<<"YES"<<"\n";
            return 0;
        }
    }
    cout<<"NO"<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
string str;
int T,X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>str;
        int l,r,x,y;
        l = r = x = y = 0;
        X = Y = 0;
        for(int i=0;i<str.size();i++) {
            x = y = str[i]-'0';
            x/=2;
            y-=x;
            if(l < r) {
                X = X*10+y;
                Y = Y*10+x;
                l+=y;
                r+=x;
            }
            else {
                X = X*10+x;
                Y = Y*10+y;
                l+=x;
                r+=y;
            }
        }
        cout<<X<<" "<<Y<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int N;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = "";
    for(int i=0;i<N;i++) {
        int x;
        cin>>x;
        if(x%3 == 0 && x%5 != 0) {
            ans+="F";
        }
        else {
            ans+="B";
        }
    }
    cout<<ans<<"\n";
    return 0;
}
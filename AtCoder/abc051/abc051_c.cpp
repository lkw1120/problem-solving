#include<bits/stdc++.h>
using namespace std;
int A,B,C,D;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>C>>D;
    ans = "";
    for(int i=0;i<D-B;i++) {
        ans+='U';
    }
    for(int i=0;i<C-A;i++) {
        ans+='R';
    }
    for(int i=0;i<D-B;i++) {
        ans+='D';
    }
    for(int i=0;i<C-A;i++) {
        ans+='L';	
    }
    ans+='L';
    for(int i=0;i<D+1-B;i++) {
        ans+='U';	
    }
    for(int i=0;i<C-(A-1);i++) {
        ans+='R';
    }
    ans+='D';
    ans+='R';
    for(int i=0;i<D-(B-1);i++) {
        ans+='D';
    }
    for(int i=0;i<(C+1)-A;i++) {
        ans+='L';
    }
    ans+='U';
    cout<<ans<<"\n";
    return 0;
}
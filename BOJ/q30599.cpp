#include<bits/stdc++.h>
using namespace std;
string str;
int d;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>d;
    str = to_string(d);
    for(int i=0;i<d;i++) {
        cout<<str;
    }
    cout<<"\n";
    return 0;
}
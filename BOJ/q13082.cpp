#include<bits/stdc++.h>
using namespace std;
string S,T;
bool check(string s) {
    int size = s.size();
    int t = 0;
    for(char ch: T) {
        if(t < size && ch == s[t]) {
            t++;
        }
    }
    return t == size;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S>>T;
    string even,odd;
    int size = S.size();
    for(int i=0;i<size;i++) {
        if(i % 2 == 0) {
            even+=S[i];
        }
        else {
            odd+=S[i];
        }
    }
    if(check(even) || check(odd)) {
        cout<<"Yes"<<"\n";
    }
    else {
        cout<<"No"<<"\n";
    }
    return 0;
}
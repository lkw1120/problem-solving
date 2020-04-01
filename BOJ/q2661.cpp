#include<bits/stdc++.h>
using namespace std;
string str;
int N;
bool check(int len, int sub) {
    while(sub*2 <= len) {
        if(str.substr(len-sub,sub) == str.substr(len-(sub*2),sub)) {
            return false;
        }
        sub++;
    }
    return true;
}
void go() {
    if(str.size() == N) {
        cout<<str<<"\n";
        exit(0);
    }
    for(int n=1;n<=3;n++) {
        str.push_back(n+'0');
        if(check(str.size(),1)) {
            go();
        }
        str.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    go();
    return 0;
}
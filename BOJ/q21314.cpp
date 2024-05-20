#include<bits/stdc++.h>
using namespace std;
string str,mx,mn;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    int size = str.size();
    queue<char> q1,q2;
    for(int i=0;i<size;i++) {
        if(str[i] == 'M') {
            q1.push('M');
            q2.push('M');
        }
        else {
            mx+='5';
            while(!q1.empty()) {
                mx+='0';
                q1.pop();
            }
            if(!q2.empty()) {
                q2.pop();
                mn+='1';
                while(!q2.empty()) {
                    mn+='0';
                    q2.pop();
                }
            }
            mn+='5';
        }
    }
    if(!q1.empty()) {
        while(!q1.empty()) {
            mx+='1';
            q1.pop();
        }
    }
    if(!q2.empty()) {
        mn+='1';
        q2.pop();
        while(!q2.empty()) {
            mn+='0';
            q2.pop();
        }
    }
    cout<<mx<<"\n";
    cout<<mn<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
map<string,bool> mp;
string str1,str2;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    str1 = "12348765";
    str2 = "";
    for(int i=0;i<8;i++) {
        char ch;
        cin>>ch;
        str2+=ch;
    }
    reverse(str2.begin()+4,str2.end());
    queue<pair<string,int>> q;
    q.push({str1,0});
    mp[str1] = true;
    while(!q.empty()) {
        str1 = q.front().first;
        int t = q.front().second;
        q.pop();
        bool flag = true;
        for(int i=0;i<8;i++) {
            flag = (str1[i] == str2[i] && flag);
        }
        if(flag) {
            ans = t;
            break;
        }
        else {
            // A
            string tmp = str1.substr(4,4)+str1.substr(0,4);
            if(!mp[tmp]) {
                mp[tmp] = true;
                q.push({tmp,t+1});
            }
            // B
            tmp = str1.substr(3,1) + str1.substr(0,3) + str1.substr(7,1) + str1.substr(4,3);
            if(!mp[tmp]) {
                mp[tmp] = true;
                q.push({tmp,t+1});
            }
            // C
            tmp = str1;
            swap(tmp[1],tmp[2]);
            swap(tmp[2],tmp[6]);
            swap(tmp[5],tmp[6]);
            if(!mp[tmp]) {
                mp[tmp] = true;
                q.push({tmp,t+1});
            }
            // D
            tmp = str1;
            swap(tmp[0],tmp[7]);
            if(!mp[tmp]) {
                mp[tmp] = true;
                q.push({tmp,t+1});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
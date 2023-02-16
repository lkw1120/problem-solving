#include<bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        string url,protocol,host,port,path;
        cin>>url;
        int idx;
        idx = url.find("://");
        protocol = url.substr(0,idx);
        url = url.substr(idx+3);
        if((idx = url.find("/")) != string::npos) {
            path = url.substr(idx+1);
            url = url.substr(0,idx);
        }
        else {
            path = "<default>";
        }
        if((idx = url.find(":")) != string::npos) {
            port = url.substr(idx+1);
            url = url.substr(0,idx);
        }
        else {
            port = "<default>";
        }
        host = url;
        cout<<"URL #"<<i<<"\n";
        cout<<"Protocol = "<<protocol<<"\n";
        cout<<"Host     = "<<host<<"\n";
        cout<<"Port     = "<<port<<"\n";
        cout<<"Path     = "<<path<<"\n";
        cout<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int arr[31];
bool abc[26];
vector<string> v;
int N;
vector<string> split(string str, char ch) {
    istringstream iss(str);
    string buf;
    vector<string> res;
    while (getline(iss, buf, ch)) {
        res.push_back(buf);
    }
    return res;
}
bool shortcut(string str, int idx) {
    vector<string> vv = split(str,' ');
    int t = 0;
    for(auto item: vv) {
        int tmp = 0;
        if('a' <= item[0] && item[0] <= 'z') {
            tmp = item[0]-'a';
        }
        else {
            tmp = item[0]-'A';
        }
        if(!abc[tmp]) {
            arr[idx] = t;
            abc[tmp] = true;
            return true;
        }
        t+=item.size()+1;
    }
    int size = str.size();
    for(int i=0;i<size;i++) {
        if(str[i] == ' ') continue;
        int tmp = 0;
        if('a' <= str[i] && str[i] <= 'z') {
            tmp = str[i]-'a';
        }
        else {
            tmp = str[i]-'A';
        }
        if(!abc[tmp]) {
            arr[idx] = i;
            abc[tmp] = true;
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin.ignore();
    v.resize(N);
    for(int i=0;i<N;i++) {
        getline(cin,v[i]);
        if(!shortcut(v[i],i)) {
            arr[i] = -1;
        }
    }
    for(int i=0;i<N;i++) {
        string str = v[i];
        int size = str.size();
        for(int j=0;j<size;j++) {
            if(arr[i] != j) {
                cout<<str[j];
            }
            else {
                cout<<"["<<str[j]<<"]";
            }
        }
        cout<<"\n";
    }
    return 0;
}
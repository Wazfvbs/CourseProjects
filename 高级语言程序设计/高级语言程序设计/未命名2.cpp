#include<bits/stdc++.h>
using namespace std;
bool seven(int n){
    if(n%7==0) return false;
    while(n!=0){
        int m=n%10;
        if(m==7) return false;
        n/=10;
    }
    return true;

}
int main(){
    int n,m,t;
    cin>>n>>m>>t;
    queue <string> a;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        a.push(str);
    }
    for(int i=0;i<m-1;i++){
        str=a.front();
        a.pop();
        a.push(str);
    }
    int r=0;
    while(!a.empty()){
        if(r) a.push(str);
        r=0;
        str=a.front();
        a.pop();
        if(seven(t)){
            r=1;
        }
        t++;
    }
    cout<<str;
    return 0;
}


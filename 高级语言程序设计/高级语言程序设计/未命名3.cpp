#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    int *a=new int(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
    cin>>m;
    for(int i=0;i<m;i++){
    	int k,r=1;
    	cin>>k;
    	for(int j=0;j<n;j++){
    		if(a[j]==k){
    			cout<<j+1<<endl;
    			r=0;
			}
		}
		if(r) cout<<"0"<<endl;
	}
    return 0;
}


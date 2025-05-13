#include<bits/stdc++.h>
using namespace std;
void EX(string &str1,string &str2){
	if(str1.size()<str2.size()){
		string tmp=str1;
		str1=str2;
		str2=tmp;
	}
}
int PP(string str1,string str2,int n){
	int num=0;
	for(int i=n,j=0;j<str2.size();i++,j++){
		if(str1[i]==str2[j]) num++;
	}
	return num;
}
typedef long long LL;
LL gcd(LL a,LL b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	string str1;
	while(cin>>str1){
		string str2;
		cin>>str2;
		cout<<"appx£¨"<<str1<<"£¬"<<str2<<"£© = ";
		EX(str1,str2);
		int maxnum=0;
		for(int i=0;i<=str1.size()-str2.size();i++){
			if(PP(str1,str2,i)>maxnum) maxnum=PP(str1,str2,i);
			
		}
		int sum=str1.size()+str2.size();
		int g=gcd(maxnum*2,sum);
		cout<<maxnum*2/g<<"/"<<sum/g<<endl;
	}
	return 0;
}

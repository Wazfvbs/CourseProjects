#include<bits/stdc++.h>
using namespace std;
class stu{
	public:
		string name;
		int grade;
		stu(){
			name="";
			grade=0;
		}
};
void Sort(stu &a,stu &b){
	stu temp;
		temp=a;
		a=b;
		b=temp;
	
}
int main(){
	int n;
	cin>>n;
	stu a[20];
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].grade;
	}
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j].grade<a[j+1].grade) Sort(a[j],a[j+1]);
		}
	}
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j].grade==a[j+1].grade)
				if(a[j].name>a[j+1].name)
			 Sort(a[j],a[j+1]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i].name<<" "<<a[i].grade<<endl;
	}
	return 0;
}

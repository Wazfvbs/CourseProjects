#include <bits/stdc++.h>
using namespace std; 
typedef struct student {
    int ID;
    int namelen;
    char name[20];
    char gender;
    double grade1;
    double grade2;
    double grade3;
    double avargrade;
    double total;
    //struct student* next;
} Stu;
//Stu* CreateLits(){
//	Stu* newNode;
//	newNode=new Stu;
//	Stu->next=NULL;
//	return newNode
//}

int main()
{
    FILE *fp;
    int n,i,j;
    cin>>n;
    double avargrade = 0;
    Stu *stu=(Stu*)malloc(n*sizeof(Stu));
    for(i=0;i<n;i++){
    	scanf("%d %d",&stu[i].ID,&stu[i].namelen);
    	getchar();
    	for(j=0;j<stu[i].namelen;j++) scanf("%c",&stu[i].name[j]);
    	getchar();
        scanf("%c %lf %lf %lf",&(stu[i].gender), &(stu[i].grade1), &(stu[i].grade2), &(stu[i].grade3));
        stu[i].total=(stu[i].grade1+stu[i].grade2+stu[i].grade3);
		stu[i].avargrade = (stu[i].grade1+stu[i].grade2+stu[i].grade3)/3.0;
    fp=fopen("student.txt", "a");
    fprintf(fp, "%d %d %s %c %.2lf %.2lf %.2lf %.2lf %.2lf\n", stu[i].ID, stu[i].namelen, stu[i].name, stu[i].gender,
    stu[i].grade1, stu[i].grade2, stu[i].grade3, stu[i].total, stu[i].avargrade);
    
    fclose(fp);
    }
    return 0;
}

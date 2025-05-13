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
    struct student* next;
} Stu;
Stu* CreateList(){
	Stu* newNode;
	newNode=new Stu;
	newNode->next=NULL;
	return newNode;
}
Stu* CreateNode(){
	Stu* newNode;
	newNode=new Stu;
	newNode->next=NULL;
	newNode->ID=0;
	newNode->namelen=0;
	newNode->grade1=0;
	newNode->grade2=0;
	newNode->grade3=0;
	newNode->avargrade=0;
	newNode->total=0;
	return newNode;
}

Stu* Sort(Stu *head){
    Stu *p;
    Stu *q;
    for(p=head->next;p->next;p=p->next)
        for(q=p->next;q;q=q->next)
            if(q->total>p->total)
        {
            Stu *p_next=p->next;
            Stu *q_next=q->next;
            Stu t=*p;
            *p=*q;
            *q=t;
            p->next=p_next;
            q->next=q_next;
        }
    return head;
}
int main()
{
    FILE *fp;
    int n,i,j;
    cin>>n;
    double avargrade = 0;
    Stu *List=CreateList();
    Stu *p=List;
    for(i=0;i<n;i++){
    	Stu *Stud=CreateNode();
    	p->next=Stud;
    	p=p->next;
    	scanf("%d %d",&Stud->ID,&Stud->namelen);
    	getchar();
    	for(j=0;j<Stud->namelen;j++) scanf("%c",&Stud->name[j]);
    	getchar();
        scanf("%c %lf %lf %lf",&(Stud->gender), &(Stud->grade1), &(Stud->grade2), &(Stud->grade3));
        Stud->total=(Stud->grade1+Stud->grade2+Stud->grade3);
		Stud->avargrade = (Stud->grade1+Stud->grade2+Stud->grade3)/3.0;
	}
	Sort(List);
	for(p=List->next;p->next;p=p->next){
	fp=fopen("Student1.bat", "ab+");
    fprintf(fp, "%d %d %s %c %.2lf %.2lf %.2lf %.2lf %.2lf\n", p->ID, p->namelen, p->name, p->gender,
    p->grade1, p->grade2, p->grade3, p->total, p->avargrade);
    fclose(fp);
    }
    return 0;
}

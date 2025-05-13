#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_NUM 32767
using namespace std; 

typedef char **HuffmanCode;

typedef struct{
    int weight;
    int parent, lchild, rchild;
}HTNode, *HuffmanTree;  

typedef struct{
    HuffmanTree HT;
    char *c;
    int length;
    HuffmanCode HC;
}Huffman;


void Select(HuffmanTree HT,int end,int *s1,int *s2){
    int i;
    int min1=MAX_NUM;
    int min2=MAX_NUM;
    for (i=1;i<=end;i++)
    {
        if (HT[i].parent==0&&HT[i].weight<min1)
        {
            *s1=i;
            min1=HT[i].weight;
        }
    }
    for(i=1;i<=end;i++)
    {
        if(HT[i].parent==0&&(*s1!=i)&&min2>HT[i].weight)
        {
            *s2=i;
            min2=HT[i].weight;
        }
    }
}

Huffman HuffmanCoding(Huffman Hfm){
    int i, n, m, s1, s2, start;
    int c, f;
    char *cd;
    n = Hfm.length;
    if (n <= 1)  return Hfm;
    m = 2*n-1;
    for(i = n+1; i <= m; ++i) {
        Select(Hfm.HT, i-1, &s1, &s2);
        Hfm.HT[s1].parent = i;
        Hfm.HT[s2].parent = i;
        Hfm.HT[i].lchild = s1;
        Hfm.HT[i].rchild = s2;
        Hfm.HT[i].weight = Hfm.HT[s1].weight + Hfm.HT[s2].weight;
    }
    Hfm.HC =new char *[n+1];
    cd =new char[n];
    cd[n-1] = '\0';
    for (i = 1; i <= n; ++i) {
        start = n - 1;
        for (c = i, f = Hfm.HT[i].parent; f != 0; c = f, f = Hfm.HT[f].parent) {
            if (c == Hfm.HT[f].lchild) {
                cd[--start] = '0';
            } else cd[--start] = '1';
        }
        Hfm.HC[i] = new char[n-start];
        strcpy(Hfm.HC[i], &cd[start]);
    }
    free(cd);
    return Hfm;
}

Huffman InputHuffman(Huffman Hfm){
    int i, n;
    printf("请输入哈夫曼编码个数：");
    scanf("%d", &n);
    if (n <= 1) {
        printf("无需编码!\n");//若只有一个数值则无需编码
        printf("请重新输入哈夫曼编码个数：");
        scanf("%d",&n);
    }
    
    Hfm.HT = new HTNode[2*n];
    Hfm.c = new char[n+1];
    printf("请输入%d个结点的字符及权值（请用空格进行分隔）\n",n);
    for (i = 1; i <= n; i++) {
        printf("请输入第%d个字符和权值",i);
        getchar();
        scanf("%c %d", &Hfm.c[i], &Hfm.HT[i].weight);
        Hfm.HT[i].parent = 0;
        Hfm.HT[i].lchild = 0;
        Hfm.HT[i].rchild = 0;
    }
    for(; i <= 2*n-1; ++i) {
        Hfm.HT[i].weight = 0;
        Hfm.HT[i].parent = 0;
        Hfm.HT[i].lchild = 0;
        Hfm.HT[i].rchild = 0;
    }
    Hfm.length = n;
    return Hfm;
}

Huffman InitHuffman(Huffman Hfm)
{
    printf("\n    哈夫曼树初始化    \n");
    int n, i;
    char x;
    FILE *fp;
    fp = fopen("hfmtree", "rt");
    if (fp == NULL) {
        Hfm = InputHuffman(Hfm);
        fp = fopen("hfmtree", "wt");
        fprintf(fp, "%d\n", Hfm.length);
        for (i = 1; i <= Hfm.length; i++)
            fprintf(fp, "%c %d  ", Hfm.c[i], Hfm.HT[i].weight);
        rewind(fp);
    } else {
        getchar();
        printf("哈夫曼树已存在！\n是否新建一个哈夫曼树吗(Y/N)? ");
        scanf("%c", &x);
        x=toupper(x);
        if (x == 'Y') {
            Hfm = InputHuffman(Hfm);
            fp = fopen("hfmtree", "w+");
            fprintf(fp, "%d\n", Hfm.length);
            for (i = 1; i <= Hfm.length; i++)
                fprintf(fp, "%c %d  ", Hfm.c[i], Hfm.HT[i].weight);
            rewind(fp);
        } else {
            fscanf(fp, "%d\n", &n);
            Hfm.HT = new HTNode[2*n];
    		Hfm.c = new char[n+1];
			for (i = 1; i <= n; i++)
                fscanf(fp, "%s %d  ", &Hfm.c[i], &Hfm.HT[i].weight);
            for (i = 1; i <= n; i++) {
                Hfm.HT[i].parent = 0;
                Hfm.HT[i].lchild = 0;
                Hfm.HT[i].rchild = 0;
            }
            for(; i <= 2*n-1; ++i) {
                Hfm.HT[i].weight = 0;
                Hfm.HT[i].parent = 0;
                Hfm.HT[i].lchild = 0;
                Hfm.HT[i].rchild = 0;
            }
            Hfm.length = n;
        }
    }
    fclose(fp);
    printf("哈夫曼树的初始化已完成!\n\n");
    Hfm = HuffmanCoding(Hfm);
    return Hfm;
}

void Encoding(Huffman Hfm)
{
    int i = 0, j = 0, n, k = 0;
    char ch[60];
    FILE *fp, *fw;
    n = Hfm.length;
    printf("\n    哈夫曼编码    \n");
    
    do {
        printf("1. 对ToBeTran文件进行编码\n");
        printf("2. 对输入的字符串进行编码\n");
        printf("请选择编码方式： ");
        scanf("%d", &k);
        printf("\n");
        if (k == 1) {
            if ((fw = fopen("tobetrans", "r+")) == NULL) {
                printf("ToBeTran不存在!\n");
            } else {
                printf("已读取ToBeTran文件\n");
                printf("哈夫曼编码: ");
                fscanf(fw, "%s", ch);
                fclose(fw);
                fp = fopen("codefile", "wt+");
                k = 0;
            }
        } else if (k == 2) {
            printf("请输入要编码的字符串: ");
            scanf("%s", ch);
            printf("哈夫曼编码: ");
            fp = fopen("codefile", "wt+");
            k = 0;
        }
        if (k == 0) {   //跳出do循环
            break;
        }
    } while (k != 1 || k != 2);
    
    while(ch[j]) {
        for (i = 1; i <= n; i++) {
            if (ch[j] == Hfm.c[i]) {
                printf("%s", Hfm.HC[i]);
                fprintf(fp, "%s", Hfm.HC[i]);
                break;
            }
        }
        j++;
    }
    printf("\n已将编码存入CodeFile\n");
    rewind(fp);
    fclose(fp);
    
}

void Decoding(Huffman Hfm)
{
    HuffmanTree p;
    int i, n;
    int j = 0;
    char d[500];
    FILE *fp;
    n = Hfm.length;
    printf("\n    哈夫曼译码    \n");
    if((fp = fopen("codefile", "r+")) == NULL) {
        printf("请输入哈夫曼编码:");
        scanf("%s",d);
    } else {
        fscanf(fp, "%s", d);
        fclose(fp);
    }
    printf("经译码后CodeFile的内容是: ");
    fp = fopen("TextFile","wt+");
    while (d[j]) {
        p = &Hfm.HT[2*n-1];
        while (p->lchild || p->rchild) {
            if (d[j] == '0') {
                i = p->lchild;
                p = &Hfm.HT[i];
            } else {
                i = p->rchild;
                p = &Hfm.HT[i];
            }
            j++;
        }
        printf("%c", Hfm.c[i]);
        fprintf(fp,"%c", Hfm.c[i]);
    }
    printf("\n");
    fclose(fp);
}


void Print(Huffman Hfm)
{
    int i, n;
    int m = 1;
    char ch;
    FILE *fprint;
    n = Hfm.length;
    printf("\n    打印代码文件    \n");
    
    printf("CodeFile代码: \n");
    
    fprint = fopen("codefile", "rb");
    while (!feof(fprint)) {
        ch = fgetc(fprint);
        printf("%c", ch);
        m++;
        if (m % 50 == 0)
            printf("\n");
    }
    fclose(fprint);
    
    printf("\n编码文件: \n");
    printf("字符\t\t权值\t\t编码\n");
    for (i = 1; i <= n; i++) {
        printf("%c\t\t", Hfm.c[i]);
        printf("%d\t\t", Hfm.HT[i].weight);
        printf("");
        puts(Hfm.HC[i]);
    }
    
    printf("\n");
    
}

int numb = 0;
void coprint(HuffmanTree start, HuffmanTree HT)
{//打印哈夫曼树
    char t = ' ';
    if (start != HT) {
        FILE *TreePrint;
        if ((TreePrint = fopen("TreePrint", "a")) == NULL) {
            printf("创建文件失败\n");
            return;
        }
        numb++;
        coprint(HT+start->rchild, HT);
        if (start->lchild != 0 && start->rchild != 0) {
            t = '<';
        }
        cout << setw(5*numb) << start->weight << t << endl;
        fprintf(TreePrint, "%d\n", start->weight);
        coprint(HT+start->lchild, HT);
        numb--;
        fclose(TreePrint);
    }
    
}

void Print_Tree(HuffmanTree HT, int w)
{
    HuffmanTree p;
    p = HT + w;
    printf("打印哈夫曼树: \n");
    coprint(p, HT);
    printf("打印完成！\n\n");
}



int main()
{
    Huffman Hfm;
    char k;
    printf("                           2.哈夫曼编/译码器\n");
    while(1) {
        printf("I. 初始化\n");
        printf("E. 编码\n");
        printf("D. 译码\n");
        printf("P. 打印代码文件\n");
        printf("T. 打印哈夫曼树\n");
        printf("J. 结束\n");
        printf("请输入命令: ");
        scanf("%c",&k);
        k=toupper(k);
        switch(k) {
            case 'I':
                Hfm=InitHuffman(Hfm);
                getchar();
                break;
            case 'E':
                Encoding(Hfm);
                getchar();
                break;
            case 'D':
                Decoding(Hfm);
                getchar();
                break;
            case 'P':
                Print(Hfm);
                getchar();
                break;
            case 'T':
                Print_Tree(Hfm.HT, 2*Hfm.length-1);
                getchar();
                break;
            case 'J':
                exit(0);
            default:
            printf("错误！请重新输入命令！\n"); }
    }
}

#include <iostream>
#include <string.h>
using namespace std;
 
const int N=36;
long long c[N];
 
void Catalan()
{
    memset(c,0,sizeof(c));
    c[0]=c[1]=1;
    for(int i=2;i<=35;i++)
        for(int j=0;j<i;j++)
    {
        c[i]+=c[j]*c[i-j-1];
    }
}
 
 
 
int main()
{
    Catalan();
    int n;
    int t=1;
    while(cin>>n&&n!=-1)
    {
        cout<<t++<<" "<<n<<" "<<2*c[n]<<endl;
    }
    return 0;
}

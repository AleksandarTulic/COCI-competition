#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int naj=0;
int koliko=0;
int ele1=1;
int ele2=100;
vector <int> A(101,0),B(101,0);
vector <int> Ap(101,0),Bp(101,0);

int max_suma()
{
    for (int i=ele1;i<=naj;i++)
       if ( Ap[i] != 0 ) {ele1=i;break;}
    for (int i=ele2;i>=1;i--)
       if ( Bp[i] != 0 ) {ele2=i;break;}

    if ( Ap[ele1] > Bp[ele2] ) Ap[ele1]-=Bp[ele2],koliko-=Bp[ele2],Bp[ele2]-=Bp[ele2];
    else Bp[ele2]-=Ap[ele1],koliko-=Ap[ele1],Ap[ele1]-=Ap[ele1];

    return ele1+ele2;
}

int main()
{
    scanf("%d",&n);

    for (int ispis=1;ispis<=n;ispis++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        A[a]++;
        B[b]++;

        naj=max(naj,max(a,b));

        int suma=-10;
        koliko=ispis;
        ele2=naj;
        ele1=1;

        for (int i=1;i<=naj;i++) Ap[i]=A[i],Bp[i]=B[i];

        while (koliko) { suma=max(suma,max_suma()); }

        printf("%d\n",suma);
    }
    return 0;
}

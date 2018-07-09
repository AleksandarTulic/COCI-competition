#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c;

    char e[3];

    cin>>a>>b>>c;

    for (int i=0;i<3;i++) cin>>e[i];

    int minn,maxx,srednji;

    minn=min(a,min(b,c));
    maxx=max(a,max(b,c));

    if (minn==a)
    {
        if (maxx==b) srednji=c;
        else srednji=b;
    }
    else if (minn==b)
    {
        if (maxx==a) srednji=c;
        else srednji=a;
    }
    else if (minn==c)
    {
        if (maxx==a) srednji=b;
        else srednji=a;
    }

    for (int i=0;i<3;i++)
    {
        if (e[i]=='A') cout<<minn<<" ";
        else if (e[i]=='B') cout<<srednji<<" ";
        else if (e[i]=='C') cout<<maxx<<" ";
    }
    return 0;
}

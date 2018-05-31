#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    string g;
    cin>>g;

    int poz=1;

    for (int i=0;i<g.size();i++)
        if (g[i]=='A' && poz==1) poz=2;
        else if (g[i]=='A' && poz==2) poz=1;
        else if (g[i]=='B' && poz==3) poz=2;
        else if (g[i]=='B' && poz==2) poz=3;
        else if (g[i]=='C' && poz==1) poz=3;
        else if (g[i]=='C' && poz==3) poz=1;

    cout<<poz<<endl;
    return 0;
}

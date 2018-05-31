#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

#define mod 100000

int n;
string g;
long long dp[201][201];
bool flag=false;

int zagrade(char a, char b)
{
    if ( a == '?' && b == '?' ) return 3;
    else if ( a == '(' && b == ')' ) return 1;
    else if ( a == '[' && b == ']' ) return 1;
    else if ( a == '{' && b == '}' ) return 1;
    else if ( a == '?' && b == ')' ) return 1;
    else if ( a == '?' && b == ']' ) return 1;
    else if ( a == '?' && b == '}' ) return 1;
    else if ( a == '(' && b == '?' ) return 1;
    else if ( a == '[' && b == '?' ) return 1;
    else if ( a == '{' && b == '?' ) return 1;
    else return 0;
}

long long zapis(int x, int y)
{
    if ( x > y ) return 1;
    if ( dp[x][y] != -10 ) return dp[x][y];

    long long br=0;
    for (int i=x+1;i<=y;i+=2)
    {
        br+=zapis(x+1,i-1) * zapis(i+1,y) * zagrade(g[x],g[i]);

        if ( br > mod ) flag=true;

        br%=mod;
    }

    dp[x][y]=br%mod;
    return br%mod;
}

int main()
{
    cin>>n;
    cin>>g;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        dp[i][j]=-10;

    long long rez=zapis(0,n-1);

    if ( flag )
    {
        rez%=mod;

        if ( rez < mod )
        {
            long long r = rez;

            int br=0;
            while (r > 0)
            {
                r/=10;
                br++;
            }

            for (int i=0;i<5-br;i++) cout<<"0";
            cout<<rez<<endl;
        }
    }
    else cout<<rez<<endl;
    
    return 0;
}

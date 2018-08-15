#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <map>
using namespace std;

int n,m;
vector <vector <int> > graf(10001);
vector <bool> flag(10001,false);
vector <int> posj;

void dfs(int x)
{
    flag[x]=true;

    for (int i=0;i<graf[x].size();i++)
        if ( flag[graf[x][i]] == false )
            dfs(graf[x][i]);
    posj.push_back(x);
}

int main()
{
    cin>>n>>m;

    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
    }

    dfs(1);

    bool ispis = false;
    vector <int> dp(n+1,0);
    dp[1]=1;

    for (int i=posj.size()-1;i>=0;i--)
    {
        for (int j=0;j<graf[posj[i]].size();j++)
        {
            dp[graf[posj[i]][j]]+=dp[posj[i]];

            if ( dp[graf[posj[i]][j]] >= 1e9 )
            {
                dp[graf[posj[i]][j]]=dp[graf[posj[i]][j]]%1000000000;
                ispis=true;
            }
        }
    }

    if ( ispis ) printf("%09d\n",dp[2]%1000000000);
    else cout<<dp[2]<<endl;
    return 0;
}

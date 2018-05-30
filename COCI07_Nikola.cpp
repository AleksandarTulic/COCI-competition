#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <utility>
#include <map>

using namespace std;

int n;
int dp[1001][1001];
int a[1001];
const int inf = 2e9;

int rec(int polje, int skok)
{
    if ( polje < 1 || polje > n || skok > n ) return inf;
    if ( polje == n ) return a[n];
    if ( dp[polje][skok] != inf ) return dp[polje][skok];

    dp[polje][skok] = min(dp[polje][skok],min(rec(polje+skok+1,skok+1),rec(polje-skok,skok))) + a[polje];

    return dp[polje][skok];
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];

    for (int i=0;i<=1000;i++)
        for (int j=0;j<=1000;j++)
            dp[i][j]=inf;

    cout<<rec(2,1)<<endl;
    return 0;
}

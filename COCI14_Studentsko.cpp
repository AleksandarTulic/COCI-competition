#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int k;
    cin>>k;

    pair <int, int> a[n];
    int b[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a,a+n);
    for (int i=n-1;i>=0;i--)
        b[a[i].second] = i / k;

    vector <int> dp(n,1);
    /*for (int i=0;i<n;i++) cout<<b[i]<<" ";
    cout<<endl;*/

    for (int i=1;i<n;i++)
        for (int j=0;j<i;j++)
            if ( b[i] >= b[j] ) dp[i] = max(dp[i], dp[j] + 1);

    /*for (int i=0;i<n;i++) cout<<dp[i]<<" ";
    cout<<endl;*/
    sort(dp.begin(),dp.end());
    cout<<n-dp[n-1]<<endl;
    return 0;
}

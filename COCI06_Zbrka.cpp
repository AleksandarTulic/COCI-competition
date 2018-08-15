#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    int n,c;
    cin>>n>>c;

    const int mod = 1e9 + 7;

    int dp[2][10001];
    for (int i=0;i<2;i++)
        for (int j=0;j<=c;j++)
        dp[i][j]=0;
    dp[1][0]=1;

    for (int i=2;i<=n;i++)
    {
        dp[i%2][0]=dp[(i-1)%2][0] % mod;
        for (int j=1;j<=c;j++)
        {
            dp[i%2][j]=dp[(i-1)%2][j] % mod;
            dp[i%2][j]=(dp[i%2][j] + dp[i%2][j-1]) % mod;
            if (j >= i) dp[i%2][j]=(dp[i%2][j] - dp[(i-1)%2][j-i] + mod) % mod;
        }
    }

    cout<<dp[n%2][c]<<endl;
    return 0;
}

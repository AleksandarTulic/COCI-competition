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

using namespace std;

double k;int n;
double d[100001];

int main()
{
    cin>>k>>n;
    for (int i=0;i<n;i++) cin>>d[i];

    double kol = 0.0;

    for (int i=1;i<n;i++)
    {
        if ( d[i] - d[i-1] - kol <= k ) d[i] = min(d[i-1] + k, d[i] + kol);
        else
        {
            double sec = ( d[i] - d[i-1] - k - kol )/2;
            d[i]-=kol+sec;
            kol+=sec;
        }
    }

    cout<<setprecision(5)<<fixed<<kol<<endl;
    return 0;
}

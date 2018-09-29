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
    scanf("%d",&n);

    map <int, int> m;
    int a[n];
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int br = 0;

    for (int i=0;i<n;i++)
    {
        if ( m[a[i]] == 0 )
        {
            br++;
            m[a[i]-1]++;
        }
        else
        {
            m[a[i]]--;
            m[a[i]-1]++;
        }
    }

    cout<<br<<endl;
    return 0;
}

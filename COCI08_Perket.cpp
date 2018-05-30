#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;

    pair <int, int> a[n];
    for (int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;

    int d=(1<<n);

    int naj=2e9;

    for (int i=1;i<d;i++)
    {
        int p=1;
        int suma=0;

        for (int j=0;j<n;j++)
        {
            if ( ( 1<<j ) & i )
            {
                p*=a[j].first;
                suma+=a[j].second;
            }
        }

        naj=min(naj,abs(p-suma));
    }

    cout<<naj<<endl;
    return 0;
}

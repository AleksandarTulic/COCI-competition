#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cin>>n;

    int a[n];

    for (int i=0;i<n;i++) cin>>a[i];

    vector <int> b(n,0);

    for (int i=0;i<n;i++)
    {
        int suma=0;
        for (int j=0;j<i;j++)
            suma+=b[j];
            
        b[i]=a[i]*(i+1)-suma;
    }

    for (int i=0;i<n;i++) cout<<b[i]<<" ";
    return 0;
}

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

    unsigned long long suma = 0;
    int ele = -1;
    for (int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        ele=max(ele,a);
        suma+=a;
    }

    if ( ele <= suma/2 ) cout<<suma<<endl;
    else cout<<ele*2<<endl;
    return 0;
}

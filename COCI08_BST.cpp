#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n;
    cin>>n;

    map <int, int> bst;
    map <int, int>::iterator look;

    int node;
    cin>>node;
    unsigned long long rez = 0;
    cout<<rez<<endl;
    bst[node]=0;
    n--;

    while (n--)
    {
        cin>>node;
        int maks = -1;
        look = bst.upper_bound(node);
        if ( look != bst.end() ) maks = max(maks,look->second+1);
        if ( look != bst.begin() ) maks = max(maks,(--look)->second+1);
        bst[node]=maks;
        rez+=maks;
        cout<<rez<<endl;
    }
    return 0;
}

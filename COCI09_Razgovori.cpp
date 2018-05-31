#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    pair <int, int> det[n];
    for (int i=0;i<n;i++) cin>>det[i].first>>det[i].second;

    sort(det,det+n);

    long long rez = det[n-1].second;
    for (int i=1;i<n;i++)
    {
        int br_pre = det[i-1].second - det[i].second;
        rez+=max(0,br_pre);
    }

    cout<<rez<<endl;
    return 0;
}

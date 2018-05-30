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

    vector <int> brx(100001,-1);
    vector <int> bry(100001,-1);

    pair <int, int> xy[n];

    for (int i=0;i<n;i++)
    {
        cin>>xy[i].first>>xy[i].second;

        brx[ xy[i].first ]++;
        bry[ xy[i].second ]++;
    }

    long long broj=0;
    for (int i=0;i<n;i++)
    {
        long long X=brx[xy[i].first];
        long long Y=bry[xy[i].second];

        broj+=(X*Y);
    }

    cout<<broj<<endl;
    return 0;
}

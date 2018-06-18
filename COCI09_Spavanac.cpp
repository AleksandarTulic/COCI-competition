#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int d,h,m;
    cin>>h>>m;
    if (m>=45)
        cout<<h<<" "<<m-45;
    else
        cout<<h-1<<" "<<60-abs(m-45);
    return 0;
}

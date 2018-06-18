#include <iostream>
using namespace std;

int main()
{
    int d;
    string h,t;
    cin>>h;
    d=h.size();
    for (int i=0;i<d;i++)
        if (isupper(h[i]))
            t=t+h[i];
    cout<<t;
    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    int a[9];
    for (int i=0;i<9;i++) cin>>a[i];

    for (int i=0;i<(1<<9);i++)
    {
        int suma=0;
        vector <int> broj;
        for (int j=0;j<9;j++)
        {
            if ( (1 << j) & i )
            {
                suma+=a[j];
                broj.push_back(a[j]);
            }
        }
        if ( broj.size() == 7 && suma == 100)
        {
            for (int j=0;j<broj.size();j++)
                cout<<broj[j]<<endl;
            return 0;
        }
    }
    return 0;
}

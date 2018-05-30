#include <iostream>

using namespace std;

int main()
{
    int r,c;

    cin>>r>>c;

    char matrica[r+1][c+1];

    for (int i=0;i<r+1;i++)
    {
        for (int j=0;j<c+1;j++)
        {
            matrica[i][j]='#';
        }
    }

    for (int i=1;i<r+1;i++)
    {
        for (int j=1;j<c+1;j++)
        {
            cin>>matrica[i][j];
        }
    }

    int brojac1=0,brojac2=0,brojac3=0,brojac4=0,brojac5=0;

    for (int i=1;i<r;i++)
    {
        for (int j=1;j<c;j++)
        {
            if (matrica[i][j]=='.' && matrica[i+1][j]=='.' && matrica[i+1][j+1]=='.' && matrica[i][j+1]=='.')
            {
                brojac1++;
            }
            else if (matrica[i][j]=='X' && matrica[i+1][j+1]=='.' && matrica[i+1][j]=='.' && matrica[i][j+1]=='.')
            {
                brojac2++;
            }
            else if (matrica[i][j]=='.' && matrica[i+1][j+1]=='X' && matrica[i+1][j]=='.' && matrica[i][j+1]=='.')
            {
                brojac2++;
            }
            else if (matrica[i][j]=='.' && matrica[i+1][j+1]=='.' && matrica[i+1][j]=='X' && matrica[i][j+1]=='.')
            {
                brojac2++;
            }
            else if (matrica[i][j]=='.' && matrica[i+1][j+1]=='.' && matrica[i+1][j]=='.' && matrica[i][j+1]=='X')
            {
                brojac2++;
            }
            else if (matrica[i][j]=='X' && matrica[i+1][j+1]=='X' && matrica[i+1][j]=='.' && matrica[i][j+1]=='.')
            {
                brojac3++;
            }
            else if (matrica[i][j]=='.' && matrica[i+1][j+1]=='X' && matrica[i+1][j]=='X' && matrica[i][j+1]=='.')
            {
                brojac3++;
            }
            else if (matrica[i][j]=='.' && matrica[i+1][j+1]=='.' && matrica[i+1][j]=='X' && matrica[i][j+1]=='X')
            {
                brojac3++;
            }
            else if (matrica[i][j]=='X' && matrica[i+1][j+1]=='.' && matrica[i+1][j]=='X' && matrica[i][j+1]=='.')
            {
                brojac3++;
            }
            else if (matrica[i][j]=='X' && matrica[i+1][j+1]=='.' && matrica[i+1][j]=='.' && matrica[i][j+1]=='X')
            {
                brojac3++;
            }
            else if (matrica[i][j]=='.' && matrica[i+1][j+1]=='X' && matrica[i+1][j]=='.' && matrica[i][j+1]=='X')
            {
                brojac3++;
            }
            else if (matrica[i][j]=='X' && matrica[i+1][j+1]=='X' && matrica[i+1][j]=='X' && matrica[i][j+1]=='.')
            {
                brojac4++;
            }
            else if (matrica[i][j]=='X' && matrica[i+1][j+1]=='X' && matrica[i+1][j]=='.' && matrica[i][j+1]=='X')
            {
                brojac4++;
            }
            else if (matrica[i][j]=='X' && matrica[i+1][j+1]=='.' && matrica[i+1][j]=='X' && matrica[i][j+1]=='X')
            {
                brojac4++;
            }
            else if (matrica[i][j]=='.' && matrica[i+1][j+1]=='X' && matrica[i+1][j]=='X' && matrica[i][j+1]=='X')
            {
                brojac4++;
            }
            else if (matrica[i][j]=='X' && matrica[i+1][j+1]=='X' && matrica[i+1][j]=='X' && matrica[i][j+1]=='X')
            {
                brojac5++;
            }
        }
    }

    cout<<brojac1<<endl;
    cout<<brojac2<<endl;
    cout<<brojac3<<endl;
    cout<<brojac4<<endl;
    cout<<brojac5<<endl;
    return 0;
}

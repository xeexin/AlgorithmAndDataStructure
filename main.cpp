#include<iostream>
using namespace std;
char name[6] = "ABCDE";
char path[10];
void abc(int lev)
{

    if (lev == 3) {
        cout << path << endl;
        return;
    }

    for (int x = 0; x < 6; x++) {
        if(lev!=0 && path[lev-1]>=(char) x+'A')continue;
        path[lev] = x + 'A';
        abc(lev + 1);
        path[lev] = 0;
    }
}
int main()
{
    abc(0); // level


    return 0;
}
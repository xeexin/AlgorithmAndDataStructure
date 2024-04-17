//최종 몇개의 그룹이 있을까요

#include<iostream>
#include<vector>
using namespace std;
vector<string>vect =
        {
                "AE",
                "FE",
                "CE",
                "CA",
                "BD",
                "DB",
        };

int arr[200];
int answer = 6; //처음 그룹은 6개임

char findboss(char member)
{
    if (arr[member] == 0) return member;
    char ret = findboss(arr[member]); // 해당 값을 findboss해주어야 함
    //arr[member] = ret;
    return ret;

}
void setunion(char a, char b)
{
    if (findboss(a) == findboss(b)) return;
    arr[findboss(b)] = findboss(a);
}
int main()
{
    for (int x = 0; x < vect.size(); x++)
    {
        if (findboss(vect[x][0]) != findboss(vect[x][1])) // 보스가 같지 않다면
        {
            setunion(vect[x][0], vect[x][1]); //보스를 묶어주고
            answer--; //그룹 개수 하나 줄어듬!
        }
    }

    cout << answer << "개";

    return 0;
}
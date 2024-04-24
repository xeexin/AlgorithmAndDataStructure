/*
a 50
b 40
c 99
d 5
e 25
f 6
g 37

 서바이벌 선수와 전투력이 있을때
a~f를 두 팀으로 만들어서 서바이벌 게임을 하고자 한다.
두 팀의 전투력 차이가 가장 적게하여 두 팀을 구성한다고 했을때
두 팀의 최소 전투력 차이는 몇이 되는가?*/

#include<iostream>
#include<cstdlib>
using namespace std;
//br=7
//lv=6
int score[7] = { 50,40,99,5,25,6,37 };
int teamA[7];
char path[10];
int Min = 21e8;
void dfs(int level, int sum)
{
    int against = 0; // 상대편 점수
    for (int x = 0; x < 7; x++)
    {
        if (teamA[x] == 0)against += score[x]; //A가 아닌 팀의 점수
    }
    int gap = abs(sum - against); //절댓값
    if (gap < Min) {
        Min = gap;
    }

    if (level == 6)return; // 팀이 다 짜여지면 리턴;

    for (int x = 0; x < 7; x++)
    {
        if (level != 0 && path[level - 1] >= (char) (x + 'A'))  continue; // 이전에 선택된 선수가 존재하고 && 오름차순으로 팀 정렬(중복배열방지)

        path[level] = x + 'A';
        teamA[x] = 1;

        dfs(level + 1, sum + score[x]);

        teamA[x] = 0;
        path[level] = 0;
    }

}
int main()
{

    dfs(0, 0); // level sum;  레벨과, a팀의 전투력의 합
    cout << Min;
    return 0;
}

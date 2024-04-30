#include<iostream>
#include<string>
#include<vector>
using namespace std;
string target = "mincoding";
vector<string>vect={"mi","ncod","ing","cod","minco","min"};
int used[6];
int flag = 0;
string words;
void dfs(int level )
{
    if(words.length() > target.length() )return; // 시간 최소화

    if (words == target) {
        flag=1;
        return;
    }

    if(level==vect.size())return;

    string backup = words; //백업해주기!!

    for (int x = 0; x < vect.size(); x++) {
        if(used[x]==1) continue;
        used[x] = 1;
        words += vect[x];
        dfs(level + 1);
        used[x] = 0;
        words = backup;
    }
}
int main()
{
    dfs(0);

    return 0;
}
#include<iostream>
using namespace std;
char name[6] = "ABTKG";
int map[5][5] = {
	0,1,1,0,0,
	0,0,1,1,1,
	0,1,0,1,0,
	0,0,0,0,0,
	0,0,0,0,0,
};
int used[6];

void dfs(int now){
    cout << name[now] << " ";

    for (int x = 0; x < 5; x++) {
        if (map[now][x] == 1 && used[x] == 0) {
            used[x] = 1;
            dfs(x);
        }
    }
}

int main()
{
	char st;
	cin >> st;

    int idx = 0;
    for (int x = 0; x < 5; x++) {
        if (name[x] == st) {
            idx = x;
            break;
        }
    }
    used[idx] = 1;
    dfs(idx);

	return 0;
}
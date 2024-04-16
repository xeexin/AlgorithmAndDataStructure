/*
10. 이차배열의 형태
vector<vector<string>>v;

예를들어 vector<vector<string>>v={{1,2,3},{4,5}};
[0] 123
[1] 45

출력해 보세요~
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> v = {{1, 2, 3},
                         {4, 5}};
int main()
{
    for (int y = 0; y < v.size(); y++) {
        for (int x = 0; x < v[y].size(); x++) {
            cout << v[y][x];
        }
        cout << endl;
    }


    return 0;
}

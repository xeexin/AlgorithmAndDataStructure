#include<iostream>
using namespace std;
char name[6] = "ABCDE";
const int _ = 999;
int map[5][5] = {
        _,1,_,9,3,
        _,_,7,_,1,
        _,_,_,1,_,
        _,_,_,_,_,
        _,_,1,_,_,
};
int used[5] = {1};
int result[5] = {_, 1, _, 9, 3};
int choice()
{
    int MIN = 21e8;
    int minIdx = 0;

    for (int x = 0; x < 5; x++) {
        if (used[x] == 0 && result[x] < MIN) {
            MIN = result[x];
            minIdx = x;
        }
    }
    return minIdx;
}
void dijkstra()
{
    for (int y = 0; y < 5; y++) {
        int via = choice();
        used[via] = 1;

        for (int x = 0; x < 5; x++) {
            int baro = result[x]; //바로 가는 것
            int ky = result[via] + map[via][x]; //경유

            if (baro > ky) {
                result[x] = ky;
            }
        }
    }

}
int main()
{
    dijkstra();

    for (int x = 0; x < 5; x++)
    {
        cout << result[x] << " ";
    }

    return 0;
}
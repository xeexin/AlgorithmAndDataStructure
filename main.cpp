// 백준 G_5_1759

#include <iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int n, m;
int minCityDistance = 21e8;
struct home {
    int yy,xx;
};
struct chicken {
    int yy,xx;
    bool visited;
};

vector<home> home;
vector<chicken> chicken;

// 1. m개의 치킨집 뽑기(중복 조합 X)
// 2. m개의 치킨집에서 가장 가까운 거리 구하기
// 3. 조합이 최대가 되는 거 구하기
void getDistance() {
    int cityDistance = 0;

    for (int y=0; y<home.size(); y++) {
        int minHomeDistance = 21e8;
        for (int x=0; x<chicken.size(); x++) {
            if (chicken[x].visited == true) {
                int homeDistance = abs(home[y].yy - chicken[x].yy) + abs(home[y].xx - chicken[x].xx);
                if (homeDistance < minHomeDistance) {
                    minHomeDistance = homeDistance;
                }
            }
        }
        cityDistance += minHomeDistance;
    }

    if (cityDistance < minCityDistance) {
        minCityDistance = cityDistance;
    }
}
void selectChicken(int st, int lev) {

    if (lev == m) {
        getDistance();
    }

    for (int x= st; x<chicken.size(); x++) {
        if (!chicken[x].visited) {
            chicken[x].visited = true;
            selectChicken(x, lev+1);
            chicken[x].visited = false;
        }
    }


}
int main() {

    //1. 입력
    cin >> n >> m; //도시n개 치킨집m개
    int flag;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> flag;
            if (flag==1) home.push_back({y,x});
            else if (flag==2) chicken.push_back({y,x,false});
        }
    }

    //2. 연산
    selectChicken(0,0);


    cout << minCityDistance << endl;

    return 0;
}

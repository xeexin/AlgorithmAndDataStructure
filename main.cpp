//반장선거
//
#include<iostream>
using namespace std;
int main()
{
    // 반 아이들 투표
    char classMate[2][4] = {"aaa",
                            "ddd"};
    char candidate[4] = {"ace"};

    char bucket[200]={0};

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 4; x++) {
            bucket[classMate[y][x]]++;
        }
    }

    int gikwon=0;
    int MAX=0;
    int MaxIdx=0;

    for (int x = 0; x < 200; x++) {
        if (bucket[x] > MAX) {
            MAX = bucket[x];
            MaxIdx = x;

            //기권표
            if (bucket[x] > 0) {
                if (x != 'a' || x != 'c' || x != 'e') {
                    gikwon ++;
                }
            }
        }
    }

    cout << "당선된 사람은 " << (char)MaxIdx<< "이고 표는 " << MAX << "개이며 기권표 갯수는 " << gikwon << "입니다.";

    return 0;
}
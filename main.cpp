// 백준 G_5_2447

#include<iostream>
#include<cmath> // pow(=거듭제곱에 필요)
using namespace std;
int n, r, c, cnt;

void solve(int y, int x, int size) {
    while (size >= 1) {
        int set = pow(size / 2, 2); // (size/2) ^ 2  *한 사분면의 칸 개수

        // 4개 사분면 중에서 어디로 갈지 판별

        if (r < y + size / 2 && c < x + size / 2) {
            // 1사분면 -> 그대로 진행 (cnt 값 증가 X)
        }
        else if (r < y + size / 2 && c >= x + size / 2 && c < x + size) {
            cnt += set; // 2사분면이면 1사분면 개수만큼 더함
            x += size / 2; // y좌표 이동
        }
        else if (r >= y + size / 2 && r < y + size && c < x + size / 2) {
            cnt += set * 2; // 3사분면이면 1, 2사분면 개수만큼 더함
            y += size / 2; // x좌표 이동
        }
        else {
            cnt += set * 3; // 4사분면이면 1, 2, 3사분면 개수 더함
            y += size / 2;
            x += size / 2;
        }
        size /= 2; // 크기 줄이면서 더 작은 영역 탐색
    }
}

int main() {
    cin >> n >> r >> c;

    int size = pow(2, n); // 2 ^ n  ** 현재 조사하는 정사각형의 한 변의 길이

    solve(0, 0, size);

    cout << cnt;


    return 0;
}

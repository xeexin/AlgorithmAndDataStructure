// AG#UCG#BTS#KB 파싱하기

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string arr = "AG#UCG#BTS#KB";
    string ret[10];

    int idx = 0;
    int a = 0;
    int b;

    while (1) {
        b = arr.find("#", a);

        if (b == -1) {

            ret[idx++] = arr.substr(a, arr.length() - a);
            break;
        }
        ret[idx++] = arr.substr(a, b - a);
        a = b + 1;
    }

    for (int x = 0; x < idx; x++) {
        cout << ret[x] << endl;
    }

    return 0;
}


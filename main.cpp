//2개 조합해서 starbuckskorea 만들기


#include<iostream>
#include<string>
using namespace std;

int main()
{
    string arr[5] = { "star","start","buckskorea","starbucks","korea" };

    for (int y = 0; y < 5-1; y++) {
        for (int x = y + 1; x < 5; x++) {
            if (arr[y] + arr[x] == "starbuckskorea") {
                cout << "[" << y << "] + [" << x << "] = starbuckskorea\n";
            }
        }
    }

}



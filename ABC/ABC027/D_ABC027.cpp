#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
// 幸福度の計算
void Happiness(char S[]) {
    int length = strlen(S);
    int cnt = 0;
    std::vector<int> V;
    for (int i = 0; i < length; ++i)
    {
        if (S[i] == '+') {
            cnt ++;
        } else if (S[i] == '-') {
            cnt --;
        } else {
            V.push_back(cnt);
        }
    }
    // ソート
    sort(V.begin(), V.end());
    // 幸福度の計算
    int ans = 0;
    for (int i = 0; i < V.size(); ++i)
    {
        if (i < V.size()/2) {
            ans -= V[i];
        } else {
            ans += V[i];
        }
    }
    std::cout << ans << "\n";
}
int main(int argc, char* argv[])
{
    int sizeS = pow(10, 5)+1;
    char S[sizeS];
    std::cin >> S;
    // 幸福度の計算
    Happiness(S);
    return 0;
}

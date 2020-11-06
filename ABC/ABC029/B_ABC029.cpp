#include <iostream>

int main(int argc, char* argv[])
{
    const int length = 11;
    const int words = 12;
    char S[words][length];
    // 入力
    for (int i = 0; i < words; ++i)
    {
        std::cin >> S[i];
    }
    // rの数を計算
    int cnt = 0;
    for (int i = 0; i < words; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (S[i][j] == 'r')
            {
                cnt++;
                break;
            } else if (S[i][j] == '\0') {
                break;
            }
        }
    }
    // 出力
    std::cout << cnt << "\n";
    return 0;
}

#include <iostream>
// 再帰
void Rec(int N, std::string s) {
    if (N == 0) {
        std::cout << s << "\n";
    } else {
        for (char c = 'a'; c <= 'c'; ++c)
        {
            Rec(N-1, s+c);
        }
    }
}
// メイン
int main(int argc, char* argv[])
{
    int N;
    std::cin >> N;
    Rec(N, "");
    return 0;
}

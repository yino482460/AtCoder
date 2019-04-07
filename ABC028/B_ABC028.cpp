#include <iostream>

class B_ABC028 {
private:
    static const alphabets = 6;
    int alphabet[alphabets];
public:
    B_ABC028 ();
    virtual ~B_ABC028 ();
    void cntAlphabet (char S[]);
};
// 各アルファベットの数の計算
void B_ABC028 :: cntAlphabet (char S[]) {
    int i = 0;
    while (S[i] != '\0') {
        int no = S[i] - 'A';
        alphabet[no] ++;
        i++;
    }
    for (int i = 0; i < 6; ++i)
    {
        std::cout << alphabet[i] << " ";
    }
    std::cout << "\n";
}
// メイン
int main(int argc, char* argv[])
{
    const int sizeS = 101;
    char S[sizeS];
    // 入力
    std::cin >> S;
    B_ABC028 ABCDEF;
    ABCDEF.cntAlphabet(S);
    return 0;
}

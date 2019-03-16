#include <iostream>
#include <vector>
#include <algorithm>

class Amida {
private:
    /* data */
public:
    int N, M, D;
    std::vector<int> A;  // 阿弥陀の横線の組み合わせ
    std::vector<int> toA;    // 移動後の位置
    Amida ();   // 入力を受け取って配列に設定
    virtual ~Amida ();
    void move();    // 阿弥陀を移動する
    void  setResultAmida(); // 答えを返す
};

// 入力を設定
Amida :: Amida () {
    std::cin >> N >> M >> D;    // 入力
    // 配列に阿弥陀の横棒を設定
    for (size_t i = 0; i < M; i++) {
        int tmp;
        std::cin >> tmp;
        A.push_back(tmp);
    }
}
Amida :: ~Amida() {};

// 阿弥陀を移動する関数
void Amida :: move() {
    std::vector<int> ans;
    for (size_t i = 0; i < N; i++) {
        ans.push_back(i);
    }
    
}

int main(int argc, char const *argv[]) {
    // 変数
    return 0;
}

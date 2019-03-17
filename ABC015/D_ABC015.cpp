#include <iostream>
#include <vector>

class DABC015 {
public:
    int W, N, K;
    std::vector<int> width, importance;  // 重要度
    std::array<int, 10> dp[][][];
    DABC015 ();
    virtual ~DABC015 ();
    void DP();
};
// 入力
DABC015 :: DABC015() {
    std::cin >> W >> N >> K;
    for (int i = 0; i < N; ++i) {
        int a, b;
        std::cin >> a >> b;
        width.push_back(a);
        importance.push_back(b);
    }
}
DABC015 :: ~DABC015() {}
// 動的計画法

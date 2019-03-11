#include <iostream>
#include <vector>
#include <algorithm>

class Tree {
private:
    /* data */
public:
    int N, Q;
    std::vector<int> A;  // 阿弥陀の横線の組み合わせ
    std::vector<int> toA;    // 移動後の位置
    Tree ();   // 入力を受け取って配列に設定
    virtual ~Tree ();
};

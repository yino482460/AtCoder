#include <iostream>
#include <vector>
#include <algorithm>

class LCA {
private:
    /* data */
public:
    int N, Q, root;
    typedef struct edge_t {
        int node1, node2;
    } edge_t;
    std::vector<edge_t> edge;   // ノード同士の連結状態を記憶
    std::vector<int> a, b;
    std::vector<int> parent, depth; //親のノード番号, ルートからの深さ
    std::vector<std::vector<int>> tree;
    // 関数
    void Input();
    void MakeTree();
    void DFS(int v, int p, int d);
    LCA ();
    virtual ~LCA ();
};
// 入力
void LCA :: Input() {
    std::cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int x, y;
        std::cin >> x >> y;
        x = x-1; y = y-1;
        // ノード同士の連結状態を記憶
        edge.push_back({x, y});
    }
    // 追加する辺の取得
    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a_i, b_i;
        std::cin >> a_i >> b_i;
        a_i = a_i - 1; b_i = b_i - 1;
        a.push_back(a_i);  b.push_back(b_i);
    }
}
// 木構造を構築
void LCA :: MakeTree() {
    for (int i = 0; i < N-1; ++i) {
        int x = edge[i].node1;
        int y = edge[i].node2;
        // 連結状態を表現
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
}
// 深さ優先探索  親:p, 深さ:d
void LCA :: DFS(int v, int p, int d) {
    // ノード vの親 = p
    parent[v] = p;
    //ルートからノード vまでの深さ = d
    depth[v] = d;
    for (int i = 0; i < tree[v].size(); ++i) {
        if (tree[v][i] != p) {  // 子が自分の親と連結していない
            DFS(tree[v][i], v, d+1);
        }
    }
}

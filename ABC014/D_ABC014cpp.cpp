#include <iostream>
#include <vector>
#include <algorithm>

class LCA {
private:
    /* data */
public:
    int N, Q;
    // 辺の構造体
    typedef struct edge_t {
        int node1, node2;
    } edge_t;
    std::vector<edge_t> edge;   // ノード同士の連結状態を記憶
    std::vector<int> parent;
    std::vector<int> depth; //親のノード番号, ルートからの深さ
    std::vector< std::vector<int> > tree;
    // 関数
    LCA (); // 入力
    virtual ~LCA ();
    void MakeTree();    // 木構造を構築
    void DFS(int v, int p, int d);  // 深さ優先探索
    void Init();    //DFSの初期設定
    int CalcLCA(int u, int v);  // LCAの計算
    void Exec();
};

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
// 初期化
void LCA :: Init() {
    DFS(0, -1, 0);  // rootは0
}
// u と vのLCAを求める
int LCA :: CalcLCA(int u, int v) {
    //uとvそれぞれのrootからの深さを揃える
    while (depth[u] > depth[v]) { u = parent[u]; }
    while (depth[v] > depth[u]) { v = parent[v]; }
    //最小祖先ノードで合流するまで１つ１つ向かっていく
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}
LCA :: ~LCA() {}
LCA :: LCA() {
    std::cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int x, y;
        std::cin >> x >> y;
        x = x-1; y = y-1;
        edge_t a = {x, y};
        // ノード同士の連結状態を記憶
        edge.push_back(a);
    }
    // 関数
    MakeTree();
    Init(); // DFS開始
}
void LCA :: Exec() {
    // 追加する辺の取得
    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a_i, b_i;
        std::cin >> a_i >> b_i;
        a_i = a_i - 1; b_i = b_i - 1;
        int p = CalcLCA(a_i, b_i);  //   最小共通祖先
        int ans = depth[a_i] - depth[p] + depth[b_i] - depth[p] + 1;
        std::cout << ans  << "\n";
    }
}
int main(int argc, char* argv[]) {
    LCA lca = LCA();
    lca.Exec();
    return 0;
}

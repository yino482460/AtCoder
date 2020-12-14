#include <bits/stdc++.h>
using namespace std;

static const long long mod = 1e9+7;
static const int MAX = 1005;

int a[MAX][MAX];
long long dp[MAX][MAX];
int H, W;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void init() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      a[i][j] = -1;
      dp[i][j] = -1;
    }
  }
}

long long memoDP(int y, int x) {
  if (dp[y][x] != -1)
  {
    return dp[y][x];
  }
  long long ret = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y+dy[i];
    int nx = x+dx[i];
    if (!(0<=nx && nx<W && 0<=ny && ny<H))
    {
      continue;
    }
    if (a[y][x] < a[ny][nx])
    {
      ret += memoDP(ny, nx);
      ret %= mod;
    }
  }
  return dp[y][x] = ret;
}

int main(int argc, char const *argv[])
{
  /* 入力 */
  cin >> H >> W;
  init();
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  /* 計算 */
  long long ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans += memoDP(i, j);
      ans %= mod;
    }
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}

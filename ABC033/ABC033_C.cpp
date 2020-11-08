#include <bits/stdc++.h>
using namespace std;

int ctoi(const char c)  // 文字を数字に変換
{
  if ('0' <= c && c <= '9')
    return (c - '0');
  return -1;
}

int main(int argc, char const *argv[])
{
  /* 入力 */
  string S;
  cin >> S;

  /* 計算 +で分解 */
  int ans = 0;
  int zero_flg = 0;
  int is_prd = 0;
  int len = S.size();

  if ( len == 1 )
  {
    if ( S[0] == '0')
    {
      cout << 0 << endl; // 出力
    }
    else
    {
      cout << 1 << endl; // 出力
    }
  }
  else
  {

    vector<int> nums; // 数だけ
    vector<char> ope; // 記号だけ
    // 数式の分解
    for (int i = 0; i < len; i++)
    {
      if (i%2 == 0)
      {
        nums.push_back(ctoi(S[i]));
      }
      else
      {
        ope.push_back(S[i]);
      }
    }
    // 数値の計算
    vector<int> tmp;
    tmp.push_back(nums[0]);
    int id = 0; // 何番目の塊か
    int num;
    for (int i = 1; i < nums.size(); i++)
    {
      // オバーフロー避け
      if (nums[i] == 0)
      {
        num = 0;
      }
      else
      {
        num = 1;
      }

      if (ope[i-1] == '*')
      {
        tmp[id] *= num;
      } else  // 足し算の時
      {
        tmp.push_back(nums[i]);
        id++;
      }
    }
    // 最終計算
    int ans = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
      if (tmp[i] != 0)
      {
        ans++;
      }
    }
    // 出力
    cout << ans << endl;
  }

  return 0;
}

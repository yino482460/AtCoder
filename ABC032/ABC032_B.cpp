#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string s;
  int k;
  cin>> s>> k;

  /* メイン計算 */
  set<string> ans;  // 重複を許さない文字列集合
  size_t strlen = s.size(); // 対象の文字列の長さ

  if (strlen < k)
  {
    /* 出力 */
    cout << 0 << endl;
  }
  else
  {
    for (size_t i = 0; i <= strlen - k; i++)
    {
      ans.insert(s.substr(i, k));
    }
    /* 出力 */
    cout << ans.size() << endl;
  }

  return 0;
}

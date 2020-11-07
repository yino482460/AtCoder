#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int A, D;
  cin >> A>> D;
  if ((A +1 )* D > A*(D + 1))
  {
    cout << (A + 1) * D << endl;
  }
  else
  {
    cout << A * (D + 1) << endl;
  }

  // cout << "HelloWorld." << endl;
  return 0;
}

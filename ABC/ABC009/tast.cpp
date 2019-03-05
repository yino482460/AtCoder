#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void Solve(int n, int k)	{
	string s, t="";
	int count_s[26]={0}, count_t[26]={0};

	cin >> s;
	for (int i=0; i<n; ++i)	{
		++count_s[s[i]-'a'];
		++count_t[s[i]-'a'];
	}
	for (int i=0; i<n; ++i)	{
		for (int index=0; index<26; ++index)	{
			if (!count_t[index])	continue;
			char c='a'+index;
			int diff=0;
			for (int j=0; j<i; ++j)
				if (s[j] != t[j])	++diff;
			if (c != s[i])	++diff;
			--count_s[s[i]-'a'];
			--count_t[index];
			int number=(n-1)-i;
			for (int j=0; j<26; ++j)
				number-=min(count_s[j],count_t[j]);
			diff+=number;
			if (diff <= k)	{
				t+=('a'+index);
				break;
			}
			++count_s[s[i]-'a'];
			++count_t[index];
		}
	}
	cout << t << endl;
}

int main(void)	{
	int n, k;

	cin >> n >> k;
	Solve(n,k);
	return 0;
}

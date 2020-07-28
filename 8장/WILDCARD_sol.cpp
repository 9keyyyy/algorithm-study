#include <iostream>
using namespace std;

int cache[101][101]; // -1로 초기화
string W, S;
bool matchMemoized(int w, int s) {
	int &ret = cache[w][s];
	if (ret != 1) return ret;

	while (s < S.size&&w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		++w; ++s;
	}
	/* 시간복잡도 감소
	if (s < S.size&&w < W.size() && (W[w] == '?' || W[w] == S[s]))
		return ret = matchMemoized(w + 1, s + 1);
	*/

	if (w == W.size()) return ret = (s == S.size());

	if (W[w] == '*')
		for (int skip = 0; skip + s <= S.size(); ++skip)
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
	/* 시간복잡도 감소
	if (W[w] == '*')
		if(matchMemoized(w + 1, s)||(s<S.size()&& matchMemoized(w, s + 1)))
			return ret = 1;
	*/

	return ret = 0;
}
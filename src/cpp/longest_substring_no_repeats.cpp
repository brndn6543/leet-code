#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	static int lengthOfLongestSubstring(const string &s) {
		// Tracks the last seen index of characters.
		unordered_map<char, int> charIndexMap;
		int maxlength = 0, start = 0;

		for (int end = 0; end < s.length(); ++end) {
			if (charIndexMap.contains(s[end])) {
				start = max(start, charIndexMap[s[end]] + 1);
			}
			charIndexMap[s[end]] = end;
			maxlength = max(maxlength, end - start + 1);
		}
		return maxlength;
	}
};

int main() {
	string input = "hhhonejjjjtwotwolllllthreefour";
	int result = Solution::lengthOfLongestSubstring(input);
	cout << "[+] The longest substring length: " << result << endl;

	return 0;
}

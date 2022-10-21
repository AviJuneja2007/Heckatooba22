class Solution {
public:
   
	vector<string>v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (digits.size() == 0)
		{
			return ans;
		}
		ans.push_back("");

		for (auto d : digits)
		{
			vector<string>temp;
			for (auto c : v[d - '0'])
			{
				for (auto s : ans)
				{
					temp.push_back(s + c);
				}
			}
			swap(temp, ans);
		}

		return ans;
	}
};
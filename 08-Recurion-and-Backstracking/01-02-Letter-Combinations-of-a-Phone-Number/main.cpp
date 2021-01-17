#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

/// 17. Letter Combinations of a Phone Number
/// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
/// 时间复杂度: O(2^len(s))
/// 空间复杂度: O(len(s))
class Solution {
    const string stringMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> res;

private:
    // s中保存了此时从digits[0...index-1]翻译得到的一个字母字符串
    // 寻找和digits[index]匹配的字母, 获得digits[0...index]翻译得到的解
    void findCombinations(const string& digits, int index, const string& s) {
        if(index == digits.size()) {
            res.emplace_back(s);
            return;
        }

        char c = digits[index];
        string letters = stringMap[c - '0'];
        for(char letter : letters) {
            findCombinations(digits, index + 1, s + letter);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;

        findCombinations(digits, 0, "");

        return res;
    }
};
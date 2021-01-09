#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/
// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if(stk.size() == 0) {
                    return false;
                }

                char topChar = stk.top();
                stk.pop();

                switch(topChar) {
                    case '(':
                        if(c != ')') return false;
                        
                        break;

                    case '[':
                        if(c != ']') return false;
                        
                        break;
                    
                    case '{':
                        if(c != '}') return false;
                        
                        break;
                }
            }
        }

        return stk.empty();
    }
};
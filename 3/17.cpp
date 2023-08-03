class Solution {
public:
    vector<string> ret;
    void mycombination(string digits, vector<char>& temp, unordered_map<char, string> phone, int index) {
        if(index == digits.size())
        {
            string str(temp.begin(), temp.end());
            if(str != "")
                ret.push_back(str);
            return;
        }

        char idx = digits[index];
        for(int i=0; i<phone[idx].size(); i++)
        {
            // cout << "letter = " << phone[idx][i] << endl;
            temp.push_back(phone[idx][i]);
            mycombination(digits, temp, phone, index + 1);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<char> temp;
        unordered_map<char, string> phone;
        phone = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        mycombination(digits, temp, phone, 0);
        return ret;
    }
};
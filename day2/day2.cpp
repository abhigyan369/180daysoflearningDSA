/* 2785. Sort Vowels in a String
Attempted
Medium
Topics
Companies
Hint
Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 

Example 1:

Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
Example 2:

Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH"*/

class Solution {
public:
    string sortVowels(string s) {
        std::vector<char> vowels;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
                 s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                
                 vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());
        int i = 0;
        int j =0;
        while(i<s.length()){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
                 s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                    s[i] = vowels[j]; 
                    j++;
            }
            i++;
        }
        return s;   
        
    }
};


/*
415. Add Strings
Solved
Easy
Topics
Companies
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
*/

class Solution {
public:
    string add(string num1, string num2) {
        string ans;
        int index1 = num1.size() - 1, index2 = num2.size() - 1;
        int sum, carry = 0;

        while (index2 >= 0) {
            sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
            carry = sum / 10;
            char c = (sum % 10) + '0'; // Convert to character
            ans += c;
            index2--, index1--;
        }

        while (index1 >= 0) {
            sum = (num1[index1] - '0') + carry;
            carry = sum / 10;
            char c = (sum % 10) + '0'; // Convert to character
            ans += c;
            index1--;
        }

        if (carry) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end()); // Reverse the final string
        return ans;
    }

    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) {
            return add(num2, num1);
        } else {
            return add(num1, num2);
        }
    }
};

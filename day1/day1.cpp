/*409. Longest Palindrome
Easy
Topics
Companies
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.*/
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>lower(26,0),upper(26,0);
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a') lower[s[i]-'a']++;
            else upper[s[i]-'A']++;
        }

        bool odd =0;
        int ctr=0;
        for(int i=0; i<26; i++){
            if(lower[i]%2==0) ctr += lower[i];
            else ctr += lower[i]-1; odd=1;

            if(upper[i]%2==0) ctr+= upper[i];
            else ctr += upper[i]-1; odd=1;
        }
        return ctr + odd;


        
    }
};

/*1859. Sorting the Sentence
Solved
Easy
Topics
Companies
Hint
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

 

Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
Example 2:

Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.*/

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int count = 0;

        for (int index = 0; index < s.size(); ++index) {
            if (s[index] == ' ') {
                int pos = temp.back() - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
            } else {
                temp += s[index];
            }
        }
        
        // Process the last word
        int pos = temp.back() - '0';
        temp.pop_back();
        ans[pos] = temp;
        count++;

        string result;
        for (int i = 1; i <= count; ++i) {
            result += ans[i];
            if (i != count) {
                result += ' ';
            }
        }

        return result;
    }
};

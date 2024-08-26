/* abhigyan
Longest Prefix Suffix
Difficulty: HardAccuracy: 27.91%Submissions: 110K+Points: 8
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. */

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    vector <int> lps(s.size(),0);
	    int pre = 0, suf=1;
	    
	    while(suf < s.size())
	    {
	        //match
	        if(s[pre]==s[suf])
	        {
	            lps[suf] = pre + 1;
	            pre ++, suf++;
	        }
	        //not match
	        else
	        {
	            if(pre==0)
	            {
	                lps[suf]=0;
	                suf++;
	            }
	            else
	            {
	                pre = lps[pre-1];
	            }
	        }
	    }
	    return lps[s.size()-1];
	}
};

/*
Solve this question using KMP algo 
28. Find the Index of the First Occurrence in a String
Solved
Easy
Topics
Companies
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.*/

class Solution {
public:
    void lpsfind(vector<int>& lps, string s) {
        int pre = 0, suf = 1;

        while (suf < s.size()) {
            // match
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }
            // not match
            else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;  // Edge case: empty needle

        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int first = 0, second = 0;
        while (first < haystack.size()) {
            if (needle[second] == haystack[first]) {
                first++;
                second++;
            } else {
                if (second == 0) {
                    first++;
                } else {
                    second = lps[second - 1];
                }
            }

            // Check if we have found the entire needle
            if (second == needle.size()) {
                return first - second;
            }
        }

        return -1;
    }
};

// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:

// Input: "hello"
// Output: "holle"
// Example 2:

// Input: "leetcode"
// Output: "leotcede"
// Note:
// The vowels does not include the letter "y".

// Solution

class Solution {
public:
    string reverseVowels(string s) {
     unordered_set<char> ss;
        ss.insert('a');
        ss.insert('e');
        ss.insert('i');
        ss.insert('o');
        ss.insert('u');
        ss.insert('A');
        ss.insert('E');
        ss.insert('I');
        ss.insert('O');
        ss.insert('U');
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(ss.find(s[i])!=ss.end()){
                if(ss.find(s[j])!=ss.end()){
                    swap(s[i], s[j]);
                    i++;
                    j--;
                }else{
                    j--;
                }
            }else{
                i++;
            }
        }
        
        return s;
    }
};

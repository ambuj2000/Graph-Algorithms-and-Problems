// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. 
// Find the length of the shortest transformation sequence from startWord to targetWord.
// Keep the following conditions in mind:

// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList
// The second part of this problem can be found here.

// Note: If no possible way to transform sequence from startWord to targetWord return 0


Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".



class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==targetWord)  return steps;
            
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    //if it exists in the sets
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};


//T.C---N*(Wordlength *26)*log N

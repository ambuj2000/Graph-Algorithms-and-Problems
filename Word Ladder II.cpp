// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"


class Solution {
    public:
    vector<vector<string>>ans;//stores all possible paths
    void DFS(string& beginWord,string& endWord,unordered_map<string,unordered_set<string>>&adj, vector<string>&path){
        path.push_back(beginWord);//push current word
        if(beginWord==endWord){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x:adj[beginWord])
            DFS(x,endWord,adj,path);
        path.pop_back();//pop current word to backtrack
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,unordered_set<string>>adj;//adjacency list
        unordered_set<string>dict(wordList.begin(),wordList.end());//Insert wordlist in set
        
        //step-1: find min-depth using bfs
        queue<string>q;
        q.push(beginWord);//push start node
        unordered_map<string,int>visited;//value->level(depth of traversal)
        visited[beginWord]=0;//start node will always be at level 0
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            string temp=curr;
            for(int i=0;i<curr.size();i++)//for all character
            {
                for(char x='a';x<='z';x++)//try all possible 26 letters
                {
                    if(temp[i]==x)//skip if the letter is same as in original word
                        continue;
                    temp[i]=x;
                    if(dict.count(temp)>0)//check if the new word is present in wordList
                    {
                        if(visited.count(temp)==0)//check if the new word was already visited
                        {
                            visited[temp]=visited[curr]+1;// 1+level of(curr)node(here curr is parent)
                            q.push(temp);
                            adj[curr].insert(temp);
                        }
                        else if(visited[temp]==visited[curr]+1)//if already visited and new word is the child or new word is the adjacent(we should always move down)
                            adj[curr].insert(temp);
                    }
                }
                temp[i]=curr[i];//Revert back temp to curr(parent)
            }
        }
        //now after completing all the steps 1 BFS we will be making special adj list
        //Step-2: Find all possible paths at min-depth using DFS
        vector<string>path;
        DFS(beginWord,endWord,adj,path);//Find all possible paths with min-depths
        return ans;
    }
};

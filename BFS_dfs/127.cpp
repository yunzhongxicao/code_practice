/*
@File  :127.cpp
@Author:dfc
@Date  :2023/4/6  10:58
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"
#include "unordered_map"
#include "queue"
using namespace std;
int path = 0;
int result = INT32_MAX;
void dfs(unordered_map<string ,vector<string>> &graph, unordered_map<string,int> &visited,const string &current_node,string &endWord)
{
    path++;
    visited[current_node] = 1;
    if (current_node==endWord)
    {
        result = min(result,path);
        return;
    }
    vector<string> children = graph[current_node];
    for (int i = 0; i < children.size(); ++i) {
        if (visited[children[i]]==1) continue;
        dfs(graph,visited,children[i],endWord);
        path--;
        visited[children[i]]=0;
    }
}

void bfs(unordered_map<string ,vector<string>> &graph, unordered_map<string,int> &visited,const string &beginWord,string &endWord)
{
    queue<pair<string ,int>> my_queue; // 节点 和对应的节点长度
    my_queue.push(pair<string,int>(beginWord,1));
    visited[beginWord]= 1;
    while (!my_queue.empty())
    {
        string current_node = my_queue.front().first;
        path = my_queue.front().second;
        my_queue.pop();
        vector<string> children = graph[current_node];

        for (int i = 0; i < children.size(); ++i) {
            if (visited[children[i]]==1) continue;
            my_queue.push(pair<string,int>(children[i],path+1));
            visited[children[i]] = 1;
            if (children[i]==endWord)
            {
                result = path+1;
                return;
            }
        }
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> word_set(wordList.begin(),wordList.end());
    word_set.emplace(beginWord);
    unordered_map<string ,vector<string>> graph;
    for(const auto& iter:word_set)
    {
        string word = iter;
        graph[word];
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            for (int j = 0; j < 26; ++j) {
                string new_word =word;
                char ch_change = 'a'+j;
                if (ch==ch_change) continue;
                new_word[i] = ch_change;
                if (word_set.find(new_word) != word_set.end())
                    graph[word].push_back(new_word); // 如果找到了 就把这条边加进去
            }
        }
    }
    unordered_map<string,int> visited;
    for(const auto& iter:word_set)
    {
        visited[iter] = 0;
    }
    bfs(graph,visited,beginWord,endWord);
    if (result==INT32_MAX) return 0;
    return result;
}

int  main()
{
    string beg = "hit", end="cog";
    vector<string> wordlist = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength(beg,end,wordlist);
}
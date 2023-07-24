#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption, word will be in CAPS
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);

                // move next
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

// longest common prefix
/*
    arr = {"coding", "codezen", "codingninja", "coders"}
    method1:
        - take first sring
        - take char of first latter and compare form all
        - t.c O(m8n), s.c = O(1)  [more good this one]

    method2:
        - using the trie
        - insert all string into trie
        - child count == 1 then add in ans that char
        - t.c O(m8n), s.c = O(m*n) [ just for trie knowledge ]
*/

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    // for traversing all characters of first string
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];

        bool match = true;

        // for comparing ch with rest of the string
        for (int j = 1; j < n; j++)
        {
            // not match
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{
    vector<string> arr = {"coding", "codezen", "codingninja", "coders"};
    // cout << longestCommonPrefix(arr, arr.size()) << endl;

    Trie *t = new Trie('\0');

    // insert all strings into TRIE
    for (int i = 0; i < arr.size(); i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    cout << ans << endl;

    return 0;
}
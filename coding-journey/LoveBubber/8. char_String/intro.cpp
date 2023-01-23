// cpp intro.cpp -o intro && intro
#include <bits/stdc++.h>
using namespace std;

// length of string
int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

// reverse string
void reverse(char name[], int n)
{
    int s = 0, e = n - 1;
    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}

// case uppercase --> lowercase
char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    char temp = ch - 'A' + 'a';
    return temp;
}

// check palindrome
bool checkPalindrome(char name[], int n)
{
    int s = 0, e = n - 1;
    while (s <= n)
    {
        if (toLowerCase(name[s]) != toLowerCase(name[e]))
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

// check valid string
string validStringCheck(char name[], int n)
{
    string st = "";
    for (int i = 0; i < n; i++)
    {
        if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9'))
        {
            st.push_back(name[i]);
        }
    }
    cout << st << endl;
    return st;
}

char getMaxOccCharter(string s)
{
    int arr[26] = {0};

    // create an array of count of characters
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // lowercase
        int number = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else
        { // uppercase
            number = ch - 'A';
        }
        arr[number]++;
    }
    int maxi = -1, ans = -1;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    return ('a' + ans);
}

// remove all sub string occurence
string removeOccurrences(string s, string part)
{
    while ((s.length() != 0) && (s.find(part) < s.length()))
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

// Permutation in String
/*
    s1 --> character count store --> arr1[26]
    s2 --> traverse --> window (s1.length)--> store arr2[26];
    --> need to maintain window size after traverse according to length
    then compare s1 -> arr1[26] and s2 -> arr2[26]
*/
bool checkEqual(int arr1[], int arr2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0;
        }
    }
    return 1;
}

bool permutationCount(string s1, string s2)
{
    // s1 character count array
    int arr1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        arr1[index]++;
    }

    // traverse s2 string in window of size s1 length and compare
    int i = 0, windowSize = s1.length(), arr2[26] = {0};
    // running for first window only
    while (i < windowSize)
    {
        int index = s2[i] - 'a';
        arr2[index]++;
        i++;
    }

    if (checkEqual(arr1, arr2))
    {
        return 1;
    }

    // aage process karo
    while (i < s2.length())
    {
        char newChar = s2[i]; // get new element
        int index = newChar - 'a';
        arr2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        arr2[index]--;
        if (checkEqual(arr1, arr2))
        {
            return 1;
        }
        i++;
    }
    return 0;
}

/*
    if --> count = 1 --> sirf character append karna h
    else --> character with count -->
        if < 10 --> add like 1,0
        else --> add single digit

*/
int stringCompression(vector<char> &chars)
{
    int i = 0, ansIndex = 0;
    int n = chars.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }
        // yaha kab aaoge
        // ya to vector completed
        // ya to new/different character encounter

        // old character store
        chars[ansIndex++] = chars[i];

        int count = j - i;
        if (count > 1)
        {
            // converting counting into single digit and saving in answer
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}
int main()
{
    /*
    char name[20];
    cout << "enter name ";
    cin >> name;
    cout << "name " << name << endl;
    int len = getLength(name);
    cout << "length: " << len << endl;

    cout << "revse: ";
    reverse(name, len);
    cout << "name " << name << endl;
    cout << "checkPalindrome check : " << checkPalindrome(name, len) << endl;

    string str = validStringCheck(name, len);
    cout << str << endl;
    */

    string s;
    cout << "enter string: ";
    cin >> s;
    cout << getMaxOccCharter(s) << endl;

    cout << removeOccurrences(s, "abc") << endl;

    cout << permutationCount("ab", "eidaooo") << endl;

    vector<char> s;
    s.push_back('a');
    s.push_back('a');
    s.push_back('b');
    s.push_back('b');
    s.push_back('c');
    s.push_back('c');
    s.push_back('c');
    // cout << stringCompression() << endl;  // need to check
    return 0;
}

////////////////////////////////////////////////////////

// leetcode
/*
    class Solution {
private:
    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            return ch;
        }
        char temp = ch - 'A' + 'a';
        return temp;
    }
    string getValidStr(string name, int n) {
        string st = "";
        for (int i = 0; i < n; i++)
        {
            if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9'))
            {
                st.push_back(name[i]);
            }
        }
        return st;
    }

public:
    bool isPalindrome(string s) {
        string validStr = getValidStr(s, s.size());
        int start = 0, end = validStr.size() - 1;
        while(start<=end){
            if (toLowerCase(validStr[start]) != toLowerCase(validStr[end]))
            {
                return false;
            }
            start++;
            end--;
        }
        return true;

    }
};
*/

// h/w
/*
differance b/w char and string
char s[20] = "ab\0cd\0";
string str = "ab\0cd\0";
cout << s << " -> " << str << endl;

cin.getline(str, len);

custom delimeter


// h/w   imp:

Remove All Adjacent Duplicates In String
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

string compression: good questions
*/

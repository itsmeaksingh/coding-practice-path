// reverse words in a string 2
/*
i/p: "My name is AkSingh"
o/p: "yM eman si hginSkA"
*/

// h/w
#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
    string str = "My name is AkSingh";
    string s = "", ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            s += " ";
            reverse(s.begin(), s.end());
            ans += s;
            s = "";
        }
        else if (i == str.length() - 1)
        {
            s = s + str[i] + " ";
            reverse(s.begin(), s.end());
            ans += s;
        }
        else
        {
            s += str[i];
        }
    }
    ans.erase(ans.begin());
    cout << ans << " " << ans.length() << endl;
    cout << str << " " << str.length() << endl;
    return 0;
}
*/

/*
    time complexity: O(n)
*/

int main()
{
    string s = "  hello   world  ";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == ' ') && (s[i - 1] == ' ') && (i > 0) && (i < s.length() - 1))
        {
            s.erase(s[i]);
        }
    }
    cout << s << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void print_stack(stack <char> s)
{
    if (s.size() == 0)
        return;

    char c = s.top();
    s.pop();
    print_stack(s);
    cout << c;
}

stack <char> create_stack (int n, string s)
{
    stack<char> b;
    stack<char> z;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '<')
        {
            if (i + 2 < n)
            {
                if (s[i + 1] == 'B' || s[i + 1] == 'b')
                {
                    if (s[i + 2] == '>')
                    {
                        if (b.size() != 0)
                        {
                            z.push(b.top());
                            b.pop();
                        }

                        i += 2;
                    }
                } 
                else if (s[i + 1] == 'Z' || s[i + 1] == 'z')
                {
                    if (s[i + 2] == '>')
                    {
                        if (z.size() != 0)
                        {
                            b.push(z.top());
                            z.pop();
                        }

                        i += 2;
                    }
                }
                else
                {
                    b.push(s[i]);
                }
            }
        }
        else
        {   
            b.push(s[i]);
        }
    }

    return b;
}

int main ()
{
    string s;
    getline(cin, s);

    stack <char> stack = create_stack(s.size(), s);
    print_stack(stack);
    cout << endl;

    return 0;
}
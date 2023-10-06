#include <bits/stdc++.h>
using namespace std;

void extractNums(string str, vector<string> &nums)
{
    for (int i = 0; i < str.length(); i++)
    {
        bool flag = 0;
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
        {
            string ans = "";
            while (str[i] - '0' >= 0 && str[i] - '0' <= 9)
            {
                ans += str[i];
                i++;
            }
            for (int j = 0; j < ans.length(); j++)
            {
                if (ans[j] == '9')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                nums.push_back(ans);
        }
    }
    return ;
}

void takeInput(int t)
{
    for(int i=0;i<t;i++)
    {
        string str;
        getline(cin,str);
        vector<string> nums;
        extractNums(str, nums);
        for (auto it : nums)
        {
            cout << it << " ";
        }
        cout<<endl;
    }
    return;
}

int main()
{
    int t;
    cin>>t;

    takeInput(t);
}
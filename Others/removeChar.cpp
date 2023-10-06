// You are using GCC
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int freq[26] = {0};
	int capfreq[26] = {0};
    string temp = "";
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
		{
			if(freq[s[i] - 'a'] == 0){
				temp += s[i];
				freq[s[i]-'a']++;
			}
		}
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			if(capfreq[s[i] - 'A'] == 0){
				temp += s[i];
				capfreq[s[i]-'A']++;
			}
		}
    }
	for(int i = 0 ; i < 26 ; i++) cout<<freq[i]<<" ";
	cout<<endl;
    for(int i = 0 ; i < 26 ; i++) cout<<capfreq[i]<<" ";
	cout<<endl;
    
    // cout<<temp<<endl;
}
#include <iostream>
using namespace std;

int main() {
	int counts[26][26],n=0;

	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			counts[i][j] = 0;
		}
	}

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		char one = 0, two = 0, c;
		int length = 0;

		while(true)
		{
			cin.get(c);
			if(c < 'a' || c > 'z')
			{
				if(!two)
				{
					for(int i = 0; i < 26; i++)
					{
						counts[one-'a'][i]+=length;
						counts[i][one-'a']+=length;
					}
					counts[one-'a'][one-'a']-=length;
				}
				else
				{
					counts[one-'a'][two-'a']+=length;
					counts[two-'a'][one-'a']+=length;
				}
				break;
			}
			length++;
			if(!one) one = c;
			else if(one != c)
			{
				if(!two) two = c;
				else if(two != c)
				{
					while('a' <= c && 'z' >= c)
						cin.get(c);
					break;
				}
			}
		}
	}

	int words = 0;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			words = max(words,counts[i][j]);
		}
	}

	cout << words << endl;
}

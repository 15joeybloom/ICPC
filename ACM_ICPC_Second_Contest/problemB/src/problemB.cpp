#include <iostream>
using namespace std;

int main()
{
	bool on[101];

	for(int i = 0; i < 101; i++)
	{
		on[i] = false;
	}
	int n, m;

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		for(int j = 0; j < x; j++)
		{
			int temp;

			cin >> temp;

			on[temp] = true;
		}
	}

	for(int i = 1; i <= m; i++)
	{
		if(!on[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}

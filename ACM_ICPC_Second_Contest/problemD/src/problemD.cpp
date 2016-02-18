#include <iostream>
using namespace std;

int main() {
	int n=0,m=0,count=0;

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int a,b;
			cin >> a >> b;

			if(a || b) count++;
		}
	}

	cout << count << endl;
}

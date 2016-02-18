#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int n;
	cin >> n;

	int x[4],y[4];

	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	int diffX=0, diffY=0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(x[i] != x[j])
			{
				diffX = abs(x[i]-x[j]);
			}
			if(y[i] != y[j])
			{
				diffY = abs(y[i]-y[j]);
			}
		}
	}

	if(diffX && diffY)
	{
		cout << diffX*diffY << endl;
	}
	else
		cout << -1 << endl;
}

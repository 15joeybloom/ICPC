#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int g[502][502];
	int N, G;
	cin >> N;
	while(N > 0)
	{
	G = 0;

	for(int j = 0; j < N; j++)
	{
		g[0][j] = j;
		g[j][0] = j;
	}
	for(int j = 2; j <= N; j++)
	{
		g[1][j] = 1;
                G += g[1][j];
	}

	for(int i = 2; i < N; i++)
	{
		g[i][i] = i;
		for(int j = i+1; j <= N; j++)
		{
			g[i][j] = g[j%i][i];	
			G += g[i][j];
			//cout << g[i][j] << " ";
		}
		//cout << endl;
	}
	cout << G << endl;

	cin >> N;
	}
}

#include <iostream>
#include <climits>
using namespace std;

int main() {
	long long sum = 0;
	int n = 0, numOdds = 0, minOdd = INT_MAX;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		if(temp % 2)
		{
			numOdds++;
			if(minOdd > temp)
			{
				minOdd = temp;
			}
		}
	}

	if(numOdds % 2) sum -= minOdd;

	cout << sum << endl;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n=0,s=0,time=0;

	cin >> n >> s;

	for(int i = 0; i < n; i++)
	{
		int floor,timme;
		cin >> floor >> timme;

		time = max(time,max(s-floor,timme)+floor);
	}

	cout << time << endl;
}

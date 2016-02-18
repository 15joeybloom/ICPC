#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char N[105];
	char D;
	scanf("%c %s", D, N);
	while(D != '0')
	{
		int i = 0;
		bool zero = true;
		if(N[0] == D)
		{
			while(N[i] == '0' || N[i] == D)
			{
				i++;
				printf("Hey");
			}
		}
		do
		{
			if(N[i] != D)
			{
				printf("%c",N[i]);
				zero = false;
			}
			printf("HoHoHo");
			i++;
		}
		while( '0' <= N[i] && N[i] <= '9');

		if(zero) printf("0");
		
		printf("\n");

		scanf("%c %s", D, N);
	}
}

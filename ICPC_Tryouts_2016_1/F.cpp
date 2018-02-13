#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	char s[310];
	scanf("%s", s);

	int counter = 0;
	for(int i = 0; i < strlen(s); i++)
	{
		if( (i%3 == 0 && s[i] != 'P')
		|| (i%3 == 1 && s[i] != 'E')
		|| (i%3 == 2 && s[i] != 'R'))
		{
			counter++;
		}
	}
	printf("%d\n", counter);
}

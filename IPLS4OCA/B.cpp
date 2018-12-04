#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int pixels[100010];
int n, k;
int group[300];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", pixels+i);

    memset(group, -1, sizeof(group));
    for (int i = 0; i < n; i++) {
        if (group[pixels[i]] == -1) {
            //for (int k = 0; k < 20; k++) {
                //printf("%d ", group[k]);
            //}
            //printf("\n");
            //printf("Setting group for color %d\n", pixels[i]);
            int start = pixels[i];
            while (start > 0 && start + k - 1 > pixels[i] && group[start-1] == -1)
                start--;
            if (start > 0 && group[start-1] != -1 && group[start-1] + k > pixels[i])
                start = group[start-1];
            //printf("Starting at %d\n", start);
            for (int j = start; j <= pixels[i]; j++)
                group[j] = start;
        }
    }

    for (int i = 0; i < n-1; i++)
        printf("%d ", group[pixels[i]]);
    printf("%d\n", group[pixels[n-1]]);
}

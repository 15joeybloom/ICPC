#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

int uptree[100010];
int find(int x)
{
    if(uptree[x] >= 0)
        return uptree[x] = find(uptree[x]);
    return x;
}
void un(int x, int y)
{
    if(x < y)
    {
        uptree[find(x)] = uptree[find(x)]+uptree[find(y)];
        uptree[y]  = find(x);
    }
    else
        uptree[find(y)] = uptree[find(x)]+uptree[find(y)];
}

typedef pair<int, int> pii;
class node
{
public:
    int score = 0;
    set<node*> edges;
} nodes[100010];

size_t pathlen[100010];
int main()
{
    memset(uptree, -1, sizeof(uptree));
    memset(pathlen, -1, sizeof(pathlen));

    int c, l;
    scanf("%d %d", &c, &l);

    if(c == 1)
    {
        printf("0\n");
        return 0;
    }
    else if(c == 2)
    {
        printf("1\n");
        return 0;
    }

    for(int i = 0; i < l; i ++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        nodes[a].edges.insert(nodes+b);
        nodes[b].edges.insert(nodes+a);
    }

    queue<node*> bfs;
    for(int i = 0; i < c; i++)
    {
        if(nodes[i].edges.size() == 1)
            bfs.push(nodes+i);
    }

    while(!bfs.empty())
    {
        node* n = bfs.front();
        bfs.pop();

        if(n->edges.size() == 0)
            continue;

        node *parent = *n->edges.begin();
        if(parent->edges.size() == 1)
        {
            parent->score += n->score + 1;
            parent->edges.erase(n);
            n->score = 0;
        }
        else if(parent->edges.size() > 1)
        {
            parent->score = max(parent->score, n->score+1);
            n->score = 0;
            parent->edges.erase(n);
            
            if(parent->edges.size() == 1)
                bfs.push(parent);
        }
    }

    vector<int> scores;
    for(int i = 0; i < c; i++)
        if(nodes[i].score > 0)
            scores.push_back(nodes[i].score);

    sort(scores.begin(), scores.end());

    
    if(scores.size() == 0)
        printf("2\n");
    else if(scores.size() == 1)
        printf("%d\n", max(2,scores[0]));
        else
        {
    int max1 = scores[scores.size()-1], max2 = scores[scores.size()-2];
    int ans = max(1+(max1+1)/2+(max2+1)/2, max1);
    printf("%d\n", ans);
    }
}


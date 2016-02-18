#include <stdio.h>
#include <cmath>
using namespace std;

int nCr[20][20];

//double Gb, Tb, Sb, Mb;
double p, W, G, T, S, M;

/*
double game(int a, int b, int limit, double path)
{
    if(a == limit && b < limit-1) return path;
    if(b == limit && a < limit-1) return 0;

    if(a == limit-1 && b == limit-1) return path*W;

    return game(a+1,b,limit,path*p) + game(a,b+1,limit,path*(1-p));
}

double set(int a, int b, int limit, double path)
{
    if(a >= limit && a-b >= 2) return path;
    if(b >= limit && b-a >= 2) return 0;

    if(a == limit && b == limit) return path*Tb;

    return set(a+1,b,limit,path*Gb) + set(a,b+1,limit,path*(1-Gb));
}

double match(int a, int b, int limit, double path)
{
    if(a == limit) return path;
    if(b == limit) return 0;

    return match(a+1,b,limit,path*Sb) + match(a,b+1,limit,path*(1-Sb));
}
*/

int main()
{
     nCr[0][0] = 1;
     nCr[1][0] = 1;
     nCr[1][1] = 1;
     for(int n = 2; n <=12; n++)
     {
        nCr[n][0] = 1;
        for(int r = 1; r < n; r++)
        {
            nCr[n][r] = nCr[n-1][r-1]+nCr[n-1][r];
        }
        nCr[n][n] = 1;
     }

     scanf("%lf",&p);
    while(p >= 0)
    {
        W = p*p/(1-2*p*(1-p));

        G = 0;
        for(int i = 0; i <= 2; i++)
            G += nCr[6][i]*pow(p,6-i)*pow(1-p,i);
        G += nCr[6][3]*pow(p,3)*pow(1-p,3)*W;

        T = 0;
        for(int i = 0; i <= 5; i++)
            T += nCr[12][i]*pow(p,12-i)*pow(1-p,i);
        T += nCr[12][6]*pow(p,6)*pow(1-p,6)*W;

        S = 0;
        for(int i = 0; i <= 4; i++)
            S += nCr[10][i]*pow(G,10-i)*pow(1-G,i);
        S += nCr[10][5]*pow(G,5)*pow(1-G,5)*(G*G+2*G*(1-G)*T);

        M = nCr[3][0]*pow(S,3) + nCr[3][1]*pow(S,2)*(1-S);

        printf("%.12f %.12f %.12f\n",G,S,M);

        /*
        Gb = game(0,0,4,1);
        Tb = game(0,0,7,1);
        Sb = set(0,0,6,1);
        Mb = match(0,0,2,1);

        printf("%.11Lf %.11Lf %.11Lf\n",Gb,Sb,Mb);
        */

        scanf("%lf",&p);
    }
}

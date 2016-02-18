#include<cstdio>
using namespace std;
int C[20][20];
int main(){
    double p;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(i<j) C[i][j]=0;
            else if(i==j||j==0) C[i][j]=1;
            else C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    while(scanf("%lf",&p),p>=0){
        double w[3]={};
        double tb=0;
        for(int i=6;i<=12;i++){
            double t=C[12][i];
            for(int j=0;j<i;j++) t*=p;
            for(int j=i;j<12;j++) t*=1-p;
            if(i>6) tb+=t;
            else tb+=t*p*p/ (1-2*p*(1-p));
        }
        for(int i=3;i<=6;i++){
            double t=C[6][i];
            for(int j=0;j<i;j++) t*=p;
            for(int j=i;j<6;j++) t*=(1-p);
            if(i>3) w[0]+=t;
            else w[0]+=t*p*p/ (1-2*p*(1-p));
        }
        for(int i=6;i<=12;i++){
            double t=1;
            for(int j=0;j<i;j++) t*=w[0];
            for(int j=i;j<12;j++) t*=(1-w[0]);
            if(i>6) w[1]+=t*C[12][i];
            else{
                w[1]+=t*C[10][6];
                w[1]+=t*(C[12][6]-2*C[10][6])*tb;
            }
        }
        for(int i=2;i<=3;i++){
            double t=C[3][i];
            for(int j=0;j<i;j++) t*=w[1];
            for(int j=i;j<3;j++) t*=1-w[1];
            w[2]+=t;
        }
        printf("%.12f %.12f %.12f\n",w[0],w[1],w[2]);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10

float dp(int n,int * v,float mean){
    float sum = 0;
    for(int i=0;i<n;i++){
        sum+=(v[i]-mean)*(v[i]-mean);
    }
    sum/=n;
    return sqrt(sum);
}

int main(int argc, char *argv[]){
    int n,sum=0;
    n = argc==1?N:atoi(argv[1]);
    int * v = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        sum+=v[i];
    }
    printf("Soma = %d\n",sum);
    printf("Media = %.2f\n",(float)sum/n);
    printf("Desvio Padrão = %.2f\n",dp(n,v,(float)sum/n));
    free(v);
    return 0;
}
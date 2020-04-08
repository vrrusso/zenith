#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float dp(int n,int * v,float mean){
    float sum = 0;
    for(int i=0;i<n;i++){
        sum+=(v[i]-mean)*(v[i]-mean);
    }
    sum/=n;
    return sqrt(sum);
}
int main(void){
    FILE * fp_r = fopen("dados2.csv","rt");
    FILE * fp_w = fopen("resultados.csv","wt");

    if(fp_w == NULL || fp_r == NULL){
        printf("Erro na abertura");
        return -1;
    }
    int v[3];

    while(!feof(fp_r)){
        fscanf(fp_r,"%d, %d, %d",&v[0],&v[1],&v[2]);
        fprintf(fp_w,"%d, %.2f, %.2f\n",v[0]+v[1]+v[2],(float)(v[0]+v[1]+v[2])/3,dp(3,v,(float)(v[0]+v[1]+v[2])/3));
    }


    fclose(fp_r);
    fclose(fp_w);
    return 0;
}
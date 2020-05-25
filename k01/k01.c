#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val, int i,double ave);
extern double var_online(double ave,double val,int i,double square_ave);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int  i = 0;
    double ave = 0;
    double square_ave = 0;
    double ret;
    double ans;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        i = i + 1;
        ret = ave_online(val,i,ave);
        ans = var_online(ave,val,i,square_ave);
        square_ave = ((i-1)*square_ave+pow(val,2.0))/i;
        ave = ret;
        printf("[%d] var:%f, sq_ave:%f, ave:%f\n", i,ans,square_ave,ave);
    }
    double mans = i/(i-1) * ans;
    printf("標本平均：%f\n",ret);
    printf("標本分散：%f\n",ans);
    printf("母集団平均推定値；%f\n",ret);
    printf("母集団分散推定値：%f\n",mans);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    return 0;
}

double ave_online(double val,int i,double ave){
    return ave = ((i-1)*ave+val)/i;
}

double var_online(double ave,double val,int i,double square_ave){
    ave = ((i-1)*ave+val)/i;
    return square_ave - pow(ave,2.0);
}
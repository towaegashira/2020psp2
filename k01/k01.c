#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val, int i,double s_ave);
extern double var_online(double ave,double square_ave);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int  i = 0;
    double s_ave = 0;
    double s_var = 0;
    double square_ave = 0;

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
        s_ave = ave_online(val,i,s_ave);
        square_ave = ((i-1)*square_ave+pow(val,2.0))/i;
        s_var = var_online(s_ave,square_ave);
        printf("[%d] var:%f, sq_ave:%f, ave:%f\n", i,s_var,square_ave,s_ave);
    }
    double p_var = i* s_var / (i-1);
    printf("標本平均：%f\n",s_ave);
    printf("標本分散：%f\n",s_var);
    printf("母集団平均推定値；%f\n",s_ave);
    printf("母集団分散推定値：%f\n",p_var);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    return 0;
}

double ave_online(double val,int i,double s_ave){
    return s_ave = ((i-1)*s_ave+val)/i;
}

double var_online(double s_ave,double square_ave){
    return  square_ave - pow(s_ave,2.0);
}
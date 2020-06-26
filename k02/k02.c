#define _USE_MATH_DEFINES
#define A_AVE 170.8
#define A_VAR 5.43
#define B_AVE 169.7
#define B_VAR 5.5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);
extern double LikelihoodA(double p_normA,double L_A);
extern double LikelihoodB(double p_normB,double L_B);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double A_z,B_z;
    double z;
    double L_A=1.0;
    double L_B=1.0;

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
        A_z=(val-A_AVE)/A_VAR;
        B_z=(val-B_AVE)/B_VAR;
        z=A_z;
        double p_normA=p_stdnorm(z);
        L_A=LikelihoodA(p_normA,L_A);
        z=B_z;
        double p_normB=p_stdnorm(z);
        L_B=LikelihoodB(p_normB,L_B);
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L_A);
    printf("L_B: %f\n",L_B);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

double LikelihoodA(double p_normA,double L_A)
{
    return L_A=L_A*p_normA;
}
double LikelihoodB(double p_normB,double L_B)
{
    return L_B=L_B*p_normB;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  DATA
{
    int gender;
    double height;
    int ID;
};

struct DATA x [14];

int main(void)
{
    int i,id,gen;
    double hei;
    char file_1[FILENAME_MAX];
    char file_2[FILENAME_MAX];
    char data1[FILENAME_MAX];
    char data2[FILENAME_MAX];
    FILE* fp_1;
    FILE* fp_2;

    printf("Input the filename of sample height :");
    fgets(file_1,sizeof(file_1),stdin);
    file_1[strlen(file_1)-1] = '\0';
    fp_1 = fopen(file_1,"r");

    for(i=0;i<=14;i++){
        fgets(data1,sizeof(data1),fp_1);
        sscanf(data1,"%d,%lf",&gen,&hei);
        
        x[i].gender=gen;
        x[i].height=hei;
    }

    printf("Input the filename of sample ID:");
    fgets(file_2,sizeof(file_2),stdin);
    file_2[strlen(file_2)-1] = '\0';
    fp_2 = fopen(file_2,"r");
    
    for(i=1;i<=14;i++){
        fgets(data2,sizeof(data2),fp_2);
        x[i].ID=atoi(data2);
    }

    printf("Which ID`s data do you want? :");
    scanf("%d",&id);
    
    i=1;
    while(id !=x[i].ID && i<=14){
        i=i+1;
    }
    if(i==15){
        printf("No data\n");
        exit(0);
    }

    if(x[i].gender==2){
        printf("gender : female\n");
    }
    else{
        printf("gender : male\n");
    }
    
    printf("ID : %d\n",x[i].ID);
    printf("height : %.2f\n",x[i].height);
     
    return 0;   
}
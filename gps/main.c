//
//  main.c
//  gps
//
//  Created by 20161104598 on 17/6/7.
//  Copyright © 2017年 20161104598. All rights reserved.
//

#include <stdio.h>
int main()
{
    int i,j;
    int s[20];
    FILE *fp1;
    FILE *fp2;
    fp1=fopen("//Users//a20161104598//Desktop//gps//read.txt","r");
    fp2=fopen("//Users//a20161104598//Desktop//gps//save.txt","w+");
    for (i=0;i<10;i++)
    {
        fscanf(fp1,"%d\n",&s[i]);
    }
    for(j=1;j<=10-1;j++)
    {
        for(i=0;i<=10-1-j;i++)
        {
            if(s[i]>s[i+1])
            {
                s[19]=s[i];
                s[i]=s[i+1];
                s[i+1]=s[19];
            }
        }
    }
    for(i=0;i<10;i++)
    {
        fprintf(fp2,"%d ",s[i]);
    }

    for(i=0;i<10;i++)
    {
        printf("%d\n",s[i]);
    }
    
    return 0;
}


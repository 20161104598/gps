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
    char ch;
    int s[20];
    FILE *fp;
    fp=fopen("//Users//a20161104598//Desktop//gps//save.txt","r");
    ch=fgetc(fp);
    for(i=1;i<=10;i++)
    {
        while(ch!=EOF)
        {
            s[i]=ch;
            ch=fgetc(fp);
            
        }
        
    }
    fclose(fp);
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
    for(i=0;i<=10;i++)
    {
        printf("%d\n",s[i]);
    }
    
    return 0;
}


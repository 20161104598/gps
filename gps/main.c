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
    int n,i,j;
    int s[20];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&n);
    }
    for(j=1;j<=n-1;j++)
    {
        for(i=0;i<=n-1-j;i++)
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
        printf("%d",s[n]);
    }
    
    return 0;
}

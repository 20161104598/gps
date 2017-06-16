//
//  main.c
//  gps
//
//  Created by 20161104598 on 17/6/7.
//  Copyright © 2017年 20161104598. All rights reserved.
//

include <stdio.h>
int main()
{
	int i, j,n;
	int s[20];
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("read.txt", "r+"); 
	fp2 = fopen("save.txt", "w+");
	fseek(fp1, 0L, SEEK_END);
	n = ftell(fp1);
	printf("%d", n);
	fseek(fp1, 0L, SEEK_SET);
	for (i = 0; i<n; i++)
	{
		fscanf(fp1, "%d\n", &s[i]);
	}
	for (j = 1; j <= n - 1; j++)
	{
		for (i = 0; i <= n- 1 - j; i++)
		{
			if (s[i]>s[i + 1])
			{
				s[19] = s[i];
				s[i] = s[i + 1];
				s[i + 1] = s[19];
			}
		}
	}
	for (i = 0; i<n; i++)
	{
		fprintf(fp2, "%d ", s[i]);
	}

	for (i = 0; i<n; i++)
	{
		printf("%d\n", s[i]);
	}

	return 0;
}

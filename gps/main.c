//
//  main.c
//  gps
//
//  Created by 20161104598 on 17/6/7.
//  Copyright © 2017年 20161104598. All rights reserved.
//

include <stdio.h>
typedef struct GPS
{
	char UTCtime[11];	/*UTC时间*/
	char state;  /*定位状态*/
	int  lat[10];/*维度*/
	char lathem；/*维度半球*/
		int  lon[10]; /*经度*/
	char lonhem; /*经度半球*/
	char speed[10];/*速度*/
	char pitch[10];/*地面航向*/
	char UTCdate[11];	/*UTC日期*/
	struct GPS * next;
}GPS;
int main()
{
	int i, j, n;
	int s[20];
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("GPS.txt", "r+");
	fp2 = fopen("save.txt", "w+");

}
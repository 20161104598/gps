#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fr, *fp1, *fp2;
	char str1[70], str2[70], lat1[9], lat2[10], speed[6], time[7], deg[6], date[7], state[2], quantity[3], high[5];
	int i;
	fr = fopen("GPS.txt", "r+");
	fp1 = fopen("save.txt", "w+");
	fp2 = fopen("save.csv", "w+");
	while (fscanf(fr, "%s%s", str1, str2) != EOF)
	{
		printf("结果:%s\n%s\n", str1, str2);
		for (i = 0; i<8; i++)
		{
			lat1[i] = str1[i + 16];
		}
		lat1[8] = '\0';
		printf("纬度:北纬%s\n", lat1);
		fprintf(fp1, "纬度:北纬%s\n", lat1);
		fprintf(fp2, "北纬%s,", lat1);
		for (i = 0; i<9; i++)
		{
			lat2[i] = str1[i + 27];
		}
		lat2[9] = '\0';
		printf("经度:东经%s\n", lat2);
		fprintf(fp1, "经度:东经%s\n", lat2);
		fprintf(fp2, "东经%s,", lat2);
		for (i = 0; i<6; i++)
		{
			speed[i] = str1[i + 39];
		}
		speed[5] = '\0';
		printf("速率:%s节\n", speed);
		fprintf(fp1, "速率:%s节\n", speed);
		fprintf(fp2, "速率:%s节,", speed);
		for (i = 0; i<6; i++)
		{
			deg[i] = str1[i + 45];
		}
		deg[5] = '\0';
		printf("地面航向:%s度\n", deg);
		fprintf(fp1, "地面航向:%s度\n", deg);
		fprintf(fp2, "地面航向:%s度,", deg);
		for (i = 0; i<6; i++)
		{
			time[i] = str1[i + 7];
		}
		time[6] = '\0';
		printf("UTC时间:%c%c时%c%c分%c%c秒\n", time[0], time[1], time[2], time[3], time[4], time[5]);
		fprintf(fp1, "UTC时间:%c%c时%c%c分%c%c秒\n", time[0], time[1], time[2], time[3], time[4], time[5]);
		fprintf(fp2, "UTC时间:%c%c时%c%c分%c%c秒,", time[0], time[1], time[2], time[3], time[4], time[5]);
		for (i = 0; i<6; i++)
		{
			date[i] = str1[i + 51];
		}
		date[6] = '\0';
		printf("UTC日期:%c%c日%c%c月%c%c年\n", date[0], date[1], date[2], date[3], date[4], date[5]);
		fprintf(fp1, "UTC日期:%c%c日%c%c月%c%c年\n", date[0], date[1], date[2], date[3], date[4], date[5]);
		fprintf(fp2, "UTC日期:%c%c日%c%c月%c%c年,", date[0], date[1], date[2], date[3], date[4], date[5]);
		for (i = 0; i<2; i++)
		{
			state[i] = str2[i + 37];
		}
		state[1] = '\0';
		printf("GPS状态:%s\n", state);
		fprintf(fp1, "GPS状态:%s\n", state);
		fprintf(fp2, "GPS状态:%s,", state);
		for (i = 0; i<2; i++)
		{
			quantity[i] = str2[i + 39];
		}
		quantity[2] = '\0';
		printf("卫星数量:%s个\n", quantity);
		fprintf(fp1, "卫星数量:%s个\n", quantity);
		fprintf(fp2, "卫星数量:%s个,", quantity);
		for (i = 0; i<4; i++)
		{
			high[i] = str2[i + 43];
		}
		high[4] = '\0';
		printf("海拔高度:%s米\n", high);
		fprintf(fp1, "海拔高度:%s米\n", high);
		fprintf(fp2, "海拔高度:%s米,", high);
		fprintf(fp2, "\n");

	}
	fclose(fr);
	return 0;
}

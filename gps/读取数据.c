#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct GPRMC
{
	char UTCtime[11];	/*UTC时间*/
	char state;  /*定位状态*/
	char lat[10];/*维度*/
	char lathem;/*维度半球*/
	char lon[10]; /*经度*/
	char lonhem; /*经度半球*/
	char speed[10];/*速度*/
	char pitch[10];/*地面航向*/
	char UTCdate[11];	/*UTC日期*/
	char a[5];
	struct GPRMC * next;
}GPRMC;

int main(GPRMC * rmc);
int main(GPRMC * rmc)
{
	char UTCtime1[11], state1, lathem1, lonhem1, speed1[10], pitch1[10], UTCdate1[11], a1,lat1[10], lon1[10];
	GPRMC *p = rmc, *q;
	int s[20];
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("GPS.txt", "r");
	fp2 = fopen("save.txt", "w+");
	if (fp1 == NULL)
	{
		printf("打开文件错误，可能要打开的文件不存在");
		return 0;
	}
	else
	{
		printf("载入成功\n");
	}
	/*$GPRMC,013238,A,4047.533,N,11141.856,E,012.2,253.6,100517,,*1A*/
	while (fscanf(fp1, "$GPRMC,%6s,%s,%c,%c,%s,%c,%4s,%4s,%6s,,%s", UTCtime1, state1, lat1, lathem1, lon1, lonhem1, speed1, pitch1, UTCdate1, a1) != EOF)
	{
		q = (GPRMC *)malloc(sizeof(GPRMC));
		strcpy(q->UTCtime, UTCtime1);
		strcpy(q->state, state1);
		strcpy(q->lat, lat1);
		strcpy(q->lathem, lathem1);
		strcpy(q->lon, lon1);
		strcpy(q->lonhem, lonhem1);
		strcpy(q->speed, speed1);
		strcpy(q->pitch, pitch1);
		strcpy(q->UTCdate, UTCdate1);
		strcpy(q->a, a1);
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	fclose(fp1);

		printf("|数据类型|UTC时间|定位状态|纬度半球|经度|经度半球|速度|地面航向|UTC日期|\n");
		printf("|------|------|--------|\n");

		while ( p!= NULL)
		{
			printf("|GPRMC|%-6s|%-s\n", p->UTCtime, p->state, p->lat, p->lathem, p->lon, p->lonhem, p->speed, p->pitch, p->UTCdate, p->a);
			 p= p->next;
		}

}

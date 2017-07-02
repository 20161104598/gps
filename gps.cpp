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
		printf("���:%s\n%s\n", str1, str2);
		for (i = 0; i<8; i++)
		{
			lat1[i] = str1[i + 16];
		}
		lat1[8] = '\0';
		printf("γ��:��γ%s\n", lat1);
		fprintf(fp1, "γ��:��γ%s\n", lat1);
		fprintf(fp2, "��γ%s,", lat1);
		for (i = 0; i<9; i++)
		{
			lat2[i] = str1[i + 27];
		}
		lat2[9] = '\0';
		printf("����:����%s\n", lat2);
		fprintf(fp1, "����:����%s\n", lat2);
		fprintf(fp2, "����%s,", lat2);
		for (i = 0; i<6; i++)
		{
			speed[i] = str1[i + 39];
		}
		speed[5] = '\0';
		printf("����:%s��\n", speed);
		fprintf(fp1, "����:%s��\n", speed);
		fprintf(fp2, "����:%s��,", speed);
		for (i = 0; i<6; i++)
		{
			deg[i] = str1[i + 45];
		}
		deg[5] = '\0';
		printf("���溽��:%s��\n", deg);
		fprintf(fp1, "���溽��:%s��\n", deg);
		fprintf(fp2, "���溽��:%s��,", deg);
		for (i = 0; i<6; i++)
		{
			time[i] = str1[i + 7];
		}
		time[6] = '\0';
		printf("UTCʱ��:%c%cʱ%c%c��%c%c��\n", time[0], time[1], time[2], time[3], time[4], time[5]);
		fprintf(fp1, "UTCʱ��:%c%cʱ%c%c��%c%c��\n", time[0], time[1], time[2], time[3], time[4], time[5]);
		fprintf(fp2, "UTCʱ��:%c%cʱ%c%c��%c%c��,", time[0], time[1], time[2], time[3], time[4], time[5]);
		for (i = 0; i<6; i++)
		{
			date[i] = str1[i + 51];
		}
		date[6] = '\0';
		printf("UTC����:%c%c��%c%c��%c%c��\n", date[0], date[1], date[2], date[3], date[4], date[5]);
		fprintf(fp1, "UTC����:%c%c��%c%c��%c%c��\n", date[0], date[1], date[2], date[3], date[4], date[5]);
		fprintf(fp2, "UTC����:%c%c��%c%c��%c%c��,", date[0], date[1], date[2], date[3], date[4], date[5]);
		for (i = 0; i<2; i++)
		{
			state[i] = str2[i + 37];
		}
		state[1] = '\0';
		printf("GPS״̬:%s\n", state);
		fprintf(fp1, "GPS״̬:%s\n", state);
		fprintf(fp2, "GPS״̬:%s,", state);
		for (i = 0; i<2; i++)
		{
			quantity[i] = str2[i + 39];
		}
		quantity[2] = '\0';
		printf("��������:%s��\n", quantity);
		fprintf(fp1, "��������:%s��\n", quantity);
		fprintf(fp2, "��������:%s��,", quantity);
		for (i = 0; i<4; i++)
		{
			high[i] = str2[i + 43];
		}
		high[4] = '\0';
		printf("���θ߶�:%s��\n", high);
		fprintf(fp1, "���θ߶�:%s��\n", high);
		fprintf(fp2, "���θ߶�:%s��,", high);
		fprintf(fp2, "\n");

	}
	fclose(fr);
	return 0;
}

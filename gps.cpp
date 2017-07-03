#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fr, *fp1, *fp2;
	char str1[70], str2[70], lat[9], lon[10], speed[6], UTCtime[7], pitch[6], UTCdate[7], state[2], quantity[3], high[5];
	int i;
	fr = fopen("GPS.txt", "r+");
	fp1 = fopen("save.txt", "w+");
	fp2 = fopen("save.csv", "w+");
	while (fscanf(fr, "%s%s", str1, str2) != EOF)
	{
		printf("���:%s\n%s\n", str1, str2);
		for (i = 0; i<8; i++)
		{
			lat[i] = str1[i + 16];
		}
		lat[8] = '\0';
		printf("γ��:��γ%s\n", lat);
		fprintf(fp1, "γ��:��γ%s\n", lat);
		fprintf(fp2, "��γ%s,", lat);
		for (i = 0; i<9; i++)
		{
			lon[i] = str1[i + 27];
		}
		lon[9] = '\0';
		printf("����:����%s\n", lon);
		fprintf(fp1, "����:����%s\n", lon);
		fprintf(fp2, "����%s,", lon);
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
			pitch[i] = str1[i + 45];
		}
		pitch[5] = '\0';
		printf("���溽��:%s��\n", pitch);
		fprintf(fp1, "���溽��:%s��\n", pitch);
		fprintf(fp2, "���溽��:%s��,", pitch);
		for (i = 0; i<6; i++)
		{
			UTCtime[i] = str1[i + 7];
		}
		UTCtime[6] = '\0';
		printf("UTCʱ��:%c%cʱ%c%c��%c%c��\n", UTCtime[0], UTCtime[1], UTCtime[2], UTCtime[3], UTCtime[4], UTCtime[5]);
		fprintf(fp1, "UTCʱ��:%c%cʱ%c%c��%c%c��\n", UTCtime[0], UTCtime[1], UTCtime[2], UTCtime[3], UTCtime[4], UTCtime[5]);
		fprintf(fp2, "UTCʱ��:%c%cʱ%c%c��%c%c��,", UTCtime[0], UTCtime[1], UTCtime[2], UTCtime[3], UTCtime[4], UTCtime[5]);
		for (i = 0; i<6; i++)
		{
			UTCdate[i] = str1[i + 51];
		}
		UTCdate[6] = '\0';
		printf("UTC����:%c%c��%c%c��%c%c��\n", UTCdate[0], UTCdate[1], UTCdate[2], UTCdate[3], UTCdate[4], UTCdate[5]);
		fprintf(fp1, "UTC����:%c%c��%c%c��%c%c��\n", UTCdate[0], UTCdate[1], UTCdate[2], UTCdate[3], UTCdate[4], UTCdate[5]);
		fprintf(fp2, "UTC����:%c%c��%c%c��%c%c��,", UTCdate[0], UTCdate[1], UTCdate[2], UTCdate[3], UTCdate[4], UTCdate[5]);
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


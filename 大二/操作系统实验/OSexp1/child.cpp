#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
	printf("�ӽ�������!\n");
	Sleep(500);
	char a[20] = {0};
	int num;
	FILE *p;
	if ((p = fopen("1.txt", "w")) == NULL) {         //�����ļ���ʧ�ܱ���
		printf("Failed to read file!");
		return 0;
	} else {
		printf("�Ѿ������ļ�!\n");              //д���ļ�
		Sleep(500);
		fwrite("XiDian University", 1, strlen("XiDian University"), p);
		fclose(p);
		printf("�Ѿ�д������!\n");
		Sleep(500);
		p = fopen("1.txt", "r");                    //��ȡ�ļ����ݲ����
		num = fread(a, 1, 20, p);
		fclose(p);
		printf("Successfully read %d words:\n", num);
		puts(a);
	}

	Sleep(1000);
	return 1;
}
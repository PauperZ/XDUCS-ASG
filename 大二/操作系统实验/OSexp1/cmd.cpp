#include <stdio.h>
#include <windows.h>

int main() {
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION pi;
	BOOL b = CreateProcess("C:\\Users\\Administrator\\Desktop\\OSexp\\child.exe", NULL, NULL, NULL, FALSE,    //��������
	                       CREATE_NEW_CONSOLE,
	                       NULL, NULL, &si, &pi);
	if (!b) {                //����ʧ�ܱ���
		printf("Failed to create process!");
		return 0;
	} else {
		int i, sum = 0;
		char a[20] = {0};
		FILE *p;
		for (i = 1; i <= 100; i++) {              //ִ�м���
			sum += i;
			printf("sum = %d\n", sum);
			Sleep(10);
		}
		WaitForSingleObject(pi.hProcess, INFINITE);        //�ȴ��ӽ���ִ��
		p = fopen("1.txt", "r");                  //�����ӽ����ļ������
		int num = fread(a, 1, 20, p);
		fclose(p);
		printf("Successfully read %d words:\n", num);
		puts(a);
		Sleep(500);
		printf("�ӽ��̽���");
	}

	return 0;
}
#include <stdio.h>
#include <windows.h>

static int count = 10;
DWORD WINAPI ThreadProc(LPVOID lpParameter) {        //�̹߳��췽��
	printf("���߳�����!\n");
	for (count = 1; count <= 5; count++) {
		printf("�߳�count = %d\n", count);
	}
	printf("�̵߳ȴ�������\n");
	Sleep(5000);
	printf("���߳̽���!\n");

	return 0;
}

int main() {
	printf("��������!\n����count = %d\n", count);
	HANDLE pthread;
	pthread = CreateThread( NULL, 0, ThreadProc, NULL, 0, NULL); //�����߳�
	WaitForSingleObject(pthread, INFINITE);        //�ȴ��߳�ִ��
	printf("���̽���");

	return 0;
}

#include <stdio.h>
#include <windows.h>
int count = 0;
HANDLE hempty, hproduct;

DWORD WINAPI ThreadProc(LPVOID lpParameter) {        //�������̹߳��췽��
	printf("Create worker thread!\n");
	while (1) {
		WaitForSingleObject(hempty, INFINITE);          //�����п��ź������п��п����������
		Sleep(100);
		count++;
		printf("producer has producerd %d products all together\n", count);
		ReleaseSemaphore(hproduct, 1, NULL);   //ÿ������һ����Ʒ����Ʒ�������в�Ʒ�����ͼ�1
	}

	return 0;
}

int main() {
	hempty = CreateSemaphore(NULL, 10, 10, "empty");   //���п��ź���
	hproduct = CreateSemaphore(NULL, 0, 10, "product");   //��Ʒ���ź���
	HANDLE hThread1;
	hThread1 = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);      //�����������߳�
	WaitForSingleObject(hThread1, INFINITE);    //�ȴ��������߳̽���
	CloseHandle(hThread1);   //�رվ��

	return 1;
}
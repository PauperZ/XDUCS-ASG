#include <stdio.h>
#include <windows.h>
#include <process.h>

int main() {
	HANDLE p;
	char name[] = {"tql"};
	p = CreateEvent(NULL, false, false, name);
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION pi;
	BOOL b = CreateProcess("C:\\Users\\Administrator\\Desktop\\OSexp3\\child.exe", NULL, NULL, NULL, FALSE,    //��������
	                       CREATE_NEW_CONSOLE,
	                       NULL, NULL, &si, &pi);
	if (!b) {                //����ʧ�ܱ���
		printf("Failed to create process!");
		return 0;
	}
	printf("Wait for event.\n");
	DWORD s;
	s = WaitForSingleObject(p, 5000);         //�ȴ���ȡ�ź�״̬
	if (s == WAIT_TIMEOUT) {                 //�ȴ���ʱ����
		printf("Failed to wait for the signal!");
		return 1;
	}
	printf("Get the event.\n");          //�źż���
	printf("Press any key to continue.");
	getchar();

	return 0;
}
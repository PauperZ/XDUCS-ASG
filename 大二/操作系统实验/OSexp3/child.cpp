#include <stdio.h>
#include <windows.h>
#include <process.h>

int main() {
	char c;
	HANDLE p;
	p = OpenEvent( EVENT_ALL_ACCESS, FALSE, "tql" );          //��ȡ�������¼����
	Sleep(1000);
	printf("Signal the event to Parent?[y\\n]\n");
	scanf("%c", &c);
	if (c == 'y')          //�����ź�
		SetEvent(p);
	else                   //�����ź�Ϊδ����״̬
		ResetEvent(p);
	Sleep(1000);

	return 0;
}
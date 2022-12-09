#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int ClipboardInputText(LPWSTR buffer);
int ClipboardOutptText();
TCHAR* ClipboardOutptText2();
LPSTR Data;
DWORD str;

int ClipboardInputText(LPWSTR buffer)
{
	DWORD mess;
	HANDLE hMen; // ���������� ���������� ������� ������ 
	mess = wcslen(buffer) + 1; 
	hMen = GlobalAlloc(GMEM_MOVEABLE, mess * sizeof(LPWSTR));// Global - �������� ������ � ���������� ������� ���������, ����� ������ ���� ����� �� ��������� ���������
	//memcpy - ������� ����������� � ������
	// GlobalLock - ��������� ���������� ������
	memcpy(GlobalLock(hMen), buffer, mess * sizeof(LPWSTR));
	GlobalUnlock(hMen); // ������ ���������� ��������� 
	OpenClipboard(0); // ��������� ����� ������ 
	EmptyClipboard(); // ������ ������ ������
	//CF_UNICODETEXT - ��� ������ (������ ����� - ���), hMen - ��� ���������� (���������� ����� ���������� ������� ������ �������)
	SetClipboardData(CF_UNICODETEXT, hMen);
	CloseClipboard(); // ������� �����, ������ ��� ��������� ��� ������ ����������
	return 0;
}

int ClipboardOutptText() // �� ������ ���� ���������� � ����� ���������� ���������� ������� ������
{
	LPWSTR Mess = NULL; // ���������, ������� ��� ������ � MessageBox
	OpenClipboard(NULL); // ������� ����� ������ - ��� NULL � ������ �� ���������
	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
	Mess = (LPWSTR)GlobalLock(hClipboardData); // ������� �� ����������� ������� ������, �������� ��� � � ������ (LPWSTR) � ��������� � ������ Messege
	GlobalUnlock(hClipboardData);
	CloseClipboard();// ������ ����� ��������� ��� ������ ����������
	MessageBox(NULL, Mess, L"���������� ������", MB_OK);
	return 0;
}

TCHAR* ClipboardOutptText2()
{
	TCHAR* Mess = NULL;
	OpenClipboard(NULL);
	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
	Mess = (TCHAR*)GlobalLock(hClipboardData);
	GlobalUnlock(hClipboardData);
	CloseClipboard();
	return Mess;
}

int main()
{
	/*system("chcp 1251 > null");*/
	////����� ������� ����� ����������� word � ���������� WinAPI
	//LPWSTR Message = L"����� ��� ������ � ����� � ����������� ����������� � Word"; 
	//ClipboardInputText(Message);
	//ClipboardOutptText();

	////������ ����������� �� ���������� ������ ������
	//while (TRUE) 
	//{
	//	LPSTR Data = ClipboardOutptText2(); // ��������� ���� - ����� �������
	//	TCHAR Alert[] = L"��������� ��������� ���� ��� ����������� ������: "; // ������ ������ ��� MessageBox
	//	TCHAR third[512]; // ����������� �� ����� �������� - 1 ��
	//	swprintf(third, sizeof third, L"%s%s", Alert, Data);
	//	if (*Data != 0) // ���� �� ������ ������
	//	{
	//		MessageBox(NULL, &third, L"��������! ���������!", MB_OK | MB_ICONASTERISK);
	//		ClipboardInputText(""); // ������� ������
	//	}
	//	Sleep(1000); 
	//}


	
	//��� ����������� ����� � ��������� ����� ������ �������� � ����� �� ��������� ��������
	while (TRUE)
	{
		Data = ClipboardOutptText2();
		str = wcslen((LPWSTR)Data) + 1;
		// 0 1 2 3 4 5 6 7 8 9 		 
		
		if (*Data != NULL) // ���� �� ������ ������
		{
			for (DWORD i = 0; i < str; i++)
			{
				switch (Data[i])
				{
				case '0':
					ClipboardInputText(L"����");
					break;
				case '1':
					ClipboardInputText(L"����");
					break;
				case '2':
					ClipboardInputText(L"���");
					break;
				case '3':
					ClipboardInputText(L"���");
					break;
				case '4':
					ClipboardInputText(L"������");
					break;
				case '5':
					ClipboardInputText(L"����");
					break;
				case '6':
					ClipboardInputText(L"�����");
					break;
				case '7':
					ClipboardInputText(L"����");
					break;
				case '8':
					ClipboardInputText(L"������");
					break;
				case '9':
					ClipboardInputText(L"������");
					break;
				default:
					ClipboardInputText(Data);
					break;
				}
			}

		}
		Sleep(1000);
	}


	return 0;
}





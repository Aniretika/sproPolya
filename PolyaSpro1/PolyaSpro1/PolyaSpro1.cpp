
#include <windows.h> // підключення бібліотеки з функціями API
#include "Resource.h"

// Глобальні змінні:
HINSTANCE hInst; 	//Дескриптор програми	
LPCTSTR szWindowClass = "QWERTY";
LPCTSTR szTitle = "POLINA";

// Попередній опис функцій

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
BOOL CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);  //объявляем прототип функции процедуры диалогового окна 
BOOL CALLBACK AboutDlgProc1(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc2(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc3(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


// hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// Основна програма 
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	// Реєстр
	MyRegisterClass(hInstance);

	// Створення вікна програми
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	// Цикл обробки повідомлень
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_NOCLOSE;   //стиль вікна
	wcex.lpfnWndProc = (WNDPROC)WndProc;   //віконна процедура
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;    //дескриптор програми
	wcex.hIcon = LoadIcon(NULL, IDI_QUESTION);   //визначення іконки
	wcex.hCursor = LoadCursor(NULL, IDC_SIZE);  //визначення курсору
	wcex.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //установка фону
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);//визначення меню
	wcex.lpszClassName = szWindowClass;   //ім’я класу
	wcex.hIconSm = NULL;

	return RegisterClassEx(&wcex);    //реєстрація класу вікна
}

// FUNCTION: InitInstance (HANDLE,BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; //зберігає дескриптор додатка в змінній hInst
	hWnd = CreateWindow(szWindowClass,  // ім’я класу вік
		szTitle,     // назва програми
		WS_MINIMIZEBOX | WS_HSCROLL | WS_SYSMENU,// стиль вікна
		50,    // положення по Х 
		90,   // положення по Y 
		400,    // розмір по Хn
		500,    // розмір по Y
		NULL,      // дескриптор батьківського вікна 
		NULL,      // дескриптор меню вікна
		hInstance,     // дескриптор програми
		NULL);     // параметри створення.

	if (!hWnd)  //Якщо вікно не творилось, функція повертає FALSE
	{
		return FALSE;
	}
	ShowWindow(hWnd, SW_SHOWMINIMIZED);  //Показати вікно
	UpdateWindow(hWnd);     //Оновити вікно
	return TRUE;
}
BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  // 1 діалогове вікно
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg, 0);
			return TRUE;
		case IDCANCEL2:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG2), 0, (AboutDlgProc1), 0);
			break;
		case IDCANCEL:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG3), 0, (AboutDlgProc2), 0);
			break;
		}
	}
	return FALSE;
}//реализация диалогового окна


BOOL CALLBACK AboutDlgProc1(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  // докладніше
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg, 0);
			return TRUE;
			break;
		}
	}
	return FALSE;
}
BOOL CALLBACK AboutDlgProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  //  запитання
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			PostQuitMessage(0);
			break;
		case IDCANCEL3:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}
// FUNCTION: WndProc (HWND, unsigned, WORD, LONG)
// Віконна процедура. Приймає і обробляє всі повідомлення, що приходять в додаток


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	
	switch (message)
	{
	case WM_CREATE:     //Повідомлення приходить при створенні вік-на
		break;
	/*case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_CURSOR1:
			SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1)));
			break;
		}
*/
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_CHANGE_CURSORE:
			SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1)));
			break;
		case ID_CHANGE_CURSORE2:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR2)));
			break;
		case ID_ICON_ICON1:
			SetClassLong(hWnd, GCLP_HICON, (LONG)LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)));
			break;
		case ID_ICON_ICON2:
			SetClassLong(hWnd, GCLP_HICON, (LONG)LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON2)));
			break;
		//case ID_CHANGE_CURSOR3:
		//	SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR3)));
		//	break;
		//case ID_ABOUTUS_ABOUTSTUDENTS:
		//	DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, (AboutDlgProc), 0);//создает диалговое окно, когда нажимаем на студентов
		//	
		}

	
	case WM_PAINT:     //Перемалювати вікно
		hdc = BeginPaint(hWnd, &ps);  //Почати графічний вивід 
		GetClientRect(hWnd, &rt);   //Область вікна для малювання
		DrawText(hdc, "н6ек", -1, &rt, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hWnd, &ps);   //Закінчити графічний вивід 
		break;
	case WM_LBUTTONDBLCLK:
		MessageBox(hWnd, "А ось і я!", "HNURE", MB_OK);
		break;
	case WM_DESTROY:     //Завершення роботи
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
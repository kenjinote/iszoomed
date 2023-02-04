#pragma comment(linker, "/opt:nowin98")
#include <windows.h>

#define IDU_BUTTON1 100

CHAR szClassName[]="window";

LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
    switch(msg){
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDU_BUTTON1:
					if(IsZoomed(hWnd))MessageBox(hWnd,"Å‘å‰»‚µ‚Ä‚¢‚Ü‚·",szClassName,0);
					else MessageBox(hWnd,"Å‘å‰»‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ",szClassName,0);
					break;
			}
			break;
		case WM_CREATE:
			CreateWindow("BUTTON","Å‘å‰»‚ð”»’è",
						 WS_CHILD|WS_VISIBLE,
						 10,10,200,30,
						 hWnd,
						 (HMENU)IDU_BUTTON1,
						 ((LPCREATESTRUCT)lParam)->hInstance,
						 NULL);
			break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return(DefWindowProc(hWnd,msg,wParam,lParam));
    }
    return (0L);
}

int WINAPI WinMain(HINSTANCE hinst,HINSTANCE hPreInst,
                   LPSTR pCmdLine,int nCmdShow)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS wndclass;
    if(!hPreInst){
        wndclass.style=CS_HREDRAW|CS_VREDRAW;
        wndclass.lpfnWndProc=WndProc;
        wndclass.cbClsExtra=0;
        wndclass.cbWndExtra=0;
        wndclass.hInstance =hinst;
        wndclass.hIcon=NULL;
        wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
        wndclass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
        wndclass.lpszMenuName=NULL;
        wndclass.lpszClassName=szClassName;
        if(!RegisterClass(&wndclass))
            return FALSE;
    }
    hWnd=CreateWindow(szClassName,
        "ƒ^ƒCƒgƒ‹",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hinst,
        NULL);
    ShowWindow(hWnd,nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}



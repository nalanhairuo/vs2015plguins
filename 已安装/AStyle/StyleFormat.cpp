/***********************************************************************
* 版权所有 (C)2017,WQH
*
* 文件名称：
* 内容摘要：
* 其它说明：
* 当前版本：
* 作   者：
* 完成日期：$now$
* //TODO //FIXME
*修改记录1://修改历史记录，包括修改日期、版本号、修改人及修改内容等
*  修改日期：
*  版本号：
*  修改人：
*  修改内容：
***********************************************************************/
//       File Include Section
//***********************************************************************
//#include <...> //标准库
//#include "..." //非标准库
#include <stdio.h>
#include <windows.h>
#include <string.h>


//***********************************************************************
//       Macro Define Section
//***********************************************************************
//#define MACRO_NAME 0x24
//#define MACRO_FUNC ({...})
//#define MAX(a,b) ((a)>(b) ?(a):(b))
//#define TRACE(var,fmt) printf("TRACE: " #var " = " #fmt "\n",var)
//#define Trace(var) printf("TRACE: " #var " =  %d \n",var)
//#define Fn_apply(type,fn,...){\
//void *stopper_for_apply = (int[]){0};\
//type **list_for_apply = (type*[]){__VA_ARGS__,stopper_for_apply};\
//for(int i = 0;list_for_apply[i] != stopper_for_apply;i++)\
//        fn(list_for_apply[i]);\
//}
//
//#define Free_all(...) Fn_apply(void,free,__VA_ARGS__);
//***********************************************************************
//       Structure Define Section
//***********************************************************************
// typedef struct
// {
//
// }SELF_DEFINE_TYPE;

//***********************************************************************
//       Global Variable Declare Section
//***********************************************************************
//extern int gGlobalVar;


//***********************************************************************
//       File Static Variable Define Section
//***********************************************************************
//static unsigned int x;
//***********************************************************************
//       Prototype Declare Section
//***********************************************************************
//void Function(...);


int main(int argc, char *argv[])
{
        int *a;
        int* b;
        char szModuleFileName[128];
        GetModuleFileNameA(NULL, szModuleFileName, 128);
        printf("%s\n", szModuleFileName);
        printf("%s\n", argv[0]);
        char *name;
        name = strrchr(argv[0], 0x5C);

        for (int i = 0; i < strlen(name); i++)
        {
                name[i] = name[i + 1];        //每个字符向前移一位，去掉"\"
        }


        switch ()
        {
                case :
                {
                        break;
                }

                default:
                {
                        break;
                }
        }

        printf("%s\n", name);

        return 0;
}

//VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR *lpszArgv)
//{
//      g_status.dwCurrentState = SERVICE_STOPPED;
//      g_status.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE;
//      g_status.dwWin32ExitCode = 0;
//      g_status.dwCheckPoint = 0;
//      g_status.dwWaitHint = 0;
//      g_status.dwServiceSpecificExitCode = 0;
//      g_status.dwServiceType = SERVICE_WIN32;
//
//      g_ServiceStatusHandle = RegisterServiceCtrlHandler(SERVICE_NAME,
//              ServiceHandler);
//      if (g_ServiceStatusHandle == 0) {
//              return;
//      }
//
//      g_status.dwCurrentState = SERVICE_START_PENDING;
//      SetServiceStatus(g_ServiceStatusHandle, &g_status);
//
//      g_stopEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
//
//      g_status.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN| SERVICE_ACCEPT_PAUSE_CONTINUE;
//      g_status.dwCurrentState = SERVICE_RUNNING;
//      Sleep(60000);
//      SetServiceStatus(g_ServiceStatusHandle, &g_status);
//      //app running
//      bool ret=true;
//      //ret=mgr.initLines("127.0.0.1","root","redhat","szbp");
//      do
//      {
//              Beep(1000, 100);
//              Sleep(5000);
//              if(ret==false)
//              {
//                      LogEvent(_T("读取数据库失败!!!!\r\n"));
//                      break;
//              }
//              else
//              {
//               //
//               LogEvent(_T("开始写入数据"));
//               sendReport();
//               LogEvent(_T("循环一次数据完成"));
//              }
//      } while (WaitForSingleObject(g_stopEvent, 5000) == WAIT_TIMEOUT);
//       LogEvent(_T("服务停止"));
//      g_status.dwCurrentState = SERVICE_STOP_PENDING;
//      SetServiceStatus(g_ServiceStatusHandle, &g_status);
//
//      CloseHandle(g_stopEvent);
//
//      g_status.dwCurrentState = SERVICE_STOPPED;
//      g_status.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE;
//      SetServiceStatus(g_ServiceStatusHandle, &g_status);
//}
//
//
// 功能:这些代码用来实现一个服务的功能,这个服务可以用来监视本机的可用物理内存(以M为单位)
// 每5秒记录一次,并将结果存放在C:\MemoryStatus.txt这个文本文件中

#pragma warning(disable:4996)
#include "MemoryStatus.h"
SERVICE_STATUS          ServiceStatus; // 服务状态
SERVICE_STATUS_HANDLE   hStatus;       // 服务状态句柄
LPSTR SERVICE_NAME = "MemoryStatus";
//-------------------------写信息字符串到磁盘文件----------------------------------//
int WriteToLog(char* str)
{
        FILE* log;
        log = fopen(LOGFILE, "a+");
        // Opens for reading and appending;
        // creates the file first if it doesn’t exist.

        if (log == NULL)
        {

                return -1;
        }

        fprintf(log, "%s\n", str);
        fclose(log);
        return 0;
}

int InitService()
{
        // 记录服务启动的时间
        char startTime[100] = { 0 };
        SYSTEMTIME systemTime;
        GetLocalTime(&systemTime);
        wsprintfA(startTime, "Monitoring started at :%d年%d月%d日 %d时:%d分:%d秒"
                  , systemTime.wYear, systemTime.wMonth, systemTime.wDay
                  , systemTime.wHour, systemTime.wMinute, systemTime.wSecond);

        int result;
        result = WriteToLog(startTime);
        return (result);
}

void RunService(void)
{
        //  一个程序可能包含若干个服务。每一个服务都必须列于专门的分派表中
        //  （为此该程序定义了一个 ServiceTable 结构数组）。
        //  这个表中的每一项都要在 SERVICE_TABLE_ENTRY 结构之中。它有两个域：
        //  lpServiceName: 指向表示服务名称字符串的指针；当定义了多个服务时，那么这个域必须指定；
        //  lpServiceProc: 指向服务主函数的指针（服务入口点）；
        /*SERVICE_TABLE_ENTRY dispatchTable[] = { { SERVICE_NAME, ServiceMain }, {
            NULL, NULL }, };
        StartServiceCtrlDispatcher(dispatchTable);*/
        SERVICE_TABLE_ENTRY ServiceTable[2];
        ServiceTable[0].lpServiceName = SERVICE_NAME;
        ServiceTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)ServiceMain;

        ServiceTable[1].lpServiceName = NULL;
        ServiceTable[1].lpServiceProc = NULL;
        //  启动服务的控制分派机线程
        //  SCM启动一个服务程序之后，它会等待该程序的主线程去调StartServiceCtrlDispatcher。
        //  如果那个函数在两分钟内没有被调用，SCM将会认为这个服务有问题，
        //  并调用TerminateProcess去杀死这个进程。
        //  这就要求你的主线程要尽可能快的调用StartServiceCtrlDispatcher。
        //  main()调用StartServiceCtrlDispatcher()并挂起
        //  因为一个服务进程可以支持多个服务，对于每个服务
        //  StartServiceCtrlDispatcher()产生一个线程来执行该服务

        StartServiceCtrlDispatcher(ServiceTable);

}

//ServiceMain要迅速完成自身工作，首先是必不可少的两项工作，
//1、第一项是调用RegisterServiceCtrlHandler函数去通知SCM它的ControlHandler回调函数的地址
//2、在RegisterServiceCtrlHandler函数返回后，ServiceMain线程要立即用SetServiceStatus
//告诉SCM服务正在继续初始化
//---------------------------------服务主函数------------------------------------//
void ServiceMain(int argc, char** argv)
{
        int error;

        // dwServiceType指示服务类型，创建 Win32 服务。赋值 SERVICE_WIN32
        // 这个成员的值在你的服务的生存期内绝对不应该改变。
        ServiceStatus.dwServiceType = SERVICE_WIN32;

        //dwCurrentState是这个结构中最重要的成员，它将告诉SCM你的服务的现行状态。
        //为了报告服务仍在初始化，应该把这个成员设置成SERVICE_START_PENDING。
        ServiceStatus.dwCurrentState = SERVICE_START_PENDING;

        //dwControlsAccepted指明服务愿意接受什么样的控制通知
        ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
        //dwWin32ExitCode 和 dwServiceSpecificExitCode：
        //这两个域在你终止服务并报告退出细节时很有用。
        //初始化服务时并不退出，因此，它们的值为 0；
        ServiceStatus.dwWin32ExitCode = 0;
        ServiceStatus.dwServiceSpecificExitCode = 0;
        //dwCheckPoint 和 dwWaitHint：这两个域表示初始化某个
        //服务进程时要30秒以上。本文例子服务的初始化过程很短，
        //所以这两个域的值都为 0。
        ServiceStatus.dwCheckPoint = 0;
        ServiceStatus.dwWaitHint = 0;

        //  注册处理服务控制请求的函数
        //  调用RegisterServiceCtrlHandler函数去通知SCM它的ControlHandler回调函数的地址：
        //  第一个参数指明你正在建立的ControlHandler是为哪一个服务所用，
        //  第二个参数是ControlHandler函数的地址。lpServiceName必须和在SERVICE_TABLE_ENTRY里面被
        //  初始化的服务的名字相匹配。
        hStatus
                = RegisterServiceCtrlHandlerA(SERVICE_NAME, (LPHANDLER_FUNCTION)ControlHandler);

        if (hStatus == (SERVICE_STATUS_HANDLE)0)
        {
                // Registering Control Handler failed
                return;
        }

        // Initialize Service
        error = InitService();

        if (error)
        {
                // 初始化失败，终止服务
                ServiceStatus.dwCurrentState = SERVICE_STOPPED;
                ServiceStatus.dwWin32ExitCode = -1;
                // 退出 ServiceMain
                SetServiceStatus(hStatus, &ServiceStatus); //服务的句柄,SERVICE_STATUS结构的地址
                return;
        }

        // 在服务的所有初始化都完成之后，服务调用SetServiceStatus指明SERVICE_RUNNING，
        // 在那一刻服务已经开始运行。
        // 向 SCM 报告运行状态
        ServiceStatus.dwCurrentState = SERVICE_RUNNING;
        SetServiceStatus(hStatus, &ServiceStatus);


        MEMORYSTATUS memory;

        // 服务的循环
        while (ServiceStatus.dwCurrentState == SERVICE_RUNNING)

        {
                GlobalMemoryStatus(&memory);

                char runningState[100] = { 0 };
                SYSTEMTIME systemTime;
                GetLocalTime(&systemTime);
                wsprintfA(runningState, "%d年%d月%d日 %d时:%d分:%d秒 可用物理内存:%d(M)",
                          systemTime.wYear, systemTime.wMonth, systemTime.wDay,
                          systemTime.wHour, systemTime.wMinute, systemTime.wSecond
                          , memory.dwAvailPhys / (1024 * 1024));

                int result = WriteToLog(runningState);

                if (result)
                {
                        ServiceStatus.dwCurrentState = SERVICE_STOPPED;
                        ServiceStatus.dwWin32ExitCode = -1;
                        SetServiceStatus(hStatus, &ServiceStatus);
                        return;
                }

                Sleep(SLEEP_TIME);
        }

        return;
}


//----------------------------ControlHandler处理服务控制请求----------------------------//
void ControlHandler(DWORD request)
{

        SYSTEMTIME systemTime;
        GetLocalTime(&systemTime);
        char stopTime[100] = { 0 };
        char shutDownTime[100] = { 0 };

        switch (request)
        {
                case SERVICE_CONTROL_STOP: // 用户停止了服务
                {
                        wsprintfA(stopTime, "Service stopped at :%d年%d月%d日 %d时:%d分:%d秒",
                                  systemTime.wYear, systemTime.wMonth, systemTime.wDay,
                                  systemTime.wHour, systemTime.wMinute, systemTime.wSecond);

                        WriteToLog(stopTime);
                        ServiceStatus.dwWin32ExitCode = 0;
                        ServiceStatus.dwCurrentState = SERVICE_STOPPED;
                        SetServiceStatus(hStatus, &ServiceStatus);
                        return;
                }

                case SERVICE_CONTROL_SHUTDOWN:  // 用户关机
                {
                        wsprintfA(shutDownTime, "Computer shutdowned at :%d年%d月%d日 %d时:%d分:%d秒",
                                  systemTime.wYear, systemTime.wMonth, systemTime.wDay,
                                  systemTime.wHour, systemTime.wMinute, systemTime.wSecond);

                        WriteToLog(shutDownTime);
                        ServiceStatus.dwWin32ExitCode = 0;
                        ServiceStatus.dwCurrentState = SERVICE_STOPPED;
                        SetServiceStatus(hStatus, &ServiceStatus);
                        return;
                }

                case SERVICE_CONTROL_PAUSE:
                        break;

                case SERVICE_CONTROL_CONTINUE:
                        break;

                case SERVICE_CONTROL_INTERROGATE:
                        break;

                default:
                        break;
        }

        // 向SCM报告当前用户的状态
        SetServiceStatus(hStatus, &ServiceStatus);
        return;
}

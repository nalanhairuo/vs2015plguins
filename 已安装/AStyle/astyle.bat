REM ��������Ŀ¼�е�����C++�ļ���Astyle���д�����������
REM ����Astyle����λ�úͲ���
@echo off
set astyle="astyle.exe"
REM ѭ������Ŀ¼
for /r . %%a in (*.cpp;*.c) do %astyle% --style=allman --indent=spaces=4 --attach-extern-c --attach-closing-while --indent-modifiers --indent-switches --indent-cases --indent-namespaces --indent-preproc-define --indent-col1-comments --break-blocks=all --pad-oper --pad-comma --pad-header --unpad-paren --break-closing-braces --break-one-line-headers --add-brackets --convert-tabs --mode=c  "%%a"
for /r . %%a in (*.hpp;*.h) do %astyle% --style=allman --indent=spaces=4 --attach-extern-c --attach-closing-while --indent-modifiers --indent-switches --indent-cases --indent-namespaces --indent-preproc-define --indent-col1-comments --break-blocks=all --pad-oper --pad-comma --pad-header --unpad-paren --break-closing-braces --break-one-line-headers --add-brackets --convert-tabs --mode=c  "%%a"
REM ɾ�����е�astyle�����ļ�
for /r . %%a in (*.orig) do del "%%a"
pause
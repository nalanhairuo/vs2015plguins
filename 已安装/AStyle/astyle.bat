REM 批量将本目录中的所有C++文件用Astyle进行代码美化操作
REM 设置Astyle命令位置和参数
@echo off
set astyle="astyle.exe"
REM 循环遍历目录
for /r . %%a in (*.cpp;*.c) do %astyle% --style=allman --indent=spaces=4 --attach-extern-c --attach-closing-while --indent-modifiers --indent-switches --indent-cases --indent-namespaces --indent-preproc-define --indent-col1-comments --break-blocks=all --pad-oper --pad-comma --pad-header --unpad-paren --break-closing-braces --break-one-line-headers --add-brackets --convert-tabs --mode=c  "%%a"
for /r . %%a in (*.hpp;*.h) do %astyle% --style=allman --indent=spaces=4 --attach-extern-c --attach-closing-while --indent-modifiers --indent-switches --indent-cases --indent-namespaces --indent-preproc-define --indent-col1-comments --break-blocks=all --pad-oper --pad-comma --pad-header --unpad-paren --break-closing-braces --break-one-line-headers --add-brackets --convert-tabs --mode=c  "%%a"
REM 删除所有的astyle生成文件
for /r . %%a in (*.orig) do del "%%a"
pause
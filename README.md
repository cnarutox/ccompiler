# CComplier
## 基于MIPS汇编的C语言编译器
- ### Lex Yacc C++ 实现
> ##### 进入项目根目录
>> ```cd ccompiler```
> ##### 在Windows环境下执行4YuanFormual.exe，该程序为```./4YuanFormula/```目录下vs2015生成的exe可执行文件的链接
>> ```./4YuanFormual.exe.ink```
> ##### 程序会从```./input.c```中读入C源文件并在控制台进行`错误处理`与`类型检查`，并将生成的四元式输出到```./4yuan.txt```
> ##### 接着执行```./trans4toCode.py```读取四元式并将中间代码输入到```./innerCode.txt```中
>> ```python ./trans4toCode.py```
>
> 变量消减的代码优化为可选项，建议在即有示例代码```./input.c```上尝试，其余输入情况下发生故障本项目组具有完全解释权
>> ```python ./optimize.py```
> ##### 最终执行```objectcode.py```将中间代码转为MIPS汇编到```result.asm```中
>> ```python ./objectcode.py```
> ##### 打开```./QtSpim/QtSpim.exe```，导入```result.asm```汇编即可执行！
> ![QtSpim](img/QtSpim.png)
> ![console](img/console.png)
>
> 另：生成四元式后，可一键自动生成MIPS汇编，因为此脚本集成了代码优化，所以不是很推荐
>> ```python mips.py```
- ### Java CC 实现
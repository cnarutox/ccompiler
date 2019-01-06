# Mac 修改环境变量

```
cd ~/
```

```
touch .bash_profile
```

```
open -e .bash_profile
```

```
JAVA_HOME=/Library/Java/JavaVirtualMachines/jdk1.8.0_40.jdk/Contents/Home
PATH=$JAVA_HOME/bin:$PATH:.
CLASSPATH=$JAVA_HOME/lib/tools.jar:$JAVA_HOME/lib/dt.jar:.
export JAVA_HOME
export PATH
export CLASSPATH
```

```
source .bash_profile
```

---

# Mac 的控制台命令无法使用：command not found

- 第一步：打开终端，输入如下命令并回车：

```
export PATH=/usr/bin:/usr/sbin:/bin:/sbin:/usr/X11R6/bin
```

- 第二步：进入当前用户的home目录：

```
cd ~/
```

- 第三步：创建bash_profile 执行命令：

```
touch .bash_profile
```

- 第四步：打开并编辑bash_profile 执行命令：

```
open .bash_profile
```

- 第五步：这样就打开了一个记事本，会显示你之前配置过的path，修改记事本或者不修改；

- 第六步：进行保存 全选: command+s 或者不放心的话 选中记事本 文件-保存 保存之后没提示 直接关掉就可以；

- 第七步：此时在命令行中输入更新命令(命令行一直不要关)：

```
source .bash_profile
```

---

# 运行：

cd 到jj文件到目录；

```
java -cp /Users/local/javacc-master/target/javacc.jar javacc *.jj
```
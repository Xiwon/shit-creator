# shit-creator
> a program that reads a program and outputs some shit-like code. 😍

简单的替换所有的标识符为 "__intxxx" 组成的字符串

原理：提取所有 `[A-Za-z0-9_]+` 匹配的串，然后依次判断是否需要替换

naive 且暴力的实现（

由于完全没有语法 / 语义分析 (词法分析都算不上)，所以需要直接打保留字表。

如果你发现 create 出来的 shit.cpp 没办法编译过，可以试着找找源代码里哪些不该替换的字符被替换成了 '__int...'，然后把他们逐一添加到保留字表中（

### 如何改变你想替换成的字符串？

改一改定义在 Line 53/54 的 `ret`&`preffix` 就可以啦！比如，你可以把它改成这样：

```cpp
vector<string> ret={"🐲","🐉","🐍"};
string preffix="";
```

然后，生成的代码就会变成这样：

```cpp
for(🐲🐲🐲🐍 🐍🐍🐍🐲🐉🐲=0;🐍🐍🐍🐲🐉🐲<🐍🐲🐲🐉🐉.size();🐍🐍🐍🐲🐉🐲++){
	🐲🐲🐉🐉[🐍🐲🐲🐉🐉[(🐍🐍🐍🐲🐉🐲+🐍🐉🐉🐉🐍)%🐍🐲🐲🐉🐉.size()]]=🐍🐲🐍🐲🐍🐲[🐍🐲🐲🐉🐉[🐍🐍🐍🐲🐉🐲]];
}
```

又或者改成这样：

```cpp
vector<string> ret={"1","2","3","4","5","6","7","8","9","0"};
string preffix="mt";
```

然后，生成的代码就会变成这样：

```cpp
if (isdigit(mt781[0]) || mt545(mt781)) mt54559 += mt781;
else {
	if (mt339.find(mt781) != mt339.end()) mt54559 += mt339[mt781];
	else mt339[mt781] = mt04097(), mt54559 += mt339[mt781];
}
mt54559 += mt5181;
mt96562 = 0, mt781 = "";
```

### 项目意义！

没有意义 😀

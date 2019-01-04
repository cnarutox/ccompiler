
== == == == == == == == = 函数 == == == == == == == == == ==
√ int func(int i)
{
    print(i);
    return 0;
}
int main()
{
    int j = 5;
    func(j);
    return 0;
}

√ int func()
{
    int i = 4;
    if (i < 5)
    {
        print(i);
    }
    return i;
}

int main()
{
    int i = func();
    print(i);
    return 0;
}

void main()
{
    int i;
    i = 5;
    do
    {
        i = i - 1;
        print(i);
    } while (i > 0);
    for (i = 0; i < 3; i = i + 1)
    {
        print(i);
    }
    if (i == 2)
    {
        print(i);
    }
    return 0;
}

== == == == == == == == == = 运算符 == == == == == == == == == =
                                                                   ---------------------------------关系运算符-- -----------------------------
√ int main()
{
    int a = 0;
    int b = 1;
    int c = 1;
    if (a < b)
    {
        print(0);
    }
    if (b == c)
    {
        print(1);
    }
    if (b >= a)
    {
        print(2);
    }
    if (a != b)
    {
        print(3);
    }
    if (a == c)
    {
        print(4);
    }
    return 0;
}

-----------------------------逻辑运算符-- ----------------------------
√ int main()
{
    if ((1 == 2) || (1 == 1))
    {
        print(1);
    }
    if ((1 == 2) || (2 == 3))
    {
        print(2);
    }
    if ((1 == 1) && (1 == 2))
    {
        print(3);
    }
    if ((1 == 1) && (2 == 2))
    {
        print(4);
    }
    if (!(1 == 2))
    {
        print(5);
    }
    if (2 != 3)
    {
        print(6);
    }
    if (1 != 1)
    {
        print(7);
    }
    return 0;
}
//输出 1, 4, 5, 6

== == == == == == == = 循环 == == == == == == == == =
                                                        -----------------------循环 + if语句-- -------------------------
√ int main()
{
    int i = 5;
    int j;
    do
    {
        if (i < 1 + 1)
            print(i);
        i = i - 1;
    } while (i > 0);
    while (i < 8)
    {
        if (i > 10 / 2)
            print(i);
        else
        {
            print(i * 10);
        }
        i = i + 1;
    }
    return 0;
}

-----------------------------for循环-- --------------------------
√ void f4() {}
int main()
{
    int i;
    for (i = 0; i < 3; i = i + 1)
    {
        f4();
    }
    return 0;
}

int main()
{
    int i;
    for (i = 0; i < 3; i = i + 1)
    {
        print(i);
    }
    return 0;
}

-------------------------------while循环-- ------------------------------
√ int main()
{
    int i = 5;
    do
    {
        print(i);
        i = i - 1;
    } while (i > 0);
    while (i < 8)
    {
        print(i);
        i = i + 1;
    }
    return 0;
}
//输出 5，4，3，2，1，0，1，2，3，4，5，6，7

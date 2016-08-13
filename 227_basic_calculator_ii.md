# [227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)

咳咳，加减乘除的运算嘛，如果是基本计算器1的话就是

* 直接加减就好了呗hhhh
* 一个for循环里面判断isdigit或者isspace

基本计算器2的加减乘除就需要：
* 初始时把符号设成'+'为了处理第一个数字.
* 如果数字前的符号是'+'就直接push到stack里面.
* 如果数字前是'-'就把这个数的负数push到stack里面.
* 如果数字前是'*' '/'从stack里面pop出来一个数字做运算再把结果push进去
* 最后把stack里面所有数字都加一遍

```c++
int calculate(string s) {
    s += '+';
    int cur = 0, last = 1, ans = 0;
    bool pos = true, mul = true;
    for (char c: s)
        if (isdigit(c)) {
            cur = cur*10 + c-'0';
        } else if (c == '+' || c == '-') {
            ans += (mul ? last * cur : last / cur) * (pos ? 1 : -1);
            pos = c == '+', mul = true, last = 1, cur = 0;
        } else if (c == '*' || c == '/') {
            last = mul ? last * cur : last / cur;
            mul = c == '*', cur = 0;
        }
    return ans;
}
```
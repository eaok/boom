#!/usr/bin/env python3
#-*- coding:utf-8 -*-

a=input('输入密文：')
for i in range(1, 26): # 向后移1~25位
    result = '' # 结果存放处
    for j in a:
        if j.isalpha():
            result += chr(97 + (ord(j) - 97 + i) % 26) # 考虑到超过z要回到a, 将结果加入result
        else:
            result+=j
    print(result, i)

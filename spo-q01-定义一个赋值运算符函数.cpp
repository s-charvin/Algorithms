/**
 * @file spo-q01-定义一个赋值运算符函数.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-01-03
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：
 * - 如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
 * 链接:
 * 考察
 * - 定义一个赋值运算符函数
 * 基本注意点
 * - 返回值的类型
 * - 传入的参数的类型
 * - 释放实例
 * - 特殊输入(实例本身):
 * 高阶注意点
 * - 先delete 再 new 分配新内容时, 会遇到内存超出异常问题导致的实例内容丢失
 */

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class CMyString
{
public:
    CMyString(char *pData = NULL);
    CMyString(const CMyString &str);
    ~CMyString(void);

private:
    char *m_pData;
};

// 把返回值的类型声明为该类型的引用
CMyString &CMyString::operator=(const CMyString &str)
// 传入的参数的类型声明为 const 引用, 减少从形参到实参过程调用一次复制构造函数的无谓消耗
{
    // 如果传入的参数和当前的实例是同一个, 直接返回自身
    // 因为后面有内存释放操作, 一旦释放了自身的内存，传入的参数的内存也同时被释放了，
    // 需要赋值的内容也就消失了。
    if (this != &str)
    {
        delete[] this->m_pData;                            // 释放实例内部自身已有的内存
        this->m_pData = NULL;                              //
        this->m_pData = new char[strlen(str.m_pData) + 1]; // 分配新内存
        // char *strcpy(char *dest, const char *src) 把 src 所指向的字符串复制到 dest。
        // 当 dest 指向的存储空间不足以存储 src 指向的字符串，会覆盖其他内存空间
        strcpy(this->m_pData, str.m_pData);
    }
    // 在函数结束前返回实例自身的引用, 只有返回一个引用，才可以允许连续赋值。
    return *this;
}

CMyString &CMyString::operator=(const CMyString &str)
{
    if (this != &str)
    {
        CMyString strTemp(str);

        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }

    return *this;
}
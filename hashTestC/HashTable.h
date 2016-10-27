#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//g++ -o Test main.cpp

typedef enum 
{
	EM_SELECT = 0,
	EM_INSERT,
}EM_HASH_STATE;

//hash表结构
typedef struct 
{
	char  m_cExists;                       //当前块是否已经使用,1已经使用，0没有被使用
	char* m_szKey;                         //当前的key值，没有则为空
	int   m_nKeySize;                      //当前key数据长度
	int   m_nNextKeyIndex;                 //链表信息，如果主键有冲突,记录下一个冲突主键的位置
	int   m_nProvKeyIndex;                 //链表信息，如果主键有冲突,记录上一个冲突主键的位置
	unsigned long m_uHashA;                //第二次的hashkey值
	unsigned long m_uHashB;                //第三次的hashkey值 
	char* m_szValue;                       //当前数据体指针
	int   m_nValueSize;                    //当前数据体长度  
}_Hash_Table_Cell;

char cryptTable[1280];

//生成秘钥
void prepareCryptTable();

//初始化一个p_Hash_Table_Cell节点
void Init_Hash_Table_Cell(_Hash_Table_Cell* p_Hash_Table_Cell);

//初始化一个hash数据key空间
void Set_Hash_Table_Key_Cell(_Hash_Table_Cell* p_Hash_Table_Cell, char* pKey, int nKeySize);

//初始化一个hash数据value空间
void Set_Hash_Table_Value_Cell(_Hash_Table_Cell* p_Hash_Table_Cell, char* pValue, int nValueSize);

//清理一块hash数据内存
void Clear_Hash_Table_Value_Cell(_Hash_Table_Cell* p_Hash_Table_Cell);

//清理一个p_Hash_Table_Cell节点
void Clear_Hash_Table_Cell(_Hash_Table_Cell* p_Hash_Table_Cell);

unsigned long HashString(const char* pKey, unsigned long dwHashType);

int GetLastClashKey(_Hash_Table_Cell *lpTable, int nCount, int nStartIndex, const char *lpszString, unsigned long uHashA, unsigned long uHashB, EM_HASH_STATE emHashState);

int GetHashTablePos(const char *lpszString, _Hash_Table_Cell *lpTable, int nCount, EM_HASH_STATE emHashState);

int DelHashTablePos(const char *lpszString, _Hash_Table_Cell *lpTable, int nCount);

#endif

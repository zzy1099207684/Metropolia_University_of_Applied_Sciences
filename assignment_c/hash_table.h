//
// Created by zhiyo on 2024/10/9.
//

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// 哈希表的大小
#define TABLE_SIZE 10

// 链表节点结构，用于处理哈希冲突
typedef struct Entry {
    char *key;
    char *value;
    struct Entry *next;
} Entry;

// 哈希表结构
typedef struct HashTable {
    Entry *table[TABLE_SIZE];
} HashTable;

// 函数声明
HashTable* create_table();                          // 创建哈希表
void insert(HashTable *table, const char *key, const char *value);  // 插入数据
char* search(HashTable *table, const char *key);    // 查找数据
void delete(HashTable *table, const char *key);     // 删除数据
void free_table(HashTable *table);                  // 释放哈希表的内存

#endif // HASH_TABLE_H

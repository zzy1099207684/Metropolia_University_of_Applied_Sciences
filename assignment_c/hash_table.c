//
// Created by zhiyo on 2024/10/9.
//
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 哈希函数，将键字符串映射到表的索引
unsigned int hash(const char *key, int table_size) {
    unsigned int hash_value = 0;
    while (*key) {
        hash_value = (hash_value * 31) + *key;
        key++;
    }
    return hash_value % table_size;
}

// 创建哈希表
HashTable* create_table() {
    HashTable *new_table = malloc(sizeof(HashTable));
    if (!new_table) {
        return NULL;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        new_table->table[i] = NULL;
    }
    return new_table;
}

// 插入键值对到哈希表
void insert(HashTable *table, const char *key, const char *value) {
    unsigned int index = hash(key, TABLE_SIZE);
    Entry *new_entry = malloc(sizeof(Entry));
    if (!new_entry) {
        printf("Memory allocation error\n");
        return;
    }
    new_entry->key = strdup(key);
    new_entry->value = strdup(value);
    new_entry->next = table->table[index];
    table->table[index] = new_entry;
}

// 查找键对应的值
char* search(HashTable *table, const char *key) {
    unsigned int index = hash(key, TABLE_SIZE);
    Entry *entry = table->table[index];

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

// 删除键值对
void delete(HashTable *table, const char *key) {
    unsigned int index = hash(key, TABLE_SIZE);
    Entry *entry = table->table[index];
    Entry *prev = NULL;

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (prev == NULL) {
                table->table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            free(entry->key);
            free(entry->value);
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

// 释放哈希表的内存
void free_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *entry = table->table[i];
        while (entry != NULL) {
            Entry *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(table);
}

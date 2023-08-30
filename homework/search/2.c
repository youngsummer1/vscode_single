// 哈希表添加

// 哈希表（Hash Table，也叫散列表），是根据键（Key）而直接访问在内存存储位置的数据结构。也就是说，它通过计算一个关于键值的函数，将所需查询的数据映射到表中一个位置来访问记录，这加快了查找速度。这个映射函数称做哈希函数，存放记录的数组称做哈希表。哈希表相关定义如下：

// typedef enum{
//     HASH_OK,
//     HASH_ERROR,
//     HASH_ADDED,
//     HASH_REPLACED_VALUE,
//     HASH_ALREADY_ADDED,
//     HASH_DELETED,
//     HASH_NOT_FOUND,
// } HASH_RESULT;

// typedef struct __HashEntry HashEntry;
// struct __HashEntry{
//     union{
//         char  *str_value;
//         double dbl_value;
//         int       int_value;
//     } key;
//     union{
//         char  *str_value;
//         double dbl_value;
//         int       int_value;
//         long   long_value;
//         void  *ptr_value;
//     } value;
//     HashEntry *next;
// };

// struct __HashTable{
//     HashEntry **bucket;        
//     int size;
//     HASH_RESULT last_error;
// };
// typedef struct __HashTable HashTable;

// // 向哈希表中添加元素，其中键类型为char*， 元素类型为int。
// HASH_RESULT hash_add_int(HashTable * table, const char * key, int value);

// 哈希表相关说明：

// HASH_RESULT 类型为相关函数的返回类型
// HashEntry 为哈希表所保存元素（即键值对 《key, value》）类型
// HashTable 为哈希表，其中 bucket 指向大小为size的、元素类型为 HashEntry*的指针数组
// 哈希表采用链地址法处理冲突
// 请实现 hash_add_int 函数，向哈希表中添加元素，其中键类型为char*， 元素类型为int。在添加过程中，如果要添加的键值key已在哈希表中，且对应的值value也已存在，则函数返回 HASH_ALREADY_ADDED；如果要添加的键值key已在哈希表中，但对应的值value不同，则函数将value值更新到哈希表中，之后返回 HASH_REPLACED_VALUE；如果要添加的键值key不在哈希表中，则函数创建 HashEntry 类型，并将其加入到哈希表中，且函数返回 HASH_ADDED。本题所用的哈希函数如下：

// long hash_string(const char *str)
// {
//     long hash = 5381;
//     int c;

//     while (c = *str++)
//         hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
//     if(hash < 0)
//         hash *= -1;
//     return hash;
// }
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
typedef enum{
    HASH_OK,
    HASH_ERROR,
    HASH_ADDED,
    HASH_REPLACED_VALUE,
    HASH_ALREADY_ADDED,
    HASH_DELETED,
    HASH_NOT_FOUND,
} HASH_RESULT;

typedef struct __HashEntry HashEntry;
struct __HashEntry{
    union{
        char  *str_value;
        double dbl_value;
        int       int_value;
    } key;
    union{
        char  *str_value;
        double dbl_value;
        int       int_value;
        long   long_value;
        void  *ptr_value;
    } value;
    HashEntry *next;
};

struct __HashTable{
    HashEntry **bucket;        
    int size;
    HASH_RESULT last_error;
};
typedef struct __HashTable HashTable;

// 向哈希表中添加元素，其中键类型为char*， 元素类型为int。
HASH_RESULT hash_add_int(HashTable * table, const char * key, int value);


long hash_string(const char *str)
{
    long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    if(hash < 0)
        hash *= -1;
    return hash;
}

//成功了的
HASH_RESULT hash_add_int(HashTable* table, const char* key, int value) {
    long hash_value = hash_string(key);  // 计算键的哈希值
    int index = hash_value % table->size;  // 根据哈希值计算链表头指针数组索引

    // 在对应链表中查找是否已存在相同的键
    HashEntry* entry = table->bucket[index];
    while (entry != NULL) {
        if (strcmp(entry->key.str_value, key) == 0) {
            // 键已存在
            if (entry->value.int_value != value) {
                // 值不同，更新值
                entry->value.int_value = value;
                return HASH_REPLACED_VALUE;
            } else {
                // 值相同，不做修改
                return HASH_ALREADY_ADDED;
            }
        }
        entry = entry->next;
    }

    // 创建新的哈希表元素
    HashEntry* new_entry = (HashEntry*)malloc(sizeof(HashEntry));
    if (new_entry == NULL) {
        return HASH_ERROR;
    }

    // 复制键字符串到新的内存中 
    // 注意在分配new_entry->key.str_value的内存时，为了容纳字符串结尾的空字符\0，我们将分配的大小设置为strlen(key)+1
    new_entry->key.str_value = (char*)malloc(sizeof(char) * (strlen(key) + 1));
    if (new_entry->key.str_value == NULL) {
        free(new_entry);
        return HASH_ERROR;
    }
    strcpy(new_entry->key.str_value, key);

    // 设置值
    new_entry->value.int_value = value;

    // 头插法
    new_entry->next = table->bucket[index];
    table->bucket[index] = new_entry;

    return HASH_ADDED;
}


//下面这个错的原因在于char*赋值时内存的申请

// HASH_RESULT hash_add_int(HashTable * table, const char * key, int value) 
// {
//     int hash = hash_string(key) % table->size; // 计算键key的哈希值
//     HashEntry *entry = table->bucket[hash];
    
//     // 查找键key是否已存在
//     while (entry != NULL) {
//         if (strcmp(entry->key.str_value, key) == 0) {
//             // 键key已存在,判断值value是否相同
//             if (entry->value.int_value == value) 
//                 return HASH_ALREADY_ADDED;
//             else {
//                 // 值value不同,更新值后返回
//                 entry->value.int_value = value;
//                 return HASH_REPLACED_VALUE;
//             }
//         }
//         entry = entry->next;  // 访问链表下一节点
//     }
    
//     // 键key不存在,创建新节点并加入哈希表
//     entry = (HashEntry*)malloc(sizeof(HashEntry));
//     entry->key.str_value = key;
//    //换成下面这个就是对的
//    // entry->key.str_value = (char*)malloc(sizeof(char) * (strlen(key) + 1));
//    // strcpy(entry->key.str_value, key);
//     entry->value.int_value = value;
//     entry->next = table->bucket[hash];
//     table->bucket[hash] = entry;
    
//     return HASH_ADDED;
// }



// int main(){
//     char* str1="zcaln", *str2="aozge",*str3="shzpn",*str4="ylhhw";
//     int hash1=hash_string(str1);
//     int hash2=hash_string(str2);
//     int hash3=hash_string(str3);
//     int hash4=hash_string(str4);
//     printf("hash1=%d\n",hash1);
//     printf("hash2=%d\n",hash2);
//     printf("hash3=%d\n",hash3);
//     printf("hash4=%d\n",hash4);

//     return 0;
// }
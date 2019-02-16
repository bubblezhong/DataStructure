#include <stdio.h>
#define HASHSIZE 12
#define NULLKEY -32768
typedef struct {
  int *elem;
  int count;
} HashTable;
int m = 0;      //散列表的长度，全局变量
//初始化散列表
int InitHashTable (HashTable *H) {
  int i;
  m = HASHSIZE;
  H -> count = m;
  H -> elem = (int *)malloc(m * sizeof(int));          //分配数组内存
  for (i = 0; i < m; i++) {
    H -> elem[i] = NULLKEY;
  }
  return 1;
}
//散列函数
Hash(int key) {
  return key % m;
}
//插入关键字进散列表
void InsertHash (HashTable *H, int key) {
  int addr = Hash(key);
  while(H -> elem[addr] != NULLKEY) {            //如果不为空则冲突
    addr = (addr + 1) % m;                       //开放定址法线性探测
  }
  H -> elem[addr] = key;                         //直到有空位后插入数据
}
//散列表查找关键字
int HashSearch (HashTable H, int key, int *addr) {
  *addr = Hash(key);
  while(H.elem[*addr] != key) {
    *addr = (*addr + 1) % m;
    if (H.elem[*addr] = NULLKEY || *addr == Hash(key)){          //如果循环回到原点，关键字不存在
        printf("表中不存在此关键字\n");
    }
  }
  return 1;
}
void main () {
  HashTable H;
  int i, addr;
  InitHashTable(&H);
  int a[12] = {12, 25, 38, 15, 16, 29, 78, 67, 56, 21, 22, 47};
  for(i = 0; i < 12; i++) {
     InsertHash(&H, a[i]);
  }
  HashSearch(H, 78, &addr);
  printf("地址是%d\n", addr);
}














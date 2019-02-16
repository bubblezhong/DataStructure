#include <stdio.h>
#define HASHSIZE 12
#define NULLKEY -32768
typedef struct {
  int *elem;
  int count;
} HashTable;
int m = 0;      //ɢ�б�ĳ��ȣ�ȫ�ֱ���
//��ʼ��ɢ�б�
int InitHashTable (HashTable *H) {
  int i;
  m = HASHSIZE;
  H -> count = m;
  H -> elem = (int *)malloc(m * sizeof(int));          //���������ڴ�
  for (i = 0; i < m; i++) {
    H -> elem[i] = NULLKEY;
  }
  return 1;
}
//ɢ�к���
Hash(int key) {
  return key % m;
}
//����ؼ��ֽ�ɢ�б�
void InsertHash (HashTable *H, int key) {
  int addr = Hash(key);
  while(H -> elem[addr] != NULLKEY) {            //�����Ϊ�����ͻ
    addr = (addr + 1) % m;                       //���Ŷ�ַ������̽��
  }
  H -> elem[addr] = key;                         //ֱ���п�λ���������
}
//ɢ�б���ҹؼ���
int HashSearch (HashTable H, int key, int *addr) {
  *addr = Hash(key);
  while(H.elem[*addr] != key) {
    *addr = (*addr + 1) % m;
    if (H.elem[*addr] = NULLKEY || *addr == Hash(key)){          //���ѭ���ص�ԭ�㣬�ؼ��ֲ�����
        printf("���в����ڴ˹ؼ���\n");
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
  printf("��ַ��%d\n", addr);
}














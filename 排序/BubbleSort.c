#include <stdio.h>
#define MAXSIZE 10
typedef struct {
  int r[MAXSIZE];
  int length;
} SqList;
Swap (SqList *L, int i, int j) {
  int temp;
  temp = L -> r[i];
  L -> r[i] =L -> r[j];
  L -> r[j] = temp;
}
void BubbleSort (SqList *L) {
   int flag, i, j, count1 = 0, count2 = 0;
   flag = 1;
   for (i = 0; i < L -> length - 1 && flag; i++) {
     flag = 0;
     for (j = L ->length - 2; j >= i; j-- ) {
        count1++;
        if (L -> r[j] > L -> r[j + 1]) {
            count2++;
           Swap(L, j, j + 1);
           flag = 1;
        }
     }
   }
   printf("�Ƚ���%d��,������%d��.\n", count1, count2);
}
void main() {
  int a[10] = {4, 2, 1, 3, 5, 6, 7, 8, 9, 0}, i;
  SqList *L;
  L -> length = MAXSIZE;
  for (i = 0; i <= 9; i++) {
    L ->r[i] = a[i];
  }
  printf("length��%d\n",L -> length);
  BubbleSort(L);
  printf("�����Ľ��\n");
 for(i = 0; i <= 9; i++) {
    printf("��%d��Ԫ����%d\n",i,L ->r[i]);
 }
}


























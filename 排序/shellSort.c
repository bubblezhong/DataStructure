#include <stdio.h>
typedef struct {
  int r[10];
  int length;
} SqList;
void ShellSort (SqList *L) {
  int i, j, increment;
  increment =  L ->length;
  do {
    increment = increment /3 + 1;
    for (i = increment + 1; i < L ->length; i++) {
        if(L ->r[i] < L ->r[i - increment]) {
            L ->r[0] = L ->r[i];
            for (j = i - increment; j > 0 && L ->r[j] > L ->r[0]; j -=increment) {
                L ->r[j + increment] =  L ->r[j];
            }
            L ->r[j + increment] = L ->r[0];
        }
    }
  } while (increment > 1);
}
void main() {
  int a[10] = {0, 450, 10, 92, 30, 70, 40, 83, 60, 20 ,}, i;
  SqList *L;
  L -> length = 10;
  for (i = 0; i <= 9; i++) {
    L ->r[i] = a[i];
  }
  printf("length：%d\n",L -> length);
  ShellSort(L);
  printf("排序后的结果\n");
  for(i = 1; i <= 9; i++) {
    printf("第%d个元素是%d\n",i,L ->r[i]);
 }
}

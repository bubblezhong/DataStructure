#include <stdio.h>
#define MAXSIZE 10
typedef struct {
  int r[MAXSIZE];
  int length;
} SqList;
void MergeSort (SqList *L) {
  MSort(L -> r, L ->r, 1, L ->length);
}
void MSort (int SR[], int TR1[], int s, int t) {
  int m;
  int TR2[MAXSIZE + 1];
  if (s == t)
    TR1[s] = SR[s - 1];
  else {
    m = (s + t) / 2;
    MSort(SR, TR2, s, m);
    MSort(SR, TR2, m + 1, t);
    Merge(TR2, TR1, s, m, t);
  }
}
void Merge (int SR[], int TR[], int i, int m, int n) {
  int j, k, l;
  for (j = m + 1, k = i; j <= n && i <= m; k ++) {
    if (SR[i] < SR[j])
        TR[k] = SR[i++];
    else
        TR[k] = SR[j++];
  }
  if (i <= m) {
    for (l = 0; l <= m - i; l++)
        TR[k + l] = SR[i + l];
  }
  if (j <= n) {
    for (l = 0; l <= n - j; l++)
        TR[k + l] = SR[j + l];
  }
}
void main() {
  //int a[10] = {0, 4, 9, 6, 7, 2, 5, 3, 8, 1}, i;
  int a[10] = {0, 400, 900, 600, 700, 200, 500, 300, 800, 100}, i;
  SqList *L;
  L -> length = MAXSIZE;                //10
  for (i = 0; i < MAXSIZE; i++) {
    L ->r[i] = a[i];
  }
  printf("length：%d\n",L -> length);
  MergeSort(L);
  printf("排序后的结果\n");
  for(i = 1; i <= MAXSIZE; i++) {
    printf("第%d个元素是%d\n",i,L ->r[i]);
 }
}

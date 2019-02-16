#include <stdio.h>
int count = 0;
int DagerCount = 0;
//row:��ʾ��ʼ��
//n:��ʾ����
//(*chess)[16]����ʾָ������ÿһ�е�ָ��
int noDanger (int row, int j, int (*chess)[16]) {
    DagerCount++;
    int i, k, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
    //�ж��з���
    for (i = 0; i < 16; i++) {
      if (*(*(chess + i) + j) != 0) {
        flag1 = 1;
        break;
      }
    }
   //�ж����Ϸ�
   for (i = row, k = j; i >= 0 && k >= 0; i--, k--) {
     if (*(*(chess + i) + k) != 0) {
        flag2 = 1;
        break;
      }
   }
   // �ж����·�
   for (i = row, k = j; i < 16 && k < 16; i++, k++) {
     if (*(*(chess + i) + k) != 0) {
        flag3 = 1;
        break;
      }
   }
   // �ж����Ϸ�
   for (i = row, k = j; i >= 0 && k < 16; i--, k++) {
     if (*(*(chess + i) + k) != 0) {
        flag4 = 1;
        break;
      }
   }
   // �ж����·�
   for (i = row, k = j; i < 16 && k >= 0; i++, k--) {
     if (*(*(chess + i) + k) != 0) {
        flag5 = 1;
        break;
      }
   }
   if (flag1 || flag2 || flag3 || flag4 || flag5) {
     return 0;
   } else {
     return 1;
   }


}
void EightQueen(int row, int n, int (*chess)[16]){
  int chess2[16][16], i, j;
  for (i = 0; i < 16; i++) {
    for (j = 0; j < 16; j++) {
        chess2[i][j] = chess[i][j];
    }
  }
  if (16 == row) {
    printf("��%d�֣�", count + 1);
    for (i = 0; i < 16; i++) {
       for (j = 0; j < 16; j++) {
        printf("%d", *(*(chess2 + i) + j));
       }
       printf("\n");
    }
    printf("\n");
    count++;
  } else {
     //printf("uggg\n");
    for (i = 0; i < 16; i++) {
      if ( noDanger(row, i, chess) ) {
        for (j = 0; j < 16; j++) {
          *(*(chess2 + row) + j) = 0;
        }
        *(*(chess2 + row) + i) = 1;
        EightQueen(row + 1, n, chess2);
      }
    }
  }
}
int main() {
  int chess[16][16], i, j;
  for (i = 0; i < 16; i++) {
    for (j = 0; j < 16; j++) {
        chess[i][j] = 0;
    }
  }
  EightQueen(0, 16, chess);
  printf("�ܹ���%d�ֽ��������\n\n", count);
   printf("�ܹ���������%d�Σ�\n\n", DagerCount);
  return 0;
}

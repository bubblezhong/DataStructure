#include <stdio.h>

//��n�����Ӵ�x����y�ƶ���z��
void move (int n, char x, char y, char z) {
  if (1 == n) {
    printf("%c--->%c\n", x , z);
  } else {
    move(n-1, x, z, y); //��n-1�����Ӵ�x����z�ƶ���y��
    printf("%c--->%c\n", x, z); //����n�����Ӵ�x�ƶ���z��
    move(n-1, y, x, z);   //����n-1�����Ӵ�y����x�ƶ���z��
  }
}
int main() {
  int n;
  printf("�����뺺ŵ��������");
  scanf("%d", &n);
  printf("�ƶ��������£�\n");
  move(n, 'X', 'Y', 'Z');
  return 0;
}

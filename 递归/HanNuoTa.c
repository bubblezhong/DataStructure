#include <stdio.h>

//将n个盘子从x借助y移动到z上
void move (int n, char x, char y, char z) {
  if (1 == n) {
    printf("%c--->%c\n", x , z);
  } else {
    move(n-1, x, z, y); //将n-1个盘子从x借助z移动到y上
    printf("%c--->%c\n", x, z); //将第n个盘子从x移动到z上
    move(n-1, y, x, z);   //将第n-1个盘子从y借助x移动到z上
  }
}
int main() {
  int n;
  printf("请输入汉诺塔层数：");
  scanf("%d", &n);
  printf("移动步骤如下：\n");
  move(n, 'X', 'Y', 'Z');
  return 0;
}

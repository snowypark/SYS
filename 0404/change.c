#include <stdio.h>
#include <string.h>

void change(char c) {
   int n, arr[4] = { 0, };
   n = (int)c - 48;

   // 숫자가 아닐경우 A를 10으로 만들어줌
   if (n > 9) n -= 7;

   for (int i = 0; i < 4; i++) {
      arr[i] = (n % 2);
      n /= 2;
   }
   for (int i = 3; i >= 0; i--) {
      printf("%d", arr[i]);
   }
   printf(" ");
}

int main() {
   char arr[50001];
  
  printf("16진수: ");
   scanf("%s", arr);

  
  printf("2진수: ");
   for (int i = 0; i < strlen(arr); i++) {
      change(arr[i]);
   }
  printf("\n");
   return 0;
}

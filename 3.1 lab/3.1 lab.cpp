#include<cstdio>
int main() { for (int k = 2, i, j;k < 7;k += 4, puts("\n"))for (i = 1;i < 10;i++)for (j = k;j < k + 4;j++)printf("%d*%d=%2d%c", i, j, i * j, j < k + 3 ? 32 : 10); }
//puts — функция из <cstdio>, которая выводит строку и автоматически добавляет в конце перевод строки
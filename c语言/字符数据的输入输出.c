#include<stdio.h>
int main(void)
{
	char a,b,c;
	a=getch();/*getcchr输入时不会再屏幕上显示*/ 
	b=getchar();/*getchar会在屏幕上显示*/ 
	c='y';
	putch(a);
	putchar(b);
	putchar(c);
	putchar('\n'); 
}

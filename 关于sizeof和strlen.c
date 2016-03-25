#include<stdio.h>
#include<string.h>//提供strlen()函数的原型 
#define PRALSE "what a girl!"//define a = 20是错误的，会吧=20赋给a; 
void main()
{	int x=121;
	int  t;
	t=printf("%dn m l.",x);//printf有返回值，包括换行符和空格 121 F is water's boiling point.  这是31个字符，加上\n就是32 
	printf("%d",t);
	char name[40];
	scanf("%s",name);//scanf开始输入之后遇到空格（blank)，制表符(tab)，换行符(newline)处便会停止读取，如果输入(hello,my name)计算机读取hello，my 之后的虽然可以输入但是却并没有真正储存在name里 
	printf("sizeof name=%d\n",sizeof(name));//下同 
	printf("sizeof name=%d\n",sizeof name);//会输出name 定义时的字节数   是由scanf输入的 
	printf("strlen name=%d\n",strlen (name));//  strlen 都只会读取储存在name里的并返回数，
	//sizeof 是否带括号，，要获取的是具体量的大小如一个用户自己输入的字符串之类的 不用，获取类型的大小，要 
	printf("定义strlen=%d",strlen(PRALSE));//输出字符串中字符包括（空格 标点）的数字 
	printf("定义sizeof=%d",sizeof PRALSE); //但是sizeof会比strlen多一个，因为会读取\o
	//但是都带不会混乱  
	 /*整型[signed]int                  -2147483648~+2147483648
无符号整型unsigned[int]                       0~4294967295
短整型 short [int]                                    -32768~32768
无符号短整型unsigned short[int]             0~65535
长整型 Long int                            -2147483648~+2147483648
无符号长整型unsigned [int]                   0~4294967295
字符型[signed] char                               -128~+127
无符号字符型 unsigned char                       0~255
单精度 float                                 3.4 x 10^（-38）~  3.4 x 10^（+38）
双精度double                              1.7 x 10^（-308）~  1.7 x 10^（+308）
长双精度 long double                 1.7 x 10^（-308）~  1.7 x 10^（+308）*/
 } 

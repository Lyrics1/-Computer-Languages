#include<stdio.h>
void main()
{
	char D[20];
	printf("������ĳһ���Ӣ�ģ�������һ��mondy,\n�����룺");
	gets(D);
	switch(D[1])
	{
		case 'm':printf("this is monday");break;
		case 't':switch(D[2])
		         {
		         	case 'u':printf("this is Tuesday");break;
		         	case 'h':printf("this is thursday");break;
				  }
		case 'w':printf("this is wednesday");break;
		case 'f':printf("this is friday");break;
		case 's':switch(D[2])
		         {
		         	case 'a':printf("this is saturday");break;
		         	case 'u':printf("this is sunday");break;
				 }				 		
	}
}

#include<stdio.h>
void main()
{
	int choice;
	printf ("    ******�Զ���������ѯϵͳ******");
	printf("   1.�̲�\n");
	printf("   2.����\n");
	printf("   3.�Ҵ�\n");
	printf("   4.��Ȫˮ\n");
	printf("��ѯ�۸���������Ʒǰ�����   ��0�˳�\n");
	scnaf("%d",&choice);
	switch(choice)
	{
		case 1:printf("�̲裺4Ԫ/ƿ");break;
		case 2:printf("���֣�3.5Ԫ/ƿ");break;
		case 3:printf("�Ҵ4Ԫ/ƿ");break;
		case 4: printf("��Ȫˮ��1Ԫ/ƿ"); break;
		case 0:return;
	}
	 printf("\n");
}

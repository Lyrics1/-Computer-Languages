#include<stdio.h>
void main()
{
	int choice;
	printf("    ******�Զ�����ϵͳ******");
	printf("��ѯ��Ʒ�밴��Ʒǰ����ţ���0�˳���ѯ");
	printf("           1.�̲�");
	printf("           2.����");
	printf("           3.�Ҵ�");
	printf("           4.��Ȫˮ\n");
	printf("��Ҫ��ѯ��\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("�̲�  4Ԫ/ƿ");break;
		case 2:printf("���� 3.5Ԫ/ƿ");break;
		case 3:printf("�Ҵ� 4Ԫ/ƿ");break;
		case 4:printf("��Ȫˮ 1Ԫ/ƿ");break;
		case 0:return;
	 } 
	 printf("\n");
}

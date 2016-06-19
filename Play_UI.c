/*
* File name:  Play_UI.c
* File ID:	  TTMS_SSF_Play_UI_Sour
* Author:     Huang Ru
* Version:    V1.0
* Date: 	  2015-04-25
*/


#include "Play_UI.h"
#include "Schedule_UI.h"

#include "../Common/list.h"
#include "../Service/Play.h"
#include "../Service/EntityKey.h"

#include <stdio.h>
#include <stdlib.h>


	/*
	 * Function:    Play_UI_ShowList
	 * Function ID:	TTMS_SCU_Play_UI_Show
	 * Description: ���б�ģʽ��ʾ��Ŀ��Ϣ
	 * Input:       list��Ŀ��Ϣ�����ͷָ�룬paging��ҳ���ò���
	 * Output:      ���о�Ŀ����Ϣ
	 * Return:      ���ز��ҵ��ļ�¼��Ŀ
	 */
void Play_UI_ShowList(play_list_t list, Pagination_t paging) {
	
}

/*
 * Function:    Play_UI_MgtEntry
 * Function ID:	TTMS_SCU_Play_UI_MgtEnt
 * Description: ��Ŀ��Ϣ�������
 * Input:       flagΪ0���������ҳ�棬flagΪ1�����ѯ����
 * Output:      ��Ŀ�������
 * Return:      ��
 */
void Play_UI_MgtEntry(int flag){
		int i,id;
		char choice;
		play_list_t head;
		play_node_t *pos;
		Pagination_t paging;
		play_list_t p;
		
		List_Init(head,play_node_t);
		
		paging.offset=0;
		paging_Locate_FirstPage(head,paging);
		
		do{
			system("cls");
				printf("\n========================��Ŀ�б�========================\n\n");
		printf("%5s%10%10s%10s%12s%10s%12s%12s%10s","ID","��Ŀ����","��Ŀ����","��Ŀ��Ʒ����","��Ŀ�ȼ�","��ӳʱ��","��ʼ��ӳʱ��","������ӳʱ��","Ʊ��");
		printf("----------------------------------------------------------------------------------------------------------------------------------------\n\n");
		//��ʾ����
        for(i=0;pos=(play_node_t *)(paging.curPos),
			pos!=head && i<paging.pageSize;i++){
			printf("%d%s%s%s%s%d%s%s%d",p->data.id,p->data.name,p->data.type,p->data.area,p->data.rating,p->data.duration,p->data.start_date,p->data.end_date,p->data.price);
	}
    printf("-------------�ܾ�Ŀ�б� :%3d------------page(ҳ�룩 %3d/%3d\n---\n",paging.totalRecords, Pageing_CurPage(paging),
                Pageing_TotalPages(paging));
		printf("********************************************************************************\n");
	printf("[P]revPage|[N]extPage | [A]dd|[D]elete|[U]pdate | [S]eat | [R]eturn");//U���� 
        printf(
                "\n==================================================================\n");
        printf("Your Choice:");
        fflush(stdin);
        scanf("%c", &choice);
        fflush(stdin);
switch (choice) {
        case 'a':
        case 'A':
            if (Play_UI_Add()) //����ӳɹ����������һҳ��ʾ
            {
                paging.totalRecords = Play_Srv_FetchAll(head);
                Paging_Locate_LastPage(head, paging, play_node_t);
            }
			break;
		case 'd':
        case 'D':
            printf("Input the ID:");
            scanf("%d", &id);
            if (Play_UI_Delete(id)) { //������������
                paging.totalRecords = Play_Srv_FetchAll(head);
                List_Paging(head, paging, play_node_t);
            }
            break;
        case 'u':
        case 'U':
            printf("Input the ID:");
            scanf("%d", &id);
            if (Play_UI_Modify(id)) { //������������
                paging.totalRecords = Play_Srv_FetchAll(head);
                List_Paging(head, paging, play_node_t);
            }
            break;
        case 's':
        case 'S':
            printf("Input the ID:");
            scanf("%d", &id);
            Seat_UI_MgtEntry(id);
            paging.totalRecords = Play_Srv_FetchAll(head);
            List_Paging(head, paging, play_node_t);
            break;
        case 'p':
        case 'P':
            if (1 < Pageing_CurPage(paging)) {
                Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
            }
            break;
		 case 'n':
         case 'N':
            if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
            }
            break;
        }
    } while (choice != 'r' && choice != 'R');
    //�ͷ�����ռ�
 //   List_Destroy(head, studio_node_t);

		if(flag==0)
	{
		printf("\n\n=============================��Ŀ��Ϣ����ҳ��=============================\n\n");
		printf("[s]��ѯ��Ŀ�Ƿ����\n\n");
		printf("[Q]�����Ŀ��Ϣ\n\n");
		printf("[A]������Ŀ��Ϣ\n\n");
		printf("[D]ɾ����Ŀ��Ϣ\n\n");
		printf("[U]�޸ľ�Ŀ��Ϣ\n\n");
		printf("[P]��ǰҳ��\n\n");
		printf("[n]��ǰҳ�����ҳ��\n\n");
		printf("[R]�˳�����ϵͳ\n\n");
		printf("please input your choice �� ");
		scanf("%c",&choice);
		do{
					switch(choice)
				{	case 's':
					case 'S':printf("please input id:");scanf("%d",&id);Play_UI_Query(id);break;
					case 'q':
					case 'Q':printf("please input id:");scanf("%d",&id);Play_UI_Query(id);break;
					case 'a':
					case 'A':printf("please input id:");scanf("%d",&id);Play_UI_Add();break;
					case 'd':
                    case 'D':printf("please input id:");scanf("%d",&id);Play_UI_Delete(id);break;
					case 'u':
					case 'U':printf("please input id:");scanf("%d",&id); Play_UI_Modify(id);break;
					case 'p':
					case 'P':
					  if (1 < Pageing_CurPage(paging)) {
                	Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
					  }break;
					case 'n':
					case 'N':
					 if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
           		 }
        	    break;
				}
			}while(choice!='r'||choice!='R');
	}
			if(flag==1)
			{
				printf("\n=============================��Ŀ��ѯ����=============================\n\n");
				printf("please input id:");scanf("%d",&id);
				/* printf("[s]��ѯ��Ŀ�Ƿ����\n\n");        printf("[Q]�����Ŀ��Ϣ\n\n");
					fflush(stdin);
					scanf("%c",&choice);
					fflush(stdin);*/
			Play_UI_Query(id); 
			}

		List_Destroy(head,play_node_t);//��������

}



/*
 * Function:    Play_UI_Add
 * Function ID:	TTMS_SCU_Play_UI_Add
 * Description: ���һ����Ŀ��Ϣ
 * Input:       ��
 * Output:      ������Ϣʱ�ĸ�����ʾ
 * Return:      ��ӵļ�¼��
 */
int Play_UI_Add(void)
{
		play_t rec;
		int newRecCount =0;
		char choice;
		int flag;
		
		do{
			system("cls");
			printf("\n========================================================================\n");
			printf("������������������������µľ�Ŀ��Ϣ��������������������\n\n");
			printf("----------------------------------------------------------------------------\n\n");
			printf("��ϢID��:");
			scanf("%d",&(rec.id));
			printf("��Ŀ���ƣ�");
			scanf("%c",rec.name);
			printf("��Ŀ����  1:��Ӱ 2����� 3�����ֻ�\n");
			scanf("%d",&(rec.rating));
			printf("��Ŀ��Դ�أ�");
			scanf("%s",rec.area);
			printf("��Ŀ���� 1����ͯ���Թۿ� 2��������ɹۿ� 3�����˿ɹۿ�\n");
			printf("�ݳ�ʱ����");
			scanf("%d",&(rec.duration));
			printf("��ӳ���ڣ�");
			scanf("");
			printf("��������:");
			scanf("");
			printf("Ʊ�ļ۸�:");
			scanf("%d",&(rec.price));
			printf("===================================================================\n\n");
			//��ȡ����ID��
			rec.id=EntKey_Srv_CompBewKey("Play");
			if(Play_Srv_Add(&rec))
			{
			newRecCount++;
			printf("��Ŀ��ӳɹ�\n");
			flag=1;
			}
			else 
			{printf("��Ŀ���ʧ��\n");flag=2;}
			printf("[A]�������  [R]���ز˵�\n");
			fflush(stdin);
			scanf("%c",&choice);
		//	return flag;
		if(choice!='a'||choice!='A')
			return newRecCount;
		}while(choice=='a'||choice=='A');
	return 0;
}

/*
 * Function:    Play_UI_Modify
 * Function ID:	TTMS_SCU_Play_UI_Mod
 * Description: ���¾�Ŀ��Ϣ
 * Input:       �����µľ�ĿID��
 * Output:      ������Ϣʱ�ĸ�����ʾ
 * Return:      ���µľ�Ŀ��Ϣ����0��ʾδ�ҵ���1��ʾ�ҵ�������
 */
int Play_UI_Modify(int id){
	int flag=2,rtn=0;
	play_t rec;
	flag=Play_UI_Query(id);
	if(flag==1)
	{
		printf("%5s%10s%10s%10s%12s%10s%12s%12s%10s","��Ŀ����","��Ŀ����","��Ŀ��Ʒ����","��Ŀ�ȼ�","��ӳʱ��","��ʼ��ӳʱ��","������ӳʱ��","Ʊ��");
		printf("%-5d%6s%6s%6s%6s%5d%6s%6s%5d",rec.id,rec.name,rec.type,rec.area,rec.rating,rec.duration,rec.start_date,rec.end_date,rec.price);
   		    printf("��ϢID��:");
            scanf("%d",&(rec.id));
            printf("��Ŀ���ƣ�");
            scanf("%c",rec.name);
            printf("��Ŀ����  1:��Ӱ 2����� 3�����ֻ�\n");
            scanf("%d",&(rec.rating));
            printf("��Ŀ��Դ�أ�");
            scanf("%s",rec.area);
            printf("��Ŀ���� 1����ͯ���Թۿ� 2��������ɹۿ� 3�����˿ɹۿ�\
n");
            printf("�ݳ�ʱ����");
            scanf("%d",&(rec.duration));
            printf("��ӳ���ڣ�");
            /*scanf("");
            printf("��������:");
            scanf("");
            printf("Ʊ�ļ۸�:");
            scanf("%d",&(rec.price));*/
 			rtn=Play_Srv_Modify(&rec);
			if(rtn==1)
			printf("Modify  �ɹ�\n");
			else printf("Modify  ʧ��\n");
			return rtn;
		}
		else return 0;
}

/*
 * Function:    Play_UI_Delete
 * Function ID:	TTMS_SCU_Play_UI_Del
 * Description: ����ID��ɾ����Ŀ��Ϣ
 * Input:       ��ɾ���ľ�ĿID��
 * Output:      ��ʾɾ���Ƿ�ɹ�
 * Return:      0��ʾɾ��ʧ�ܣ�1��ʾɾ���ɹ�
 */
int Play_UI_Delete(int id){
	int rtn=0;
	if(Play_UI_Query(id))
	{
			printf("���ڴ˾�Ŀ��������ɾ��\n");
		if(Play_Srv_DeleteByID(id))
		{
			printf("ɾ���ɹ�\n");
			rtn=1;}
		else printf("ɾ��ʧ��\n");
		return rtn;
	}
	else printf("�˾�Ŀ������\n");			
	return 0;
}

/*
 * Function:    Play_UI_Query
 * Function ID:	TTMS_SCU_Play_UI_Qry
 * Description: ����ID�Ų�ѯ��Ŀ��Ϣ
 * Input:       �����ҵľ�ĿID��
 * Output:      ���ҵ��ľ�Ŀ��Ϣ
 * Return:      0��ʾδ�ҵ���1��ʾ�ҵ���
 */
int Play_UI_Query(int id){
	int rtn=0;
	play_t p;
	if(Play_Srv_FetchByID(id,&p))
	{
		printf("�˾�Ŀ����\n");
		rtn=1;
		return rtn;	
	}
	else printf("�˾�Ŀ������\n");
	return 0;
}
//�޸ģ����Թ���

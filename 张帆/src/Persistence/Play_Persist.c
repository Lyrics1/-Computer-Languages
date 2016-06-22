/*
* File name:  Play_Persist.c
* File ID:	  TTMS_SSF_Play_Perst_Sour
* Author:     Huang Ru
* Version:    V1.0
* Date: 	  2015-04-25
*/


#include "Play_Persist.h"
#include "../Service/Play.h"
#include "../Common/list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

static const char PLAY_DATA_FILE[] = "Play.dat";//保存剧目信息
static const char PLAY_DATA_TEMP_FILE[] = "PlayTmp.dat";//删除或更新时，暂时保存剧目信息

/*
 * Function:    Play_Perst_Insert
 * Function ID:	TTMS_SCU_Play_Perst_Insert
 * Description: 在剧目信息文件末尾写入一条剧目信息
 * Input:       待加入文件的剧目信息数据
 * Output:      打开文件失败的信息
 * Return:      写入文件的记录数
 */
int Play_Perst_Insert(const play_t *data) {
	assert(NULL!=data);
	FILE *fp;
	fp=fopen(PLAY_DATA_FILE,"ab");
	int rtn=0;
	if(fp == NULL){
		printf("Cannot open file Play.dat!\n");
		return 0;
	}

	rtn=fwrite(data,sizeof(play_t),1,fp);
	fclose(fp);
	return rtn;
}

/*
 * Function:    Play_Perst_Update
 * Function ID:	TTMS_SCU_Play_Perst_Mod
 * Description: 按照剧目ID号更新文件中的剧目信息
 * Input:       待在文件中更新的剧目信息数据
 * Output:      打开文件失败的信息
 * Return:      更新的剧目信息数，0表示未找到，1表示找到并更新
 */
int Play_Perst_Update(const play_t *data) {
	int Found=0;
	FILE *fp;
	play_t buf;
	fp=fopen(PLAY_DATA_FILE,"rb+");
	if(fp==NULL){
	printf("Cannot open file Play.dat!\n");

	return 0;
	}

		while(!feof(fp))
		{
			if(fread(&buf,sizeof(play_t),1,fp))
			{
				if(buf.id == data->id)
				{
					fseek(fp,-sizeof(play_t),SEEK_CUR);//文件读写回撤到前一条记录
					fwrite(data,sizeof(play_t),1,fp);
					Found = 1;
					break;
				}
			}
		}
	fclose(fp);
	return Found;
}


/*
 * Function:    Play_Perst_DeleteByID
 * Function ID:	TTMS_SCU_Play_Perst_DelByID
 * Description: 按照剧目ID号删除剧目的信息
 * Input:       待删除的剧目ID号
 * Output:      打开文件失败的信息
 * Return:      0表示删除失败，1表示删除成功
 */
int Play_Perst_DeleteByID(int ID) {
	if(rename(PLAY_DATA_FILE,PLAY_DATA_TEMP_FILE)<0){
		printf("Cannot open file Play.dat!\n");
		return 0;
	}	
	FILE *fpsour;/*临时文件*/
	FILE *fpTarg;//原来的文件
	if((fpsour=fopen(PLAY_DATA_TEMP_FILE,"rb"))==NULL)
		{
		printf("Cannot open file Play.dat!\n");
        return 0;
    }
	if((fpTarg=fopen(PLAY_DATA_FILE,"wb"))==NULL)
		{
		printf("Cannot open file Play.dat!\n");
        return 0;
    }
	play_t buf;
	int Found=0;
	while(!feof(fpsour)){
	if(fread(&buf,sizeof(play_t),1,fpsour)){
		if(ID==buf.id){
			Found=1;
			continue;
		}
	fwrite(&buf,sizeof(play_t),1,fpTarg);
	}
}
fclose(fpsour);
fclose(fpTarg);
//删除临时文件
remove("PlayTmp.dat");
return Found;
}


/*
 * Function:    Play_Perst_SelectByID
 * Function ID:	TTMS_SCU_Play_Perst_SelByID
 * Description: 按照剧目ID号查找剧目的信息
 * Input:       待查找的剧目ID号，保存查找结果的内存的地址
 * Output:      无
 * Return:      0表示未找到，1表示找到了
 */
int Play_Perst_SelectByID(int ID, play_t *buf) {
	assert(buf!=NULL);
	FILE *fp=fopen(PLAY_DATA_FILE,"rb");
	if(fp==NULL){
		printf("Cannot open file Play_t!\n");
		return 0;
	}
	
	play_t data;
	int Found=0;
	
	while(!feof(fp)){
		if(fread(&data,sizeof(play_t),1,fp)){
			if(ID==data.id){
				buf->id=data.id;
				Found=1;
				break;
			};
		}
	}
	fclose(fp);
	return Found;
}


/*
 * Function:    Play_Perst_SelectAll
 * Function ID:	TTMS_SCU_Play_Perst_SelAll
 * Description: 将所有剧目信息建立成一条链表
 * Input:       list剧目信息链表的头指针
 * Output:      提示建立链表时，申请空间失败
 * Return:      返回查找到的记录数目
 */
int Play_Perst_SelectAll(play_list_t list) {
	play_node_t *newNode;
	play_t data;
	int recCount=0;

	//arrest(list!=NULL);
	
	List_Free(list ,play_node_t);
	
	FILE *fp =fopen(PLAY_DATA_FILE,"rb");
	if(fp==NULL){
	printf("Cannot open file Play.data!");
	return 0;
	}
	while(!feof(fp)){
		if(fread(&data,sizeof(play_t),1,fp)){
			newNode=(play_node_t *)malloc(sizeof(play_node_t));
			if(!newNode){
				printf("warning, Memory OverFlow!!! \ncannot load more data into memory!!\n");
				break;
			}
			newNode->data=data;
			//List_Addtail(list,newNode);
			recCount++;
		}	
	}	
	fclose(fp);
	return recCount;
}


/*
 * Function:    Play_Perst_SelectByName
 * Function ID:	TTMS_SCU_Play_Perst_SelByName
 * Description: 按照剧目名称查找剧目的信息
 * Input:       list为查找到的剧目信息链表，condt为模糊查询的关键字
 * Output:      提示建立链表时，申请空间失败
 * Return:      返回查找到的记录数目
 */
int Play_Perst_SelectByName(play_list_t list, char condt[]) {
	int recCount=0;
	FILE *fp;
	play_node_t *newNode;
	//play_list_t p;
	//p=list;
	if((fp=fopen(PLAY_DATA_FILE,"rb"))==NULL){
		printf("cannot open file Play.dat!");
		return 0;
	}
	assert(list!=NULL);
	List_Free(list,play_node_t);
	play_t buf;
	while(!feof(fp)){

		if(fread(&buf,sizeof(play_t),1,fp)){

			if(strstr(buf.name,condt)!=NULL){
	
		newNode=(play_node_t *)malloc(sizeof(play_node_t));
		if(!newNode){
		 printf(
                        "Warning, Memory OverFlow!!!\n Cannot Load more Data into memory!!!\n");
                	break;
            	}
			newNode->data=buf;
			List_AddTail(list,newNode);
			recCount++;
		}
	}
	}
	fclose(fp);
	return recCount;
}
	//xiugai 

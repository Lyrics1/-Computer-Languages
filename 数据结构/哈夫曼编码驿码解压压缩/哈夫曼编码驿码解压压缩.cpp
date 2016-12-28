#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#define MAX 256
#define ZMAX 2000
#define NMAX 30
typedef struct {
	char data;
	int weight;
	int parent,Rchild,Lchild;
	int tag;
} HfNode,hf[ZMAX];
typedef char* hfcode[MAX];//编码类型定义

//函数声明

int Read(char name[],int znum[],hf h);
void creathf(hf h,int n);
void select(hf h,int n,int *s1,int *s2);
void translation(hf h,int n,hfcode hc,char name[],char recodename[]);

void creathuffCode1(hf h,hfcode hc,int n);
void printnum(hfcode hc,hf h,int n,char name[],char translation[],char codename[]);
void  conv(char c[],char jiecomname[],char codename[] );




//读文件
int Read(char name[],int znum[],hf h) {

	char buffer;
	int i,j,count=0,fileLen=0,tagnum=0;
	HfNode temp;
	FILE *infile,*outfile;
	infile=fopen(name,"rb");
	//判断文件是否存在
	if(infile==NULL) {
		printf("文件不存在！");
		return-1;
	}
	for(i=0; i<MAX; i++) //初始化标记
		h[i].tag=-1;


	//先给buff分配空间
	fread((char*)&buffer,sizeof(char),1,infile);
	while(!feof(infile)) { //判断文件是否结束，0表示没有结束，非0表示结束
		znum[buffer]++;
		if(h[buffer].tag==-1) {
			tagnum++;
			h[buffer].tag=tagnum;
		}
		fileLen++;
		h[buffer].data=buffer;
		h[buffer].weight++;
		//	printf("%c,%d\n",buffer,buffer-'a');//输出读出的字符
		if(buffer<0)
			printf("遇到汉字");
		fread((char*)&buffer,sizeof(char),1,infile);
	}


	fclose(infile);
	//将频度为0的字符排到后面
	for(i=0; i<MAX-1; i++)
		for(j=i+1; j<MAX; j++) {
			if(h[i].weight<h[j].weight) {
				temp=h[i];
				h[i]=h[j];
				h[j]=temp;
			}
		}
	//计算非零个数，也就是哈夫曼节点初始个数（2种方法）
	for(i=0; i<MAX; i++)
		if(h[i].weight!=0) {
			count++;
			//printf("%c,%d,%d,%d\n",h[i].data ,h[i].data -'a',i,h[i].weight);
		}

//		for(i=0;i<MAX;i++)
//		  	if(h[i].weight==0)
//		  		break;
//		count=i; //i就是节点数；因为刚才已经排好序了
//		int hufnum=2*count+1;//计算哈夫曼所需节点数
//	printf("read end\n");
	//	printf("%c,%d,%d,%d",h[1].data ,h[1].data -'a',1,h[1].weight);
	return count;
}


//开始建立哈夫曼树
void creathf(hf h,int n) {
	int weight;
	int m=2*n-1;
	int i,temp;
	int s1,s2;

	for(i=n; i<=m; i++) {
		select(h,i-1,&s1,&s2);

		temp=h[s1].weight+h[s2].weight;

		h[i].weight=temp;

		h[i].Lchild=s1;
		h[i].Rchild=s2;
		h[s1].parent=h[s2].parent=i;

	}
}

void select(hf h,int n,int *s1,int *s2) {
	int i,j;
	int x1=0,x2=0;
	int m1 = 1000;
	int m2 = 1000;
	for (j=1; j<=n; j++) {
		if (h[j].weight < m1 && h[j].parent==0) {
			m2=m1;
			x2=x1;
			m1=h[j].weight;
			x1=j;
		} else if (h[j].weight < m2 && h[j].parent==0) {
			m2=h[j].weight;
			x2=j;
		}
	}
	*s1=x1;
	*s2=x2;

}

void output(hf h,int n) {
	int i=1;
	for(i=0; i<2*n-1; i++) {
		printf("%3d   p:%3d L：%d R:%d\n",h[i].weight,h[i].parent,h[i].Lchild,h[i].Rchild);
	}


}
//哈夫曼编码

void creathuffCode1(hf h,hfcode hc,int n) {
	char *cd;
	int start,p,i,c;
	cd=(char *)malloc(sizeof(char)*n);
	cd[n-1]='\0';
	for(i=0; i<n; i++) {
		start=n-1;
		c=i;
		p=h[i].parent;
		while(p!=0) {
			--start;
			if(h[p].Lchild==c)
				cd[start]='0';
			else cd[start]='1';
			c=p;
			p=h[p].parent;
		}
		hc[i]=(char *)malloc(sizeof(char)*(n-start));
		strcpy(hc[i],&cd[start]);
	}

	free(cd);
}
//读取单个字符并返回
//检验
void printnum(hfcode hc,hf h,int n,char name[],char translation[],char codename[]) {
	int i,j,k=1,t;
	char buffer;
	FILE *infile,*outfile,*codefile;
	infile=fopen(name,"rb");
	//判断文件是否存在
	if(infile==NULL) {
		printf("文件不存在！");
		return;
	}
	fread((char*)&buffer,sizeof(char),1,infile);
	while(!feof(infile)) { //判断文件是否结束，0表示没有结束，非0表示结束
		for(i=0; i<n; i++)
			if(h[i].data==buffer) {
//				printf("%s",hc[i]);
				//	printf("%c",h[i].data);
				strcat(translation,hc[i]);
			}

		fread((char*)&buffer,sizeof(char),1,infile);
	}
	fclose(infile);
	//存入编码,新建文件名为code.txt
	int L=strlen(translation);
	i=0;
	codefile=fopen(codename,"wb");
	if(codefile==NULL) {
		printf("文件不存在！");
		return;
	}
	while(i<L-1) {
		fwrite(&translation[i],sizeof(char),1,codefile);
		i++;
	}
	fclose(codefile);
}
//译码
void translation(hf h,int n,hfcode hc,char name[],char recodename[]) {
	char buffer,a[MAX];
	int i=0,j,p,t;
	FILE *infile,*outfile,*Recodefile;
	infile=fopen(name,"rb");
	//判断文件是否存在
	if(infile==NULL) {
		printf("文件不存在！");
		return;
	}
	fread((char*)&buffer,sizeof(char),1,infile);
	a[i]=buffer;
	i++;
	while(!feof(infile)) { //判断文件是否结束，0表示没有结束，非0表示结束
		fread((char*)&buffer,sizeof(char),1,infile);
		a[i]=buffer;
		i++;
	}

	fclose(infile);
	j=strlen(a);
//	printf("\nj:%d",j);
	Recodefile=fopen(recodename,"wb");
	if(Recodefile==NULL) {
		printf("文件不存在！");
		return;
	}
	a[j]='\0';
	p=2*n-1;
	for(i=0; i<=j; i++) {

		if(a[i]=='0')
			p=h[p].Lchild;
		if(a[i]=='1')
			p=h[p].Rchild;
		if(h[p].Lchild==0&&h[p].Rchild==0) {

			t=p;
//			printf("%c",h[t].data);
			fwrite(&h[t].data,sizeof(char),1,Recodefile);
			p=2*n-1;
		}

	}
	fclose(Recodefile) ;

}
// 压缩
void compress(char codename[],char compressname[]) {
	unsigned char buffer;
	int count=1,i=0,j,sum=0;
	char temp[ZMAX],tcode[9];//因为要按照8bit压缩
	FILE *filecode,*outfile;
	filecode=fopen(codename,"rb");
	outfile=fopen(compressname,"wb");

	if(outfile==NULL||filecode==NULL) {
		printf("文件不存在！");
		return;
	}
	i=0;
	fread((unsigned char*)&buffer,sizeof(char),1,filecode);
//	temp[i]=buffer;
//	i++;
	while(!feof(filecode)) {

		temp[i]=buffer;
		i++;
		fread((unsigned char*)&buffer,sizeof(char),1,filecode);
	}

	fclose(filecode);
	sum=0;
	j=strlen(temp);
	//	printf("%d\n",strlen(temp));

	while(j>=8) {
		for(i=0; i<8; i++) {
			if(temp[i]=='1')//按数字压缩
				sum+=pow(2,8-i-1);
//					temp <<= 1;
		}
//				printf("\n%d",sum);
		//	sprintf(tcode,"%d",sum);//数字转换为字符串因为要存储为二进制文件
//				printf("%c",sum);
		fwrite((char*)&sum,sizeof(char),1,outfile);
		strcpy(temp,temp+8);//覆盖前8位
		j=strlen(temp);
		sum=0;
	}

	//处理最后几个比bu满足8位的字符
	j=strlen(temp);
//			printf("\nj:%d\n,%s",j,temp);
	int k=0;
	sum=0;
	while(k<j&&j>0) { //00001001
		if(temp[k]=='1')//按数字压缩
			sum+=pow(2,j-k-1);
		//	temp<<=1;
		k++;
	}
 
			printf("%d\t%c\n",sum,sum);

//			sprintf(tcode,"%d",sum);
	fwrite((char*)&sum,sizeof(char),1,outfile);
	fclose(outfile);
}
//解压
void jiecompress(char compressname[],char jiecomname[],char codename[]) {
	FILE *infile,*outfile;
	int temp,i,j,k,codetemp,o,tag;
	char tcode[30],buffer;
	outfile=fopen(jiecomname,"wb");
	infile=fopen(compressname,"rb");
	if(outfile==NULL||infile==NULL) {
		printf("文件打开错误\n");
		return;
	}
	int p=0;
	fread(&buffer,sizeof(char),1,infile);//与存储文件时保持一致
//	int fno = fileno(infile);  //
//	int fsize = filelength(fno);   //
	int fsize=ZMAX;
	char hanzi[fsize];
	while(!feof(infile)) {
		fsize++;
		hanzi[p++] = buffer;
		fread((char*)&buffer,sizeof(char),1,infile);

	}

	hanzi[p] = '\0';
	conv(hanzi,jiecomname,codename);

	fclose(infile);
	fclose(outfile);
}
//处理汉字
void  conv(char c[],char jiecomname[],char codename[] )
 {
	FILE *outfile,*infile;
	char tcode[30],buffer;
	int temp=0,mod=0;

	outfile=fopen(jiecomname,"wb");
	infile = fopen(codename,"rb");
	if(outfile==NULL || infile==NULL)
		return;
	fread((char*)&buffer,sizeof(char),1,infile);
	while(!feof(infile))	
	{
		temp++;
		fread((char*)&buffer,sizeof(char),1,infile);	
	}
	fclose(infile);
	mod=temp%8;
//	printf("%d",strlen(c));
	char ch[9] = {'\0'};

	char h[20];
	int i;
	int j = 0;
	int count = 0;
	char t[3] = {'\0'};
	while('\0' != c[j]) {
		for(i = 7; i >= 0; i--) {
			ch[i] = (c[j]&1)+'0';
			//右移
			c[j]>>=1;
		}
		//strcat(h,ch);
		j++;
		fwrite(&ch,sizeof(char),8,outfile);
	}
	itoa((int)(c[j]),ch,2);
	temp=j=strlen(ch);
//	printf("j:%dmod：%d\n",j,mod);

	for(i=mod-1;i>=0,j>0;i--)
	{
		ch[i]=ch[j-1];//10  0010
		j--;	
	} 
	for(i=0;i<temp;i++)
	{
		ch[i]='0';
	}
	ch[mod] ='\0';
//	for(i=0;i<)
	
//	printf("%s%d",ch,strlen(ch));
	
	fwrite(&ch,sizeof(char),strlen(ch),outfile);
	fclose(outfile);

}

int main(void) {
	int znum[MAX]= {0}; //每个字符出现的次数
	char s[ZMAX];//输入的字符
	char name1[MAX];//文件名
	int n;//初始节点数
	hf h;char b[MAX];
	char codename[10],recodename[10],compressname[10],jiecomname[10];
	printf("\t\t================我的哈夫曼解压压缩==================\n\n"); 
	printf("\t\t\t\t1:编码\n\t\t\t\t2:译码\n\t\t\t\t3:压缩\n\t\t\t\t4:解压\n\t\t\t\t0:退出\n\n");
	printf("\t\t请输入你所要解压的文件名：例如：z.txt :");
	gets(name1);
	hfcode hc;
	int chance;
		//开始读文件然后存储哈弗树初始节点；
	n=Read(name1,znum,h);
//	printf("n:%d\n",n);
	creathf(h,n);
	//output(h,n);//检验哈夫曼树的正确性
	creathuffCode1(h,hc, n);

	printf("请输入你的选择："); 
	scanf("%d",&chance);
	while(chance!=0)
	{
		switch(chance)
		{
			case 1: printf("\n你所要存储编码的文件名：code.txt\n");
			getchar();
//					gets(codename);
					printnum(hc,h,n,name1,b,"code.txt");break;
			case 2:	printf("\n你所要存储的以码文件名：recode.txt\n");
			getchar();
			printnum(hc,h,n,name1,b,"code.txt");
//					gets(recodename);
					translation(h,n,hc,"code.txt","recode.txt");break;
			case 3:	printf("\n你所要存储压缩文件的文件名：:stor.txt\n");
			getchar();
			printnum(hc,h,n,name1,b,"code.txt");
			translation(h,n,hc,"code.txt","recode.txt");
//					gets(compressname);
					compress("code.txt", "stor.txt");break;
			case 4: printf("\n你所要解压存储的文件名：jie.txt\n");
			getchar();
			printnum(hc,h,n,name1,b,"code.txt");
			translation(h,n,hc,"code.txt","recode.txt");
			compress("code.txt", "stor.txt");
//					gets(jiecomname);
					jiecompress("stor.txt","jie.txt","code.txt") ;
		}
			printf("\n请输入你的选择："); 
		scanf("%d",&chance);
	}

	
	
	
	
}






#include<stdio.h>
#include<stdlib.h>
#include "¶þ²æÊ÷.cpp"
typedef struct  
  {
  	Bitree data[M];
  	int rear,front;
  }*seQueue;
  
  void init(seQueue  *s)
  {
  	*s=(seQueue)malloc(sizeof(seQueue));
  	if(*s==NULL)
  		return;
  	(*s)->rear=-1;
  	(*s)->front=-1;
  }
  
  int IsEmpty(seQueue s)
  {
  	if(s->front==s->rear)
  		return 0;
  	else return 1;
  	
  }
  
  void push(seQueue s,Bitree root)
  {
  	if(s->rear==M-1)
  		return;//¶ÓÂú
	else{
		s->rear++;
		s->data[s->rear]=root;
	} 
  }
Bitree pop(seQueue s)
  {
  	Bitree temp;
  	if(IsEmpty(s)==0)
  		return;
  	else {
  		temp=s->data[s->rear];
  		s->rear--;
  		return temp;
	  }
  }

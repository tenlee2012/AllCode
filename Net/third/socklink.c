#include"socklink.h"
#include"sockutil.h"
#include<stdio.h>
#include<stdlib.h>

pSockEle linkHead,linkTail;
static int      linkSize;

static pSockEle Linkmalloc(int sock,pthread_t tid)
{
	pSockEle p=(pSockEle)malloc(sizeof(struct SockEle));
	p->sock=sock;
	p->tid=tid;
	p->next=NULL;
}

void linkInsert(int sock,pthread_t tid)
{
	pSockEle p;
	if(sock<0)
		errexit("linkInsert err");
	p=Linkmalloc(sock,tid);
	if(linkHead==NULL)
		linkHead=linkTail=p;
	else
	{
		linkTail->next=p;
		linkTail=p;
	}
	linkSize++;
}
void linkDelete(int sock)
{
	pSockEle p,it;
	if(sock<0)
		errexit("linkDelete err");	
	for(p=linkHead;p!=NULL;p=p->next)
	{
		if(p->sock==sock)
		{
			if(linkHead==linkTail)
				linkHead=linkTail=NULL;
			else if(p==linkHead)
				linkHead=linkHead->next;
			else if(p==linkTail)
			{
				//找出尾部元素的前一个对象 
				for(it=linkHead;it->next!=linkTail;it=it->next)
					;
				it->next=NULL;
				linkTail=it;
			}
			else
			{
				//找出待删除元素的前一个对象 
				for(it=linkHead;it->next!=p;it=it->next)
					;
				it->next=p->next; 
			}	
			break;
		}
	}
	if(p!=NULL)
	{
		free(p);
		linkSize--;	
	}
}
void linkPrint(void)
{
	pSockEle p;
	for(p=linkHead;p!=NULL;p=p->next)
		printf("%d ",p->sock);
	printf("\n");
}
int linkGetSize(void)
{
	return linkSize;
}

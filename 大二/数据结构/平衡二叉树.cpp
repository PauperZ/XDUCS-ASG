#include<stdio.h>
#include<stdlib.h>

#define LH +1
#define EH 0
#define RH -1
#define NULL 0

typedef struct BSTNode {
	int data;
	int bf;
	struct BSTNode *lchild,*rchild;
} BSTNode,*BSTree;

void CreatBST(BSTree &T);
void R_Rotate (BSTree &p);
void L_Rotate(BSTree &p);
void LeftBalance(BSTree &T);
void RightBalance(BSTree &T);
bool InsertAVL(BSTree &T,int e,bool &taller);
bool SearchBST(BSTree &T,int key);
void LeftBalance_div(BSTree &p,int &shorter);
void RightBalance_div(BSTree &p,int &shorter);
void Delete(BSTree q,BSTree  &r,int &shorter);
int DeleteAVL(BSTree &p,int x,int &shorter);
void PrintBST(BSTree T,int depth);

int main() {
	BSTree T;
	int sear,cmd,depth;
	char ch;
	int shorter=0;
	bool taller=false;
	T=(BSTree)malloc(sizeof(BSTNode));
	T=NULL;
	printf("****************ƽ��������Ĳ����˵�****************\n");
	printf("                    1--����\n");
	printf("                    2--����\n");
	printf("                    3--����\n");
	printf("                    4--ɾ��\n");
	printf("                    5--�˳�\n");
	printf("****************************************************\n");
	do {
		printf("\n��ѡ������ı�ţ�");
		scanf("%d",&cmd);
		getchar();
		switch(cmd) {
			case 1:
				CreatBST(T);
				break;
			case 2:
				printf("��������Ҫ���ҵĹؼ��֣�");
				scanf("%d",&sear);
				getchar();
				if(SearchBST(T,sear)) printf("�ؼ���%d���ڣ����ҳɹ�!\n",sear);
				else printf("����ʧ��!\n");
				break;
			case 3:
				printf("��������Ҫ����Ĺؼ��֣�");
				scanf("%d",&sear);
				getchar;
				InsertAVL(T,sear,taller);
				depth=0;
				PrintBST(T,depth);
				break;
			case 4:
				depth=0;
				printf("��������Ҫɾ���Ĺؼ���: ");
				scanf("%d",&sear);
				getchar();
				DeleteAVL(T,sear,shorter);
				PrintBST(T,depth);
				break;
			case 5:
				printf("����!\n");
				break;
			default:
				printf("�������!\n");
		}
		if(cmd==5)
			break;
		printf("\n������? y/n: ");
		scanf("%s",&ch);
		getchar();
		printf("\n");
	} while(ch=='y');
	printf("\n");
	
	return 0;
}

void CreatBST(BSTree &T) {
	int depth;
	int e;
	bool taller=false;
	T = NULL;
	printf("\n������ؼ���(��-114514��������ƽ�������):");
	scanf("%d",&e);
	getchar();
	while(e != -114514) {
		InsertAVL(T,e,taller);
		printf("\n������ؼ���(��-114514��������ƽ�������):");
		scanf("%d",&e);
		getchar();
		taller=false;
	}
	depth=0;
	printf("\n****************************************************\n");
	printf("                 �������Ķ�����Ϊ\n");
	if(T)
		PrintBST(T,depth);
	else
		printf("����һ�ÿ���!\n");
}

void R_Rotate (BSTree &p) {  //����*pΪ���Ķ�������������������
	BSTree lc;
	lc=p->lchild;
	p->lchild=lc->rchild;
	lc->rchild=p;
	p=lc;
}

void L_Rotate(BSTree &p) { //����*pΪ���Ķ�������������������
	BSTree rc;
	rc=p->rchild;
	p->rchild=rc->lchild;
	rc->lchild=p;
	p=rc;
}

void LeftBalance(BSTree &T) {  //����ָ�����ָ���Ϊ���Ķ���������ƽ����ת����
	BSTree lc,rd;
	lc=T->lchild;
	switch(lc->bf) {
		case LH:
			T->bf=lc->bf=EH;
			R_Rotate(T);
			break;
		case RH:
			rd=lc->rchild;
			switch(rd->bf) {
				case LH:
					T->bf=RH;
					lc->bf=EH;
					break;
				case EH:
					T->bf=lc->bf=EH;
					break;
				case RH:
					T->bf=EH;
					lc->bf=LH;
					break;
			}
			rd->bf=EH;
			L_Rotate(T->lchild);
			R_Rotate(T);
	}
}

void RightBalance(BSTree &T) {   //����ָ�����ָ���Ϊ���Ķ���������ƽ����ת����
	BSTree rc,ld;
	rc=T->rchild;
	switch(rc->bf) {
		case RH:
			T->bf=rc->bf=EH;
			L_Rotate(T);
			break;
		case LH:
			ld=rc->lchild;
			switch(ld->bf) {
				case RH:
					T->bf=LH;
					rc->bf=EH;
					break;
				case EH:
					T->bf=rc->bf=EH;
					break;
				case LH:
					T->bf=EH;
					rc->bf=RH;
					break;
			}
			ld->bf=EH;
			R_Rotate(T->rchild);
			L_Rotate(T);
	}
}

bool InsertAVL(BSTree &T,int e,bool &taller) { //������e
	if(!T) {
		T=(BSTree)malloc(sizeof(BSTNode));
		T->data=e;
		T->lchild=T->rchild=NULL;
		T->bf=EH;
		taller=true;
	} else {
		if(e==T->data) {
			taller=false;
			printf("�Ѵ�����ͬ�ؼ��ֵĽ��!\n");
			return 0;
		}
		if(e<T->data) {
			if(!InsertAVL(T->lchild,e,taller))
				return 0;
			if(taller)
				switch(T->bf) {
					case LH:
						LeftBalance(T);
						taller=false;
						break;
					case EH:
						T->bf=LH;
						taller=true;
						break;
					case RH:
						T->bf=EH;
						taller=false;
						break;
				}
		} else {
			if(!InsertAVL(T->rchild,e,taller))
				return 0;
			if(taller)
				switch(T->bf) {
					case LH:
						T->bf=EH;
						taller=false;
						break;
					case EH:
						T->bf=RH;
						taller=true;
						break;
					case RH:
						RightBalance(T);
						taller=false;
						break;
				}
		}
	}
}

bool SearchBST(BSTree &T,int key) { //����Ԫ��key�Ƿ���������
	if(!T)
		return false;
	else if(key==T->data)
		return true;
	else if(key<T->data)
		return SearchBST(T->lchild,key);
	else
		return SearchBST(T->rchild,key);
}

void LeftBalance_div(BSTree &p,int &shorter) {   //ɾ�����ʱ��ƽ����ת����
	BSTree  p1,p2;
	if(p->bf==1) {
		p->bf=0;
		shorter=1;
	} else if(p->bf==0) {
		p->bf=-1;
		shorter=0;
	} else {
		p1=p->rchild;
		if(p1->bf==0) {
			L_Rotate(p);
			p1->bf=1;
			p->bf=-1;
			shorter=0;
		} else if(p1->bf==-1) {
			L_Rotate(p);
			p1->bf=p->bf=0;
			shorter=1;
		} else {
			p2=p1->lchild;
			p1->lchild=p2->rchild;
			p2->rchild=p1;
			p->rchild=p2->lchild;
			p2->lchild=p;
			if(p2->bf==0) {
				p->bf=0;
				p1->bf=0;
			} else if(p2->bf==-1) {
				p->bf=1;
				p1->bf=0;
			} else {
				p->bf=0;
				p1->bf=-1;
			}
			p2->bf=0;
			p=p2;
			shorter=1;
		}
	}

}

void RightBalance_div(BSTree &p,int &shorter) {  //ɾ�����ʱ��ƽ����ת����
	BSTree  p1,p2;
	if(p->bf==-1) {
		p->bf=0;
		shorter=1;
	} else if(p->bf==0) {
		p->bf=1;
		shorter=0;
	} else {
		p1=p->lchild;
		if(p1->bf==0) {
			R_Rotate(p);
			p1->bf=-1;
			p->bf=1;
			shorter=0;
		} else if(p1->bf==1) {
			R_Rotate(p);
			p1->bf=p->bf=0;
			shorter=1;
		} else {
			p2=p1->rchild;
			p1->rchild=p2->lchild;
			p2->lchild=p1;
			p->lchild=p2->rchild;
			p2->rchild=p;
			if(p2->bf==0) {
				p->bf=0;
				p1->bf=0;
			} else if(p2->bf==1) {
				p->bf=-1;
				p1->bf=0;
			} else {
				p->bf=0;
				p1->bf=1;
			}
			p2->bf=0;
			p=p2;
			shorter=1;
		}
	}
}

void Delete(BSTree q,BSTree  &r,int &shorter) {       //ɾ�����
	if(r->rchild==NULL) {
		q->data=r->data;
		q=r;
		r=r->lchild;
		free(q);
		shorter=1;
	} else {
		Delete(q,r->rchild,shorter);
		if(shorter==1)
			RightBalance_div(r,shorter);
	}
}

int DeleteAVL(BSTree &p,int x,int &shorter) {    //ƽ���������ɾ������
	int k;
	BSTree q;
	if(p==NULL)  {
		printf("������Ҫɾ���Ĺؼ���!\n");
		return 0;
	} else if(x<p->data) {
		k=DeleteAVL(p->lchild,x,shorter);
		if(shorter==1)
			LeftBalance_div(p,shorter);
		return k;
	} else if(x>p->data) {
		k=DeleteAVL(p->rchild,x,shorter);
		if(shorter==1)
			RightBalance_div(p,shorter);
		return k;
	} else {
		q=p;
		if(p->rchild==NULL) {
			p=p->lchild;
			free(q);
			shorter=1;
		} else if(p->lchild==NULL) {
			p=p->rchild;
			free(q);
			shorter=1;
		} else {
			Delete(q,q->lchild,shorter);
			if(shorter==1)
				LeftBalance_div(p,shorter);
			p=q;
		}
		return 1;
	}
}

void PrintBST(BSTree T,int depth) {
	int i;
	if(T->rchild)
		PrintBST(T->rchild,depth+1);
	for(i=1; i<=depth; i++)
		printf("     ");
	printf("%d\n",T->data);
	if(T->lchild)
		PrintBST(T->lchild,depth+1);
}

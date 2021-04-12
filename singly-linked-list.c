/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode= NULL;

	printf("[----- [이연규] [2018038038] -----]\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		fflush(stdout);
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			fflush(stdout);
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			fflush(stdout);
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			fflush(stdout);
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			fflush(stdout);
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); //새로운 노드를 생성해준다.
	node->key = key; //입력받은 키값을 노드안에 넣어준다.

	node->link = h->first; //first가 가르키고 있는곳을 node가 가르킨다.
	h->first = node; // first가 노드를 가르키게 만든다.

	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	listNode *temp=(listNode *)malloc(sizeof(listNode));
	listNode *New=(listNode *)malloc(sizeof(listNode));
	listNode *pre=(listNode *)malloc(sizeof(listNode));
	New->key=key;
	New->link=NULL;
	pre->link=NULL;
	temp=h->first; //temp을 first가 가르키는 값으로 지정한다.

	if(h->first ==NULL){ // 현재 리스트가 공백인 경우에.
		h->first =New; //first가 New를 가르킬수 있게 만든다.
		return 0;
	}
	while(temp->key<key){//입력받은 키값보다 리스트안의 키값이 클때까지 반복한다.
		if(temp->link==NULL){
			temp->link=New;//모든 수보다 입력한 키값이 크다면 마지막에 넣어준다.
			return 0;	}
		pre=temp;
		temp=temp->link; //temp노드가 가르키는 곳을 temp로 바꾼다.
	}
	if(pre->link==NULL) //첫번째 값보다 작은경우.
	{
		New->link = h->first; //first가 가르키고 있는곳을 New가 가르킨다.
		h->first = New; // first가 New를 가르키게 만든다
		return 0;
	}
	New->link=pre->link; //temp노드가 가르키는 곳을 new도 가르키게한다.
	pre->link=New;//temp노드가 new를 가르키도록 지정한다.

	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {

	listNode* last;
		listNode* New =(listNode*)malloc(sizeof(listNode)); //새로운 노드를 할당해준다.
		New->link=NULL; //링크 필드는 아직 받지 않았기에 공백 할당.

			if(h !=NULL){ // 현재 리스트가 공백인 경우에.
				New->link = h->first; //first가 가르키고 있는곳을 new가 가르킨다.
					h->first = New; // first가 new를 가르키게 만든다.
				return 1;
			}
			last=h->first; //first가 가리키는 값을 last로 놓는다.
			while(last->link !=NULL){//last의 링크가 가르키는 값이 없을때까지 반복해 마지막 노드를 찾는다.
				last=last->link;//last노드가 가르키는 곳을 last로 바꾼다.
			}
			last->link=New; //last가 New를 가르키도록 지정한다.
			return 1;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
	listNode *del;
	if(h->first==NULL)return 0; // 공백일시 함수 나간다.
	del=h->first; //first가 del을 가르키게한다.

	h->first=h->first->link; //first가 first의 링크값을 가르키도록 지정.
	free(del); //del 할당해제

	return 1;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

	listNode *find =(listNode*)malloc(sizeof(listNode));
	listNode *pre =(listNode*)malloc(sizeof(listNode));
	listNode *del;
	pre->link=NULL;
	find=h->first; // first가 가르키는 값을 find로 놓는다.

	while(find->key !=key){//find의 키값과 같은 값이 나올때까지 반복해 원하는 노드를 찾는다.
		pre=find;//find값을 pre에 넣어준다.
		if(find->link==NULL) return 0; //모든 값이 다른경우 함수에서 나간다.
		del=find->link;//find가 가르키는 곳을 del이 가르키게 한다.
		find=find->link;//find노드가 가르키는 곳을 find로 바꾼다.
	}
	if(pre->link == NULL) h->first=h->first->link; // 첫번째 키가 같다면 첫번째 노드를 없애준다.
	pre->link=find->link; //find가 가르키고있는 값을 pre가 가르킨다.
	free(del);

	return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
	listNode *del;
	listNode *pre;

	pre=h->first; // 삭제할 노드의 앞의 노드를 첫번째로 지정.
	del=h->first->link; //삭제할 노드를 두번째로 지정.
	if(h->first==NULL) return -1; //빈노드면 종료.
	if(h->first->link==NULL) { //노드가 한개라면
		free(h->first); //그 노드의 할당 해제.
		h->first=NULL;
		return 0;
	}
	else{
		while(del->link !=NULL){//노드를 끝까지 반복한다.
			pre=del; //pre에 del값을 넣어준다.
			del=del->link; // del의 링크가 가르키는 값으로 del을 바꿔준다.
		}
		free(del); //del을 할당 해제해준다.
		pre->link=NULL;
	}

	return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {

	listNode *p,*q,*r;

	p=h->first; //역순으로 만들어줄 리스트.
	q=NULL; // 역순으로 만들어줄 노드.
	while(p!=NULL)
	{
		r=q; //r은q를, q는 p를 차례로 따라간다.

		q=p;
		p=p->link;
		q->link=r; //q의 링크 방향을 바꿔준다.
	}
	h->first=q; //first가 q를 가르키도록 바꿔준다.
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) { //리스트가 공백인 경우.
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {//리스트의 끝가지 반복.
		printf("[ [%d]=%d ] ", i, p->key); // 리스트의 키값 출력.
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}


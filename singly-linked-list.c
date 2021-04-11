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
	listNode *Pre;
	New->key=key;
	New->link=NULL;
	temp=h->first; //temp을 first가 가르키는 값으로 지정한다.

	if(h->first ==NULL){ // 현재 리스트가 공백인 경우에.
		h->first =New; //first가 New를 가르킬수 있게 만든다.
		return New;
	}
	while(temp->key>key) //입력받은 키값보다 리스트안의 키값이 클때까지 반복한다.
		temp=temp->link; //temp노드가 가르키는 곳을 temp로 바꾼다.
	New->link=temp->link; //temp노드가 가르키는 곳을 new도 가르키게한다.
	temp->link=New;//temp노드가 new를 가르키도록 지정한다.

	return New;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {

	listNode* last;
		listNode* New =(listNode*)malloc(sizeof(listNode)); //새로운 노드를 할당해준다.
		New->key=key; //노드안에 key값을 넣어준다.
		New->link=NULL; //링크 필드는 아직 받지 않았기에 공백 할당.

			if(h->first ==NULL){ // 현재 리스트가 공백인 경우에.
				h->first =New; //first가 New를 가르킬수 있게 만든다.
				return New;
			}
			last=h->first; //first가 가리키는 값을 last로 놓는다.
			while(last->link !=NULL) //last의 링크가 가르키는 값이 없을때까지 반복해 마지막 노드를 찾는다.
				last=last->link;//last노드가 가르키는 곳을 last로 바꾼다.
			last->link=New; //last가 New를 가르키도록 지정한다.
			return New;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {


	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

	return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {

	return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {

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

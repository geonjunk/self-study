# 07 연결리스트2 
* 참고) 일반적으로 연결리스트의 중간 위치에 노드 삽입, 삭제 시 선행노드(pre)가리키는 포인터 필요함 
## 7.1 원형 연결리스트 
### 원형 연결리스트의 개념
* 마지막 노드가 NULL이 아닌 첫 번째 노드를 가리키는 연결 리스트
* 하나의 노드에서 다른 모든 노드로 접근이 가능하다는 장점 가진다
* 즉, 삽입과 삭제가 단순 연결 리스트보다 유용할 수 있음 
	* 유용한 case : 변형된 원형 연결리스트) 단순 연결리스트는 끝에 노드 추가하려면 순차접근 해서 마지막 노드까지 가야 하는데 head포인터가 마지막 노드를 가리키도록 구성하면 상수 시간안에 리스트의 처음과 끝에 노드 삽입 삭제할 수 있다
###	변형된 원형 연결리스트의 처음과 끝의 삽입 구현 
* 원형 연결리스트는 앞뒤 구분이 불분명하므로 head위치 조정을 통해 구분해준다 
```
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode*link;
}ListNode;

ListNode*insert_last(ListNode*head,element e){
	ListNode*node=(ListNode*)malloc(sizeof(ListNode));
	node->data=e;
	if(head==NULL){
		head=node;
		head->link=head;//=node->link=head; 
	}else{
		node->link=head->link;
		head->link=node;
		head=node;
	}
	return head;
}
ListNode*insert_first(ListNode*head,element e){
	ListNode*node=(ListNode*)malloc(sizeof(ListNode));
	node->data=e;
	if(head==NULL){
		head=node;
		head->link=head;
	}else{
		node->link=head->link;
		head->link=node;
	}
	return head;
}
void print_list(ListNode*head){
    if(head==NULL)return;
	ListNode*temp=head->link;
	for(;temp!=head;temp=temp->link){
		printf("%d->",temp->data);
	} 
	printf("%d->",temp->data);
	printf("\n");
}

int main(){
	ListNode* head=NULL;
	
	head=insert_last(head,20);
	head=insert_last(head,30);
	head=insert_last(head,40);
	head=insert_first(head,10);
	print_list(head);
	return 0;
}

```
###	원형 연결리스트의 활용
* 멀티 플레이어 턴제 게임
* 원형 큐
* CPU의 응용프로그램 실행
	* 현재 실행중인 모든 응용 프로그램은 원형 연결 리스트에 보관되며 OS는 각 프로그램마다 고정된 시간 슬롯을 제공하여 모든 으용 프로그램 완료하기 전까지 OS는 연결리스트 순회함

## 7.2 이중 연결 리스트
### 이중 연결리스트의 개요
* 하나의 노드가 선행 노드아 후속 노드에 대한 두 개의 링크를 가지는 리스트 
* 양방향으로 자유롭게 움직일 필요가 있는 상황에서 사용하기 나온구조
* 후속 노드는 찾기 쉽지만 선행 노드는 찾기 어려운 연결리스트의 단점 개선을 위해 나옴
* 단, 코드가 복잡하며 공간 많이 사용함
* head node 개념 도입 
	* 데이터를 가지고 있지 않은 노드
	* 주의) 헤드포인터(첫번째 노드를 가리키는 포인터)랑은 다른 개념
* node의 구성 
	* 왼쪽 링크 필드
	* 오른쪽 링크 필드 
	* 데이터 필드	
### 이중 연결리스트의 구현
* 삽입 순서 : 새 노드 연결 후, 다른 노드 연결 값 변경
* 삭제 순서 : 다른 노드 연결 바꾼 후 삭제 
```
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DListNode{
	element data;
	struct DListNode*llink,*rlink;
}DListNode;

void init(DListNode*head){
	head->llink=head->rlink=head;
}
void dinsert(DListNode*before,element e){
	DListNode*node=(DListNode*)malloc(sizeof(DListNode));
	node->data=e;
	node->llink=before;
	node->rlink=before->rlink;
	//node에 연결 후 
	before->rlink->llink=node;
	before->rlink=node;
	//이전 연결 끊기 
}
void ddelete(DListNode*head,DListNode*removed){
	
	if(removed==head)return;
	removed->llink->rlink=removed->rlink;
	removed->rlink->llink=removed->llink;
	//연결 바꾼 후 
	free(removed);
	//제거 
}

void print_dlist(DListNode*head){
	DListNode*p=head->rlink;
	
	while(p!=head){
		printf("<-||%d|| -> ",p->data);
		p=p->rlink;
	}
	printf("\n");
	
}

int main(){
	DListNode*head=(DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계\n");
	int i;
	for(i=0;i<5;i++){
		dinsert(head,i);
		print_dlist(head);
	}
	printf("\n삭제단계\n");
	for(i=0;i<5;i++){
		print_dlist(head);
		ddelete(head,head->rlink);
	}
	free(head);
	return 0;
}


``` 
### 예제 : MP3 프로그램
* 참고
	* kbhit() : 입력 여부만 확인 (리턴 값이 0또는 1) 
	* getchar() : 입력 버퍼 사용, 엔터가 들어올 때까지 입력 담아둔 후 첫글자 리턴, 반복문에서 사용 시 버퍼 비워주는 작업 필요('\n'가 버퍼에 남아있음) 
	* getch() : 버퍼 사용 x, 키보드로 입력한 값 화면에 보여주지 않음 
	* getche() : 버퍼 사용x, 키보드로 입력한 값 화면에 보여줌 
	* 배열 형태 자료형 typedef할 때 : typedef 자료형 별명 [배열크기] 
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char element[100];
typedef struct DListNode{
	element data;
	struct DListNode*llink,*rlink;
}DListNode;

void init(DListNode*head){
	head->llink=head->rlink=head;
}
void dinsert(DListNode*before,element e){
	DListNode*node=(DListNode*)malloc(sizeof(DListNode));
	strcpy(node->data,e);
	node->llink=before;
	node->rlink=before->rlink;
	//node에 연결 후 
	before->rlink->llink=node;
	before->rlink=node;
	//이전 연결 끊기 
}
void ddelete(DListNode*head,DListNode*removed){
	
	if(removed==head)return;
	removed->llink->rlink=removed->rlink;
	removed->rlink->llink=removed->llink;
	free(removed);
}

void print_dlist(DListNode*head,DListNode*current){
	DListNode*p=head->rlink;
	
	while(p!=head){
		if(p==current) printf("<-||#%s#|| -> ",p->data);
	    else printf("<-||%s|| -> ",p->data);	
		p=p->rlink;
	}
	printf("\n");
	
}


int main(){
	DListNode*head=(DListNode*)malloc(sizeof(DListNode));
	init(head);
	
	dinsert(head,"Mamamia");
	dinsert(head,"Dancing Queen");
	dinsert(head,"Fernando");
	DListNode*current=head->rlink;
	char ch;
//	printf("Hello");
	print_dlist(head,current);
	do{

		printf("\n명령어를 입력하세요(<,>,q) : ");
		ch=getchar();
		if(ch=='>'){
			current=current->rlink;
			if(current==head)
			current=current->rlink;
		}else if(ch=='<'){
			current=current->llink;
			if(current==head)
			current=current->llink;
		}
		print_dlist(head,current);
		getchar();
	}while(ch!='q');
	
	free(head);
	return 0;
}

```
## 7.5 연결리스트로 구현한 스택과 큐
### 연결리스트로 구현한 스택
* 연결된 스택이라고 하며, 외부 인터페이스는 배열로 구현한 연결리스트와 같다
* 크기제한 없지만 동적할당 사용하기 때문에 삽입, 삭제에는 시간 걸린다
* top변수는 정수가 아닌 top에 있는 노드 가리키는 포인터로 설정(stack top pointer)
* top이 head 포인터랑 같은 역할 하며, top에서 삽입 삭제 일어남(stack의 특징) 
* 구현)
```
#include<stdio.h> 
#include<stdlib.h>
typedef int element;

typedef struct StackNode{
	element data;
	struct StackNode*link;
}StackNode;

typedef struct LinkedStackType{
	StackNode*top;//head랑 같은역할 
}LinkedStackType;

void print_stack(LinkedStackType*s){
	StackNode*p=s->top;
	for(;p!=NULL;p=p->link){
		printf("%d->",p->data);
	}
	printf("NULL\n");
}

void init(LinkedStackType*s){
	s->top=NULL;
}
void push(LinkedStackType*s,element data){
	StackNode*p=(StackNode*)malloc(sizeof(StackNode));
	p->data=data;
	p->link=s->top;
	s->top=p; //인자를 포인터로 받았으므로 실제값 변경가능 
}

element pop(LinkedStackType*head){
	StackNode*temp;
	element item;
	if(head->top!=NULL){
		temp=head->top;
		item=temp->data;
		head->top=head->top->link;
		free(temp);
	}
	return item;
}
int main(){
	LinkedStackType s;
	init(&s);
	push(&s,1);print_stack(&s);
	push(&s,2);print_stack(&s);
	push(&s,3);print_stack(&s);
	pop(&s);print_stack(&s);
	pop(&s);print_stack(&s);
	pop(&s);print_stack(&s);
	return 0;
}

```
### 연결리스트로 구현한 큐
* 연결된 큐(linked queue)라고 함
* 크기 제한은 없지만 배열에 비해 복잡하고 링크 필드때문에 메모리 공간 많이 사용
* 단순 연결리스트에서 front와 rear포인터가 추가된 구조
* 큐에 요소가 없으면 front와 rear가 NULL이됨 
* front,rear를 통해 삽입, 삭제 쉽게 함, 여기서는 front를 헤드 포인터라 생각 
```
#include<stdio.h> 
#include<stdlib.h>
typedef int element;

typedef struct QueueNode{
	element data;
	struct QueueNode*link;
}QueueNode;

typedef struct LinkedQueueType{
	QueueNode*rear,*front; //front를 head포인터로 
}LinkedQueueType;


void init(LinkedQueueType*q){
	q->front=q->rear=NULL;
}
int is_empty(LinkedQueueType*q){
	return q->front==NULL;
}
void enqueue(LinkedQueueType*q,element data){
	QueueNode*node=(QueueNode*)malloc(sizeof(QueueNode));
	node->link=NULL;
	node->data=data;
	
	if(is_empty(q))
		q->front=node;
	else
		q->rear->link=node;//rear다음에 삽입하면 됨 
	
	q->rear=node;	//삽입 후 rear 바꿔줌 
}
element dequeue(LinkedQueueType*q){
	
	if(is_empty(q)){
		fprintf(stderr,"큐가 비어있음\n");
		exit(1);
	}
	QueueNode*temp=q->front;
	element item=temp->data;
	q->front=q->front->link;
	
	if(q->front==NULL)q->rear=NULL;//삭제후 빈 큐인지 체크해서 바꿔줌
	 
	free(temp);
	return item;
	
	
}


void print_queue(LinkedQueueType*q){
	QueueNode*p=q->front;
	while(p!=NULL){
		printf("%d->",p->data);
		p=p->link;
	}
	printf("NULL\n");
}
int main(){
	LinkedQueueType queue;
	init(&queue);
	
	enqueue(&queue,1);print_queue(&queue); 
	enqueue(&queue,2);print_queue(&queue); 
	enqueue(&queue,3);print_queue(&queue); 
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	return 0;
}

```
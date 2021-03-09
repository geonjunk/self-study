# 05 큐(queue) 
## 5.1 큐의 개요
### 큐의 기본 
* FIFO(선입선출)구조
	* ex) 매표소에 줄서는 사람들 : 먼저 온 사람이 먼저 표 삼 
* 스택은 삽입과 삭제가 같은 쪽에서 일어나지만 큐는 삽입과 삭제가 다른 곳에서 일어남
	* 삽입 -> 후단(rear) 
	* 삭제 -> 전단(front)
* 큐의 사용예
	* 이륙하는 비행기들, 인터넷에서 전송되는 데이터 패킷들 등 현실세계의 실제 상황 
	* OS에서도 중요하게 사용되며, 주로 컴퓨터와 주변기기 사이의 큐 존재함 
		*ex)
	* 교통 관리 시스템 : 컴퓨터로 제어되는 신호등에서는 신호등을 순차적으로 제어하는데 원형큐 사용
	* CPU 스케줄링 : 운영체제에서 실행 가능한 프로세스들을 저장하거나 이벤트 기다리는 프로세스 저장하기 위하여 몇 개의 큐를 사용한다
	* 큐는 서로 다른 속도로 실행되는 두 프로세스 간의 상호 작용을 조화시키는 버퍼 역할을 담당
		* Ex) CPU와 프린터 사이 프린터 버퍼, CPU와 키보드 사이 키보드 버퍼 등
	* 생산자(데이터 생산)-소비자(데이터 소비) 프로세스 사이에 큐로 구성된 버퍼 존재, 일반 적으로 생산 속도가 소비하는 속도보다 빨라 큐가 포화상태가 될 가능성이 높음
		
 
### 큐의 ADT
* ADT QUEUE
```
* 객체 : 0개 이상의 요소들로 구성된 선형 리스트
* 연산 
	* create(max_size)::= 최대크기가 max_size인 공백큐를 생성한다
	* init(q)::= 큐 q를 초기화 한다
	* is_empty(q)::= 큐 q가 비어있는지 검사
	* is_full(q)::= 큐 q가 가득찼는지 검사
	* enqueue(q,e)::= 큐 q의 끝에 e를 추가한다
	* dequeue(q) ::= 큐 q의 맨 앞에 있는 e를 제거하여 반환한다
	* peek(q)::= 큐 q의 맨 앞에 있는 요소를 읽어서 반환한다 
```
* 스택에서 top 변수 1개만 이용해 삽입 삭제 가능하지만, 큐에서는 삽입은 rear, 삭제는 front변수 사용한다


## 5.2 선형 큐
### 선형 큐의 개요 
* 선형 큐 : 큐를 구현하는 가장 간단한 방법
	* 1차원 배열을 이용해서 구현
	* front 변수는 큐의 첫번째 요소 가리키며, rear는 큐의 마지막 요소 가리킴
		* 두 변수의 초기값은 -1
	* 데이터 추가되면 rear를 증가시켜 그 위치의 데이터 저장 
	* 데이터 삭제는 front값을 증가시키고 그 위치의 데이터 삭제 
* 이해하기는 쉽지만 front,rear값이 계속 증가만 하기 때문에 언젠간 배열의 끝부분의 도달하게 되고 이때 배열의 앞부분이 비어있어도 사용하지 못하는 문제점 발생
### 선형큐의 구현
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5 

typedef int element;
typedef struct Queue{
	int front;//맨앞 
	int rear;//맨뒤 
	element data[MAX_QUEUE_SIZE];
}Queue;
void init_queue(Queue*q){
	q->front=q->rear=-1;
}
int is_empty(Queue*q){
	return (q->front==q->rear);
}
int is_full(Queue*q){
	return (q->rear==MAX_QUEUE_SIZE-1);
}
void enqueue(Queue*q,element e){
	if(is_full(q)){
		fprintf(stderr,"queue is full");
		exit(1);
	}else q->data[++(q->rear)]=e;
	
}
element dequeue(Queue*q){
	if(is_empty(q)){
		fprintf(stderr,"queue is empty");
		return -1;
	}else {
		return q->data[++(q->front)];
	}
}

void queue_print(Queue*q){
    int i;
    for(i=0;i<MAX_QUEUE_SIZE;i++){
        if(i<=q->front||i>q->rear)printf(" | ");//if(i>q->front&&i<=q->rear) printf("%d | ",q->data[i]); -> 뭐가 더 빠를지 생각하면서 구현
        else printf("%d | ",q->data[i]);
    }
    printf("\n");
}

int main() {
    int item=0;
    Queue q;
    
    init_queue(&q);
    
    enqueue(&q,10);queue_print(&q);
    enqueue(&q,20);queue_print(&q);
    enqueue(&q,30);queue_print(&q);
    
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    
    return 0;
}

```
### 선형 큐의 응용 
* OS의 작업 스케줄링 
	* 한개의 CPU 구성에서 모든 작업들이 우선순위 갖지 않으면, 들어오는 순서대로 작업 처리한다(선형 큐)

## 5.3 원형 큐  
### 원형 큐의 개요
* 선형큐는 비어있는 공간 활용 못한다는 문제점 가짐
* 이를 해결하는 방법중 하나는 모든 요소를 front앞에 빈 공간 만큼 이동시키는 방법 있지만 매번 이동시켜야 하기 때문에 시간 상당히 소요되며 코딩 복잡해짐
* 따라서 이 문제점을 해결하기위해 배열을 선형이 아닌 원형으로 생각하여 개념상으로 원형으로 배열의 인덱스 변화시켜주는 방법 이용한다 
### 원형 큐의 구현
* front, rear값이 배열의 끝인 (MAX_QUEUE_SIZE-1)에 도달하면 다음에 바뀌는 값은 0이 되게한다
* **포화상태<->공백상태** 의 구분방법 
	* 방법 1) 하나의 자리를 항상 비워둔다
	* 방법 2) 요소의 개수 저장하는 count변수 이용한다
* front, rear를 원형으로 회전시킨다는 개념을 %연산자 이용해서 구현한다
* 코드
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5 

typedef int element;
typedef struct Queue{
	int front;//맨앞 
	int rear;//맨뒤 
	element data[MAX_QUEUE_SIZE];
}Queue;
void init_queue(Queue*q){
	q->front=q->rear=0;//한칸 비워두고 시작, -1로 시작하면 공백상태, 포화상태 구분 불가능 
}
int is_empty(Queue*q){
	return (q->front==q->rear);
}
int is_full(Queue*q){
    return (((q->rear+1)%MAX_QUEUE_SIZE)==q->front);
}
void enqueue(Queue*q,element e){
	if(is_full(q)){
		fprintf(stderr,"queue is full");
		exit(1);
	}else {
		q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
	    q->data[q->rear]=e;
	    printf("삽입 %d \n", e);
   }
}
element dequeue(Queue*q){
	if(is_empty(q)){
		fprintf(stderr,"queue is empty");
		return -1;
	}else {
		q->front=(q->front+1)%MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

void printQueue(Queue *q) {
	printf("Queue (front = %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		//	printf("%d %d\n", q->front,q->rear);
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
		} while (i != q->rear);
	}	
	printf("\n");
}


int main() {
	Queue q;
	element item;
 
	init_queue(&q);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&q))
	{
		printf("정수를 입력하시오: ");
		scanf_s("%d", &item);
		enqueue(&q, item);
		printQueue(&q);
	}
	printf("큐는 포화상태입니다.\n\n");
 
	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&q))
	{
		item = dequeue(&q);
		printf("꺼내진 정수 : %d \n", item);
		printQueue(&q);
	}
 
	printf("큐는 공백상태입니다. \n\n");
	
	return 0;
}


``` 
* 참고) 생산자-소비자 문제

## 5.4 덱(Deque)
### 덱의 정의 및 특징
* double ended quque의 줄임말 -> 즉, 큐의 front,rear에서 모두 삽입과 삭제가 가능한 큐
* 중간 삽입,  삭제는 허용하지 않음
* 스택과 큐의 연산 모두 갖고 있음
	* add_front/delete front : push/pop
	* add_rear/delete_front : enqueue/dequeue
* 스택과 큐보단 융통성있는 자료형
* 배열과 연결리스트로 구현 가능하다
* 덱의 ADT
	* 객체 : n개의 element형의 요소들의 순서 있는 모임
	* 연산 
		* create()::= 덱 생성
		* init(dq)::= 덱 초기화
		* is_empty(dq)::= 덱이 공백 상태인지를 검사한다
		* is_full(dq)::= 덱이 포화 상태인지를 검삼
		* add_front(dq,e)::= 덱의 앞에 요소를 추가한다 
		* add_rear(dq,e)::= 덱의 앞에 요소를 삭제한다 
		* delete_front(dq)::= 덱의 앞에 있는 요소를 반환한 다음 삭제한다.
		* delete_rear(dq)::= 덱의 뒤에 있는 요소를 반환한 다음 삭제한다.
		* get_front(q)::= 덱의 앞에서 삭제하지 않고 앞에 있는 요소를 반환한다.
		* get_rear(q) :: = 덱의 뒤에서 삭제하지 않고 뒤에 있는 요소를 반환한다.
### 덱의 구현
1. 배열을 이용한
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_DEQUE_SIZE 5 

typedef int element;
typedef struct Deque{
	int front;//맨앞 
	int rear;//맨뒤 
	element data[MAX_DEQUE_SIZE];
}Deque;
/*
	* create()::= 덱 생성
		* init(dq)::= 덱 초기화
		* is_empty(dq)::= 덱이 공백 상태인지를 검사한다
		* is_full(dq)::= 덱이 포화 상태인지를 검삼
		* add_front(dq,e)::= 덱의 앞에 요소를 추가한다 
		* add_rear(dq,e)::= 덱의 앞에 요소를 삭제한다 
		* delete_front(dq)::= 덱의 앞에 있는 요소를 반환한 다음 삭제한다.
		* delete_rear(dq)::= 덱의 뒤에 있는 요소를 반환한 다음 삭제한다.
		* get_front(q)::= 덱의 앞에서 삭제하지 않고 앞에 있는 요소를 반환한다.
		* get_rear(q) :: = 덱의 뒤에서 삭제하지 않고 뒤에 있는 요소를 반환한다.
*/
void init_deque(Deque*dq){
	dq->rear=dq->front=0;
}
int is_empty(Deque*dq){
	return (dq->rear==dq->front);
}
int is_full(Deque*dq){
	return (dq->front==(dq->rear+1)%MAX_DEQUE_SIZE);
}
void add_front(Deque*dq,element e){
	if(is_full(dq)){
		fprintf(stderr,"Deque is full");
		return;
	}else{
		dq->data[dq->front]=e;
		dq->front=((dq->front-1)+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
	}
		
}
void add_rear(Deque*dq,element e){//
	if(is_full(dq)){
		fprintf(stderr,"Deque is full");
		return;
	}else {
		dq->rear=(dq->rear+1)%MAX_DEQUE_SIZE;
		dq->data[dq->rear]=e;
	}
}
element delete_front(Deque*dq){//
	if(is_empty(dq)){
		fprintf(stderr,"Deque is empty");
        return -1;
	}else{
		dq->front=(dq->front+1)%MAX_DEQUE_SIZE;
		return dq->data[dq->front];
	}
}//실제로는  삭제안함 
element delete_rear(Deque*dq){
	 if(is_empty(dq)){
 		fprintf(stderr,"Deque is empty");
        return -1;
	 }else{
	 	element item=dq->data[dq->rear];
	 	dq->rear=((dq->rear-1)+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
		return item;
	 }
 }
 void deque_print(Deque*q){
    printf("DEQUE (front=%d rear=%d) =",q->front,q->rear);
    if(!is_empty(q)){
    int i= q->front;
    do{
       i=(i+1)%MAX_DEQUE_SIZE;
       printf(" %d |",q->data[i]);
       if(i==q->rear)//q->rear
       break;
	}while(i!=q->front); // rear까지는 프린트해야 함	 
}
    printf("\n");
    
}

int main() {
	Deque queue;
	
	init_deque(&queue);
	int i;
	for(i=0;i<3;i++){
		add_front(&queue,i);
		deque_print(&queue);
	}

	for(i=0;i<3;i++){
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}



```
2. 이중 연결리스트를 이용한 구현 


```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_QUEUE_SIZE 5 

typedef struct Customer{
	int id;
	int service_time;
	int arrival_time;
}Customer;
typedef struct Queue{
	int front;//맨앞 
	int rear;//맨뒤 
	Customer data[MAX_QUEUE_SIZE];
}Queue;
void init_queue(Queue*q){
	q->front=q->rear=0;//한칸 비워두고 시작, -1로 시작하면 공백상태, 포화상태 구분 불가능 
}
int is_empty(Queue*q){
	return (q->front==q->rear);
}
int is_full(Queue*q){
    return (((q->rear+1)%MAX_QUEUE_SIZE)==q->front);
}
void enqueue(Queue*q,Customer c){
	if(is_full(q)){
		fprintf(stderr,"queue is full");
		exit(1);
	}else {
		q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
	    q->data[q->rear]=c;
   }
}
Customer dequeue(Queue*q){
	if(is_empty(q)){
		fprintf(stderr,"queue is empty");
		exit(1);
	}else {
		q->front=(q->front+1)%MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}


int main() {
	int clock;
	Queue q;
	init_queue(&q);
	int total_customers=0;
	int total_wait_time=0;
	int service_time=0;
	
	Customer service_customer;

	srand((unsigned) time(NULL));//rand함수 매번 다르게 하기위한 함수 
	for(clock=0;clock<60;clock++){
		printf("현재시각=%d\n",clock);
		if((rand()%10)<3){//대기줄에 들어감 
			Customer c;
			c.id=total_customers++;
			c.arrival_time=clock;
			c.service_time=rand()%3+1;
			enqueue(&q,c);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",c.id,c.arrival_time,c.service_time);
		} 
		if(service_time>0){
		    printf("고객 %d 업무처리중입니다.\n",service_customer.id);
			service_time--;
		}else {
			if(!is_empty(&q)){
			service_customer=dequeue(&q);
			service_time=service_customer.service_time;
			printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",service_customer.id,clock,clock-(service_customer.arrival_time));
			total_wait_time+=(clock-(service_customer.arrival_time));
		}
		}
		
	}
	printf("총 대기시간 : %d\n",(total_wait_time));
	printf("평균 대기시간 : %d\n",(total_wait_time)/total_customers);
	return 0;
}



```

2) 2명일때 딱히 의미없음
```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_QUEUE_SIZE 5 

typedef struct Customer{
	int id;
	int service_time;
	int arrival_time;
}Customer;
typedef struct Queue{
	int front;//맨앞 
	int rear;//맨뒤 
	Customer data[MAX_QUEUE_SIZE];
}Queue;
void init_queue(Queue*q){
	q->front=q->rear=0;//한칸 비워두고 시작, -1로 시작하면 공백상태, 포화상태 구분 불가능 
}
int is_empty(Queue*q){
	return (q->front==q->rear);
}
int is_full(Queue*q){
    return (((q->rear+1)%MAX_QUEUE_SIZE)==q->front);
}
void enqueue(Queue*q,Customer c){
	if(is_full(q)){
		fprintf(stderr,"queue is full");
		exit(1);
	}else {
		q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
	    q->data[q->rear]=c;
   }
}
Customer dequeue(Queue*q){
	if(is_empty(q)){
		fprintf(stderr,"queue is empty");
		exit(1);
	}else {
		q->front=(q->front+1)%MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}


int main() {
	int clock;
	Queue q[2];
	init_queue(q);
	init_queue(q+1);
	int total_customers=0;
	int total_wait_time=0;
	int service_time[2]={0,0};
	
	Customer service_customer[2];

	srand((unsigned) time(NULL));//rand함수 매번 다르게 하기위한 함수 
	int r;
	for(clock=0;clock<60;clock++){
		printf("현재시각=%d\n",clock);
		r=rand()%10;
		Customer c;
		if(r<3){//대기줄에 들어감 		
			c.id=total_customers++;
			c.arrival_time=clock;
			c.service_time=rand()%3+1;
			enqueue(q,c);
			printf("1번 창구 고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",c.id,c.arrival_time,c.service_time);
		}else if(r>6){
			c.id=total_customers++;
			c.arrival_time=clock;
			c.service_time=rand()%3+1;
			enqueue(q+1,c);
			printf("2번 창구 고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",c.id,c.arrival_time,c.service_time);
		
		}
		if(service_time[0]==0){
			if(!is_empty(q)){
			service_customer[0]=dequeue(q);
			service_time[0]=service_customer[0].service_time;
			printf("1번 창구 고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",service_customer[0].id,clock,clock-(service_customer[0].arrival_time));
			total_wait_time+=(clock-(service_customer[0].arrival_time));
		}
		}else{
			printf("1번 창구 고객 %d 업무처리중입니다.\n",service_customer[0].id);
			service_time[0]--;
		} 
		
		if(service_time[1]==0){
			if(!is_empty(q+1)){
			service_customer[1]=dequeue(q+1);
			service_time[1]=service_customer[1].service_time;
			printf("2번 창구 고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",service_customer[1].id,clock,clock-(service_customer[1].arrival_time));
			total_wait_time+=(clock-(service_customer[1].arrival_time));
		}
		}else{
			printf("2번 창구 고객 %d 업무처리중입니다.\n",service_customer[1].id);
			service_time[1]--;
		}
	
		    
	
		
	}
	printf("총 대기시간 : %d\n",(total_wait_time));
	printf("평균 대기시간 : %d\n",(total_wait_time)/total_customers);
	return 0;
}



``` 

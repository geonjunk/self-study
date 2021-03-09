# 04 스택
## 4.1 스택이란?
### 스택의 개요 및 개념
* LIFO(Last In First Out)(후입선출)방식의 자료구조
* 입출력은 맨 위(Stack top)에서만 일어나고 중간에는 데이터 삽입, 삭제 불가능 
* 용어
	* stack top: 스택의 맨위, 입출력 일어나는 곳
	* stack bottom : 스택의 맨 아래
* 응용
	* **되돌리기(undo)**기능 구현 시 많이 사용
		*ex) 스마트폰 뒤로가기 기능 : 뒤로가기 하면 이전에 수행되던 앱 나타남
	* 산술 연산(중위연산), 함수 호출, 인터럽트 처리등  

### 스택의 응용1 : 시스템 스택을 이용한 함수 호출
* 수많은 함수 호출 이루어지는 중 함수 실행이 끝나면 자신을 호출한 함수로 돌아가야하는데 이 복귀 주소를 기억하는데 스택을 사용한다
	* 함수 호출이된 역순으로 되돌아가기때문에 스택 사용
* 함수 호출 시 Activation record가 시스템 스택에 쌓임
	* Activation record에는 복귀 주소가 저장됨
* Activation record에는 PC(프로그램 카운터)(다음에 실행될 명령어의 주소 저장)뿐만 아니라 함수 호출 시 매개변수와 안에서 선언된 지역변수들이 같이 생성됨 
* 함수가 자기자신을 호출하여도 다른 함수 호출과 동일한 방식으로 시스템 스택에 쌓임

## 4.2 스택의 구현
### 스택의 추상 자료형(ADT)
* 0개 이상의 요소를 가지는 선형 리스트의 일종으로 정의
* 기본연산인 추가(push), 삭제(pop)와 현재 스택 상태 검사(is_full,is_empty)하는 검사 연산 존재
	* 기본연산 : 추가->push연 / 삭제 ->pop연산 산
	* 검사연산
		* 스택의 공간이 없는지 : push에러 방지
		* 스택이 빈 스택인지 : pop에러 방지
	* + peek연산 : pop처럼 요소를 삭제하고 출력이 아닌, 맨 위에 것 출력만 함
* ADT Stack
	* 객체 : 0개 이상의 원소를 가지는 유한 선형 리스트
	* 연산 :
		* Create(size)::=최대 크기가 size인 공백 스택을 생성한다
		* is_full(s)::= 스택 s가 가득 찼는지 검사
		* is_empty(s)::= 스택 s가 비어있는지 검사
		* push(s,item)::= 스택의 맨 위에 요소 item을 추가 
		* pop(s) ::= 스택의 맨 위에 있는 요소 삭제 
		* peek(s) ::= 스택의 맨위의 원소를 제거하지 않고 반환
* 배열, 연결리스트로 구현 가능하다
	* 배열 : 구현 방법 간단하고, 성능이 우수하지만 스택의 크기 고정이다 
	* 연결리스트 : 구현 복잡, 스택의 크기 가변적으로 가능하다 
	
### 스택의 구현 

* 기본적인 구현
	* 스택의 가장 최근에 입력되었던 자료를 가리키는 top 변수 요구
	* top변수는 size변수가 아닌 인덱스 위치를 가리키는 변수, 스택이 비어있으면 0이 아니라 -1의 값 가짐 
	* 코드) 배열을 이용한 구현 
	```
#include<stdio.h>

#define MAX_STACK_SIZE 100

typedef int element;// stack에 들어갈 데이터 element로 정의 
//배열 할당시 define변수 아니면 배열 크기에 들어갈수 없음 
typedef struct Stack{
	int top;
	element data[MAX_STACK_SIZE];
}Stack;

void init(Stack*s){
	s->top=-1;
} 

int is_full(Stack*s){//if문줄여서 바로 리턴 할 수 있음 
	return s->top==(MAX_STACK_SIZE-1);
}
int is_empty(Stack*s){
    return s->top==-1;
}
void push(Stack*s,element item){
	if(!is_full(s))
	s->data[++(s->top)]=item;
	else {
		fprintf(stderr,"Stack is full\n");
		exit(1);
	}
}
element pop(Stack*s){
	if(!is_empty(s)) return s->data[(s->top)--];	
	else{
		fprintf(stderr,"Stack is empty\n");
		exit(1);
	}
}
element peek(Stack*s){
    if(is_empty(s)) {
        fprintf(stderr,"Stack is empty\n");
        exit(1);
    }else return s->data[s->top];
}


int main() {
    Stack s;
    init(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    return 0;
}
```

* 동적 배열 스택
	* 컴파일 시간에 필요한 스택의 크기 아는 것 실제로는 어려움-> 동적 할당 통해 실생 시간에 메모리 할당 받아 해결
	* c는 realloc(유지할내용, 할당할 공간)함수를 통해 현재 내용 유지하면서 주어진 크기로 동적메모리 다시 할당한다
	* 코드)
	```
	#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct Stack{
	int top;
	int capacity;//현재 스택 사이즈 
	element*data;
}Stack; 

void initStack(Stack*s){
	s->top=-1;
	s->capacity=1;
	s->data=(element*)malloc(sizeof(element)*s->capacity);
}
int is_full(Stack*s){
	return s->top==(s->capacity-1);
}
int is_empty(Stack*s){
	return s->top==-1; 
}

void push(Stack*s,element item){
	if(is_full(s)){
		s->capacity*=2;
		s->data=(element*)realloc(s->data,sizeof(element)*s->capacity);
	}
	s->data[++(s->top)]=item;

}

element pop(Stack*s){
	if(is_empty(s)){
		fprintf(stderr,"stack is empty\n");
    	exit(1);
	}
	return s->data[(s->top)--];
	
}
element peek(Stack*s){
    if(is_empty(s)) {
        fprintf(stderr,"Stack is empty\n");
        exit(1);
    }else return s->data[s->top];
}
int main() {
    Stack s;
    initStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    free(s.data);
    return 0;
}
	```
### 스택의 응용2: 괄호 검사 문제
* 문제설명
	* 프로그램에서 사용되는 괄호([], {}, ())들이 올바르게 사용되는지 검사하는 문제
		* 조건1 : 왼쪽 괄호의 개수와 오른쪽 괄호의 개수는 같아야 함
		* 조건2 : 같은 종류의 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 한다
		* 조건3 : 서로 다른 종류의 왼쪽 괄호와 오른쪽 괄호 쌍은 서로 교차하면 안된다
	* 참고
		* 문자열 char str [6]= "hello"-> str[6]={'h','e','l','l','o','\0'	}; (c에선 string 대신 char 배열 사용)
		* strlen함수는 null포인터를 제외한 길이 반환한다 
* 코드
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct Stack{
	int top;
	element data[MAX_STACK_SIZE];
}Stack;

void init(Stack*s){
	s->top=-1;
} 

int is_full(Stack*s){//if문줄여서 바로 리턴 할 수 있음 
	return s->top==(MAX_STACK_SIZE-1);
}
int is_empty(Stack*s){
    return s->top==-1;
}
void push(Stack*s,element item){
	if(!is_full(s))
	s->data[++(s->top)]=item;
	else {
		fprintf(stderr,"Stack is full\n");
		exit(1);
	}
}
element pop(Stack*s){
	if(!is_empty(s)) return s->data[(s->top)--];	
	else{
		fprintf(stderr,"Stack is empty\n");
		exit(1);
	}
}
element peek(Stack*s){
    if(is_empty(s)) {
        fprintf(stderr,"Stack is empty\n");
        exit(1);
    }else return s->data[s->top];
}
int check_matching(char*p){
	Stack s;
	int i,n;
	char ch,top_ch;
	init(&s);
	n=strlen(p);
	for(i=0;i<n;i++){
		ch=p[i];
		switch(ch){
			case '[':
			case '{':
			case '(':
			push(&s,p[i]);
			break;
			
			case ']':case '}': 	case ')':
			if(is_empty(&s))
			return 0;
			else{
			    top_ch=pop(&s);
				if((top_ch=='['&&ch!=']')||
				(top_ch=='{'&&ch!='}')||
				(top_ch=='('&&ch!=')')){
				return 0;
			    }
				break;
			}
		    //조건 2,3 처리 : 오른쪽 괄호는 스택에 못들어가며, 오른쪽 괄호와 짝이되는 왼쪽 괄호가 pop안되면 오류 
		}
	}
	return is_empty(&s);//조건1 처리 : 다 끝나고 stack에 남아있으면 오류	
	
}
int main(){
	 
	char *p ="{ A[(i+1)]=0; }";
	if(check_matching(p)==1) 
		printf("%s 괄호검사성공\n",p);
	else  
		printf("%s 괄호검사실패\n",p);
	return 0;
}
``` 
### 스택의 응용 : 후위 표기 수식 계 산 
* 후위 표기 수식을 계산하는 코드
	* 후위 표기 수식
		* 컴파일러가 선호하는 표기법, 중위 표기법과 다른게 괄호 사용할 필요가 없음 
		* 중위 표기법은 연산자 우선순위나 괄호에 의해 수식을 끝까지 읽은 후 계산해야 하지만 후위 표기법은 수식을 읽으면서 계산 가능
``` 
int eval(char*p){
	Stack s;
	init(&s);
	int len=strlen(p);
	int i,num1,num2;
	char ch;
	for(i=0;i<len;i++){
	ch=p[i];
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
    num1=pop(&s);
	num2=pop(&s);
	switch(ch){
		case '+':
		push(&s,num2+num1);
		break;
		
		case '-':
		push(&s,num2-num1);
		break;
		
		case '*':
		push(&s,num2*num1);	
		break;

    	case '/':
		push(&s,num2/num1);
		break;
	
	}
    }else 
		push(&s,ch-'0');//ASCII값 알 필요없이 문자를 INT형으로 변환하는 방법 
	}
	return pop(&s);
}
int main() {
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result=eval("82/3-32*+");
    printf("결과값은 %d\n",result);
    return 0;
}
```
* 중위 표기 수식을 후위 표기 수식으로 변환하는 코드 
	* 프로그래머가 입력하는 수식은 중위 표기법이므로 후위 표기법으로 변환 필요
	* 피연산자는 그대로 출력, 연산자를 스택에 넣어야 하며 나중에 스캔된 연산자부터 출력
	* 연산자의 우선순위 처리 고려해야 함 
		* 스택에 있는 연산자의 우선순위 >= 현재처리중인 연산자의 우선순위 : 스택에 있는 연산자 출력 후 처리중인 연산자 스택에 넣는다  
		* 여는 괄호는 가장 우선순위가 낮은 연산자, 닫는 괄호를 만나면 괄호 사이에 들어간 모든 연산자 출력한다
	* 우선순위를 임의로 부여하는 함수 이용! 
	```
int makeRank(char ch){
	if(ch=='/'||ch=='*')return 2;
	if(ch=='+'||ch=='-')return 1;
	if(ch=='('||ch=='{'||ch=='['||ch==')'||ch=='}'||ch==']')return 0;
	//여는괄호는 stack들어 가면 우선 순위 최하, 닫는괄호는 스택에서 연산자 꺼내므로 우선순위 최하라고 할 수 있음 
	return -1;
	
}
int infix_to_postfix(char*p){
	Stack s;
	init(&s);
	int i;
	int len=strlen(p);
	char ch,ch2;
	for(i=0;i<len;i++){
		ch=p[i];
	switch(ch){	
		case '}':
			ch2=pop(&s);
			while(ch2!='{'){
				printf("%c",ch2);
				ch2=pop(&s);
			}
			break;
		case ']':
	    	ch2=pop(&s);
			while(ch2!=']'){
				printf("%c",ch2);
				ch2=pop(&s);
			}
			break;
		case ')':
        	ch2=pop(&s);
			while(ch2!='('){
				printf("%c",ch2);
				ch2=pop(&s);
			}
			break;
	    case '+':case'-':case'/':case '*':
	    	//자기보다 우선순위 낮은거 만날때까지 pop 해야함 
			while(!is_empty(&s)&&makeRank(peek(&s))>=makeRank(ch)) {
			printf("%c",pop(&s));
			}
			push(&s,ch);
			break;
		case '[':case '{': case '('://여는 괄호면 무조건 push, stack 들어가면 우선순위 최하됨 
			push(&s,ch);
			break;
		default:
			printf("%c",ch);
			break;
	}
	}
	while(!is_empty(&s))printf("%c",pop(&s));	//스택의 남은거 출력 
} 
int main() {
    char *s="(2+3)*4+9";
    printf("중위표시수식 %s \n",s);
    printf("후위표시수식 ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}
	```  
### 스택의 응용 : 미로 문제 
* 기본적인 방법은 하나의 경로를 선택하여 한번 시도해보고 안되면 다른 경로 시도
* 현재 위치에서 갈수 있는 위치를 스택에 push하며 스택에서 하나의 위치를 꺼내어 현재 위치로 만듬(1번 방법) 
* 스택이 빈 상태면 미로 찾기 실패 (8방향 , 이동경로 프린트 구현하기)
	1. 일반 미로찾기 
	```
	char maze[MAZE_SIZE][MAZE_SIZE]={
  {'1','1','1','1','1','1'},
  {'e','0','1','0','0','1'},
  {'1','0','0','0','1','1'},
  {'1','0','1','0','1','1'}, 
  {'1','0','1','0','0','x'},
  {'1','1','1','1','1','1'}
};


element start={1,0};
element entry;
element offset[4]={{-1,0},{0,1},{1,0},{0,-1}};//4방향 
//element offset[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{1,-1},{-1,-1}};//시계방향으로 이동가능한 8방향 


void print_maze(){
	int r,c;
	for(r=0;r<MAZE_SIZE;r++){
		for(c=0;c<MAZE_SIZE;c++){
			printf("%c",maze[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void push_loc(Stack*s,int r,int c){
	int i;
	element temp;
   	for(i=0;i<4;i++){
	temp.r=r+offset[i].r;
	temp.c=c+offset[i].c;
	if(temp.r<0||temp.c<0) continue;
	if(maze[temp.r][temp.c]!='1'&&maze[temp.r][temp.c]!='.')
   	push(s,temp);
	}
	
}

int main() {
   Stack s;//하나는 동선 출력용, 하나는 길찾기 용 스택 
   init(&s);
   entry=start;
   int r,c;
  
   while(maze[entry.r][entry.c]!='x'){//현재위치 보고 도착위치 인지 판단 
   	r=entry.r;
   	c=entry.c;
   	maze[r][c]='.';//도착 위치 아니므로 흔적 남김 
   	print_maze();
   	
   	push_loc(&s,r,c);//갈수있는 위치 찍음 
	
	if(is_empty(&s)){
		printf("실패\n");
		return ;
	}else entry=pop(&s); //현재 위치 이동 
	
   }
   printf("성공\n");
   
   return 0;
}
	``` 
	2. stack에 모든 좌표 다 넣으면서 하는 법  
		```
		char maze[MAZE_SIZE][MAZE_SIZE]={
  {'1','1','1','1','1','1'},
  {'e','0','1','0','0','1'},
  {'1','0','0','0','1','1'},
  {'1','0','1','0','1','1'}, 
  {'1','0','1','0','0','x'},
  {'1','1','1','1','1','1'}
};

element start={1,0};
element entry;
element offset[4]={{-1,0},{0,1},{1,0},{0,-1}};//4방향 
//element offset[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{1,-1},{-1,-1}};//시계방향으로 이동가능한 8방향 



void print_maze(){
	int r,c;
	for(r=0;r<MAZE_SIZE;r++){
		for(c=0;c<MAZE_SIZE;c++){
			if(maze[r][c]=='-')printf("0");
			else printf("%c",maze[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}


int main() {
   Stack s;//하나는 동선 출력용, 하나는 길찾기 용 스택 
   init(&s);
   entry=start;
   int r,c;
   push(&s,entry);
   
   while(maze[entry.r][entry.c]!='x'){//현재위치 보고 도착위치 인지 판단 
   r=entry.r;
   c=entry.c;

   maze[r][c]='2';//방문했다고 체크
   int i;
   element e;
   print_maze();
   for(i=0;i<4;i++){
   e.r=r+offset[i].r;
   e.c=c+offset[i].c;
   if(maze[e.r][e.c]=='0'||maze[e.r][e.c]=='x'){
   	push(&s,e);
   	break;
   }else if (i==3) {
   	pop(&s);
   	maze[r][c]='-';
   }
   } 
   
   if(is_empty(&s)){
   	printf("실패\n");
   	return 0;
   }else entry=peek(&s);
   
   }
   
   element e;
   while(!is_empty(&s)){
   	   e=pop(&s);
	   printf("(%d,%d)->",e.r,e.c);
   } 
   printf("\n");
   printf("성공\n");
   
   return 0;
}

		```
* 참고) https://blog.naver.com/zkd1750/90184598460 
* 일단 다넣고 판단 

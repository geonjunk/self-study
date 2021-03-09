#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct element{
	int r;
	int c;
}element;
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



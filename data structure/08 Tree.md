# 08 트리  
## 8.1 트리의 개념
### 비선형 자료 구조(NonLinear data structure)
* 선형 자료구조 : 자료들이 선형으로 나열되어 있는 구조
	* ex) 리스트, 큐, 스택 등
* 가계도, 회사의 조직도, 컴퓨터의 디렉토리 등 계층적인 구조를 표현하기엔 선형 자료구조는 적합하지 않음
* 이를 표현하기 위한 자료구조가 비선형 자료구조
	* 하나의 자료 뒤에 하나의 자료만 오는게 아닌 여러개의 자료가 올 수 있는 구조
	* ex) 트리, 그래프
### 트리의 개요 
* 계층적인 자료를 표현하는데 적합한 자료구조
* 인공지능 문제에서도 트리 많이 사용함
	* ex) 결정 트리(decision tree) : 인간의 의사 결정 구조를 표현하는 한 가지 방법
	```
	사진 
	```
### 트리 관련 용어
* node(노드) : 트리를 구성하고 있는 요소, 트리는 한개 이상의 노드로 이루어진 유한 집합이다
* root(루트) : 계층적인 구조에서 가장 높은 곳에 있는 노드
* sub tree(서브 트리) : 루트 노드가 아닌 나머지 노드들
* edge(간선) : 루트와 서브트리간 연결선
* 노드의 차수(degree) : 어떤 노드가 가지고 있는 자식 노드의 개수
* 트리의 차수(degree) : 노드의 차수 중 가장 큰 값
* 레벨(level) : 트리의 각층에 번호를 매기는 것으로 루트부터 1로 한 층씩 내려갈수록 1씩 증가
* 트리의 높이(height) : 트리가 가지고 있는 최대 레벨
* 노드들 사이의 관계
	* 부모 노드(parent node) : 어떤 노드의 이전 레벨의 노드
	* 자식 노드(child node) : 어떤 노드의 연결된 다음 레벨의 노드
	* 형제 노드(sibling) : 동일한 부모를 갖는 노드
	* 조상 노드(ancestor node): 임의의 노드에서 루트 노드까지의 경로를 이루고 있는 노드들
	* 후손 노드(descendent node) : 임의의 노드 하위에 연결된 모든 노드들
	* 단말 노드(leaf node) : 자식노드가 없는 노드 
	* 비단말 노드(nonterminal node) : 자식 노드가 있는 노드
	* 포리스트 (forest): 서로 독립된 트리들의 집합
* Ex) 
```
사진 
```
### 트리의 표현
* 가장 일반적인 방법은 각 노드가 데이터를 저장하는 데이터 필드와 자식 노드를 가리키는 링크필드로 구성되게 하는 것
*```
사진 
```
* 일반 트리는 자식 노드의 개수는 노드마다 다르기 때문에 노드의 크기가 고정되지 않으므로 프로그램 복잡해짐
* 따라서 자식노드의 개수가 2개인 이진트리를 주로 많이 사용함, 일반트리를 이진트리로 변환해서 사용하는 방법도 존재함 

## 8.2 이진트리(binary tree)
### 이진트리의 개요
* 트리 중에 가장 많이 사용하는 트리
* 모든 노드가 2개의 서브 트리를 가지고 있는 트리이며 서브 트리는 공집합일 수 있음 
* 이진트리의 노드에는 최대 2개까지의 자식 노드가 존재할 수 있고 모든 노드의 차수가 2이하가 됨
* 이진 트리에는 서브트리간의 순서가 존재하기 때문에 왼쪽과 오른쪽 서브트리를 서로 구별된다 
* 공집합도 이진트리라고 할 수 있음
* 이진트리의 정의를 이용해 서브트리부터 이진트리 여부 순차적으로 확인하며 이진트리인지 확인 가능하다 
* 이진트리의 정의
	1. 공집합 이거나
	2. 루트와 왼쪽, 오른쪽 서브 트리로 구성된 노드들의 유한집합으로 정의. 이진트리의 서브트리들은 모두 이진트리여야함
* 이진트리와 일반 트리의 차이점
	1. 이진트리의 모든 노드는 차수가 2이하, 일반 트리는 자식 노드의 개수 제한 없다
	2. 일반 트리와 달리 이진 트리는 노드를 하나도 갖지 않을 수도 있다(=공집합도 이진트리)
	3. 이진트리는 서브트리간의 순서갖 존재하므로 왼쪽 서브트리와 오른쪽 서브트리 구별한다 

### 이진트리의 성질
* n개의 노드를 가진 이진트리는 정확하게 n-1개의 간선을 갖는다
	* why) 루트를 제외하고 정확하게 하나의 부모노드를 가지는는데 부모 자식간에는 정확하게 1개의 간선만 존재하므로
* 높이가 h인 이진 트리의 경우, 최소 h개 최대 2^h-1 개의 노드를 가진다
	* why) 한 레벨에서 적어도 하나의 노드가 존재해야 하므로 높이가 h인 이진트리는 최소 h개의 노드를 가지며 레벨 i에서의 노드의 최대 개수는 2^(i-1)이므로 최대 전체 노드의 개수는 ∑_(i=1)^h▒2^(i-1) =2^h-1 이 된다.
* n개의 노드를 가지는 이진트리의 높이는 최대 n,	최소 ?log(n+1)? 이다.
	* why) 레벨당 최소 1개의 노드를 가져야 하므로 높이는 n을 넘을 수 없다. 또한 높이가 h인 이진트리에서 가질 수 있는 노드 개수의 최대값은 2^h-1인데 n≤ 2^h-1 이 성립 하므로 양변에 log취하면 h≥?log(n+1)? 이 된다(저 괄호는 올림 연산). 따라서 최솟값은 ?log(n+1)? 이다.

### 이진트리의 분류
* 포화 이진 트리(full binary tree) 
	* 각 레벨에 노드가 꽉 차있는 이진트리를 의미한다
		* 높이가 h인 포화 이진트리는 정확하게  2^h-1개의 노드를 가진다.
	* 각 노드에 번호 붙일 수 있으며 부여 방식은 레벨 단위로 왼쪽에서 오른쪽으로 번호 붙인다

* 완전 이진 트리(complete binary tree)
	* 높이가 h일 때 레벨 1부터 h-1까지는 노드가 모두 채워져 있고 마지막 레벨 h에선 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진트리
	* 마지막 레벨에서는 노드가 꽉 차있지는 않아도 중간에 빈곳은 없어야 함
	* 포화이진트리는 완전이진트리지만 역은 성립X
	* 포화 인진트르의 노드번호와 완전 이진트리의 노드 번호는 1대1 대응함
* 기타 이진 트리

### 이진트리의 구현
1. 배열을 이용한 방법
	* 주로 포화 이진트리나 완전 이진 트리의 경우 많이 쓰이는 방법(다른 이진 트리도 가능은 함)
	* 높이가 h이면 2^h-1개의 공간을 연속적으로 할당한 다음 이진 트리의 번호대로 노드들을 저장한다
	* 노드번호가 1부터 시작이므로 배열을 인덱스 1부터 사용(선택 사항)
	* 인덱스(노드번호) 관련 연산
		* 노드 i의 부모 노드 인덱스 : i/2
		* 노드 i의 왼쪽 자식 노드의 인덱스 : 2i
		* 노드 i의 오른쪽 자식 노드 인덱스 : 2i+1

2. 포인터를 이용한 방법 (링크 표현법)
	* 노드가 구조체로 표현되고 각 노드가 포인터 가지고 있어 노드와 노드를 포인터로 연결하는 방법
	* 하나의 노드가 3개의 필드 가짐 : 2개의 링크 필드(왼쪽, 오른쪽 자식 노드), 데이터 필드 
	* 가리키는 노드 없으면 각 링크 필드 NULL 가리키게 함
	* ex)
	```
	typedef struct TreeNode{
	int data;
	struct TreeNode*left,*right;
	}TreeNode;

	``` 

## 8.3 이진트리의 순회(traversal)
### 이진트리의 순회방법
* 이진 트리 순회 : 이진 트리의 속하는 모든 노드를 한 번씩 방문하여 노드가 가진 데이터를 목적에 맞게 처리하는 것
* 선형 자료구조는 순차적으로 순회하는 방법은 하나뿐이지만 트리는 여러 가지 순서로 순회 가능
* 순회하는 표준적인 방법 3가지
	* 참고(V: 루트를 방문하는 작업,L : 왼쪽 서브트리 방문, R : 오른쪽 서브트리 방문) 
	1. 전위 순회(preorder traversal) : 루트를 서브 트리에 앞서서 먼저 방문 VLR 
	2. 중위 순회(inoreder treaversal) : 루트를 왼쪽과 오른쪽 서브트리 중간에 방문 LVR 
	3. 후위 순회(postorder traversal) : 루트를 서브트리 방문 후에 방문 LRV 

* 전체 트리와 서브 트리의 구조는 동일하므로 전체 트리 순회에 사용된 방법은 동일하게 서브트리 순회에 적용 가능하다
	* 즉, 순회는 재귀(순환)을 통해 구현 가능하다
	* 참고) 문제의 구조는 같고 크기만 작아지는 경우 -> 주로 순환 적용 

### 이진트리의 순회 구현
1. 전위 순회 
	* 방문 순서 : 루트노드 -> 왼쪽 서브트리 -> 오른쪽 서브트리
	* 알고리즘 설명 : 현재 방문 노드 x라고 함
		1. x가 NULL이면 순환 호출 하지 않음
		2. x의 데이터 출력
		3. x의 왼쪽 서브트리를 순환 호출하여 방문
		4. x의 오른쪽 서브트리를 순환 호출하여 방문

2. 중위 순회
	* 방문 순서 : 왼쪽 서브트리 -> 루트노드 -> 오른쪽 서브트리
	* 알고리즘 설명 : 현재 방문 노드 x라고 함
		1. x가 NULL이면 순환 호출 하지 않음
		2. x의 왼쪽 서브트리를 순환 호출하여 방문 
		3. x의 데이터 출력 
		4. x의 오른쪽 서브트리를 순환 호출하여 방문
		
3. 후위 순회
	* 방문 순서 : 왼쪽 서브트리 ->  오른쪽 서브트리 ->루트노드
	* 알고리즘 설명 : 현재 방문 노드 x라고 함
		1. x가 NULL이면 순환 호출 하지 않음
		2. x의 왼쪽 서브트리를 순환 호출하여 방문 
		3. x의 오른쪽 서브트리를 순환 호출하여 방문
		4. x의 데이터 출력 
* 전체 구현 코드)
```
#include<stdio.h>


typedef int element;
typedef struct TreeNode{
	element data;
	struct TreeNode*left,*right;
}TreeNode;

void inorder(TreeNode*root){
	if(root!=NULL){
	inorder(root->left);
	printf("[%d] ",root->data);
	inorder(root->right);
	}
}



void preorder(TreeNode*root){
	if(root!=NULL){
	printf("[%d] ",root->data);
	preorder(root->left);
	preorder(root->right);
	}
}

void postorder(TreeNode*root){
	if(root!=NULL){
	postorder(root->left);
	postorder(root->right);
	printf("[%d] ",root->data);

	}
}
int main(){
	TreeNode n1={1,NULL,NULL};
	TreeNode n2={4,&n1,NULL};
	TreeNode n3={16,NULL,NULL};
	TreeNode n4={25,NULL,NULL};
	TreeNode n5={20,&n3,&n4};
	TreeNode n6={15,&n2,&n5};
	TreeNode*root=&n6;

	printf("중위 순회=");
	inorder(root);
	printf("\n");
	
	printf("전위 순회=");
	preorder(root);
	printf("\n");
	
	printf("후위 순회=");
	postorder(root);
	printf("\n");
	return 0;
}

``` 

### 반복적 순회
* 재귀가 아닌 반복을 이용해서도 트리 순회 구현 가능하다
* 재귀로 구현시에도 시스템 스택을 사용하고 있는 것 이므로 별도의 스택 사용하여 반복으로 구현한다 
* AI의 지능적인 탐색을 할 때 활용 가능하다	
```
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode*left, *right;
}TreeNode;

int top = -1;
TreeNode*stack[SIZE];

void push(TreeNode*p) {
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

TreeNode*pop() {
	TreeNode*temp = NULL;
	if (top > -1) {
		temp = stack[top--];
		return temp;
	}
	return temp;
}

TreeNode*peek() {
	TreeNode*temp = NULL;
	if (top > -1) {
		temp = stack[top];
		return temp;
	}
	return temp;
}
void inorder_iter(TreeNode*root) {//중위
	TreeNode*temp = root;
	while (1) {
		for (; temp != NULL; temp = temp->left) {
			push(temp);
		}
		temp = pop();
		if (temp == NULL)
			break;
		printf("[%d]", temp->data);
		temp = temp->right;

	}
}
void preorder_iter(TreeNode*root) {//전위
	TreeNode*temp = root;
	while (1) {
		for (; temp != NULL; temp = temp->left) {
			printf("[%d]", temp->data);
			push(temp);
		}
		temp = pop();
		if (temp == NULL)
			break;
		temp = temp->right;


	}

}
void preorder_iter2(TreeNode*root) {//2번째 방법, 좀 더 직관적인 코드
	TreeNode*temp = root;
	push(temp);
	while (1) {

		temp = pop();
		if (temp == NULL)break;

		printf("[%d]", temp->data);
		if (temp->left != NULL) {
			if (temp->right != NULL) {
				push(temp->right);
			}
			push(temp->left);
		}

	}
}

void postorder_iter(TreeNode*root) {
	TreeNode*temp = root;

	while (1) {
		for (; temp != NULL; temp = temp->left) {
			if (temp->right)
				push(temp->right);
			push(temp);
		}
		temp = pop();
		if (temp == NULL)
			break;
		if (temp->right != NULL && peek() == temp->right) {
			pop();//저장된 오른쪽 노드 스택에서 제거
			push(temp);
			temp = temp->right;
		}
		else {//오른쪽이 NULL이거나, 이미 방문했을경우
			printf("[%d]", temp->data);
			temp = NULL;
		}

	}




}



int main() {
	
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 4,&n1,NULL };
	TreeNode n3 = { 16,NULL,NULL };
	TreeNode n4 = { 25,NULL,NULL };
	TreeNode n5 = { 20,&n3,&n4 };
	TreeNode n6 = { 15,&n2,&n5 };
	TreeNode*root = &n6;

	

	printf("중위순회 = ");
	inorder_iter(root);
	printf("\n");

	printf("전위순회 = ");
	preorder_iter(root);
	printf("\n");
	printf("후위순회 = ");
	postorder_iter(root);
	printf("\n");

return 0;
}


```
### 순회방법의 선택
* 후위 순회 : 자식 노드를 처리하고 부모 노드를 처리해야 하는 경우
	* ex) 디렉토리 용량 계산 : 하위 디렉토리 용량 계산되어야 현재의 디렉토리 용량 계산 가능
* 전위 순회 : 부모노드를 처리하고 자식 노드를 처리해야 하는 경우

## 8.4 레벨 순회
### 레벨 순회
* 각 노드를 레벨 순으로 검사하는 순회 방법
* 동일한 레벨인 경우 좌에서 우로 방문
* 스택이 아닌 **큐**를 이용한 순회 방법
* 큐에 있는 노드를 꺼내어 방문 후 그 자식 노드를 큐에 삽입하여 더 이상 큐에 노드가 없을 때까지 반복한다
* 코드
```
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100


typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode*left, *right;
}TreeNode;


typedef struct QueueType {
	TreeNode*data[SIZE];
	int rear, front;
}QueueType;

void error(char*message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType*q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType*q) {

	return q->rear == q->front;
}
int is_full(QueueType*q) {

	return q->front == (q->rear + 1) % SIZE;

}

void enqueue(QueueType*q, TreeNode*p) {
	if (is_full(q)) {
		error("queue is full");
	}
	q->rear = (q->rear + 1) % SIZE;
	q->data[q->rear] = p;

}
TreeNode* dequeue(QueueType*q) {
	if (is_empty(q)) {
		error("queue is empty");
	}
	q->front = (q->front + 1) % SIZE;
	return q->data[q->front];
}

void level_order(TreeNode*root) {
	QueueType q;
	init(&q);
	enqueue(&q, root);
	while (!is_empty(&q)) {//queue가 빌때 까지 
		root = dequeue(&q);
		printf("[%d]", root->data);
		if(root->left)
			enqueue(&q,root->left);
		if (root->right)
			enqueue(&q,root->right);
	}

}


TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode*root = &n6;

int main() {

	printf("레벨 순회=");
	level_order(root);
	printf("\n");
	return 0;
}



```

## 8.5 트리의 응용
### 수식 트리 처리
* 수식 트리(expression tree) : 산술 연산자와 피연산자로 구성된 트리
* 이진트리를 통해 수식 트리 처리가능
* 피연산자는 단말 노드, 연산자는 비단말 노드
* 수식 트리를 전위, 중위, 후위 순회 방법으로 읽으면 각각 전위, 중위, 후위 표기 수식이 됨
* 수식 트리 처리(계산)시 후위 순회를 이용함 
* 수식 트리의 루트 노드는 연산자이기 때문에 루트 노드의 자식 노드들이 계산되면 전체 수식 계산이 가능해진다
	* 즉, 자식 노드를 방문하고 루트노드를 방문하는 순회 이용해야함 -> 후위 순회
* 수식 트리 계산 코드
```
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct TreeNode{
	char data;
	struct TreeNode*left,*right;
}TreeNode;



TreeNode n1={1,NULL,NULL};
TreeNode n2={4,NULL,NULL};
TreeNode n3={'*',&n1,&n2};
TreeNode n4={16,NULL,NULL};
TreeNode n5={25,NULL,NULL};
TreeNode n6={'+',&n4,&n5};
TreeNode n7={'+',&n3,&n6};
TreeNode*exp=&n7;

int evaluate(TreeNode*root){
	if(root==NULL)	
	return 0;

	if(root->left==NULL&&root->right==NULL)//단말 노드인 경우 
	return root->data;
	
	int left,right;
	left=evaluate(root->left);
	right=evaluate(root->right);
	printf("%d %c %d를 계산합니다.\n",left,root->data,right); 
	switch(root->data){
		case '+':
			return left+right;
		case '-':
			return left-right;
		case '*':
			return left*right;
		case '/':
			return left/right;
	}
	return 0;
}
int main (){
	printf("수식의 값은 %d입니다.\n",evaluate(exp)); 
	return 0;
}

``` 
* 참고 char는 1바이트, int형 4바이트 
### 디렉토리 용량 계산
* 먼저 서브 디렉토리의 용량을 모두 계산한 다음 루트 디렉토리의 용량 계산 -> 후위 순회 이용
* 코드)
```
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode*left,*right;
}TreeNode;

int calc_dir_size(TreeNode*root){
	if(root==NULL) return 0;
	
	int left=0,right=0,result;
	left=calc_dir_size(root->left);
	right=calc_dir_size(root->right);
	return (left+right+root->data);
} 
int main(){
	TreeNode n4={500,NULL,NULL};
	TreeNode n5={200,NULL,NULL};
	TreeNode n3 ={100,&n4,&n5};
	TreeNode n2={50,NULL,NULL};
	TreeNode n1={0,&n2,&n3};
	printf("디렉토리의 크기= %d",calc_dir_size(&n1));
	return 0;
}
``` 
## 8.6 이진트리의 추가적인 연산
### 노드의 개수 구하는 연산
* 트리의 노드들을 전체적으로 순회해야함
```
int get_node_count(TreeNode*root){
	int count=0;
	if(root!=NULL){
		count=1+get_node_count(root->left)+get_node_count(root->right);
	}
	return count;
}
```
### 단말 노드의 개수 구하는 연산
```
int get_leaf_count(TreeNode*root){
	if(root==NULL)return 0;
	if(root->left==NULL&&root->right==NULL)	return 1;
	return get_leaf_count(root->left)+get_leaf_count(root->right);

}
```


### 트리의 높이 구하는 연산 
```
	int height=0,left=0,right=0;
	
	if(root!=NULL){
		left=get_height(root->left);
		right=get_height(root->right);
		if(left>right){
			height=1+left;	
		}else{
		height =1+right;	
		}
		
	}
	return height;
	
}
```
## 8.7 스레드 이진트리(thread binary tree)
### 스레드 이진 트리란
* 실(스레드)처럼 노드를 순회 순서대로 연결시켜 놓은 트리 
* 순환 호출 없이(스택의 도움 없이) 이진 트리 순회 가능한 트리 
* 스레드 이진트리의 idea : 이진 트리의 노드의 개수 n이라 하면
	* 1개의 노드당 NULL 포함 링크 2개씩이므로 총 링크의 개수는 2n개
	* 그 중 루트 제외 n-1의 링크가 다른 노드 가리키미르 총 n+1 개의 링크가 다른 노드 가리킴
	* 이때 나머지 NULL인 n-1개의 링크를 활용하는 방법
* 중위 순회 시 NULL인 링크에 선행 노드인 중위 선행자(inorder predecessor)나 후속 노드인 중위 후속자(inorder successor)를 저장함

### 스레드 이진 트리의 구현
* 링크가 스레드 저장되는지, 자식노드 가리키는지 구별해주는 태그 변수 필요함
* 오른쪽 자식을 확인했을 때, 중위 후속자이면 그대로 따라감, 실제 자식이면 그 자식의 왼쪽 먼저 순회 함 
* 코드
```
void thread_inorder(TreeNode*root){
	
	if(root==NULL) return;
	while(root->left)
		root=root->left;
	do{
		printf("%c->",root->data);
		if(root->right==NULL)break;
		if(root->right!=NULL){
			if(root->is_thread){
				root=root->right;
			}else{
				root=root->right;
				while(root->left)root=root->left;
			}
		}
	}while(1);
	 
}

TreeNode n1={'A',NULL,NULL,1};
TreeNode n2={'B',NULL,NULL,1};
TreeNode n3={'C',&n1,&n2,0};
TreeNode n4={'D',NULL,NULL,1};
TreeNode n5={'E',NULL,NULL,0};
TreeNode n6={'F',&n4,&n5,0};
TreeNode n7={'G',&n3,&n6,0};
TreeNode*exp=&n7;



int main(){
	n1.right=&n3;
	n2.right=&n7;
	n4.right=&n6;
	
	thread_inorder(exp);
	printf("\n");
	return 0;
}


``` 
## 8.8 이진 탐색 트리(binary search tree)
### 이진 탐색 트리란
* 이진 트리 기반의 탐색을 위한 자료구조
* 탐색(search) 
	* 가장 중요한 컴퓨터 응용 중 하나
	* 가장 시간이 많이 걸리는 작업 중 하나이므로 효율적으로 수행하는 것이 매우 중요
	* ex) 전화번호부에서 전화번호 찾기, 사전에서 단어 찾기, 약속 날짜 찾기 등 
	* 탐색 관련 용어
		1. 레코드(record) : 하나 이상의 필드(field)로 구성된 데이터의 집합체, 탐색은 특정한 레코드를 찾는 과정
		2. 필드(field) : 같은 종류의 의미를 갖는 데이터를 저장하기 위한 항목
		3. 테이블(table) : 레코드들의 집합
		4. 키, 기본키 : 레코드를 식별하는 하나의 필드 값, 다른 키와 중복되지 않는 고유한 값을 갖는 키를 기본 키
* 이진 탐색 트리의 정의
	1. 모든 원소의 키는 유일한 키를 가진다
	2. 왼쪽 서브 트리 키들은 루트 키보다 작다**
	3. 오른쪽 서브 트리의 키들은 루트의 키보다 크다**
	4. 왼쪽, 오른쪽 서브 트리도 이진 탐색 트리
	* 중위 순회 방법으로 이진 탐색 트리 순회하면 크기 순으로 나옴

### 이진 탐색 트리의 구현
1. 탐색 연산
	* 탐색 키 값과 루트 노드의 키 값을 비교
		* 같으면 탐색 종료
	 	* 탐색 키<루트 노드 키 : 루트 노드의 왼쪽 자식을 기준으로 다시 비교
		* 탐색 키>루트 노드 키 : 루트 노드의 오른쪽 자식을 기준으로 다시 비교
	* 순환적인 구현과 반복적인 구현(순환보다 효율성 높다)이 있음  
2. 삽입 연산 
* 이진 탐색 트리에서는 같은 키 값을 갖는 노드가 없어야 하고 탐색에 실패한 위치가 바로 새로운 노드를 삽입하는 위치
	* 탐색에 실패한 위치가 곧 새로운 노드를 삽입하는 위치임
	* 따라서 먼저 탐색을 하는 작업이 필요 
* 새로운 노드는 항상 단말 노드에 추가되므로 단말 노드를 발견할 때까지 루트에서 키를 검색하고 단말 노드가 발견되면 새로운 노드가 단말 노드의 하위 노드로 추가된다
 
3. 삭제 연산 
* 3가지 case 존재
	1. 삭제하려는 노드가 단말 노드인 경우 
		* 단말노드의 부모 노드를 찾아 단말 노드와 연결된 링크를 NULL로 하고 단말 노드 삭제한다
	2. 삭제하려는 노드가 하나의 왼쪽이나 오른쪽 서브 트리중 하나만 가지고 있는 경우
		* 자기의 부모 노드와 서브 트리를 연결한 후 자기 노드를 삭제한다
	3. 삭제하려는 노드가 두개의 서브 트리 모두 가지고 있는 경우
		* 왼쪽 자식이나 오른쪽 자식을 그냥 가지고 오면 안됨 -> 다른 노드의 이동 발생하게 되므로
		* 삭제할 노드의 키 값과 가장 비슷한 키 값을 가진 노드를 가져와야 다른 노드 이동시키지 않아도 이진 탐색 트리 유지됨
			* 가장 비슷한 키 값 : 왼쪽 서브트리의 가장 오른쪽 값 또는 오른쪽 서브트리의 가장 왼쪽 값 중 선택
		* 현재 노드의 키에 가장 비슷한 키값 넣어주고 그 키 값을 갖는 노드는 단말 노드를 삭제하는 방법으로 삭제해준다 
* 전체 코드
```
#include<stdio.h>
#include<stdlib.h>
 
 
typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
}TreeNode;


TreeNode*search(TreeNode*node,element key){
	if(node==NULL)return NULL;//NULL이면 root->key못하므로 앞에서 예외처리 
	if(node->key<key){
		return search(node->left,key);
	}else if(node->key>key){
		return search(node->right,key);
	}else{
		return node;
	}
} 
TreeNode*search2(TreeNode*node,element key){
	while(node!=NULL){
		if(node->key>key){
			node=node->left;
		}else if(node->key<key){
			node=node->right;
		}else return node;
	}
	return NULL;
	
}
TreeNode*insert_node(TreeNode*root,element key){
	if(root==NULL){
		root=(TreeNode*)malloc(sizeof(TreeNode));
		root->key=key;
		root->left=NULL;
		root->right=NULL;
		//새노드 링크 꼭 NULL로 초기화 해주기 
	}else if(root->key>key){
		root->left=insert_node(root->left,key);
	}else if(root->key<key){
		root->right=insert_node(root->right,key);
	}
	//같은경우는 그냥 root리턴 
	return root;
}

TreeNode*delete_node(TreeNode*root,element key){	
//중간 것 삭제
//단말 노드 삭제
//하나의 서브트리
//2개의 서브트리 
// 재귀를 통해 삭제하므로 이전노드 정보 필요없음, 추가시에는 무조건 중간에 들가는 경우 없음	
	if(root==NULL) return NULL;
	if(root->key>key){
		root->left=delete_node(root->left,key);
	}else if(root->key<key){
		root->right=delete_node(root->right,key);
	}else{
		TreeNode*p=root;
		if(root->left==NULL){
			root=root->right;
			free(p);
		}else if(root->right==NULL){
			root=root->left;
			free(p);
		}else{
			p=p->right;
			while(p->left)p=p->left;
			root->key=p->key;
			root->right=delete_node(root->right,root->key);
		}
	}
	return root;

}


void inorder(TreeNode*root){
	if(root==NULL)return;
	inorder(root->left);
	printf("%d->",root->key);
	inorder(root->right);
}

int main() {
	TreeNode*root = NULL;
	TreeNode*tmp = NULL;
 
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL) printf("이진 탐색 트리에서 30을 발견함\n");
	else printf("이진 탐색 트리에서 30을 발견못함 \n");
	
	root=delete_node(root,30);
	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);
	printf("\n\n");
	return 0;
}


``` 
### 이진 탐색 트리의 분석
* 탐색, 삽입, 삭제 연산의 시간 복잡도
	* 트리의 높이 h라고 했을 때 o(h)임
	* n개의 노드를 가지는 트리의 일반적인 높이는	?log?n ? (?log??(n?+1)?)임
	* 따라서, 평균적인 경우 시간 복잡도는 O(log?n)  
	* 한쪽으로 치우친 경우 트리의 높이는 n이므로 O(n)임
* 한쪽으로 치우친 경우는 선형 탐색에 비해 탐색의 시간적인 이득을 못봄
	* 이를 개선하기 위해 트리의 높이를 ?log?n ? (?log??(n?+1)?)로 한정 시키는 균형 기법 요구됨
		* ex) AVL 트리 등
		
## 8.9 이진 탐색 트리(binary search tree)의 응용 : 영어 사전
* 문자열 비교 시에는 strcmp함수 이용
	* strcmp(a,b)<0 : b가 a보다 큼
	* strcmp(a,b)=0 : 같음
	* strcmp(a,b)>0 : a가 b보다 큼 
* 참고)입력 버퍼 비우기
	* gets()를 이용하거나 getchar를 이용해서 getchar()또는 scnaf의 버퍼 비워주는 작업 요구됨 
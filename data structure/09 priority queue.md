# 09 Priority Queue
## 9.1 우선순위 큐의 개요
### 우선순위 큐?
* 우선순위 개념을 도입한 자료구조로 데이터들이 우선 순위를 가지고 있고 우선 순위가 높은 데이터가 먼저 나가게된다 
* 가장 일반적인 큐로 볼 수 있음 -> 적절한 우선 순위를 부여하여 큐, 스택도 구현할 수 있기 때문에
* 들어간 순서대로가 아닌 우선순위 개념 도입이 필요한 상황에 사용하고 컴퓨터의 여러 분야에서 이용됨 
* 사용 예)	
	* 도로에서 구급차나 소방차가 지나갈 때는 양보해야 함
	* 네트워크 패킷 중에서도 네트워크 관리와 관련된 패킷은 다른 일반 패킷보다 우선 순위 가짐
	* 시뮬레이션 시스템(우선 순위는 대개 사건의 시각), 네트워크 트래픽 제어, 운영 체제에서의 작업 스케줄링
	* 수치 해석적인 계산 등에 사용
* 배열, 연결 리스트 등의 방법으로 구현 가능하지만, 가장 효율적인 구조는 heap(히프)을 이용한 구현이다
* 우선 순위 큐의 ADT
	* 객체 : n개의 element형의 우선 순위를 가진 요소들의 모임
	* 연산
		* create()::= 우선순위 큐를 생성
		* init(q)::= 우선순위 큐를 생성한다
		* is_empty(q)::= 우선 순위 큐q가 가득 비어있는지 검사 
		* is_full(q)::= 우선 순위 큐q가 가득 찼는가를 검사
		* insert(q,x)::= 우선순위 큐 q에 요소 x를 추가
		* delete(q)::= 우선순위 큐로부터 가장 우선순위가 높은 요소를 삭제하고 그 요소를 반환
		* find(q)::= 우선 순위가 가장 높은 요소를 반환
	* insert와 delete연산이 핵심임! 
* 우선순위 큐는 2가지로 구분할 수 있음
	* 최소 우선순위 큐 : 가장 우선 순위가 낮은 요소를 먼저 삭제
	* 최대 우선순위 큐 : 가장 우선 순위가 높은 요소를 먼저 삭제

### 우선순위 큐의 구현
1. 배열을 사용하는 방법
	* 정렬된 배열 
		* 삽입은 삽입 위치를 탐색(순차 탐색, 이진 탐색 등)을 통해 찾은 후 삽입 위치 뒤에 있는 요소들을 이동시켜 빈자리를 만든 후 삽입
		* 삭제는 맨 뒤 혹은 맨 앞 요소 삭제하면 됨
	* 정렬되지 않은 배열
		* 삽입은 그냥 배열의 맨 끝에 요소를 추가하면 됨
		* 삭제는 가장 우선순위가 높은 요소를 탐색으로 찾고 삭제 후, 뒤에 있는 요소들을 앞으로 이동시킴

2. 연결리스트를 사용하는 방법
	* 삽입, 삭제 시 다른 노드를 이용할 필요 없이 포인터만 변경하면됨
	* 정렬된 경우 : 우선 순위가 높은 노드를 첫번째 노드로 함
		* 삽입 시 우선 순위 기준으로 삽입 위치 찾아 삽입 
		* 삭제 시 첫번째 노드 삭제
	* 정렬되지 않은 경우
		* 삽입 시 첫번째 노드로 삽입
		* 삭제 시 포인터를 따라 모든 노드 탐색

3. heap를 사용하는 방법
	* heap는 완전 이진트리의 일종으로 우선순위 큐를 위하여 만들어진 특별한 자료 구조
	* 완전히 정렬된 것은 아니지만 전혀 정렬 안 된 것도 아닌 상태인 느슨한 정렬 상태 유지한다
	* 다른 방법보다 상당히 효율적임
	* 참고 우선 순위 큐를 구현하는 여러 가지 방법 비교
	```
	표 
	``` 
## 9.2 Heap
### heap란?
* 컴퓨터 분야에서 히프는 완전 이진 트리 기반이며 더미(dummy)와 모습이 비슷한 특정한 자료 구조 
* 여러 개의 값들 중 최댓값 또는 최솟값을 빠르게 찾아내도록 만들어진 자료구조
* 히프의 종류는 2가지이며 다음 조건이 항상 성립하는 트리는 해당 히프이다(히프도 완전 이진 트리이므로 트리 임)
	* 최대 히프(max heap) : 부모노드의 키값이 자식노드의 키 값보다 항상 큰 히프 (key(부모 노드)>=key(자식노드))
	* 최소 히프(min heap) : 부모노드의 키 값이 자식노드의 키 값보다 항상 작은 히프(key(부모 노드)<=key(자식노드))
* 히프 안에서는 데이터들이 느슨한 정렬 상태 유지함
	* 느슨한 정렬상태 : 큰 값 또는 작은 값이 상위 레벨에 있고 작은 값 또는 큰값이 하위레벨에 있다는 정도
	* 삭제 시에는 최댓값 또는 최솟값만 찾아내기 위한 목적이므로 전체 정렬을 할 필요는 없다
* 중복 값 허용하며, 완전 이진 트리를 꼭 만족해야 함



## 9.3 Heap의 구현
### heap 구현의 기본
* 히프는 완전 이진 트리이므로 각각의 노드에 차례대로 번호를 부여 가능하다 -> 이 번호를 배열의 인덱스로 생각하여 배열 통해 히프 구현(단, 쉽게 구현 위해 0 인덱스는 사용 X)
* 새로운 노드가 추가되어도 특정위치의 노드 번호는 변하지 않음 (ex) 루트 노드의 오른쪽 노드는 항상 3번)
* 인덱스 관련 식
	* 왼쪽 자식의 인덱스 = (부모의 인덱스)*2
	* 오른쪽 자식의 인덱스 = (부모의 인덱스)*2+1
	* 부모의 인덱스 = (자식의 인덱스)/2

### heap 구현
* 삽입 연산
	* 신입사원을 일단 말단 자리에 앉힌 다음 능력에 따라 승진시키는 것과 유사
	* 새로운 요소가 들어오면 우선 히프의 마지막 노드에 이어서 삽입 후 heap의 성질을 만족할 때 까지 부모노드들과 교환하여 히프의 성질을 만족시킨다.

* 삭제 연산
	* 시장이 은퇴하면 가장 신입사원을 사장 자리로 올린 다음 강등시키는 것과 유사
	* 루트 노드 삭제 후 빈 루트 노드 자리에는 히프의 마지막 노드를 가져온다, 그 후 자식 노드들과 교환하여 히프의 성질을 만족시킨다.

* 코드) 매우중요*****
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200


typedef int element;

typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;//인덱스 1부터
}HeapType;

HeapType*create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType*h) {
	h->heap_size = 0;
}
void insert_max_heap(HeapType*h, element e) {
	if (h->heap_size == MAX_ELEMENT - 1)
		return;

	int idx= ++(h->heap_size);
	while (h->heap[idx / 2] <e&&idx>1) {
			h->heap[idx] = h->heap[idx / 2];
			idx /= 2;
	}
	h->heap[idx] = e;
}
element delete_max_heap(HeapType*h) {
	if (h->heap_size == 0)
		exit(1);

	element item = h->heap[1];
	element e = h->heap[h->heap_size--];
	int idx = 1;
	int child=idx*2;
	while (child <=h->heap_size) {//자식idx로 반복 조건 처리
		if ((child<h->heap_size)&&(h->heap[child] < h->heap[child + 1])) {//오른쪽 자식이 없을 경우 예외처리
			child ++;
		}
		if (e > h->heap[child])
			break;

		h->heap[idx] = h->heap[child];
		idx = child;
		child *= 2;
	}
	h->heap[idx] = e;
	return item;
	
}
int main() {
	element e1 =  10 , e2 = 5 , e3 =  30;
	element e4, e5, e6;
	HeapType*heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("< %d >\n", e4);
	e5 = delete_max_heap(heap);
	printf("< %d >\n", e5);
	e6 = delete_max_heap(heap);
	printf("< %d >\n", e6);
	return 0;
}

```
### heap의 복잡도 분석
* 삽입연산 : 새로운 요소가 히프트리를 타고 올라가면서 부모 노드들과 교환을 하게됨, 최악의 경우에는 루트까지 올라가야 함 -> 트리의 높이만큼 비교 및 이동연산 필요
	* 히프가 완전 이진트리이므로 높이는 log n이므로 O(log n)의 복잡도 가짐
* 삭제 연산 : 최악의 경우 가장 아래 레벨까지 내려가므로 역시 트리의 높이만큼 시간 소요됨
	* O(log n) 복잡도 가짐
## 9.4 히프 정렬(heap sort)
### 히프 정렬 이란?
* 최대 히프를 이용한 정렬
* n개의 요소는 O(n log n)시간 안에 정렬 가능
* 구현)
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200
#define SIZE 8		

typedef int element;

typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;//인덱스 1부터
}HeapType;

HeapType*create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType*h) {
	h->heap_size = 0;
}
void insert_max_heap(HeapType*h, element e) {
	if (h->heap_size == MAX_ELEMENT - 1)
		return;

	int idx= ++(h->heap_size);
	while (h->heap[idx / 2] <e&&idx>1) {
			h->heap[idx] = h->heap[idx / 2];
			idx /= 2;
	}
	h->heap[idx] = e;
}
element delete_max_heap(HeapType*h) {
	if (h->heap_size == 0)
		exit(1);

	element item = h->heap[1];
	element e = h->heap[h->heap_size--];
	int idx = 1;
	int child=idx*2;
	while (child <=h->heap_size) {//자식idx로 반복 조건 처리
		if ((child<h->heap_size)&&(h->heap[child] < h->heap[child + 1])) {//오른쪽 자식이 없을 경우 예외처리
			child ++;
		}
		if (e > h->heap[child])
			break;

		h->heap[idx] = h->heap[child];
		idx = child;
		child *= 2;
	}
	h->heap[idx] = e;
	return item;
	
}
void heap_sort(element*list, int size) {
	int i;
	HeapType*heap = create();
	init(heap);
	for (i = 0; i < size; i++) {
		insert_max_heap(heap,list[i]);
	}
	for (i = size-1; i >=0; i--) {
		list[i] = delete_max_heap(heap);
	}
	free(heap);
}
int main() {
	element list[8] = { 23,56,11,9,56,99,27,34 };
	heap_sort(list, SIZE);
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}

```

## 9.5 머쉰 스케줄링(machine scheduling)
### 머쉰 스케줄링 문제
* 어떤 공장에 동일한 기계가 m개 있다고 하면 우리는 처리해야 하는 작업을 n개 가지고 있을 때 각 작업이 필요로하는 기계의 사용시간은 다르다고 할때 모든 기계를 풀가동하여 최소의 시간 안에 작업들을 모두 끝내는 목표 갖는 문제
* 알고리즘 분야에서 상당히 유서 깊은 문제, 여러 응용분야 있음
	* ex) 서버가 여러 개 있어서 서버에 작업을 분배하는 문제

### LPT(longest time first) 방법
* 방법 중 하나로 긴 작업을 우선적으로 기계에 할당하는 방법
* 최소 히프를 이용해서 구현
* 구현)
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200
#define JOBS 7
#define MACHINES 3

typedef struct element {
	int id;//머신 id
	int avail;//사용가능시간
}element;

typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;//인덱스 1부터
}HeapType;

HeapType*create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType*h) {
	h->heap_size = 0;
}
void insert_min_heap(HeapType*h, element e) {
	if (h->heap_size == MAX_ELEMENT - 1)
		return;

	int idx= ++(h->heap_size);
	while (h->heap[idx / 2].avail >e.avail&&idx>1) {
			h->heap[idx] = h->heap[idx / 2];
			idx /= 2;
	}
	h->heap[idx] = e;
}
element delete_min_heap(HeapType*h) {
	if (h->heap_size == 0)
		exit(1);

	element item = h->heap[1];
	element e = h->heap[h->heap_size--];
	int idx = 1;
	int child=idx*2;
	while (child <=h->heap_size) {//자식idx로 반복 조건 처리
		if ((child<h->heap_size)&&(h->heap[child].avail > h->heap[child + 1].avail)) {//오른쪽 자식이 없을 경우 예외처리
			child ++;
		}
		if (e.avail < h->heap[child].avail)
			break;

		h->heap[idx] = h->heap[child];
		idx = child;
		child *= 2;
	}
	h->heap[idx] = e;
	return item;
	
}

int main() {
	int jobs[JOBS] = { 8,7,6,5,3,2,1 };
	element m = { 0,0 };
	HeapType*heap;
	heap = create();
	init(heap);
	int i;
	for (i = 0; i < MACHINES; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(heap, m);
	}
	for (i = 0; i < JOBS; i++) {//최소 히프에서 기계를 꺼내서 작업 할당하고 사용가능 시간 증가 시키고 다시 최소히프에 추가
		m = delete_min_heap(heap);
		printf("JOB %d을 시간=%d 부터 시간=%d까지 기계 %d번에 할당한다\n",i,m.avail, m.avail + jobs[i]-1,m.id);
		m.avail += jobs[i];
		insert_min_heap(heap, m);
	}
	return 0;
}

```

## 9.6 허프만 코드(Huffman code)
### 허프만 코드의 개념
* 각 글자의 빈도가 알려져 있는 텍스트 내용을 압축하는데 사용하는 방법
* 이때 사용하는 이진트리를 허프만 코딩 트리라 함
* 데이터를 압축할 때 ASCII코드와 같은 고정된 길이의 코드를 사용하지 않고 가변길이 코드를 사용
* 각 글자의 빈도수를 이용하여 데이터를 압축할 때 각 글자들을 나타내는 인코딩 비트열을 만들 수 있는데 빈도수에 따라 잘 나오는 글자에는 짧은 비트열, 잘 나오지 않는 글자에는 긴 비트열을 사용하여 전체 크기를 줄인다
* 글자를 나타내는 비트 열은 서로 간에 혼동을 일으키지 않아야 하며 해독 가능해야 함 
* 해독과정이 가능하게 하는 원인은 글자 나타내는 모든 코드가 다른 코드의 첫 부분이 아니기 때문이다 
	* 이러한 특수한 코드를 만들기 위해 이진 트리를 사용 -> 이 특수한 코드를 허프만 코드라 함

### 허프만 코드의 생성 과정
* 가장 작은 빈도수를 가지는 글자 2개(s(4), i(6))을 추출하여 이를 단말노드로 한 이진트리 생성하며 루트의 값은 각 자식 노드의 값을 합한 값이 된다
* 다시 정렬된 글자들의 리스트로 돌아가서 이 합쳐진 값을 글자들의 리스트에 삽입하여 다시 가장 작은 값 2개를 단말노드로 하여 이진트리 구성하는 과정 반복
* 허프만 트리에서 왼쪽 간선은 비트1을 나타내고 오른쪽 간선은 비트 0을 나타낸다. 
* 완성된 이진 트리에서 각 글자에 대한 호프만 코드는 루트 노드에서 단말 노드까지의 경로에 있는 간선의 라벨 값들의 나열이다.

### 허프만 코드 프로그램
* 각 빈도수를 단일 노드로 만들고 최소 히프에 넣은 후 가장 작은 2개의 빈도수를 갖는 노드 2개를 꺼낸 후 합쳐서 하나의 트리로 만들고 그 합친 값을 다시 최소 히프에 넣어 같은 과정 반복하여 트리 완성
* 코드 
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200

//그냥 element와 2개 합쳐진 element 구분 해야함


typedef struct TreeNode {
	int weight;
	char ch;
	struct TreeNode*left, *right;
}TreeNode;

typedef struct element {
	TreeNode*ptree;
	int freq;
	char ch;
}element;
typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;//인덱스 1부터
}HeapType;

HeapType*create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType*h) {
	h->heap_size = 0;
}
void insert_min_heap(HeapType*h, element e) {
	if (h->heap_size == MAX_ELEMENT - 1)
		return;

	int idx= ++(h->heap_size);
	while (h->heap[idx / 2].freq >e.freq&&idx>1) {
			h->heap[idx] = h->heap[idx / 2];
			idx /= 2;
	}
	h->heap[idx] = e;
}
element delete_min_heap(HeapType*h) {
	if (h->heap_size == 0)
		exit(1);

	element item = h->heap[1];
	element e = h->heap[h->heap_size--];
	int idx = 1;
	int child=idx*2;
	while (child <=h->heap_size) {//자식idx로 반복 조건 처리
		if ((child<h->heap_size)&&(h->heap[child].freq > h->heap[child + 1].freq)) {//오른쪽 자식이 없을 경우 예외처리
			child ++;
		}
		if (e.freq < h->heap[child].freq)
			break;

		h->heap[idx] = h->heap[child];
		idx = child;
		child *= 2;
	}
	h->heap[idx] = e;
	return item;
	
}
TreeNode* makeTree(TreeNode*left,TreeNode*right) {
	TreeNode*node = (TreeNode*)malloc(sizeof(TreeNode));
	//node->ch = NULL;
	node->left = left;
	node->right = right;
	return node;
}

void destroy_tree(TreeNode*root) {
	if (root == NULL)
		return;

	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}
void print_codes(TreeNode*root, int codes[], int len) {

	if (root == NULL) return;
	if (root->left != NULL) {
		codes[len] = 1;//len++ (x) : 현재 len값은 변하면 안됨
		print_codes(root->left, codes, len+1);
	}
	if (root->right != NULL) {
		codes[len] = 0;
		print_codes(root->right, codes, len+1);
	}
	if (root->left == NULL && root->right == NULL) {
		printf("%c : ", root->ch);
		int i;
		for (i = 0; i < len; i++) {
			printf("%d", codes[i]);
		}
		printf("\n");
	}

}

void huffman_tree(int freq[], char ch_list[], int size) {
	HeapType*heap=create();
	init(heap);
	element e;
	int i;
	element e1, e2;
	TreeNode*root;
	int codes[100];
	int len = 0;
	for (i = 0; i < size; i++) {
		e.ptree = makeTree(NULL, NULL);
		e.freq = e.ptree->weight=freq[i];
		e.ch = e.ptree->ch=ch_list[i];
		insert_min_heap(heap,e);
	}

	for(i=0;i<size-1;i++) {
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		root = makeTree(e1.ptree, e2.ptree);
		root->weight = e.freq=e1.freq + e2.freq;
		e.ptree = root;
		printf("%d + %d -> %d\n", e1.freq, e2.freq, e.freq);
		insert_min_heap(heap,e);
	}
	e = delete_min_heap(heap);
	print_codes(e.ptree,codes,len);
	destroy_tree(e.ptree);
	free(heap);
}



int main() {
	char ch_list[] = { 's','i','n','t','e' };
	int freq[] = { 4,6,8,12,15 };
	huffman_tree(freq, ch_list, 5);
	return 0;
}

```
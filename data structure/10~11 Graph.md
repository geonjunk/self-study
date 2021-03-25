# 10 Graph
## 10.1 그래프란?
### 그래프의 개요 
* 객체 사이의 연결 관계를 표현할 수 있는 자료구조
* 도시, 소자, 자원, 프로젝트 등의 객체들을 서로 연결되어 있는 구조로 표현할 수 있는 논리적 도구
* 사용 예 
	* 지하철 노선도 : 여러 개의 역들이 어떻게 연결되었는지 보여주며, 특정 역에서 다른 역으로 가는 최단 경로 쉽게 프로그래밍해서 찾을 수 있음
	* 전기 소자 : 전기 회로의 소자들이 어떻게 연결되었는지 확인하여 회로 제대로 작동하는지 분석 가능
	* 운영체제 : 프로세스와 자원들이 어떻게 연관된느지를 그래프로 분석하여 시스템 효율이나 교착 상태 유무등을 알아낼 수 있음
	* 도로 : 도로의 교차점과 일방통행길 등을 표현 가능
	* 미로, 선 이수 과목 등
* 인접 행렬이나 인접 리스트로 메모리에 표현되고 처리될 수 있어 광범위한 분야의 다양한 문제들을 그래프로 표현하여 해결가능
* 비선형 자료구조이며, 아주 일반적인 자료구조로 트리도 그래프의 특수한 종류로 볼 수 있음
* 배열, 선형리스트 등으로 표현 불가능한 복잡한 문제들을 표현가능 
* 그래프 이론 : 컴퓨터 학문 분야의 활발한 연구 주제로 문제 해결을 위한 도구로서 많은 이론과 응용이 존재한다

### 그래프의 역사(오일러 정리)
* 그래프는 오일러가 Konkigsberg의 다리 문제를 해결하기 위해 처음 사용
	* Konigsberg의 다리문제 : 임의의 지역에서 출발하여 모든 다리를 단 한번만 건너 처음 출발했던 지역으로 돌아올 수 있는가?
	* 오일러는 이문제의 핵심적인 것을 "A,B,C,D(각 지역)의 위치가 어떠한 관계로 연결되었는가?" 라고 생각하고 특정 지역은 정점(node), 다리는 간선(edge)로 표현하여 그래프 문제로 변환
* 이러한 그래프에 존재하는 모든 간선을 한번만 통과하면서 처음 정점으로 되돌아오는 경로를 오일러 회로라 정의하고 그래프의 모든 정점에 연결된 간선의 개수가 짝수(차수가 짝수)일 때만 오일러 회로(Eulerian circuit)가 존재한다는 오일러 정리 증명함

## 10.2 그래프의 정의와 용어
### 그래프의 정의
* 정점(vertex)와 간선(edge)들의 유한 집합
* 수학적으로는 G=(V,E)
	* V(G)는 그래프 G의 정점들의 집합, E(G)는 그래프의 간선들의 집합
	* 정점(vertex) : 여러 가지 특성을 가질 수 있는 개체, 노드(node)라고도 불림
	* 간선(edge) : 정점들 간의 관계, 링크(link)라고도 불림

### 무방향 그래프와 방향 그래프
* 무방향 그래프(undirected graph)  
	* 간선과 간선을 통해서 양방향으로 갈 수 있는 그래프 
	* 정점 A와 정점 B를 연결하는 간선은 (A,B)와 같이 정점의 쌍으로 표현하며 (A,B)와 (B,A)는 동일한 간선
	* ex) V(G) = {0,1,2,3}, E(G)={(0,1),(0,3),(1,3),(2,3)}

* 방향 그래프(directed graph) 
	* 간선에 방향성이 존재하는 그래프
	* 도로의 일방통행 길처럼 간선을 통하여 한쪽 방향으로만 갈 수 있음을 나타냄
	* 정점 A에서 정점 B로만 갈수 있는 간선은 <A,B>로 표시, <A,B>와 <B,A>는 다른 간선임
	* ex) V(G) = {0,1,2,3}, E(G)={<0,1>,<0,3>,<3,1>,<2,3>}
### 가중 그래프(네트워크)
* 간선에 비용이나 가중치가 할당된 그래프
* 연결 강도까지 나타낼 수 있어 복잡한 관계 표현 가능
* 응용분야) 도시와 도시 연결하는 도로의 길이, 회로소자의 용량, 통신망의 사용료 등 표현 가능

### 부분 그래프(subgraph)
* 어떤 그래프의 정점의 일부와 간선의 일부로 이루어진 그래프
* V(S)⊆V(G), E(S)⊆E(G) 수식 만족한다

### 정점의 차수
* 인접 정점(adjacent vertex) : 간선에 의해 직접 연결된 정점
* 인접과 부속 : 정점 a,b에 대하여 간선 (a,b)존재하면, a는 b와 인접하다하며, 간선 (a,b)는 정점 a와 b에 부속한다함
* 정점의 차수(degree) : 해당 정점에서 인접 정점의 수
* 무방향 그래프에서 모든 정점의 차수의 합 = 간선의 수*2 (하나의 간선에 두 개의 정점이 인접하기 때문)
* 방향 그래프에서는 외부에서 오는 간선의 개수를 진입 차수(in-degree), 외부로 향하는 간선의 개수를 진출 차수(out-degree)라 함
 
### 경로
* 무방향 그래프에서 정점 s로부터 정점 e까지의 경로는 정점의 나열 s,v1,v2...,vk,e로, 나열된 정점들 간에는 반드시 간선 (s,v1),(v1,v2)...(vk,e)가 존재해야 함
* 방향 그래프에서는 간선 <s,v1>,<v1,v2>..<vk,e>가 존재해야 함
	* ex) 경로를 0,1,2,3 이라 했을 때 간선 (1,2) 또는 <1,2>가 존재하지 않으면 경로가 아님 -> 정점 사이에 간선이 존재햐야함!
* 단순 경로(simple path) : 경로 중에서 반복되는 간선이 없는 경우의 경로
* 사이클 (cycle) : 단순 경로의 시작 정점과 종료정점이 동일한 경우의 경로

### 연결 그래프
* 그래프 G에 있는 모든 정점 쌍에 대하여 항상 경로가 존재한다면 G는 연결되었다고 하며 이러한 그래프를 연결 그래프(Connected graph)라 함
* 연결되지 않은 그래프는 비연결 그래프(unconnected graph)라함 

### 완전 그래프 
* 그래프에 속해있는 모든 정점이 서로 연결되어 있는 그래프
* 정점의 개수 n개라 하면 하나의 정점은 n-1개의 다른 정점으로 연결됨 
	* 무방향 그래프에서 간선의 개수 : n(n-1)/2
	* 방향 그래프 간선의 개수 : n(n-1)(두 정점에 방향이 다른 두 간선 연결 가능하므로) 

### 그래프의 ADT
* ADT Graph
	* 객체 : 정점의 집합과 간선의 집합
	* 연산 (간선은 2개의 정점을 이용하여 표현) 
		* create_graph()::=그래프를 생성
		* init(g)::=그래프 g를 초기화 함
		* insert_vertex(g,v)::= 그래프 g에 정점 v를 삽입
		* insert_edge(g,u,v)::= 그래프 g에 간선 (u,v)를 삽입
		* delete_vertex(g,v)::= 그래프 g의 정점 v를 삭제
		* delete_edge(g,u,v)::= 그래프 g의 간선 (u,v)를 삭제
		* is_empty(g)::= 그래프 g가 공백 상태인지 확인한다
		* adjacent(v)::= 정점 v에 인접한 정점들의 리스트를 반환
		* destroy_graph(g)::= 그래프 g를 제거
		
## 10.3 그래프의 표현 방법
### 표현 방법 2가지 
* 2가지 방법있으며 각각 메모리 사용량과 처리 시간 등에서 장단점 가지므로 문제에 적합한 표현 선택하여 이용
 	1. 인접 행렬(adjacency matrix) : 2차원 배열을 사용하여 그래프를 표현
	2. 인접 리스트(adjacency list) : 연결리스트를 사용하여 그래프를 표현

### 인접 행렬 
* 정점의 수가 n이라면 n x n의 2차원 배열로 나타내는 방식
* 인접행렬 M이라 하면 M의 각 원소를 규칙을 따라 할당
	* 규칙 if(간선(i,j)가 그래프에 존재) M[i][j]=1, otherwise M[i][j]=0
* 무방향 그래프에서는 인접 행렬이 대칭 행렬이 됨
	* 간선 (I,j)는 i에서 j로부터 연결 뿐만 아니라 j에서 i로의 연결을 동시에 의미하기 때문
	* 이를 이용해 하위 삼각, 상위 삼각만 저장하여 메모리 절약하는 방법도 있음
* 간선이 많이 존재하는 밀집 그래프(dense graph)를 표현하는 경우에는 적합
* 적은 숫자의 간선만을 가지는 희소 그래프(sparse graph)의 경우에는 메모리 낭비가 크므로 적합하지 않음
* 두 정점을 연결하는 간선의 존재 여부를 O(1) 시간 안에 즉시 할 수 있다 ->M[u][v]의 값만 조사하면 됨 
* 정점의 차수는 인접행렬의 행이나 열만 조사하면 알수 있으므로 O(n)만에 가능
	* Degree(i) = ∑_(k=0)^(n-1)▒?M[i][k]? (i번째 행에 있는 값 모두 더함)  
* 그래프에 존재하는 모든 간선의 수 알아내려면 인접 행렬 전체 조사해야 하므로 O(n^2)의 시간 요구 됨
* 구현) 무방향 그래프의 예시 
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50
typedef struct GraphType{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init(GraphType*g){
	int r,c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;r++){
		for(c=0;c<MAX_VERTICES;c++){
			g->adj_mat[r][c]=0;
		}
	}

}

void insert_vertex(GraphType*g,int v){
	if((g->n+1)>MAX_VERTICES){
		fprintf(stderr,"그래프: 정점의 개수 초과");
		return; 
	}
	g->n++;
}
void insert_edge(GraphType*g,int u,int v){
	if(g->n<=u||g->n<=v){
		fprintf(stderr,"그래프: 정점 번호 오류");
		return; 
	}
	g->adj_mat[u][v]=g->adj_mat[v][u]=1;
}

void print_adj(GraphType*g){
	int r,c;
	for(r=0;r<g->n;r++){
	for(c=0;c<g->n;c++){
		printf("%2d",g->adj_mat[r][c]);
	}
	printf("\n"); 
   }	
}


int main(){
	GraphType*g;
	g=(GraphType*)malloc(sizeof(GraphType));
	init(g);
	
	int i;
	for(i=0;i<4;i++) 
	insert_vertex(g,i);
	
	insert_edge(g,0,1);
	insert_edge(g,0,2);
	insert_edge(g,0,3);
	insert_edge(g,1,2);
	insert_edge(g,2,3);
	
	print_adj(g);
	
	free(g);
	return 0;
}
``` 
### 인접 리스트
* 각각의 정점에 인접한 정점들을 연결 리스트로 표시한 것
* 각 연결리스트의 노드들은 인접 정점을 저장하게 되며, 각 연결리스트 들은 헤더 노드를 가지고 있고 이 헤더 노드들은 하나의 배열로 구성됨
* 즉, 정점의 번호만 알면 이 번호를 배열의 인덱스로 하여 헤더 노드를 접근해 각 정점의 연결리스트에 쉽게 접근 가능하다
* 정점의 개수가 n개이고 간선의 개수가 e개인 무방향 그래프에서는 n개의 연결리스트와 n개의 헤더노드와 2e개의 노드가 필요함
* 간선의 개수가 적은 희소 그래프 표현에 적합
* 간선 (i,j)의 존재 여부, 정점 i의 차수를 알기 위해서는 정점 i의 연결리스트 탐색해야 함 -> 연결리스트에 있는 노드의 수 만큼, 정점의 차수만큼 시간 필요
* 따라서, n개의 정점과 e개의 간선을 가진 그래프에서 전체 간선의 수를 알아내려면 헤더노드 포함 모든 인접리스트를 조사해야하므로 O(n+e)의 연산 요구됨
* 참고) 각각의 연결 리스트에 정점들이 입력되는 순서에 따라 연결 리스트 내에서 정점들의 순서가 달라질 수 있으므로 일관성 유지하기 위해 정점의 오름차순 또는 내림차순으로 연결된다고 해준다.
* 구현)
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphNode{
	int vertex;
	struct GraphNode*link;
}GraphNode;

typedef struct GraphType{
	GraphNode*adj_list[MAX_VERTICES];
	int n;
}GraphType;

void init(GraphType*g){
	g->n=0;
	int i;
	for(i=0;i<MAX_VERTICES;i++)
		g->adj_list[i]=NULL;
}
void insert_vertex(GraphType*g,int v){
	if((g->n+1)>MAX_VERTICES){
		fprintf(stderr,"그래프: 정점의 개수 초과");
		return; 
	}
	g->n++;
}

void insert_edge(GraphType*g,int v,int u){
	if(g->n<=v||g->n<=u){
		fprintf(stderr,"그래프: 정점 번호 오류");
		return; 
	}
	GraphNode*node=(GraphNode*)malloc(sizeof(GraphNode));
	node->vertex=u;
	node->link=g->adj_list[v];
	g->adj_list[v]=node;

/*	GraphNode*temp=g->adj_list[v];
	node->link=temp;
	temp=node;
*/	
}
print_adj_list(GraphType*g){
	int i;
	for(i=0;i<g->n;i++){
		printf("정점 %d의 인접 리스트 ",i);
		GraphNode*node=g->adj_list[i];
		while(node!=NULL){
		printf("-> %d",node->vertex);
		node=node->link;	
		}
		printf("\n");
	}
	
}

int main(){
	GraphType*g;
	g=(GraphType*)malloc (sizeof(GraphType));
	init(g);
	int i;
	for(i=0;i<4;i++)
	insert_vertex(g,i);
	
	insert_edge(g,0,1);
	insert_edge(g,1,0);
	insert_edge(g,0,2);
	insert_edge(g,2,0);
	insert_edge(g,0,3);
	insert_edge(g,3,0);
	insert_edge(g,1,2);
	insert_edge(g,2,1);
	insert_edge(g,2,3);
	insert_edge(g,3,2);
	print_adj_list(g);
	free(g);
	return 0;
}

``` 
### 간선 리스트 
* 배열에 간선들만 저장
* 가장 간단하게 구현되지만 한 정점의 간선에 대한 정보를 얻기 위해서는 모든 부분을 탐색해야 함
* 일부 알고리즘 구현 시 사용 ex) 크루스칼 알고리즘 
* 참고) DFS 와 BFS구현 시 stack이나 queue에 넣으면서 방문했다고 표시 하는 방법이 있고 꺼내면서 방문했다고 표시하는 방식도 있다.

## 10.4 그래프의 탐색	 
* 그래프 탐색 : 가장 기본적인 연산으로 정점으로 부터 차례대로 모든 정점을 한 번씩 방문하는 것
* 그래프 탐색으로 특정한 정점에서 다른 정점 갈 수 있는지 여부 등 많은 문제들 해결 가능
	* 예) 특정 도시에서 다른 도시로 갈 수 있는지 없는지 판단, 회로에서 특정 단자와 단자가 서로 연결되어 있는지 확인 등
* 탐색 방법의 종류
	* 깊이 우선 탐색 (DFS : depth first search) : 트리(그래프의 일종)의 탐색 방법과 유사하며 시작 정점에서 한 방향으로 계속 가다가 더이상 갈 수 없게 되면 다시 가장 가까운 갈림길로 돌아와 다른 방향으로 다시 탐색을 진행하는 방법
	* 너비 우선 탐색(BFS : breath first search) : 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법
	* ex) BFS / DFS
	```
	```

## 10.5 깊이 우선 탐색
### 깊이 우선 탐색 
* 전체적인 과정 
	* 시작 정점 v라고 하면 시작 정점v 방문하였다고 표시
	* 이어서 v에 인접한 정점들 중에서 아직 방문하지 않은 정점을 선택
	* 그러한 정점이 없다면 최근 탐색했던 정점에서부터 인접한 정점 중 방문하지 않은 정점이 있는지 확인하고 있으면 그 정점 기준으로 깊이 우선 탐색 실행
	* 없으면 그전에 방문한 정점에서 또 확인하고 모든 정점 탐색 할 때까지 과정 반복한다
* 순환 알고리즘 형태 가지고 있으며 명시적 스택으로도 구현 가능
* visited라는 방문 여부 확인하는 배열 생성하여 이용한다
* 의사 코드
	* 재귀 알고리즘 의사 코드
		```
		depth_first_search(v) :
		v를 방문되었다고 표시;
		for all u ∈ (v에 인접한 정점) do
  		if(u가 아직 방문되지 않았으면) 
   		then depth_first_search(u)

		``` 
	* 명시적 스택 의사 코드
		```
		DFS-iterative(G,v):
		스택 s생성 
		s.push(v)
		while(not is_empty(s)) do
		v=s.pop()
		if(v가 방문되지 않았으면) 
		v를 방문되었다고 표시
    	For all u ∈ (v에 인접한 정점) do
    	If(u가 아직 방문되지 않았으면) 
    	s.push(u)

		```	 
### 깊이 우선 탐색의 구현
1. 인접 행렬 버전
	* 순환 호출 이용
	```
	#include<stdio.h>
	#include<stdlib.h>
	#define MAX_VERTICES 50


	typedef struct GraphType{
		int adj_mat[MAX_VERTICES][MAX_VERTICES];
		int n;
	}GraphType;

	int visited[MAX_VERTICES]={0,};
	void init(GraphType*g){
		g->n=0;
		int r,c;
		for(r=0;r<MAX_VERTICES;r++){
			for(c=0;c<MAX_VERTICES;c++){
				g->adj_mat[r][c]=0;
			}
		}
	}
	void insert_vertex(GraphType*g,int v){
		if((g->n+1)>MAX_VERTICES){
			fprintf(stderr,"그래프: 정점의 개수 초과");
			return; 
		}
		g->n++;
	}

	void insert_edge(GraphType*g,int v,int u){
		if(g->n<=v||g->n<=u){
			fprintf(stderr,"그래프: 정점 번호 오류");
			return; 
		}
		g->adj_mat[v][u]=g->adj_mat[u][v]=1;
	}

	void dfs_mat(GraphType*g,int v){
		if(s>=g->n){
			fprintf(stderr,"그래프: 정점 번호 오류");
			return; 
		}
		visited[v]=1;
		printf("정점 %d->",v);
		int i;
		for(i=0;i<g->n;i++)
			if(g->adj_mat[v][i]&&!visited[i])
				dfs_mat(g,i);

	}
	int main(){
		GraphType*g;
		g=(GraphType*)malloc (sizeof(GraphType));
		init(g);
		int i;
		for(i=0;i<4;i++)
		insert_vertex(g,i);
		
		insert_edge(g,0,1);
		insert_edge(g,0,2);
		insert_edge(g,0,3);
		insert_edge(g,1,2);
		insert_edge(g,2,3);

		printf("깊이 우선 탐색\n");
		dfs_mat(g,0); 
		free(g);
		return 0;
	}

	``` 
 	* 명시적 스택 이용 
	```
	void dfs_mat(GraphType*g,int v) {
	Stack s;
	initStack(&s);
	push(&s, v);
	int u;
	int i;
	while (!isEmpty(&s)) {
		u = pop(&s);
		if (!visited[u]) {//stack에 있는 중에 방문할 수 있으므로 if문 필요 
			visited[u] = 1;
			printf("정점 %d 방문 -> ", u);
		}
		for (i = 0; i < g->n; i++) {
			if (g->adj_mat[u][i] && !visited[i])
				push(&s, i);
		}
	}

	}
	
	```
2. 인접 리스트 버전
	* 순환 호출 이용
	```
	#include<stdio.h>
	#include<stdlib.h>
	#define MAX_VERTICES 50

	typedef struct GraphNode{
		int vertex;
		struct GraphNode*link;
	}GraphNode;
	typedef struct GraphType{
		GraphNode*adj_list[MAX_VERTICES];
		int n;
	}GraphType;


	int visited[MAX_VERTICES]={0,};
	void init(GraphType*g){
		g->n=0;
		int i;
		for(i=0;i<MAX_VERTICES;i++){
			g->adj_list[i]=NULL;
		}
	}
	void insert_vertex(GraphType*g,int v){
		if((g->n+1)>MAX_VERTICES){
			fprintf(stderr,"그래프: 정점의 개수 초과");
			return; 
		}
		g->n++;
	}

	void insert_edge(GraphType*g,int v,int u){
		if(g->n<=v||g->n<=u){
			fprintf(stderr,"그래프: 정점 번호 오류");
			return; 
		}
		GraphNode*node=(GraphNode*)malloc(sizeof(GraphNode));
		node->vertex=u;
		node->link=g->adj_list[v];
		g->adj_list[v]=node;
	}

	void dfs_list(GraphType*g,int v){
		if(v>=g->n){
			fprintf(stderr,"그래프: 정점 번호 오류");
			return; 
		}
		printf("정점 %d방문->",v);
		visited[v]=1;
		GraphNode*u;
		for(u=g->adj_list[v];u!=NULL;u=u->link){
			if(!visited[u->vertex]){
				dfs_list(g,u->vertex);
			}
		}

	}
	int main(){
		GraphType*g;
		g=(GraphType*)malloc (sizeof(GraphType));
		init(g);
		int i;
		for(i=0;i<4;i++)
		insert_vertex(g,i);
		insert_edge(g,2,3);
		insert_edge(g,3,2);
		insert_edge(g,1,2);
		insert_edge(g,2,1);
		insert_edge(g,0,3);
		insert_edge(g,3,0);
		insert_edge(g,0,2);
		insert_edge(g,2,0);
		insert_edge(g,0,1);
		insert_edge(g,1,0);



		printf("깊이 우선 탐색\n");
		dfs_list(g,0); 
		free(g);
		return 0;
	}

	```
	* 명시적 스택 이용
	```
	void dfs_list(GraphType*g, int v) {
	if(v>=g->n){
		fprintf(stderr,"그래프: 정점 번호 오류");
		return; 
	}
	Stack s;
	init(&s);
	push(&s,v);
	int temp;
	while (!isEmpty(&s)) {
		temp = pop(&s);
		if (!visited[temp]) {
			visited[temp] = 1;
			printf("정점 %d -> ", temp);
		}
		
		
		GraphNode*u;
		for (u = g->adj_list[temp]; u != NULL; u = u->link) {
			if (!visited[u->vertex]) 
				push(&s, u->vertex);
			
			}
		}
	}

	```
### 깊이 우선 탐색의 분석 
* 모든 간선 조사하므로 정점의 수가 n이고 간선의 수가 e인 그래프의 경우 
	* 인접 리스트: O(n+e) 
	* 인접 행렬: O(n^2)
	* 희소 그래프의 경우 인접리스트가 시간적으로 유리

## 10.6 너비 우선 탐색(BFS)
### 너비 우선 탐색
* 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법
* 가까운 거리순으로 정점 방문 ex) 거리 0인정점->거리 d인정점->d+1인 정점…
* 가까운 거리에 있는 정점들을 차례대로 저장한 후 꺼낼 수 있는 자료구조 큐 (Queue) 이용
* 너비 우선 탐색의 의사 코드
	```
	breath_first_search(v):
	 	v를 방문되었다고 표시:
 		큐에 Q에 정점 v를 삽입;
 		While(Q가 공백이 아니면) do
  		 Q에서 정점 w를 삭제;
  		 For all u ∈ (v에 인접한 정점) do
       	 If(u가 아직 방문되지 않았으면) 
        	Then u를 큐에 삽입; 
             	U를 방문되었다고 표시;

	``` 
### 너비 우선 탐색의 구현
1. 인접 행렬 버전
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

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

typedef struct GraphType{
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
	int n;
}GraphType;

int visited[MAX_VERTICES]={0,};
void init(GraphType*g){
	g->n=0;
	int r,c;
	for(r=0;r<MAX_VERTICES;r++){
		for(c=0;c<MAX_VERTICES;c++){
			g->adj_mat[r][c]=0;
		}
	}
}
void insert_vertex(GraphType*g,int v){
	if((g->n+1)>MAX_VERTICES){
		fprintf(stderr,"그래프: 정점의 개수 초과");
		return; 
	}
	g->n++;
}

void insert_edge(GraphType*g,int v,int u){
	if(g->n<=v||g->n<=u){
		fprintf(stderr,"그래프: 정점 번호 오류");
		return; 
	}
	g->adj_mat[v][u]=g->adj_mat[u][v]=1;
}


void bfs_mat(GraphType*g,int v){
	if(v>=g->n){
		fprintf(stderr,"그래프: 정점 번호 오류");
		return; 
	}
	Queue q;
	init_queue(&q);
	enqueue(&q,v);
	visited[v]=1;
	printf("%d 방문 -> ",v);
	int i;
	element u;
	while(!is_empty(&q)){
		u=dequeue(&q);
		for(i=0;i<g->n;i++){
			if(g->adj_mat[u][i]&&!visited[i]){
				enqueue(&q,i);
				visited[i]=1;
				printf("%d 방문 -> ",i);
			}
		}
		
	}
	

}
int main(){
	GraphType*g;
	g=(GraphType*)malloc (sizeof(GraphType));
	init(g);
	int i;
	for(i=0;i<6;i++)
		insert_vertex(g,i);다 


	insert_edge(g,0,2);
	insert_edge(g,2,1);
	insert_edge(g,2,3);
	insert_edge(g,0,4);
	insert_edge(g,4,5);
	insert_edge(g,1,5);
	
	printf("너비 우선 탐색\n");
	bfs_mat(g,0); 
	free(g);
	return 0;
}


```
2. 인접 리스트 버전
```
void bfs_list(GraphType*g,int v) {
	QueueType q;
	queue_init(&q);
	enqueue(&q, v);
	visited[v] = 1;
	printf("%d 방문 -> ", v);
	element u;
	int i;
	GraphNode*w;
	while (!is_empty(&q)) {
		u = dequeue(&q);
		for (w = g->adj_list[u]; w != NULL; w = w->link) {
			if (!visited[w->vertex]) {
				enqueue(&q, w->vertex);
				visited[w->vertex] = 1;
				printf("%d 방문 -> ", w->vertex);
			}
				
		}

	}

}

```
### 너비 우선 탐색의 분석
* 인접 리스트의 경우 O(n+e)만 큼 걸리고 인접행렬 경우에는 O(n^2)으로 깊이 우선 탐색과 같다.
* 희소 그래프인 경우 인접리스트 사용하는 것이 효율적이다.

# 11 Graph 2 
## 11.1 최소 비용 신장트리
### 신장 트리(spanning tree)
* 신장 트리의 개념 
1. 그래프의 모든 정점을 포함
2. 모든 정점들이 연결되어 있어야 하고 사이클이 존재하지 않는 그래프(->트리의 조건) 
* 신장 트리는 최소 연결 그래프로(최소의 간선 수를 갖는 연결 그래프) 
* 그래프에 있는 n개의 정점을 연결하려면 최소 n-1개의 간선을 가져야 하며 n-1개의 간선으로 연결되어 있으면 필연적으로 트리 형태가 되며 신장 트리가됨 
* 하나의 그래프에는 많은 신장 트리가 존재 가능
* 탐색(dfs,bfs)때 사용한 간선들을 표시하여 신장 트리 만들 수 있음
* 활용) 통신 네트워크를 최소 링크 수를 이용한 구축, 가장 적은 수의 케이블을 이용한 전화기 연결
* but, 비용은 고려하지 못함 -> 적은 수의 간선을 사용하다고 최소 비용이 얻어지는 것은 아님 
* 이때는 최소 비용의 신장 트리를 선택할 필요가 있음

### 최소 비용 신장 트리(Minimal cost spanning tree)(MST)
* 최소 비용 신장 트리(MST) :  신장 트리 중에서 사용된 간선들의 가중치 합이 최소인 신장 트리 
* 통신망, 도로망, 유통망 등은 간선에 가중치 (길이, 구축비용, 전송시간 등)가 부여된 네트워크로 표현될 수 있는데 
* 이러한 것들을 가장 적은 비용으로 구축하려면, 네트워크에 있는 모든 정점들을 가장 적은 수의 간선과 비용으로 연결하는 최소 비용 시장 트리(MST)가 필요함
* 응용 예) 
	* 도로 건설 - 도시들을 모두 연결하면서 도로의 길이 최소
	* 전기 회로 - 단자들을 모두 연결하면서 전선의 길이가 최소 
	* 통신 - 전화선의 길이가 최소가 되도록하는 전화 케이블 망을 구성
	* 배관 - 파이프를 모두 연결하면서 파이프의 총 길이가 최소
* MST를 구하는 방법
	* Kruskal 알고리즘, prim 알고리즘이 대표적
	* 이 알고리즘들은 간선의 가중치 합이 최소,  n-1개의 간선만 사용, 사이클이 없다는 조건을 적절히 이용함


## 11.2 Kruskal의 MST 알고리즘
### kruskal 알고리즘과 greedy method(탐욕적인 방법)
* greedy method(탐욕적인 방법) : 알고리즘 설계에 있어서 중요한 기법 중 하나로 선택할 때 마다 그 순간 가장 좋다고 생각되는 것을 선택 함으로써 최종적인 해답에 도달하는 방법
	* ex) 먹을 때 맛있는 것부터 먹기...
* greedy는 선택 당시에는 최적이지만 최적이라고 생각했던 지역적인 해답들을 모아서 최종적인 해답이 반드시 전역적으로 최적이라는 보장은 없다
* Kruskal 알고리즘은 최소 비용의 간선으로 구성, 사이클 포함하지 않음 조건에 근거하여 각 단계에서 사이클을 이루지 않는 최소 비용 간선을 선택하는 과정을 반복하여 모든 정점을 최소 비용응로 연결하는 최적의 해답 구할 수 있다 

### Kruskal 알고리즘의 동작
1. 그래프의 간선들을 가중치의 오름차순으로 정렬
2. 정렬된 간선들의 리스트에서 가중치가 가장낮고 사이클을 형성하지 않는 간선을 찾아서 선택한다 
3. 해당 간선을 현재의 최소 비용 신장 트리의 집합에 추가
* MST 구하는 다른 알고리즘보다 간단함
* 다음 간선을 이미 선택된 간선들의 집합에 추가할 때 사이클 생성하는지를 체크하는 과정 요구
* 새로운 간선이 연결하는 양끝 정점이 같은 집합에 속해 있으면 사이클 형성되고 간선이 서로 다른 집합에 속하는 정점을 연결하면 사이클이 형성되지 않는다 
* 추가하려는 간선의 양 끝 정점이 같은 집합에 속하는지 검사하여야 함 
* 이때 사용하는 것이 union-find 알고리즘

### union-find(disjoint set) 연산
* 공통 원소가 없는, 즉 상호 배타적으로 이루어진 집합(서로소 집합)을 표현할 때 사용하는 알고리즘
* 집합을 구현하는데 비트 섹터, 배열, 연결 리스트를 이용할 수 있으나 가장 효울적인 방법은 트리 형태 이용
* 각 노드에 대해 그 노드의 부모 노드만 알면되므로 '부모 포인터 표현' 사용
* 부모 포인터 표현 
	* 각 노드에 대해 부모에 대한 포인터만 저장하는 것
	* 부모 포인터 표현은 노드의 가장 오른쪽 자식, 왼쪽 자식을 찾는 것과 같은 목적에는 부적합하지만 두노드가 같은 트리에 있음 판단가능
	* 즉, 집합 구현 가능
	* 포인터를 사용하지 않고 1차원배열을 통해 구현 가능하다
		* 배열 안에는 부모 노드의 인덱스를 저장하며 부모 노드가 없거나 루트노드이면 -1(또는 자기 자신으로)저장한다
		* ex) 
* union-find의 연산
	1. init(n) : 초기화 연산 , n개의 원소가 자기 자신만을 원소로 갖는 각각의 집합이 되도록 초기화
	2. union(x,y) : 두 원소 x와 y가 속해있는 2개의 집합의 합집합을 만든다
	3. find(x) : 원소 x가 속해있는 집합을 반환한다
* 구현)
 ```
 void set_init(int n){
	int i;
	for(i=0;i<n;i++){
		parents[i]=-1;
	}
}
void set_union(int x,int y){
	int a,b;
	a=set_find(x);
	b=set_find(y);
	if(a!=b)
	parents[a]=b;
}
int set_find(int x){
	while(parents[x]!=-1){
		x=parents[x];
	}
	return x;
}
 ```
 
### Kruskal 알고리즘의 구현
* qsort : stdlib.h에서 제공하는 퀵 정렬 함수
	* void qsort (void *base, size_t nel, size_t width, int (*compare)(const void *, const void *);
	* (정렬하고자 하는 배열, 배열의 원소 수, 배열에서 원소 하나의 크기, 비교함수 포인터)
	* 비교 함수 (ex) 
	```
	int compare (const void* first, const void* second)
	{
	//오름차순 정렬 함수 
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
	}
	``` 
* 간선 배열을 이용해 그래프 구현
* kruskal 구현)
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50
#define INF 1000
/*
[1] init(n) : 초기화 연산, n개의 원소가 자기 자신만을 원소로 갖는 각각의 집합이 되도록 초기화한다.
[2] union(x,y) : 두 원소 x와 y가 속해있는 2개의 집합의 합집합을 만든다
[3] find(x) : 원소 x가 속해있는 집합을 반환한다.
*/

int parents[MAX_VERTICES];
typedef struct Edge{
	int start,end,weight;
}Edge;

typedef struct GraphType{
	Edge edges[MAX_VERTICES*2];//간선 배열 
	int n;
}GraphType;

void set_init(int n){
	int i;
	for(i=0;i<n;i++){
		parents[i]=-1;
	}
}
void set_union(int x,int y){
	int a,b;
	a=set_find(x);
	b=set_find(y);
	if(a!=b)
	parents[a]=b;
}
int set_find(int x){
	while(parents[x]!=-1){
		x=parents[x];
	}
	return x;
}

void graph_init(GraphType*g){
	g->n=0;
	int i;
	for (i = 0; i < 2 * MAX_VERTICES; i++) {//쓰레기값 초기화, g->n이 있기때문에 필요성 못느끼겠음
            g->edges[i].start = 0;
            g->edges[i].end = 0;
            g->edges[i].weight = INF;
    }

}
void insert_edge(GraphType*g,int s,int e,int w){
	if((g->n)+1>2*MAX_VERTICES)
	return ;
    g->edges[g->n].start = s;
    g->edges[g->n].end = e;
    g->edges[g->n].weight = w;
    g->n++;

}

int compare(const void*a, const void*b) {
        Edge*x = (Edge*)a;
        Edge*y= (Edge*)b;
        return (x->weight - y->weight);
}
   
void kruskal(GraphType*g){
	printf("크루스칼 최소 시잔 트리 알고리즘\n");
	set_init(g->n);
	qsort(g->edges, g->n, sizeof(Edge), compare);//quick sort 이용 
	
	int i;
	Edge e;
	for(i=0;i<g->n;i++){ //정점의 수 모르기 때문에 끝까지 돌아야 함 
		e=g->edges[i];
		int x=set_find(e.start);
		int y=set_find(e.end);// 그냥 start,end 해도되지만 연산 수 줄이기 위해 
		if(x!=y){
			printf("간선 (%d,%d) %d 선택\n",e.start,e.end,e.weight);
			set_union(x,y);
		}
	}
			
	
}

int main(){
    GraphType*g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
 
    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);
 
    kruskal(g);
    free(g);

	return 0;
}

``` 
* 성능 : union-find 를 이용하면 kruskal의 알고리즘의 시간 복잡도는 간선들을 정렬하는 시간에 따라 결정됨 가장 효율적인 정렬 이요하면 시간 복잡도 O(|e|log|e|)이다 (합치는데 걸리는 시간은 O(1))

## 11.3 Prim의 MST 알고리즘 
### Prim 알고리즘의 개요
* 시작 정점에서부터출발하여 신장 트리 집합을 단계적으로 확장해나가는 방법
* kruskal은 간선을 기반으로 하는 알고리즘이지만 prim은 정점을 기반으로 하는 알고리즘
* kruskal은 이전 단계에서 만들어진 신장 트리와 상관없이 무조건 최저 간선을 선택하는 방법이지만 Prim은 이전 단계에서 만들어진 신장 트리를 확장하는 방식(둘다 greedy) 
* 알고리즘 동작 
	* 시작 단계에서는 시작정점만이 MST집합에 포함됨
	* 단계가 진행될 때마다 앞 단계에서 만들어진 MST집합에 인접한 정점들 중 최저 간선으로 연결된 정점을 선택하여 트리를 확장
	* 이 과정을 트리가 n-1개의 간선 가질 때까지 반복
 ### Prim 알고리즘의 구현
 * 현재까지 알려진, 신장 트리 정점 집합에서 각 정점까지의 거리 나타내는 distance배열 사용하며 처음에는 시작 노드만 0이고 나머진 무한대의 값 갖는다
 * 트리 집합에 새로운 정점 추가될 때마다 인접한 정점의 가중치 값에 다라 distance배열 값 갱신
 * priority queue를 이용하며 PQ에 모든 정점 소진될 때까지 이 과정 반복 
 * 정점 선택된 여부 나타내는 배열도 사용하여 사이클 방지
 * 가중치 인접 행렬 이용 
 	* 가중치 저장하는 인접 행렬로 기존의 인접행렬에서는 간선이 없으면 인접행렬의 값이 0이지만 가중치 인접 행렬에서는 간선의 가중치가 0일 수도 있기 때문에 간선이 없는 경우에는 무한대 값 저장함
	* 컴퓨터에서는 무한대 값 존재하지 않으므로 상당히 큰값을 무한대라 생각하고 저장한다
 * 의사 코드
 ```
 Prim(G,s): //그래프 G=(V,E) , s는 시작 정점
For each u∈V do
   Distance[u]<- ∞
Distance[s]<-0
우선 순위큐 Q에 모든 정점을 삽입(우선순위는 distance[])
For i<-0 to n-1 do
U<-delete_min(Q)
화면에 u를 출력
For each v ∈ (u의 인접정점)
   If(v∈Q and weight[u][v]<distance[v])
   Then distance[v]<-weight[u][v]

 ``` 
 * 구현 : 우선 전체 순회로 품 나중에 heap이용 
 ```
 #include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define INF 1000L


typedef struct GraphType{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES]={0,};
int distance[MAX_VERTICES];
void init_distance(GraphType*g){
	int i;
	for(i=0;i<g->n;i++){
		distance[i]=INF;
	}
}
   
int get_min_vertex(int n){
	int i;
	int min=INF;
	int v;
	for(i=0;i<n;i++){
		if(!selected[i]&&distance[i]<min){
				min=distance[i];
				v=i;
		}
	}
	return v;
}

void prim(GraphType*g,int s){
	int i,v;
	init_distance(g);
	distance[s]=0;//시작점 먼저 초기화**
	
	for(i=0;i<g->n;i++){
		s=get_min_vertex(g->n);
		if(distance[s]==INF)return;//최솟값이 무한대면 그냥 리턴 (더 이상 연결된 선 없음) 
		printf("정점 %d 방문\n",s);
		selected[s]=1;
		for(v=0;v<g->n;v++){
			if(g->weight[s][v]!=INF) 
			if(!selected[v]&&distance[v]>g->weight[s][v])
			distance[v]=g->weight[s][v];
		}
	}
	
}

int main(){
	GraphType g={7,
	{ {0,29,INF,INF,INF,10,INF},
	  {29,0,16,INF,INF,INF,15},
	  {INF,16,0,12,INF,INF,INF},
	  {INF,INF,12,0,22,INF,18},
	  {INF,INF,INF,22,0,27,25},
	  {10,INF,INF,INF,27,0,INF},
	  {INF,15,INF,18,25,INF,0} }
	};
	prim(&g,0);
	
	return 0;
}

 ``` 
 * 성능 
 	* 주 반복문이 정점의 수 n만큼 반복하고 내부 반복문이 n번 반복하므로 O(n^2)
	* 힙을 이용하면 O(|E|log n)까지 줄일 수 있음  
	* 희소 그래프 대상인 경우 kruskal알고리즘(O(eloge)), 밀집 그래프의 경우 prim이 유리함

## 11.4 최단 경로
### 최단 경로 문제(shortest path problem)
* 네트워크에서 정점 i와 정점 j를 연결하는 경로 중에서 간선들의 가중치 합이 최소가 되는 경로를 찾는 문제(간선의 가중치 : 비용, 거리, 시간 등이 될 수 있음)
* 2가지 방법 존재
	[1] Floyd 알고리즘 : 모든 정점에서 다른 모든 정점까지의 최단 경로를 구함
	[2] Dijkstra 알고리즘 : 하나의 시작 정점에서 다른 정점까지의 최단 경로 구함

## 11.5 Dijkstra 최단 경로 알고리즘
### Dijkstra 알고리즘의 개요 및 과정 
* 하나의 시작 정점으로부터 모든 다른 정점까지의 최단 경로 찾는 알고리즘
* 최단 경로는 경로의 길이 순으로 구해진다
* 과정 
	* 집합 S를 시작 정점으로의 최단 경로가 이미 발견된 정점들의 집합이라고 함
	* 집합 S에 있는 정점만을 거쳐서 다른 정점으로 가는 최단거리를 기록하는 배열인 distance 배열을 둔다
	* 시작 정점 v라고 하면 가중치 인접 행렬에서 v와 직접 연결된 간선의 가중치 값을 알아내고 distance 배열 값을 갱신한다
	* S안에 있지 않은 정점중 distance 값이 가장 작은 정점을 S에 추가한다
	* 새로운 정점이 추가되면 s에 있지 않은 다른 정점들의 distance값을 새로 추가된 정점을 거쳐서 가는 거리와 기존 거리 비교하여 더작은 거리로 distance값을 수정한다
	* (distance[w]=min(distance[w],distance[u]+weight[u][w]))

### Dijkstra 알고리즘의 구현
* pq사용하면 시간 단축 가능 
* 코드)
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES]={0,};
int distance[MAX_VERTICES];
void init_distance(GraphType*g){
	int i;
	for(i=0;i<g->n;i++){
		distance[i]=INF;
	}
}
   
int get_min_vertex(int n){
	int i;
	int min=INF;
	int v;
	for(i=0;i<n;i++){
		if(!selected[i]&&distance[i]<min){
				min=distance[i];
				v=i;
		}
	}
	return v;
}
void print_status(GraphType*g) {
	static int step = 1;
	int i;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (i = 0; i < g->n; i++) {
		if (distance[i] == INF)printf("*");
		else printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("found: ");
	for (i = 0; i < g->n; i++) 
		printf("%2d", selected[i]);

	printf("\n\n");
}

void shortest_path(GraphType*g,int s){
	init_distance(g);
	distance[s]=0;
	/*
	for (i = 0; i < g->n; i++) {
		distance[i] = g->weight[s][i];
		selected[i] = FALSE;
	}//시작점만 말고 전체 시작점에서 거리 초기화 먼저하고 반복수 하나 줄여도 됨 

	*/
	int v;
	int min;
	int i;
	for(i=0;i<g->n;i++){
	print_status(g);
	min=get_min_vertex(g->n);
	selected[min]=1;
	for(v=0;v<g->n;v++){
		if(!selected[v])
		if(distance[v]>distance[min]+g->weight[min][v]){//경로 갱신 (지금까지의 최소경로+ 추가된 점에서의 루트) 
			distance[v]=distance[min]+g->weight[min][v];
		}
	}
	}
	
} 
int main() {
	GraphType g={7,
	{{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}}	
	};
	
	shortest_path(&g, 0);
	return 0;

}



```
### Dijkstra 알고리즘의 분석
* 주 반복문은 n번 반복하고 내부 반복문은 2n번(최솟값 찾기+distance배열 값 갱신) 반복하므로 O(n^2)
* PQ 사용하면 O(|E|log|E|) ->O(|E|log|V|)정도로 개선 가능 (e+eloge->eloge) 
 	* O((V+E)logV)의 시간복잡도를 가지는 이유는 각 노드마다 미방문 노드 중 출발점으로부터 현재까지 계산된 최단 거리를 가지는 노드를 찾는데 O(VlogV)의 시간이 필요하고, 각 노드마다 이웃한 노드의 최단 거리를 갱신할 때 O(ElogV)의 시간이 필요하기 때문이다.

## 11.6 Flyod 최단 경로 알고리즘
### Floyd 알고리즘의 개요
* 모든 정점 사이의 최단 경로를 구하려면 구하려면 Dijkstra 알고리즘을 정점의 수만큼 반복 실행하는 방법 존재 하지만 더 효율적인 방법인 Floyd 최단 경로 알고리즘 사용한다 
* Floyd 알고리즘 : 그래프에 존재하는 모든 정점 사이의 최단 경로를 한번에 모두 찾아주는 알고리즘
* 2차원 배열 A를 이용해 3중 반복을 하는 루프로 구성됨

### 과정 및 증명
* 배열 A의 초기값은 가중치 행렬의 값으로 하고 수행
* A^k[i][j]를 0부터 k까지의 정점만을 이용한 정점 i에서 j까지의 최단 경로라고 하면 원하는 최종 결과 값은 A^(n-1)[i][j] 즉, 0부터 n-1까지의 모든 정점을 이용한 최단 경로이다.
* 가장 핵심적인 부분은 A^(-1)->A^0->…->A^(n-1) 순으로 최단거리를 구하는 것이다. (A^(-1)은 weight배열의 값과 같다)
* 의사 코드)
```
Floyd(G):
 For k<-0 to n-1
    For i<-0 to n-1
     For j<-0 to n-1
       A[i][j]=min(A[i][j],A[i][k]+A[k][j])

```
* 증명) A^(k-1)까지는 완벽한 최단거리가 구해져 있는 상태라면 A^k[i][j]는 2가지 case 존재한다
	1. 정점 k를 지나는 경우 : (i에서 k까지의 최단거리) A^(k-1) [i][k]+(k에서j까지의 최단거리) A^(k-1) [k][j]
	2. 정점 k를 지나지 않는 경우 : A^(k-1)[i][j]
	* [1],[2]중 적은 값이 최단거리가 된다.

### 구현
* 코드)
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define INF 1000L

/*
[1] init(n) : 초기화 연산, n개의 원소가 자기 자신만을 원소로 갖는 각각의 집합이 되도록 초기화한다.
[2] union(x,y) : 두 원소 x와 y가 속해있는 2개의 집합의 합집합을 만든다
[3] find(x) : 원소 x가 속해있는 집합을 반환한다.
*/
typedef struct GraphType{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];
void init_A(GraphType*g){
	int i,j;
	for(i=0;i<g->n;i++){
		for(j=0;j<g->n;j++){
			A[i][j]=g->weight[i][j];	
		}
	}
}
 

void printA(GraphType*g){
	int i,j;
	printf("==============================\n");
	for(i=0;i<g->n;i++){
		for(j=0;j<g->n;j++){
			if(A[i][j]==INF)printf("*");
			else printf("%3d",A[i][j]);
		}
		printf("\n");
	}
	printf("==============================\n");
}
void floyd(GraphType*g){
	int i,j,k;
	init_A(g);
	printA(g);
	for(i=0;i<g->n;i++){
		for(j=0;j<g->n;j++){
			for(k=0;k<g->n;k++){
				if(A[i][j]>A[i][k]+A[k][j]){
					A[i][j]=A[i][k]+A[k][j];
				}
			}
		}
		printA(g);
	}
	
}

int main(){
	GraphType g={7,
	{{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}}
	};
	floyd(&g);
	return 0;
	
}



``` 
### 성능
* 3중 반복문을 사용하기 때문에 O(n^3)의 시간 복잡도
* Dijkstra를 정점의 수만큼 반복하는 것과 시간 복잡도는 같지만 Floyd는 매우 간결한 반복구문을 사용하므로 Dijkstr보다 실제론 빠르게 찾을 수 있음

## 11.7 위상 정렬(topological sort)
### 위상정렬의 개요
* 방향 그래프에서 간선 <u,v>가 있다면 정점 u는 정점 v를 선행한다고 한다
* 위상 정렬은 방향 그래프에서 존재하는 각 정점들의 선행 순서를 위배하지 않으면서 모든 정점을 나열하는 것
* DAG(Direct Acyclic Graph) (비순환 방향성 그래프)에 만 적용 가능 
* 사용 예) 큰 프로젝트를 단계적으로 나누어 진행, 선수과목 구현
* 구현 방법 
	* 진입 차수(외부에서 정점으로 오는 간선의 개수)가 0인 정점 먼저 선택
	* 선택된 정점과 연결된 간선을 모두 삭제한다
	* 진입 차수 0인 정점의 선택과 삭제를 반복해서 모든 정점이 선택, 삭제되면 알고리즘 종료
	* 그래프에 남아있는 진입 차수 0인 정점이 없으면 위상 정렬 불가능하며 알고리즘 중단됨
* 진입 차수 0인 정점이 여러 개 존재할 경우 어느 정점을 선택하여도 무방하다 -> 하나의 그래프에서는 복수의 위상 정렬 순서 존재
* 의사코드)
```
For i<-0 to n-1 do
   If( 모든 정점이 선행 정점을 가지면) 
   Then 사이클이 존재하고 위상 정렬 불가;
   선행 정점을 가지지 않는 정점 v 선택;
   V를 출력; 
   V와 v에서 나온 모든 간선들을 그래프에서 삭제;

```
* 참고) DFS를 이용한 방법도 존재 : DFS는 위상정렬의 역순으로 출력하는 탐색 방법이므로 stack과 dfs를 이용해도 구현가능하다
* 구현
	1. 일반 구현
	```
	#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_STACK_SIZE 100
typedef struct GraphNode {
	int vertex;
	struct GraphNode*link;
}GraphNode;
typedef struct GraphType {
	int n;
	GraphNode*adj_list[MAX_VERTICES];
}GraphType;
typedef int element;
typedef struct StackType {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;
void graph_init(GraphType*g) {
	int i;
	g->n = 0;
	for (i = 0; i < MAX_VERTICES; i++) {
		g->adj_list[i] = NULL;
	}

}
void insert_vertex(GraphType*g, int v) {
	if (g->n + 1 > MAX_VERTICES) {
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}
	g->n++;
}
void insert_edge(GraphType*g, int s, int e) {
	if ((g->n) <= s || (g->n) <= e) {
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}
	GraphNode*node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = e;
	node->link = g->adj_list[s];
	g->adj_list[s] = node;
}
void init(StackType*s) {
	s->top = -1;
}
int is_empty(StackType*s) {
	return (s->top < 0);
}
int is_full(StackType*s) {
	return(s->top == MAX_STACK_SIZE - 1);
}
void push(StackType*s, element e) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = e;
}
element pop(StackType*s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백  에러\n");
		exit(1);
	}
	element e = s->stack[s->top--];
	return e;
}


int topo_sort(GraphType*g) {//실패인 경우도 있으므로 리턴 값을 둔다
	StackType s;
	init(&s);
	//진입 차수 판단
	int*inDegree = (int*)malloc(sizeof(int)*g->n);
	int i;
	GraphNode*node;

	for (i = 0; i < g->n; i++)
		inDegree[i] = 0;
	for (i = 0; i < g->n; i++) {
		node = g->adj_list[i];
		while (node != NULL) {
			inDegree[node->vertex]++;
			node = node->link;
		}
	}
	element e;
	for (i = 0; i < g->n; i++) {
		if (inDegree[i] == 0)
			push(&s, i);
	}
	while (!is_empty(&s)) {
		e = pop(&s);
		printf("정점 %d ->", e);
		node = g->adj_list[e];
		while (node != NULL) {
			int u = node->vertex;
			inDegree[u]--;
			if (inDegree[u] == 0)//간선 끊었을때 진입차수 0되면 삽입
				push(&s, u);
			node = node->link;
		}

	}
	free(inDegree);
	printf("\n");
	return i == g->n;//0이면 성공, 1이면 실패


}
int main() {
	GraphType g;

	graph_init(&g);
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);

	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);

	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);

	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);

	insert_edge(&g, 3, 5);

	insert_edge(&g, 4, 5);

	topo_sort(&g);
	return 0;
}

	```
	2. DFS를 이용한 구현
	```
	void dfs_mat(GraphType*g,int v){
	GraphNode*temp;
	visited[v]=TRUE;
	for(temp=g->adj_list[v];temp!=NULL;temp=temp->link){
		if(!visited[temp->vertex]){
			dfs_mat(g,temp->vertex);//정점 temp에서 DFS 새로 시작
		}
	}
	push(&stack,v);
}

int main(){
......
    for(i=0;i<g.n;i++){
		if(!visited[i])dfs_mat(&g,i);
	}
	while(!is_empty(&stack)){
		printf("정점 %d 방문->",pop(&stack));
	}
}

	```
# 12 정렬 
## 12.1 정렬이란? 
### 정렬의 개념과 중요성 
* 정렬 : 물건 또는 어떤 형태의 것을 크기순으로 오름차순(ASCENDING)이나 내림차순(descending)으로 나열하는 것을 의미
* 컴퓨터 공학에서 가장 기본적이고 중요한 알고리즘 중의 하나로 일상생활에서 많이 사용 
	* ex) 책들의 제목 순이나 저자 순 정렬, 사람의 키, 나이 순 정렬 등 정렬
* 자료 탐색을 하는데 정렬은 필수적인데 정렬되지 않은 자료가 주어지면 컴퓨터의 탐색 효율도 크게 떨어짐 

### 정렬 관련 용어
* 레코드(record) : 정렬 시켜야 할 대상, 필드의 집합
* 필드(field) : 항목으로 어떠한 의미를 지니는 정보의 최소단위
* 키(key) : 레코드와 레코드를 식별해주는 역할을 하는 필드
* ex) 학생 레코드라면 필드는 학번,이름, 주소 / 키는 학번이 될 수있음
* 정렬이란 결국 레코드를 키 값의 순서로 재배열 하는 것

### 정렬의 효율성
* 많은 정렬 알고리즘이 개발됐지만 모든 경우에서 최상의 성능을 보여주는 최적 알고리즘은 존재하지 않음
* 따라서 현재의 프로그램 수행환경에서 가장 효율적인 알고리즘을 선택해야 한다
* 정렬 알고리즘의 효율성의 평가
	* 정렬을 위해 필요한 비교연산의 횟수와 이동 연산의 횟수에 따라 평가
	* 정확하게 구하기 힘드므로 빅오표기법을 통해 근사적으로 표현 
* 일반적으로 이동횟수와 비교횟수는 서로 비례하지 않으며 이들횟수는 자료의 초기화 분포 여부에 의존적이다 

### 정렬 알고리즘의 분류
1. 단순 + 효율성에 따른 분류
	* 단순하지만 비효율적인 알고리즘 - 삽입 정렬, 선택 정렬, 버블 정렬 등
	* 복잡하지만 효율적인 방법 - 퀵 정렬, 히프 정렬, 합병 정렬, 기수 정렬 등
	* 자료의 개수가 적다면 [1] 방법을 사용하는 것도 괜찮지만 자료의 개수가 일정 개수를 넘어가면 [2] 방법 사용 

2. 내부 정렬 <-> 외부 정렬
	* 내부 정렬(internal sorting) : 정렬하기 전 모든 데이터가 메인 메모리에 올라와 있는 정렬
	* 외부 정렬(external sorting) : 외부 기억 장치에 대부분의 데이터가 있고 일부만 메모리에 올려 놓은 상태에서 정렬을 하는 방법

3. 안정성 측면
	* 정렬의 안정성 : 입력 데이터에서 동일한 키 값을 갖는 레코드가 여러 개 존재할 경우 이들 레코드들의 상대적인 위치가 정렬 후에도 바뀌지 않는 것, 정렬 후에 위치가 바뀌면 안정하지 않은 것 
 		* ex) 30_1 30_2 10 20 -> 정렬 후 : 10 20 30_2 30_1 -> 상대적인 위치 바뀜, 안정하지 않음
 	* 안정성 충족 정렬 : 삽입 정렬, 버블 정렬, 합병 정렬

## 12.2 선택 정렬(selection sort)
### 선택 정렬 개요 
* 가장 이해하기 쉬운 방법
* 2개의 리스트가 있을 때 왼쪽 리스트에는 정려이 완료된 리스트고 오른쪽에는 정렬안된 리스트이다
* 초기 상태에는 왼쪽 리스트가 비어있고 오른쪽 리스트에서 최소 또는 최대 값을 찾아 왼쪽 리스트로 이동시키는 과정울 오른쪽 리스트가 공백상태가 될 때 까지 반복하는 정렬
* 위과정은 입력 배열외에 추가적인 공간(배열)을 사용함 -> 제자리 정렬(in-place-sorting)을 통해 해결한다
* 제자리 정렬 : 입력 배열외에는 다른 추가 메모리를 요구하지 않는 정렬 방법
* 제자리 정렬을 이용한 방법 : 입력 배열에서 최솟값을 발견한 후 배열의 첫번째 요소와 이 최소값을 교환하고 다음에는 첫번째 요소를 제외한 두번째 요소와 최소값을 교환한다. 이 절차를 (원소개수-1)만큼 되풀이한다
	* (원소개수-1) 만큼 하는 이유 : 0~n-2까지 정렬이 됐다고 하면 마지막 list[n-1]은 자동으로 최대 값(또는 최솟값)이기 때문에 정렬할 필요가 없다

### 선택 정렬의 구현
* SWAP 매크로
	1. 비트 연산 이용(정수 타입에 가능)
		* define SWAP(a,b) {a^=b,b^=a,a^=b;} 
		* 동일한 값을 두번 XOR연산 하면 본래 가지고 있던 값 가짐
	2. 대입 연산 이용
		* #define SWAP(x,y,t) ( (t)=(x),(x)=(y),(y)=(t)) or #define SWAP(x,y,t) {t=x,x=y,y=t;)
* 참고) 전처리기와 매크로
	* 전처리기(preprocesser) : 컴파일 직전에 처리되는 별도의 프로그램, 컴파일 전 단순히 텍스트를 조작하는 치환 역할을 하기도 하고, 디버깅에도 도움 주며 헤더파일의 중복 포함도 방지해줌
		* 종류 
			* #include : 다른 소스 파일(주로 헤더 파일) 전체를 #include 위치에 치환한다
			* #define : 매크로 만들 수 있ㅈ는 지시자
				* ex)  #define MAX 10 -> 매크로 변수 , #define 매크로 함수명(매크로함수내용) -> 매크로 함수
* 참고) C에서 함수인자로 배열 전달
	* C에서는 배열의 값을 직접 인자로 전달 못하므로 인자로는 배열의 주소 값이 전달된다 
		* ex) int[30] 전달하면 ->120바이트가아닌 주소 값 4바이트만 전달됨
		* 메모리 복사로 인한 수행속도 저하및 데이터 중복 해결하기 위해 이렇게 실행
	* 따라서, c에서 인자로는 대괄호 내 숫자를 적지 않는 것이 일반적인데(int arr[]) 선언 시 배열의 대괄호에 어떤 값을 적든 무시된다.
	* 일반적으로는 배열대신 포인터로 선언해서 쓰는게 좋음 

* 코드
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

void selection_sort(int arr[],int n){
	int i,j;
	int minIdx,temp;
	for(i=0;i<n-1;i++){
		minIdx=i;
		for(j=i+1;j<n;j++){
			if(arr[minIdx]>arr[j])
				minIdx=j;
		}
		if(minIdx!=i) 
		SWAP(arr[i],arr[minIdx],temp);
	}
}
int main(){
	
	int i;
	n=MAX_SIZE;
	srand((unsigned int)time(NULL));
	for(i=0;i<n;i++){
		list[i]=rand()%100;
	}
	selection_sort(list,n);
	for(i=0;i<n;i++){
		printf("%d ",list[i]);
	}
	printf("\n");
	return 0;
} 
```

### 선택 정렬의 분석
* 성능 분석을 위한 비교횟수와 이동횟수
	* 비교 횟수 : 두 개의 for루프에서 실행 횟수를 계산해보면 외부루프 n-1번, 내부 루프는 (n-1)-i번 반복되는데 키 값들의 비교는 내부 루프 안에서 이루어지므로 전체 비교횟수는 (n-1)+(n-2)+…+1=n(n-1)/2 = O(n^2)
	* 이동 횟수 : 외부 루프의 실행 횟수와 같고 한번 교환하기 위하여 3번의 이동이 필요하므로 전체 이동 횟수는 3(n-1)이다.
	* 이동횟수가 상당히 큰 편이며, 자료가 정렬된 경우에는 불필요하게 자기 자신과의 이동을 하게되는데 이를 개선하기 위해 if문을 추가해주며 자기자신이 최솟값이면 이동하지 않게 한다.
		* if(least!=i) swap(list[i],list[least],temp);
* 따라서 O(n^2)의 복잡도 가짐 
* 선택 정렬은 안정성을 만족하지 않는 정렬이다. (같은 값의 레코드가 있는 경우 상대적인 위치 변경될 수 있다.)

## 12.3 삽입 정렬(insertion sort)
### 삽입 정렬의 원리
* 손 안의 카드를 정렬하는 방법과 유사
* 새로운 카드가 들어오면 기존의 정렬된 카드 사이의 올바른 자리를 찾아 삽입함
* 정렬되어 있는 리스트에 새로운 레코드를 적절한 위치에 삽입하는 과정 반복 
* 선택 정렬과 마찬가지로 입력 배열을 정렬된 부분과 정렬되지 않은 부분으로 나누어 사용한다.
* 정렬되어 있지 않은 부분의 첫번째 요소가 정렬된 부분의 어떤 위치에 삽입되어야 하는가를 판단한 후 해당 위치에 삽입하면, 정렬된 배열의 크기는 하나 늘고, 정렬되어 있지 않은 배열의 크기는 하나 줄어든다. 이러한 연산을 정렬되지 않은 부분이 빌 때까지 반복한다.
* 의사코드
```
Insertion_sort(A,n) : 
1. For i<-1 to n-1 do    : 인덱스는 1부터 시작, 인덱스 0은 이미 정렬된 것으로 볼 수 있음
2.   Key<-A[i];  : 삽입될 숫자 key변수로 복사
3.   J<- i-1;  : 현재 정렬된 배열은 i-1까지 이므로 i-1번째부터 역순으로 조사함
4.   While j≥0 and A[j]>key do
5.         A[j+1]<-A[j];
6.         J<-j-1;
7.     A[j+1]<-key

``` 
### 삽입 정렬의 구현
* 매 단계마다 shift연산 필요 할 수 있으므로 이는 새롭게 정렬된 배열에 추가하려던 값을 임시변수에 저장하여 원래 그 값이 들어있는 배열의 부분은 값이 바껴도 상관없으므로 shift연산 가능해진다 
* 코드
```
void insertion_sort(int list[],int n){
	int i,j;
	int key;//삽입하려는 값 저장하는 임시변수 
	for(i=1;i<n;i++){
		key=list[i];
		for(j=i-1;j=>0&&list[j]>key;j--){
				list[j+1]=list[j];//새로 확장되는 배열칸이 있고 key값 따로 저장했기때문에 shift연산 가능 
		}
		list[j+1]=key;
	}
} 
``` 
### 삽입 정렬의 성능
* 삽입 정렬의 복잡도는 입력 자료의 구성에 따라 달라짐
* 입력 자료가 이미 정렬되어 있는 경우 가장 빠름
	* 정렬된 경우 : 외부루프는 n-1번, 각 단계에서 1번의 비교와 2번의 이동(대입) 이루어지므로 총 비교횟수는 n-1번, 총 이동횟수는 2(n-1)번 이므로 ->  O(n) 이다
	* 최악의 경우(입력 자료가 역순인 경우) :  외부루프 안의 각 반복마다 i번의 비교 수행되므로 
* 비교횟수는 ∑_(i=0)^(n-1)▒i=1+2+…+n-1 = n(n-1)/2= O(n^2) , 총 이동 횟수는 외부 루프의 각 단계마다 i+2번 이동이 이루어 지므로 총 n(n-1)/2+2(n-1)= (n^2+3n+4)/2 = O(n^2)
* 삽입 정렬은 비교적 많은 레코드들의 이동을 포함하므로 레코드 양이 많고 레코드 크기가 클 경우 적합하지 않다
* 안정한 정렬 방법으로 레코드의 수가 적을 경우 알고리즘 자체가 매우 간단하므로 다른 복잡한 정렬보다 유리할 수 있고 대부분의 레코드가 이미 정렬되어 있는 경우에 매우 효율적이다.

## 12.4 버블 정렬(Bubble sort)
### 버블 정렬의 원리
* 인접한 2개의 레코드를 비교하여 크기가 순서대로 되어 있지 않으면 서로 교환하는 비교-교환 과정을 왼쪽 끝에서 시작하여 오른쪽 끝까지 진행하고 이러한 비교-교환 과정(스캔)이 한번 완료되면 가장 큰 레코드가 리스트의 오른쪽 끝으로 이동함
* 이러한 스캔 과정에서 오른쪽 리스트는 정렬된 상태이며 정렬이 안 된 왼쪽 리스트에서 과정을 반복하여 적용하면 전체리스트는 정렬된 상태가 됨
* 이러한 이동 과정이 마치 물속에 거품이 보글보글 떠오르는 것과 유사하다고 하여 버블정렬이라 함
* 의사코드)
```
BubbleSort(A,n):
For i<-n-1 to 1 do
    For j<-0 to i-1 do
        J와 j+1번째의 요소가 크기순이 아니면 교환
        J++;
i--;

``` 

### 버블정렬의 구현
* 코드
```
void bubble_sort(int list[],int n){
	int i,j;
	int temp;
	for(i=n-1;i>0;i--){
		for(j=0;j<i;j++){
			if(list[j]>list[j+1])
				SWAP(list[j],list[j+1],temp);
		}
	}
}
``` 

### 버블정렬의 복잡도
* 버블정렬의 비교횟수는 모든 경우(최선, 평균, 최악) 일정하다
: ∑_(i=1)^(n-1)▒i = n(n-1)/2 = O(n^2)
* 이동횟수는 최악의 경우는 역순으로 자료가 정렬된 경우이며 그 횟수는 비교연산의 횟수에 3을 곱한 값이다(swap 이동이 3번의 이동 포함)
* 최선의 경우는 자료가 이미 정렬된 경우며 이동 한번도 발생하지 않는다.
* 평균적인 경우에는 자료 이동이 0번에서 i번까지 같은 확률로 일어난다. 
* 따라서 O(n^2) 의 알고리즘임
* 가장 큰 문제점은 순서에 맞지 않는 요소를 인접한 요소와 교환한다는 것-> 이미 정렬 위치에 있어도 교환되는 일 발생, 비효율적
* 일반적으로 자료의 교환(swap)작업이 자료의 이동(move) 작업보다 더 복잡하기 때문에 단순하지만 잘 사용하지 않는다.


## 12.5 쉘 정렬(shell sort)
### 쉘 정렬의 개요와 동작 
* Donald L. Shell이 제안한 방법으로 삽입 정렬이 어느 정도 정렬된 배열에 대해서는 대단히 빠른 것에 착안한 방법
* 삽입 정렬의 문제점 : 요소들이 삽입될 때, 이웃한 위치로만 이동한다는 것 -> 삽입되어야 할 위치가 현재위치보다 상당히 떨어진 곳이면 많은 이동을 해야 함 
* 삽입 정렬의 O(n^2)보다 빠르다
* 전체 리스트를 한번에 정렬하지 않고, 먼저 정렬해야 할 리스트를 일정한 기준에 따라 분류하여 연속적이지 않은 여러 개의 부분 리스트를 만들고 각 부분리스트를 삽입 정렬을 이용하여 정렬
* 모든 부분 리스트가 정렬되면 다시 전체 리스트를 더 적은 개수의 부분 리스트로 만든 후에 알고리즘을 되풀이 하며 이 과정을 부분리스트가 1개가 될 때 까지 반복 
* 부분 리스트를 구성할 때는 주어진 리스트의 각 k번째 요소를 추출하여 만들며 이 k를 간격(gap)이라고 한다. 셀 정렬은 각 스텝마다 간격 k를 줄여간다. 마지막 스텝에서는 간격이 1이 된다.
* 실제로는 부분리스트들이 따로 만들어지는게 아니고 삽입 정렬을 일정한 간격으로 수행하는 것이기 대문에 추가적인 공간은 필요 없다
* 간격은 처음에 n/2정도로 하고 각 패수마다 간격을 절반으로 줄이는 방식을 많이 사용

### 쉘 정렬의 구현
* 부분 리스트 삽입 정렬하는 함수 만들어 이용하기
* 코드
```
void inc_insertion_sort(int list[],int start,int gap,int end){//부분 삽입 정렬 함수 
	int i,j;//삽입정렬
	int key;
	for(i=start+gap;i<=end;i+=gap){
		key=list[i];
		for(j=i-gap;j>=start&&list[j]>key;j-=gap){
				list[j+gap]=list[j];
			}
		}
		list[j+gap]=key;//j+gap임 
	}

} 
void shell_sort(int list[],int n){
	int gap;
	int i;
	//시작점,gap 감소 
	for(gap=n/2;gap>0;gap/=2){
		if(gap%2==0)gap++;//짝수일때 홀수일때 구분 안해도 되나 간격이 홀수일 때 성능이 더 좋은것으로 판명되어 간격 홀수로 만들어준다.
		for(i=0;i<gap;i++){
			inc_insertion_sort(list,i,gap,n-1);
		}
	}
	
	
}
``` 
### 쉘 정렬의 분석
* 연속적이지 않은 부분 리스트에서 자료의 교환이 일어나면 더 큰 거리를 이동하므로 한번에 한 칸씩 만 이동하는 삽입 정렬보다는 최종 위치에 더 가까이 있을 가능성이 높아진다.
* 부분 리스트는 어느 정도 정렬이 된 상태이기 때문에 부분 리스트의 개수가 1이되게 되면 셀 정렬은 기본적으로 삽입 정렬을 수행하는 것이지만 빠르게 수행된다.(삽입 정렬이 거의 정렬된 리스트에 대해서는 빠르게 수행되기 때문)
* 최악의 경우는 O(n^2)이지만 평균적인 경우에는 O(n^1.5)이다

* 여기까지는 비효율적이지만 간단하여 데이터 양이 적을 때 사용 가능한 방법 
## 12.6 합병정렬(Merge sort)
### 합병 정렬이란?
* 하나의 리스트를 두 개의 균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음 두 개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트를 얻고자 하는 정렬
* Divide and conquer(분할 정복) 기법에 바탕을 두고 있다
	* Divide and conquer : 문제를 작은 문제들로 분리하고 각각을 해결한 다음 결과를 모아 원래의 문제를 해결하는 전략
	* 분리한 문제가 충분히 작지 않다면(분리된 문제도 해결하기 어려움) 분할 정복 방법을 연속하여 다시 적용
	* 대개 순환 호출을 이용하여 구현
* 합병정렬의 구성
	1. 분할(Divide) : 입력 배열을 같은 크기의 2개의 부분 배열로 분할
	2. 정복(Conquer) : 부분 배열을 정렬, 부분 배열의 크기가 충분히 작지 않으면 순환 호출을 이용하여 다시 분할 정복 기법 적용
	3. 결합(Combine) : 정렬된 부분 배열들을 하나의 배열에 통합한다
	* 부분 배열들을 정렬할 때도 합병 정렬 순화적으로 적용한다

### 합병 정렬의 구현
* 의사코드)
```
merge_sort(list,left,right):
1.  if left<right //나누어진 구간의 크기가 1이상이면
2.    mid=(left+right)/2;  //중간 위치를 계산
3.    merge_sort(list, left, mid); // 앞쪽 부분 배열을 정렬하기위해 merge_sort함수 순환 호출
4.    merge_sort(list, mid+1, right); // 뒤쪽 부분 배열을 정렬하기위해 merge_sort함수 순환 호출
5.    merge(list, left, mid, right);// 정렬된 2개의 부분 배열을 합병하여 하나의 정렬된 배열 만듬

```
 
* 합병 정렬에서 실제로 정렬이 이루어지는 시점은 2개의 리스트를 합병(merge)하는 단계임
* 합병(결합) 과정에는 추가적인 리스트를 필요로 하며 2개의 리스트의 요소들을 처음부터 하나씩 비교하여 두개의 리스트의 요소 중에서 더 작은 요소를 새로운 리스트로 옮긴다.
* 둘 중에서 하나가 끝날 때까지 이 과정을 반복하며 하나의 리스트가 먼저 끝나게 되면 나머지 리스트의 요소들을 전부 새로운 리스트로 복사한다.
* 코드)
```
int sorted[MAX_VERTICES];//정렬 완성품 저장하는 임시변수
void merge(int list[], int left,int mid, int right) {
	int i = left, j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (list[i] > list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}
	for (; i <= mid; i++) {
		sorted[k++] = list[i];
	}
	for (; j <= right; j++) {
		sorted[k++] = list[j]; 
	}
	for (i = left; i <= right; i++)
		list[i] = sorted[i]; //sorted를 list로 복사 
}
void merge_sort(int list[], int left,int right) {

	if (left<right) {//순환에서 항상 중요한 종료 조건! 
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid,right);
	}
}
```
 
### 합병 정렬의 성능 
* 레코드의 개수 n이 2의 거듭제곱이라고 가정하고 순환호출의 깊이 분석하면  n=2^k라고 하면 부분 배열의 크기는 2^k→2^(k-1)…→2^0이 되어 순환 호출의 깊이가 k가 되므로 k=logn이다.
* 부분 배열로 나눠지는 단계에선 비교, 이동 연산 수행되지 않고 merge(합병)하는 과정에서 비교연산과 이동 연산 수행됨
* 비교연산은 한번에 합병 단계에 (최대) n번 일어나고 총 k번 만큼 있으므로 비교 연산은 최대 nlogn번 필요
* 이동 연산은 합병 단계에서 임시 배열에 복사했다가 다시 가져와야 하므로 총 부분 배열에 들어 있는 요소의 개수가 n이면 2n번 발생
* 따라서 logn개의 합병단계 요구되므로 2nlogn개의 이동 연산 필요하다.
* 결론적으로 O(nlog n)
* 장점은 안정적인 정렬이며 데이터의 분포에 영향을 덜 받음 -> 최악, 평균, 최선의 경우가 다 같이 O(nlogn)의 복잡도 갖는다.
* 단점은 임시 배열을 필요로 하며(공간적 낭비) 레코드들의 크기가 큰 경우 이동 횟수가 많으므로 큰 시간적 낭비 초래 
* 하지만 레코드들을 연결 리스트로 구성하여 정렬하면, 링크 인덱스만 변경되므로 데이터의 이동은 무시할 수 있을 정도로 작아져 크기가 큰 경우에도 퀵 정렬을 포함한 다른 어떤 정렬 방법보다 효율적일 수도 있다.

## 12.7 퀵정렬(quick sort)
### 퀵 정렬의 개념
* 평균적으로 매우 빠른 수행속도를 자랑하는 방법
* 합병 정렬과 비슷하게 전체 리스트를 2개의 부분 리스트로 분할하고, 각각의 부분 리스트를 다시 퀵 정렬하는 분할-정복법(Divide and conquer)사용
* 합병 정렬과는 달리 리스트를 비 균등하게 분할한다
* 먼저 리스트 안에 있는 한 요소를 피벗(pivot)으로 선택한 후 피벗보다 작은 요소들은 왼쪽으로 옮겨지고 피벗보다 큰 요소들은 모두 피벗의 오른쪽으로 옮겨짐
* 이 상태에서 피벗을 제외한 왼쪽 리스트를 다시 정렬하게 되면 전체 리스트가 정렬된다 
```
int partition(int list[], int left, int right) {
	int pivot = list[left];
	int i = left + 1, j = right;
	int temp;
	while(i < j) {
		while (list[i] < pivot)i++;
		while (list[j] > pivot)j--;//조건 안맞는 인덱스 찾을때까지 반복
		if (i < j) swap(list[i], list[j], temp);// 찾았을때 i<j이면 스왑
	swap(list[left], list[j], temp);
	return j;
}
void q_sort(int list[],int left, int right) {
	
	if (left < right) {
		int p = partition(list, left, right);
		q_sort(list,left,p-1);
		q_sort(list, p+1, right);
		//pivot 부분 빼고 정렬 이므로 p-1, p+1
	}
}
```
## 12.8 히프 정렬 
## 12.9 기수 정렬 (radix sort)
### 기수 정렬의 원리
* 비교가 불가능한 레코드들을 정렬하기 위해 만든 비교하지 않고도 정렬하는 방법
* 어떤 비교 연산도 실행하지 않고 데이터를 정렬할 수 있다.
* 정렬에 기초한 방법들은 O(nlogn)이라는 이론적인 하한선을 깰 수 없지만 기수 정렬은 깰 수 있는 유일한 방법으로 O(kn)의 복잡도를 갖는데 k<4이하이다.
* 추가적인 메모리를 요구하지만 이를 감안해도 기수 정렬이 다른 정렬 기법보다 빠르기 때문에 데이터 정렬 시 상당히 인기 있는 정렬 기법 중 하나이다.
* 단점은 정렬할 수 있는 레코드의 타입이 한정된다는 점이다. 기수 정렬을 사용하려면 레코드의 키들이 동일한 길이를 가지는 숫자나 문자열로 구성되어야 한다.
* 기수(radix)는 숫자의 자리수를 의미하며 기수 정렬은 자리수의 값에 따라 정렬
* 다단계 정렬이며 단계의 수는 데이터의 자리수의 개수와 일치한다
* 버킷(bucket) 개념을 사용하여 비교 연산을 하지 않고 각 자리수의 값에 따라 버킷에 넣고 빼는 동작만 반복한다.
* 십진수의 경우 십진수에서는 각 자리수가 0에서 9까지의 값만 가지는 것을 이용해 10개의 버킷을 만들어 각 자리수의 값에따라 상자에 넣고 순차적으로 다시 뺀다. 

### 기수 정렬 알고리즘의 구현
* LSD(least significant digit)는 가장 낮은 자리수, MSD(most significant digit)는 가장 높은 자리수
* 의사코드) 기수 정렬 알고리즘
```
RadixSort(list, n):
for d<-LSD의 위치 to MSD의 위치 do
{
	d번째 자리수에 따라 0번부터 9번 버킷에 집어놓는다
	버킷에서 숫자들을 순차적으로 읽어서 하나의 리스트로 합친다
	d++;
}

``` 
* 버킷에 먼저들어간 숫자는 먼저 나와야하므로 큐로 이용해 버킷 구현한다.
* 버킷의 개수는 키의 표현 방법과 밀첩한 관련이 있음
	* ex) 알파벳이면 26개, 십진수면 10개, 이진수면 2개...등
* 코드)
```
void radix_sort(int list[], int n) {
	// 자릿수  
	QueueType queues[BUCKETS];
	int d,i,factor,k;
	factor=1;
	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);
	
	for(d=0;d<2;d++){//자릿수 미리암 
		for(i=0;i<n;i++){
			enqueue(&queues[(list[i]/factor)%10],list[i]);	
		}
		k=0;
		for(i=0;i<BUCKETS;i++){
			while(!is_empty(&queues[i])) 
				list[k++]=dequeue(&queues[i]);
		}
		factor*=10;
	}
	
}
``` 
### 기수 정렬의 분석
* 만약 입력 리스트가 n개의 정수를 가지고 있다고 하면 내부루프는 n번 반복될 것이며 d개의 자리수를 가지고 있다면 외부루프는 d번 반복된다. 따라서 O(d*n)의 복잡도 갖는다
* 시간복잡도가 d에 비례하기 때문에 기수 정렬의 수행 시간은 정수의 크기와 관련이 있다.
* 일반적으로 32비트 컴퓨터의 경우 대개 10개 정도의 자리수만 갖게 되므로 일반적으로 n보단 작은 수가 되므로 O(n)이라고 해도 무리가 없다
* 기수정렬은 매우 빠르지만 키값이 숫자로 표현되어야 만이 적용이 가능하다 
	* 한글, 한자, 실수 등으로 이루어진 키값을 적용하려면 많은 버킷 필요하므로 기수 정렬의 적용이 불가능하다.

## 12.10 정렬 알고리즘의 비교 
### 성능 비교 표
* 코드)
```
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define BUCKETS 10
#define DIGITS 4//최고 자릿수 
#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))


int list[MAX_SIZE];
int n;

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;
 
void error(char*message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
 
void init_queue(QueueType*q) {
	q->front = 0;
	q->rear = 0;
}
 
int is_empty(QueueType*q) {
	return q->front == q->rear;
}
 
int is_full(QueueType*q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType*q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
 
element dequeue(QueueType*q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void selection_sort(int list[],int n){
	int i,j;
	int minIdx,temp;
	for(i=0;i<n-1;i++){
		minIdx=i;
		for(j=i+1;j<n;j++){
			if(list[j]<list[minIdx]){
				minIdx=j;
			}
		}
		if(minIdx!=i)//swap횟수 줄일 수 있는 if문
		swap(list[i],list[minIdx],temp);
	}
}
void insertion_sort(int list[],int n){
	int i,j;
	int key;
	for(i=1;i<n;i++){
		key=list[i];
		for(j=i-1;j>=0&&list[j]>key;j--){
			list[j+1]=list[j];
		}		
		list[j+1]=key;
	}
}
void bubble_sort(int list[],int n){
	int i,j;
	int temp;
	for(i=n-1;i>0;i--){
		for(j=0;j<i;j++){
			if(list[j+1]<list[j])
				swap(list[j+1],list[j],temp);
		}
		
	}
}

void inc_insertion_sort(int list[],int start,int gap,int end){//부분 삽입 정렬 함수 
	int i,j;//삽입정렬
	int key;
	for(i=start+gap;i<=end;i+=gap){
		key=list[i];
		for(j=i-gap;j>=start&&list[j]>key;j-=gap){
				list[j+gap]=list[j];
			}
		}
		list[j+gap]=key;//j+gap임 
	}

} 
void shell_sort(int list[],int n){
	int gap;
	int i;
	//시작점,gap 감소 
	for(gap=n/2;gap>0;gap/=2){
		if(gap%2==0)gap++;//짝수일때 홀수일때 구분 안해도 되나 간격이 홀수일 때 성능이 더 좋은것으로 판명되어 간격 홀수로 만들어준다.
		for(i=0;i<gap;i++){
			inc_insertion_sort(list,i,gap,n-1);
		}
	}
	
	
}
int sorted[MAX_VERTICES];//정렬 완성품 저장하는 임시변수
void merge(int list[], int left,int mid, int right) {
	int i = left, j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (list[i] > list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}
	for (; i <= mid; i++) {
		sorted[k++] = list[i];
	}
	for (; j <= right; j++) {
		sorted[k++] = list[j]; 
	}
	for (i = left; i <= right; i++)
		list[i] = sorted[i]; //sorted를 list로 복사 
}
void merge_sort(int list[], int left,int right) {

	if (left<right) {//순환에서 항상 중요한 종료 조건! 
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid,right);
	}
}
int partition(int list[], int left, int right) {//pivot의 이동된 위치 리턴하는
	int pivot=list[left];
	int low=left+1,high=right;
	int temp;
	while (low<high) {
		while (pivot > list[low]) low++;
		while (pivot < list[high])high--;//조건 안맞는 인덱스 찾을때까지 반복
		if (low < high) SWAP(list[low], list[high], temp);//찾았을때 low<high이면 값 스왑
	}
	SWAP(list[left], list[high], temp);
	return high;
	
}
void quick_sort(int list [], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q-1);//피벗 빼고 정렬이므로 q-1
		quick_sort(list, q+1, right);//피벗 빼고 정렬이므로 q+1
	}
}


void radix_sort(int list[], int n) {
	// 자릿수  
	QueueType queues[BUCKETS];
	int d,i,factor,k;
	factor=1;
	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);
	
	for(d=0;d<2;d++){//자릿수 미리암 
		for(i=0;i<n;i++){
			enqueue(&queues[(list[i]/factor)%10],list[i]);	
		}
		k=0;
		for(i=0;i<BUCKETS;i++){
			while(!is_empty(&queues[i])) 
				list[k++]=dequeue(&queues[i]);//list에 넣음
		}
		factor*=10;
	}
	
}
int main() {
	int i;
	n = MAX_SIZE;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % 100;
	print_arr(list, n);
	printf("\n");
	//selection_sort(list,n);
	//insertion_sort(list,n);
	//bubble_sort(list, n);
	//shell_sort(list, n);
	//quick_sort(list,0,n-1);
	radix_sort(list, n);
	print_arr(list, n);
	printf("\n");
	return 0;
}

```

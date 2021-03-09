#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100

/*
	* 객체 : n개의 element형으로 구성된 순서 있는 모임
	* 연산 
		* insert(list,pos,item)::= pos위치에 요소를 추가함
		* insert_last(list,item)::= 맨 끝에 요소를 추가함
		* insert_first(list,item)::= 맨 처음에 요소를 추가함
		* delete(list,pos)::= pos위치의 요소를 제거 
		* clear(list)::= list의 모든 요소를 제거
		* get_entry(list,pos)::= pos위치의 요소를 반환
		* get_length(list)::= 리스트의 길이를 구함
		* is_empty(list)::= 리스트가 비었는지 확인 
		* is_full(list)::= 리스트가 꽉찼는지 검사
		* print_list(list)::= 모든 요소 출력
	*/
typedef int element;
typedef struct ArrayListType{
	int size;//현재사이즈 (추가하고 증가할거임) 
	element data[MAX_LIST_SIZE];
}ArrayListType;
void init(ArrayListType*list){
	list->size=0;
}
int is_full(ArrayListType*list){
	return (list->size==MAX_LIST_SIZE);
}
int is_empty(ArrayListType*list){
	return (list->size==0);
}
void insert(ArrayListType*list,int pos,element item){
	if(pos<0||pos>list->size){
		return;
	} 
	
	//중간에 삽입한 경우 처리 
	list->data[pos++]=item;
}

void insert_last(ArrayListType*list,element item){
	if(pos<0||pos>list->size){
		return;
	}
	if(!is_full(list)) list->data[pos++]=item;
} 
void insert_first(ArrayListType*list,element item){
	if(pos<0||pos>list->size){
		return;
	}
	if(!is_full(list)) {
	int i;
	element temp=list[0];
	//shift 연산 
	for(i=1;i<list->size;i++){
	
	
	}
	
	list->data[pos++]=item;
		
	}
}
int main(){
	
	ArrayListType list;
	
	init(&list);
	insert(&list,0,10); print_list(&list);
	
	insert(&list,0,20); print_list(&list);
	insert(&list,0,30); print_list(&list);
	insert_last(&list,40);print_list(&list);
	delete(&list,0); print_list(&list);

	return 0;
}


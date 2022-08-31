  #include<iostream>
  using namespace std;
  
  
  int arr[10001];
  int main(){
  	 int sum,temp;
  	 for(int i=1;i<=10000;i++){
  	 	sum=temp=i;
  		while(temp>0){
  	 		sum+=(temp%10);
  	 		temp=temp/10;
  		 }
  		if(sum<=10000){
  			arr[sum]=1;
  		}
  	 }
  	 for(int i=1;i<=10000;i++){
  	 	if(!arr[i])cout<<i<<"\n";
  	 }
  	
  	
  	return 0;
  }
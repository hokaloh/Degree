#include <stdio.h>

const double PI = 3.14159;

//double triangle(){
//	
//	return result;
//}
//double rectangle(){
//	return result;
//}
//double square(){
//	return result;
//}
//double circle(){
//	return result;
//}

int main(){
	
//	do{
//		int selection;
//		printf("Shape Selection Through Number :\n1 -> Triangle\n2 -> Rectangle\n3 -> Square\n4 -> Circle ");
//		scanf("%d", selection);
//	}while(selection)
	
	try{
		int selection;
		printf("Shape Selection Through Number :\n1 -> Triangle\n2 -> Rectangle\n3 -> Square\n4 -> Circle ");
		scanf("%d", selection);
	} catch (Exception e){
		printf("Error")
	}
	
	return 0;
}

#include "manager.h"
int selectMenu(){

	int m =0;
	printf("\n1.메뉴조회\n2.메뉴추가\n3.메뉴수정\n4.메뉴삭제\n0.종료\n");
	printf("\n원하는 메뉴는? ");
	scanf("%d",&m);

	return m;

}
int main(){
	Product p[100];
	int menu=-1;
	int count=0;
	int index=0;
#ifdef DEBUG 
printf("debug : while()\n");
#endif
	while(1){

	menu=selectMenu();
	if(menu==0) break;
	if(menu==1) {
		if(count<=0){
			printf("no product!\n");
			continue;
		}
		else{
#ifdef DEBUG
printf("debug : listProduct()\n");
#endif
		listProduct(p,index);
	}
	}
	if(menu==2){
#ifdef DEBUG
printf("debug : addProduct()\n");
#endif
		count+=addProduct(&p[index++]);
	}	
	if(menu==3){
	
		if(count<=0) continue;
		else {
			int no=0;
		
#ifdef DEBUG
printf("debug : selectdata()\n");
#endif
			no = selectdata(p,count);
			updateProduct(&p[no-1]);
		}
	}
	if(menu==4){
		if(count==0) continue;
		else {
		
#ifdef DEBUG
printf("debug :selectdata()\n");
#endif	
			int d=0;
			d=selectdata(p,count);
			printf("삭제하시겠습니까? (Y : 1, N : 0) ");
               		int delok;
               		scanf("%d",&delok);
			if(delok==0){printf("->취소됨!\n");continue;}

			else {
#ifdef DEBUG
printf("debug :deleteProduct()\n");
#endif
               		

                   		count+=deleteProduct(&p[d-1]);
                   		printf("->삭제됨!\n");
               		}			
		}

	}
}	
return 0;
}

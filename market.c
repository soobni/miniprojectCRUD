#include "manager.h"
int main(){
	Product p[1000];
	int menu=-1;
	int count=loadProduct(p);
	int index=count;
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

#ifdef DEBUG
printf("debug :saveProduct()");
#endif	
	if(menu==5){
		if(count==0)
			printf("데이터가 없습니다.\n");
		else 
			saveProduct(p,index);
	}

#ifdef DEBUG
printf("debug :searchProduct()");
#endif	
	if(menu==6){
		if(count==0)
			printf("데이터가 없습니다.\n");
		else {
			searchProduct(p,index);
			
		}
			
	}
#ifdef DEBUG
printf("debug :buy Product ()");
#endif	
	if(menu==7){
		if(count==0)
			printf("데이터가 없습니다.\n");
		else{
			listProduct(p,index);
			int buy=0;
			printf("살 상품은? ");
			scanf("%d",&buy);
			buyProduct(p,buy);
		}
		
	}



}	
return 0;
}

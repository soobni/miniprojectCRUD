#include "manager.h"

void readProducts(Product p){
printf("%s %.0f %d %.1f %.1f\n",p.name,p.gram,p.price,p.stand_price,p.t_star);
}
void listProduct(Product *pp ,int count){
	int i=1;
        printf("제품no 상품명 중량 가격 표준가격 별점\n");
	printf("*****************************************************\n");
	for(int i=0;i<count;i++){
       		if(pp[i].price==-1)continue;
       		printf("%02d\t",i+1);
        	readProducts(pp[i]);
    }
	printf("\n");
}

int selectdata(Product p[],int n){
	int no=0;
	listProduct(p,n);
	printf("번호는?");
	scanf("%d",&no);
	return no;
}


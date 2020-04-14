#include "manager.h"

void readProducts(Product p){
printf("%s %.0f %d %.1f %d %d\n",p.name,p.gram,p.price,p.stand_price,p.t_star,p.sell_c);
}
void listProduct(Product *pp ,int count){
	int i=1;
        printf("제품no 상품명 중량 가격 표준가격 별점 판매개수\n");
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
void saveProduct(Product p[],int count){
        FILE * fp;
        fp=fopen("product.txt","wt");
        for(int i=0;i<count;i++){
                if(p[i].price!=-1)
                        fprintf(fp,"%s %.0f %d %.1f %d %d\n",p[i].name,p[i].gram,p[i].price,p[i].stand_price,p[i].t_star,p[i].sell_c);
        }
        printf("-> 저장됨!\n");
}


int loadProduct(Product *p){
	int n=0;
    FILE * fp;
    fp = fopen("product.txt","rt");
    if(fp == NULL){
        printf("=> 파일 없음\n");
        return 0;
    }
    for(; ; n++){
		if(feof(fp))break;
        fscanf(fp,"%s %f %d %f %d %d\n",p[n].name,&p[n].gram,&p[n].price,&p[n].stand_price,&p[n].t_star,&p[n].sell_c);
        
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return n;
}

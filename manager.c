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

void searchProduct(Product *pp, int count ){
    int selectnum=0;
	int c=0;
	printf("무엇으로 검색하시겠습니까? 1:이름 2:가격대 3:별점 4:판매량");
	scanf("%d",&selectnum);
	if(selectnum>4||selectnum<1){
	printf("잘못입력하였습니다.\n");
	}
        if(selectnum==1){
                char name[30];
                printf("검색할 이름을 입력하십시오.");
                getchar();
                scanf("%[^\n]",name);
                getchar();
                printf("제품no 상품명 중량 가격 표준가격 별점   판매개수\n");
	            printf("*****************************************************\n");
                for(int i=0;i<count;i++){
                        if(pp[i].price!=-1){
                                if(strstr(pp[i].name,name)){
                                        printf("%2d\t",i+1);
                                        readProduct(pp[i]);
                                        c++;
                                }
                        }
                }
                if(c==0) printf("검색된 제품이 없습니다.\n");
        }
        else if(selectnum==2){
                int search=0;
                int ud=0;
                printf("가격대 검색 1:이상검색 2:이하검색 ");
                scanf("%d",&ud);
                if(ud==1){
                        printf("얼마 이상의 상품의 가격을 검색하시겠습니까? ");
                        scanf("%d",&search);
                        printf("제품no 상품명 중량 가격 표준가격 별점   판매개수\n");
	                    printf("*****************************************************\n");
                        for(int i=0;i<count;i++){
                        if(pp[i].price!=-1){
                                if(pp[i].price>=search){
                                        printf("%2d\t",i+1);
                                        readProducts(pp[i]);
                                        c++;
                                }
                        }
                }
                
                }
                else{
                        printf("얼마 이하의 상품의 가격을 검색하시겠습니까? ");
                        scanf("%d",&search);
                        printf("제품no 상품명 중량 가격 표준가격 별점   판매개수\n");
	                    printf("*****************************************************\n");
                        for(int i=0;i<count;i++){
                        if(pp[i].price!=-1){
                                if(pp[i].price<=search){
                                        printf("%2d\t",i+1);
                                        readProducts(pp[i]);
                                        c++;
                                }
                        }
                        }
                }
                if(c==0)printf("검색된 제품이 없습니다.\n");

        }
        else if(selectnum==3){
                //별점
                int search=0;
                printf("별점 몇점 이상의 상품을 원하냐요? ");
                scanf("%d",&search);
                printf("제품no 상품명 중량 가격 표준가격 별점   판매개수\n");
	            printf("*****************************************************\n");
                for(int i=0;i<count;i++){
                        if(pp[i].t_star>=search){
                                printf("%2d\t",i+1);
                                readProducts(pp[i]);
                                c++;
                        }
                }
                if (c==0) printf("제품이 없습니다.\n");
        }
        else {
                //판매개수
                int search=0;
                printf("얼마 이상 팔린 제품을 원하시냐요? ");
                scanf("%d",&search);
                printf("제품no 상품명 중량 가격 표준가격 별점   판매개수\n");
	            printf("*****************************************************\n");
                for(int i=0;i<count;i++){
                        if(pp[i].sell_c>=search){
                                printf("%2d\t",i+1);
                                readProducts(pp[i]);
                                c++;
                        }
                }
                if (c==0) printf("제품이 없습니다.\n");

        }
}

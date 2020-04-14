#include "product.h"

void readProduct(Product p){

    if(p.price==-1)printf("읽을 상품이 없습니다.\n");
    else{
    printf("상품명 중량 가격 표준가격 별점\n");
    printf("*****************************************************\n");
    printf("%s %.0f %d %.1f %.1f\n",p.name,p.gram,p.price,p.stand_price,p.t_star);
    }
}


int addProduct(Product *pp){
        getchar();
        printf("상품명은? ");
	scanf("%[^\n]",pp->name);	

        printf("중량은? ");
        scanf("%f",&pp->gram);

        printf("가격은? ");
        scanf("%d",&pp->price);

        printf("별점은? (소수점 X, 정수형태로 입력) ");
        scanf("%d",&pp->star);
	pp->t_star=pp->star;
	pp->stand_price=1.0*(pp->price*10)/pp->gram;


	printf("추가됨 \n");
	
	return 1;
}
void updateProduct(Product *pp){
        getchar();
        printf("새 상품명은? ");
	scanf("%[^\n]",pp->name);

        printf("새 중량은? ");
        scanf("%f",&pp->gram);

        printf("새 가격은? ");
        scanf("%d",&pp->price);

        printf("별점은? ");
        scanf("%d",&pp->star);


}
int deleteProduct(Product *pp){

	pp->price=-1;
	pp->gram=-1;
	pp->star=-1;	
	printf("삭제됨! \n");
	return -1;
}

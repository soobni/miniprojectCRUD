#include <stdio.h>
typedef struct Product{
    char name [80]; //제품명
    float gram;       //중량
    int price;      //가격
    float stand_price;//표준가격
    int star;   //별점
    int t_star; //별점 총점 
    int sell_c; // 판매개수
}Product;

int selectMenu(); // 메뉴선택
int deleteProduct(Product*pp); //제품삭제
void readProduct(Product p); //제품 읽기
int addProduct(Product * pp); //제품 추가
void updateProduct(Product *pp); //제품 수정


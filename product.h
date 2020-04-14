#include <stdio.h>
typedef struct Product{
    char name [80]; //제품명
    float gram;       //중량
    int price;      //가격
    float stand_price;//표준가격
    int star;   //별점
    float t_star; //별점 총점 
    int sell_c; // 판매개수
}Product;

int selectmenu(); // 메뉴선택
int deleteProduct(Product*pp); //제품삭제
void readProduct(Product p); //제품 읽기
int addProduct(Product * pp); //제품 추가
void updateProduct(Product *pp); //제품 수정
int loadProduect(Product *pp); // 불러오기
void saveProduct(Product p[],int count); //제품 저장
void searchProduct(Product *pp,int count); //제품 검색 //이름 //가격//별점 //판매개수
int searchSelect();// 검색 기준 정하기
int buyProduct(Product *pp); //제품 사기;
//


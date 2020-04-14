#include <stdio.h>
#include "product.h"

int selectdata(Product p[],int n); //인댁스 구하기₩

void readProducts(Product p);
void listProduct(Product p[],int n);

int buyProduct(Product *pp,int index); //제품 사기;
int loadProduct(Product *pp); // 불러오기
void saveProduct(Product p[],int count); //제품 저장
void searchProduct(Product *pp, int count);
void searchindex(Product *pp);

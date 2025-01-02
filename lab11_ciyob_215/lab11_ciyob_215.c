/*	Caleb Iyob, G01257159
 *	Lab Section 215
 *	Lab 11
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d" 
#define BYTETOBINARY(byte) \
(byte & 0x80 ? 1 : 0), \
(byte & 0x40 ? 1 : 0), \
(byte & 0x20 ? 1 : 0), \
(byte & 0x10 ? 1 : 0), \
(byte & 0x08 ? 1 : 0), \
(byte & 0x04 ? 1 : 0), \
(byte & 0x02 ? 1 : 0), \
(byte & 0x01 ? 1 : 0)
#define PRINTBIN(x) printf(BYTETOBINARYPATTERN, BYTETOBINARY(x));
void setlsbs(unsigned char*,unsigned char);
unsigned char getlsbs(unsigned char*);
int main(){
	srand((unsigned) time(NULL));
	//unsigned char num =173; 
	//PRINTBIN(num); printf("\n");
	unsigned char* p=malloc(sizeof(8));
	int m;
	for(m=0;m<sizeof(p);++m){
		p[m]=rand()%256;
	}
	printf("Array p:\n");
	int j;
	unsigned char byte0=rand()%256;
	for(j=0;j<sizeof(p);++j){
                PRINTBIN(p[j]);
		printf("\n");
        }
	printf("Decimal format:\n");
	int h;
	for(h=0;h<sizeof(p);++h){
		printf("%u",p[h]);
		printf("\n");
	}
	printf("\n");
	printf("byte0:\n");
	PRINTBIN(byte0);
	printf("\n");
	printf("Decimal format: %u\n",byte0);
	printf("\n");
	setlsbs(p,byte0);
	printf("Array p after setlsbs():\n");
	int k;
	for(k=0;k<sizeof(p);++k){
		PRINTBIN(p[k]);
		printf("\n");
	}
	printf("\n");
	printf("Decimal format:\n");
	int g;
	for(g=0;g<sizeof(p);++g){
		printf("%u",p[g]);
		printf("\n");
	}
	printf("\n");
	printf("Least significant bits from p using getlsbs():\n");
	PRINTBIN(getlsbs(p));
	printf("\n");
	printf("Decimal format: %u\n",getlsbs(p));
	free(p);
}

void setlsbs(unsigned char *p, unsigned char b0){	
	int i;
	for(i=0;i<sizeof(p);++i){
		unsigned char b0extra=b0 & 0x01;
		if(b0extra){
			p[i]=p[i]|b0extra;
		}
		else{
			p[i]=p[i]&~1;
		}
		b0=b0>>1;
	}
}

unsigned char getlsbs(unsigned char *p){
	int q;
	unsigned char lsbs=0;
	for(q=0;q<sizeof(p);++q){
		unsigned char extralsbs=p[q] & 0x01;
		extralsbs=extralsbs<<q;
		lsbs=lsbs|extralsbs;
	}
	return lsbs;
}

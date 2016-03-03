#include<stdio.h>
#include<malloc.h>
#include "General.h"

int _Sbox_0_linearProfile[INPUT_SIZE][OUTPUT_SIZE];


void linearInit(){
	//initialize the linear profile of s1
	for(int i=0;i<INPUT_SIZE;i++)
		for(int j=0;j<OUTPUT_SIZE;j++)
			_Sbox_0_linearProfile[i][j]=0;
}

int liklyhood(char x,char y,int* sbox){
	int counter=0;
	for(int i=0;i<16;i++){
		int tmp=*(sbox+i);
		if((x&1&i)^((x&2&i)>>1)^((x&4&i)>>2)^((x&8&i)>>3)==(y&1&tmp)^((y&2&tmp)>>1)^((y&4&tmp)>>2)^((y&8&tmp)>>3)){
			counter++;
		}
	}

	return counter;
}

void generatingLinearProfile(int profile[INPUT_SIZE][OUTPUT_SIZE],int* sbox){
	linearInit();
	for(int i=0;i<INPUT_SIZE;i++)
		for(int j=0;j<OUTPUT_SIZE;j++){
			profile[i][j]=liklyhood(i,j,sbox);
		}
}

/*void main (void){
	init();
	//liklyhood(0,4,_Sbox_1);
	generatingLinearProfile(_Sbox_0_linearProfile,_Sbox_0);

	for(int i=0;i<16;i++){
		for(int j=0;j<OUTPUT_SIZE;j++){
			printf("%d,",_Sbox_0_linearProfile[i][j]);
		}
		printf("\n");
	}
	int r=-1;
	int c=-1;
	int value=findMin(_Sbox_0_linearProfile,&r,&c);
	printf("min = %d,r=%d,c=%d\n",value,r,c);
	r=-1;
	c=-1;
	value=findMax(_Sbox_0_linearProfile,&r,&c);
	printf("max = %d,r=%d,c=%d",value,r,c);
	getchar();
}*/
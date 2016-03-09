#ifndef GEN
#define GEN
#include <malloc.h>

#define ROUND 4
#define INPUT_SIZE 16
#define OUTPUT_SIZE 16
#define MAX_DEF_SIZE 16
#define FALSE 0
#define TRUE 1
#define MIN_NUM -100
#define MAX_NUM 100

int _Sbox_0[16]={3,8,15,1,10,6,5,11,14,13,4,2,7,0,9,12};
int _Sbox_1[16]={15,12,2,7,9,0,5,10,1,11,14,8,6,13,3,4};
int _Sbox_2[16]={8,6,7,9,3,12,10,15,13,1,14,4,0,11,5,2};
int _Sbox_3[16]={0,15,11,8,12,9,6,3,13,1,2,4,10,7,5,14};
int _Sbox_4[16]={1,15,8,3,12,0,11,6,2,5,4,10,9,14,7,13};
int _Sbox_5[16]={15,5,2,11,4,10,9,12,0,3,14,8,13,6,7,1};
int _Sbox_6[16]={7,2,12,5,8,4,6,11,14,9,1,15,13,3,10,0};
int _Sbox_7[16]={1,13,15,0,14,8,2,11,7,4,12,10,9,3,5,6};
int _Inv_Sbox_0[16]={13,3,11,0,10,6,5,12,1,14,4,7,15,9,8,2};
int _Inv_Sbox_1[16]={5,8,2,14,15,6,12,3,11,4,7,9,1,13,10,0};
int _Inv_Sbox_2[16]={12,9,15,4,11,14,1,2,0,3,6,13,5,8,10,7};
int _Inv_Sbox_3[16]={0,9,10,7,11,14,6,13,3,5,12,2,4,8,15,1};
int _Inv_Sbox_4[16]={5,0,8,3,10,9,7,14,2,12,11,6,4,15,13,1};

int findMax(int profile[INPUT_SIZE][OUTPUT_SIZE],int* row, int* col){
	int value=MIN_NUM;
	if(*row==-1 && *col ==-1){
		for(int i=1;i<INPUT_SIZE;i++)
			for(int j=1;j<OUTPUT_SIZE;j++){
				if(profile[i][j]>value){
					value=profile[i][j];
					*row=i;
					*col=j;
				}
		}
	}else if(*row==-1){
		for(int i=0;i<INPUT_SIZE;i++){
			if(profile[i][*col]>value){
				value=profile[i][*col];
				*row=i;
			}
		}
	}else if(*col==-1){
		for(int i=0;i<INPUT_SIZE;i++){
			if(profile[*row][i]>value){
				value=profile[*row][i];
				*col=i;
			}
		}
	}

	return value;
}
int findMin(int profile[INPUT_SIZE][OUTPUT_SIZE],int* row, int* col){
	int value=MAX_NUM;
	if(*row==-1 && *col ==-1){
		for(int i=0;i<INPUT_SIZE;i++)
			for(int j=0;j<OUTPUT_SIZE;j++){
				if(profile[i][j]<value){
					value=profile[i][j];
					*row=i;
					*col=j;
				}
		}
	}else if(*row==-1){
		for(int i=0;i<INPUT_SIZE;i++){
			if(profile[i][*col]<value){
				value=profile[i][*col];
				*row=i;
			}
		}
	}else if(*col==-1){
		for(int i=0;i<INPUT_SIZE;i++){
			if(profile[*row][i]<value){
				value=profile[*row][i];
				*col=i;
			}
		}
	}

	return value;
}

struct node{
	int key;
	node* next;
};

node *finalKey[32]={NULL};
void push (int index, int key )
{
	if (finalKey[index] == NULL ) {
		finalKey[index] = (node*) malloc (sizeof (node)); 
		finalKey[index]->key= key ; 
		finalKey[index]->next=NULL ; 	
		return ; 
	}
	node *current= finalKey[index] ;	
	while (current->next != NULL ) 
		current = current->next; 
	current->next = (node*) malloc (sizeof (node));
	current->next->key= key ; 
	current->next->next= NULL ;	
}
void print_node () {
	for(int i=0;i<32;i++){
		node *current=finalKey[i];
		printf("index: %d",i);
		int size=0;
		while (current != NULL ) {
			printf (" -> key:%d", current->key);
			current=current->next;
			size++;
		}
		printf("\tsize = %d\n",size);
	}
}

#endif
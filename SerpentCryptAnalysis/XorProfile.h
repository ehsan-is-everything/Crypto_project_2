#include <stdio.h>
#include <malloc.h>
#include "General.h"

int _Sbox_0_XorProfile[INPUT_SIZE][OUTPUT_SIZE]={0};
int _Sbox_1_XorProfile[INPUT_SIZE][OUTPUT_SIZE]={0};
int _Sbox_2_XorProfile[INPUT_SIZE][OUTPUT_SIZE]={0};
int _Sbox_3_XorProfile[INPUT_SIZE][OUTPUT_SIZE]={0};
int _Sbox_4_XorProfile[INPUT_SIZE][OUTPUT_SIZE]={0};

struct input_pairs
{
	int first_input ; 
	int second_input;
	input_pairs *next ; 
};

struct paire{
	int first_input ; 
	int second_input;
};

input_pairs *head [16] = { NULL } ; 


void push_pair (int index, int first , int second )
{
	if (head[index] == NULL ) {
		head[index] = (input_pairs*) malloc (sizeof (input_pairs)); 
		head[index]->first_input= first ; 
		head[index]->second_input=second ; 
		head[index]->next=NULL ; 	
		return ; 
	}
	input_pairs *current= head[index] ;	
	while (current->next != NULL ) 
		current = current->next; 
	current->next = (input_pairs*) malloc (sizeof (input_pairs));
	current->next->first_input = first ; 
	current->next->second_input = second ; 
	current->next->next= NULL ;	
}

void print_input_pairs (input_pairs *head) {
	input_pairs *current= head ; 
	//printf("size=%d\n",current->size);
	while (current != NULL ) {
		printf ("%d\t%d\n", current->first_input, current->second_input);
		current=current->next;
	}
}

void list2Array(input_pairs *head, paire* A){
	input_pairs *current= head ;
	for(int i=0;current!=NULL;i++){
		paire p;
		p.first_input=current->first_input;
		p.second_input=current->second_input;
		A[i] = p;
		current=current->next;
	}
}

void create_input_pairs(){
	for (int i=0; i<INPUT_SIZE; i++) //output Difference 
	{
		for (int j=0; j<INPUT_SIZE; j++) //first input 
		{
			for (int k=0; k<INPUT_SIZE; k++) //second input 
			{
				if ((((j&1)^(k&1)) | (((j&2)^(k&2))) | (((j&4)^(k&4))) | (((j&8)^(k&8)))) == i) 
				{
					
					push_pair (i, j, k );
				}
			}
		}
		
	}
}

void xorInit(){
	//initialize the Xor Profile of s0,s1,s2,s3,s4
	create_input_pairs ();
}


void generatingXorProfile(int profile[INPUT_SIZE][OUTPUT_SIZE],int* sbox){
	for (int i=0; i< INPUT_SIZE ; i++){
		input_pairs *current ; 
		current = head [i] ; 
		//(((j&1)^(k&1)) | (((j&2)^(k&2))) | (((j&4)^(k&4))) | (((j&8)^(k&8)))
		while (current != NULL ) {
		/*	int column =_Sbox_1[((current->first_input&1)^ (current->second_input&1)) | 
					            ((current->first_input&2)^ (current->second_input&2)) |
								((current->first_input&4)^ (current->second_input&4)) |
								((current->first_input&8)^ (current->second_input&8))];
*/
			int f = sbox[current->first_input];
			int s = sbox[current->second_input]; 
			profile[i][((f&1)^(s&1)) | ((f&2)^(s&2)) | ((f&4)^(s&4)) | ((f&8)^(s&8))] ++ ;
			current = current->next ; 
		}	
     }
}



double differentialProbabilityCalcuation (double pre_prob, double cur_prob) {
	double result = pre_prob * cur_prob ; 
	return result ;
}
/*
int main (){
	generatingXorProfile (_Sbox_1_XorProfile, _Sbox_1) ; 
	for (int i=0; i<INPUT_SIZE ; i++) {
		for (int j=0 ; j<INPUT_SIZE ; j++)
			printf ("%d  " , _Sbox_1_XorProfile[i][j]) ; 
		printf ("\n") ; 
	}

	int r=-1;
	int c=-1;
	int value = findMax(_Sbox_1_XorProfile,&r,&c) ; 
	
	printf("max = %d,r=%d,c=%d\n",value, r, c);
	getchar();
	return 0;
}*/
#include <stdio.h>
#include <malloc.h>

#define INPUT_SIZE 16
#define OUTPUT_SIZE 16
#define FALSE 0
#define TRUE 1
#define MIN_NUM -100
#define MAX_NUM 100

int _Sbox_1[16]={3,8,15,1,10,6,5,11,14,13,4,2,7,0,9,12};
int _Sbox_1_XorProfile[INPUT_SIZE][OUTPUT_SIZE];

struct input_pairs
{
	int first_input ; 
	int second_input;
	input_pairs *next ; 
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
	while (current != NULL ) {
		printf ("%d\t%d\n", current->first_input, current->second_input);
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

void init(){
	//initialize the Xor Profile of s1
	for(int i=0;i<INPUT_SIZE;i++)
		for(int j=0;j<OUTPUT_SIZE;j++)
			_Sbox_1_XorProfile[i][j]=0;
}
//
//void likelyhood (char x, char y, int *sbox) {
//	for (int i=0 ; i<INPUT_SIZE ; i++) {
//		int tmp= *(sbox+i); 
//		
//			counter++; 	
//	}
//}

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
			int f = _Sbox_1[current->first_input];
			int s = _Sbox_1[current->second_input]; 
			_Sbox_1_XorProfile[i][((f&1)^(s&1)) | ((f&2)^(s&2)) | ((f&4)^(s&4)) | ((f&8)^(s&8))] ++ ;
			current = current->next ; 
		}	
     }
}


int findMax(int profile[INPUT_SIZE][OUTPUT_SIZE],int* row, int* col){
	int value=MIN_NUM;
	if(*row==-1 && *col ==-1){
		for(int i=1;i<INPUT_SIZE;i++)
			for(int j=0;j<OUTPUT_SIZE;j++){
				if(profile[i][j]>value){
					value=profile[i][j];
					*row=i;
					*col=j;
				}
		}
	}else if(*row==-1){
		for(int i=1;i<INPUT_SIZE;i++){
			if(profile[i][*col]>value){
				value=profile[i][*col];
				*row=i;
			}
		}
	}else if(*col==-1){
		for(int i=1;i<INPUT_SIZE;i++){
			if(profile[*row][i]>value){
				value=profile[*row][i];
				*col=i;
			}
		}
	}

	return value;
}

double diff_pbob_calc (double pre_prob, double cur_prob) {
	double result = pre_prob * cur_prob ; 
	return result ;
}


int main (){
	/*for (int i=0; i<INPUT_SIZE; i++)
		head[i]= (input_pairs*) malloc (sizeof (input_pairs)); */
	init(); 
	create_input_pairs (); 
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

	return 0;
}
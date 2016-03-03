#include "Serpent.h"
#include "LinearProfile.h"
#include "XorProfile.h"

double characteresticProbability;
unsigned int input[ROUND-1][4];
unsigned int output[4];
unsigned int key [4] = {1, 2, 3, 4} ; // input key 

void init(){
	serpentInit(key);

}

void differentialInit(){
	//init probability
	characteresticProbability=1;
	//generate all xor profiles
	xorInit();
	generatingXorProfile(_Sbox_0_XorProfile,_Sbox_0);
	generatingXorProfile(_Sbox_1_XorProfile,_Sbox_1);
	generatingXorProfile(_Sbox_2_XorProfile,_Sbox_2);
	generatingXorProfile(_Sbox_3_XorProfile,_Sbox_3);
	//init arrays
	int i;
	for(i=0;i<4;i++){
		int j;
		for(j=0;j<4;j++)
			input[i][j]=0;
		output[i]=0;
	}
}

void featureExtractionMiddleRounds(int profile[INPUT_SIZE][OUTPUT_SIZE],unsigned int* tmpInput,unsigned int* tmpOutput, int round){
	int i;
	//set input of this round
	for(i=0;i<4;i++){
		input[round][i]=tmpInput[i];
	}
	//extract 4 bit input of each sbox
	int index;
	for(index=0;index<4;index++){
		int j;
		for(j=28;j>-1;j=j-4){
			int in=(tmpInput[index]&(15<<j))>>j;
			//check for being active
			if(in!=0){
				//find the best out put from xor profile
				int out=-1;
				int value=findMax(profile,&in,&out);
				//total prob calc
				double cur_prob=((double)value)/((double)MAX_DEF_SIZE);
				characteresticProbability = differentialProbabilityCalcuation(characteresticProbability,cur_prob);
				//produce the output aray
				tmpOutput[index]=tmpOutput[index]|(out<<j);
			}
		}
	}
	//produce next round input
	for(i=0;i<4;i++){
		tmpInput[i]=0;
	}
	linearTrans(tmpOutput,tmpInput);
	
	for(i=0;i<4;i++){
		tmpOutput[i]=0;
	}
	
}

void featureExtraction(){
	int round;
	unsigned int tmpInput[4];
	unsigned int tmpOutput[4];
	//init arrays
	int i;
	for(i=0;i<4;i++){
		tmpInput[i]=0;
		tmpOutput[i]=0;
	}
	for(round=0; round<ROUND-1;round++){
		switch(round){
			case 0:
				{
					//find best prob for s0
					int in=-1;int out=-1;
					int value=findMax(_Sbox_0_XorProfile,&in,&out);
					//set in as input of cipher 
					input[0][0]=input[0][0]|(in<<28);
					//total prob calc
					double cur_prob=((double)value)/((double)MAX_DEF_SIZE);
					characteresticProbability = differentialProbabilityCalcuation(characteresticProbability,cur_prob);
					//produce input of next round
					tmpOutput[0]=tmpOutput[0]|(out<<28);
					linearTrans(tmpOutput,tmpInput);
					int i;
					for(i=0;i<4;i++){
						tmpOutput[i]=0;
					}
					break;
				}
			case 1:
				featureExtractionMiddleRounds(_Sbox_1_XorProfile,tmpInput,tmpOutput,round);
				break;
			case 2:
				featureExtractionMiddleRounds(_Sbox_2_XorProfile,tmpInput,tmpOutput,round);
				break;
			case 3:
				{
					featureExtractionMiddleRounds(_Sbox_3_XorProfile,tmpInput,tmpOutput,round);
					for(i=0;i<4;i++){
						output[i]=tmpInput[i];
					}
					break;
				}
		}
	}
}



void differentialCryptAnalysis(){
	differentialInit();

	featureExtraction();

}






void main(void){
	init();
	
	differentialCryptAnalysis();
	
	unsigned int in[4]={1<<28,0,0,0};
	unsigned int out[4]={0,0,0,0};
	encrypt(in,out);
	in[0]=0;
	decrypt(out,in);
	getchar();
}

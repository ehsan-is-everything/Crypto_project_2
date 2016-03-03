#include "Serpent.h"
#include "LinearProfile.h"
#include "XorProfile.h"

#define ROUND 5

double characteresticProbability;
unsigned int input[4];
unsigned int output[4];

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
		input[i]=0;
		output[i]=0;
	}
}

void featureExtractionMiddleRounds(int profile[INPUT_SIZE][OUTPUT_SIZE],unsigned int* tmpInput,unsigned int* tmpOutput){
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
			double cur_prob=value/MAX_DEF_SIZE;
			characteresticProbability = differentialProbabilityCalcuation(characteresticProbability,cur_prob);
			//produce the output aray
			tmpOutput[index]=tmpOutput[index]|(out<<j);
		}
	}
}
//produce next round input
linearTrans(tmpOutput,tmpInput);
int i;
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
					input[4]=input[4]|(in<<28);
					//total prob calc
					double cur_prob=value/MAX_DEF_SIZE;
					characteresticProbability = differentialProbabilityCalcuation(characteresticProbability,cur_prob);
					//produce input of next round
					tmpOutput[4]=tmpOutput[4]|(out<<28);
					linearTrans(tmpOutput,tmpInput);
					int i;
					for(i=0;i<4;i++){
						tmpOutput[i]=0;
					}
					break;
				}
			case 1:
				featureExtractionMiddleRounds(_Sbox_1_XorProfile,tmpInput,tmpOutput);
				break;
			case 2:
				featureExtractionMiddleRounds(_Sbox_2_XorProfile,tmpInput,tmpOutput);
				break;
			case 3:
				{
					featureExtractionMiddleRounds(_Sbox_3_XorProfile,tmpInput,tmpOutput);
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

}






void main(void){
	

	getchar();
}

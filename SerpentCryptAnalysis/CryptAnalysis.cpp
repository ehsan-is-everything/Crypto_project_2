#include "Serpent.h"
#include "LinearProfile.h"
#include "XorProfile.h"
#include <fstream> 

double characteresticProbability;
unsigned int input[ROUND-1][4]={0};
unsigned int output[4]={0};
unsigned int key [4] = {1, 2, 3, 4} ; // input key 
FILE *plaintext ; 
FILE *ciphertext ;

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
}

void differentialFeatureExtractionMiddleRounds(int profile[INPUT_SIZE][OUTPUT_SIZE],unsigned int* tmpInput,unsigned int* tmpOutput, int round){
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

void differentialFeatureExtraction(){
	int round;
	unsigned int tmpInput[4]={0};
	unsigned int tmpOutput[4]={0};
	//init arrays
	int i;
	for(round=0; round<ROUND-1;round++){
		switch(round){
			case 0:
				{
					//find best prob for s0
					int in=-1,out=-1;
					int value=findMax(_Sbox_0_XorProfile,&in,&out);
					//set in as input of cipher 
					input[0][0]=input[0][0]|(in<<28);
					//total prob calc
					double cur_prob=((double)value)/((double)MAX_DEF_SIZE);
					characteresticProbability = differentialProbabilityCalcuation(characteresticProbability,cur_prob);
					//produce input of next round
					tmpOutput[0]=tmpOutput[0]|(out<<28);
					linearTrans(tmpOutput,tmpInput);
					for(int i=0;i<4;i++){
						tmpOutput[i]=0;
					}
					break;
				}
			case 1:
				differentialFeatureExtractionMiddleRounds(_Sbox_1_XorProfile,tmpInput,tmpOutput,round);
				break;
			case 2:
				differentialFeatureExtractionMiddleRounds(_Sbox_2_XorProfile,tmpInput,tmpOutput,round);
				break;
			case 3:
				{
				differentialFeatureExtractionMiddleRounds(_Sbox_3_XorProfile,tmpInput,tmpOutput,round);
				for(i=0;i<4;i++){
					output[i]=tmpInput[i];
				}
				break;
				}
		}
	}
}
void linearInit(){
	//init probability
	characteresticProbability=1;
	//generate linear profiles
	generatingLinearProfile(_Sbox_0_linearProfile,_Sbox_0);
	generatingLinearProfile(_Sbox_1_linearProfile,_Sbox_1);
	generatingLinearProfile(_Sbox_2_linearProfile,_Sbox_2);
	generatingLinearProfile(_Sbox_3_linearProfile,_Sbox_3);
}

void linearFeatureExtractionMiddleRounds(int profile[INPUT_SIZE][OUTPUT_SIZE],unsigned int* tmpInput,unsigned int* tmpOutput, int round){
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
				int out=-1,value=-1;
					//find best prob for s0
					int outMax=-1;
					int valueMax=findMax(_Sbox_0_linearProfile,&in,&outMax);
					int outMin=-1;
					int valueMin=findMin(_Sbox_0_linearProfile,&in,&outMin);
					if(valueMax > MAX_DEF_SIZE-valueMin){
						out=outMax;
						value=valueMax;
					}else{
						out=outMin;
						value=valueMin;
					}
				//total prob calc
				double cur_prob=((double)value)/((double)MAX_DEF_SIZE);
				characteresticProbability = pileUpLemma(characteresticProbability,cur_prob);
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


void linearFeatureExtraction(){
	int round;
	unsigned int tmpInput[4]={0};
	unsigned int tmpOutput[4]={0};
	//init arrays
	int i;
	for(round=0; round<ROUND-1;round++){
		switch(round){
			case 0:
				{
					int in=-1,out=-1,value=-1;
					//find best prob for s0
					int inMax=-1,outMax=-1;
					int valueMax=findMax(_Sbox_0_linearProfile,&inMax,&outMax);
					int inMin=-1,outMin=-1;
					int valueMin=findMin(_Sbox_0_linearProfile,&inMin,&outMin);
					if(valueMax > MAX_DEF_SIZE-valueMin){
						in=inMax;
						out=outMax;
						value=valueMax;
					}else{
						in=inMin;
						out=outMin;
						value=valueMin;
					}
					//set in as input of cipher 
					input[0][0]=input[0][0]|(in<<28);
					//total prob calc
					double cur_prob=((double)value)/((double)MAX_DEF_SIZE);
					characteresticProbability = pileUpLemma(characteresticProbability,cur_prob);
					//produce input of next round
					tmpOutput[0]=tmpOutput[0]|(out<<28);
					linearTrans(tmpOutput,tmpInput);
					for(int i=0;i<4;i++){
						tmpOutput[i]=0;
					}
					break;
				}
			case 1:
				linearFeatureExtractionMiddleRounds(_Sbox_1_linearProfile,tmpInput,tmpOutput,round);
				break;
			case 2:
				linearFeatureExtractionMiddleRounds(_Sbox_2_linearProfile,tmpInput,tmpOutput,round);
				break;
			case 3:
				{
				linearFeatureExtractionMiddleRounds(_Sbox_3_linearProfile,tmpInput,tmpOutput,round);
				for(i=0;i<4;i++){
					output[i]=tmpInput[i];
				}
				break;
				}
		}
	}
}

void last_round_exhaustive_search () {


}

void Plaintext_Ciphertext_Generation () {
	 
	plaintext = fopen ("plaintext.txt","w"); 
	if (plaintext == NULL) {
		printf ("Can't create plaintext file\n");
		return;
	}
	ciphertext = fopen ("ciphertext.txt","w"); 
	if (ciphertext == NULL) {
		printf ("Can't create ciphertext file\n");
		return;
	}
	int best_input = (input[0][0]&(15<<28))>>28 ;
	paire bestPairs[16];
	paire zeroPairs[16];
	list2Array(head[best_input],bestPairs);
	list2Array(head[0],zeroPairs);

	unsigned int plain_1[4];
	unsigned int cipher_1[4];
	unsigned int plain_2[4];
	unsigned int cipher_2[4];
	
	for(int i_8=0;i_8<16;i_8++){
		for(int i_7=0;i_7<16;i_7++){
			for(int i_6=0;i_6<16;i_6++){
				for(int i_5=0;i_5<16;i_5++){
					for(int i_4=0;i_4<16;i_4++){
						for(int i_3=0;i_3<16;i_3++){
							for(int i_2=0;i_2<16;i_2++){
								for(int i_1=0;i_1<16;i_1++){
									for(int i=0; i<4;i++)
										if(i == 0){
											plain_1[i]=bestPairs[i_8].first_input <<28|zeroPairs[i_7].first_input <<24|zeroPairs[i_6].first_input <<20|
												zeroPairs[i_5].first_input <<16|zeroPairs[i_4].first_input <<12|zeroPairs[i_3].first_input <<8|
												zeroPairs[i_2].first_input <<4|zeroPairs[i_1].first_input;
											plain_2[i]=bestPairs[i_8].second_input <<28|zeroPairs[i_7].second_input <<24|zeroPairs[i_6].second_input <<20|
												zeroPairs[i_5].second_input <<16|zeroPairs[i_4].second_input <<12|zeroPairs[i_3].second_input <<8|
												zeroPairs[i_2].second_input <<4|zeroPairs[i_1].second_input;
										}else{
											plain_1[i]=zeroPairs[i_8].first_input <<28|zeroPairs[i_7].first_input <<24|zeroPairs[i_6].first_input <<20|
												zeroPairs[i_5].first_input <<16|zeroPairs[i_4].first_input <<12|zeroPairs[i_3].first_input <<8|
												zeroPairs[i_2].first_input <<4|zeroPairs[i_1].first_input;
											plain_2[i]=zeroPairs[i_8].second_input <<28|zeroPairs[i_7].second_input <<24|zeroPairs[i_6].second_input <<20|
												zeroPairs[i_5].second_input <<16|zeroPairs[i_4].second_input <<12|zeroPairs[i_3].second_input <<8|
												zeroPairs[i_2].second_input <<4|zeroPairs[i_1].second_input;
										}
										encrypt(plain_1,cipher_1);
										encrypt(plain_2,cipher_2);

								}
							}
						}
					}
				}
			}
		}
	}
}



void differentialCryptAnalysis(){
	differentialInit();

	differentialFeatureExtraction();

}

void linearCryptAnalysis(){
	linearInit();

	linearFeatureExtraction();
}




void main(void){
	init();
	
	differentialCryptAnalysis();
	Plaintext_Ciphertext_Generation();
	//print_input_pairs(head[2]);
	//list2Array(head[2]);
	/*unsigned int in[4]={1<<31,0,0,0};
	unsigned int out[4]={0,0,0,0};
	encrypt(in,out);
	in[0]=0;
	decrypt(out,in);*/
	//getchar();
	//linearTrans(in,out);
	//inverseLinearTrans(in,out);
	getchar();
}

#include "Serpent.h"
#include "LinearProfile.h"
#include "XorProfile.h"
#include <fstream> 
#include <math.h>

double characteresticProbability;
unsigned int input[ROUND][4]={0};
unsigned int key [4] = {1, 2, 3, 4} ; // input key 
FILE *plaintext_ciphertext ; 

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
	switch(round)
	{
	case 0:
		{
		tmpOutput[0]=262144;
		tmpOutput[1]=2147483840;
		tmpOutput[2]=16;
		tmpOutput[3]=129;
		break;
		}
	case 1:
		{
		tmpOutput[0]=0;
		tmpOutput[1]=128;
		tmpOutput[2]=16;
		tmpOutput[3]=128;
		break;
		}
	case 2:
		{
		tmpOutput[0]=0;
		tmpOutput[1]=536870912;
		tmpOutput[2]=0;
		tmpOutput[3]=536870912;
		break;
		}
	case 3:
		{
		tmpOutput[0]=67109376;
		tmpOutput[1]=1140851208;
		tmpOutput[2]=1073742360;
		tmpOutput[3]=24;
		characteresticProbability = pow(2.0,-31);
		break;
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
	unsigned int tmpInput[4]={2147483712,145,2147745857,2147745873};
	unsigned int tmpOutput[4]={0};
	//init arrays
	int i;
	for(round=0; round<ROUND;round++){
		switch(round){
			case 0:
				differentialFeatureExtractionMiddleRounds(_Sbox_0_XorProfile,tmpInput,tmpOutput,round);
				break;
			case 1:
				differentialFeatureExtractionMiddleRounds(_Sbox_1_XorProfile,tmpInput,tmpOutput,round);
				break;
			case 2:
				differentialFeatureExtractionMiddleRounds(_Sbox_2_XorProfile,tmpInput,tmpOutput,round);
				break;
			case 3:
				{
				differentialFeatureExtractionMiddleRounds(_Sbox_3_XorProfile,tmpInput,tmpOutput,round);
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
					/*int in=-1,out=-1,value=-1;
					//find best prob for s0
					int inMax=-1,outMax=-1;
					int valueMax=findMax(_Sbox_0_linearProfile,&inMax,&outMax);
					int inMin=-1,outMin=-1;
					int valueMin=findMin(_Sbox_0_linearProfile,&inMin,&outMin);
					if(valueMax > MAX_DEF_SIZE - valueMin){
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
					}*/
					linearFeatureExtractionMiddleRounds(_Sbox_0_linearProfile,tmpInput,tmpOutput,round);
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
				break;
				}
		}
	}
}

void last_round_exhaustive_search () {
	plaintext_ciphertext=fopen("plaintext_ciphertext.txt", "r");

	unsigned int c1[4];
	unsigned int c2[4];//should be initialize with file
	unsigned int tmpc1_1[4]={0};
	unsigned int tmpc1_2[4]={0};
	unsigned int tmpc2_1[4]={0};
	unsigned int tmpc2_2[4]={0};
	unsigned int key[4]={0};
	int result[16]={0};

	bool activeSboxes[32]={0};
	for(int i=0;i<32;i++){
		if(((input[ROUND - 1][0]&(1<<i))>>i)|((input[ROUND - 1][1]&(1<<i))>>i)<<1|((input[ROUND - 1][2]&(1<<i))>>i)<<2|((input[ROUND - 1][3]&(1<<i))>>i)<<3 != 0)
			activeSboxes[i]=1;
	}

	for (int index=0; index<32; index++){//active sbox
		if(activeSboxes[index] != 0){// if active
			for (int key=0; key<16; key++){ //all permutations of key
				fseek(plaintext_ciphertext,0,SEEK_SET);
				while(true){//all pairs in file ZOHRE
					fseek(plaintext_ciphertext,32, SEEK_CUR);
					fread(c1,4,1,plaintext_ciphertext);
					if (fread(c2,4,1,plaintext_ciphertext)<1)
						break;

					int tmp = (((c1[0]&(1<<index))>>index)|((c1[1]&(1<<index))>>index)<<1|((c1[2]&(1<<index))>>index)<<2|((c1[3]&(1<<index))>>index)<<3)^key;
					tmpc1_1[3] |= ((tmp & (1<<3))>>3)<<index;
					tmpc1_1[2] |= ((tmp & (1<<2))>>2)<<index;
					tmpc1_1[1] |= ((tmp & (1<<1))>>1)<<index;
					tmpc1_1[0] |= ((tmp & (1)))<<index;
					inverseLinearTrans(tmpc1_1,tmpc1_2);
					Rev_SLayer(tmpc1_2,tmpc1_1,ROUND - 1);
					
					tmp = (((c2[0]&(1<<index))>>index)|((c2[1]&(1<<index))>>index)<<1|((c2[2]&(1<<index))>>index)<<2|((c2[3]&(1<<index))>>index)<<3)^key;
					tmpc2_1[3] |= ((tmp & (1<<3))>>3)<<index;
					tmpc2_1[2] |= ((tmp & (1<<2))>>2)<<index;
					tmpc2_1[1] |= ((tmp & (1<<1))>>1)<<index;
					tmpc2_1[0] |= ((tmp & (1)))<<index;
					inverseLinearTrans(tmpc2_1,tmpc2_2);
					Rev_SLayer(tmpc2_2,tmpc2_1,ROUND - 1);
				
					int deltaOut = ((input[ROUND - 1][0]&(1<<index))>>index)|((input[ROUND - 1][1]&(1<<index))>>index)<<1|((input[ROUND - 1][2]&(1<<index))>>index)<<2|((input[ROUND - 1][3]&(1<<index))>>index)<<3;
					int u1 = ((tmpc1_1[0]&(1<<index))>>index)|((tmpc1_1[1]&(1<<index))>>index)<<1|((tmpc1_1[2]&(1<<index))>>index)<<2|((tmpc1_1[3]&(1<<index))>>index)<<3;
					int u2 = ((tmpc2_1[0]&(1<<index))>>index)|((tmpc2_1[1]&(1<<index))>>index)<<1|((tmpc2_1[2]&(1<<index))>>index)<<2|((tmpc2_1[3]&(1<<index))>>index)<<3;
					if (u1 ^ u2 == deltaOut)
						result[key]++;
				}
			}
			int max = result[0]; 
			for(int i=1; i<16; i++)
				if(result[i] > max)
					max = result[i];
			for (int i=0;i<16;i++)
				if(result[i]==max)
					push(index,i);
		}
	}


}

void Plaintext_Ciphertext_Generation () {
	 
	plaintext_ciphertext = fopen ("plaintext_ciphertext.txt","a"); 
	if (plaintext_ciphertext == NULL) {
		printf ("Can't create plaintext_ciphertext file\n");
		return;
	}
	
	paire bestPairs_13[16];
	paire bestPairs_10[16];
	paire bestPairs_2[16];
	paire bestPairs_12[16];
	paire bestPairs_14[16];
	paire zeroPairs[16];
	list2Array(head[2],bestPairs_2);
	list2Array(head[10],bestPairs_10);
	list2Array(head[12],bestPairs_12);
	list2Array(head[13],bestPairs_13);
	list2Array(head[14],bestPairs_14);
	list2Array(head[0],zeroPairs);

	unsigned int plain_1[4]={0};
	unsigned int cipher_1[4]={0};
	unsigned int plain_2[4]={0};
	unsigned int cipher_2[4]={0};
	
	for(int i_0=0;i_0<16;i_0++){
		for(int i_1=0;i_1<16;i_1++){
			for(int i_2=0;i_2<16;i_2++){
				for(int i_4=0;i_4<16;i_4++){
					for(int i_6=0;i_6<16;i_6++){
						for(int i_7=0;i_7<16;i_7++){
							for(int i_18=0;i_18<16;i_18++){
								for(int i_31=0;i_31<16;i_31++){			
									for(int index=0;index<32;index++){
										if(index == 0){
											plain_1[3] |= ((bestPairs_14[i_0].first_input & (1<<3))>>3)<<index;
											plain_1[2] |= ((bestPairs_14[i_0].first_input & (1<<2))>>2)<<index;
											plain_1[1] |= ((bestPairs_14[i_0].first_input & (1<<1))>>1)<<index;
											plain_1[0] |= ((bestPairs_14[i_0].first_input & (1)))<<index;		

											plain_2[3] |= ((bestPairs_14[i_0].second_input & (1<<3))>>3)<<index;
											plain_2[2] |= ((bestPairs_14[i_0].second_input & (1<<2))>>2)<<index;
											plain_2[1] |= ((bestPairs_14[i_0].second_input & (1<<1))>>1)<<index;
											plain_2[0] |= ((bestPairs_14[i_0].second_input & (1)))<<index;		
										}else if(index == 4){
											plain_1[3] |= ((bestPairs_10[i_4].first_input & (1<<3))>>3)<<index;
											plain_1[2] |= ((bestPairs_10[i_4].first_input & (1<<2))>>2)<<index;
											plain_1[1] |= ((bestPairs_10[i_4].first_input & (1<<1))>>1)<<index;
											plain_1[0] |= ((bestPairs_10[i_4].first_input & (1)))<<index;		

											plain_2[3] |= ((bestPairs_10[i_4].second_input & (1<<3))>>3)<<index;
											plain_2[2] |= ((bestPairs_10[i_4].second_input & (1<<2))>>2)<<index;
											plain_2[1] |= ((bestPairs_10[i_4].second_input & (1<<1))>>1)<<index;
											plain_2[0] |= ((bestPairs_10[i_4].second_input & (1)))<<index;		
										}else if(index == 6){
											plain_1[3] |= ((bestPairs_13[i_6].first_input & (1<<3))>>3)<<index;
											plain_1[2] |= ((bestPairs_13[i_6].first_input & (1<<2))>>2)<<index;
											plain_1[1] |= ((bestPairs_13[i_6].first_input & (1<<1))>>1)<<index;
											plain_1[0] |= ((bestPairs_13[i_6].first_input & (1)))<<index;		

											plain_2[3] |= ((bestPairs_13[i_6].second_input & (1<<3))>>3)<<index;
											plain_2[2] |= ((bestPairs_13[i_6].second_input & (1<<2))>>2)<<index;
											plain_2[1] |= ((bestPairs_13[i_6].second_input & (1<<1))>>1)<<index;
											plain_2[0] |= ((bestPairs_13[i_6].second_input & (1)))<<index;		
										}else if(index == 7){
											plain_1[3] |= ((bestPairs_2[i_7].first_input & (1<<3))>>3)<<index;
											plain_1[2] |= ((bestPairs_2[i_7].first_input & (1<<2))>>2)<<index;
											plain_1[1] |= ((bestPairs_2[i_7].first_input & (1<<1))>>1)<<index;
											plain_1[0] |= ((bestPairs_2[i_7].first_input & (1)))<<index;		

											plain_2[3] |= ((bestPairs_2[i_7].second_input & (1<<3))>>3)<<index;
											plain_2[2] |= ((bestPairs_2[i_7].second_input & (1<<2))>>2)<<index;
											plain_2[1] |= ((bestPairs_2[i_7].second_input & (1<<1))>>1)<<index;
											plain_2[0] |= ((bestPairs_2[i_7].second_input & (1)))<<index;		
										}else if(index == 18){
											plain_1[3] |= ((bestPairs_12[i_18].first_input & (1<<3))>>3)<<index;
											plain_1[2] |= ((bestPairs_12[i_18].first_input & (1<<2))>>2)<<index;
											plain_1[1] |= ((bestPairs_12[i_18].first_input & (1<<1))>>1)<<index;
											plain_1[0] |= ((bestPairs_12[i_18].first_input & (1)))<<index;		

											plain_2[3] |= ((bestPairs_12[i_18].second_input & (1<<3))>>3)<<index;
											plain_2[2] |= ((bestPairs_12[i_18].second_input & (1<<2))>>2)<<index;
											plain_2[1] |= ((bestPairs_12[i_18].second_input & (1<<1))>>1)<<index;
											plain_2[0] |= ((bestPairs_12[i_18].second_input & (1)))<<index;		
										}else if(index == 31){
											plain_1[3] |= ((bestPairs_13[i_31].first_input & (1<<3))>>3)<<index;
											plain_1[2] |= ((bestPairs_13[i_31].first_input & (1<<2))>>2)<<index;
											plain_1[1] |= ((bestPairs_13[i_31].first_input & (1<<1))>>1)<<index;
											plain_1[0] |= ((bestPairs_13[i_31].first_input & (1)))<<index;		

											plain_2[3] |= ((bestPairs_13[i_31].second_input & (1<<3))>>3)<<index;
											plain_2[2] |= ((bestPairs_13[i_31].second_input & (1<<2))>>2)<<index;
											plain_2[1] |= ((bestPairs_13[i_31].second_input & (1<<1))>>1)<<index;
											plain_2[0] |= ((bestPairs_13[i_31].second_input & (1)))<<index;		
										}else if(index == 1){
											plain_1[3] |= ((zeroPairs[i_1].first_input & (1<<3))>>3)<<index;
											plain_1[2] |= ((zeroPairs[i_1].first_input & (1<<2))>>2)<<index;
											plain_1[1] |= ((zeroPairs[i_1].first_input & (1<<1))>>1)<<index;
											plain_1[0] |= ((zeroPairs[i_1].first_input & (1)))<<index;		

											plain_2[3] |= ((zeroPairs[i_1].second_input & (1<<3))>>3)<<index;
											plain_2[2] |= ((zeroPairs[i_1].second_input & (1<<2))>>2)<<index;
											plain_2[1] |= ((zeroPairs[i_1].second_input & (1<<1))>>1)<<index;
											plain_2[0] |= ((zeroPairs[i_1].second_input & (1)))<<index;		
										}else{
											plain_1[3] |= ((zeroPairs[i_2].first_input & (1<<3))>>3)<<index;
											plain_1[2] |= ((zeroPairs[i_2].first_input & (1<<2))>>2)<<index;
											plain_1[1] |= ((zeroPairs[i_2].first_input & (1<<1))>>1)<<index;
											plain_1[0] |= ((zeroPairs[i_2].first_input & (1)))<<index;		

											plain_2[3] |= ((zeroPairs[i_2].second_input & (1<<3))>>3)<<index;
											plain_2[2] |= ((zeroPairs[i_2].second_input & (1<<2))>>2)<<index;
											plain_2[1] |= ((zeroPairs[i_2].second_input & (1<<1))>>1)<<index;
											plain_2[0] |= ((zeroPairs[i_2].second_input & (1)))<<index;		
										}

									}
									encrypt(plain_1,cipher_1);
									encrypt(plain_2,cipher_2);
									fwrite(&plain_1,sizeof(int),4,plaintext_ciphertext);
									fwrite(&plain_2,sizeof(int),4,plaintext_ciphertext);
									fwrite(&cipher_1,sizeof(int),4,plaintext_ciphertext);
									fwrite(&cipher_2,sizeof(int),4,plaintext_ciphertext);
								}
							}
						}
					}
				}
			}
		}
	}
	
	fclose(plaintext_ciphertext);
}



void differentialCryptAnalysis(){
	differentialInit();

	differentialFeatureExtraction();

	last_round_exhaustive_search();

}

void linearCryptAnalysis(){
	linearInit();

	linearFeatureExtraction();
}




void main(void){
	init();
	
	differentialCryptAnalysis();
	//Plaintext_Ciphertext_Generation();
	//print_input_pairs(head[2]);
	//list2Array(head[2]);
	/*unsigned int in[4]={2147483712,145,2147745857,2147745873};
	unsigned int out[4]={0,0,0,0};
	encrypt(in,out);
	in[0]=0;
	decrypt(out,in);*/
	//getchar();
	//linearTrans(in,out);
	//inverseLinearTrans(in,out);
	//last_round_exhaustive_search();
	print_node();

	getchar();
}

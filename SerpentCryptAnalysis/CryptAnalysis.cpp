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
				differentialFeatureExtractionMiddleRounds(_Sbox_3_XorProfile,tmpInput,tmpOutput,round);
				break;
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
	switch(round)
	{
	case 0://3
		{
		tmpOutput[0]=268968008;
		tmpOutput[1]=35127808;
		tmpOutput[2]=66624;
		tmpOutput[3]=268967944;
		break;
		}
	case 1://4
		{
		tmpOutput[0]=294912;
		tmpOutput[1]=2415919104;
		tmpOutput[2]=301989888;
		tmpOutput[3]=0;
		break;
		}
	case 2://5
		{
		tmpOutput[0]=0;
		tmpOutput[1]=0;
		tmpOutput[2]=536870912;
		tmpOutput[3]=1;
		break;
		}
	case 3://6
		{
		tmpOutput[0]=128;
		tmpOutput[1]=0;
		tmpOutput[2]=0;
		tmpOutput[3]=0;
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


void linearFeatureExtraction(){
	int round;
	unsigned int tmpInput[4]={35194432,35127808,303113736,66624};
	unsigned int tmpOutput[4]={0};
	//init arrays
	int i;
	for(round=0; round<ROUND;round++){
		switch(round){
			case 0:	
				linearFeatureExtractionMiddleRounds(_Sbox_0_linearProfile,tmpInput,tmpOutput,round);
				break;
			case 1:
				linearFeatureExtractionMiddleRounds(_Sbox_1_linearProfile,tmpInput,tmpOutput,round);
				break;
			case 2:
				linearFeatureExtractionMiddleRounds(_Sbox_2_linearProfile,tmpInput,tmpOutput,round);
				break;
			case 3:
				linearFeatureExtractionMiddleRounds(_Sbox_3_linearProfile,tmpInput,tmpOutput,round);
				break;
		}
	}
}

void linear_last_round_exhaustive_search () {
	plaintext_ciphertext=fopen("linear_plaintext_ciphertext.txt", "r");

	unsigned int c1[4];
	unsigned int p1[4];//should be initialize with file
	unsigned int tmpc1_1[4]={0};
	unsigned int tmpc1_2[4]={0};
	unsigned int keyArray[4]={0};

	bool activeSboxesLastRound[32]={0};
	int numberOfActivesLastRound = 0;
	for(int i=0;i<32;i++){
		if(((input[ROUND - 1][0]&(1<<i))>>i)|((input[ROUND - 1][1]&(1<<i))>>i)<<1|((input[ROUND - 1][2]&(1<<i))>>i)<<2|((input[ROUND - 1][3]&(1<<i))>>i)<<3 != 0){
			activeSboxesLastRound[i]=1;
			numberOfActivesLastRound++;
		}
	}

	bool activeSboxesFirstRound[32]={0};
	for(int i=0;i<32;i++){
		if(((input[0][0]&(1<<i))>>i)|((input[0][1]&(1<<i))>>i)<<1|((input[0][2]&(1<<i))>>i)<<2|((input[0][3]&(1<<i))>>i)<<3 != 0){
			activeSboxesFirstRound[i]=1;
		}
	}
	uint64_t max_key=(uint64_t)pow(2.0,numberOfActivesLastRound*4);
	int index;
	uint64_t count=0;

	for (uint64_t key=0;key<max_key; key++){
		fseek(plaintext_ciphertext,0,SEEK_SET);
		for (index=0;index<32;index++){
			if(activeSboxesLastRound[index] == TRUE){	
				keyArray[3] |= (((15 & key) & (1<<3))>>3)<<index;
				keyArray[2] |= (((15 & key) & (1<<2))>>2)<<index;
				keyArray[1] |= (((15 & key) & (1<<1))>>1)<<index;
				keyArray[0] |= (((15 & key) & (1)))<<index;
				key=key >> 4;
			}
		}
		while(true){//all pairs in file
			if (fread(p1,4,1,plaintext_ciphertext)<1)
				break;
			if (fread(c1,4,1,plaintext_ciphertext)<1)
				break;

			for(int i=0;i<4;i++)
				c1[i]^=keyArray[i];
			inverseLinearTrans(c1,tmpc1_1);
			Rev_SLayer(tmpc1_1,tmpc1_2,START_ROUND_LINEAR + ROUND - 1);

			int xorResult=0;
			for(index=0;index<4; index++){
				if(activeSboxesLastRound[index] == TRUE){
					xorResult^=(tmpc1_2[0]&(1<<index))>>index;
					xorResult^=(tmpc1_2[1]&(1<<index))>>index;
					xorResult^=(tmpc1_2[2]&(1<<index))>>index;
					xorResult^=(tmpc1_2[3]&(1<<index))>>index;
				}
			}

			for(index = 0; index<32;index++ ){
				if(activeSboxesFirstRound[index] == TRUE){
					xorResult^=(p1[0]&(1<<index))>>index;
					xorResult^=(p1[1]&(1<<index))>>index;
					xorResult^=(p1[2]&(1<<index))>>index;
					xorResult^=(p1[3]&(1<<index))>>index;
				}
			}
			if(xorResult == 0){
				count++;
			}
		}
		pushLinearKey(keyArray,count);
	}
	fclose(plaintext_ciphertext);
}

	




void differential_last_round_exhaustive_search () {
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
					if (fread(c1,4,1,plaintext_ciphertext)<1)
						break;
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

	fclose(plaintext_ciphertext);
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
	
	for(int i_0=0;i_0<1;i_0++){
		for(int i_1=0;i_1<1;i_1++){
			for(int i_2=0;i_2<1;i_2++){
				for(int i_4=0;i_4<1;i_4++){
					for(int i_6=0;i_6<1;i_6++){
						for(int i_7=0;i_7<1;i_7++){
							for(int i_18=0;i_18<1;i_18++){
								for(int i_31=0;i_31<1;i_31++){			
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

	differential_last_round_exhaustive_search();

}

void linearCryptAnalysis(){
	linearInit();

	linearFeatureExtraction();

	linear_last_round_exhaustive_search();
}




void main(void){
	init();
	
//	differentialCryptAnalysis();
	linearCryptAnalysis();
//	Plaintext_Ciphertext_Generation();
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
	//print_node();

	getchar();
}

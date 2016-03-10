#include<stdio.h>
#include "General.h"

#define Golden_Ratio 0x9e3779b9

void IP(int* plain){

}


void SLayer(unsigned int input[4],unsigned int* output, int round){
	switch (round){
		case 0:
			for(int i=0;i<32;i++){
				int tmp = _Sbox_0[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 1:
			for(int i=0;i<32;i++){
				int tmp = _Sbox_1[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 2:
			for(int i=0;i<32;i++){
				int tmp = _Sbox_2[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 3:
			for(int i=0;i<32;i++){
				int tmp = _Sbox_3[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 4:
			for(int i=0;i<32;i++){
				int tmp = _Sbox_4[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 5:
			for(int i=0;i<32;i++){
				int tmp = _Sbox_5[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 6:
			for(int i=0;i<32;i++){
				int tmp = _Sbox_6[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 7:
			for(int i=0;i<32;i++){
				int tmp = _Sbox_7[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;

	}
}

void Rev_SLayer(unsigned int input[4],unsigned int* output, int round){
	switch (round){
		case 0:
			for(int i=0;i<32;i++){
				int tmp = _Inv_Sbox_0[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 1:
			for(int i=0;i<32;i++){
				int tmp = _Inv_Sbox_1[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 2:
			for(int i=0;i<32;i++){
				int tmp = _Inv_Sbox_2[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 3:
			for(int i=0;i<32;i++){
				int tmp = _Inv_Sbox_3[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 4:
			for(int i=0;i<32;i++){
				int tmp = _Inv_Sbox_4[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 5:
			for(int i=0;i<32;i++){
				int tmp = _Inv_Sbox_5[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 6:
			for(int i=0;i<32;i++){
				int tmp = _Inv_Sbox_6[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
		case 7:
			for(int i=0;i<32;i++){
				int tmp = _Inv_Sbox_7[((input[0]&(1<<i))>>i)|((input[1]&(1<<i))>>i)<<1|((input[2]&(1<<i))>>i)<<2|((input[3]&(1<<i))>>i)<<3];
				output[3] |= ((tmp & (1<<3))>>3)<<i;
				output[2] |= ((tmp & (1<<2))>>2)<<i;
				output[1] |= ((tmp & (1<<1))>>1)<<i;
				output[0] |= ((tmp & (1)))<<i;
			}
			break;
	}
}

unsigned int _rotl_(const unsigned int value, int shift) {
    if ((shift &= sizeof(value)*8 - 1) == 0)
      return value;
    return (value << shift) | (value >> (sizeof(value)*8 - shift));
}

unsigned int _rotr_(const unsigned int value, int shift) {
    if ((shift &= sizeof(value)*8 - 1) == 0)
      return value;
    return (value >> shift) | (value << (sizeof(value)*8 - shift));
}

void linearTrans(unsigned int input[4],unsigned int* output){
	input[0] = _rotl_(input[0],13);
	input[2] = _rotl_(input[2],3);
	input[1] = input[1]^input[0]^input[2];
	input[3] = input[3]^input[2]^(input[0] << 3);
	input[1] = _rotl_(input[1], 1);
	input[3] = _rotl_(input[3], 7);
	input[0] = input[0]^input[1]^input[3];
	input[2] = input[2]^input[3]^(input[1] << 7);
	input[0] = _rotl_(input[0] , 5);
	input[2] = _rotl_(input[2],22);
	for(int i=0;i<4;i++){
		output[i]=input[i];
	}
}

void inverseLinearTrans(unsigned int input[4],unsigned int* output){
	input[2] = _rotr_(input[2],22);
	input[0] = _rotr_(input[0] , 5);
	input[2] = input[2]^input[3]^(input[1] << 7);
	input[0] = input[0]^input[1]^input[3];
	input[3] = _rotr_(input[3], 7);
	input[1] = _rotr_(input[1], 1);
	input[3] = input[3]^input[2]^(input[0] << 3);
	input[1] = input[1]^input[0]^input[2];
	input[2] = _rotr_(input[2],3);
	input[0] = _rotr_(input[0],13);
	for(int i=0;i<4;i++){
		output[i]=input[i];
	}
}

//unsigned int padded_key[8]={0}; //256 bit key generated by key_padding
unsigned int round_key[33][4]={0} ; //33 rounds & 128-bit subkeys 
unsigned int prekey[140]={0}; //w-8,...,w-1 , w0, ..., w131 

void key_padding (unsigned int* key ) {
	//initializing w-8 ,..., w-1 
	for (int i=0 ; i<4 ; i++) 
		prekey[i]=key[i] ; 
	prekey[4] = prekey[4]|(1<<31);//appending one "1" bit to MSB end, followed by "0" bits
	}

void KeySchedule (unsigned int *key) {
	key_padding(key) ; 
	for (int i=8 ; i<140 ; i++) {
		prekey[i] = (prekey[i-8] ^ prekey[i-5] ^ prekey[i-3] ^ prekey[i-1] ^ Golden_Ratio ^ i ) ; 
		//int tmp = (prekey[i] & (2047 << 21)) >> 21 ;
		//prekey[i] = (prekey[i] << 11) | tmp ;
		prekey[i] = _rotl_(prekey[i],11);
	}

	//calculating round keys using S-boxes 
	for (int i=0; i<32 ; i++) 
		for (int j=0; j<4 ; j++) {

			round_key[0][j]|= ((_Sbox_3[((prekey[0]&(1<<i))| ((prekey[1]&(1<<i))<<1) | ((prekey[2]&(1<<i))<<2) | ((prekey[3]&(1<<i))<<3))&15] & (1<<i)) & (1<<j));
			round_key[1][j]|= ((_Sbox_2[((prekey[4]&(1<<i))| ((prekey[5]&(1<<i))<<1) | ((prekey[6]&(1<<i))<<2) | ((prekey[7]&(1<<i))<<3))&15] & (1<<i)) & (1<<j));
			round_key[2][j]|= ((_Sbox_1[((prekey[8]&(1<<i))| ((prekey[9]&(1<<i))<<1) | ((prekey[10]&(1<<i))<<2) | ((prekey[11]&(1<<i))<<3))&15] & (1<<i)) & (1<<j));
			round_key[3][j]|= ((_Sbox_0[((prekey[12]&(1<<i))| ((prekey[13]&(1<<i))<<1) | ((prekey[14]&(1<<i))<<2) | ((prekey[15]&(1<<i))<<3))&15] & (1<<i)) & (1<<j));
			round_key[4][j]|= ((_Sbox_7[((prekey[16]&(1<<i))| ((prekey[17]&(1<<i))<<1) | ((prekey[18]&(1<<i))<<2) | ((prekey[19]&(1<<i))<<3))&15] & (1<<i)) & (1<<j));
			round_key[5][j]|= ((_Sbox_6[((prekey[20]&(1<<i))| ((prekey[21]&(1<<i))<<1) | ((prekey[22]&(1<<i))<<2) | ((prekey[23]&(1<<i))<<3))&15] & (1<<i)) & (1<<j));
 	}

}


void serpentInit(unsigned int *key){
	KeySchedule(key);
}

void xorSubkey(unsigned int input[4],unsigned int* output,int round){
	for(int i=0;i<4;i++){
		output[i]=input[i]^round_key[round][i];
	}
}

void encrypt(unsigned int plain[4], unsigned int* cipher, int startRound, int numberOfRounds){
	unsigned int tmpInput[4]={0};
	unsigned int tmpOutput[4]={0};
	//init arrays
	int i;
	for(i=0;i<4;i++){
		tmpInput[i]=plain[i];
	}
	int round=startRound;
	xorSubkey(tmpInput,tmpOutput,round);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
	for (round=startRound;round<numberOfRounds;round++){
		SLayer(tmpInput,tmpOutput,round);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
		linearTrans(tmpInput,tmpOutput);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
		xorSubkey(tmpInput,tmpOutput,round+1);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
	}
	for(i=0;i<4;i++){
		cipher[i]=tmpInput[i];
	}
}

void decrypt(unsigned int cipher[4], unsigned int* plain){
	unsigned int tmpInput[4];
	unsigned int tmpOutput[4];
	//init arrays
	int i;
	for(i=0;i<4;i++){
		tmpInput[i]=cipher[i];
		tmpOutput[i]=0;
	}
	int round=0;
	xorSubkey(tmpInput,tmpOutput,ROUND);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
	for (round=ROUND-1;round>-1;round--){
		inverseLinearTrans(tmpInput,tmpOutput);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
		Rev_SLayer(tmpInput,tmpOutput,round);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
		xorSubkey(tmpInput,tmpOutput,round);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
	}
	for(i=0;i<4;i++){
		plain[i]=tmpInput[i];
	}
}

/*
void main(void){
	unsigned int input[4]={65536,0,0,0};
	unsigned int output[4]={0,0,0,0};
	//LinearTrans(input,output);
	SLayer(input,output,0);
	for(int i=0;i<4;i++)
		printf("%d",output[i]);
	getchar();
}
*/


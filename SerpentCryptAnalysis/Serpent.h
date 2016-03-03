#include<stdio.h>
#include "General.h"




void serpentInit(){

}

void IP(int* plain){

}


void SLayer(unsigned int input[4],unsigned int* output, int round){
	switch (round){
		case 0:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Sbox_0[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Sbox_0[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Sbox_0[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Sbox_0[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Sbox_0[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Sbox_0[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Sbox_0[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Sbox_0[(input[i]&(15))]));
			}
			break;
		case 1:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Sbox_1[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Sbox_1[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Sbox_1[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Sbox_1[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Sbox_1[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Sbox_1[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Sbox_1[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Sbox_1[(input[i]&(15))]));
			}
			break;
		case 2:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Sbox_2[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Sbox_2[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Sbox_2[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Sbox_2[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Sbox_2[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Sbox_2[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Sbox_2[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Sbox_2[(input[i]&(15))]));
			}
			break;
		case 3:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Sbox_3[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Sbox_3[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Sbox_3[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Sbox_3[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Sbox_3[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Sbox_3[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Sbox_3[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Sbox_3[(input[i]&(15))]));
			}
			break;
		case 4:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Sbox_4[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Sbox_4[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Sbox_4[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Sbox_4[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Sbox_4[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Sbox_4[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Sbox_4[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Sbox_4[(input[i]&(15))]));
			}
			break;
	}
}

void Rev_SLayer(unsigned int input[4],unsigned int* output, int round){
	switch (round){
		
		case 0:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Inv_Sbox_0[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Inv_Sbox_0[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Inv_Sbox_0[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Inv_Sbox_0[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Inv_Sbox_0[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Inv_Sbox_0[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Inv_Sbox_0[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Inv_Sbox_0[(input[i]&(15))]));
			}
			break;
		case 1:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Inv_Sbox_1[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Inv_Sbox_1[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Inv_Sbox_1[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Inv_Sbox_1[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Inv_Sbox_1[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Inv_Sbox_1[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Inv_Sbox_1[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Inv_Sbox_1[(input[i]&(15))]));
			}
			break;
		case 2:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Inv_Sbox_2[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Inv_Sbox_2[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Inv_Sbox_2[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Inv_Sbox_2[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Inv_Sbox_2[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Inv_Sbox_2[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Inv_Sbox_2[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Inv_Sbox_2[(input[i]&(15))]));
			}
			break;
		case 3:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Inv_Sbox_3[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Inv_Sbox_3[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Inv_Sbox_3[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Inv_Sbox_3[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Inv_Sbox_3[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Inv_Sbox_3[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Inv_Sbox_3[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Inv_Sbox_3[(input[i]&(15))]));
			}
			break;
		case 4:
			for(int i=0;i<4;i++){
				output[i]=output[i]|((_Inv_Sbox_4[(input[i]&(15<<28))>>28])<<28);
				output[i]=output[i]|((_Inv_Sbox_4[(input[i]&(15<<24))>>24])<<24);
				output[i]=output[i]|((_Inv_Sbox_4[(input[i]&(15<<20))>>20])<<20);
				output[i]=output[i]|((_Inv_Sbox_4[(input[i]&(15<<16))>>16])<<16);
				output[i]=output[i]|((_Inv_Sbox_4[(input[i]&(15<<12))>>12])<<12);
				output[i]=output[i]|((_Inv_Sbox_4[(input[i]&(15<<8))>>8])<<8);
				output[i]=output[i]|((_Inv_Sbox_4[(input[i]&(15<<4))>>4])<<4);
				output[i]=output[i]|((_Inv_Sbox_4[(input[i]&(15))]));
			}
			break;
	}
}


void trans1bit(unsigned int* bits,unsigned int size,unsigned int input[4],unsigned int* output,unsigned int place){
	char res=0;
	for(int i=0;i<size;i++){
		int tmp=*(bits+i);
		int index=tmp/32;
		int shift=tmp%32;
		res=res^(1<<(32-shift)&input[index])>>(32-shift);
	}
	int index=place/32;
	int shift=place%32;
	output[index]=(res<<(31-shift)) | output[index];
}

void linearTrans(unsigned int input[4],unsigned int* output){
	unsigned int _bits_0[7]={16,52,56,70,83,94,105};
	trans1bit(_bits_0,7,input,output,0);

	unsigned int _bits_1[3]={72,114,125};
	trans1bit(_bits_1,3,input,output,1);

	unsigned int _bits_2[7]={ 2,9,15,30,76,84,126};
	trans1bit(_bits_2,7,input,output,2);
	unsigned int _bits_3[3]={36,90,103};
	trans1bit(_bits_3,3,input,output,3);
	unsigned int _bits_4[7]={20,56,60,74,87,98,109};
	trans1bit(_bits_4,7,input,output,4);
	unsigned int _bits_5[3]={1,76,118};
	trans1bit(_bits_5,3,input,output,5);
	unsigned int _bits_6[7]={ 2,6,13,19,34,80,88};
	trans1bit(_bits_6,7,input,output,6);
	unsigned int _bits_7[3]={40,94,107};
	trans1bit(_bits_7,3,input,output,7);

	unsigned int _bits_8[7]={24,60,64,78,91,102,113};
	trans1bit(_bits_2,7,input,output,8);
	unsigned int _bits_9[3]={36,90,103};
	trans1bit(_bits_9,3,input,output,9);
	unsigned int _bits_10[7]={ 6,10,17,23,38,84,92};
	trans1bit(_bits_10,7,input,output,10);
	unsigned int _bits_11[3]={44,98,111};
	trans1bit(_bits_11,3,input,output,11);
	unsigned int _bits_12[7]={28,64,68,82,95,106,117};
	trans1bit(_bits_12,7,input,output,12);
	unsigned int _bits_13[3]={ 9,84,126};
	trans1bit(_bits_13,3,input,output,13);
   
   unsigned int _bits_14[7]={10,14,21,27,42,88,96};
	trans1bit(_bits_14,7,input,output,14);
	unsigned int _bits_15[3]={48,102,115};
	trans1bit(_bits_15,3,input,output,15);
	unsigned int _bits_16[7]={32,68,72,86,99,110,121};
	trans1bit(_bits_16,7,input,output,16);
	unsigned int _bits_17[3]={ 2,13,88};
	trans1bit(_bits_17,3,input,output,17);
	unsigned int _bits_18[7]={14,18,25,31,46,92,100};
	trans1bit(_bits_18,7,input,output,18);
	unsigned int _bits_19[3]={52,106,119};
	trans1bit(_bits_19,3,input,output,19);
   
   unsigned int _bits_20[7]={36,72,76,90,103,114,125};
	trans1bit(_bits_20,7,input,output,20);
	unsigned int _bits_21[3]={ 6,17,92};
	trans1bit(_bits_21,3,input,output,21);
	unsigned int _bits_22[7]={18,22,29,35,50,96,104};
	trans1bit(_bits_22,7,input,output,22);
	unsigned int _bits_23[3]={56,110,123};
	trans1bit(_bits_23,3,input,output,23);
	unsigned int _bits_24[7]={ 1,40,76,80,94,107,118};
	trans1bit(_bits_24,7,input,output,24);
	unsigned int _bits_25[3]={10,21,96};
	trans1bit(_bits_25,3,input,output,25);
   
	unsigned int _bits_26[7]={22,26,33,39,54,100,108};
	trans1bit(_bits_26,7,input,output,26);
	unsigned int _bits_27[3]={60,114,127};
	trans1bit(_bits_27,3,input,output,27);
	unsigned int _bits_28[7]={ 5,44,80,84,98,111,122};
	trans1bit(_bits_28,7,input,output,28);
	unsigned int _bits_29[3]={14,25,100};
	trans1bit(_bits_29,3,input,output,29);
	unsigned int _bits_30[7]={26,30,37,43,58,104,112};
	trans1bit(_bits_30,7,input,output,30);
	unsigned int _bits_31[3]={ 3,118 };
	trans1bit(_bits_31,3,input,output,31);
   
	unsigned int _bits_32[7]={ 9,48,84,88,102,115,126};
	trans1bit(_bits_32,7,input,output,32);
	unsigned int _bits_33[3]={18,29,104};
	trans1bit(_bits_33,3,input,output,33);
	unsigned int _bits_34[7]={30,34,41,47,62,108,116};
	trans1bit(_bits_34,7,input,output,34);
	unsigned int _bits_35[2]={ 7,122 };
	trans1bit(_bits_35,2,input,output,35);
	unsigned int _bits_36[7]={ 2,13,52,88,92,106,119};
	trans1bit(_bits_36,7,input,output,36);
	unsigned int _bits_37[3]={22,33,108};
	trans1bit(_bits_37,3,input,output,37);
    unsigned int _bits_38[7]={34,38,45,51,66,112,120};
	trans1bit(_bits_38,7,input,output,38);
	unsigned int _bits_39[2]={11,126 };
	trans1bit(_bits_39,2,input,output,39);

	unsigned int _bits_40[7]={ 6,17,56,92,96,110,123};
	trans1bit(_bits_40,7,input,output,40);
	unsigned int _bits_41[3]={26,37,112};
	trans1bit(_bits_41,3,input,output,41);
	unsigned int _bits_42[7]={38,42,49,55,70,116,124};
	trans1bit(_bits_42,7,input,output,42);
	unsigned int _bits_43[3]={ 2,15,76};
	trans1bit(_bits_43,3,input,output,43);
	unsigned int _bits_44[7]={10,21,60,96,100,114,127};
	trans1bit(_bits_44,7,input,output,44);
	unsigned int _bits_45[3]={30,41,116};
	trans1bit(_bits_45,3,input,output,45);
    unsigned int _bits_46[7]={ 0,42,46,53,59,74,120};
	trans1bit(_bits_46,7,input,output,46);
	unsigned int _bits_47[3]={ 6,19,80};
	trans1bit(_bits_47,3,input,output,47);

    unsigned int _bits_48[7]={ 3,14,25,100,104,118 };
	trans1bit(_bits_48,7,input,output,48);
	unsigned int _bits_49[3]={34,45,120};
	trans1bit(_bits_49,3,input,output,49);
	unsigned int _bits_50[7]={ 4,46,50,57,63,78,124};
	trans1bit(_bits_50,7,input,output,50);
	unsigned int _bits_51[3]={10,23,84};
	trans1bit(_bits_51,3,input,output,51);
	unsigned int _bits_52[7]={ 7,18,29,104,108,122 };
	trans1bit(_bits_52,7,input,output,52);
	unsigned int _bits_53[3]={38,49,124};
	trans1bit(_bits_53,3,input,output,53);
    unsigned int _bits_54[7]={ 0,8,50,54,61,67,82};
	trans1bit(_bits_54,7,input,output,54);
	unsigned int _bits_55[3]={14,27,88};
	trans1bit(_bits_55,3,input,output,55);  
	
	unsigned int _bits_56[7]={11,22,33,108,112,126 };
	trans1bit(_bits_56,7,input,output,56);
	unsigned int _bits_57[3]={ 0,42,53};
	trans1bit(_bits_57,3,input,output,57);
	unsigned int _bits_58[7]={ 4,12,54,58,65,71,86};
	trans1bit(_bits_58,7,input,output,58);
	unsigned int _bits_59[3]={18,31,92};
	trans1bit(_bits_59,3,input,output,59);
	unsigned int _bits_60[7]={ 2,15,26,37,76,112,116};
	trans1bit(_bits_60,7,input,output,60);
	unsigned int _bits_61[3]={ 4,46,57};
	trans1bit(_bits_61,3,input,output,61);
    unsigned int _bits_62[7]={ 8,16,58,62,69,75,90};
	trans1bit(_bits_62,7,input,output,62);
	unsigned int _bits_63[3]={22,35,96};
	trans1bit(_bits_63,3,input,output,63);  
   
	unsigned int _bits_64[7]={6,19,30,41,80,116,120};
	trans1bit(_bits_64,7,input,output,64);
	unsigned int _bits_65[3]={ 8,50,61};
	trans1bit(_bits_65,3,input,output,65);
	unsigned int _bits_66[7]={12,20,62,66,73,79,94};
	trans1bit(_bits_66,7,input,output,66);
	unsigned int _bits_67[3]={26,39,100};
	trans1bit(_bits_67,3,input,output,67);
	unsigned int _bits_68[7]={10,23,34,45,84,120,124};
	trans1bit(_bits_68,7,input,output,68);
	unsigned int _bits_69[3]={12,54,65};
	trans1bit(_bits_69,3,input,output,69);
    unsigned int _bits_70[7]={16,24,66,70,77,83,98};
	trans1bit(_bits_70,7,input,output,70);
	unsigned int _bits_71[3]={30,43,104};
	trans1bit(_bits_71,3,input,output,71);  
	
	unsigned int _bits_72[7]={ 0,14,27,38,49,88,124};
	trans1bit(_bits_72,7,input,output,72);
	unsigned int _bits_73[3]={16,58,69};
	trans1bit(_bits_73,3,input,output,73);
	unsigned int _bits_74[7]={20,28,70,74,81,87,102};
	trans1bit(_bits_74,7,input,output,74);
	unsigned int _bits_75[3]={34,47,108};
	trans1bit(_bits_75,3,input,output,75);
	unsigned int _bits_76[7]={ 0,4,18,31,42,53,92};
	trans1bit(_bits_76,7,input,output,76);
	unsigned int _bits_77[3]={20,62,73};
	trans1bit(_bits_77,3,input,output,77);
    unsigned int _bits_78[7]={24,32,74,78,85,91,106};
	trans1bit(_bits_78,7,input,output,78);
	unsigned int _bits_79[3]={38,51,112};
	trans1bit(_bits_79,3,input,output,79);  
   
	unsigned int _bits_80[7]={ 4,8,22,35,46,57,96};
	trans1bit(_bits_80,7,input,output,80);
	unsigned int _bits_81[3]={24,66,77};
	trans1bit(_bits_81,3,input,output,81);  
	unsigned int _bits_82[7]={28,36,78,82,89,95,110};
	trans1bit(_bits_82,7,input,output,82);
	unsigned int _bits_83[3]={42,55,116};
	trans1bit(_bits_83,3,input,output,83);
	unsigned int _bits_84[7]={8,12,26,39,50,61,100};
	trans1bit(_bits_84,7,input,output,84);
	unsigned int _bits_85[3]={28,70,81};
	trans1bit(_bits_85,3,input,output,85);
	unsigned int _bits_86[7]={32,40,82,86,93,99,114};
	trans1bit(_bits_86,7,input,output,86);
	unsigned int _bits_87[3]={46,59,120};
	trans1bit(_bits_87,3,input,output,87);
    unsigned int _bits_88[7]={12,16,30,43,54,65,104};
	trans1bit(_bits_88,7,input,output,88);
	unsigned int _bits_89[3]={32,74,85};
	trans1bit(_bits_89,3,input,output,89);
   
	unsigned int _bits_90[4]={36,90,103,118};
	trans1bit(_bits_90,4,input,output,90);
	unsigned int _bits_91[3]={50,63,124};
	trans1bit(_bits_91,3,input,output,91);  
	unsigned int _bits_92[7]={16,20,34,47,58,69,108};
	trans1bit(_bits_92,7,input,output,92);
	unsigned int _bits_93[3]={36,78,89};
	trans1bit(_bits_93,3,input,output,93);
	unsigned int _bits_94[4]={40,94,107,122};
	trans1bit(_bits_94,4,input,output,94);
	unsigned int _bits_95[3]={0,54,67};
	trans1bit(_bits_95,3,input,output,95);
	unsigned int _bits_96[7]={20,24,38,51,62,73,112};
	trans1bit(_bits_96,7,input,output,96);
	unsigned int _bits_97[3]={40,82,93};
	trans1bit(_bits_97,3,input,output,97);
    unsigned int _bits_98[4]={44,98,111,126};
	trans1bit(_bits_98,4,input,output,98);
	unsigned int _bits_99[3]={4,58,71};
	trans1bit(_bits_99,3,input,output,99);

	unsigned int _bits_100[7]={24,28,42,55,66,77,116};
	trans1bit(_bits_100,7,input,output,100);
	unsigned int _bits_101[3]={44,86,97};
	trans1bit(_bits_101,3,input,output,101);  
	unsigned int _bits_102[4]={2,48,102,115};
	trans1bit(_bits_102,4,input,output,102);
	unsigned int _bits_103[3]={8,62,75};
	trans1bit(_bits_103,3,input,output,103);
	unsigned int _bits_104[7]={28,32,46,59,70,81,120};
	trans1bit(_bits_104,7,input,output,104);
	unsigned int _bits_105[3]={48,90,101};
	trans1bit(_bits_105,3,input,output,105);
	unsigned int _bits_106[4]={6,52,106,119};
	trans1bit(_bits_106,4,input,output,106);
	unsigned int _bits_107[3]={12,66,79};
	trans1bit(_bits_107,3,input,output,107);
    unsigned int _bits_108[7]={32,36,50,63,74,85,124};
	trans1bit(_bits_108,7,input,output,108);
	unsigned int _bits_109[3]={52,94,105};
	trans1bit(_bits_109,3,input,output,109);
	
	unsigned int _bits_110[4]={10,56,110,123};
	trans1bit(_bits_110,4,input,output,110);
	unsigned int _bits_111[3]={16,70,83};
	trans1bit(_bits_111,3,input,output,111);  
	unsigned int _bits_112[7]={0,36,40,54,67,78,89};
	trans1bit(_bits_112,7,input,output,112);
	unsigned int _bits_113[3]={56,98,109};
	trans1bit(_bits_113,3,input,output,113);
	unsigned int _bits_114[4]={14,60,114,127};
	trans1bit(_bits_114,4,input,output,114);
	unsigned int _bits_115[3]={20,74,87};
	trans1bit(_bits_115,3,input,output,115);
	unsigned int _bits_116[7]={4,40,44,58,71,82,93};
	trans1bit(_bits_116,7,input,output,116);
	unsigned int _bits_117[3]={60,102,113};
	trans1bit(_bits_117,3,input,output,117);
    unsigned int _bits_118[6]={3,18,72,114,118,125};
	trans1bit(_bits_118,6,input,output,118);
	unsigned int _bits_119[3]={24,78,91};
	trans1bit(_bits_119,3,input,output,119);

	unsigned int _bits_120[7]={8,44,48,62,75,86,97};
	trans1bit(_bits_120,7,input,output,120);
	unsigned int _bits_121[3]={64,106,127};
	trans1bit(_bits_121,3,input,output,121);  
	unsigned int _bits_122[6]={1,7,22,76,118,122};
	trans1bit(_bits_122,6,input,output,122);
	unsigned int _bits_123[3]={28,82,95};
	trans1bit(_bits_123,3,input,output,123);
	unsigned int _bits_124[7]={12,48,52,66,79,90,101};
	trans1bit(_bits_124,7,input,output,124);
	unsigned int _bits_125[3]={68,110,121};
	trans1bit(_bits_125,3,input,output,125);
	unsigned int _bits_126[6]={5,11,26,80,122,126};
	trans1bit(_bits_126,6,input,output,126);
	unsigned int _bits_127[3]={32,86,99};
	trans1bit(_bits_127,3,input,output,127);
}

void inverseLinearTrans(unsigned int input[4],unsigned int* output){
	unsigned int _bits_0[3]={53,55,72};
	trans1bit(_bits_0,3,input,output,0);

	unsigned int _bits_1[4]={1,5,20,90};
	trans1bit(_bits_1,4,input,output,1);

	unsigned int _bits_2[2]={ 15,102};
	trans1bit(_bits_2,2,input,output,2);

	unsigned int _bits_3[3]={3, 31, 90};
	trans1bit(_bits_3,3,input,output,3);

	unsigned int _bits_4[3]={57, 59, 76};
	trans1bit(_bits_4,3,input,output,4);

	unsigned int _bits_5[4]={5,9,24,94};
	trans1bit(_bits_5,4,input,output,5);

	unsigned int _bits_6[2]={ 19, 106};
	trans1bit(_bits_6,2,input,output,6);

	unsigned int _bits_7[3]={7, 35, 94};
	trans1bit(_bits_7,3,input,output,7);

	unsigned int _bits_8[3]={61, 63, 80};
	trans1bit(_bits_2,3,input,output,8);

	unsigned int _bits_9[4]={9, 13, 28, 98};
	trans1bit(_bits_9,4,input,output,9);

	unsigned int _bits_10[2]={ 23, 110};
	trans1bit(_bits_10,2,input,output,10);

	unsigned int _bits_11[3]={11, 39, 98};
	trans1bit(_bits_11,3,input,output,11);

	unsigned int _bits_12[3]={65, 67, 84};
	trans1bit(_bits_12,3,input,output,12);
  
   unsigned int _bits_13[4]={13, 17, 32, 102 };
	trans1bit(_bits_13,4,input,output,14);

	unsigned int _bits_14[2]={27, 114};
	trans1bit(_bits_14,2,input,output,15);

	unsigned int _bits_15[6]={1, 3, 15, 20, 43, 102};
	trans1bit(_bits_15,6,input,output,16);

	unsigned int _bits_16[3]={ 69, 71 ,88};
	trans1bit(_bits_16,3,input,output,17);

	unsigned int _bits_17[4]={17, 21, 36, 106};
	trans1bit(_bits_17,4,input,output,18);

	unsigned int _bits_18[3]={1, 31, 118};
	trans1bit(_bits_18,3,input,output,19);
   
   unsigned int _bits_19[6]={5, 7, 19, 24, 47, 106};
	trans1bit(_bits_19,6,input,output,20);

	unsigned int _bits_20[3]={73, 75, 92};
	trans1bit(_bits_20,3,input,output,21);

	unsigned int _bits_21[4]={21, 25, 40, 110};
	trans1bit(_bits_21,4,input,output,22);

	unsigned int _bits_22[3]={5, 35, 122};
	trans1bit(_bits_22,3,input,output,23);

	unsigned int _bits_23[6]={ 9, 11, 23, 28, 51, 110};
	trans1bit(_bits_23,6,input,output,24);

	unsigned int _bits_24[3]={77, 79, 96};
	trans1bit(_bits_24,3,input,output,25);
   
	unsigned int _bits_25[4]={25, 29, 44, 114};
	trans1bit(_bits_25,4,input,output,26);

	unsigned int _bits_26[3]={9, 39, 126};
	trans1bit(_bits_26,3,input,output,27);

	unsigned int _bits_27[6]={ 13, 15, 27, 32, 55, 114};
	trans1bit(_bits_27,6,input,output,28);

	unsigned int _bits_28[3]={81, 83, 100};
	trans1bit(_bits_28,3,input,output,30);

	unsigned int _bits_29[5]={ 1, 29, 33, 48, 118};
	trans1bit(_bits_29,5,input,output,31);
   
	unsigned int _bits_30[3]={ 2, 13, 43};
	trans1bit(_bits_30,3,input,output,32);

	unsigned int _bits_31[7]={1, 17, 19, 31, 36, 59, 118};
	trans1bit(_bits_31,7,input,output,33);

	unsigned int _bits_32[3]={85, 87, 104};
	trans1bit(_bits_32,3,input,output,34);

	unsigned int _bits_33[5]={ 5, 33, 37, 52, 122};
	trans1bit(_bits_33,5,input,output,35);

	unsigned int _bits_34[3]={6, 17, 47};
	trans1bit(_bits_34,3,input,output,36);

	unsigned int _bits_35[7]={5, 21, 23, 35, 40, 63, 122};
	trans1bit(_bits_35,7,input,output,37);

    unsigned int _bits_36[3]={89, 91, 108};
	trans1bit(_bits_36,3,input,output,38);

	unsigned int _bits_37[5]={9, 37, 41, 56, 126};
	trans1bit(_bits_37,5,input,output,39);

	unsigned int _bits_38[3]={ 10, 21, 51};
	trans1bit(_bits_38,3,input,output,40);

	unsigned int _bits_39[7]={9, 25, 27, 39, 44, 67, 126};
	trans1bit(_bits_39,7,input,output,41);

	unsigned int _bits_40[3]={93, 95, 112};
	trans1bit(_bits_40,3,input,output,42);

	unsigned int _bits_41[5]={ 2, 13, 41, 45, 60};
	trans1bit(_bits_41,5,input,output,43);

	unsigned int _bits_42[3]={14, 25, 55};
	trans1bit(_bits_42,3,input,output,44);

	unsigned int _bits_43[7]={2, 13, 29, 31, 43, 48, 71};
	trans1bit(_bits_43,7,input,output,45);
	
    unsigned int _bits_44[3]={97, 99, 116};
	trans1bit(_bits_44,3,input,output,46);

	unsigned int _bits_45[5]={ 6, 17, 45, 49, 64};
	trans1bit(_bits_45,5,input,output,47);

    unsigned int _bits_46[3]={ 18, 29, 59 };
	trans1bit(_bits_46,3,input,output,48);

	unsigned int _bits_47[7]={6, 17, 33, 35, 47, 52, 75};
	trans1bit(_bits_47,7,input,output,49);

	unsigned int _bits_48[3]={ 101, 103, 120};
	trans1bit(_bits_48,3,input,output,50);

	unsigned int _bits_49[5]={10, 21, 49, 53, 68};
	trans1bit(_bits_49,5,input,output,51);

	unsigned int _bits_50[3]={ 22, 33, 63 };
	trans1bit(_bits_50,3,input,output,52);

	unsigned int _bits_51[7]={10, 21, 37, 39, 51, 56, 79};
	trans1bit(_bits_51,7,input,output,53);

    unsigned int _bits_52[3]={ 105, 107, 124};
	trans1bit(_bits_52,3,input,output,54);

	unsigned int _bits_53[5]={14, 25, 53, 57, 72};
	trans1bit(_bits_53,5,input,output,55);  
	
	unsigned int _bits_54[3]={26, 37, 67};
	trans1bit(_bits_54,3,input,output,56);

	unsigned int _bits_55[7]={14, 25, 41, 43, 55, 60, 83};
	trans1bit(_bits_55,7,input,output,57);

	unsigned int _bits_56[3]={ 0, 109, 111};
	trans1bit(_bits_56,3,input,output,58);

	unsigned int _bits_57[5]={18, 29, 57, 61, 76};
	trans1bit(_bits_57,5,input,output,59);

	unsigned int _bits_58[3]={ 30, 41, 71};
	trans1bit(_bits_58,3,input,output,60);

	unsigned int _bits_59[7]={ 18, 29, 45, 47, 59, 64, 87};
	trans1bit(_bits_59,7,input,output,61);

    unsigned int _bits_60[3]={ 4, 113, 115};
	trans1bit(_bits_60,3,input,output,62);

	unsigned int _bits_61[5]={22, 33, 61, 65, 80};
	trans1bit(_bits_61,5,input,output,63);  
   
	unsigned int _bits_62[3]={34, 45, 75};
	trans1bit(_bits_62,3,input,output,64);

	unsigned int _bits_63[7]={ 22, 33, 49, 51, 63, 68, 91};
	trans1bit(_bits_63,7,input,output,65);

	unsigned int _bits_64[3]={8, 117, 119};
	trans1bit(_bits_64,3,input,output,66);

	unsigned int _bits_65[5]={26, 37, 65, 69, 84};
	trans1bit(_bits_65,5,input,output,67);

	unsigned int _bits_66[3]={38, 49, 79};
	trans1bit(_bits_66,3,input,output,68);

	unsigned int _bits_67[7]={26, 37, 53, 55, 67, 72, 95};
	trans1bit(_bits_67,7,input,output,69);

    unsigned int _bits_68[3]={12, 121, 123};
	trans1bit(_bits_68,3,input,output,70);

	unsigned int _bits_69[5]={30, 41, 69, 73, 88};
	trans1bit(_bits_69,5,input,output,71);  
	
	unsigned int _bits_70[3]={ 42, 53, 83};
	trans1bit(_bits_70,3,input,output,72);

	unsigned int _bits_71[7]={30, 41, 57, 59, 71, 76, 99};
	trans1bit(_bits_71,7,input,output,73);

	unsigned int _bits_72[3]={16, 125, 127};
	trans1bit(_bits_72,3,input,output,74);

	unsigned int _bits_73[5]={34,45, 73, 77, 92};
	trans1bit(_bits_73,5,input,output,75);

	unsigned int _bits_74[3]={ 46, 57, 87};
	trans1bit(_bits_74,3,input,output,76);

	unsigned int _bits_75[7]={34, 45, 61, 63, 75, 80, 103};
	trans1bit(_bits_75,7,input,output,77);

    unsigned int _bits_76[3]={1, 3, 20};
	trans1bit(_bits_76,3,input,output,78);

	unsigned int _bits_77[5]={38,49, 77, 81, 96};
	trans1bit(_bits_77,5,input,output,79);  
   
	unsigned int _bits_78[3]={50, 61, 91};
	trans1bit(_bits_78,3,input,output,80);

	unsigned int _bits_79[7]={38, 49, 65, 67, 79, 84, 107};
	trans1bit(_bits_79,7,input,output,81);  

	unsigned int _bits_80[3]={5, 7, 24};
	trans1bit(_bits_80,3,input,output,82);

	unsigned int _bits_81[5]={42, 53, 81, 85, 100};
	trans1bit(_bits_81,5,input,output,83);

	unsigned int _bits_82[3]={54, 65, 95};
	trans1bit(_bits_82,3,input,output,84);

	unsigned int _bits_83[7]={42, 53, 69, 71, 83, 88, 111};
	trans1bit(_bits_83,7,input,output,85);

	unsigned int _bits_84[3]={9, 11, 28};
	trans1bit(_bits_84,3,input,output,86);

	unsigned int _bits_85[5]={46, 57, 85, 89, 104};
	trans1bit(_bits_85,5,input,output,87);

    unsigned int _bits_86[3]={58, 69, 99};
	trans1bit(_bits_86,3,input,output,88);

	unsigned int _bits_87[7]={46, 57, 73, 75, 87, 92, 115};
	trans1bit(_bits_87,7,input,output,89);
   
	unsigned int _bits_88[3]={13, 15, 32};
	trans1bit(_bits_88,3,input,output,90);

	unsigned int _bits_89[5]={50, 61, 89, 93, 108};
	trans1bit(_bits_89,5,input,output,91);  

	unsigned int _bits_90[3]={62, 73, 103};
	trans1bit(_bits_90,3,input,output,92);

	unsigned int _bits_91[7]={50, 61, 77, 79, 91, 96, 119};
	trans1bit(_bits_91,7,input,output,93);

	unsigned int _bits_92[3]={17, 19, 36};
	trans1bit(_bits_92,3,input,output,94);

	unsigned int _bits_93[5]={54, 65, 93, 97, 112};
	trans1bit(_bits_93,5,input,output,95);

	unsigned int _bits_94[3]={66, 77, 107};
	trans1bit(_bits_94,3,input,output,96);

	unsigned int _bits_95[7]={54, 65, 81, 83, 95, 100, 123};
	trans1bit(_bits_95,7,input,output,97);

    unsigned int _bits_96[3]={21, 23, 40};
	trans1bit(_bits_96,3,input,output,98);

	unsigned int _bits_97[5]={58, 69, 97, 101, 116};
	trans1bit(_bits_97,5,input,output,99);

	unsigned int _bits_98[3]={70, 81, 111};
	trans1bit(_bits_98,3,input,output,100);

	unsigned int _bits_99[7]={58, 69, 85, 87, 99, 104, 127};
	trans1bit(_bits_99,7,input,output,101);  

	unsigned int _bits_100[3]={25, 27, 44};
	trans1bit(_bits_100,3,input,output,102);

	unsigned int _bits_101[5]={62, 73, 101, 105, 120};
	trans1bit(_bits_101,5,input,output,103);

	unsigned int _bits_102[3]={74, 85, 115};
	trans1bit(_bits_102,3,input,output,104);

	unsigned int _bits_103[7]={3, 62, 73, 89, 91, 103, 108 };
	trans1bit(_bits_103,7,input,output,105);

	unsigned int _bits_104[3]={29, 31, 48};
	trans1bit(_bits_104,3,input,output,106);

	unsigned int _bits_105[5]={66, 77, 105, 109, 124};
	trans1bit(_bits_105,5,input,output,107);

    unsigned int _bits_106[3]={78, 89, 119};
	trans1bit(_bits_106,3,input,output,108);

	unsigned int _bits_107[7]={7, 66, 77, 93, 95, 107, 112};
	trans1bit(_bits_107,7,input,output,109);
	
	unsigned int _bits_108[3]={33, 35, 52};
	trans1bit(_bits_108,3,input,output,110);

	unsigned int _bits_109[5]={ 0, 70, 81, 109, 113};
	trans1bit(_bits_109,5,input,output,111);  

	unsigned int _bits_110[3]={82, 93, 123};
	trans1bit(_bits_110,3,input,output,112);

	unsigned int _bits_111[7]={11, 70, 81, 97, 99, 111, 116};
	trans1bit(_bits_111,7,input,output,113);

	unsigned int _bits_112[3]={37, 39, 56};
	trans1bit(_bits_112,3,input,output,114);

	unsigned int _bits_113[5]={4, 74, 85, 113, 117};
	trans1bit(_bits_113,5,input,output,115);

	unsigned int _bits_114[3]={86, 97, 127};
	trans1bit(_bits_114,3,input,output,116);

	unsigned int _bits_115[7]={15, 74, 85, 101, 103, 115, 120};
	trans1bit(_bits_115,7,input,output,117);

    unsigned int _bits_116[3]={41, 43, 60};
	trans1bit(_bits_116,3,input,output,118);

	unsigned int _bits_117[5]={8, 78, 89, 117, 121};
	trans1bit(_bits_117,5,input,output,119);

	unsigned int _bits_118[2]={3, 90};
	trans1bit(_bits_118,2,input,output,120);

	unsigned int _bits_119[7]={19, 78, 89, 105, 107, 119, 124};
	trans1bit(_bits_119,7,input,output,121); 

	unsigned int _bits_120[3]={45, 47, 64};
	trans1bit(_bits_120,3,input,output,122);

	unsigned int _bits_121[5]={12, 82, 93, 121, 125};
	trans1bit(_bits_121,5,input,output,123);

	unsigned int _bits_122[2]={7, 94};
	trans1bit(_bits_122,2,input,output,124);

	unsigned int _bits_123[7]={0, 23, 82, 93, 109, 111, 123};
	trans1bit(_bits_123,7,input,output,125);

	unsigned int _bits_124[3]={59, 51, 68};
	trans1bit(_bits_124,3,input,output,126);

	unsigned int _bits_125[5]={1, 16, 86, 97, 125};
	trans1bit(_bits_125,5,input,output,126);

	unsigned int _bits_126[2]={11, 98};
	trans1bit(_bits_126,2,input,output,126);

	unsigned int _bits_127[7]={4, 27, 86, 97, 113, 115, 127};
	trans1bit(_bits_127,7,input,output,127);
}
//TODO inject this code from Zohre
void xorSubkey(unsigned int input[4],unsigned int* output,int round){
	int i;
	for(i=0;i<4;i++){
		output[i]=input[i];
	}
}

void encrypt(unsigned int plain[4], unsigned int* cipher){
	unsigned int tmpInput[4];
	unsigned int tmpOutput[4];
	//init arrays
	int i;
	for(i=0;i<4;i++){
		tmpInput[i]=plain[i];
		tmpOutput[i]=0;
	}
	int round;
	for (round=0;round<ROUND-1;round++){
		xorSubkey(tmpInput,tmpOutput,round);
		for(i=0;i<4;i++){
			tmpInput[i]=tmpOutput[i];
			tmpOutput[i]=0;
		}
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
	}
	for(i=0;i<4;i++){
		cipher[i]=tmpInput[i];
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


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;


char* s00;char* s01;char* s02;char* s03;char* s10;char* s11;char* s12;char* s13;
char** k;

//adds the two bit strings and return the result
string addBitStrings( string first, string second );

// Helper method: given two unequal sized bit strings, converts them to
// same length by aadding leading 0s in the smaller string. Returns the
// the new length
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}

// The main function that adds two bit sequences and returns the addition
string addBitStrings( string first, string second )
{
    string result;  // To store the sum bits

    // make the lengths same before adding
    int length = makeEqualLength(first, second);

    int carry = 0;  // Initialize carry

    // Add all bits one by one
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';

        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';

        result = (char)sum + result;

        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    // if overflow, then add a leading 1
    if (carry)
        result = '1' + result;

    return result;
}

char XOR (char a, char b){
	if(a == b)
		return '0';
	return '1';
}

char* XORAll (char a[], char b[]){
	char out4[4], out8[8], out16[16];
	if (sizeof(a) == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if(a[i] == b[i])
				out4[i] = '0';
			else
				out4[i] = '1';
		}
		return out4;
	}
	if (sizeof(a) == 8)
	{
		for (int i = 0; i < 8; i++)
		{
			if(a[i] == b[i])
				out8[i] = '0';
			else
				out8[i] = '1';
		}
		return out8;
	}
	for (int i = 0; i < 16; i++)
	{
		if(a[i] == b[i])
			out16[i] = '0';
		else
			out16[i] = '1';
	}
	return out16;
}

char* mul (char a[], char b[]){
	char out[8];
	for (int i = 0; i < 8; i++)
	{
		if(a[i] == b[i] && a[i] == 1)
			out[i] = '1';
		else
			out[i] = '0';
	}
	return out;
}

void whitening(char* input, char k1[], char k2[], char k3[], char k4[]){
	
	for (int i = 0, j = 0; i < 64; i++, j++)
	{
		input[i] = XOR(input[i], k1[j]);
	}
	for (int i = 64, j = 0; i < 128; i++, j++)
	{
		input[i] = XOR(input[i], k2[j]);
	}
	for (int i = 128, j = 0; i < 192; i++, j++)
	{
		input[i] = XOR(input[i], k3[j]);
	}
	for (int i = 192, j = 0; i < 256; i++, j++)
	{
		input[i] = XOR(input[i], k4[j]);
	}

}

void divideInput(char* input, char* input1, char* input2, char* input3, char* input4){
	
	for (int i = 0, j = 0; i < 64; i++, j++)
	{
		input1[j] = input[i];
	}
	for (int i = 64, j = 0; i < 128; i++, j++)
	{
		input2[j] = input[i];
	}
	for (int i = 128, j = 0; i < 192; i++, j++)
	{
		input3[j] = input[i];
	}
	for (int i = 192, j = 0; i < 256; i++, j++)
	{
		input4[j] = input[i];
	}

}

void mergeOutput(char* input, char* input1, char* input2, char* input3, char* input4){
	
	for (int i = 0, j = 0; i < 64; i++, j++)
	{
		input[i] = input1[j];
	}
	for (int i = 64, j = 0; i < 128; i++, j++)
	{
		input[i] = input2[j];
	}
	for (int i = 128, j = 0; i < 192; i++, j++)
	{
		input[i] = input3[j];
	}
	for (int i = 192, j = 0; i < 256; i++, j++)
	{
		input[i] = input4[j];
	}

}

void swaping(char* input1, char* input2, char* input3, char* input4){
	char temp[64];
	for (int i = 0; i < 64; i++)
	{
		temp[i] = input1[i];
		input1[i] = input3[i];
		input3[i] = temp[i];
	}
	for (int i = 0; i < 64; i++)
	{
		temp[i] = input2[i];
		input2[i] = input4[i];
		input4[i] = temp[i];
	}

}

void circularRightShift(char* input, int n){
	n = n % 64;
	for (int i = 0; i < n; i++)
	{
		char t = input[63];
		for (int j = 63; j > 0; j--)
		{
			input[j] = input[j-1];
		}
		input[0] = t;
	}
}

void circularLeftShift(char* input, int n){
	n = n % 64;
	for (int i = 0; i < n; i++)
	{
		char t = input[0];
		for (int j = 0; j < 64; j++)
		{
			input[j] = input[j+1];
		}
		input[63] = t;
	}
}

char* RightShift(char input[], int n){
	n = n % 4;
	for (int i = 0; i < n; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			input[j] = input[j-1];
		}
		input[0] = 0;
	}
	return input;
}

char* LeftShift(char input[], int n){
	n = n % 4;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			input[j] = input[j+1];
		}
		input[3] = 0;
	}
	return input;
}

//MDS Matrix
char* MDS(char* a, char* b){
	char* y0;
	char* y1;
	char* y2;
	char* y3;
	for (int i = 0; i < 8; i++)
	{
		y0[i] = a[i];
		y1[i] = a[i+8];
		y2[i] = b[i];
		y3[i] = b[i+8];
	}

	y0 = XORAll(XORAll(mul("00000001", y0), mul("11101111", y1)),
		XORAll(mul("01011011", y2), mul("01011011", y3))); 
	y1 = XORAll(XORAll(mul("01011011", y0), mul("11101111", y1)),
		XORAll(mul("11101111", y2), mul("00000001", y3))); 
	y0 = XORAll(XORAll(mul("11101111", y0), mul("01011011", y1)),
		XORAll(mul("00000001", y2), mul("11101111", y3))); 
	y0 = XORAll(XORAll(mul("11101111", y0), mul("00000001", y1)),
		XORAll(mul("11101111", y2), mul("01011011", y3))); 

	for (int i = 0; i < 8; i++)
	{
		a[i] = y0[i];
		a[i+8] = y1[i];
		b[i] = y2[i];
		b[i+8] = y3[i];
	}
	char* output;
	for (int i = 0; i < 16; i++){
		output[i] = a[i];
		output[i+16] = b[i];
	}

	return output;
}

char* t(char* input, int r, int qn){

	if(qn == 0){
		if(r == 0){
			if(strcmp(input, "0000") == 0){return "1000";}
			else if(strcmp(input, "0001") == 0){return "0001";}
			else if(strcmp(input, "0010") == 0){return "0111";}
			else if(strcmp(input, "0011") == 0){return "1101";}
			else if(strcmp(input, "0100") == 0){return "0110";}
			else if(strcmp(input, "0101") == 0){return "1111";}
			else if(strcmp(input, "0110") == 0){return "0011";}
			else if(strcmp(input, "0111") == 0){return "0010";}
			else if(strcmp(input, "1000") == 0){return "0000";}
			else if(strcmp(input, "1001") == 0){return "1011";}
			else if(strcmp(input, "1010") == 0){return "0101";}
			else if(strcmp(input, "1011") == 0){return "1001";}
			else if(strcmp(input, "1100") == 0){return "1110";}
			else if(strcmp(input, "1101") == 0){return "1100";}
			else if(strcmp(input, "1110") == 0){return "1010";}
			else if(strcmp(input, "1111") == 0){return "0100";}
		}
		else if(r == 1){
			if(strcmp(input, "0000") == 0){return "1110";}
			else if(strcmp(input, "0001") == 0){return "1100";}
			else if(strcmp(input, "0010") == 0){return "1011";}
			else if(strcmp(input, "0011") == 0){return "1000";}
			else if(strcmp(input, "0100") == 0){return "0001";}
			else if(strcmp(input, "0101") == 0){return "0010";}
			else if(strcmp(input, "0110") == 0){return "0011";}
			else if(strcmp(input, "0111") == 0){return "0101";}
			else if(strcmp(input, "1000") == 0){return "1111";}
			else if(strcmp(input, "1001") == 0){return "0100";}
			else if(strcmp(input, "1010") == 0){return "1010";}
			else if(strcmp(input, "1011") == 0){return "0110";}
			else if(strcmp(input, "1100") == 0){return "0111";}
			else if(strcmp(input, "1101") == 0){return "0000";}
			else if(strcmp(input, "1110") == 0){return "1001";}
			else if(strcmp(input, "1111") == 0){return "1101";}
		}
		else if(r == 2){
			if(strcmp(input, "0000") == 0){return "1011";}
			else if(strcmp(input, "0001") == 0){return "1010";}
			else if(strcmp(input, "0010") == 0){return "0101";}
			else if(strcmp(input, "0011") == 0){return "1110";}
			else if(strcmp(input, "0100") == 0){return "0110";}
			else if(strcmp(input, "0101") == 0){return "1101";}
			else if(strcmp(input, "0110") == 0){return "1001";}
			else if(strcmp(input, "0111") == 0){return "0000";}
			else if(strcmp(input, "1000") == 0){return "1100";}
			else if(strcmp(input, "1001") == 0){return "1000";}
			else if(strcmp(input, "1010") == 0){return "1111";}
			else if(strcmp(input, "1011") == 0){return "0011";}
			else if(strcmp(input, "1100") == 0){return "0010";}
			else if(strcmp(input, "1101") == 0){return "0100";}
			else if(strcmp(input, "1110") == 0){return "0111";}
			else if(strcmp(input, "1111") == 0){return "0001";}
		}
		else if(r == 3){
			if(strcmp(input, "0000") == 0){return "1101";}
			else if(strcmp(input, "0001") == 0){return "0111";}
			else if(strcmp(input, "0010") == 0){return "1111";}
			else if(strcmp(input, "0011") == 0){return "0100";}
			else if(strcmp(input, "0100") == 0){return "0001";}
			else if(strcmp(input, "0101") == 0){return "0010";}
			else if(strcmp(input, "0110") == 0){return "0110";}
			else if(strcmp(input, "0111") == 0){return "1110";}
			else if(strcmp(input, "1000") == 0){return "1001";}
			else if(strcmp(input, "1001") == 0){return "1011";}
			else if(strcmp(input, "1010") == 0){return "0011";}
			else if(strcmp(input, "1011") == 0){return "0000";}
			else if(strcmp(input, "1100") == 0){return "1000";}
			else if(strcmp(input, "1101") == 0){return "0101";}
			else if(strcmp(input, "1110") == 0){return "1100";}
			else if(strcmp(input, "1111") == 0){return "1010";}
		}
	}
	else if(qn == 1){
		if(r == 0){
			if(strcmp(input, "0000") == 0){return "0010";}
			else if(strcmp(input, "0001") == 0){return "1000";}
			else if(strcmp(input, "0010") == 0){return "1011";}
			else if(strcmp(input, "0011") == 0){return "1101";}
			else if(strcmp(input, "0100") == 0){return "1111";}
			else if(strcmp(input, "0101") == 0){return "0111";}
			else if(strcmp(input, "0110") == 0){return "0110";}
			else if(strcmp(input, "0111") == 0){return "1110";}
			else if(strcmp(input, "1000") == 0){return "0011";}
			else if(strcmp(input, "1001") == 0){return "0001";}
			else if(strcmp(input, "1010") == 0){return "1001";}
			else if(strcmp(input, "1011") == 0){return "0100";}
			else if(strcmp(input, "1100") == 0){return "0000";}
			else if(strcmp(input, "1101") == 0){return "1010";}
			else if(strcmp(input, "1110") == 0){return "1100";}
			else if(strcmp(input, "1111") == 0){return "0101";}
		}
		else if(r == 1){
			if(strcmp(input, "0000") == 0){return "0001";}
			else if(strcmp(input, "0001") == 0){return "1110";}
			else if(strcmp(input, "0010") == 0){return "0010";}
			else if(strcmp(input, "0011") == 0){return "1011";}
			else if(strcmp(input, "0100") == 0){return "0100";}
			else if(strcmp(input, "0101") == 0){return "1100";}
			else if(strcmp(input, "0110") == 0){return "0011";}
			else if(strcmp(input, "0111") == 0){return "0111";}
			else if(strcmp(input, "1000") == 0){return "0110";}
			else if(strcmp(input, "1001") == 0){return "1101";}
			else if(strcmp(input, "1010") == 0){return "1010";}
			else if(strcmp(input, "1011") == 0){return "0101";}
			else if(strcmp(input, "1100") == 0){return "1111";}
			else if(strcmp(input, "1101") == 0){return "1001";}
			else if(strcmp(input, "1110") == 0){return "0000";}
			else if(strcmp(input, "1111") == 0){return "1000";}
		}
		else if(r == 2){
			if(strcmp(input, "0000") == 0){return "0100";}
			else if(strcmp(input, "0001") == 0){return "1100";}
			else if(strcmp(input, "0010") == 0){return "0111";}
			else if(strcmp(input, "0011") == 0){return "0101";}
			else if(strcmp(input, "0100") == 0){return "0001";}
			else if(strcmp(input, "0101") == 0){return "0110";}
			else if(strcmp(input, "0110") == 0){return "1001";}
			else if(strcmp(input, "0111") == 0){return "1010";}
			else if(strcmp(input, "1000") == 0){return "0000";}
			else if(strcmp(input, "1001") == 0){return "1110";}
			else if(strcmp(input, "1010") == 0){return "1101";}
			else if(strcmp(input, "1011") == 0){return "1000";}
			else if(strcmp(input, "1100") == 0){return "0010";}
			else if(strcmp(input, "1101") == 0){return "1011";}
			else if(strcmp(input, "1110") == 0){return "0011";}
			else if(strcmp(input, "1111") == 0){return "1111";}
		}
		else if(r == 3){
			if(strcmp(input, "0000") == 0){return "1011";}
			else if(strcmp(input, "0001") == 0){return "1001";}
			else if(strcmp(input, "0010") == 0){return "0101";}
			else if(strcmp(input, "0011") == 0){return "0001";}
			else if(strcmp(input, "0100") == 0){return "1100";}
			else if(strcmp(input, "0101") == 0){return "0011";}
			else if(strcmp(input, "0110") == 0){return "1101";}
			else if(strcmp(input, "0111") == 0){return "1110";}
			else if(strcmp(input, "1000") == 0){return "0110";}
			else if(strcmp(input, "1001") == 0){return "0100";}
			else if(strcmp(input, "1010") == 0){return "0111";}
			else if(strcmp(input, "1011") == 0){return "1111";}
			else if(strcmp(input, "1100") == 0){return "0010";}
			else if(strcmp(input, "1101") == 0){return "0000";}
			else if(strcmp(input, "1110") == 0){return "1000";}
			else if(strcmp(input, "1111") == 0){return "1010";}
		}
	}
}

char* q(char* input, int n){
	char* a;
	char* b;
	char* c;
	char* d;
	for (int i = 0; i < 4; i++)
	{
		a[i] = input[i];
		b[i] = input[i+4];
		c[i] = input[i+8];
		d[i] = input[i+12];
	}
	// first round => a,b | c,d
	a = XORAll(a,b);
	c = XORAll(c,d);
	b = XORAll(b, XORAll(RightShift(b, 1), LeftShift(a, 3)));
	d = XORAll(d, XORAll(RightShift(d, 1), LeftShift(c, 3)));

	a = t(a, 0, n);
	b = t(b, 1, n);
	c = t(c, 0, n);
	d = t(d, 1, n);

	a = XORAll(a,b);
	c = XORAll(c,d);
	b = XORAll(b, XORAll(RightShift(b, 1), LeftShift(a, 3)));
	d = XORAll(d, XORAll(RightShift(d, 1), LeftShift(c, 3)));

	a = t(a, 2, n);
	b = t(b, 3, n);
	c = t(c, 2, n);
	d = t(d, 3, n);
	////////////////////////////
	// second round => a,c | b,d
	a = XORAll(a,c);
	b = XORAll(b,d);
	c = XORAll(c, XORAll(RightShift(c, 1), LeftShift(a, 3)));
	d = XORAll(d, XORAll(RightShift(d, 1), LeftShift(b, 3)));

	a = t(a, 0, n);
	c = t(c, 1, n);
	b = t(b, 0, n);
	d = t(d, 1, n);

	a = XORAll(a,c);
	b = XORAll(b,d);
	c = XORAll(c, XORAll(RightShift(c, 1), LeftShift(a, 3)));
	d = XORAll(d, XORAll(RightShift(d, 1), LeftShift(b, 3)));

	a = t(a, 2, n);
	c = t(c, 3, n);
	b = t(b, 2, n);
	d = t(d, 3, n);
	///////////////////////////
	// third round => a,d | b,c
	a = XORAll(a,d);
	c = XORAll(c,b);
	d = XORAll(d, XORAll(RightShift(d, 1), LeftShift(a, 3)));
	b = XORAll(b, XORAll(RightShift(b, 1), LeftShift(c, 3)));

	a = t(a, 0, n);
	d = t(d, 1, n);
	c = t(c, 0, n);
	b = t(b, 1, n);

	a = XORAll(a,d);
	c = XORAll(c,b);
	d = XORAll(d, XORAll(RightShift(d, 1), LeftShift(a, 3)));
	b = XORAll(b, XORAll(RightShift(b, 1), LeftShift(c, 3)));

	a = t(a, 2, n);
	d = t(d, 3, n);
	c = t(c, 2, n);
	b = t(b, 3, n);
	/////////////////////////////
	for (int i = 0; i < 4; i++)
	{
		input[i+12] = a[i];
		input[i+8] = b[i];
		input[i+4] = c[i];
		input[i] = d[i];
	}
	return input;
}

void g(char* input){
	//Input fragmentation
	char is0[16], is1[16], is2[16], is3[16];
	for (int i = 0; i < 16; i++){
		is0[i] = input[i];
		is1[i] = input[i+16];
		is2[i] = input[i+32];
		is3[i] = input[i+48];
	}

	char* s0 = q(XORAll(q(XORAll(q(is0, 0),s00), 0),s10), 1);
	char* s1 = q(XORAll(q(XORAll(q(is1, 1),s01), 0),s11), 0);
	char* s2 = q(XORAll(q(XORAll(q(is2, 0),s02), 1),s12), 1);
	char* s3 = q(XORAll(q(XORAll(q(is3, 1),s03), 1),s13), 0);

	MDS(s0, s1);
	MDS(s2, s3);

}

void f(char input1[64], char input2[64], char* input3, char* input4, char* k1, char* k2){

	g(input1);

	circularLeftShift(input2, 8);
	g(input2);

	//PHT step
	char t[65];
	strncpy(t,addBitStrings(input1, input2).c_str(),65);
	for (int i = 64; i > 0 ; i--)
	{
		input1[i] = t[i];
	}
	strncpy(t,addBitStrings(input1, input2).c_str(),65);
	for (int i = 64; i > 0 ; i--)
	{
		input2[i] = t[i];
	}

	//XOR with round key
	for (int i = 0; i < 64; i++)
	{
		input1[i] = XOR(input1[i], k1[i]);
		input2[i] = XOR(input2[i], k2[i]);
	}

	circularLeftShift(input4, 1);

	//XOR After function f
	for (int i = 0; i < 64; i++)
	{
		input3[i] = XOR(input3[i], input1[i]);
		input4[i] = XOR(input4[i], input2[i]);
	}

	circularRightShift(input3, 1);
}

void makeS(char* M){
	char m[32][8];
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j  < 8; j++)
		{
			m[i][j] = M[i*32 + j];
		}
	}
	s00 = XORAll(XORAll(XORAll(mul("00000001", m[0]), mul("10100100", m[1])),
		XORAll(mul("01010101", m[2]), mul("10000111", m[3]))),
		XORAll(XORAll(mul("01011010", m[4]), mul("01011000", m[5])),
		XORAll(mul("11011011", m[6]), mul("10011110", m[7]))));
	s01 = XORAll(XORAll(XORAll(mul("10100100", m[0]), mul("01010110", m[1])),
		XORAll(mul("10000010", m[2]), mul("11110011", m[3]))),
		XORAll(XORAll(mul("00011110", m[4]), mul("11000110", m[5])),
		XORAll(mul("01101000", m[6]), mul("11100101", m[7]))));
	s02 = XORAll(XORAll(XORAll(mul("00000010", m[0]), mul("10100001", m[1])),
		XORAll(mul("11111100", m[2]), mul("11000001", m[3]))),
		XORAll(XORAll(mul("01000111", m[4]), mul("10101110", m[5])),
		XORAll(mul("00111101", m[6]), mul("00011001", m[7]))));
	s03 = XORAll(XORAll(XORAll(mul("10100100", m[0]), mul("01010101", m[1])),
		XORAll(mul("10000111", m[2]), mul("01011010", m[3]))),
		XORAll(XORAll(mul("01011000", m[4]), mul("11011011", m[5])),
		XORAll(mul("10011110", m[6]), mul("00000011", m[7]))));

	s10 = XORAll(XORAll(XORAll(mul("00000001", m[8]), mul("10100100", m[9])),
		XORAll(mul("01010101", m[10]), mul("10000111", m[11]))),
		XORAll(XORAll(mul("01011010", m[12]), mul("01011000", m[13])),
		XORAll(mul("11011011", m[14]), mul("10011110", m[15]))));
	s11 = XORAll(XORAll(XORAll(mul("10100100", m[8]), mul("01010110", m[9])),
		XORAll(mul("10000010", m[10]), mul("11110011", m[11]))),
		XORAll(XORAll(mul("00011110", m[12]), mul("11000110", m[13])),
		XORAll(mul("01101000", m[15]), mul("11100101", m[15]))));
	s12 = XORAll(XORAll(XORAll(mul("00000010", m[8]), mul("10100001", m[9])),
		XORAll(mul("11111100", m[10]), mul("11000001", m[11]))),
		XORAll(XORAll(mul("01000111", m[12]), mul("10101110", m[13])),
		XORAll(mul("00111101", m[14]), mul("00011001", m[15]))));
	s13 = XORAll(XORAll(XORAll(mul("10100100", m[8]), mul("01010101", m[9])),
		XORAll(mul("10000111", m[10]), mul("01011010", m[11]))),
		XORAll(XORAll(mul("01011000", m[12]), mul("11011011", m[13])),
		XORAll(mul("10011110", m[14]), mul("00000011", m[15]))));

	s00 = strcat(s00, XORAll(XORAll(XORAll(mul("00000001", m[16]), mul("10100100", m[17])),
		XORAll(mul("01010101", m[18]), mul("10000111", m[19]))),
		XORAll(XORAll(mul("01011010", m[20]), mul("01011000", m[21])),
		XORAll(mul("11011011", m[22]), mul("10011110", m[23])))));
	s01 = strcat(s01, XORAll(XORAll(XORAll(mul("10100100", m[16]), mul("01010110", m[17])),
		XORAll(mul("10000010", m[18]), mul("11110011", m[19]))),
		XORAll(XORAll(mul("00011110", m[20]), mul("11000110", m[21])),
		XORAll(mul("01101000", m[22]), mul("11100101", m[23])))));
	s02 = strcat(s02, XORAll(XORAll(XORAll(mul("00000010", m[16]), mul("10100001", m[17])),
		XORAll(mul("11111100", m[18]), mul("11000001", m[19]))),
		XORAll(XORAll(mul("01000111", m[20]), mul("10101110", m[21])),
		XORAll(mul("00111101", m[22]), mul("00011001", m[23])))));
	s03 = strcat(s03, XORAll(XORAll(XORAll(mul("10100100", m[16]), mul("01010101", m[17])),
		XORAll(mul("10000111", m[18]), mul("01011010", m[19]))),
		XORAll(XORAll(mul("01011000", m[20]), mul("11011011", m[21])),
		XORAll(mul("10011110", m[22]), mul("00000011", m[23])))));

	s10 = strcat(s10, XORAll(XORAll(XORAll(mul("00000001", m[24]), mul("10100100", m[25])),
		XORAll(mul("01010101", m[26]), mul("10000111", m[27]))),
		XORAll(XORAll(mul("01011010", m[28]), mul("01011000", m[29])),
		XORAll(mul("11011011", m[30]), mul("10011110", m[31])))));
	s11 = strcat(s11, XORAll(XORAll(XORAll(mul("10100100", m[24]), mul("01010110", m[25])),
		XORAll(mul("10000010", m[26]), mul("11110011", m[27]))),
		XORAll(XORAll(mul("00011110", m[28]), mul("11000110", m[29])),
		XORAll(mul("01101000", m[30]), mul("11100101", m[31])))));
	s12 = strcat(s12, XORAll(XORAll(XORAll(mul("00000010", m[24]), mul("10100001", m[25])),
		XORAll(mul("11111100", m[26]), mul("11000001", m[27]))),
		XORAll(XORAll(mul("01000111", m[28]), mul("10101110", m[29])),
		XORAll(mul("00111101", m[30]), mul("00011001", m[31])))));
	s13 = strcat(s13, XORAll(XORAll(XORAll(mul("10100100", m[24]), mul("01010101", m[25])),
		XORAll(mul("10000111", m[26]), mul("01011010", m[27]))),
		XORAll(XORAll(mul("01011000", m[28]), mul("11011011", m[29])),
		XORAll(mul("10011110", m[30]), mul("00000011", m[31])))));
		
}

void makeK(char* key){
	//Input fragmentation
	char m00[16], m01[16], m02[16], m03[16];
	char m10[16], m11[16], m12[16], m13[16];
	char m20[16], m21[16], m22[16], m23[16];
	char m30[16], m31[16], m32[16], m33[16];

	for (int i = 0; i < 16; i++){
		m00[i] = key[i];m01[i] = key[i+16];m02[i] = key[i+32];m03[i] = key[i+48];
		m10[i] = key[i+64];m31[i] = key[i+64+16];m12[i] = key[i+64+32];m13[i] = key[i+64+48];
		m10[i] = key[i+128];m31[i] = key[i+128+16];m12[i] = key[i+128+32];m13[i] = key[i+128+48];
		m10[i] = key[i+192];m31[i] = key[i+192+16];m12[i] = key[i+192+32];m13[i] = key[i+192+48];
	}
	char* input1;char* input2;
	for (int i = 0; i < 20; i++)
	{
		char* t1;char* t2;
		t1 = i==0 ? "0000000000000000" : i==1 ? "0000001000000010" : i==2 ? "0000010000000100" : i==3 ? "0000011000000110" : i==4 ? "0000100000001000" :
			i==5 ? "0000101000001010" : i==6 ? "0000110000001100" : i==7 ? "0000111000001110" : i==8 ? "0001000000010000" : i==9 ? "0001001000010010" : 
			i==10 ? "0001010000010100" : i==11 ? "0001011000010110" : i==12 ? "0001100000011000" : i==13 ? "0001101000011010" : i==14 ? "0001110000011100" : 
			i==15 ? "0001111000011110" : i==16 ? "0010000000100000" : i==17 ? "0010001000100010" : i==18 ? "0010010000100100" : i==19 ? "0010011000100110" : "0010100000101000";
		
		t2 = i==0 ? "0000000100000001" : i==1 ? "0000001100000011" : i==2 ? "0000010100000101" : i==3 ? "0000011100000111" : i==4 ? "0000100100001001" :
			i==5 ? "0000101100001011" : i==6 ? "0000110100001101" : i==7 ? "0000111100001111" : i==8 ? "0001000100010001" : i==9 ? "0001001100010011" : 
			i==10 ? "0001010100010101" : i==11 ? "0001011100010111" : i==12 ? "0001100100011001" : i==13 ? "0001101100011011" : i==14 ? "0001110100011101" : 
			i==15 ? "0001111100011111" : i==16 ? "0010000100100001" : i==17 ? "0010001100100011" : i==18 ? "0010010100100101" : i==19 ? "0010011100100111" : "0010100000101000";

		//first fragment
		char* s0 = q(XORAll(q(XORAll(q(t1, 0),m20), 0),m00), 1);
		char* s1 = q(XORAll(q(XORAll(q(t1, 1),m21), 0),m01), 0);
		char* s2 = q(XORAll(q(XORAll(q(t1, 0),m22), 1),m02), 1);
		char* s3 = q(XORAll(q(XORAll(q(t1, 1),m23), 1),m03), 0);
		input1 = MDS(s0, s1);
		input1 = strcat(input1, MDS(s2, s3));

		//second fragment
		char* s4 = q(XORAll(q(XORAll(q(t2, 0),m30), 0),m10), 1);
		char* s5 = q(XORAll(q(XORAll(q(t2, 1),m31), 0),m11), 0);
		char* s6 = q(XORAll(q(XORAll(q(t2, 0),m32), 1),m12), 1);
		char* s7 = q(XORAll(q(XORAll(q(t2, 1),m33), 1),m13), 0);
		input2 = MDS(s4, s5);
		input2 = strcat(input2, MDS(s6, s7));
		circularLeftShift(input2, 8);

		//PHT step
		char t[65];
		strncpy(t,addBitStrings(input1, input2).c_str(),65);
		for (int i = 64; i > 0 ; i--)
		{
			input1[i] = t[i];
		}
		strncpy(t,addBitStrings(input1, input2).c_str(),65);
		for (int i = 64; i > 0 ; i--)
		{
			input2[i] = t[i];
		}

		strcpy(k[2*i], input1);
		circularLeftShift(input2, 9);
		strcpy(k[2*i + 1], input2);
	}

}

int main(){

	//// Select your mode

	//printf("Encryption Mode: Enter 0\n");
	//printf("Decryption Mode: Enter 1\n");
	int m;
	//scanf("%d", &m);
	// Encrption Mode
	//if(m != 1){ 
		printf("Encryption Mode: Please enter your input:\n");
		char input[256], output[256], key[256];
		scanf("%s", &input);
		printf("Encryption Mode: Please enter your key:\n");
		scanf("%s", &key);

		makeS(key);
		makeK(key);
		//Input Whitening
		whitening(input, k[0], k[1], k[2], k[3]);
		//printf("%s\n", input);
		char input1[64], input2[64], input3[64], input4[64];//Define input fragments

		divideInput(input, input1, input2, input3, input4); //Initiate input fragments
		
		for (int i = 0; i < 16; i++)
		{
			f(input1, input2, input3, input4,k[2*i],k[2*i+1]);
			swaping(input1, input2, input3, input4);//Swaping Fragments for next round

			printf("Round #%d Output:\n%s%s%s%s", (i+1), input1, input2, input3, input4);
		}
		
		mergeOutput(output, input1, input2, input3, input4);
		// Output Whitening
		whitening(input, k[4], k[5], k[6], k[7]);
	//}
//	else
	//{
		//printf("Decryption Mode: Please enter your input:\n");
	//}

	return 0;
}
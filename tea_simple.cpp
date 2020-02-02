#include <iostream>
#include <list>
#include <array>
#include <cstdint>
using namespace std;

void encrypt(uint32_t v[2], uint32_t k[4]);
uint32_t toEncrypt(uint32_t l, uint32_t r);

int main (void) {
	
//	uint32_t key[4] = {2,4,6,8};

//	uint32_t left[5], right[5];	

	struct plainLR {
		uint32_t l;
		uint32_t r;
	};

	struct plainLR pairs[5];

	for(int i=0; i<5; i++){
		pairs[i].l = (rand() % 100)+1 ;
		pairs[i].r = (rand() % 100)+1;
	}

	printf("Plaintext Pairs: \n");
	for (int i=0; i<5; i++){
		printf(" %u %u ", pairs[i].l, pairs[i].r);
		toEncrypt(pairs[i].l, pairs[i].r);
	}
	printf("Ciphertext Pairs: \n");
	for (int i=0; i<5; i++){
//		toEncrypt(pairs[i].l, pairs[i].r);
	}


}

uint32_t toEncrypt(uint32_t l, uint32_t r){
	uint32_t key[4] = {2,4,6,8};
	uint32_t plainLR[2] = {l,r};
	encrypt(plainLR, key);
//	return plainLR;
}

void encrypt(uint32_t v[2], uint32_t k[4]) {
	uint32_t l = v[0], r = v[1], sum = 0, delta = 0x9e3779b9;
	for (int i=0; i<1; i++) {
		sum += delta;
		l += ((r<<4)+k[0]) ^ (r+sum) ^ ((r>>5)+k[1]);
		r += ((l<<4)+k[2])^(l+sum)^((l>>5)+k[3]);
	}
	v[0] = l; v[1] = r;
	printf("%u %u \n", v[0], v[1]);
}



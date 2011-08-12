
// Binary helpers
#define CBIT(word,bit_number)	word &= ~(0x01 << bit_number)
#define SBIT(word,bit_number)   word |= (1<< bit_number)
#define TBIT(word,bit_number)	word ^= (1 << bit_number)
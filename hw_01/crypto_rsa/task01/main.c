#include <stdio.h>
#include <openssl/bn.h>


#define p_in "F7E75FDC469067FFDC4E847C51F452DF"
#define q_in "E85CED54AF57E53E092113E62F436F4F"
#define e_in "0D88C3"


void print_bn(char *msg, BIGNUM *a)
{
	char *num_str = BN_bn2hex(a);
	printf("%s %s\n", msg, num_str);
	OPENSSL_free(num_str);
}

void print_key_bn(char *msg, BIGNUM *pair_one, BIGNUM *pair_two)
{
	char *pair_one_str = BN_bn2hex(pair_one);
	char *pair_two_str = BN_bn2hex(pair_two);

	printf("%s: (%s, %s)\n", msg, pair_one_str, pair_two_str);
	OPENSSL_free(pair_one_str);
	OPENSSL_free(pair_two_str);
}

int main()
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *p = NULL, *q = NULL, *e = NULL;
	BIGNUM *one = NULL;
	BIGNUM *res = BN_new();

	BN_hex2bn(&p, p_in);
	BN_hex2bn(&q, q_in);
	BN_hex2bn(&e, e_in);
	BN_hex2bn(&one, "1");

	print_bn("p: ", p);
	print_bn("q: ", q);
	print_bn("e: ", e);

	BIGNUM *p_sub_1 = BN_new();
	BIGNUM *q_sub_1 = BN_new();
	BIGNUM *totient = BN_new();

	BN_sub(p_sub_1, p, one);
	BN_sub(q_sub_1, q, one);
	BN_mul(totient, p_sub_1, q_sub_1, ctx);
	print_bn("totient: ", totient);

	BIGNUM *d = BN_new();
	d = BN_mod_inverse(d, e, totient, ctx);
	print_key_bn("Private Key", e, d);

	BN_free(totient);
	BN_free(q_sub_1);
	BN_free(p_sub_1);
	BN_free(one);
	BN_free(p);
	BN_free(q);
	BN_free(e);
	BN_CTX_free(ctx);	

	return 0;
}

CC=gcc

hexToBase64:
	$(CC) -o hexToBase64 hex_to_base64.c ../helpers/base64.c -lcrypto

fixedXor:
	$(CC) -o fixedXor fixed_xor.c ../helpers/hex.c

singleByteXor:
	$(CC) -o singleByteXor single_byte_xor.c

clean:
	rm -f hexToBase64 fixedXor singleByteXor


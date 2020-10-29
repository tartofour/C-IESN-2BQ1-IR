#include <stdio.h>

void caesar_encrypt(char plaintext[], int rot)
{
    int i = 0;

    while (*(plaintext + i) != '\0')
    {
    	*(plaintext + i) += rot;
	    i++;
    }
}

int main(void)
{
    char message[] = {"Il faut rafraichir les maquignons"};

    printf("Plaintext : %s\n", message);
    caesar_encrypt(message, 13);
    printf("Ciphertext : %s\n", message);
    caesar_encrypt(message, -13);
    printf("Plaintext : %s\n", message);

}

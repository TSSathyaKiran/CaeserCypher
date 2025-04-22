#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encrypt(int key, char *text, char *encryptedtext);
void decrypt(int key, char *text, char *decryptedtext);

int main(){

    char text[100], decryptedtext[100], encryptedtext[100]; 
    int key;
    printf("Enter the string to encrypot: ");
    scanf("%s", text);

    printf("Enter the shift key: ");
    scanf("%d", &key);

    encrypt(key, text, encryptedtext);
    printf("Encrypted Text: %s", encryptedtext);

    decrypt(key, text, decryptedtext);
    printf("Decrypted Text: %s", decryptedtext);

    return 0;
}

void encrypt(int key, char *text, char *encryptedtext){
    
    char ch;
    for(int i = 0; text[i] != '\0'; i++){

        ch = text[i];

        if(isupper(ch)){
            ch = (ch - 'A' - key + 26) % 26 + 'A';}
        if(islower(ch)){
            ch = (ch - 'a' - key + 26) % 26 + 'a';}
            
        encryptedtext[i] = ch;
    }

    encryptedtext[strlen(text)] = '\0';
}


void decrypt(int key, char *text, char *decryptedtext){
    encrypt(-key, text, decryptedtext);
}
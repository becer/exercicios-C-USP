#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao que concatena strings
char* concatenateStrings(char* str1, char* str2){
    int tamanho_total = strlen(str1) + strlen(str2) + 1;
    char *ptr = (char*)malloc(tamanho_total * sizeof(char));
    if(ptr == NULL){
        return NULL;
    }
    else{
    strcpy(ptr, str1);
    strcat(ptr, str2);
    }
    return ptr;
}
//funcao que processa o texto
char* processText(char* word1, char* word2, char* separator){
    char* temp = concatenateStrings(word1, separator);
    char* ptr = concatenateStrings(temp, word2);
    free(temp);
    return ptr;
}
int main() {
    //le os inputs
    char firstWord[50];
    char secondWord[50];
    char connector[50];
    
    fgets(firstWord, 50, stdin);
    firstWord[strcspn(firstWord, "\n")] = '\0';
    
    fgets(secondWord, 50, stdin);
    secondWord[strcspn(secondWord, "\n")] = '\0';
    
    fgets(connector, 50, stdin);
    connector[strcspn(connector, "\n")] = '\0';
    
    char* phrase = processText(firstWord, secondWord,connector);
    //chama a funcao e printa parametros 
    if(phrase != NULL){
        printf("Result: %s\n", phrase);   
        printf("Length: %zu\n", strlen(phrase));
        free(phrase);
    }
    else{
        printf("Memory allocation failed\n");
    }


    return 0;
}
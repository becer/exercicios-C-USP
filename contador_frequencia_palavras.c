#include <stdio.h>
#include <string.h>

//funcao extractWord
int extractWord(char* sentence, int startIndex, char* word){
    int index = startIndex;
    int index_base = 0;
    
    while(sentence[index] != ' ' && sentence[index] != '\0')
    {
        word[index_base] = sentence[index]; 
        index++;
        index_base++;
    }
    word[index_base] = '\0';
    return index;
}

//funcao countWordOccurrences
int countWordOccurrences(char* sentence, char* targetWord){
    
    int word_repited = 0;
    char word_extracted[100];
    int index = 0;

    //le cada caractere de uma string ate achar uma quebra
    while(sentence[index] != '\0'){
        index = extractWord(sentence, index, word_extracted);
        //compara se a string concatenada e igual a palavra procurada
        if(strcmp(word_extracted, targetWord) == 0){
            word_repited++;
        }
        while(sentence[index] == ' '){
            index++;
        }
            
    }
    return word_repited;
}
    

//funcao analyzeText
int analyzeText(char* sentence){
    int words_inSentence = 0;
    int index = 0;
    char word[500];
    while(sentence[index] != '\0'){
        index = extractWord(sentence, index, word);
        words_inSentence++;

        while(sentence[index] == ' '){
            index++;
        }
    }
    return words_inSentence;
}
int main() {
    char inputSentence[200];
    char searchWord[50];
    
    //le o input
    fgets(inputSentence, sizeof(inputSentence), stdin);
    //remove newline char se existir
    inputSentence[strcspn(inputSentence, "\n")] = '\0';
    
    //le a palavra procurada
    scanf("%s", searchWord);
    
    
    // chama analyzeText e armazena o numero total de palavras
    int totalWords = analyzeText(inputSentence);
    //chama countWordOccurrences e armazena ocorrencias
    int occurrences = countWordOccurrences(inputSentence, searchWord);
    //calcula a porcentagem da frequencia
    double frequency = (double)occurrences/totalWords * 100;
    //determina a categoria da frequencia
    char* category;
    if(frequency == 0.0){
        category = "Not found";
    }
    else if(frequency < 20.0){
        category = "Rare";
    }
    else if(frequency <= 50.0){
        category = "Common";
    }
    else{
        category = "Frequent";
    }
    //printa o output
    printf("Total words: %d\n", totalWords);
    printf("Occurrences of '%s': %d\n", searchWord, occurrences);
    printf("Frequency: %.1f%%\n", frequency);
    printf("Category: %s\n", category);
    
    return 0;
}
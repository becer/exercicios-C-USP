#include <stdio.h>

int main() {
    int num_row = 0;
    int num_col = 0;
    int num;
    int found_3 = 0;

    while(found_3 == 0){
        num_row++;
        num_col = 0;
        
        while(1){
            scanf("%d", &num);
            num_col++;

            if(num == 3){
                found_3 = 1;
                break;
            }
            if(getchar () == '\n'){
                break;
            }
        }
    }
    
    
    printf("%d %d", num_row, num_col);

    return 0;
};
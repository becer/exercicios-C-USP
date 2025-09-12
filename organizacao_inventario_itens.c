#include <stdio.h>
#include <string.h>

//define o struct do Product
typedef struct Product{
    char name[30];
    float price;
    int stock;
}Product;
//funcao findMostExpensive
int findMostExpensive(struct Product arr[], int size){
    int index = 0;
    float maximum = arr[0].price;
    for(int i = 0; i < size; i++){
        if(arr[i].price > maximum){
            maximum = arr[i].price;
            index = i;
        }
    }
    return index;
}
//funcao calculateTotalValue 
float calculateTotalValue(Product arr[], int size){
    float total_value = 0.0;
    for(int i = 0; i < size; i++){
        total_value += arr[i].price * arr[i].stock;
    }
    return total_value; 
}
//funcao findLowStock 
int findLowStock(Product arr[], int size, int threshold){
    int product_under_threshold = 0;
    for(int i = 0; i < size; i++){
        if(arr[i].stock < threshold){
            product_under_threshold += 1;
        }
    }    
    return product_under_threshold;
}

int main() {
    //cria array para 3 produtos
    //da para implementar do usuario definir a quantidade de produtos a serem criados
    struct Product inventory[3];
    
    //le o input para cada produto
    for (int i = 0; i < 3; i++) {
        scanf("%s", inventory[i].name);
        scanf("%f", &inventory[i].price);
        scanf("%d", &inventory[i].stock);
    }
    
    //printa a informacao de cada produto
    for(int i = 0; i < 3; i++){
        printf("Product %d: %s - Price: %.2lf, Stock: %d\n", i, inventory[i].name, inventory[i].price, inventory[i].stock);
    }
    //acha e printa o produto mais caro
    int index = findMostExpensive(inventory, 3);
    printf("Most expensive product: %s\n", inventory[index].name);
    //calcula e printa o valor total do estoque
    float total_value = calculateTotalValue(inventory, 3);
    printf("Total inventory value: %.2f\n", total_value);
    //le o limite do estoque
    int threshold;
    scanf("%d", &threshold);
    
    //acha e printa produtos com estoque baixo
    int products_lowStock = findLowStock(inventory, 3, threshold);
    printf("Products with low stock: %d\n", products_lowStock);
    //ve se o produto mais caro ta bem estocado
    if(inventory[index].stock > 10){
        printf("Most expensive product is well stocked\n");
    }
    else{
        printf("Most expensive product needs restocking\n");

        
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


struct card_t{
    char value;
    char color;
};

void insert_deck(FILE* file, struct card_t* deck){
	char tmp;

}


int get_value(struct card_t card){
	int value;

	if(card.value == 'J') value = 10;
	if(card.value == 'Q') value = 12;
	if(card.value == 'K') value = 15;
	if(card.value == 'A') value = 20;
	if(card.value >= '1' || card.value <= '9') value = card.value - 48;


	return value;
}

int get_color(struct card_t card){
	int value;

	if(card.color == 'C') value = 1;
	if(card.color == 'D') value = 2;
	if(card.color == 'H') value = 3;
	if(card.color == 'S') value = 4;

	return value;
}






int main()
{
    char* fname = malloc(sizeof(char) * 10);


	printf("file :\n");
	fgets(fname, 10, stdin);


	FILE* deck = fopen(fname, "r");



    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct card_t {
    char value;
    char color;
};

int main()
{

    FILE* fp;
    char file_name[64];
    char ch;

    struct card_t deck[52];

    printf("enter file name:\n");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if(fp == NULL){
        printf(" file does not exist");
        return 0;
    }

    // get cards
    int count = 0;
    char value;
    char color;
    int card_counter = 0;
    while((ch = fgetc(fp)) != EOF){
      if(count == 0){
        value = ch;
      }

      if(count == 2){
        color = ch;
        deck[card_counter].value = value;
        deck[card_counter].color = color;
        card_counter++;
      }

      count++;
      if(count == 4){
        count = 0;
      }
    }

    // deal cards
    struct card_t player1[13];
    struct card_t player2[13];
    struct card_t player3[13];
    struct card_t player4[13];

    int card_deal_count = 0;
    int card_deal_cycle = 0;

    for(int i = 0; i < 52; i++){
        if(card_deal_count == 0){
            player1[card_deal_cycle] = deck[i];
        }
        if(card_deal_count == 1){
            player2[card_deal_cycle] = deck[i];
        }
        if(card_deal_count == 2){
            player3[card_deal_cycle] = deck[i];
        }
        if(card_deal_count == 3){
            player4[card_deal_cycle] = deck[i];
        }
        card_deal_count++;
        if(card_deal_count == 4){
            card_deal_cycle++;
            card_deal_count = 0;
        }
    }

    int sum_p1 = 0;
    int value_p1;

    for(int i = 0; i < 13; i++){
        switch(player1[i].value){
		case 'J':
			value_p1 = 10;
			break;
		case 'Q':
			value_p1 = 12;
			break;
		case 'K':
			value_p1= 15;
			break;
		case 'A':
			value_p1 = 20;
			break;
		default:
			value_p1 = player1[i].value - 48;
        }
        sum_p1 = sum_p1 + value_p1;
    }

    int sum_p2 = 0;
    int value_p2;

    for(int i = 0; i < 13; i++){
        switch(player2[i].value){
		case 'J':
			value_p2 = 10;
			break;
		case 'Q':
			value_p2 = 12;
			break;
		case 'K':
			value_p2= 15;
			break;
		case 'A':
			value_p2 = 20;
			break;
		default:
			value_p2 = player2[i].value - 48;
        }
        sum_p2 = sum_p2 + value_p2;
    }

    int sum_p3 = 0;
    int value_p3;

    for(int i = 0; i < 13; i++){
        switch(player3[i].value){
		case 'J':
			value_p3 = 10;
			break;
		case 'Q':
			value_p3 = 12;
			break;
		case 'K':
			value_p3= 15;
			break;
		case 'A':
			value_p3 = 20;
			break;
		default:
			value_p3 = player3[i].value - 48;
        }
        sum_p3 = sum_p3 + value_p3;
    }

    int sum_p4 = 0;
    int value_p4;

    for(int i = 0; i < 13; i++){
        switch(player4[i].value){
		case 'J':
			value_p4 = 10;
			break;
		case 'Q':
			value_p4 = 12;
			break;
		case 'K':
			value_p4= 15;
			break;
		case 'A':
			value_p4 = 20;
			break;
		default:
			value_p4 = player4[i].value - 48;
        }
        sum_p4 = sum_p4 + value_p4;
    }

    int all_sums[4] = {sum_p1, sum_p2, sum_p3, sum_p4};

    int max = all_sums[0];
    int max_index;
    int stop = 0;

    for(int i = 1; i < 4; i++){
        if(max == all_sums[i]){
            stop = 1;
        }
        if(max < all_sums[i]){
            max = all_sums[i];
            max_index = i;
        }
    }
    printf("stop - %d\n",stop);

    int color_p1;
    int sum_color_p1 = sum_p1;
    for(int i = 0; i < 13; i++){
        switch(player1[i].color){
		case 'C':
			color_p1 = 1;
			break;
		case 'D':
			color_p1 = 2;
			break;
		case 'H':
			color_p1 = 3;
			break;
		case 'S':
			color_p1 = 4;
			break;
        }
        sum_color_p1 = sum_color_p1 + color_p1;
    }

    int color_p2;
    int sum_color_p2 = sum_p2;

    for(int i = 0; i < 13; i++){
        switch(player2[i].color){
		case 'C':
			color_p2 = 1;
			break;
		case 'D':
			color_p2 = 2;
			break;
		case 'H':
			color_p2 = 3;
			break;
		case 'S':
			color_p2 = 4;
			break;
        }
        sum_color_p2 = sum_color_p2 + color_p2;
    }

    int color_p3;
    int sum_color_p3 = sum_p3;
    for(int i = 0; i < 13; i++){
        switch(player3[i].color){
		case 'C':
			color_p3 = 1;
			break;
		case 'D':
			color_p3 = 2;
			break;
		case 'H':
			color_p3 = 3;
			break;
		case 'S':
			color_p3 = 4;
			break;
        }
        sum_color_p3 = sum_color_p3 + color_p3;
    }

    int color_p4;
    int sum_color_p4 = sum_p4;
    for(int i = 0; i < 13; i++){
        switch(player4[i].color){
		case 'C':
			color_p4 = 1;
			break;
		case 'D':
			color_p4 = 2;
			break;
		case 'H':
			color_p4 = 3;
			break;
		case 'S':
			color_p4 = 4;
			break;
        }
        sum_color_p4 = sum_color_p4 + color_p4;
    }

    int array_colors[4] = {sum_color_p1,sum_color_p2,sum_color_p3,sum_color_p4};

    int max_color = all_sums[0];
    int max_color_index;

    for(int i = 1; i < 4; i++){
        if(max_color < array_colors[i]){
            max_color = array_colors[i];
            max_color_index = i;
        }
    }


    if(stop == 1){
        printf("player %d won\n", max_color_index + 1);
    }
    if(stop == 0){
        printf("player %d won\n", max_index + 1);
    }

    return 0;
}

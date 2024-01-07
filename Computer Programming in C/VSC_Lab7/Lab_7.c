#include <stdio.h>
#include <string.h>

int decidePlayer(int player_number);
void readFile(FILE *file, int player_number);
void outcome(int player_number, double batting_average, int hits, int official_bats);

int main() {
    int player_number;
    printf("Enter the player's number: ");
    scanf("%d", &player_number);
    FILE *file = fopen("player_batting.txt", "r");
    readFile(file, player_number);
    fclose(file);
    return 0;
}

void readFile(FILE *file, int player_number) {
    int hits = 0;
    int hits_and_outs;
    char position[50];
    while (fgets(position, 100, file)) {
        for (int i = 0; i < strlen(position); i++) {
            if (position[i] == 'H') {
                hits++;
            }
            if ((position[i] == 'H') || (position[i] == 'O')) {
                hits_and_outs++;
            }
        }
        double batting_average = (double) hits / hits_and_outs;
        outcome(player_number, batting_average, hits, hits_and_outs);
    }
    fclose(file);
}

void outcome(int player_number, double batting_average, int hits, int official_bats) {
    printf("Player %d\nOfficial At-Bats: %d\nHits: %d\nBatting Average: %.3lf\n", 
    player_number, official_bats, hits, batting_average);
}
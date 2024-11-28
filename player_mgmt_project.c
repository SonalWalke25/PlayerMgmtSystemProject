#include <stdio.h>
#include <string.h>

// Define a struct to store information about each player
typedef struct PlayerInfo {
    int jerseyNumber;     // Player's jersey number
    char name[20];        // Player's name
    int runs;             // Total runs scored by the player
    int wickets;          // Total wickets taken by the player
    int matches;          // Number of matches played by the player
} Player;

// Function prototypes for various operations
void addPlayer(Player*, int);
void removePlayer(Player*, int*);
void searchPlayer(Player*, int);
void updatePlayerData(Player*, int);
void displayAllPlayers(Player*, int);
void displaySortedPlayers(Player*, int);
int searchByJerseyNumber(Player*, int, int);
int searchByName(Player*, int, char*);
void sortPlayersByRuns(Player*, int, int);
void sortPlayersByWickets(Player*, int, int);
void displayTopPlayers(Player*, int);

int main() {
    int size = 10; // Maximum number of players that can be added
    Player players[size]; // Array to store player information
    int count = 3;  // Start with 3 players, as we have hardcoded their details below

   

    int choice; // Variable to store user's choice in the menu

    printf("\n\n||======Cricket Player Management System Project======||\n\n");

    // Menu-driven program
    do {
        // Display options for the user to choose from
        printf("\n1. Add Player\n2. Remove Player\n3. Search Player\n4. Update Player Data\n5. Display All Players\n6. Display Sorted Players\n7. Display Top 3 Players");
        printf("\n0. Exit\n\nEnter your choice:");
        scanf("%d", &choice);

        // Execute corresponding function based on the user's choice
        switch(choice) {
            case 1:
                // Check if there's space for more players
                if (count >= size) {
                    printf("\nNo more space to add players.\n");
                } else {
                    addPlayer(players, count); // Add a player at the current index
                    count++; // Increment the total player count
                }
                break;
            case 2:
                removePlayer(players, &count); // Remove a player
                break;
            case 3:
                searchPlayer(players, count); // Search for a player
                break;
            case 4:
                updatePlayerData(players, count); // Update player data
                break;
            case 5:
                displayAllPlayers(players, count); // Display all players' details
                break;
            case 6:
                displaySortedPlayers(players, count); // Display sorted player list
                break;
            case 7:
                displayTopPlayers(players, count); // Display top 3 players
                break;
            case 0:
                printf("Exiting...\n"); // Exit message
                break;
            default:
                printf("Invalid choice! Try again.\n"); // Error message for invalid input
                break;
        }
    } while(choice != 0); // Repeat until user chooses to exit

    return 0;
}

// Function to add a player to the array
void addPlayer(Player* players, int i) {
    printf("\nEnter Jersey Number: ");
    scanf("%d", &players[i].jerseyNumber); // Input jersey number
    
    printf("Enter Player Name: ");
    scanf("%s", players[i].name); // Input player name

    printf("Enter Runs: ");
    scanf("%d", &players[i].runs); // Input runs scored

    printf("Enter Wickets: ");
    scanf("%d", &players[i].wickets); // Input wickets taken

    printf("Enter Matches Played: ");
    scanf("%d", &players[i].matches); // Input matches played

    printf("\nPlayer added successfully.\n");
}

// Function to remove a player by jersey number
void removePlayer(Player* players, int* count) {
    int jerseyNumber;
    printf("\nEnter Jersey Number of the player to remove: ");
    scanf("%d", &jerseyNumber); // Input the jersey number of the player to remove

    // Find the index of the player with the given jersey number
    int index = searchByJerseyNumber(players, *count, jerseyNumber);
    if (index == -1) { // Check if player is not found
        printf("\nPlayer not found!\n");
        return;
    }
    
    // Shift all players after the removed player to the left to fill the gap
    for (int i = index; i < *count - 1; i++) {
        players[i] = players[i + 1];
    }
    (*count)--; // Decrement the player count
    printf("\nPlayer removed successfully.\n");
}

// Function to search for a player by jersey number or name
void searchPlayer(Player* players, int count) {
    int choice;
    printf("\n1. Search by Jersey Number\n2. Search by Name\nEnter your choice: ");
    scanf("%d", &choice); // Input choice for search type
    
    if (choice == 1) {
        int jerseyNumber;
        printf("\nEnter Jersey Number: ");
        scanf("%d", &jerseyNumber); // Input jersey number to search

        // Search by jersey number
        int index = searchByJerseyNumber(players, count, jerseyNumber);
        if (index != -1) { // If player is found, print details
            printf("\nJersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",
                   players[index].jerseyNumber, players[index].name, players[index].runs,
                   players[index].wickets, players[index].matches);
        } else {
            printf("\nPlayer not found!\n");
        }
    } else if (choice == 2) {
        char name[20];
        printf("\nEnter Player Name: ");
        scanf("%s", name); // Input name to search

        // Search by name
        int index = searchByName(players, count, name);
        if (index != -1) { // If player is found, print details
            printf("\nJersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",
                   players[index].jerseyNumber, players[index].name, players[index].runs,
                   players[index].wickets, players[index].matches);
        } else {
            printf("\nPlayer not found!\n");
        }
    } else {
        printf("\nInvalid choice!\n");
    }
}

// Function to update a player's data
void updatePlayerData(Player* players, int count) {
    int jerseyNumber;
    printf("\nEnter Jersey Number of the player to update: ");
    scanf("%d", &jerseyNumber); // Input jersey number of the player to update

    // Find the index of the player to update
    int index = searchByJerseyNumber(players, count, jerseyNumber);
    if (index == -1) { // Check if player is not found
        printf("\nPlayer not found!\n");
        return;
    }
    
    // Update player stats
    printf("Enter new Runs: ");
    scanf("%d", &players[index].runs); // Update runs
    printf("Enter new Wickets: ");
    scanf("%d", &players[index].wickets); // Update wickets
    printf("Enter new Matches Played: ");
    scanf("%d", &players[index].matches); // Update matches

    printf("\nPlayer data updated successfully.\n");
}

// Function to display all players
void displayAllPlayers(Player* players, int count) {
    if (count == 0) { // Check if no players exist
        printf("No players to display.\n");
        return;
    }
    
    // Loop through the players array and print each player's details
    for (int i = 0; i < count; i++) {
        printf("\nJersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d",
               players[i].jerseyNumber, players[i].name, players[i].runs,
               players[i].wickets, players[i].matches);
    }
    printf("\n");
}

// Function to display sorted players by runs or wickets
void displaySortedPlayers(Player* players, int count) {
    int choice, order;
    printf("\nSort by: \n1. Runs\n2. Wickets\nEnter your choice: ");
    scanf("%d", &choice); // Input choice for sorting by runs or wickets
    printf("\n1. Minimum to Maximum\n2. Maximum to Minimum\nEnter order: ");
    scanf("%d", &order); // Input choice for ascending or descending order
    
    // Sort based on choice and order
    if (choice == 1) {
        sortPlayersByRuns(players, count, order == 1);
    } else if (choice == 2) {
        sortPlayersByWickets(players, count, order == 1);
    } else {
        printf("Invalid choice!\n");
        return;
    }
    displayAllPlayers(players, count); // Display sorted players
}

// Helper function to find a player by jersey number
int searchByJerseyNumber(Player* players, int count, int jerseyNumber) {
    for (int i = 0; i < count; i++) {
        if (players[i].jerseyNumber == jerseyNumber) { // Check if jersey number matches
            return i; // Return the index of the player if found
        }
    }
    return -1; // Return -1 if player is not found
}

// Helper function to find a player by name
int searchByName(Player* players, int count, char* name) {
    for (int i = 0; i < count; i++) {
        if (strcasecmp(players[i].name, name) == 0) { // Compare names case-insensitively
            return i; // Return index if player is found
        }
    }
    return -1; // Return -1 if player is not found
}

// Function to sort players by runs in ascending or descending order
void sortPlayersByRuns(Player* players, int count, int ascending) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if ((ascending && players[j].runs > players[j + 1].runs) ||
               (!ascending && players[j].runs < players[j + 1].runs)) {
                // Swap players if they are in the wrong order
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}

// Function to sort players by wickets in ascending or descending order
void sortPlayersByWickets(Player* players, int count, int ascending) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if ((ascending && players[j].wickets > players[j + 1].wickets) ||
               (!ascending && players[j].wickets < players[j + 1].wickets)) {
                // Swap players if they are in the wrong order
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}

// Function to display the top 3 players by runs or wickets
void displayTopPlayers(Player* players, int count) {
    if (count < 3) { // Check if there are fewer than 3 players
        printf("\nThere are fewer than 3 players to display.\n");
        return;
    }

    int choice;
    printf("\nDisplay top 3 players by:\n1. Runs\n2. Wickets\nEnter your choice: ");
    scanf("%d", &choice); // Input choice for displaying top players by runs or wickets

    // Sort players in descending order based on the choice
    if (choice == 1) {
        sortPlayersByRuns(players, count, 0); // Sort by runs in descending order
    } else if (choice == 2) {
        sortPlayersByWickets(players, count, 0); // Sort by wickets in descending order
    } else {
        printf("Invalid choice!\n");
        return;
    }

    // Display the top 3 players
    printf("\nTop 3 players:\n");
    for (int i = 0; i < 3; i++) {
        printf("Jersey Number: %d, Name: %s, Runs: %d, Wickets: %d, Matches: %d\n",
               players[i].jerseyNumber, players[i].name, players[i].runs,
               players[i].wickets, players[i].matches);
    }
}

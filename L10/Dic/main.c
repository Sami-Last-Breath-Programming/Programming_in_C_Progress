#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage" 

int main(void)
{   
    // Create a dictionary 
    Dictionary *data = newDictionary();

    // Add  data to dictionay 
    addEntry(data, newString("Fruits"), newList((String *[]){
        newString("Apple"),
        newString("Mango"),
        newString("Orange"),
    }, 3));

    addEntry(data, newString("Names"), newList((String *[]){
        newString("Sami"),
        newString("Rahul"),
        newString("Noob"),
    }, 3));

    addEntry(data , newString("Cities"), newList((String *[]){
        newString("Delh"),
        newString("New York"),
        newString("London"),
    }, 3));

    addEntry(data , newString("Prayers"), newList((String *[]){
        newString("Adoration"),
        newString("Petition"),
        newString("Intercession"),
    }, 3));

    addEntry(data , newString("Players"), newList((String *[]){
        newString("Achievers"),
        newString("Explorers"),
        newString("Socializers"),
    }, 3));

    addEntry(data , newString("Pickers"), newList((String *[]){
        newString("Street Pickers "),
        newString("Landfill Pickers "),
        newString("Door-To-Door Pickers"),
    }, 3));


    sortDictionary(data);
    
    // Print dictionay 
    printDictionary(data);

    // Free dictionary
    freeDictionary(data);

    return EXIT_SUCCESS;
}   
#pragma clang diagnostic pop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>  // For opendir(), readdir(), and closedir()
#include "player.h"
#include "game.h"
#include "room.h"
#include "item.h"
#include "creature.h"




int main() {
    srand(time(NULL));
    
    Room *allRooms[12];
    allRooms[0] = initialize_room_with_item(//entrance
    "You stand at the entrance of the dungeon. The air is cold, and the stone walls are ancient, weathered by time. Shadows flicker in the corners, as if something is watching. To the left, a narrow passage leads deeper into the dungeon, and behind you, the entrance seems to beckon you back toward the world outside.",
    "Steel Sword", 0, 0, 1, 15, NULL
);
   
    

 allRooms[1] = initialize_room_with_item(//potion room
    "The room is filled with the scent of herbs and potions. Shelves are lined with glowing vials, their contents shifting like liquid fire. The atmosphere is calm, almost healing. Ahead, a faint mist rises from the floor, beckoning you forward to the unknown, while the path you came from is now silent, calling you back.",
    "Health Potion", 40, 1, 0, 0, NULL
);


 allRooms[2] = initialize_room_with_item(//mists
    "A thick mist fills the room, making it hard to see clearly. The air is damp and heavy with magic. The faint light that cuts through the fog illuminates strange symbols on the walls. A cold breeze whispers from one side, urging you to move towards it, while the silence behind you feels like it holds long-forgotten secrets.",
    "Book of the Lovers' Bond", 0, 0, 0, 0,
    "The powerful ruler of the dungeon King Fyonir, fell in love with a woman, Lyra. Lyra was not from the dungeon. Fyonir and Lyra were met in a village when Lyra was selling fruits. Fyonir was very interested when he first saw \"Pomegranate\" sign. It was the fruit all beloved mother Thalira loved.\nThat was how they met.\nTheir love was pure and full but over time, jealousy and doubt twisted king's mind. He killed his own lover, Lyra, the woman of his life! \nThe dungeon fell under a curse and the darkness captured the dungeon day by day. A place of sorrow the dungeon became...  \n"
);


 allRooms[3] = initialize_room_with_item(//gKnight
    "This chamber is massive, with high vaulted ceilings that seem to stretch endlessly. The stone is cold and covered with faded banners of long-dead knights. In the center of the room stands an empty suit of armor, its gaze locked on the far wall. The room feels frozen in time, as if waiting for someone to return. Ahead, a pathway leads into the shadows, promising an unknown challenge.",
    "Royal Knight Sword", 0, 0, 1, 30, NULL
);


 allRooms[4] = initialize_room_with_item(//bloody
    "The floor is stained with dried blood, and the scent of iron fills the air. The walls are pockmarked with evidence of past struggles. A feeling of heaviness permeates the room. The atmosphere is oppressive, and a subtle sound of dripping echoes from somewhere distant. Beyond the room, a faint glow hints at a way forward.",
    "Health Potion", 40, 1, 0, 0, NULL
);


 allRooms[5] = initialize_room_with_item(//quarry
    "This room is filled with the sound of grinding stone. Jagged rocks line the walls, and the uneven floor is littered with debris. The heavy air pulses with ancient energy. The ground seems to vibrate beneath your feet, as if the very dungeon is alive with power. There's a sense that the path forward holds a deep, hidden meaning.",
    "Ultimate Health Potion", 80, 1, 0, 0, NULL
);


 allRooms[6] = initialize_room_with_item(//thalira
    "A large statue of Thalira stands at the center of this room. Her serene face seems to look out over the dungeon, and her stone gaze feels full of quiet wisdom. The room is filled with a sense of reverence, and the atmosphere is thick with the weight of history. A whisper in the air suggests a path leading to a place where ancient decisions were made.",
    "The Betrayal", 0, 0, 0, 0,
    "King Fyonir was an avid person and a jealousy type but every moment he saw Lyra, his whole world were changing. His heart seemed to soften. \nBut, every moment he saw Lyra, he was thinking that nobody can be this impeccable. He began to believe that Lyra is hiding something, her kindness and pure heart could be for something evil.\nOne fateful night, he started to questioning her, with a fire in his eyes. Lyra was anxious but she trusted Fyonir, she did not expect that her death was going to be by him in the garden of Lovers...\nBut it was real. Fyonir killed her with his blade without a doubt. The purest soul in the dungeon was taken by the one who promised to protect her no matter what...\n"
);


 allRooms[7] = create_room(//chestroom
    "This small, dusty room holds an ancient chest, its wooden surface covered in layers of cobwebs. The air is stale, and a sense of abandonment hangs in the room. The chest seems to hum with hidden power, as if something important lies within. You can't shake the feeling that you should open it, though you hesitate before doing so."
);


 allRooms[8] = initialize_room_with_item(//throne
    "You enter the throne room, once the seat of great power, now in ruins. The throne stands broken and covered in dust, a symbol of lost grandeur. The room is still and cold, the weight of failure pressing down on you. Beyond the ruined seat, the air grows heavy, as though the room itself is grieving. A path leads to the halls of souls, and there’s another way upward into a room where knowledge was once held.",
    "The Iron Legacy", 0, 0, 1, 50, NULL
);


 allRooms[9] = initialize_room_with_item(//library
    "The library is vast, filled with shelves upon shelves of ancient books. The air smells of old parchment, and the faint sound of pages turning can almost be heard in the silence. The walls are lined with tomes that seem to hum with knowledge. Ahead, a stairway leads upward to even older texts, and another path stretches back to the throne room.",
    "The Curse of the King", 0, 0, 0, 0,
    "After Lyra's death, the dungeon halls became silent. The king was on the ragged edge. He was not able to rule anymore.\nBut Thalira was so angry! The dungeon's beloved mother was angry by the betrayal of her daughter! Her anger was enough for all the dungeon people to leave and some to imprison between the walls of the dungeon. Lyra's innocent soul did not haunt the dungeon. Instead, she wept. Her tears filled the Lost Souls Room. \nThe dungeon, now a ruin, remained a place of torment, forever haunted by the memories of lost love and broken hearts... \n"
);


 allRooms[10] = initialize_room_with_item(//lostSouls
    "The Hall of Lost Souls is thick with sorrow. The walls echo faint whispers of forgotten voices. The room feels both endless and suffocating, as if the souls of the past are trapped within the walls. The air is cold and heavy, and there's a deep sense of mourning. One passage leads deeper into the dungeon, where even greater dangers may await.",
    "Ultimate Health Potion", 80, 1, 0, 0, NULL
);

 allRooms[11] = create_room(//depths
    "The Depths are the darkest part of the dungeon. The walls are slick with moisture, and the air is thick with a sense of dread. The very ground beneath your feet seems to groan in protest. This is the heart of the dungeon, where the final challenge awaits. There are no exits from here—only the ultimate confrontation lies ahead."
);



    // Connect rooms
    connect_rooms(allRooms[0], allRooms[1], "left");
    connect_rooms(allRooms[1], allRooms[2], "up");
    connect_rooms(allRooms[2], allRooms[3], "left");
    connect_rooms(allRooms[2], allRooms[4], "right");
    connect_rooms(allRooms[4], allRooms[5], "up");
    connect_rooms(allRooms[5], allRooms[6], "up");
    connect_rooms(allRooms[6], allRooms[8], "up");
    connect_rooms(allRooms[6], allRooms[7], "right");
    connect_rooms(allRooms[8], allRooms[10], "left");
    connect_rooms(allRooms[8], allRooms[9], "up");
    connect_rooms(allRooms[10], allRooms[11], "down");

    // Add creatures to rooms
    allRooms[1]->creature = (Creature *)malloc(sizeof(Creature));
    allRooms[1]->creature->name = strdup("Goblin");
    allRooms[1]->creature->health = 50;
    allRooms[1]->creature->story = strdup("Goblin: Be careful strange... I was here for a reason. The others are not gonna be easy against you...");
    allRooms[1]->creature->strength = 5;

    allRooms[3]->creature = (Creature *)malloc(sizeof(Creature));
    allRooms[3]->creature->name = strdup("The Last Royal Knight");
    allRooms[3]->creature->story = strdup("The Last Royal Knight: You... defeated me? How could this be? I swore an oath to protect the king, but now... the weight of my failure haunts me. What is this force that breaks even the strongest among us?");
    allRooms[3]->creature->health = 150;
    allRooms[3]->creature->strength = 25;

    allRooms[4]->creature = (Creature *)malloc(sizeof(Creature));
    allRooms[4]->creature->name = strdup("Bloody Hands");
    allRooms[4]->creature->health = 75;
    allRooms[4]->creature->story = strdup("Bloody Hands: I never wanted to be the one to stain my hands with blood, but the king's command... it was absolute. But you, stranger... have undone everything I was meant to do. How?!\n");
    allRooms[4]->creature->strength = 10;

    allRooms[5]->creature = (Creature *)malloc(sizeof(Creature));
    allRooms[5]->creature->name = strdup("Stone Golem");
    allRooms[5]->creature->story = strdup("Stone Golem: I have been guarding this place for centuries, a silent witness to the fall of many. But it is not my strength you need to fear... It is the curse of the king's broken heart. For the sake of Thalira! I wish I could move...");
    allRooms[5]->creature->health = 500;
    allRooms[5]->creature->strength = 0;

    allRooms[8]->creature = (Creature *)malloc(sizeof(Creature));
    allRooms[8]->creature->name = strdup("King's Secret Lover");
    allRooms[8]->creature->story = strdup("Secret Lover: You don't understand, do you? It was never about love... It was about power.\n Secret Lover: The king could not bear the thought of losing it, so he... ended it all. Yet, here you are, the last one standing. What is it you seek?");
    allRooms[8]->creature->health = 200;
    allRooms[8]->creature->strength = 30;

    allRooms[9]->creature = (Creature *)malloc(sizeof(Creature));
    allRooms[9]->creature->name = strdup("Thousand Years Old Librarian");
    allRooms[9]->creature->story = strdup("Player: What did you do to be cursed here, old fella?\n Librarian: Oh no, no! *smiles* You got me wrong, friend. I am here because Mother Thalira wants me to be here. I am here to protect the library from strangers.\nPlayer: Well you seem quite weak to me... \nLibrarian: HAHA! Try and see...\nPlayer: Nah-uh... I respect my elders.\nPlayer: Hey! What about the story of Lyra and King Fyonir? Do you remember it?\nLibrarian: Oh, now I see why you are here, young man! The tale of Lyra and the King... Well, I don't remember or I don't want to remember it. Seek the garden of Lovers if you wish to see more or what should I call?\nLibrarian: Lost Souls...\n ");
    allRooms[9]->creature->health = 250;
    allRooms[9]->creature->strength = 0;

    allRooms[10]->creature = (Creature *)malloc(sizeof(Creature));
    allRooms[10]->creature->name = strdup("Lyra");
    allRooms[10]->creature->story = strdup("Lyra: You have freed me from my prison of sorrow. The dungeon's walls have cried for ages, but now, perhaps... the truth will finally be known. \nLyra: I was not crying and waiting here unpurposed! I was waiting here to somebody know my story. I trusted him purely but I am not a saint... The only thing I want from you to take my avenge!\n Lyra: If you did not see the librarian, you need to see him before going to the Depths of Blackened Dungeon...");
    allRooms[10]->creature->health = 1000;
    allRooms[10]->creature->strength = 0;

    allRooms[11]->creature = (Creature *)malloc(sizeof(Creature));
    allRooms[11]->creature->name = strdup("King Fyonir");
    allRooms[11]->creature->story = strdup("Fyonir: I should have known... You would come. My reign is over, just like my soul. The curse I invoked... is now yours to bear. Tell me, warrior, did you truly think you could escape it?\nPlayer: Mother Thalira hates you! The curse is on you and it was only for you! I will not be cursed!\n");
    allRooms[11]->creature->health = 400;
    allRooms[11]->creature->strength = 50;

     


    // Initialize player at the entrance
    Player *player = create_player(allRooms[0]);
    
    


    // Start the game loop
    game_loop(player);

    // Free allocated memory
    free_player(player);
    free_room(allRooms[0]);
    free_room(allRooms[1]);
    free_room(allRooms[2]);
    free_room(allRooms[3]);
    free_room(allRooms[4]);
    free_room(allRooms[5]);
    free_room(allRooms[6]);
    free_room(allRooms[7]);
    free_room(allRooms[8]);
    free_room(allRooms[9]);
    free_room(allRooms[10]);
    free_room(allRooms[11]);

    return 0;
}

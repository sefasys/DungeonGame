# DungeonGame
It is the dungeon game homework...
Let me describe the game I created.
The game has some special functionalities except the tutor wanted such as reading a book, changing swords etc.
There are different swords, different creatures some of them wants to fight against you some of them just need to be patient.
But the most important part is the story.
This story is what I really tried to create. By reading books and dialogues with the creatures will help you to understand the mini-story of King Fyonir and his lover Lyra.

The game can be easily compiled by make beacause I created the Makefile.

This game has these functions:

move <direction: up, down, left, right>: This function helps the player to change rooms.
look: This function helps player to interact with the room and give some description of the room and where to go after, the items that are in the room... 
inventory: This function shows the items that player has in the inventory. In inventory, you can store swords, potions, books. 
commands: this function is for reminding what to 
pickup <itemname>: As the tutor wanted, this is the function how you can pickup the item and see it in your inventory.
read: If you have a book in your inventory by typing read you can see the books you have in your inventory in a numbered way. Then you select a number and you read the book. It's that easy! 
delete: This is for the items that you want to delete from your inventory.
equip: This is for the sword and basically it has the same functionality with reading function. You pick up the sword(if there is a sword in the room that you are in) then type equip then there it
shows the 
interact: This function starts the interaction with a creature. If a creature is hostile you have to choose attack option, if it is not hostile then you can try to defuse them to communicate with them.
This function is iterative and it goes until the fight ends or you defuse the creature.
list: list function shows the games that you saved in your directory.
save <file>: It is for saving a file. This helps user to save the game for playing the game later.
load <file>: It is for loading a game. This helps user to load the game and start where they left last time.
exit: It is for exiting the game. If you want to exit just type "exit" to close the game.

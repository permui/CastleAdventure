# CLI Game: Castle Adventure

This is the CLI game as project #2 of my *Object Oriented Programming (C++)* course. I took the course in 2021 Spring & Summer semester as a sophomore in ZJU.

## The Game

It may be a cliché story that some monsters have trapped the princess in a castle and you the warrior are going to rescue her. However, some modern elements such as BitCoins and teleportation makes it even more cliché. Anyway, the princess is under threat and you are at the entry of the castle.

At each step, your current state will be shown and there would be descriptions for your current circumstances. A list of commands will be given and you are to type in one of them to proceed.

There is a shop in the castle and you can buy weapons to fight monsters. There are several challenges prepared for you to earn BitCoins for shopping. There is even a teleporter hide in the castle which can transport you to a random place in the castle.

Explore the castle and rescue the princess, warrior!

## How to Build

The simplest way to build is to run the `compile.sh` to compile all the C++ source codes together.

Alternatively, you can use the `Makefile` if you want faster build under modification.

The above two ways are designed for Linux bash and would result in an executable named `game`. If you cannot run them (you are using Windows or other OS, for example), you can just compile all the `.cpp`s with a C++ compiler yourself.

Run the executable and start the adventure!

## About the Implementation

One thing that I am proud of this implementation is the use of some functional programming ideas, although this is a project in an OOP course :) .

The basic idea is simple: the castle and the player constitute the **state** of the game and **functions** operate on the state to proceed the game. For example, when you type `go_left` at the entry of the castle, it selects the specific function to go to the left grid from a bunch of functions, and that go left function acts on the player and change its position. This is to say, my program is **not** composed of a chain of if-else clauses and some global variables, **but** composed of several command-function mappings and a concise state.

The following is an example takes out from `genmap.cpp` that implements the castle story. This piece specifies the entry of the castle.

```c++
{
	{1, 0},
	GT::None,
	"entry",
	("This is the entry of the castle.\n"
	"If you want to quit, just type \"quit\".\n"
	"If you think you have successfully rescued the princess, claim \"success\".\n"
	"Or just go_left to enter the castle."),
	{
		{"quit", [](Player& player, Grid&, Map&)->void {
			player.pos = QUIT_POS;
		}},
		{"success", [](Player &player, Grid&, Map&)->void {
			if (player.with_princess) {
				cout << "Rescue princess successful!" << endl;
				player.pos = SUCC_POS;
			} else {
				cout << "You don't have princess with you???" << endl;
			}
		}},
		{"go_left", Goto<1, 1>}
	}
}
```

Fancy! It looks like JavaScript in some sense, but it *is* C++.

Welcome to read my code and any comments or advices will be appreciated!
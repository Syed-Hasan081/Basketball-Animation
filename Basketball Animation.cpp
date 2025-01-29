//Syed Hasan - Final project

#include <iostream>
#include <time.h>
using namespace std;
void IntroScreen();
void WinningScreen();
void LosingScreen();


string CLS = "\033[2J\033[1;1H";
string Red = "\033[31;1m";
string Green = "\033[32;1m";
string Yellow = "\033[33;1m";
string Blue = "\033[34;1m";
string Purple = "\033[35;1m";
string Cyan = "\033[36;1m";
string White = "\033[37;1m";
string Default = "\033[0m"; // default gray color & reset background to black

int main()
{
    srand(time(NULL));
    //step 1 - intro/loser/winner win (game, time, name) - do this last bc easiest
    IntroScreen();
    //step 2 - select SecretPhrase (string variable)
    string Phrases[10] = {"lakers", "bulls", "warriors", "pistons", "suns", "nuggets", "bucks", "clippers", "blazers", "heat"}; 
    string SecretPhrase = Phrases[rand()%5];
    //step 3 - create GuessPhrase put dots or dashes 
    string GuessPhrase = SecretPhrase;
    for(int i=0; i<GuessPhrase.size();i++)
    {
        if (GuessPhrase[i] != ' ')
            GuessPhrase[i] = '-';
    }
    //step 4 - declare variables
    string LettersRemaining = "abcdefghijklmnopqrstuvwxyz";
    int Found, Location, BadGuesses = 0;
    string Letter;
    //step 5 - game loop
    while (GuessPhrase != SecretPhrase && BadGuesses < 6)//change to 11
    {
        cout << CLS;
        if (BadGuesses == 0)
            {
                cout<< "                                    " << endl;          
                cout<< "       /|                           " << endl;  
                cout<< "       \\|=--                        " << endl;  
                cout<< "          ##.                o        " << endl;  
                cout<< "                              \\\\        " << endl;  
                cout<< "                       /       \\O       " << endl;  
                cout<< "                      O_/       T       " << endl;  
                cout<< "                     T        /|.       " << endl;  
                cout<< "                      |\\      | |       " << endl;  
                cout<< "        _______________|_|________  " << endl;  

            }
        if (BadGuesses == 1)
            {
                cout<< "                                    " << endl;          
                cout<< "       /|                           " << endl;  
                cout<< "       \\|=--               o         " << endl;  
                cout<< "          ##.                o         " << endl;  
                cout<< "                              \\\\        " << endl;  
                cout<< "                       /       \\O       " << endl;  
                cout<< "                      O_/       T       " << endl;  
                cout<< "                     T        /|.       " << endl;  
                cout<< "                      |\\      | |       " << endl;  
                cout<< "        _______________|_|________  " << endl;  
            }
        if (BadGuesses == 2)
            {
                cout<< "                                    " << endl;          
                cout<< "                                    " << endl;          
                cout<< "       /|                 o            " << endl;  
                cout<< "       \\|=--               o         " << endl;  
                cout<< "          ##.                o         " << endl;  
                cout<< "                              \\\\        " << endl;  
                cout<< "                       /       \\O       " << endl;  
                cout<< "                      O_/       T       " << endl;  
                cout<< "                     T        /|.       " << endl;  
                cout<< "                      |\\      | |       " << endl;  
                cout<< "        _______________|_|________  " << endl;  
            }
        if (BadGuesses == 3)
            {
                cout<< "                                    " << endl;          
                cout<< "                        o                " << endl;          
                cout<< "       /|                 o               " << endl;  
                cout<< "       \\|=--               o           " << endl;  
                cout<< "          ##.                o  " << endl;  
                cout<< "                              \\\\        " << endl;  
                cout<< "                       /       \\O       " << endl;  
                cout<< "                      O_/       T       " << endl;  
                cout<< "                     T        /|.       " << endl;  
                cout<< "                      |\\      | |       " << endl;  
                cout<< "        _______________|_|________  " << endl;  
            }
        if (BadGuesses == 4)
            {
                cout<< "                                    " << endl;          
                cout<< "                      o  o             " << endl;          
                cout<< "       /|                  o          " << endl;  
                cout<< "       \\|=--               o         " << endl;  
                cout<< "          ##.                o         " << endl;  
                cout<< "                              \\\\        " << endl;  
                cout<< "                       /       \\O       " << endl;  
                cout<< "                      O_/       T        " << endl;  
                cout<< "                     T        /|.        " << endl;  
                cout<< "                      |\\      | |       " << endl;  
                cout<< "        _______________|_|________   " << endl;  
            }
        if (BadGuesses == 5)
            {
                cout<< "                                    " << endl;          
                cout<< "                   o  o  o                    " << endl;          
                cout<< "       /|                  o              " << endl;  
                cout<< "       \\|=--               o              " << endl;  
                cout<< "          ##.                o               " << endl;  
                cout<< "                              \\\\        " << endl;  
                cout<< "                       /       \\O        " << endl;  
                cout<< "                      O_/       T         " << endl;  
                cout<< "                     T        /|.         " << endl;  
                cout<< "                      |\\      | |        " << endl;  
                cout<< "        _______________|_|________  " << endl;  
            }
        //step 6 - ASCII art where something happens for every wrong answer
        //step 7 - LettersRemaining
        cout << "Letters Remaining: " << Cyan << LettersRemaining << Default << endl;
        cout << "HitPoints:         " << Red << 60-10*BadGuesses;
        cout << endl;
        cout << Default;
        //step 8 - GuessPhrase
        cout << "Phrase to Guess: " << GuessPhrase << endl;
        //step 9 user enter letters and remove from lettersremaining
        cout << "Enter a letter: ";
        cin >> Letter;
        Found = LettersRemaining.find(Letter,0);
        if (Found != -1)
            LettersRemaining.replace(Found,1," ");
        //step 10 - search for letter with secret phrase and replace in guess phrase
        Location = SecretPhrase.find(Letter,0);
        if (Location > SecretPhrase.size())
            BadGuesses++;
        else
            while (Location < SecretPhrase.size())
            {
                GuessPhrase.replace(Location,1,Letter);
                Location = SecretPhrase.find(Letter, Location + 1);
            }
        
    } //end game loop
    //step 11 - winning and losing screens 
    if (BadGuesses == 6)
        LosingScreen();
    else
        WinningScreen();
    return 0;
}
void IntroScreen()
    {
        cout << CLS;
         cout << "   | |__   __ _ ___| | _____| |_| |__   __ _| | |      " << endl;
         cout << "   | '_ \\ / _` / __| |/ / _ \\ __| '_ \\ / _` | | |   " << endl;
         cout << "   | |_) | (_| \\__ \\   <  __/ |_| |_) | (_| | | |     " << endl;
         cout << "    |_.__/ \\__,_|___/_|\\_\\___|\\__|_.__/ \\__,_|_|_| " << endl;
        cout << "Hello! My name is Syed Hasan. Welcome to my game!" << endl;
        cout << "Guess the name of the NBA team!" << endl << endl;
        cout << "Instrucions: You will have six chances to pick the right NBA team, otherwise you will get blocked. Every time you get an answer wrong, your hitpoints will decrease. If the hitpoints reach zero, you lose! Good luck :)" << endl << endl;
        cout << "Press <Enter> to begin";
        cin.ignore();
    }
void WinningScreen()
    {
        cout << Blue; 
        cout<< "         __     ______  _    _  __          _______ _   _ _   " << endl;
        cout<< "         \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | | |  " << endl;
        cout<< "          \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| | |  " << endl;
        cout<< "           \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` | |  " << endl;
        cout<< "            | | | |__| | |__| |    \\  /\  /   _| |_| |\\  |_|  " << endl;
        cout<< "            |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_(_)  " << endl;
                                             
        
        
        
        cout<< "                                            __--__.                          " << endl;
        cout<< "                               -   -___\\____________________               " << endl;
        cout<< "                              |   ||________________________|               " << endl;
        cout<< "                             |   |  | \\|\\|\\|\\|\\|\\|\\\\/\\/\\/\\/|     " << endl;
        cout<< "                             |   | |  |  \\|\\|\\|\\/\\/\\/\\\\/\\/|        " << endl;
        cout<< "                             |   / |  |     \\|\\|/\\/\\/\\/\\/\\|          " << endl;
        cout<< "                             |  | |  |        \\/\\/\\/\\/\\/\\/|           " << endl;
        cout<< "                             |  ||   |         \\/\\/\\/\\/\\/\\\\|          " << endl;
        cout<< "                             |   |   |          \\/\\/\\/\\/\\/\\|          " << endl;
        cout<< "                             |   |   |             \\______/                " << endl;
        cout<< "                             |   |  |                                       " << endl;
        cout<< "                            |    |_ |                                       " << endl;
        cout<< "                           ||    | \\|                                      " << endl;
        cout<< "                          | |    |  \\                                      " << endl;
        cout << "                          | |    |  <                                      " << endl;
        cout<< "                          |/      |  >                                      " << endl;
        cout<< "                          |       | /_                                      " << endl;
        cout<< "                        _/|       | \\ \\                                   " << endl;  
        cout<< "                       /   |    /  \\/\\/                                   " << endl;    
        cout<< "                      |    |   |    \\                                       " << endl;    
        cout<< "                     |               |                                      " << endl;        
        cout<< "                     |               /                                      " << endl;    
        cout<< "                     |              |                                       " << endl;    
        cout<< "                     |             /                                        " << endl;    
        cout<< "                      |            |                                        " << endl;    
        cout<< "                      |           |                                         " << endl;
        cout<< "                       |          |                                         " << endl;
        cout<< "    _________          |         |                                          " << endl;    
        cout<< "             \\         |         |             ___                         " << endl;
        cout<< "    ___       |        |________|          _==    =                         " << endl;    
        cout<< "       \\  ____|        |_________|  _   __==        \\                     " << endl;    
        cout<< "        \\/    |        |          == \\==             \\                   " << endl;
        cout<< "         \\     |       |               \\        _=    \\                  " << endl;      
        cout<< "          |     |     | |               \\    _==  =    \\                  " << endl;
        cout<< "           |     |    |  \\_              \\__=      \\    \\               " << endl;    
        cout<< "            |     |  /     \\__          __\\         \\   \\               " << endl;
        cout<< "            |      ||         \\______===             \\   \\               " << endl;
        cout<< "             |     /\\           /                      |   \\              " << endl;
        cout<< "             |    /  \\__      /                        \\__/\\_  _____     " << endl;    
        cout<< "              |          \\ /                          |      =     \\      " << endl;
        cout<< "               \\         /                             |            |      " << endl;
        cout<< "                 \\_    _/                                \\___________/    " << endl;
        cout<< "                   ===                                                      " << endl;
        cout << Default;
    }
void LosingScreen()
    {
        cout << Purple;
        cout << "                          _______             _        _______  _______  _______  _ " << endl;
        cout << "       |\\     /|(  ___  )|\\     /|  ( \\      (  ___  )(  ____ \\(  ____ \\( )         " << endl;
        cout << "       ( \\   / )| (   ) || )   ( |  | (      | (   ) || (    \\/| (    \\/| |         " << endl;
        cout << "        \\ (_) / | |   | || |   | |  | |      | |   | || (_____ | (__    | |         " << endl;
        cout << "         \\   /  | |   | || |   | |  | |      | |   | |(_____  )|  __)   | |         " << endl;
        cout << "          ) (   | |   | || |   | |  | |      | |   | |      ) || (      (_)         " << endl;
        cout << "         | |   | (___) || (___) |  | (____/\\| (___) |/\\____) || (____/\\ _           " << endl;
        cout << "          \\_/   (_______)(_______)  (_______/(_______)\\_______)(_______/(_)         " << endl << endl << endl;
        
        
        cout<< "   o- - -  \\o          __|     " << endl;
        cout<< "      o/   /|          vv`\\    " << endl;
        cout<< "     /|     |              |   " << endl;
        cout<< "      |    / \\_            |   " << endl;
        cout<< "     / \\   |               |   " << endl;
        cout<< "     /  |                   |  " << endl;
        cout << Default;
    
    }
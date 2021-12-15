#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;

string ToLowerCase(string userInput);
bool GuessInWord(char guess, string GameWord, string& guessWord);
void ChangeGuessWord(char guess, string& guessWord, int index);
void PrintHangMan(int incorrectGuesses);
void StartPrint();

int main() {
    string userInput;
    vector <string> wordList = {"taxation", "yellow", "table", "flag", "automobile", "computer", "jacket", "philosophy", "university", "difficult"};
    string gameWord;
    string guessWord = " ";
    int guessCount;
    int correctGuesses = 0;
    int incorrectGuesses = 0;
    char letterGuess;
    vector <char> notInWord;

    //Print welcome and ask if they would like to play
    StartPrint();
    cout << "Would you like to play?" << endl;
    cout << "Please enter \"yes\" or \"no\"" << endl;

    //Changes input to all lowercase & makes sure input is either "yes" or "no"
    cin >> userInput;
    userInput = ToLowerCase(userInput);
    while (userInput != "yes" && userInput != "no"){
        cout << "Please respond with \"yes\" or \"no\"" << endl;
        cin >> userInput;
        userInput = ToLowerCase(userInput);
    }

    //The game
    while (userInput == "yes") {

        //Chooses a random word & print word length
        srand(time(NULL));
        int randNum = rand() % 10;
        gameWord = wordList.at(randNum);
        guessWord = gameWord;
        for (int i = 0; i < guessWord.size(); ++i) {
            guessWord.at(i) = '_';
        }
        cout << "Great let's play! If you guess incorrectly 7 times, you lose." << endl;
        cout << "The word is " << to_string(gameWord.size()) << " letters long." << endl;

        //Allows user to guess & prints guessed word
        cout << guessWord << endl;
        cout << "Please guess a letter" << endl;
        cin >> letterGuess;
        while (guessWord != gameWord) {
            letterGuess = tolower(letterGuess);

            //If correct guess:
            if (GuessInWord(letterGuess, gameWord, guessWord)) {
                correctGuesses++;
                cout << endl << "Correct! That makes " << correctGuesses << " correct guesses";
                cout << endl << guessWord << endl;

            }

            //If incorrect guess:
            else {
                PrintHangMan(incorrectGuesses);
                cout  << "That letter is not in the word" << endl;
                cout << "You have guessed:" << endl;
                cout << letterGuess << " ";
                for (int i = 0; i < notInWord.size(); ++i) {
                    cout << notInWord.at(i) << " ";
                }
                cout << endl;
                notInWord.push_back(letterGuess);
                incorrectGuesses++;
                cout << "That makes " << incorrectGuesses << " incorrect guesses." << endl;
            }

            //Ends game if user loses
            if (incorrectGuesses == 7){
                cout << "You Lose!" << endl;
                cout << "The word was " << gameWord << endl;
                break;
            }

            //Ends game is user wins
            if (guessWord == gameWord) {
                break;
            }

            //Continues the game
            cout << "Please guess a letter." << endl;
            cin >> letterGuess;
        }

        //Winning message & clears vector for next round & asks user if they would like to play again
        if (guessWord == gameWord){
            guessCount = incorrectGuesses + correctGuesses;
            cout << endl << "You Win! You have correctly guessed the word in " << guessCount << " guesses!" << endl;
        }
        notInWord.clear();
        incorrectGuesses = 0;
        correctGuesses = 0;
        cout << "Would you like to play again? Enter \"yes\" or \"no\"" << endl;
        cin >> userInput;
        ToLowerCase(userInput);
        while (userInput != "yes" && userInput != "no") {
            cout << "Please respond with \"yes\" or \"no\"" << endl;
            cin >> userInput;
            userInput = ToLowerCase(userInput);
        }
    }

    //End message
    cout << setw(23) << setfill('*') << " " << endl;
    cout << "* " << "Thanks for playing" << " *" << endl;
    cout << setw(23) << setfill('*') << " " << endl << endl;
    return 0;
}

string ToLowerCase(string userInput){
    for (int i = 0; i < userInput.size(); ++i){
        userInput.at(i) = tolower(userInput.at(i));
    }
    return userInput;
}

bool GuessInWord(char guess, string gameWord, string& guessWord){
    for (int i = 0; i < gameWord.size(); ++i){
        if (guess == gameWord.at(i)){
            ChangeGuessWord(guess, guessWord, i);
        }
    }
    for (int i = 0; i < gameWord.size(); ++i) {
        if (guess == gameWord.at(i)) {
            ChangeGuessWord(guess, guessWord, i);
            return true;
        }
    }
    return false;
}

void ChangeGuessWord(char guess, string& guessWord, int index){
    guessWord.at(index) = guess;
}

void PrintHangMan(int incorrectGuesses){
    switch(incorrectGuesses) {
        case 0:
            cout << setw(23) << setfill('*') << " " << endl << "*" << setw(21) << setfill(' ') << "*" << endl;
            cout << "*" << "\t" << setw(12) << setfill('_') << "    " << " *" << endl <<
                 "*\t" << "       |     *" << endl << "*\t" << "       |     *" << endl
                 << "*\t" << "       |     *" << endl<< "*\t"
                    << "       |     *" << endl << "*\t" << "       |     *" << endl  << setw(23) <<
                 setfill('*') << " " << endl << setw(23) << setfill('*') << " " << endl <<
                 setw(23) << setfill('*') << " " << endl << endl;
            break;

        case 1:
            cout << setw(23) << setfill('*') << " " << endl << "*" << setw(21) << setfill(' ') << "*" << endl;
            cout << "*" << "\t" << setw(12) << setfill('_') << "    " << " *" << endl <<
                 "*\t" << "O      |     *" << endl << "*\t" << "       |     *" << endl
                 << "*\t" << "       |     *" << endl<< "*\t"
                 << "       |     *" << endl << "*\t" << "       |     *" << endl  << setw(23) <<
                 setfill('*') << " " << endl << setw(23) << setfill('*') << " " << endl <<
                 setw(23) << setfill('*') << " " << endl << endl;
            break;

        case 2:
            cout << setw(23) << setfill('*') << " " << endl << "*" << setw(21) << setfill(' ') << "*" << endl;
            cout << "*" << "\t" << setw(12) << setfill('_') << "    " << " *" << endl <<
                 "*\t" << "O      |     *" << endl << "*\t" << "|      |     *" << endl
                 << "*\t" << "       |     *" << endl<< "*\t"
                 << "       |     *" << endl << "*\t" << "       |     *" << endl  << setw(23) <<
                 setfill('*') << " " << endl << setw(23) << setfill('*') << " " << endl <<
                 setw(23) << setfill('*') << " " << endl << endl;
            break;


        case 3:
            cout << setw(23) << setfill('*') << " " << endl << "*" << setw(21) << setfill(' ') << "*" << endl;
            cout << "*" << "\t" << setw(12) << setfill('_') << "    " << " *" << endl <<
                 "*\t" << "O      |     *" << endl << "*      _" << "|      |     *" << endl
                 << "*\t" << "       |     *" << endl<< "*\t"
                 << "       |     *" << endl << "*\t" << "       |     *" << endl  << setw(23) <<
                 setfill('*') << " " << endl << setw(23) << setfill('*') << " " << endl <<
                 setw(23) << setfill('*') << " " << endl << endl;
            break;

        case 4:
            cout << setw(23) << setfill('*') << " " << endl << "*" << setw(21) << setfill(' ') << "*" << endl;
            cout << "*" << "\t" << setw(12) << setfill('_') << "    " << " *" << endl <<
                 "*\t" << "O      |     *" << endl << "*      _" << "|_     |     *" << endl
                 << "*\t" << "       |     *" << endl<< "*\t"
                 << "       |     *" << endl << "*\t" << "       |     *" << endl  << setw(23) <<
                 setfill('*') << " " << endl << setw(23) << setfill('*') << " " << endl <<
                 setw(23) << setfill('*') << " " << endl << endl;
            break;

        case 5:
            cout << setw(23) << setfill('*') << " " << endl << "*" << setw(21) << setfill(' ') << "*" << endl;
            cout << "*" << "\t" << setw(12) << setfill('_') << "    " << " *" << endl <<
                 "*\t" << "O      |     *" << endl << "*      _" << "|_     |     *" << endl
                 << "*      /" << "       |     *" << endl<< "*\t"
                 << "       |     *" << endl << "*\t" << "       |     *" << endl  << setw(23) <<
                 setfill('*') << " " << endl << setw(23) << setfill('*') << " " << endl <<
                 setw(23) << setfill('*') << " " << endl << endl;
            break;

        case 6:
            cout << setw(23) << setfill('*') << " " << endl << "*" << setw(21) << setfill(' ') << "*" << endl;
            cout << "*" << "\t" << setw(12) << setfill('_') << "    " << " *" << endl <<
                 "*\t" << "O      |     *" << endl << "*      _" << "|_     |     *" << endl
                 << "*      /" << " \\     |     *" << endl<< "*\t"
                 << "       |     *" << endl << "*\t" << "       |     *" << endl  << setw(23) <<
                 setfill('*') << " " << endl << setw(23) << setfill('*') << " " << endl <<
                 setw(23) << setfill('*') << " " << endl << endl;
            break;
    }
}

void StartPrint() {
    cout << setw(23) << setfill('*') << " " << endl << "*" << setw(21) << setfill(' ') << "*" << endl;
    cout << "*" << "\t" << setw(12) << setfill('_') << "    " << " *" << endl <<
         "*\t" << "O      |     *" << endl << "*      _" << "|_     |     *" << endl
         << "*      /" << " \\     |     *" << endl << "*\t"
         << "       |     *" << endl << "*\t" << "       |     *" << endl << setw(23) <<
         setfill('*') << " " << endl;
    cout << "* " << "Welcome to Hangman" << " *" << endl;
    cout << setw(23) << setfill('*') << " " << endl << endl;
}
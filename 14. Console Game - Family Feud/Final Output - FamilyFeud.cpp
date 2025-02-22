#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unistd.h>
#include <iomanip>
using namespace std;

vector<pair<string, int>> highestScorers;

// Helper function to clear the screen
void clearScreen()
{
    system("cls");
}

// Function to display the start menu
void displayMenu()
{
    clearScreen();
    cout << "==============================" << endl;
    cout << "        FAMILY FEUD          " << endl;
    cout << "==============================" << endl;
    cout << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Quit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}

// Function to convert a string to lowercase
string toLowercase(string str)
{
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });
    return str;
}

// Function to play the Family Feud game
void startGame()
{


    clearScreen();
    cout << "==============================" << endl;
    cout << "        FAMILY FEUD          " << endl;
    cout << "==============================" << endl;
    cout << endl;
    sleep(1);
	cout<< "Alright folks, we're back with another exciting round of the Family Feud!" <<endl;
	cout<<"We've got two incredible families ready to battle it out for a chance at the grand prize..."<<endl;
	
	int totalPlayerPoints = 0;
    int totalChallengerPoints = 0;

    // Get family names
    string playerFamily, challengerFamily;
    cout << "\nEnter the name of the Player Family: ";
    getline(cin >> ws, playerFamily);
    cout << "Enter the name of the Challenger Family: ";
    getline(cin >> ws, challengerFamily);
	
    int playerPoints = 0;
    int challengerPoints = 0;
    int playerStrikes = 0;
    int challengerStrikes = 0;

    vector<string> surveyQuestions = {
        "Name a popular fruit.",
        "Name a capital city.",
        "Name a famous actor.",
    };

    vector<vector<string>> surveyAnswers = {
        {"apple", "banana", "orange", "grape", "strawberry"},
        {"london", "paris", "tokyo", "rome", "washington"},
        {"tom hanks", "brad pitt", "leonardo dicaprio", "meryl streep", "jennifer lawrence"},
    };

    srand(time(0)); // Seed the random number generator

    // Round
    vector<vector<pair<string, int>>> answeredAnswers(3, vector<pair<string, int>>(5, make_pair("", 0)));
 	
	 string roundWinner; // Declare roundWinner variable
    int roundPoints; // Declare roundPoints variable
    for (int round = 1; round <= 3; round++)
    {
        clearScreen();
        cout << "==============================" << endl;
        cout << "          ROUND TWISTER " << round << "             " << endl;
        cout << "==============================" << endl;
        cout << endl;
        
		cout<<"Alright folks, this is Round Twister! We've got a real nail-biter going on here for three rounds. \n";
		sleep(1);
        cout<<"I've got three mind-boggling survey questions for you. The host will ask the first question \n";
        sleep(2);
		cout<<"and both families will have to think fast and give their best answers. \n"<<endl;
		sleep(2);
		cout<< "ONLY FIVE CORRECT ANSWERS\n";

        for (int questionIndex = 0; questionIndex < 3; questionIndex++)
        {
			cout<<"\nWe'll start with the " << playerFamily << " Family. Are you ready? \n";
			sleep(2);
			cout<<"Good! Give us your answer, and remember, it's gotta be one of the top responses from the survey.\n";
            cout << "\nHost: " <<" We asked a hundred people - " << surveyQuestions[questionIndex] << endl;
            cout << endl;

            // Player and Challenger answer simultaneously
            cout << "Player Family " << playerFamily << " give an answer: ";
            string playerAnswer;
            getline(cin >> ws, playerAnswer);
			
			
            
            // Convert answers to lowercase for case-insensitive comparison
            playerAnswer = toLowercase(playerAnswer);
            

            // Check if the player's answer is correct
            bool playerAnswerCorrect = false;
            int playerSurveySays = 0;

            if (find_if(answeredAnswers[questionIndex].begin(), answeredAnswers[questionIndex].end(),
                        [&](const pair<string, int> &p) { return playerAnswer == toLowercase(p.first); }) != answeredAnswers[questionIndex].end())
            {
                cout << "Player Family " << playerFamily << " already answered that. Incorrect answer!" << endl;
            }
            else
            {
                for (int i = 0; i < 5; i++)
                {
                    if (playerAnswer == toLowercase(surveyAnswers[questionIndex][i]))
                    {
                        playerAnswerCorrect = true;
                        playerSurveySays = i + 1;
                        answeredAnswers[questionIndex][i] = make_pair(playerAnswer, playerSurveySays * 12);
                        break;
                    }
                }

                if (!playerAnswerCorrect)
                {
                    answeredAnswers[questionIndex].push_back(make_pair(playerAnswer, 0));
                }
            }
            
            cout<<"\nAlright, now it's the "<< challengerFamily << " Family's' turn. Give us your answer, and let's see if you\n"; 
			sleep(2);
			cout<<"can match or even surpass the "<<playerFamily<<"'s response. We're looking for those top survey answers, folks! \n";
            cout << "\nChallenger Family " << challengerFamily << " give an answer: ";
            string challengerAnswer;
            getline(cin >> ws, challengerAnswer);
            
            challengerAnswer = toLowercase(challengerAnswer);

            // Check if the challenger's answer is correct
            bool challengerAnswerCorrect = false;
            int challengerSurveySays = 0;

            if (find_if(answeredAnswers[questionIndex].begin(), answeredAnswers[questionIndex].end(),
                        [&](const pair<string, int> &p) { return challengerAnswer == toLowercase(p.first); }) != answeredAnswers[questionIndex].end())
            {
                cout << "Challenger Family " << challengerFamily << " already answered that. Incorrect answer!" << endl;
            }
            else
            {
                for (int i = 0; i < 5; i++)
                {
                    if (challengerAnswer == toLowercase(surveyAnswers[questionIndex][i]))
                    {
                        challengerAnswerCorrect = true;
                        challengerSurveySays = i + 1;
                        answeredAnswers[questionIndex][i] = make_pair(challengerAnswer, challengerSurveySays * 12);
                        break;
                    }
                }

                if (!challengerAnswerCorrect)
                {
                    answeredAnswers[questionIndex].push_back(make_pair(challengerAnswer, 0));
                }
            }

            // Display survey results
            cout << "\n Host: " << surveyQuestions[questionIndex] << endl;
            cout << endl;
            cout << "Survey says..." << endl;
            cout << playerFamily << ": " << (playerAnswerCorrect ? to_string(playerSurveySays * 12) : "X") << endl;
            cout << challengerFamily << ": " << (challengerAnswerCorrect ? to_string(challengerSurveySays * 12) : "X") << endl;
            cout << endl;

            // Update points and strikes
            if (playerAnswerCorrect)
            {
                playerPoints += playerSurveySays * 12;
            }
            else
            {
                playerStrikes++;
            }

            if (challengerAnswerCorrect)
            {
                challengerPoints += challengerSurveySays * 12;
            }
            else
            {
                challengerStrikes++;
            }

            // Display current score
            cout << "Current Score:" << endl;
            cout << playerFamily << ": " << playerPoints << " points and " << playerStrikes << "/2 strikes" << endl;
            cout << challengerFamily << ": " << challengerPoints << " points and " << challengerStrikes << "/2 strikes" << endl;
            cout << endl;

            // Check if either family has two strikes
            if (playerStrikes == 2 || challengerStrikes == 2)
            {
            	cout<<"The dust has settled 2 STRIKES!!, and we have our winner...\n";
            	sleep(5);
                break;
            }

            // Wait for a moment before proceeding to the next question
            sleep(2);
        }

        // Determine the winner of the round
        string roundWinner;
        int roundPoints;
        if (playerPoints > challengerPoints)
        {
            roundWinner = playerFamily;
            roundPoints = playerPoints;
        }
        else if (challengerPoints > playerPoints)
        {
            roundWinner = challengerFamily;
            roundPoints = challengerPoints;
        }
        else
        {
            roundWinner = "Tie";
            roundPoints = playerPoints;
        }
		if (roundWinner != "Tie" && roundPoints != 0) {
    highestScorers.push_back(make_pair(roundWinner, roundPoints));
}
        // Check if the winner can play the next round
        if (roundWinner == "Tie" || roundPoints == 0)
        {
            cout << "Its a tie!" << endl;
            sleep(5);
            continue;
        }

        // Display round winner
        cout << "Winner of Round " << round << ": " << roundWinner << " with " << roundPoints << " points!" << endl;
        cout << endl;

        // Reset points and strikes for the next round
        playerPoints = 0;
        challengerPoints = 0;
        playerStrikes = 0;
        challengerStrikes = 0;

		if (roundWinner == playerFamily)
        {
            totalPlayerPoints += roundPoints;
        }
        else if(roundWinner == challengerFamily)
        {
            totalChallengerPoints += roundPoints;
        }

        // Wait for a moment before proceeding to the next round
        sleep(5);
    }

    // Display final scores
    clearScreen();
    cout << "==============================" << endl;
    cout << "        ROUND SCORES          " << endl;
    cout << "==============================" << endl;
    cout << endl;
    cout << playerFamily << ": " << totalPlayerPoints << " points" << endl;
    cout << challengerFamily << ": " << totalChallengerPoints << " points" << endl;
    cout << endl;

    // Determine the winner of the game
   string gameWinner;
    int gamePoints;
    if (totalPlayerPoints > totalChallengerPoints) {
        gameWinner = playerFamily;
        gamePoints = totalPlayerPoints;
    } else if(totalChallengerPoints > totalPlayerPoints) {
        gameWinner = challengerFamily;
        gamePoints = totalChallengerPoints;
    }
	cout << "Winner of the game: " << gameWinner << " with " << gamePoints << " points!" << endl;
	cout<<"Loading...";
   	sleep(7);
	sort(highestScorers.begin(), highestScorers.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
});

clearScreen();
cout << "==============================" << endl;
cout << "   HIGHEST SCORERS PER ROUND  " << endl;
cout << "==============================" << endl;
cout << endl;
cout << "Rank\t\tWinner\t\tPoints" << endl;
cout << "--------------------------------" << endl;
for (int i = 0; i < highestScorers.size(); i++) {
    cout << i + 1 << "\t\t" << highestScorers[i].first << "\t\t" << highestScorers[i].second << endl;
}
 	cout << endl;
    cout << "Loading...";
	sleep(10);
	
   clearScreen();
    cout << "==============================" << endl;
    cout << "        FAMILY FEUD          " << endl;
    cout << "==============================" << endl;
    cout << endl;
    sleep(1);
    cout << "Congratulations! " << gameWinner <<" You have won the game and earned the chance to play the Fast Money round!" << endl;
    cout << endl;
    sleep(2);
    cout << "Here's how the Fast Money round works:" << endl;
    cout << "1. The host will ask you five survey questions." << endl;
    cout << "2. You need to provide the top answer for each question." << endl;
    cout << "3. You have a limited amount of time to answer each question." << endl;
    cout << "4. Your goal is to reach a total of 200 points or more to win the grand prize!" << endl;
    cout << endl;
    sleep(15);

    vector<string> fastMoneyQuestions = {
        "Name a popular vacation destination.",
        "Name a famous superhero.",
        "Name a type of food you can't live without.",
        "Name a popular TV show.",
        "Name a hobby or pastime."
    };
    
    vector<vector<string>> surveyFastMoney = {
        {"Hawaii", "Paris", "Bali", "New York", "Maldives"},
        {"SpiderMan", "Superman", "Batman", "Wonder Woman", "Iron Man"},
        {"Pizza", "Chocolate", "Ice cream", "Sushi", "Burgers"},
        {"Friends", "Game of Thrones", "Breaking Bad", "Stranger Things", "The Big Bang Theory"},
        {"Reading", "Gardening", "Painting", "Playing sports", "Cooking"}
    };

    vector<vector<int>> fastMoneyPoints = {
        {53, 43, 34, 25, 10},
        {50, 41, 30, 24, 19},
        {45, 37, 35, 29, 17},
        {43, 38, 20, 18, 19},
        {46, 30, 29, 28, 25}
    };

    int totalPoints = 0;
    int questionCount = 0;
	vector<pair<string, int>> highestScorersFastMoney;
    for (const string& question : fastMoneyQuestions)
    {
        clearScreen();
        cout << "==============================" << endl;
        cout << "        FAST MONEY           " << endl;
        cout << "==============================" << endl;
        cout << endl;
        cout << "Pick the two best players on your team\n";
        sleep(2);
        cout << "Question " << (questionCount + 1) << ": " << question << endl;
        cout << endl;
        cout << "You have 5 seconds to look at the questions" << endl;
        sleep(5);
        cout << endl;
        clearScreen();
        cout << "==============================" << endl;
        cout << "        FAST MONEY          " << endl;
        cout << "==============================" << endl;
        cout << endl;

        cout << "Player 1, enter your answer: ";
        string answer1;
        getline(cin >> ws, answer1);

        // Convert answer to lowercase for case-insensitive comparison
        transform(answer1.begin(), answer1.end(), answer1.begin(), [](unsigned char c) { return tolower(c); });

        bool answer1Correct = false;

        // Check if the answer matches any of the survey answers
        for (size_t i = 0; i < surveyFastMoney[questionCount].size(); ++i)
        {
            string lowercaseSurveyAnswer = surveyFastMoney[questionCount][i];
            transform(lowercaseSurveyAnswer.begin(), lowercaseSurveyAnswer.end(), lowercaseSurveyAnswer.begin(), [](unsigned char c) { return tolower(c); });

            if (answer1 == lowercaseSurveyAnswer)
            {
                answer1Correct = true;
                totalPoints += fastMoneyPoints[questionCount][i];
                cout << "Correct answer! Player 1 earned " << fastMoneyPoints[questionCount][i] << " points." << endl;
                break;
            }
        }

        if (!answer1Correct)
        {
            cout << "Incorrect answer." << endl;
        }

        cout << endl;
        sleep(2);

        // Second player's turn
        cout << "Player 2, enter your answer: ";
        string answer2;
        getline(cin >> ws, answer2);

        // Convert answer to lowercase for case-insensitive comparison
        transform(answer2.begin(), answer2.end(), answer2.begin(), [](unsigned char c) { return tolower(c); });

        bool answer2Correct = false;

        // Check if the answer matches any of the survey answers
        for (size_t i = 0; i < surveyFastMoney[questionCount].size(); ++i)
        {
            string lowercaseSurveyAnswer = surveyFastMoney[questionCount][i];
            transform(lowercaseSurveyAnswer.begin(), lowercaseSurveyAnswer.end(), lowercaseSurveyAnswer.begin(), [](unsigned char c) { return tolower(c); });

            if (answer2 == lowercaseSurveyAnswer)
            {
                answer2Correct = true;
                totalPoints += fastMoneyPoints[questionCount][i];
                cout << "Correct answer! Player 2 earned " << fastMoneyPoints[questionCount][i] << " points." << endl;
                break;
            }
        }

        if (!answer2Correct)
        {
            cout << "Incorrect answer." << endl;
        }

        cout << endl;
        sleep(2);

        questionCount++;

      if (totalPoints >= 200)
{
    cout << "Congratulations! " << gameWinner << " You reached a total of " << totalPoints << " points." << endl;
    cout << "You have won the grand prize!" << endl;
    // Add the current player and their score to the highest scorers vector
    
	highestScorersFastMoney.emplace_back("Who won", totalPoints);
	cout<<"Loading...";
   	sleep(7);
	sort(highestScorersFastMoney.begin(), highestScorersFastMoney.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
});

    // Display the Fast Money round results
    clearScreen();
    cout << "==============================" << endl;
    cout << "      FAST MONEY RESULTS      " << endl;
    cout << "==============================" << endl;
    cout << endl;
    cout << "Rank\t\tWinner\t\tPoints" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < highestScorersFastMoney.size(); i++)
    {
        cout << i + 1 << "\t\t" << highestScorersFastMoney[i].first << "\t\t" << highestScorersFastMoney[i].second << endl;
    }
    return;
}
	}
cout << "Time's up! You earned a total of " << totalPoints << " points." << endl;
sleep(7);
}
int main()
{
    string choice, playerFamily, challengerFamily;
    int playerPoints, challengerPoints;
    do
    {
        displayMenu();
        cin >> choice;
        if (choice == "1")
        {
            startGame();	
        }
        else if (choice == "2")
        {
            cout << "Thank you for playing!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

        if (choice != "2")
        {
            cout << "Press Enter to continue...";
            cin.get();
        }

    } while (choice != "2");

    return 0;
}


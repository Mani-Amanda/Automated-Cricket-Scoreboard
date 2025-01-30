#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<thread>
#include<chrono>
#include "Class.h"

using namespace std;

int main() {
    Team team1;
    Team team2;
    int targetScore;
    int battingWickets;
    int team1Wickets;

    team1.initializeTeams("team1.txt");
    team2.initializeTeams("team2.txt");


    cout << "----------------------------------------------------------------------" << endl;
    cout << "\t\t\tWORLD CUP 2023" << endl;
    cout << "\t\t\t" << team1.getTeamName() << " VS " << team2.getTeamName() << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << " Match In Progress....." << endl;


    //Play Toss
    cout << "\n---------------------Tossing Time------------------" << endl;
    string teamArray[2];
    teamArray[0] = team1.getTeamName();
    teamArray[1] = team2.getTeamName();
    cout << " Coin in the Air......." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    int fBat = rand() % 2;
    cout << " " << teamArray[fBat] << " won the toss and elected to bat" << endl;

    //Start Match
    if (fBat == 1) {
        Team temp;
        temp = team1;
        team1 = team2;
        team2 = temp;
    }

    cout << "\n---------------------Match Started-------------------" << endl;
    ScoreBoard FirstBatting;
    FirstBatting.setBowlingSquad(team1, team2);
    FirstBatting.initializeDeliveryArray();
    FirstBatting.initializeScoreArray();
    FirstBatting.initializeWicketArray();
    targetScore = FirstBatting.InningTotal(team1, team2, 20);
    team1Wickets = FirstBatting.getTeamWicket();

    cout << "\n----------------------------------------------------------------------" << endl;
    cout << "\t\t\tInning Break" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << " Match will start soon....." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));


    ScoreBoard SecondBatting;
    SecondBatting.setBowlingSquad(team2, team1);
    SecondBatting.initializeDeliveryArray();
    SecondBatting.initializeWicketArray();
    SecondBatting.initializeScoreArray();
    SecondBatting.TargetScoreFunction(team2, team1, targetScore, team1Wickets);

    for (int i = 0; i <= 15; i++) {
        int choice = 0;
        int teamChoice;
        cout << "\nView Match Statistics:" << endl;
        cout << "\t1.View Team\n\t2.View Bowling Squad\n\t3.Over Statistic\n\t4.Player Statistic\n\t5.Bowler Statistic\n\t6.Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 01:
            cout << "Select the Team:" << endl;
            cout << "\t1." << team1.getTeamName() << "\n\t2." << team2.getTeamName() << endl;
            cout << "Your Choice:";
            cin >> teamChoice;
            if (teamChoice == 1) {
                cout << "\n\n----------------------------------------------------------------------" << endl;
                cout << "\t\t\tWORLD CUP 2023" << endl;
                cout << "\t\t\t" << team1.getTeamName() << " VS " << team2.getTeamName() << endl;
                cout << "\t\t\t" << team1.getTeamName() << " Players" << endl;
                cout << "----------------------------------------------------------------------" << endl;
                team1.printTeam();
            }
            else if (teamChoice == 2) {
                cout << "\n\n----------------------------------------------------------------------" << endl;
                cout << "\t\t\tWORLD CUP 2023" << endl;
                cout << "\t\t\t" << team1.getTeamName() << " VS " << team2.getTeamName() << endl;
                cout << "\t\t\t" << team2.getTeamName() << " Players" << endl;
                cout << "----------------------------------------------------------------------" << endl;
                team2.printTeam();
            }
            else {
                cout << " Error :Invalid Input " << endl;
            }
            break;

        case 02:
            cout << "Select the Team:" << endl;
            cout << "\t1." << team1.getTeamName() << "\n\t2." << team2.getTeamName() << endl;
            cout << "Your Choice:";
            cin >> teamChoice;
            if (teamChoice == 1) {
                SecondBatting.getBowlingSquad(team1, team2);
            }
            else if (teamChoice == 2) {
                FirstBatting.getBowlingSquad(team2, team1);
            }
            else {
                cout << " Error :Invalid Input " << endl;
            }
            break;
        case 03:
            cout << "Select the Team:" << endl;
            cout << "\t1." << team1.getTeamName() << "\n\t2." << team2.getTeamName() << endl;
            cout << "Your Choice:";
            cin >> teamChoice;
            if (teamChoice == 1) {
                SecondBatting.OverStatistic(team1, team2);
            }
            else if (teamChoice == 2) {
                FirstBatting.OverStatistic(team2, team1);
            }
            else {
                cout << " Error :Invalid Input " << endl;
            }
            break;
        case 04:
            cout << "Select the Team:" << endl;
            cout << "\t1." << team1.getTeamName() << "\n\t2." << team2.getTeamName() << endl;
            cout << "Your Choice:";
            cin >> teamChoice;
            if (teamChoice == 1) {
                FirstBatting.PlayerStatistic(team1, team2);

            }
            else if (teamChoice == 2) {
                SecondBatting.PlayerStatistic(team2, team1);
            }
            else {
                cout << " Error :Invalid Input " << endl;
            }
            break;
        case 05:
            cout << "Select the Team:" << endl;
            cout << "\t1." << team1.getTeamName() << "\n\t2." << team2.getTeamName() << endl;
            cout << "Your Choice:";
            cin >> teamChoice;
            if (teamChoice == 1) {
                SecondBatting.BowlerStatistics(team2, team1);
            }
            else if (teamChoice == 2) {
                FirstBatting.BowlerStatistics(team1, team2);
            }
            else {
                cout << " Error :Invalid Input " << endl;
            }
            break;
        case 06:
            return 0;
        default:
            break;
        }
    }
    return 0;
}


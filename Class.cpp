#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<thread>
#include<chrono>
#include "Class.h"
using namespace std;

Player::Player(const string& playerName, const string& playerRole, const string& age)
    : name(playerName), role(playerRole), Age(age) {}
string Player::getName() {
    return name;
}
string Player::getRole() {
    return role;
}
string Player::getAge() {
    return Age;
}

void Team::setFileName(string fileName) {
    FileName = fileName;
}
void Team::setTeamName(const string& teamName) {
    TeamName = teamName;
}
string Team::getTeamName() {
    return TeamName;
}
void Team::printTeam() {
    for (int i = 0; i < numPlayers; i++) {
        cout << players[i].getName() << endl;
    }
}
void Team::playerInfo(int i) {
    cout << players[i].getName() << "  " << players[i].getRole() << endl;
}
void Team::initializeTeams(const string& fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Unable to open the file: " << fileName << endl;
        return;
    }
    string initialLine;
    if (getline(inputFile, initialLine)) {
        TeamName = initialLine;
        string line;
        while (getline(inputFile, line) && !inputFile.eof()) {
            istringstream iss(line);
            string name;
            string role;
            string age;
            string wordArray[6];
            string word;
            int j = 0;
            while (iss >> word) {
                wordArray[j] = word;
                j++;
            }
            addPlayer(wordArray[0], wordArray[1], wordArray[2]);
        }
    }
    inputFile.close();
    //Player TeamName;
}
void Team::addPlayer(const string& playerName, const string& playerRole, const string& age) {
    if (numPlayers < MaxPlayers) {
        players[numPlayers] = Player(playerName, playerRole, age);
        numPlayers++;
    }
    else {
        cout << "Team is full. Cannot add more players." << endl;
    }
}
string Team::printPlayerName(int i) {
    return players[i].getName();
}
string Team::printPlayerRole(int i) {
    return players[i].getRole();
}
string Team::printPlayerAge(int i) {
    return players[i].getAge();
}



float ScoreBoard::getTotalScore() {
    return TotalScore;
}
int ScoreBoard::getTeamWicket() {
    return TeamWicket;
}
int ScoreBoard::getExtraBalls() {
    return ExtraBalls;
}
int ScoreBoard::getRunsPerPlayer(int i) {
    return runsPerPlayer[i];
}
int ScoreBoard::setRunsPerPlayer(int i, int run) {
    runsPerPlayer[i] += run;
    return runsPerPlayer[i];
}
int ScoreBoard::setPlayerFacedBalls(int i) {
    return playerFacedBalls[i];
}
int ScoreBoard::getExtra() {
    return Extra;
}
int ScoreBoard::runsPerBall(Team Batting, Team Balling, int ball, int Bowler) {
    int run = 0;
    cout << " Ball " << ball << endl;
    if (rand() % 20 == 0) {
        ExtraBalls += 1;
        Extra += 1;
        run = 1;


        cout << "\tWide extra run" << endl;
    }
    else if (rand() % 30 == 0) {
        ExtraBalls += 1;
        Extra += 1;
        run = rand() % 7;
        cout << "\tNo ball extra run" << endl;


    }
    else if (rand() % 10 == 0) {       // random probability for a wicket is 10%
        run = 0;
        TeamWicket++;
        cout << "\tWICKET!!" << endl;
        cout << "\t" << Batting.printPlayerName(BattingPlayer) << " wicket by " << Balling.printPlayerName(BowlingPlayer) << endl;;
        BowlerWickets[Bowler]++;
        if (BattingPlayer > BowlingPlayer) {
            BattingPlayer += 1;
        }
        else {
            BattingPlayer = BowlingPlayer + 1;
        }

    }
    else {
        string role = Batting.printPlayerRole(BattingPlayer);
        if (role == "Batsman") {
            run = rand() % 7;
            cout << "\trun =" << run << " ";
            if (run == 0 || run == 2 || run == 4 || run == 6) {
                setRunsPerPlayer(BattingPlayer, run);
                cout << "\t" << Batting.printPlayerName(BattingPlayer) << " got " << run << " runs." << endl;
            }
            else {
                setRunsPerPlayer(BattingPlayer, run);
                cout << "\t" << Batting.printPlayerName(BattingPlayer) << " got " << run << " runs." << endl;
                cout << "\tPlayers switch sides." << endl;
                int temp = BattingPlayer;
                BattingPlayer = BowlingPlayer;
                BowlingPlayer = temp;
            }
            playerFacedBalls[BattingPlayer]++;
            cout << Batting.printPlayerName(BattingPlayer) << "=" << runsPerPlayer[BattingPlayer] << " (" << playerFacedBalls[BattingPlayer] << ") \t" << Batting.printPlayerName(BowlingPlayer) << "=" << runsPerPlayer[BowlingPlayer] << " (" << playerFacedBalls[BowlingPlayer] << ")" << endl;
        }
        else if (role == "AllRounder") {
            run = rand() % 5;
            cout << "\trun=" << run << " ";
            cout << Batting.printPlayerName(BattingPlayer) << endl;
            if (run == 0 || run == 2 || run == 4 || run == 6) {
                cout << "\t" << Batting.printPlayerName(BattingPlayer) << " got " << run << " runs." << endl;
                setRunsPerPlayer(BattingPlayer, run);
            }
            else {
                setRunsPerPlayer(BattingPlayer, run);
                cout << "\t" << Batting.printPlayerName(BattingPlayer) << " got " << run << " runs." << endl;
                cout << "\tPlayers switch sides." << endl;
                int temp = BattingPlayer;
                BattingPlayer = BowlingPlayer;
                BowlingPlayer = temp;
            }
            playerFacedBalls[BattingPlayer]++;
            cout << Batting.printPlayerName(BattingPlayer) << "=" << runsPerPlayer[BattingPlayer] << " (" << playerFacedBalls[BattingPlayer] << ") \t" << Batting.printPlayerName(BowlingPlayer) << "=" << runsPerPlayer[BowlingPlayer] << " (" << playerFacedBalls[BowlingPlayer] << ")" << endl;

        }
        else {
            run = rand() % 4;
            cout << "\trun=" << run << " ";
            cout << Batting.printPlayerName(BattingPlayer) << endl;
            if (run == 0 || run == 2 || run == 4 || run == 6) {
                cout << "\t" << Batting.printPlayerName(BattingPlayer) << " got " << run << " runs." << endl;
                setRunsPerPlayer(BattingPlayer, run);
            }
            else {
                setRunsPerPlayer(BattingPlayer, run);
                cout << "\t" << Batting.printPlayerName(BattingPlayer) << " got " << run << " runs." << endl;
                cout << "\tPlayers switch sides." << endl;
                int temp = BattingPlayer;
                BattingPlayer = BowlingPlayer;
                BowlingPlayer = temp;
            }
            playerFacedBalls[BattingPlayer]++;
            cout << Batting.printPlayerName(BattingPlayer) << "=" << runsPerPlayer[BattingPlayer] << " (" << playerFacedBalls[BattingPlayer] << ") \t" << Batting.printPlayerName(BowlingPlayer) << "=" << runsPerPlayer[BowlingPlayer] << " (" << playerFacedBalls[BowlingPlayer] << ")" << endl;

        }
    }
    this_thread::sleep_for(chrono::milliseconds(500));
    return run;
}
void ScoreBoard::setBowlingSquad(Team Batting, Team Bowling) {
    int j = 0;
    string role;
    for (int i = 0; i < 11; i++) {
        role = Bowling.printPlayerRole(i);
        if (role == "AllRounder" || role == "Bowler") {
            BowlingSquad[j] = Bowling.printPlayerName(i);
            j++;
        }
    }
}
void ScoreBoard::getBowlingSquad(Team Batting, Team Bowling) {
    cout << "\n\n----------------------------------------------------------------------" << endl;
    cout << "\t\t\tWORLD CUP 2023" << endl;
    cout << "\t\t\t" << Batting.getTeamName() << " VS " << Bowling.getTeamName() << endl;
    cout << "\t\t\t" << Bowling.getTeamName() << " Bowling Squad" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < 11; i++) {
        if (BowlingSquad[i] != "") {
            cout << BowlingSquad[i] << endl;
        }
    }
}
int ScoreBoard::getBowler(Team Batting, Team Bowling) {
    int randomIndex = rand() % 6;
    string choosenBowler = BowlingSquad[randomIndex];
    if (choosenBowler != " ") {
        return randomIndex;
    }
    else {
        getBowler(Batting, Bowling);
    }
}
void ScoreBoard::initializeDeliveryArray() {
    for (int i = 0; i < 11; i++) {
        if (BowlingSquad[i] != " ") {
            BowlerDeliveries.push_back(0);
        }
    }
}
void ScoreBoard::initializeWicketArray() {
    for (int i = 0; i < 11; i++) {
        if (BowlingSquad[i] != " ") {
            BowlerWickets.push_back(0);
        }
    }
}
void ScoreBoard::initializeScoreArray() {
    for (int i = 0; i < 11; i++) {
        if (BowlingSquad[i] != " ") {
            BowlerScore.push_back(0);
        }
    }
}
float ScoreBoard::GetSizeOfDeliveryArray() {
    return BowlerDeliveries.size();
}
int ScoreBoard::GetSizeOfWicketArray() {
    return BowlerWickets.size();
}
float ScoreBoard::CurrentRunRate() {
    return TotalScore / Balls;
}
float ScoreBoard::RequiredRunRate() {
    int requiredRuns = TargetScore - TotalScore;
    return requiredRuns / (120 - Balls);
}
int ScoreBoard::runsPerOver(Team Batting, Team Bowling) {
    int runsInOver = 0;
    int Bowler = getBowler(Batting, Bowling);
    cout << "\n----------------------------------------------------------------------" << endl;
    cout << "\t\tOver: " << Over << "\t" << "Bowler= " << Bowling.printPlayerName(Bowler) << "\tAge=" << Bowling.printPlayerAge(Bowler) << endl;
    cout << "----------------------------------------------------------------------" << endl;
    int tempTotalScore = TotalScore;
    for (int i = 1; i <= 6; i++) {
        TotalScore += runsPerBall(Batting, Bowling, i, Bowler);
        if (RequiredRunRate() > 0) {
            cout << " " << Batting.getTeamName() << " " << TotalScore << "/" << TeamWicket << " (" << Over << "." << i << ")\t Current Run Rate= " << CurrentRunRate() << endl;
            cout << " Required Runs= " << TargetScore - TotalScore << "\tRequired Run Rate= " << RequiredRunRate() << endl;
            cout << endl;
        }
        else {
            cout << " " << Batting.getTeamName() << " " << TotalScore << "/" << TeamWicket << " (" << Over << "." << i << ")\tCurrent Run Rate= " << CurrentRunRate() << "\n" << endl;
            cout << endl;
        }
        BowlerDeliveries[Bowler]++;
        Balls++;
        if (TeamWicket == 10) {
            break;
            cout << "ALL OUT....!" << endl;
        }

    }
    if (ExtraBalls > 0) {
        cout << "Ball " << endl;
        cout << "-----Extra Balls-----" << endl;
        for (int i = 1; i <= ExtraBalls; i++) {
            TotalScore += runsPerBall(Batting, Bowling, i, Bowler);
            cout << "Current Run Rate= " << CurrentRunRate() << endl;
            BowlerDeliveries[Bowler]++;
        }
        ExtraBalls = 0;
    }
    runsInOver = TotalScore - tempTotalScore;
    cout << "This over runs= " << runsInOver << endl;
    BowlerScore[Bowler] += runsInOver;
    Over++;
    return runsInOver;
}
int ScoreBoard::InningTotal(Team Batting, Team Bowling, int overs) {
    for (int i = 1; i <= overs; i++) {
        RunsPerOver[i] = runsPerOver(Batting, Bowling);
    }
    cout << "\n " << Batting.getTeamName() << " Total Score= " << TotalScore << " Wickets= " << TeamWicket << " /10\n" << endl;
    cout << "-------------------Inning Over-------------------------\n" << endl;
    return TotalScore;
}
void ScoreBoard::PlayerStatistic(Team Batting, Team Balling) {
    cout << "\n\n----------------------------------------------------------------------" << endl;
    cout << "\t\t\tWORLD CUP 2023" << endl;
    cout << "\t\t\t" << Batting.getTeamName() << " VS " << Balling.getTeamName() << endl;
    cout << "\t\t\t" << Batting.getTeamName() << " Playing Statistic" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Name\t\t\tScore" << endl;

    for (int i = 0; i < 11; i++) {
        string playerName = " ";
        int playerScore = 0;
        int facedBalls = 0;
        int strikeRate = 0;
        playerName = Batting.printPlayerName(i);
        playerScore = getRunsPerPlayer(i);
        facedBalls = setPlayerFacedBalls(i);
        cout << playerName << "\t\t\t" << playerScore << " (" << facedBalls << ")" << endl;
    }
    cout << "\nExtra=" << Extra << "\t\t" << Batting.getTeamName() << " - " << TotalScore << "/" << TeamWicket << endl;
}
void ScoreBoard::BowlerStatistics(Team Batting, Team Bowling) {
    cout << "\n\n----------------------------------------------------------------------" << endl;
    cout << "\t\t\tWORLD CUP 2023" << endl;
    cout << "\t\t\t" << Batting.getTeamName() << " VS " << Bowling.getTeamName() << endl;
    cout << "\t\t\t" << Bowling.getTeamName() << " Bowlers" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Name\t\t\tScore\t\t\tWickets" << endl;
    for (int i = 0; i < sizeof(BowlerScore) / sizeof(BowlerScore[0]) - 1; i++) {
        if (BowlingSquad[i] != " ") {
            cout << BowlingSquad[i] << "\t\t" << BowlerScore[i] << "(" << BowlerDeliveries[i] << ") \t\t\t" << BowlerWickets[i] << endl;
        }
    }
}
void ScoreBoard::TargetScoreFunction(Team Batting, Team Bowling, int targetScore, int Wicket) {
    for (int i = 1; i <= 20; i++) {
        TargetScore = targetScore;
        RunsPerOver[i] = runsPerOver(Batting, Bowling);
        TotalScore += RunsPerOver[i];
        if (TeamWicket == 10) {
            cout << "ALL OUT....!" << endl;
            break;
        }
        if (TotalScore >= targetScore + 1) {
            if (Wicket > TeamWicket) {
                cout << Batting.getTeamName() << " won the match by " << Wicket - TeamWicket << "/10 Wickets" << endl;
                break;
            }
            else if (Wicket < TeamWicket) {
                cout << Batting.getTeamName() << " won the match by " << TeamWicket - Wicket << "/10 Wickets" << endl;
                break;
            }
            else {
                cout << Batting.getTeamName() << " won the match" << endl;
                break;
            }
        }
    }
    cout << Batting.getTeamName() << " Total Score= " << TotalScore << " Wickets= " << TeamWicket << " /10" << endl;
    cout << "-------------------Inning Over-------------------------\n" << endl;
    if (Wicket > TeamWicket) {
        cout << Bowling.getTeamName() << " won the match by " << targetScore - TotalScore << " runs and " << Wicket - TeamWicket << "/10 Wickets" << endl;
    }
    else if (Wicket < TeamWicket) {
        cout << Bowling.getTeamName() << " won the match by " << targetScore - TotalScore << " runs and " << TeamWicket - Wicket << "/10 Wickets" << endl;
    }
    else {
        cout << Bowling.getTeamName() << " won the match by" << targetScore - TotalScore << " runs" << endl;
    }
}
void ScoreBoard::OverStatistic(Team Batting, Team Bowling) {
    cout << "\n\n----------------------------------------------------------------------" << endl;
    cout << "\t\t\tWORLD CUP 2023" << endl;
    cout << "\t\t\t" << Batting.getTeamName() << " VS " << Bowling.getTeamName() << endl;
    cout << "\t\t\t" << Batting.getTeamName() << " Over Statistic" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "\n\tOver\tRuns" << endl;
    for (int i = 1; i <= 20; i++) {
        cout << "\t" << i << "\t" << RunsPerOver[i - 1] << endl;
    }
    cout << "\n " << Batting.getTeamName() << " Total Score= " << TotalScore << " Wickets= " << TeamWicket << " /10\n" << endl;
}



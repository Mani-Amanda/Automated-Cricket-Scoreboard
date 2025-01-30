#include<string>
using namespace std;

class Player {
private:
	string name;
	string role;
	string Age;

public:
	Player() :name(""), role(""), Age("") {}
	Player(const string& playerName, const string& playRole, const string& age);
	string getName();
	string getRole();
	string getAge();

};
class Team {
private:
	static const int MaxPlayers = 11;
	Player players[MaxPlayers];
	int numPlayers;
	string TeamName;
	string FileName;

public:
	Team() : numPlayers(0), FileName(" ") {}
	void setFileName(string fileName);
	void setTeamName(const string& teamName);
	string getTeamName();
	void printTeam();
	void playerInfo(int i);
	void initializeTeams(const string& fileName);
	void addPlayer(const string& playerName, const string& playerRole, const string& age);
	string printPlayerName(int i);
	string printPlayerRole(int i);
	string printPlayerAge(int i);
};
class ScoreBoard :public Team {
private:
	float TotalScore;
	int TeamWicket;
	int RunsPerOver[100];
	int Extra;
	int ExtraBalls;
	int BattingPlayer;
	int BowlingPlayer;
	int runsPerPlayer[11];
	int playerFacedBalls[11];
	string BowlingSquad[11];
	vector<int> BowlerDeliveries;
	vector<int> BowlerWickets;
	vector<int>BowlerScore;
	float Balls;
	int Over;
	int TargetScore;

public:
	ScoreBoard() {
		TotalScore = 0;
		TeamWicket = 0;
		for (int i = 0; i < 100; i++) {
			RunsPerOver[i] = 0;
		}
		Extra = 0;
		ExtraBalls = 0;
		BattingPlayer = 0;
		BowlingPlayer = 1;
		for (int i = 0; i < 11; i++) {
			runsPerPlayer[i] = 0;
		}
		for (int i = 0; i < 11; i++) {
			playerFacedBalls[i] = 0;
		}
		for (int i = 0; i < 11; i++) {
			BowlingSquad[i] = "";
		}
		Balls = 1;
		Over = 0;
		TargetScore = 0;
	}
	float getTotalScore();
	int getTeamWicket();
	int getExtraBalls();
	int getRunsPerPlayer(int i);
	int setRunsPerPlayer(int i, int run);
	int setPlayerFacedBalls(int i);
	int getExtra();
	int runsPerBall(Team Batting, Team Balling, int ball, int Bowler);
	void setBowlingSquad(Team Batting, Team Bowling);
	void getBowlingSquad(Team Batting, Team Bowling);
	int getBowler(Team Batting, Team Bowling);
	void initializeDeliveryArray();
	void initializeWicketArray();
	void initializeScoreArray();
	float GetSizeOfDeliveryArray();
	int GetSizeOfWicketArray();
	float CurrentRunRate();
	float RequiredRunRate();
	int runsPerOver(Team Batting, Team Bowling);
	int InningTotal(Team Batting, Team Bowling, int overs);
	void PlayerStatistic(Team Batting, Team Balling);
	void BowlerStatistics(Team Batting, Team Bowling);
	void TargetScoreFunction(Team Batting, Team Bowling, int targetScore, int Wicket);
	void OverStatistic(Team Batting, Team Bowling);
};


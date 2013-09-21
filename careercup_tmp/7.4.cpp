class ChessPieceTurn
{};
class GameManager
{
public:
	void processTurn(PlayerBase &player)
	{}
	bool acceptTurn(ChessPieceTurn &turn)
	{
		return true;
	}
	Position &current;
};
class PlayerBase
{
public:
	virtual ChessPieceTurn getTurn(Position &p) = 0;
};
class ComputerPlayer : public PlayerBase
{
public:
	virtual ChessPieceTurn getTurn (Position &p)
	{
		return NULL;
	}
	void setDifficulty()
	{}
	PositionEstimator estimator;
	PositionBackTracker backtracker;
};
class HumanPlayer : public PlayerBase
{
public:
	virtual ChessPieceTurn getTurn(Position p)
	{
		return NULL;
	}
};
class ChessPieceBase
{
public:
	virtual bool canBeChecked() = 0;
	virtual bool isSupportCastle() = 0;
};
class King : public ChessPieceBase
{};
struct Position
{
	std::vector<ChessPieceBase &> black, white;
};
class PositionBackTracker
{
public:
	Position getNext(Position p)
	{
		return NULL;
	}
}
// ...

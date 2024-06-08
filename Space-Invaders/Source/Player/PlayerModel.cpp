#include "Player/PlayerModel.h"

namespace Player
{
	using namespace Entity;

	PlayerModel::PlayerModel()
	{

	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		player_position = initial_player_position;
		player_score = 0;

		b_rapid_fire = false;
		b_shield = false;
		b_triple_laser = false;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

	int PlayerModel::getPlayerScore()
	{
		return player_score;
	}

	void PlayerModel::setPlayerScore(int score)
	{
		player_score = score;
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}

	EntityType PlayerModel::getEntityType()
	{
		return entity_type;
	}

	bool PlayerModel::isShieldEnabled()
	{
		return b_shield;
	}

	void PlayerModel::setShieldState(bool value)
	{
		b_shield = value;
	}

	bool PlayerModel::isRapidFireEnabled()
	{
		return b_rapid_fire;
	}

	void PlayerModel::setRapidFireState(bool value)
	{
		b_rapid_fire = value;
	}

	bool PlayerModel::isTripleLaserEnabled()
	{
		return b_triple_laser;
	}

	void PlayerModel::setTripleLaserState(bool value)
	{
		b_triple_laser = value;
	}
}
#pragma once

namespace Enemy
{
	enum class EnemyType
	{
		ZAPPER,
		SUBZERO,
		//UFO,
		//THUNDERSNAKE,
	};

	enum class EnemyState
	{
		PATROLLING,
		ATTACK,
		DEAD,
	};

	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
	};
}
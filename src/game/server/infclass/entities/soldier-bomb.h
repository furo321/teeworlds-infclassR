/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_ENTITIES_SOLDIER_BOMB_H
#define GAME_SERVER_ENTITIES_SOLDIER_BOMB_H

#include "infc-placed-object.h"

#include <base/tl/array.h>

class CSoldierBomb : public CPlacedObject
{
public:
	CSoldierBomb(CGameContext *pGameContext, vec2 Pos, int Owner);
	~CSoldierBomb() override;

	void Snap(int SnappingClient) override;
	void Tick() override;
	void TickPaused() override;

	void Explode();
	int GetNbBombs() const { return m_nbBomb; }

private:
	void ChargeBomb(float time);

	int m_StartTick;
	float m_Angle = 0;
	array<int> m_IDBomb;
	int m_nbBomb;
	int m_ChargedBomb;
};

#endif

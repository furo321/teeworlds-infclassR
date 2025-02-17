/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_ENTITIES_TURRET_H
#define GAME_SERVER_ENTITIES_TURRET_H

#include "infc-placed-object.h"

class CTurret : public CPlacedObject
{
public:
	static int EntityId;

	enum Type
	{
		LASER,
		PLASMA,
	};

	CTurret(CGameContext *pGameContext, vec2 Pos, int Owner, vec2 Direction, Type Type);
	~CTurret() override;

	void Tick() override;
	void TickPaused() override;
	void Snap(int SnappingClient) override;
	float HitRadius() const { return 4.0f; }
	void Die(CInfClassCharacter *pKiller);

	int GetEndTick() const { return m_EndTick; }

protected:
	void AttackTargets();
	void Reload();

private:
	vec2 m_Vel;
	vec2 m_Dir;
	int m_StartTick;
	int m_EndTick;
	int m_Bounces;
	int m_Radius;
	Type m_Type;
	const float m_RadiusGrowthRate = 4.0f;
	int m_WarmUpCounter;
	int m_ReloadCounter;
	int m_ammunition;
	bool m_foundTarget;

	int m_IDs[8];
};

#endif

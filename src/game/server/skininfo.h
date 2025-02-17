#ifndef GAME_SERVER_SKININFO_H
#define GAME_SERVER_SKININFO_H

class CSkinContext
{
public:
	int PlayerClass = 0;
	int ExtraData1 = 0;
	bool Highlight = 0;
};

class CWeakSkinInfo
{
public:
	const char *pSkinName = nullptr;
	int UseCustomColor = 0;
	int ColorBody = 0;
	int ColorFeet = 0;
};

using SkinGetter = bool(*)(const CSkinContext &, CWeakSkinInfo *, int, int);

#endif //GAME_SERVER_SKININFO_H

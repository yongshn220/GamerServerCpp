#pragma once

class GameSession;

using GameSessionRef = shared_ptr<GameSession>;

class GameSessionManager
{

public:
	void Add(GameSessionRef session);
	void Remove(GameSessionRef session);
	void BroadCast(SendBufferRef sendBuffer);

private:
	USE_LOCK;
	xset<GameSessionRef> _sessions;
};

extern GameSessionManager GSessionManager;


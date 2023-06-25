#pragma once

class GameSession;

using GameSessionRef = shared_ptr<GameSession>;

class GameSessionManager
{

public:
	void Add(GameSessionRef session);
	void Remove(GameSessionRef session);
	void Broadcast(SendBufferRef sendBuffer);

	bool IsEmpty() { return _sessions.size() == 0; }

private:
	USE_LOCK;
	xset<GameSessionRef> _sessions;
};

extern GameSessionManager GSessionManager;


#pragma once


// 1st try

//struct SListEntry
//{
//	SListEntry* next;
//};
//
//class Data
//{
//public:
//	SListEntry _entry;
//
//	int32 _hp;
//	int32 _mp;
//};
//
//struct SListHeader
//{
//	SListEntry* next = nullptr;
//};
//
//void InitializeHead(SListHeader* header);
//void PushEntrySList(SListHeader* header, SListEntry* entry);
//SListEntry* PopEntrySList(SListHeader* header);


//2nd try

/*
struct SListEntry
{
	SListEntry* next;
};

class Data
{
public:
	SListEntry _entry;

	int32 _hp;
	int32 _mp;
};

struct SListHeader
{
	SListEntry* next = nullptr;
};

void InitializeHead(SListHeader* header);
void PushEntrySList(SListHeader* header, SListEntry* entry);
SListEntry* PopEntrySList(SListHeader* header);
*/


// 3rd try
DECLSPEC_ALIGN(16)
struct SListEntry
{
	SListEntry* next;
};

DECLSPEC_ALIGN(16)
struct SListHeader
{
	SListHeader()
	{
		alignment = 0;
		region = 0;
	}

	union
	{
		struct
		{
			uint64 alignment;
			uint64 region;
		} DUMMYSTRUCTNAME;
		struct
		{
			uint64 depth : 16;
			uint64 sequence : 28;
			uint64 reserved : 4;
			uint64 next : 60;
		} HeaderX64;
	};
};


class Data
{
public:
	SListEntry _entry;

	int32 _hp;
	int32 _mp;
};


void InitializeHead(SListHeader* header);
void PushEntrySList(SListHeader* header, SListEntry* entry);
SListEntry* PopEntrySList(SListHeader* header);
#include "pch.h"
#include "BufferWriter.h"

BufferWriter::BufferWriter()
{
}

BufferWriter::BufferWriter(BYTE* buffer, uint32 size, uint32 pos)
	: _buffer(buffer), _size(size), _pos(pos)
{ 
}

BufferWriter::~BufferWriter()
{
}

bool BufferWriter::Write(void* dest, uint32 len)
{
	return false;
}
 
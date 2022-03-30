#include "FooInternal.h"

namespace ddahlkvist
{

///////////////////////////////////

u32 FooMixed::getPublic()
{
	return 1;
}

u32 FooMixed::getInternal()
{
	return 2;
}

u32 FooMixed::getNothing()
{
	return 3;
}

///////////////////////////////////

u32 FooPublic::getPublic()
{
	return 11;
}

u32 FooPublic::getInternal()
{
	return 12;
}

u32 FooPublic::getNothing()
{
	return 13;
}

///////////////////////////////////

}

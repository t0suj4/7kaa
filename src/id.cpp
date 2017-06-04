#define _ID_CPP_
#include "id.h"

namespace {
const unsigned int INVALID_ID = 0;
}

template <typename T, unsigned int ID_MAX>
Id<T, ID_MAX>::Id(const unsigned int id) :id(id) {}

template <typename T, unsigned int ID_MAX>
Id<T, ID_MAX>::operator unsigned int() const
{
	return id;
}

template <typename T, unsigned int ID_MAX>
Id<T, ID_MAX>::operator int() const
{
	return (int) id;
}

template <typename T, unsigned int ID_MAX>
bool Id<T, ID_MAX>::operator ==(Id<T,ID_MAX> a) const
{
	id == a.id;
}

template <typename T, unsigned int ID_MAX>
bool Id<T, ID_MAX>::is_valid() const
{
	return id != ::INVALID_ID && id <= ID_MAX; 
}

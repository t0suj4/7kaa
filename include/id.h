// -- Have you ever had a problem to track origin of a bug because   -- //
// -- somewhere along the lines your IDs got invalidated?            -- //
// -- Have you always wondered how in hell did that value got there? -- //
// -- This elegant class is just for you! All you need to do is      -- //
// -- to put some instrumentation in its methods and watch the magic -- //
// -- happen. You will have everything at your fingertips!           -- //
// --                                                                -- //
// -- Finished debugging? Great! There is absolutely no need to      -- //
// -- worry about disabling this class. Rely on your compiler!       -- //
// -- Compiler optimizations will optimize it down to nothing!       -- //

#ifdef _ID_H_
#error "Multiple inclusion of id.h"
#endif
#define _ID_H_

#include <limits>

// -- Following macros were derived from an answer -- //
// -- http://stackoverflow.com/questions/3046889   -- //

// -- When debugging them, it is useful to comment out all includes    -- //
// -- and run only preprocessor `gcc -E % -o - | less` from vim        -- //
// -- is priceless!  '%' in vim stands for current file name           -- //

// -- _ID_ALIAS_TEMPLATE(FooId, Foo, 2) must generate:                 -- //
// -- namespace IdName {enum Foo{};} template class Id<IdName::Foo, 2> -- //
// --                                                                  -- //
// -- _ID_ALIAS_TEMPLATE(BarId, Bar) must generate:                    -- //
// -- namespace IdName {enum Bar{};} template class Id<IdName::Bar>    -- //
// --
// -- Oh... and don't forget to undefine them at the end...            -- //
// -- you never know...                                                -- //

// --- If this is included by the id.cpp file, create template class --- //
#ifdef _ID_CPP_
# define _ID_ALIAS_TEMPLATE_1(alias, name)		\
	namespace IdName {enum name{};}				\
   	template class Id<IdName::name>

# define _ID_ALIAS_TEMPLATE_2(alias, name, MAX)	\
	namespace IdName {enum name{};}				\
   	template class Id<IdName::name, MAX>
#else
# define _ID_ALIAS_TEMPLATE_1(alias, name)		\
	namespace IdName {enum name{};}				\
	using alias = Id<IdName::name>

# define _ID_ALIAS_TEMPLATE_2(alias, name, MAX)	\
	namespace IdName {enum name{};}				\
	using alias = Id<IdName::name, MAX>
#endif

#define _ID_GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#define _ID_ALIAS_CHOOSER(...)						\
	_ID_GET_4TH_ARG(__VA_ARGS__, _ID_ALIAS_TEMPLATE_2,	\
                                 _ID_ALIAS_TEMPLATE_1)
#define _ID_ALIAS_TEMPLATE(...) _ID_ALIAS_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

namespace IdDecl {
typedef short type;
}
// -- TODO: Remove ID_MAX from template argument, probably creating  -- //
// --       a static variable for each class instance.               -- //
template <typename T, unsigned int ID_MAX = std::numeric_limits<IdDecl::type>::max()>
class Id
{
	private:
		const IdDecl::type id;
	public:
		explicit Id(const IdDecl::type id);
		constexpr Id(const Id<T, ID_MAX>& _id) : id(_id.id) {}
		explicit operator IdDecl::type() const;
//		explicit operator short() const;
		// Assignment
		Id<T, ID_MAX>& operator=(Id<T, ID_MAX> &&id);
		Id<T, ID_MAX>& operator=(const Id<T, ID_MAX> &id);
		bool operator ==(Id<T, ID_MAX> a) const;
		bool is_valid() const;
}; 

_ID_ALIAS_TEMPLATE(SlotId, Slot);
_ID_ALIAS_TEMPLATE(RaceId, Race);
_ID_ALIAS_TEMPLATE(LayoutId, Layout);
_ID_ALIAS_TEMPLATE(BuildTypeId, BuildType);
_ID_ALIAS_TEMPLATE(TownBuildId, TownBuild);
_ID_ALIAS_TEMPLATE(TownNameId, TownName);
// --- Undefine all macros as they are not useful anymore ---//
#undef _ID_ALIAS_TEMPLATE_1
#undef _ID_ALIAS_TEMPLATE_2
#undef _ID_GET_4TH_ARG
#undef _ID_ALIAS_CHOOSER
#undef _ID_ALIAS_TEMPLATE

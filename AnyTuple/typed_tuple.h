#pragma once
#include <tuple>

namespace mkato {

	template <class First, class... Rests> class TypedTuple : public TypedTuple<Rests...> {
	public:
		using Next = TypedTuple<Rests...>;
		using Current = First;
	private:
		First value;

	public:
	//	constructor (with move)
		TypedTuple(const First&& value, const Rests&&... rests)
			: value(value), Next(rests...) {}

	//	constructor (with const reference)
		TypedTuple(const First& value, const Rests&&... rests)
			: TypedTuple((const First&&)value, rests...) {}

	//	constructor with first value and rest values
		TypedTuple(const First&& value, const Next&& next)
			: value(value), Next(next) {}

	//	convertion functions
		operator First() const;
		operator const First&() const;
		operator const First&&() const;
		operator First&();
		operator First&&();

	//	call func with each current (const) value (no returns)
		template <class Func> void doEach(const Func&& func) const;
		template <class Func> void doEach(const Func&& func);

	//	call func with each current (const) value and return each returns
	//	type of return value is std::tuple because types of values may be duplicated
		template <class Func> auto forEach(const Func&& func) const;
		template <class Func> auto forEach(const Func&& func);


	//	call Func::call() with each current (const) value (no returns)
		template <class Func> void doEach() const;
		template <class Func> void doEach();

	//	call Func::call() with each current (const) value and return each returns
	//	type of return value is std::tuple because types of values may be duplicated
		template <class Func> auto forEach() const;
		template <class Func> auto forEach();



	};

	

}
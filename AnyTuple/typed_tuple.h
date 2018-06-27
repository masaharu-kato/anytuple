#pragma once
#include <tuple>

namespace mkato {

	template <class First, class... Rests> class TypedTuple : public TypedTuple<Rests...> {
	public:
		using Next = TypedTuple<Rests...>;
		using Current = First;
	private:
		First value;

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


	//	call func with each current (const) value and return each returns
		template <class Func> auto forEach(const Func&& func) const;
		template <class Func> auto forEach(const Func&& func);

	//	call Func::call() with each current (const) value and return each returns
		template <class Func> auto callEach() const;
		template <class Func> auto callEach();
		
	//	make Type objects with each current (const) value and return made objects
		template <class Type> auto makeEach() const;

		
	//	call func with all (const) values and return return value
		template <class Func> auto visit(const Func&& func) const;
		template <class Func> auto visit(const Func&& func);

	//	call Func::call() with all (const) values and return return value
		template <class Func> auto call() const;
		template <class Func> auto call();
		
	//	make Type object with all values and return it
		template <class Type> auto make() const;


	private:
	//	make return values for forEach and callEach
		auto makeReturns();
		auto makeReturns(const First&& value, const Next&& next);
		template <class A, class B> auto makeReturns(const A&& a, const B&& b);

	};

	

}
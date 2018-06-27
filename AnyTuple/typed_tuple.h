#pragma once
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
			: value(value), Next(rests) {}

	//	constructor (with const reference)
		TypedTuple(const First& value, const Rests&&... rests)
			: TypedTuple((const First&&)value, rests...) {}

	//	convertion functions
		operator First() const;

	};

}
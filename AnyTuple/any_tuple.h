#pragma once
#include "typed_tuple.h"

namespace mkato {

	class AnyTuple {
	public:
	//	This type
		using This = AnyTuple;

	//	default constructor
		AnyTuple();

	//	copy constructor
		AnyTuple(const AnyTuple&);

	//	move constructor
		AnyTuple(AnyTuple&&);

	//	deconstructor
		~AnyTuple();

	//	return T's value (const), throw exception if T doesn't exist.
		template <class T> const T& get() const;

	//	return T's value (not const), throw exception if T doesn't exist.
		template <class T> T& get();


	//	if T exists return T's value (const), else return default value
		template <class T> const T& getWith(const T& defval) const;

	//	if T exists return T's value (not const), else return default value
		template <class T> T& getWith(const T& defval);


	//	get T's value to out (const), return true if T exists
		template <class T> bool get(const T& out) const;

	//	get T's value to out (not const), return true if T exists
		template <class T> bool get(T& out);
		

	//	return const pointer to T's value, return NULL if T doesn't exist.
		template <class T> const T* getPtr() const;

	//	return not const pointer to T's value, return NULL if T doesn't exist.
		template <class T> T* getPtr();


		

	//	return several T's values (not const), throw exception if any T doesn't exist.
		template <class... Types>
		TypedTuple<const Types&...> get() const;

	//	return several T's values (const), throw exception if any T doesn't exist.
		template <class... Types>
		TypedTuple<Types&...> get();


	//	return several T's values (const) with default values by arguments
		template <class... Types>
		TypedTuple<const Types&...> getWith(const Types&... defvals) const;

	//	return several T's values (not const) with default values by arguments
		template <class... Types>
		TypedTuple<      Types&...> getWith(const Types&... defvals);

	//	return several T's values (const) with default values by standard tuple
		template <class... Types>
		TypedTuple<const Types&...> getWith(const TypedTuple<Types...>& defvals) const;

	//	return several T's values (not const) with default values by standard tuple
		template <class... Types>
		TypedTuple<      Types&...> getWith(const TypedTuple<Types...>& defvals);

	//	return several T's values (const) with default values by this type
		template <class... Types>
		TypedTuple<const Types&...> getWith(const This& defvals) const;

	//	return several T's values (not const) with default values by this type
		template <class... Types>
		TypedTuple<      Types&...> getWith(const This& defvals);


	//	get T's value to out (const), return true if T exists
		template <class... Types>
		bool get(const std::tuple<Types...>& out) const;

	//	get T's value to out (not const), return true if T exists
		template <class... Types>
		bool get(std::tuple<Types...>& out);
		

	//	get T's value to out (const), return true if T exists
		template <class... Types>
		bool get(const Types&... outs) const;

	//	get T's value to out (not const), return true if T exists
		template <class... Types>
		bool get(Types&... outs);
		

	//	return const pointer to T's value, return NULL if T doesn't exist.
		template <class... Types>
		TypedTuple<const Types*...> getPtr() const;

	//	return not const pointer to T's value, return NULL if T doesn't exist.
		template <class... Types>
		TypedTuple<Types*...>  getPtr();



	//	return true if T exists
		template <class T> bool exist() const;


	//	set T's value using copy constructor
		template <class T> void set(const T&);
		
	//	set T's value using move constructor
		template <class T> void set(const T&&);

	//	set T's value using direct construction (like emplace)
		template <class T, class... Args> void emset(const Args&&...);


	//	unset T's value
		template <class T> void unset();

	};

};

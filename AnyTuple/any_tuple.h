#pragma once
namespace mkato {

	class AnyTuple {
	public:
	//	default constructor
		AnyTuple();

	//	copy constructor
		AnyTuple(const AnyTuple&);

	//	move constructor
		AnyTuple(AnyTuple&&);

	//	deconstructor
		~AnyTuple();

	//	return T's value
		template <class T> T get() const;

	//	get T's value to out, return true if T exists
		template <class T> bool get(T& out) const;

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

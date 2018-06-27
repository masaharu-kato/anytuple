#pragma once
#include "typed_tuple.h"

namespace mkato {

	//	call func with each current const value (no returns)
	template <class Func> void doEach(const Func&& func) const {
		func((const First&&)*this);
		Next::doEach((const Func&&)func);
	}

//	call func with each current const value and return each returns
//	type of return value is std::tuple because types of values may be duplicated
	template <class Func> auto forEach(const Func&& func) const {
		return std::tuple_cat(
			func((const First&&)*this),
			Next::forEach((const Func&&)func)
		);
	}

}
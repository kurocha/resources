//
//  RelativeLoader.hpp
//  This file is part of the "Resources" project and released under the MIT License.
//
//  Created by Samuel Williams on 19/7/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include "ChainLoader.hpp"

namespace Resources
{
	template <typename LoadT>
	class RelativeLoader : public ChainLoader<LoadT, LoadT>
	{
	public:
		RelativeLoader(const URI::Generic & base, Loader<LoadT> * loader) : ChainLoader<LoadT, LoadT>(loader), _base(base) {}
		virtual ~RelativeLoader() {}
		
		virtual Owned<LoadT> load(const URI::Generic & uri) const
		{
			return this->load_next(_base + uri);
		}
		
	private:
		URI::Generic _base;
	};
}

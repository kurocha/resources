//
//  FileData.cpp
//  This file is part of the "Resources" project and released under the MIT License.
//
//  Created by Samuel Williams on 19/7/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Resources/FileData.hpp>

#include <URI/File.hpp>

#include <cstdlib>

namespace Resources
{
	UnitTest::Suite FileDataTestSuite {
		"Resources::FileData",
		
		{"it should load data from disk",
			[](UnitTest::Examiner & examiner) {
				URI::File fixtures_root(std::getenv("RESOURCES_FIXTURES"), true);
				URI::File test_file_uri = fixtures_root + "Resources/fixtures/test.txt";
				
				FileData file_data(test_file_uri.native_path());
				
				examiner.expect(file_data.size()) == 12;
			}
		},
	};
}

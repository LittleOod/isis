/*
 * imageTest.cpp
 *
 *  Created on: Oct 1, 2009
 *      Author: proeger
 */

#define BOOST_TEST_MODULE ImageTest
#include <boost/test/included/unit_test.hpp>
#include <boost/foreach.hpp>
#include "DataStorage/image.hpp"

namespace isis{namespace test{

/* create an image list from chunks*/
BOOST_AUTO_TEST_CASE (imageList_chunk_test)
{
	const size_t images=5;
	const size_t timesteps=10;
	ENABLE_LOG(util::CoreLog,util::DefaultMsgPrint,util::warning);
	ENABLE_LOG(util::CoreDebug,util::DefaultMsgPrint,util::warning);
	ENABLE_LOG(data::DataLog,util::DefaultMsgPrint,util::info);
	ENABLE_LOG(data::DataDebug,util::DefaultMsgPrint,util::info);
	
	data::ChunkList chunks;
	for(int i=0;i<timesteps;i++){
		for(int c=0;c<images;c++){
			data::MemChunk<float> ch(3,3,3);
			ch.setProperty("indexOrigin",util::fvector4(0,0,0,i));
			ch.voxel<float>(0,0,0)=c*i;
			chunks.push_back(ch);
		}
	}
	data::ImageList list(chunks);
	BOOST_CHECK(list.size() == images);

	BOOST_FOREACH(data::ImageList::value_type &ref,list){
		BOOST_CHECK(ref->size() == util::fvector4(3,3,3,timesteps));
	}
	
}

}}
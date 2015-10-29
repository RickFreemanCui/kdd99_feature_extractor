#pragma once

#include "IpReassemblyBufferHoleList.h"
#include "IpFragment.h"
#include "IpDatagram.h"

namespace FeatureExtractor {
	/*
	 * Reassembly buffer used to reassemble fragments of one original IP datagram.
	 * Techniques to cope with IP fragmentation based od RFC 815.
	 */
	class IpReassemblyBuffer
	{
		// Hole descriptor list - initially one hole from 0 to "infinity"
		IpReassemblyBufferHoleList hole_list;

		IpDatagram *datagram;
		struct timeval first_frag_ts;
		struct timeval last_frag_ts;
		uint16_t frame_count;
		size_t total_length;

	public:
		IpReassemblyBuffer();
		~IpReassemblyBuffer();

		IpDatagram *add_fragment(const IpFragment *fragment);
	};
}

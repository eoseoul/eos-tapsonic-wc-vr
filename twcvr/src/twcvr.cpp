#include <twcvr/twcvr.hpp>
#include <eosiolib/dispatcher.hpp>

#include "record.cpp"

namespace twcvr {
	twcvr_contract::twcvr_contract(action_name self) : contract(self) {
	}
};

EOSIO_ABI( twcvr::twcvr_contract,
	// record.hpp
	(regrecord)
)

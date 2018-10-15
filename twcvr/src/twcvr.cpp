#include <twcvr/twcvr.hpp>
#include <eosiolib/dispatcher.hpp>

#include "record.cpp"

namespace twcvr {
	// twcvr_contract::twcvr_contract(name self) : contract(self) { }
};

EOSIO_DISPATCH( twcvr::twcvr_contract,
	// record.hpp
	(regrecord)
)

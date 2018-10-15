#pragma once

#include <eosiolib/print.hpp>
#include <eosiolib/multi_index.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/contract.hpp>

/* to generate abi, comment out*/
#include "record.hpp"

namespace twcvr {
    using std::string;
    using std::vector;

    class [[eosio::contract("twcvr")]] twcvr_contract : public eosio::contract {
        public:
            using contract::contract;

            // record.hpp
            [[eosio::action]]
            void regrecord(name owner, uint16_t music_id, uint32_t score );
    };
} // twcvr

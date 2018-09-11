#pragma once
#include <eosiolib/types.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/multi_index.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/contract.hpp>

/* to generate abi, comment out*/
#include "record.hpp"

// #include <string>
// #include <vector>

namespace twcvr {
    using std::string;
    using std::vector;

    class twcvr_contract : public eosio::contract {
        public:
            explicit twcvr_contract(action_name self);

            // record.hpp
            [[eosio::action]]
            void regrecord(account_name owner, uint16_t music_id, uint32_t score );
    };
} // twcvr

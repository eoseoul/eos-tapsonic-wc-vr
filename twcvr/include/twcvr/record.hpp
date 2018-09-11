#pragma once

#include <eosiolib/eosio.hpp>

namespace twcvr {
    using std::string;
    using std::vector;

    struct musicscore {
        uint16_t music_id;
        uint32_t score;
        bool operator == (const musicscore& rhs) {
            if (this->music_id == rhs.music_id)
                return true;
            return false;
        }
        EOSLIB_SERIALIZE( musicscore, (music_id)(score) );
    };

    struct [[eosio::table]] record {
        account_name owner;
        vector<musicscore> scores;
        uint64_t primary_key() const { return owner; }
        EOSLIB_SERIALIZE( record, (owner)(scores) );
    };
    typedef eosio::multi_index< N(records), record> record_table;
} // twcvr
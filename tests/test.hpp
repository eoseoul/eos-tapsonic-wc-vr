#include <boost/test/unit_test.hpp>

#include <eosio/testing/tester.hpp>
#include <eosio/chain/abi_serializer.hpp>
#include <eosio/chain/wast_to_wasm.hpp>

#include <fc/variant_object.hpp>

#include <Runtime/Runtime.h>

#include "contracts.hpp"

using namespace eosio::testing;
using namespace eosio;
using namespace eosio::chain;
using namespace eosio::testing;
using namespace fc;

using mvo = fc::mutable_variant_object;

struct musicscore_t {
    uint16_t music_id;
    uint32_t score;
    bool operator == (const musicscore_t& rhs) {
        if (this->music_id == rhs.music_id)
            return true;
        return false;
    }
};
FC_REFLECT( musicscore_t, (music_id)(score) );

struct record_t {
    name owner;
    vector<musicscore_t> scores;
    uint64_t timestamp;
    uint64_t reserve_1;
    uint64_t primary_key() const { return owner.value; }
};

FC_REFLECT( record_t, (owner)(scores)(timestamp)(reserve_1) );
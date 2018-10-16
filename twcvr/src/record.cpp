#include <twcvr/record.hpp>
#include <algorithm>

#include <twcvr/validate_hash.h>

namespace twcvr {
    void twcvr_contract::regrecord(name owner, uint16_t music_id, uint32_t score, string hash) {
        require_auth(owner);

        eosio_assert(music_id >= 0, "music_id should be more than equal 0 long");
        eosio_assert(score >= 0, "score should be more than equal 0 long");
        eosio_assert(hash.size() <= 64, "score should be equal 32 long");

        eosio_assert(validate_hash(owner, music_id, score, hash), "incorresct hash");

        //creates the records table if it doesn't exist already
        musicscore mscore{music_id, score};
        record_table records(_self, _self.value);
        auto itr = records.find(owner.value);
        if (itr == records.end()) {
            records.emplace(_self, [&](auto& record){
                record.owner = owner;
                record.scores.emplace_back(mscore);
            });
        } else {
            records.modify(itr, same_payer, [&](auto& new_record) {
                auto itr_score = std::find(new_record.scores.begin(), new_record.scores.end(), mscore);
                if (itr_score == new_record.scores.end()) {
                    new_record.scores.emplace_back(mscore);
                } else {
                    itr_score->score = score;
                }
            });
        }
    }
} // twcvr
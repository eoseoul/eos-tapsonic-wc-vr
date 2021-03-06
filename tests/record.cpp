#include "test.hpp"

class record_tester : public tester {
public:
   record_tester() {
    create_accounts( {/*N(eosio.token),*/ N(eoseoultwcvr)} );
    produce_block();
    create_accounts( {N(wwforevernw1), N(gameuseraaaa), N(gameuseraaab),  N(gameuseraaac),  N(gameuseraaad)} );
    produce_block();

/*
    base_tester::push_action(config::system_account_name, N(setpriv), config::system_account_name,
      mutable_variant_object()
      ("account", "eosio.token")
      ("is_priv", 1)
    );

    set_code( N(eosio.token), contracts::util::token_wasm() );
    set_abi( N(eosio.token), contracts::util::token_abi().data() );
*/

    set_code( N(eoseoultwcvr), contracts::twcvr_wasm() );
    set_abi( N(eoseoultwcvr), contracts::twcvr_abi().data() );

    produce_blocks();

    const auto& accnt = control->db().get<account_object,by_name>( N(eoseoultwcvr) );
    abi_def abi;
    BOOST_REQUIRE_EQUAL(abi_serializer::to_abi(accnt.abi, abi), true);
    abi_ser.set_abi(abi, fc::seconds(1));
   }

  bool get_record(record_t& record, account_name owner) {
    return get_table_entry(record, N(eoseoultwcvr), N(eoseoultwcvr), N(records), owner);
  }

  abi_serializer abi_ser;
};

BOOST_AUTO_TEST_SUITE(regrecord_tests)

BOOST_FIXTURE_TEST_CASE( regrecord, record_tester ) try {
  auto record1_1 = mvo()
      ("owner",  "wwforevernw1")
      ("music_id", 2)
      ("score", 200)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record1_2 = mvo()
      ("owner",  "gameuseraaaa")
      ("music_id", 2)
      ("score", 12)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record1_3 = mvo()
      ("owner",  "gameuseraaaa")
      ("music_id", 3)
      ("score", 13)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record1_3_2 = mvo()
      ("owner",  "gameuseraaaa")
      ("music_id", 3)
      ("score", 23)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record1_3_3 = mvo()
      ("owner",  "gameuseraaaa")
      ("music_id", 3)
      ("score", 33)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record2_1 = mvo()
      ("owner",  "gameuseraaab")
      ("music_id", 1)
      ("score", 11)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record2_2 = mvo()
      ("owner",  "gameuseraaab")
      ("music_id", 2)
      ("score", 12)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record2_3 = mvo()
      ("owner",  "gameuseraaab")
      ("music_id", 3)
      ("score", 13)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record3_1 = mvo()
      ("owner",  "gameuseraaac")
      ("music_id", 1)
      ("score", 11)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record3_2 = mvo()
      ("owner",  "gameuseraaac")
      ("music_id", 2)
      ("score", 12)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record3_3 = mvo()
      ("owner",  "gameuseraaac")
      ("music_id", 3)
      ("score", 13)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record4_1 = mvo()
      ("owner",  "gameuseraaad")
      ("music_id", 1)
      ("score", 11)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record4_2 = mvo()
      ("owner",  "gameuseraaad")
      ("music_id", 2)
      ("score", 12)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  auto record4_3 = mvo()
      ("owner",  "gameuseraaad")
      ("music_id", 3)
      ("score", 13)
      ("hash", "2b25a7d86995207d340a39f55b3b4432e98259420b10d798db4f7a8fa562fdf1");

  record_t wwforevernw1;
  auto trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(wwforevernw1), record1_1);
  produce_block();
  BOOST_TEST_MESSAGE( fc::json::to_pretty_string(trace) );
  get_record(wwforevernw1, N(wwforevernw1));
  BOOST_TEST_MESSAGE( fc::json::to_pretty_string(wwforevernw1) );

  return;

  record_t r_gameuseraaaa;
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaaa), record1_2);
  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaaa), record1_3);

  get_record(r_gameuseraaaa, N(gameuseraaaa));

  //BOOST_TEST_MESSAGE( fc::json::to_pretty_string(r_gameuseraaaa) );
  musicscore_t mscore1_3{static_cast<uint16_t>(record1_3["music_id"].as_uint64()),  static_cast<uint32_t>(record1_3["score"].as_uint64())};
  auto itr1_3 = std::find(r_gameuseraaaa.scores.begin(),r_gameuseraaaa.scores.end(), mscore1_3);
  BOOST_CHECK(record1_3["score"] == itr1_3->score);

  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaaa), record1_3_2);
  get_record(r_gameuseraaaa, N(gameuseraaaa));
  //BOOST_TEST_MESSAGE( fc::json::to_pretty_string(r_gameuseraaaa) );
  musicscore_t mscore1_3_2{static_cast<uint16_t>(record1_3_2["music_id"].as_uint64()),  static_cast<uint32_t>(record1_3_2["score"].as_uint64())};
  auto itr1_3_2 = std::find(r_gameuseraaaa.scores.begin(),r_gameuseraaaa.scores.end(), mscore1_3_2);
  BOOST_CHECK( itr1_3_2 != r_gameuseraaaa.scores.end());
  BOOST_CHECK(record1_3_2["score"] == itr1_3_2->score);

  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaaa), record1_3_3);
  get_record(r_gameuseraaaa, N(gameuseraaaa));
  //BOOST_TEST_MESSAGE( fc::json::to_pretty_string(r_gameuseraaaa) );
  musicscore_t mscore1_3_3{static_cast<uint16_t>(record1_3_3["music_id"].as_uint64()),  static_cast<uint32_t>(record1_3_3["score"].as_uint64())};
  auto itr1_3_3 = std::find(r_gameuseraaaa.scores.begin(),r_gameuseraaaa.scores.end(), mscore1_3_3);
  BOOST_CHECK( itr1_3_3 != r_gameuseraaaa.scores.end());
  BOOST_CHECK(record1_3_3["score"] == itr1_3_3->score);

  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaab), record2_1);
  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaab), record2_2);
  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaab), record2_3);

  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaac), record3_1);
  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaac), record3_2);
  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaac), record3_3);

  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaad), record4_1);
  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaad), record4_2);
  produce_block();
  trace = base_tester::push_action( N(eoseoultwcvr), N(regrecord), N(gameuseraaad), record4_3);

  //trace = base_tester::push_action( N(eoseoultwcvr), N(init), N(eoseoultwcvr), mvo());
  produce_block();

  record_t r_gameuseraaad;
  get_record(r_gameuseraaad, N(gameuseraaad));
  //BOOST_TEST_MESSAGE( fc::json::to_pretty_string(r_gameuseraaad) );
  musicscore_t mscore4_3{static_cast<uint16_t>(record4_3["music_id"].as_uint64()),  static_cast<uint32_t>(record4_3["score"].as_uint64())};
  auto itr4_3 = std::find(r_gameuseraaad.scores.begin(),r_gameuseraaad.scores.end(), mscore4_3);
  BOOST_CHECK(itr4_3 != r_gameuseraaad.scores.end());
  BOOST_CHECK(record4_3["score"] == itr4_3->score);
} FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()

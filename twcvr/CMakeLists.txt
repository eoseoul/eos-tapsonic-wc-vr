add_contract(twcvr twcvr ${CMAKE_CURRENT_SOURCE_DIR}/src/twcvr.cpp)
target_include_directories(twcvr.wasm
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(twcvr.wasm
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

#configure_file("${CMAKE_CURRENT_SOURCE_DIR}/abi/twcvr.abi" "${CMAKE_CURRENT_SOURCE_DIR}/bin/twcvr/twcvr.abi" COPYONLY)

#include_directories(${EOSIO_ROOT}/include)

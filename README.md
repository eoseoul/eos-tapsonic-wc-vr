# Tapsonic World Champion VR Contract
## Version : 1.3.0

These smart contracts are referred to game score.

Dependencies:
* [eosio v1.3.x](https://github.com/eosio/eos)
* [eosio.cdt v1.3.x](https://github.com/eosio/eosio.cdt)

To build the contracts and the unit tests:
* First, ensure that your __eosio__ is compiled to the core symbol for the EOSIO blockchain that intend to deploy to.
* Second, make sure that you have ```sudo make install```ed __eosio__.
The naming convention is codeaccount::actionname followed by a list of paramters.

After build:
* The unit tests executable is placed in the _build/tests_ and is named __unit_test__.
* The contracts are built into a _bin/\<contract name\>_ folder in their respective directories.
* Finally, simply use __cleos__ to _set contract_ by pointing to the previously mentioned directory.

## abi-gen
* eosio-cpp twcvr/include/twcvr/twcvr.hpp -o twcvr/abi/twcvr.wasm --abigen

## build
./build.sh

## test
cd build/tests
./unit_test --log_level=message

## deploy
### jungle
cleos -u http://jungle.cryptolions.io:18888 set contract eoseoultwcvr twcvr/bin/twcvr/ -p eoseoultwcvr

### live
cleos -u https://user-api.eoseoul.io set contract eoseoultwcvr twcvr/bin/twcvr/ -p eoseoultwcvr

## Actions
Note: When the required authority is `_self`, it means that the authority of the contract account is required.

#### regrecord
Required authority: `owner`
Parameters: `account_name owner, uint16_t music_id, uint32_t score`

Description: record game score for music. All fields are required.
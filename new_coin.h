#include <sstream>
#include <fstream>



using namespace std;

namespace Binance_plugin
{
	

	class coins : public QWidget, // ui dont forget
	{
		Q_OBJECT
	}
	private:
	
	//Copied from Bitcoin source
    const uint64_t COIN = 100000000;
    const uint64_t CENT = 1000000;
	
	uint32_t OP_CHECKSIG = 172; // This is expressed as 0xAC
    bool generateBlock = false;
    uint32_t startNonce = 0;
    uint32_t unixtime = 0; 
	
	typedef struct {
	/* Hash of Tx */
	uint8_t merkleHash[32];
	
	/* Tx serialization before hashing */
	uint8_t *serializedData;
	
	/* Tx version */
	uint32_t version;
	
	/* Input */
	uint8_t numInputs; // Program assumes one input
	uint8_t prevOutput[32];
	uint32_t prevoutIndex;
	uint8_t *scriptSig;
	uint32_t sequence;
	
	/* Output */
	uint8_t numOutputs; // Program assumes one output
	uint64_t outValue;
	uint8_t *pubkeyScript;
	
	/* Final */
	uint32_t locktime;
} Transaction;

/*
You can modify the MAX_MONEY variable to choose the max amount of coins, modify the stake age
 requirement and the stake %, modify the length of a block (30 seconds, 1 minute, 10 minutes), 
 and modify the reward per blog for which the code is found in main.cpp. This article is not going 
 to go into every single detail in creating a coin but will give a general overview of the process.
 */
 
 /*
 Step 6: Create a new genesis block. After modifying the code for the altcoin you must reset the code 
 in order to generate the genesis block which is the first block in the chain. In order to do so you 
 must set a few variables, the merkle hash, the genesis block, and the nOnce. Once set it will look 
 something like this:
*/


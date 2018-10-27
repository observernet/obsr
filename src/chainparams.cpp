// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2018 The OBSR developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (       0, uint256("0000070f9c4520b097379c2f6be965a4e3727acf250be9ae420ec6d10d0a02b5"))   // POW1 - PHASE 1 - Initial Premine block
    (       1, uint256("0000007ad4bb62d97a626d7179df1dfdbc0ea96687865f5000efab0ffeb0185f"))   // POW2 - PHASE 2 - Closed Mining start
    (     101, uint256("0000001ba0612b7bdbb997a3aa9d1d580120c6cb9acdd94f1abd96807e0c6114"))   // POS1 - PHASE 3 - Closed POS mining start
    (    1001, uint256("30b8a5dfd3c4e9ef0952ac77a6da7b65f5f4a4fa94fdf24c0994360df71d8fbc"))   // POS2 - PHASE 4 - Closed POS mining
    (    1492, uint256("8da46d9871055be809995d090ad673d749f24fa521dbe1bb02eaf775ed498a06"))
    (   20000, uint256("57f027034fc78dd30ed779f4dec698b06cfbd437e85e9f80b38451993ceb34c0"))   // POS2 - PHASE 4 - Closed POS mining end
    (   20001, uint256("7e38a5460b021b2a1d969c0d237805790db9c9773b8b90a18201c4e119f522bb"))   // POS3 - PHASE 5 - Public POS mining start
    (   25000, uint256("38f219f342df4ebf09464f971d5cd3be57b575df25e5e316ae1723c28fb74712"))
    (   26186, uint256("f32641d74c1a9b03561e53606d402a4a93e2325d1bd6a74b80c182f585290922"))
    (   27904, uint256("7ea6796ce8118af336e8dd0477e4bcb8db8ce4796729910aadaf0903897fe588")); // 1.0.1
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1540416629, // * UNIX timestamp of last checkpoint block
    65866,      // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
    (       0, uint256("0x0000070f9c4520b097379c2f6be965a4e3727acf250be9ae420ec6d10d0a02b5"))
    (       1, uint256("0x00000f5a3d0540fe8e48f5fdb3e03bc1dc3329177067cd9dfa112ffe72f9c00c"))
    (      99, uint256("0x000000e262fd60c2a04f6cb0e5f021e4de964f677c27d0916007db15771d3ebf"))   // Testlaunch PoW End
    (     101, uint256("0x00000032bc5d0f02cce93bb7f8b05515ec189e44b23bad9ba985ba7a5820c061"))   // Last PoW block
    (     102, uint256("0x607b3edd508b79ecc5d5bda2c2081fecb169dd11b48fee4fcf954787673e9322"))   // First PoS block
    (     150, uint256("0x500f4e82b8880a70a611c617ab9c506482c8a37edf3a46e5b15ab2909fbca84f"))   // Zercoin V1 first block
    (     200, uint256("0xc0d057c811435dd9083b6e19b192f70cd9476daa1a87f1e6665387de198a5a72"))   // Zercoin V1 first block
    (     205, uint256("0xd626da8a76d9597438f47c8af776624944eec28500d5eba0cc95ae23446158dd"));  // Last block
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1540603720,
    319,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1533686511,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xb4;
        pchMessageStart[1] = 0xa6;
        pchMessageStart[2] = 0x82;
        pchMessageStart[3] = 0xe9;
        vAlertPubKey = ParseHex("044bb16beb766d57f1895700bcf10adc5ae8827dee29b0aa358409a2893a22f5ddbb5f7b2274aef456e4f4afebb5302980ca17054f0adf6843fe5d21d6e39019f7");
        nDefaultPort = 9567;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // OBSR starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // OBSR: 1 day
        nTargetSpacing = 1 * 60;  // OBSR: 1 minute
        nMaturity = 20;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 11250000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 101;
        nModifierUpdateBlock = 1;
        nZerocoinStartHeight = 2;
        nZerocoinStartTime = 1538661894; //  GMT: Thursday, October 4, 2018 2:04:54 PM
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 49; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 3; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 99999999; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 1; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0*COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 150; //!> The block that zerocoin v2 becomes active - GMT: Friday, October 5, 2018 3:58:01 PM
        nEnforceNewSporkKey = 1538661892; //!> Sporks signed after GMT: Thursday, October 4, 2018 2:04:52 PM must use the new spork key
        nRejectOldSporkKey = 1538661893; //!> Reject old spork key after GMT: Thursday, October 4, 2018 2:04:53 PM

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "Senate Gets F.B.I. Inquiry on Kavanaugh; White House Is ‘Confident’ on Confirmation";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04079ebf2ae7a2041f67acbaec5b31c72f09fa6b5a4c04a012cf3344ee0475aa43625d6e161d50de26a38ec227cb559eeaf4dbc8138e1c3ea536ddf1607d4d8c7c") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1538661890; // GMT: Thursday, October 4, 2018 2:04:50 PM
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 33235910;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000070f9c4520b097379c2f6be965a4e3727acf250be9ae420ec6d10d0a02b5"));
        assert(genesis.hashMerkleRoot == uint256("0x0e36366ad7a4ce0f1979569a95ccd0ca085612d0d48f3aa9daa6262177d3163d"));

        vSeeds.push_back(CDNSSeedData("1", "main1.seeder.obsr.org")); // OBSR official seed 1
        vSeeds.push_back(CDNSSeedData("2", "main2.seeder.obsr.org")); // OBSR official seed 2
        vSeeds.push_back(CDNSSeedData("obsrseeder1.obsr.xyz", "main.obsrseeder1.obsr.xyz"));      // Obsr Asia1 Dev DNS Seeder
        vSeeds.push_back(CDNSSeedData("obsrseeder2.obsr.xyz", "main.obsrseeder2.obsr.xyz"));     // Obsr US1 Dev DNS Seeder

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 115); //  addresses start with a letter 'o'. Public keys start with '04' for uncompressed and '02' and '03' for compressed public address
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  //  Obsr script addresses start with '8'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 222);  //  Obsr compressed private keys (WIF) start with '8' (uncompressed) or 'Z' (compressed)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2E)(0x32)(0x1B).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x27)(0x1A).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x6f)(0x62)(0x73).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "041449e5ad74fd7c33c82117ab908da0d49779330f9503055a82f25983068063062a7099a49aed29cbac4a9d94b9b13f0b0756097e0fda444b4bd9bea2a237d28c";
        strSporkKeyOld = "040007976ea2750f5c3d9af5d8e802e381c71d1e661214adfb4cd61be489d4cdf49128cdac8e94302869dc2f4f38f0c89036c0381afe26b9620bc622cf5d11349b";
        strObfuscationPoolDummyAddress = "oHWR9kpVrCG4gdFtzrHQWmdmk6M41WszQ7";
        nStartMasternodePayments = 1403728576; //Wed, 25 Jun 2014 20:36:16 GMT

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zobsr to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x24;
        pchMessageStart[1] = 0x5c;
        pchMessageStart[2] = 0xfc;
        pchMessageStart[3] = 0x14;
        vAlertPubKey = ParseHex("04d220a8d9b9da1564293ff0f827ee33fa3320b2b20a5169e5d8a1b6171b843e5b00268b7c3700e8b9ce2092091e12ee9507b4de7fc4e297c9053dd344a477d8a3");
        nDefaultPort = 29567;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // OBSR: 1 day
        nTargetSpacing = 1 * 60;  // OBSR: 1 minute
        nLastPOWBlock = 101;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 110; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 11250000000 * COIN;
        nZerocoinStartHeight = 150;
        nZerocoinStartTime = 1538661894; //  GMT: Thursday, October 4, 2018 2:04:54 PM
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 180; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 99999999; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 99999999; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 170; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 200; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1538661892; //!> Sporks signed after GMT: Thursday, October 4, 2018 2:04:52 PM must use the new spork key
        nRejectOldSporkKey = 1538661893; //!> Reject old spork key after GMT: Thursday, October 4, 2018 2:04:53 PM

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1538661890; // GMT: Thursday, October 4, 2018 2:04:50 PM
        genesis.nNonce = 43138716;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000008c2f02402a0d4df651c0119941e45c9dcae64ec07215088048c3f450db9"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("1", "testnet1.seeder.obsr.org"));
        vSeeds.push_back(CDNSSeedData("2", "testnet2.seeder.obsr.org")); // OBSR official testseed 2"));
        vSeeds.push_back(CDNSSeedData("obsrtestseeder1.obsr.xyz", "testnet.obsrseeder1.obsr.xyz"));      // Obsr Asia1 Dev DNS Seeder
        vSeeds.push_back(CDNSSeedData("obsrtestseeder2.obsr.xyz", "testnet.obsrseeder2.obsr.xyz"));     // Obsr US1 Dev DNS Seeder

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 129); // Testnet  addresses start with 'u' or 't'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet obsr script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet obsr BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet obsr BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet obsr BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04bb8b30e137591e0ecacb9ea776249e2771e1075d3acba3f31d0cf0ee0e04e1b5427706e959649f20dc8e98796e9ba1863142350332a8b0f088c2ec0219bbc533";
        strSporkKeyOld = "04ee2a8a415ac76434ecca011fc0984221de3b59c176bec2ecfd58db5bbe20a7e30f8c85cab80d4a216e38729852be95ba6345d70aa6875aeca34c93ef0f68ae77";
        strObfuscationPoolDummyAddress = "tyuDwZMktGm9hXDr9C4BFZVnFQkRdoSJQ9";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x22;
        pchMessageStart[1] = 0xc6;
        pchMessageStart[2] = 0x6c;
        pchMessageStart[3] = 0xf8;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // OBSR: 1 day
        nTargetSpacing = 1 * 60;        // OBSR: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1538661890; // GMT: Thursday, October 4, 2018 2:04:50 PM
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 39884651;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 29568;
        assert(hashGenesisBlock == uint256("0x2ea7e583abd0698f31b8f5126ad1b22fb68cc697e298e683e918be63dd0ce3f5"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 39568;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}

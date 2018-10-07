// Copyright (c) 2011-2013 The Bitcoin Core developers
// Copyright (c) 2017 The PIVX developers
// Copyright (c) 2018 The OBSR developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p1 = uint256("0x000008004818317fce163222fc1d8a1b2b12b509c2ac281221307eb098ab25b2");
    uint256 p101 = uint256("0x0000003a43a68047ba373e281be2d2377d38e0c5c6b950321367bc5f3b0e5069");
    BOOST_CHECK(Checkpoints::CheckBlock(1, p1));
    BOOST_CHECK(Checkpoints::CheckBlock(101, p101));


    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(1, p101));
    BOOST_CHECK(!Checkpoints::CheckBlock(101, p1));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(1+1, p101));
    BOOST_CHECK(Checkpoints::CheckBlock(101+1, p1));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 101);
}

BOOST_AUTO_TEST_SUITE_END()

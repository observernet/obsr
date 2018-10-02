OBSR Core integration/staging repository
=====================================

[![Build Status](https://travis-ci.org/observernet/obsr.svg?branch=master)](https://travis-ci.org/observernet/obsr) [![GitHub version](https://badge.fury.io/gh/observernet%2Fobsr.svg)](https://badge.fury.io/gh/observernet%2Fobsr)

OBSR is an open source crypto-currency focused on fast private transactions with low transaction fees & environmental footprint.  It utilizes a custom Proof of Stake protocol for securing its network and uses an innovative variable seesaw reward mechanism that dynamically balances 90% of its block reward size between masternodes and staking nodes and 10% dedicated for budget proposals. The goal of OBSR is to achieve a decentralized sustainable crypto currency with near instant full-time private transactions, fair governance and community intelligence.
- Anonymized transactions using the [_Zerocoin Protocol_](http://www.obsr.org/zobsr).
- Fast transactions featuring guaranteed zero confirmation transactions, we call it _SwiftX_.
- Decentralized blockchain voting utilizing Masternode technology to form a DAO. The blockchain will distribute monthly treasury funds based on successful proposals submitted by the community and voted on by the DAO.

More information at [obsr.org](http://www.obsr.org)

### Coin Specs
<table>
<tr><td>Algo</td><td>Quark</td></tr>
<tr><td>Block Time</td><td>60 Seconds</td></tr>
<tr><td>Difficulty Retargeting</td><td>Every Block</td></tr>
<tr><td>Max Coin Supply (PoW Phase)</td><td>11,278,125,000 OBSR</td></tr>
<tr><td>Max Coin Supply (PoS Phase)</td><td>Infinite</td></tr>
<tr><td>Premine</td><td>8,437,500,000 OBSR*</td></tr>
</table>

Source forked from ([PIVX](https://pivx.org/)): [056b4d5cb183cc64f5af5812c560e22681745aea](https://github.com/PIVX-Project/PIVX/tree/056b4d5cb183cc64f5af5812c560e22681745aea)

### Reward Distribution

<table>
<th colspan=4>Genesis Block</th>
<tr><th>Block Height</th><th>Reward Amount</th><th>Notes</th></tr>
<tr><td>1</td><td>8,437,500,000 OBSR</td><td>Initial Pre-mine</a></td></tr>
</table>

### Rewards Breakdown

<table>
<th>Block Height</th><th>Masternodes</th><th>Pow/Pos Miner</th><th>Budget</th>
<tr><td>1-101</td><td>0% (0 OBSR)</td><td>100% (28,125,000 OBSR)</td><td>N/A</td></tr>
<tr><td>102-1001</td><td>75% (0 OBSR)</td><td>25% (0 OBSR)</td><td>N/A</td></tr>
<tr><td>1002-10000</td><td>75% (0 OBSR)</td><td>25% (0 OBSR)</td><td>N/A</td></tr>
<tr><td>10001-Infinite</td><td>75% (161.25 OBSR)</td><td>25% (53.75 OBSR)</td><td>N/A</td></tr>
</table>

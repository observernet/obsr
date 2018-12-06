OBSR Core version *1.0.2* is now available from:  <https://github.com/observernet/obsr/releases>

This is a new major version release, including various bug fixes and performance improvements, as well as updated translations.

Please report bugs using the issue tracker at github: <https://github.com/observernet/obsr/issues>

- [How to Upgrade](#how-to-upgrade)
- [Compatibility](#compatibility)
        - [MacOS 10.13 High Sierra warning](#macos-1013-high-sierra-warning)
- [Notable Changes](#notable-changes)
        - [Snapcraft](#snapcraft)
    - [PIVX Sources updated](#pivx-sources-updated)
- [*1.0.2* Change log](#102-change-log)
    - [Credits](#credits)

# How to Upgrade

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/OBSR-Qt (on Mac) or obsrd/obsr-qt (on Linux).


# Compatibility

OBSR Core is extensively tested on multiple operating systems using the Linux kernel, macOS 10.8+, and Windows 7 and later.

Microsoft ended support for Windows XP on [April 8th, 2014](https://www.microsoft.com/en-us/WindowsForBusiness/end-of-xp-support), No attempt is made to prevent installing or running the software on Windows XP, you can still do so at your own risk but be aware that there are known instabilities and issues. Please do not report issues about Windows XP to the issue tracker.

OBSR Core should also work on most other Unix-like systems but is not frequently tested on them.

### MacOS 10.13 High Sierra warning
:exclamation::exclamation::exclamation: MacOS 10.13 High Sierra :exclamation::exclamation::exclamation:

**Currently there are issues with the 3.x gitian release on MacOS version 10.13 (High Sierra), no reports of issues on older versions of MacOS.**

 
# Notable Changes

- Checkpoint to ensure staying on correct chain

### Snapcraft
- Add support for all desktops
- add obsr.tx

## PIVX Sources updated
- OBSR updated up to commit [abfceb](https://github.com/PIVX-Project/PIVX/commit/abfceb39a16bf7aa1b987fd2e1bf1fe6b2606882) ([PIVX tree](https://github.com/PIVX-Project/PIVX/tree/abfceb39a16bf7aa1b987fd2e1bf1fe6b2606882))

# *1.0.2* Change log

Detailed release notes follow. This overview includes changes that affect behavior, not code moves, refactors and string updates. For convenience in locating the code changes and accompanying discussion, both the pull request and git merge commit are mentioned.

931ebcd Snapcraft: add obsr-tx (obsr.tx)
ee5d997 Snapcraft: add support for additional desktops
d2f6824 Add a security warning to the debug console's default output.
71f3ae8 Finalize cleanup of sync.cpp/h
78a4ece Use c++11 nullptr instead of macros or void(0) in sync.cpp/h
f0ea581 Remove unused fTry from push_lock
26c37a1 Initialize lockstack to prevent null pointer deref
bb61680 Remove Boost dependency from sync.cpp
0c4bea2 Do not record zerocoin tx's in ConnectBlock() if it is fJustCheck
65fb20b Unify shutdown proceedure in init rather than per-app
ad913b3 Fix zOBSR spend when too much mints are selected
1467eb2 WIN32 Seed Cleanup: Move nLastPerfmon behind win32 ifdef. Code to avoid calling Perfmon too often is only needed when perfmon is actually going to get called. This is not intended to make any functional difference in the addition of entropy to the random pool.
62c5406 Show BIP65 soft-fork progress in getblockchaininfo
280c955 7 day CLTV activation
f236067 Add action to hide orphans in overview and txlist
ba2a288 Fix RPCTimerInterface ordering issue (https://github.com/bitcoin/bitcoin/pull/7317)
88c245b Fix checklocktime verify unit tests
a75ee63 Update changes for CLTV
7fd5f3a Ported CLTV from BIP65 to OBSR. Added checks for supermajority activation.
33b14d6 Bump version to v1.0.2
b1eef29 Add gitian build python script
0f5b3ea Update accumulator checkpoints
0f15bb1 Update checkpoints
9d4fd91 Set release to false on master
1b4b246 Set new checkpoint
9583686 Bump version
6e27b70 Update snapcraft.yaml
b6571f3 Replace help address
50b196b Update README.md
5039431 Update README.md
a0c6fcd Update README.md
7cdbf58 Update README.md
b3cd1bf Update README.md
cedc253 Update README.md
ba57dbd Remove architectures and reenable all archs again by default despite not working on arm64
f8a2a35 Update snapcraft
c86d4bc Cleanup snapcraft.yaml
a2c76b1 Update transifex url
 
## Credits

Thanks to everyone who directly contributed to this release:

- 21E14
- Benjamin Allred
- blondfrogs
- Fuzzbawls
- OBSERVER
- observerdev
- presstab
- random-zebra
- warrows

As well as everyone that helped translating on [Transifex](https://www.transifex.com/observer/obsr/dashboard/), the QA team during Testing and the Node hosts supporting our Testnet.

OBServer Core version 1.2.0.0 is now available from:

  <https://github.com/observernet/obsr/releases/tag/v1.2.00>

This is a new major version release, including new features, various bug
fixes and performance improvements, as well as updated translations.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/observernet/obsr/issues>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has
completely shut down (which might take a few minutes for older
versions), then run the installer (on Windows) or just copy over
`/Applications/OBSR-Qt` (on Mac) or `obsrd`/`obsr-qt` (on
Linux).

Compatibility
=============

OBServer Core is supported and extensively tested on operating systems
using the Linux kernel, macOS 10.10+, and Windows 7 and newer. It is not
recommended to use OBServer Core on unsupported systems.

OBServer Core should also work on most other Unix-like systems but is not
as frequently tested on them.

From 1.2.0 onwards, macOS <10.10 is no longer supported. 1.2.0 is
built using Qt 5.9.x, which doesn't support versions of macOS older than
10.10. Additionally, OBServer Core does not yet change appearance when
macOS "dark mode" is activated.

1.2.0 change log
================

- update snapcraft to bionic (core18) (observerdev)
- fix-use-snap-instead--of-dirty (observerdev)
- snap - use snap instead of dirty (observerdev)
- revert dirty for non snap (observerdev)
- snap - use only SHORTNAME and HOST as custom vars (observerdev)
- Release v1.1.01 for snap bionic, bump to v1.1.01 (observerdev)
- release false and bump version to 1.1.99 (observerdev)
- snap - update readme.md (observerdev)
- snap - readme.md add html tags for frame (observerdev)
- snap - readme.md remove iframe (observerdev)
- 4 more scripts running (ckti)
- Remove whitespace in test_runner (ckti)
- incorrect arg (Steven)
- update contrib/debian (observerdev)
- update libzerocoin (observerdev)
- update QT locales (observerdev)
- update test suite (observerdev)
- update contrib (observerdev)
- update gitian keys (observerdev)
- Update depends (observerdev)
- update doc (observerdev)
- Update copyrights for some QT files (observerdev)
- update QT (observerdev)
- update src/tests (observerdev)
- update makefile's and config (observerdev)
- obsr core upgrade (observerdev)
- post upgrade fixes (observerdev)
- fix qt localizations (observerdev)
- fix redundant declarartion (observerdev)
- fix splashscreen copyright (observerdev)
- add checkpoint on main net (observerdev)
- set public coin spend block height (observerdev)
- fix links (observerdev)
- add OBSR string to splashscreen (observerdev)
- bump snapcraft version (observerdev)
- fix transifex link in readme (observerdev)
- clear base58_keys_valid.json (observerdev)
- reapply lineareze fix (observerdev)
- add linearize to lint whitelist (observerdev)
- fix timedata (observerdev)
- fix functional tests (observerdev)
- move zerocoin spend block for 1 week and set testnet zerocoin spend block (observerdev)
- disable wallet_basic.py for test runner (observerdev)
- disable non working tests for test runner (observerdev)
- bump version 1.2.00 and set as release (observerdev)
- update gitian descriptors version (observerdev)
- trigger building stable snap v1.2.00 (observerdev)
- rename snaps icon from bitcoin to obsr (observerdev)
- Add blockhash + datadir to information tab (Mrs-X)
- add pythong scripts to vscode debugger (observerdev)

Credits
=======

Thanks to everyone who directly contributed to this release:

- ckti
- Mrs-X
- observerdev
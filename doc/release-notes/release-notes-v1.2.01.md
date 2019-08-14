OBServer Core version 1.2.0.1 is now available from:

  <https://github.com/observernet/obsr/releases/tag/v1.2.01>

This is a new obligatory release, including various bug
fixes and performance improvements.

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

- [fix] Fix merge issue: masternode colleteral amount (Charunder)
- Replace CLTV (BIP65) soft fork check with its corresponding activation heights (Charunder)
- [FIX] Better precision for GetPriority()'s floating point operation (Charunder)

Credits
=======

Thanks to everyone who directly contributed to this release:

- Charunder
# Challenge Files

This directory contains the original CTF challenge files from HackTheBox.

## Files
- `encrypt` - The vulnerable encryption binary
- `flag.enc` - The encrypted flag file (32 bytes: 4-byte seed + 28-byte encrypted flag)

## Challenge Description
The encryption program uses a pseudo-random number generator (PRNG) seeded with a value stored at the beginning of the encrypted file. This design flaw allows the encryption to be reversed if you can extract the seed.
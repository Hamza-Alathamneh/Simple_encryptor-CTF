# Solution

This directory contains the decryption solution for the Simple Encryptor CTF challenge.

## How It Works

The decryptor reverses the encryption by:
1. Reading the seed from the first 4 bytes of `flag.enc`
2. Initializing the PRNG with that seed
3. Applying the same XOR and rotation operations to decrypt

## Compilation

```bash
g++ Encryptor.cpp -o decrypt
```

## Usage

1. Make sure `flag.enc` is in the same directory
2. Run the decryptor:
   ```bash
   ./decrypt
   ```

The decrypted flag will be printed to stdout.

## Key Insight

The vulnerability lies in storing the PRNG seed in plaintext. Since `rand()` is deterministic when seeded with the same value, we can reproduce the exact sequence of "random" values used during encryption and reverse the process.
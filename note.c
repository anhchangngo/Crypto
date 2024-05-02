// Euler’s phi function, Φ(𝑚) is the number of positive integers less than 𝑚 that are relatively prime to 𝑚.

// Kerchhoff’s principle
// A cryptosystem should be secure even if the attacker knows all details about the system, with the exception of the secret key. 
// In particular, the system should be secure when the attacker knows the encryption and decryption algorithms.

// Cryptanalysis Classification
// Classical Cryptanalysis : recovering x or k from y
// Implementation Attacks : try to extract a secret key from side-channel
// analysis, e.g., power measurement, electromagnetic radiation, etc.
// Social engineering : obtain a secret key by involving humans, e.g., trick a user into giving her password.

// Brute-Force Attack (Exhaustive Key Search) against Symmetric Ciphers
// Requires at least 1 plaintext-ciphertext pair (𝑥0, 𝑦0) 
// Check all possible keys K until: 𝑑𝐾 (𝑦0) = 𝑥0
// How many keys do we need?

// Key length     Key space      Time for all keys searching
// 64 bits           2^64            few hours or days
// 128 bits          2^128           decades without quantum computer
// 256 bits          2^256           decades with quantum computer

// Shift Cipher - Description
// Let 𝑘, 𝑥, 𝑦 ∈ 0, 1, ..., 25
// Encryption: 𝑦 = 𝑒𝑘(𝑥) ≡ (𝑥 + 𝑘) mod 26 
// Decryption: 𝑥 = 𝑑𝑘(𝑥) ≡ (𝑦 − 𝑘) mod 26

// Affine Cipher
// A key is consisted of two parts: 𝑘 = (𝑎, 𝑏) Let 𝑘, 𝑥, 𝑦 ∈ 0, 1, ..., 25
// Encryption: 𝑦 = 𝑒𝑘 (𝑥) ≡ (𝑎.𝑥 + 𝑏) mod 26
// Decryption: 𝑥 = 𝑑𝑘 (𝑥) ≡ (𝑎−1.(𝑦 − 𝑏)) mod 26 gcd(a,26)=1, then 𝑎 = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25}

// -----------------------------------------------------------------------------
// Session 3: Introduction to Cryptography - Symmetric Cryptography
// 1 Symmetric ciphers
// Stream ciphers
// A5/1 cipher
// RC4 - Keystream generation

// Symmetric ciphers
// A key 𝐾 of 𝑛 bits is stretched into a long keystream S 
//             𝑆𝑡𝑟𝑒𝑎𝑚𝐶𝑖𝑝h𝑒𝑟(𝐾) = 𝑆

// Stream cipher Encryption and Decryption
// 𝑥𝑖 , 𝑦𝑖 , 𝑠𝑖 ∈ {0, 1}: individual bits of plaintext, ciphertext and keystream 
// Encryption: 𝑦𝑖 = 𝑥𝑖 + 𝑠𝑖 (𝑚𝑜𝑑 2)
// Decryption: 𝑥𝑖 = 𝑦𝑖 + 𝑠𝑖 (𝑚𝑜𝑑 2)

// Stream ciphers
// Modulo 2 addition is equivalent to XOR operation 
// Plaintext 𝑃, Ciphertext 𝐶       𝐶=𝑃⊕𝑆 
//                                 𝑃=𝐶⊕𝑆

// A5/1 cipher
// designed for hardware, used in GSM
// Key of 64 bits initially fills in 3 Linear Feedback Shift Registers (LFSRs):
// X 19 bits 
// Y 22 bits 
// Z 23 bits
// How to obtain every single keystream bit?

// When they step?
// Majority vote function: 𝑚 = 𝑚𝑎 𝑗 (𝑥, 𝑦, 𝑧), 𝑚 = 0 when majority of (x,y,z) is 0, otherwise 𝑚 = 1
// In A5/1, 𝑚 = 𝑚𝑎𝑗 (𝑥8, 𝑦10, 𝑧10)
// if 𝑥8 = 𝑚, then X steps 
// if 𝑦10 = 𝑚, then Y steps 
// if 𝑧10 = 𝑚, then Z steps

// RC4 algorithm
// Designed for software, e.g, SSL, WEP... Key: N bytes, 1 ≤ 𝑁 ≤ 256
// Lookup table: a 256-byte array S
//         - Initialized from the key to the identify permutation: Key-scheduling Algorithm (KSA)
//         - can be one of all 256 possible permutations of 256 bytes
// From the lookup table, a keystream byte is generated at each step: Pseudo-random generation algorithm (PRGA)

// RC4 - Keystream generation

// KSA pseudo code:
// for 𝑖= 1 to 255 do 
//     𝑆[𝑖] = 𝑖
//     𝐾[𝑖] = 𝑘𝑒𝑦[𝑖 𝑚𝑜𝑑 𝑁] 
// endfor
// j=0 
// for 𝑖 = 0 to 255 do
//     𝑗 = (𝑗 + 𝑆[𝑖] + 𝐾[𝑖]) 𝑚𝑜𝑑 256 
//     Swap(S[i], S[j])
// endfor
// i=j=0

// PRGA pseudo code: 
// 𝑖 = (𝑖 + 1) 𝑚𝑜𝑑 256
// 𝑗 = ( 𝑗 + 𝑆[𝑖]) 𝑚𝑜𝑑 256 
// 𝑆𝑤𝑎𝑝(𝑆[𝑖],𝑆[𝑗])
// 𝑡 = (𝑆[𝑖] + 𝑆[𝑗]) 𝑚𝑜𝑑 256 
// 𝐾𝑒𝑦𝑠𝑡𝑟𝑒𝑎𝑚𝐵𝑦𝑡𝑒 = 𝑆[𝑡]

// ----------------------------------------------------------------------
// Session 4: Symmetric Cryptography - Block Cipher and Operation Modes

// 1 Symmetric ciphers
//     Block ciphers 
//         Feistel Cipher DES
//         AES
//         Mode of Operation
//         Exhaustive key search revisited 
//         Increasing the security of Block cipher

// Block ciphers
// Claude Shannon: There are two primitive operations with which strong encryption algorithms can be built:
//     - Confusion: An encryption operation where the relationship between key and ciphertext is obscured (e.g., substitution).
//     - Diffusion: An encryption operation where the influence of one plaintext symbol is spread over many ciphertext symbols with the goal of hiding statistical properties of the plaintext (e.g., permutation).

// Combining the two primitives to build a so called product ciphers 
// Most of today’s ciphers are product ciphers as they consist of rounds
// which are applied repeatedly to the data.

// Common block ciphers
// Feistel Cipher 
// DES
// AES

// Data Encryption Standard
// DES overview:
//     - Developed by IBM, based on Lucifer cipher
//     - Standardized in 1977 by the National Bureau of Standards (NBS) today called National Institute of Standards and Technology (NIST)
//     - Features:
//         Key length: ? 
//         Block length?
//         how many rounds? 
//         Subkey length?

// S-box substitution
// Eight substitution tables
// 6 bits of input, 4 bits of output
// Non-linear, crucial element for DES security
// 𝑆(𝑥1) ⊕ 𝑆(𝑥2) ≠ 𝑆(𝑥1 ⊕ 𝑥2)

// Key schedule
// PC-1: reduce 64 bits to 56 bits by ignoring every 8 bits and permute
// Round 1, 2, 9, 16: rotate left by 1 bits, others by 2 bits
// Rotation is only taken place within either left or right half

// Decryption
// Key schedule is reversed in decryption

// Summary of DES
// From above description of DES algorithm and key schedule, what we can summarize?
//     DES Features:
//         Key length: 56 bits
//         Block lenghth: 64 bits 
//         Subkey length: 48 bits 
//         Number of rounds: 16
// 56-bit key is susceptible to an exhaustive key search

// Advanced Encryption Standard
// AES overview:
// - The most widely used symmetric cipher today 
// - Approved by US NIST in 2001 after years of 
// - byte-oriented cipher

// AES Encryption Algorithm
// Features:
// - block size: 128 bits
// - 3 key lengths: 128/192/ 256 bits (subkey length =?)
// - Number of rounds: 10/12/14 
// - Each round: 3 layers

// AES Encryption Algorithm
// 3 layers:
//     Key addition layer
//     Byte substitution layer
//     Diffusion layer
// Data path (state): 128 bits = 16 bytes

// AES Internal structure
// Plaintext block is arranged in matrix of 16 bytes 
// Key bytes are arranged in matrix of 4 row x n columns

// AES Internal structure - Round function
// Round function for round 1,2,...,𝑛𝑟−1

// AES Round function - Byte substitution layer
// Consist of 16 S-boxes 
// S-boxes are:
//     identical
//     non-linear
//     one-to-one mapping of input and output
// In implementation, S-boxes are realized as a look up table (mapping)

// AES Round function- Diffusion layers
// provides diffusion 
// consist of two sublayers:
//     ShiftRows sublayer: permutation 
//     MixColumn sublayer: mixes block of 4 bytes
// perform linear operation on state matrices A and B (input matrices)
//         𝐷𝑖 𝑓 𝑓 (𝐴) + 𝐷𝑖 𝑓 𝑓 (𝐵) = 𝐷𝑖 𝑓 𝑓 (𝐴 + 𝐵)

// ShiftRows sublayer
// Rows of state matrix are shifted cyclically:

//    B0 B4 B8 B12     no shift
//    B5 B9 B13 B1     one position left shift
//    B10 B14 B2 B6    two position left shift
//    B15 B3 B7 B11    three position left shift

// MixColumn sublayer
// Mixes each column of the state matrix
//         𝑀𝑖𝑥𝐶𝑜𝑙𝑢𝑚𝑛(𝐵) = 𝐶
// Each 4-byte column is multiplied by a fixed 4x4 matrix
// All arithmetic is done in Galois Feild GF(2^8)

// Key Addition layer
// Input: 16-byte state matrix C and subkey 𝑘 𝑗 
// Output: 𝐶 ⊕ 𝑘 𝑗

// AES Key schedule
// 1 word = 32 bits
// In each round i,subkey 𝑘𝑖 = 4 words 𝑊[4𝑖+𝑗], 𝑗 = 0..3 
// Different key schedule for different key size

// AES Key schedule - 128-bit key
// The leftmost word: 𝑊[4𝑖] = 𝑊[4(𝑖 − 1)] ⊕ 𝑔(𝑊[4𝑖 − 1])
// The remain words: 𝑊[4𝑖 + 𝑗] = 𝑊[4𝑖 + 𝑗 − 1] ⊕ 𝑊[4(𝑖 − 1) + 𝑗]

// g function:
//     S-box substitution: adds nonlinearity to the schedule
// RC[i]: a round coefficient, 8-bit value, vary from round to round

// AES Decryption
// All layers must be inverted for decryption:
//     Inv MixColumn layer: inverse of the 4x4 matrix
//     Inv ShiftRows layer: all the state of the state matrix B are shifted in the opposite direction
//     Inv Byte substitution: inverse S-Box 
// Key schedule for decryption:
//     Subkeys are needed in reversed order

// Implementation in Software
// One requirement of AES was the possibility of an efficient software implementation
// Straightforward implementation is well suited for 8-bit processors (e.g., smart cards), but inefficient on 32-bit or 64-bit processors
// A more sophisticated approach: Merge all round functions (except the key addition) into one table look-up
//     - This results in four tables with 256 entries, where each entry is 32 bits wide 
//     - One round can be computed with 16 table look-ups
// Typical SW speeds are more than 1.6 Gbit/s on modern 64-bit processors

// AES Security
// Brute-force attack: ?
// Analytical attack: There is currently no analytical attack against AES known which has a complexity less than a brute-force attack

// Mode of Operation
// How to encrypt more than one single block of plaintext? 
//     - Electronic Code Book Mode (ECB)
//     - Cipher Block Chaining Mode (CBC)
//     - Cipher Feedback Mode (CFB)
//     - Output Feedback Mode (OFB) Counter mode (CTR)
//     - others
// They provides: confidentiality, integrity and authenticity

// Electronic Code Book Mode
// The length of the plaintext must be an exact multiple of the block size of the cipher, if not it must be padded
// Each block is encrypted separatedly
// b-bit plaintext block 𝑥𝑖 has 𝑏 bits, b-bit ciphertext block 𝑦𝑖 
// Message exceeding b-bit must be partitioned into b-bit blocks

// ECB Mode
// Let e() be a block cipher of block size b, and let 𝑥𝑖 and 𝑦𝑖 be bit strings of length b.
//     Encryption: 𝑦𝑖 = 𝑒𝑘(𝑥𝑖),𝑖 ≥ 1 
//     Decryption: 𝑥𝑖 = 𝑒−1(𝑒𝑘(𝑥𝑖)),𝑖 ≥ 1

// ECB security
// Substitution Attack:
// Example: electronic bank transfer: Block #1.Sending Bank A #2.Sending Account #3.Receiving Bank B #4.Receiving Account #5. Amount
// Attacker: transfers repeatedly from his account in bank A to his account in bank B
//     He obtains ciphertext for block 1,3,4
//     replaces block 4 of other transfers with his block 4 then all transfers are redirected to his account

// ECB Advantages and Disadvantages
// Advantages:
// no block synchronization between sender and receiver is required
// bit errors caused by noisy channels only affect the corresponding block but not succeeding blocks
// Block cipher operating can be parallelized, then advantage for high-speed implementations
// Disadvantages: ECB encrypts highly deterministically
// identical plaintexts result in identical ciphertexts
// an attacker recognizes if the same message has been sent twice
// plaintext blocks are encrypted independently of previous blocks
// an attacker may reorder ciphertext blocks which results in valid plaintext

// Cipher Block Chaining Mode
// The encryption of all blocks are chained together
// The encryption is randomized by using an initialized vector (IV)

// CBC-Encryption and Decryption
// We do not have to keep IV secret. Why?
// Nguyen Minh Huong (ICT Department, USTH) ICT Course: Introduction to Cryptography January 3, 2023 39 / 53
// Encryption and Decryption in CBC mode
// Let e() be a block cipher of block size b; let 𝑥𝑖 and 𝑦𝑖 be bit strings of length b; and IV be a nonce of length b.
// Encryption (first block): 𝑦1 = 𝑒𝑘 (𝑥1 ⊕ 𝐼𝑉)
// Encryption (general block): 𝑦𝑖 = 𝑒𝑘 (𝑥𝑖 ⊕ 𝑦𝑖−1), 𝑖 ≥ 2
// Decryption (first block): 𝑥 = 𝑒 −1(𝑦 ) ⊕ 𝐼𝑉 1𝑘1
// Decryption (general block): 𝑥 = 𝑒 −1(𝑦 ), 𝑖 ≥ 2 𝑖𝑘𝑖

// Substitution attack on CBC
// Example of electronic bank transfer
// If IV is chosen for every wire transfer, attack will not work 
// If IV is kept the same, the attacker would recognize
// Why?

// Output Feedback Mode
// Is used to build synchronous stream cipher from a block cipher 
// key stream is generated blockwise fashion
// Output of the cipher: key stream bits 𝑆𝑖 to encrypt plaintext bits using the XOR operation

// OFB - Encryption and Decryption
// Encryption and decryption in OFB mode
// Let e() be a block cipher of block size b; let 𝑥𝑖, 𝑦𝑖 and 𝑠𝑖 be bit strings of length b; and IV be a nonce of length b.
// Encryption(first block): 𝑠1 = 𝑒𝑘 (𝐼𝑉) and 𝑦1 = 𝑠1 ⊕ 𝑥1 
// Encryption (general block): 𝑠𝑖 = 𝑒𝑘 (𝑠𝑖−1), 𝑖 ≥ 2
// Decryption (first block): 𝑠1 = 𝑒𝑘 (𝐼𝑉) and 𝑥1 = 𝑠1 ⊕ 𝑦1 
// Decryption (general block): 𝑠𝑖 = 𝑒𝑘 (𝑠𝑖−1) and 𝑥𝑖 = 𝑠𝑖 ⊕ 𝑦𝑖, 𝑖 ≥ 2

// Cipher Feedback Mode
// Same requirement of plaintext size as ECB
// Uses block cipher as building block for an asynchronous stream cipher
// Key stream 𝑆𝑖 is generated in blockwise fashion and function of ciphertext
// non-deterministic (if the IV is a nonce)

// CFB-Encryption and Decryption
// Encryption and Decryption in CFB mode
// Let e() be a block cipher of block size b; let 𝑥𝑖 and 𝑦𝑖 be bit strings of length b; and IV be a nonce of length b.
// Encryption (first block): 𝑦1 = 𝑒𝑘 (𝐼𝑉) ⊕ 𝑥1 
// Encryption (general block): 𝑦𝑖 = 𝑒𝑘 (𝑦𝑖−1) ⊕ 𝑥𝑖, 𝑖 ≥ 2 
// Decryption (first block): 𝑥1 = 𝑒𝑘 (𝐼𝑉) ⊕ 𝑦1 
// Decryption (general block): 𝑥𝑖 = 𝑒𝑘 (𝑦𝑖−1) ⊕ 𝑦𝑖, 𝑖 ≥ 2

// Counter Mode
// Uses a block cipher as a stream cipher
// Key stream is generated in blockwise fashion
// The counter assumes a different value everytime a new key stream block is computed

// CTR - Encryption and Decryption
// Encryption and Decryption in CTR mode
// Let e() be a block cipher of block size b, and let 𝑥𝑖 and 𝑦𝑖 be bit strings of length b. The concatenation of the initialization value IV and the counter 𝐶𝑇𝑅𝑖 is denoted by (𝐼𝑉||𝐶𝑇𝑅𝑖) and is a bit string of length b.
// Encryption:𝑦𝑖 =𝑒𝑘(𝐼𝑉||𝐶𝑇𝑅𝑖)⊕𝑥𝑖,𝑥≥1 
// Decryption:𝑥𝑖 =𝑒𝑘(𝐼𝑉||𝐶𝑇𝑅𝑖)⊕𝑦𝑖,𝑖≥1

// Exhaustive key search revisited
// A brute-force attack can produce false positive results
// keys 𝑘𝑖 that are found are not the one used for the encryption
// The likelihood of this is related to the relative size of the key space and the plaintext space
// brute-force attack is still possible, but several pairs of plaintext–ciphertext are needed

// Exhaustive key search revisited
// Given a block cipher with a key length of 𝑘 bits and block size of n bits, as well as t plaintext–ciphertext pairs (𝑥1, 𝑦1), ..., (𝑥𝑡 , 𝑦𝑡 ), the likelihood of false keys which encrypt all plaintexts to the corresponding ciphertexts is:
// 2^ (𝑘−𝑡∗𝑛)

// Increasing the security of Block cipher
// Multiple Encryption Key whitening

// Multiple Encryption- Double Encryption
// A plaintext x is first encrypted with a key 𝑘𝐿, and the resulting ciphertext is encrypted again using a second key 𝑘𝑅

// Key lengths: k bits, then key space (number of encryptions) =?

// Double Encryption- Meet-in-the-middle attack
// Phase 1: encryption to compute the look up table 𝑍𝐿,𝑖
// Phase 2: decryption (result 𝑍𝑅,𝑖) to check whether any 𝑍𝑅,𝑖 equal to 𝑍𝐿,𝑖 The complexity or number of encryption or decryption = ?
// How much it is more secure than single encryption?

// Key whitening
// Make block cipher more resistant against brute-force attack

// Key whitening for block ciphers
// Encryption:𝑦=𝑒𝑘,𝑘1,𝑘2 =𝑒𝑘(𝑥⊕𝑘1)⊕𝑘2
// Decryption:𝑥=𝑒−1 ,𝑘 ,𝑘 (𝑦)=𝑒 −1(𝑦⊕𝑘 )⊕𝑘

// Security of key whitening: key length 𝑘 bits, block length 𝑛 bits A naive brute-force attack: 2(𝑘+2∗𝑛) search steps Meet-in-the-middle attack: 2(𝑘+𝑛) search steps

// ----------------------------------------------------------------
// Session 5: Asymmetric Cryptography - Introductions

// 1 Introduction to Public Key Cryptography Symmetric cryptography issues
// Principle of asymmetric cryptography
// Security mechanisms of Public Key Cryptography

// Symmetric cryptography issues
// Key Distribution: The key must be established between Alice and Bob in secured channel
// Number of keys: a key for each pairs of users
// No protection against cheating of either Alice or Bob

// Principle of asymmetric cryptography
// Trap door one-way function A key pair:
// public key 𝑘1: is broadcast to anyone private key 𝑘2 :is kept secret
// Algorithm: plaintext M, Ciphertext C
// 𝐶 = 𝑒𝑘1 (𝑀)
// 𝑀 = 𝑒𝑘2 (𝐶)

// Security mechanisms of Public Key Cryptography
// Key Distribution without a pre-shared secret key, e.g, Diffie-Hellman key exchange, RSA
// Digital Signatures
// providing integrity
// preventing ’reputation’
// idetification: using challenge-response protocols
// Encryption, e.g, RSA

// Practical protocols
// Most protocol are hybrid protocol, incorporate both symmetric and public-key algorithms:
// Key exchange and digital signature: use asymmetric algorithms (slow) Encryption: uses symmetric ciphers (fast)

// How to build Public-Key algorithm
// Asymmetric schemes are based on one-way function 𝑓 () Computing 𝑦 = 𝑓 (𝑥): easy
// Computing𝑥= 𝑓−1(𝑦):infeasible
// One-way function are based on mathematically hard problems:
// Factoring integers: given a composite integer 𝑛, find its prime factors Discrete Logarithm: given 𝑎, 𝑦, and 𝑚, find 𝑥 such that 𝑎𝑥 = 𝑦 𝑚𝑜𝑑 𝑚 Elliptic Curves: Generalization of discrete logarithm

// -----------------------------------------------------------------
// Session 6: Asymmetric Cryptography - RSA Cryptosystem and Diffie-Hellman Key Exchange

// 1 RSA Cryptosystem
// Generating RSA public and private keypair Encryption-Decryption
// Proof of the correctness
// Repeated squaring
// Speed up RSA
// Cryptanalysis
// 2 Diffie-Hellman Key exchange
// 3 Application of Public Key cryptography

// Overview of RSA
// be made practical by Rivest, Shamir and Aldeman
// the most widely used asymmetric cryptosystem
// Applications: Transport of (symmetric) keys and Digital Signature

// RSA Key Generation
// Choose 2 large prime numbers 𝑝, 𝑞: 𝑁 = 𝑝 ∗ 𝑞 
// Choose 𝑒 relative prime to (𝑝 − 1)(𝑞 − 1) 
// Find 𝑑:
//     𝑒𝑑=1𝑚𝑜𝑑(𝑝−1)(𝑞−1) ⇐⇒ 𝑒−1 𝑚𝑜𝑑(𝑝−1)(𝑞−1)=𝑑
// RSA key pair consists of: 
//     Publickey: (𝑁,𝑒)
//     Private key: 𝑑
//     where N: modulus, e: encryption exponent, d: decryption exponent
// N has 1024 bits or 2048 bits or larger

// Encryption - Decryption
// Encryption: 𝐶 ≡ 𝑀𝑒 (𝑚𝑜𝑑𝑁) 
// Decryption: 𝑀 ≡ 𝐶𝑑 (𝑚𝑜𝑑𝑁)

// Proof of correctness
// Euler’s phi function reminds:
// - 𝜙(𝑚) is the number of positive integers less than 𝑚 that are relatively
// prime to 𝑚
// - For any prime number 𝑝: 𝜙(𝑝) = (𝑝 − 1)
// - If 𝑝, 𝑞 are prime: 𝜙(𝑝 ∗ 𝑞) = (𝑝 − 1)(𝑞 − 1)
// Euler’s Theorem
// If𝑥isrelativeprimeto𝑛then𝑥𝜙(𝑛) ≡1𝑚𝑜𝑑𝑛

// Cryptanalysis
// Protocol attack 
// Mathematical attack 
// Side-channel attack

// Diffie-Hellman Key exchange - Overview1
// Proposed in 1976 by Whitfield Diffie and Martin Hellman
// Widely used, e.g. in Secure Shell (SSH), Transport Layer security (TLS), Internet Protocol Security (IPSec)
// Used to establish a shared key, not usually for encryption

// Diffie-Hellman Key Exchange

// Discrete Logarithm problem:
// Given integers 𝑔, 𝑝, 𝑔𝑘 𝑚𝑜𝑑 𝑝, find 𝑘 =⇒ Very difficult to solve

// Diffie-Hellman Key Echange setup:
// Choose a large prime 𝑝 and a (integer) generator 𝑔 ∀𝑥∈{1,2,...,𝑝−1},∃𝑛: 𝑥≡𝑔𝑛(𝑚𝑜𝑑𝑝)
// 𝑔, 𝑝 are public

// -----------------------------------------------
// Session 7: Digital signature and Hash function
// 1 Digital Signature
//     Principles of Digital Signatures
//     RSA signature scheme
//     Elgamal Digital Signature
//     Digital signature algorithm(DSA)
// 2 Hash function 
//     Overview
//     Security requirements of Hash functions 
//     Hash function algorithms

// Digital Signature
// Digital signature provides:
// Message authentication: assures that message is authentic to one user (the same functionality of hand-written signature)
// Integrity 
// Nonrepudiation

// Principles of Digital Signatures
// Key generation? Signature Algorithm? Verification function?

// RSA signature scheme
// Generate private keys and public keys: use the RSA key generation Generate signature: "encrypt" the message with private key to obtain 𝑠,
// append 𝑠 to the message
// Verify signature: "decrypt" the signature with public key and compare it
// with the message

// RSA signature scheme - Details
// Key generation:
// Private key: 𝑘 𝑝𝑟 = 𝑑 Public key: 𝑘 𝑝𝑢𝑏 = (𝑛, 𝑒)

// RSA Signature Scheme - Security
// 𝑛 needs to be at least 1024 bits Forgery Attack:
// Trudy can generate a valid signature for a random message Method:
// 1 Choose a signature
// 2 Compute the respectively message from 𝑘 𝑝𝑢𝑏
// Trudy can claim to Alice that he’s Bob
// Solution against Forgery Attack: Padding Scheme

// Elgamal Digital Signature
// Key generation?
// Signature generation and Verification
// Example: Bob wants to send a message to Alice. This time, it should be signed with the Elgamal digital signature scheme. Describe the key generation, signature generation and verification process.
// 𝑝=29,𝛼=2,𝑑=12,𝑘𝐸 =5

// Digital Signature Algorithm (DSA)-Overview
// Federal US Government standard for Digital Signature Proposed by NIST
// Based on Elgamal signature scheme
// Signature length: 320 bits
// Signature verification is slower compared to RSA

// DSA - Key Generation
// Key generation:
// 1 Generate a prime 𝑝: 21023 < 𝑝 < 21024
// 2 Findaprimedivisor𝑞of𝑝−1:2159 <𝑞<2160
// 3 Find𝛼:𝑜𝑟𝑑(𝛼)=𝑞
// 4 Choosearandominteger𝑑:0<𝑑<𝑞
// 5 Compute𝛽≡𝛼𝑑𝑚𝑜𝑑𝑝
// Key pairs:
// 𝑘𝑝𝑢𝑏 =(𝑝,𝑞,𝛼,𝛽) 
// 𝑘𝑝𝑟 =𝑑

// DSA - Signature Generation - Verification
// Signature Generation
// 1 Choose random ephemeral key 𝑘𝐸: 0 < 𝑘𝐸 < 𝑞
// 2 Compute 𝑟 ≡ (𝛼𝑘𝐸 𝑚𝑜𝑑𝑝) 𝑚𝑜𝑑 𝑞
// 3 Compute𝑠≡(𝑆𝐻𝐴(𝑥)+𝑑∗𝑟)∗𝑘−1𝑚𝑜𝑑𝑞 𝐸
// Signature Verification
// 1 Compute 𝑤 ≡ 𝑠−1 𝑚𝑜𝑑 𝑞
// 2 Compute 𝑢1 ≡ 𝑤 ∗ 𝑆𝐻𝐴(𝑥) 𝑚𝑜𝑑 𝑞
// 3 Compute𝑢2≡𝑤∗𝑟𝑚𝑜𝑑𝑞
// 4 Compute𝜈≡(𝛼𝑢1 ∗𝛽𝑢2 𝑚𝑜𝑑𝑝)𝑚𝑜𝑑𝑞
// 5 Verification 𝑣𝑒𝑟(𝑥, (𝑟, 𝑠)):
// if 𝜈 ≡ 𝑟 𝑚𝑜𝑑 𝑞, then valid signature if 𝜈 . 𝑟 𝑚𝑜𝑑 𝑞, then invalid signature

// Hash function - Why it is required?
// Signing a long message:
// If the message is divided into block size that is less than allowed input size of digital signature algorithm
// High computational load Message overhead Security limitations
// a short signature for the message: hash function

// Basic protocol for Digital Signature with a hash function
// Desirable properties of hash function: Fast to compute
// Output is fixed length and independent of input length
// Computed fingerprint (output of the hash function) is highly sensitive to all input bits (a minor modification of input leads to different output)

// Security requirements of hash functions
// Properties needed for a hash function to be "secure":
// 1 preimage resistance (one-wayness): h(x) is one-way
// 2 second preimage resistance (weak collision resistance): 𝑥2 ≠ 𝑥1 : h(𝑥1) = h(𝑥2)
// 3 collision resistance (strong collision resistance): h(𝑥1) = h(𝑥2) : 𝑥1 ≠ 𝑥2

// Hash function algortihms
// Two general types of hash functions:
// Dedicated hash functions: algorithms are specifically designed to serve as hash functions, e.g., MD4 family: MD5, SHA-1...
// Block cipher hash functions: using block cipher to construct hash functions

// Hash Algorithm SHA-1
// part of MD4 family
// based on Merkel-Damgard construction
// 160-bit output from a message of maximum length 264 bits Widely used

// SHA-1 High-level Diagram
// Compress function: 80 rounds, 20 rounds/stage

// SHA-1 Prepocessing
// Padding:
// Message length: 𝑙 bits
// Padded message length: multiple of 512 bits
// Dividing the padded message: 512 bit blocks 𝑥𝑖, each block 16 𝑤𝑜𝑟𝑑𝑠 𝑥 32 𝑏𝑖𝑡𝑠
// Initial fixed hash value 𝐻0: 160 bits ≡ 5 words 𝐻(𝑖)

// SHA-1 Hash computation
// Message schedule: 80 words 𝑊 𝑗 are derived from 16 words of a block in the padded message

// 𝑊𝑗 =
// 𝑥i^(𝑗) if 0 ≤ 𝑗 ≤ 15 
// (𝑊𝑗−16 ⊕ 𝑊𝑗−14 ⊕ 𝑊𝑗−8 ⊕ 𝑊𝑗−3)<<<1 if 16 ≤ 𝑗 ≤ 79
// denote: 𝑋<<<𝑛: circular left shift of the word 𝑋 by 𝑛 bit positions.

// SHA-1 Hash computation - Compression function
// 80-round compression function:
// In each stage 𝑡 (20 rounds): internal function 𝑓𝑡 , constant 𝐾𝑡 are specified
// output after 80 rounds is added to the input value 𝐻𝑖−1 modulo 232 in word-wise fashion.

// SHA-1 Hash function - Compression function
// The operation within round 𝑗 in stage 𝑡: 𝐴,𝐵,𝐶,𝐷,𝐸=(𝐸+𝑓𝑡(𝐵,𝐶,𝐷)+(𝐴)<<<5+𝑊𝑗 +𝐾𝑡),𝐴,(𝐵)<<<30,𝐶,𝐷

// SHA-1 - Parameters
// Initial hash values:
// 𝐴 = 𝐻(0)0 = 674523010
// 𝐵 = 𝐻(1)0 = 𝐸𝐹𝐶𝐷𝐴𝐵890 𝐶 = 𝐻(2)0 = 98𝐵𝐴𝐷𝐶𝐹𝐸0 𝐷 = 𝐻(3)0 = 103254760 𝐸 = 𝐻(4)0 = 𝐶3𝐷2𝐸1𝐹0.

// --------------------------------------------------------------------
// Session 8: Message Authentication Codes and Key
// Establishment

// 1 Message Authentication Codes (MACs)
// Overview
// MACs from Hash functions
//     MACs from hash functions - HMAC
// MACs from Block ciphers

// 2 Key Establishment
// Introduction
// The key distribution problem
// Key Establishment using Symmetric Key Distribution
//     Key Distribution Center
//     Kerberos
// Key Establishment using Asymmetric Key Distribution
//     Cerificates
//     Public Key Infrastructure

// Message Authentication Codes (MACs) - Overview

// Properties:
// Cryptographic checksum or keyed hash function
// Using symmetric-key scheme (much faster than DS)
// Provides:
// Message integrity
// Message authentication
// no non-repudiation

// MACs from Hash functions

// Overview:
// Use hash function, e.g, SHA-1 as a building block to construct MAC
// Basic idea: key is hashed together with the message, e.g, HMAC
// Two ways of construction:
//     secret prefix MAC: m = M ACk (x) = h(k ||x)
//     secret suffix MAC: m = M ACk (x) = h(x||k)

// MACs from hash functions- 2 construction ways
// Secret Prefix MACs:

// Without knowing the key, attacker can generate a valid MAC by adding an
// additional block

// Secret Suffix MAC
// If attacker can find message x0 such that h(x) = h(x0),
// m = h(x||k) = h(x0||k) can be found

// HMAC
// Proposed by Mihir Bellare, Ran Canetti and Hugo Krawczyk in 1996
// Widely used
// Scheme: inner hash and outer hash

// k+ = (k ||0...0): expended key (b
// bits)
// ipad = (00110110,00110110, ...,
// 00110110)
// xi
// : message blocks
// opad = (01011100, 01011100, ...,
// 01011100)
// HM ACk (x) =?

// MACs from Block ciphers

// Using block ciphers to construct MACs
// The most popular approach in practice: a block cipher in CBC mode
// (CBC-MAC)
// Principle of CBC-MAC:

// Key Establishment - Introduction

// Key Establishment: deals with establishing a shared secret between two
// or more parties.
// Key Establishment methods:
//     - Key transport: 1 party generates and distributes a secret key
//     - Key Agreement: parties jointly generate a secret key (Ideally, no single
// party can control what the key value will be)
// Identification of parties is the most important concern

// Key Establishment- Introduction

// Key Freshness
// Key Derivation

// The n^2 key distribution prolem

// Problem:
// Each pair of users needs secured channel
// n users will need: n(n − 1) ≈ n^2 keys (n.(n − 1)/2 if symmetric keys are used)
// A problem for large networks
// → Key Distribution?

// Symmetric Key Distribution

// Key Distribution Center
// Kerberos Protocol

// Key Distribution Center (KDC)
// KDC:
// is a server trusted by all users
// shares a secret key, namely Key Encryption Key (KEK) with each user
// KEK is used to securely transmit secret session keys to users
// Scheme:

// KDC - cont

// Advantages:
// only n KEKs are maintained long-term
// new user needs to establish only KEK with KDC
// Attacks:
// Replay attack
// Key confirmation attack

// Kerberos Protocol

// Provides:
//     - user authentication
//     - Key distribution protocol → key confirmation
// Timeliness:
//     - lifetime of the session key: T
//     - Time stamp to assure message is recent and not replay attack: TS

// Assymetric Key Distribution
// Problem:
// DHKE does not provide authenticated key
// Man-in-the-middle attack against DHKE:

// ⇒ Need authentication for the key to assure Alice and Bob to know the key is
// only from each other ⇒ Certificate: (k pub,A, IDA)

// Cerificates

// Certificates should bind the identity of a user to their public key
// Applying cryptographic mechanism
// CertA = [(k pub,A, IDA), sigkpr

// (k pub,A, IDA)]
// Certificates are provided by trusted third party: Certification Authority
// (CA):
// Certificate Generation with user-provided keys: users ask CA to sign
// Certificate Generation with CA-provided keys: CA generates keys

// Cerificates

// Certificates should bind the identity of a user to their public key
// Applying cryptographic mechanism
// CertA = [(k pub,A, IDA), sigkpr

// (k pub,A, IDA)]
// Certificates are provided by trusted third party: Certification Authority
// (CA):
// Certificate Generation with user-provided keys: users ask CA to sign
// Certificate Generation with CA-provided keys: CA generates keys


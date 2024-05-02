/*
Hash computation - Compression function
80-round compression function:
- In each stage 𝑡 (20 rounds): internal function 𝑓𝑡 , constant 𝐾𝑡 are specified
- output after 80 rounds is added to the input value 𝐻_(i-1) modulo 2^32 in word-wise fashion.
The operation within round 𝑗 in stage 𝑡:
𝐴,𝐵,𝐶,𝐷,𝐸=(𝐸+𝑓𝑡(𝐵,𝐶,𝐷)+(𝐴)<<<(5)+𝑊𝑗 +𝐾𝑡),𝐴,(𝐵)<<<(30),𝐶,𝐷 || (X)<<<(n) --> circular left shift by n

Session 8: Message Authentication Codes and Key Establishment
MACs

MAC from Hash: key + message --> h()
prefix : h(k||x)
suffix : h(x||k)

2 ways construction

Without knowing the key, attacker can generate a valid MAC by adding an additional block

x = (x1...x_n) / m = h(k||x) --> intercept x0 = (x1...x_(n+1)) / m0 = h(m||x_n+1) --> m` = h(k||x1....x_(n+1)) --> m` = m
if suffix: if x0 is found such that h(x) = h(x0):
    m = h(x||k) = h(x0||k) can be found


𝑘¸ = (𝑘 ||0.....0): expended key (b
bits)
ipad = (00110110,00110110, ...,
00110110)
𝑥𝑖 : message blocks
opad = (01011100, 01011100, ...,
01011100)
𝐻𝑀𝐴𝐶_k(𝑥) =?

MACs from Block ciphers
Using block ciphers to construct MACs
The most popular approach in practice: a block cipher in CBC mode
(CBC-MAC)
Principle of CBC-MAC: Cheatsheet


HMAC
Key Establishment: deals with establishing a shared secret between two
or more parties.
Key Establishment methods:
    Key transport: 1 party generates and distributes a secret key
    Key Agreement: parties jointly generate a secret key (Ideally, no single party can control what the key value will be)
Identiﬁcation of parties is the most important concern

The n^2 key distribution prolem
Problem: 
Each pair of users needs secured channel
n users will need: 𝑛(𝑛 - 1) ~ 𝑛2 keys (𝑛•(𝑛 - 1)/2 if symmetric keys are used)
A problem for large networks
--> Key Distribution?

Symmetric Key Distribution
    Key Distribution Center
    Kerberos Protocol

(Key Distribution Center)
KDC: is a server trusted by all users
    shares a secret key, namely Key Encryption Key (KEK) with each user
    KEK is used to securely transmit secret session keys to users

Advantages:
        only n KEKs are maintained long-term
        new user needs to establish only KEK with KDC
Attacks:
        Replay attack
        Key conﬁrmation attack

Kerberos Protocol
Provides:
        user authentication
        Key distribution protocol --> key conﬁrmation
Timeliness:
        lifetime of the session key: 𝑇
        Time stamp to assure message is recent and not replay attack: 𝑇_s



Assymetric Key Distribution

Problem:
    DHKE does not provide authenticated key
    Man-in-the-middle attack against DHKE:
--> Need authentication for the key to assure Alice and Bob to know the key is
only from each other --> Certiﬁcate: (𝑘_𝑝𝑢𝑏,_a– 𝐼𝐷 𝐴)


Certiﬁcates should bind the identity of a user to their public key
Applying cryptographic mechanism
𝐶𝑒𝑟𝑡𝐴 = [(𝑘_𝑝𝑢𝑏,_𝐴, 𝐼𝐷𝐴)– 𝑠𝑖𝑔𝑘𝑝𝑟(𝑘_𝑝𝑢𝑏,_𝐴, 𝐼𝐷𝐴)]
Certiﬁcates are provided by trusted third party: Certiﬁcation Authority
(CA):
    Certiﬁcate Generation with user-provided keys: users ask CA to sign
    Certiﬁcate Generation with CA-provided keys: CA generates keys

*/ 
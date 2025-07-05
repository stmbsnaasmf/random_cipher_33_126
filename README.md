# random_cipher_33_126
ROT13, ROT_N and random cipher, all operating on 94 chars from ASCII-33 to ASCII-126.

ASCII-33 to ASCII-126 are all readabily printable characters.

# Random Cipher

### Encryption 

Encryption is easy and intuitive. We create a map (or key) array of 94 chars, populate it with ASCII-33 to ASCII-126, then shuffle it. Then encryption is simple:

`ciphertext[i] = map[plaintext[i] - 33];`

As we can see, encryption of a single char is an $O(1)$ operation., or $O(m)$ for a char array of length $m$.

### Decryption

Decryption is a little complicated. There are two ways to decrypt:

1. Using the same map that was used for encryption
2. Using the inverse map

#### Using the Same Map

`plaintext[i] = indexOf(map, 94, ciphertext[i]) + 33;`

This requires us to first find the index of the ciphertext char in the map array, which is an $O(n)$ operation for a single character, or $O(n x m)$ for a char array of length $m$. Here, $n$ is the length of the map array. As we can see, it is extremely inefficient.

If we can encrypt a single char in $O(1)$ time using `ciphertext[i] = map[plaintext[i] - 33];`, we should also be able to decrypt in $O(1)$ time as well, right? That brings us to the next section.

#### Using the Inverse Map

"Inverse" may not be the right term here, but I do not know what the correct term would be. I have decided to call this array "pam" in my code. Not very creative, I know. It lets us decrypt a single char in $O(1)$ time, and it lets us decrypt using the **encrypt function**.

`randomCipherEncrypt(map, plaintext, ciphertext);  //Encryption`

`randomCipherEncrypt(pam, ciphertext, plaintext);  //Decryption`

Its construction is not intuitive, not to me at least for now, and I have spent quite some time with a white board trying to figure this out. Luckily, I got it right in the code on the first try, Alhamdulillah.

`int pam[94];
for (int i = 0; i < 94; i++)
{
  pam[i] = indexOf(map, 94, i + 33) + 33;
}`

It does not even look intuitive. For example, the following are the map and the corresponding pam arrays from one of my runs (that had the srand() commented out):

`map: J L E w x ; + ? o 9 b H `` " | 6 r % B X C Q \ e @ i ^ z - . g t & j > 5 [ ( $ V ' ) M N 0 l # < Y 1 y } 8 = ] P n S { 4 s * v / I u c _ a 7 W O 2 Z d ~ m T : G p h F f D q k K 3 U R A , !`

`pam: ~ . O G 2 A I F J ^ ' } = > `` M R i y \ D 0 f U * o & P V C ( 9 | 3 5 u # s p , a ! x " K L h X 6 { Z n z H g 4 Q j E 7 W ; d - e + c k 8 t ? r : B w N m Y ) q v 1 ] @ b _ $ % S < [ / T l`

The construction of this "pam" array is an $O(n^2)$ operation where n is the size of the arrays, but that is a one time cost.

class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        total = 1
        last = {}

        for ch in s:
            new_total = (total * 2 - last.get(ch, 0)) % MOD
            last[ch] = total
            total = new_total

        return (total - 1) % MOD
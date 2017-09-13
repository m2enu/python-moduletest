# hex2dec speedup

## comparison

1. Python built-in int(str_hex, 16) -> 3.32 sec
1. Extend hex2dec with c-lang: call function 1024 times -> 2.84 sec
1. Extend hex2dec with c-lang: call function 1 times and get decs as return value -> 0.558 sec

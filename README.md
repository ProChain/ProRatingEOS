
# ProChain Rating DApp

A dapp gives rating data provided by [`prochaintech`](https://eosflare.io/account/prochaintech)

## EOS Mainnet

 - contract account: [`rating.pra`](https://eosflare.io/account/rating.pra)
 - scope: `rating.pra`
 
 ```
 cleos get table rating.pra rating.pra trating
 ```

## Data Structure

### Table `trating`
- `account` eos account name
- `account_type` enum_account_type: 0, normal account; 1, code account;
- `normal_account_level` rating level for normal account, from 0 to 10
- `code_account_level` rating level for code account, from 0 to 10

### enum `enum_account_type` 
- 0, `normal_account`
- 1, `code_account`

### level defined for both normal and code account
- `BP_BLACKLIST`: 0

### level defined for normal account
- `PRABOX_BLACKLIST`: 2
- `PRABOX_GREYLIST`: 3
- `PRABOX_AUTH_VERYFIED`: 6
- `PRABOX_KYC_VERYFIED`: 6

### level defined for code account
- `MALICIOUS_CODE_ACCOUNT`: 0

## Call Back

TBD

### call back results
- `RESULT_FOUND`: "FOUND"
- `RESULT_NOTFOUND`: "NOTFOUND"

## License
    Copyright (c) 2018-2019 ProChain
    
    The MIT License
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
## Known Users

* [**TopBidder**](https://chain.pro/domain-auction/)
* [**EOSDice**](https://eosdice.vip/)



# ProChain Rating DApp

A dapp gives rating data provided by [`prochaintech`](https://eosflare.io/account/prochaintech)

## EOS Mainnet

 - contract account: [`rating.pra`](https://eosflare.io/account/rating.pra)
 - scope: rating.pra
 
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


# demo

## sample codes:

```
        #include "../pradata.hpp"

        using namespace prochain;

        //声明rating.pra的trating表
        auto list = rating_index(N(rating.pra), N(rating.pra));

        //检查账号是否存在
        auto check = list.find(account);

        //trating表中存储了全量链上合约账号，并实时更新
        //如果找不到，则该账号是普通账号
        if (check != list.end())
        {
            //获取账号类型：普通账号 或 合约账号
            uint8_t account_type = check->account_type;

            //获取普通账号的评分
            if (account_type == normal_account)
            {
                uint8_t account_level = check->normal_account_level;
            }
            //获取合约账号的评分
            else if (account_type == code_account)
            {
                uint8_t account_level = check->code_account_level;
            }
        }
        else
        {
            //普通账号默认评分
            uint8_t account_level = ACCOUNT_LEVEL_DEFAULT;
        }
```
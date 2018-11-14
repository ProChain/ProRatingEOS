#include "pradata.hpp"

using eosio::action;
using eosio::permission_level;
using namespace eosio;

using namespace prochain;
//{

class pradata : public contract
{

  public:
    explicit pradata(account_name self) : contract(self){};

    /**
	* @brief  check account is black or not
	*  
    * @param account      account name to be checked
	* @param notifyaccnt  call back, send check result to notify account
    * @param notifyfunc   call back, send check result to notify function
    */

    //@abi action
    void checkblack(const account_name &account, const account_name &notifyaccnt, std::string notifyfunc)
    {
        require_auth(notifyaccnt);

        rating_index ratinglist(_self, _self);
        auto iter = ratinglist.find(account);
        if (iter != ratinglist.end())
        {
            bool isblack = false;

            //check account type and level
            if (iter->account_type == normal_account)
            {
                if (iter->normal_account_level == BP_BLACKLIST || iter->normal_account_level == PRABOX_BLACKLIST)
                {
                    isblack = true;
                }
            }
            else
            {
                if (iter->code_account_level == BP_BLACKLIST || iter->code_account_level == MALICIOUS_CODE_ACCOUNT)
                {
                    isblack = true;
                }
            }

            //found the account is black
            if (isblack)
            {
                action(permission_level{_self, N(active)},
                       N(notifyaccnt),
                       N(notifyfunc),
                       std::make_tuple(account, std::string(RESULT_FOUND)))
                    .send();
            }
        }
        else
        {
            //can not found
            action(permission_level{_self, N(active)},
                   N(notifyaccnt),
                   N(notifyfunc),
                   std::make_tuple(account, std::string(RESULT_NOTFOUND)))
                .send();
        }
    }

    //@abi action
    void addrating(const Rating &rating)
    {
        require_auth(_self);

        eosio_assert(is_account(rating.account), "rating account is not valid");
        eosio_assert(rating.account_type >= 0 && rating.account_type < account_type_count, "rating account type is not valid");

        rating_index ratinglist(_self, _self);
        auto iter = ratinglist.find(rating.account);
        if (iter == ratinglist.end())
        {
            ratinglist.emplace(_self, [&](auto &r) {
                r.account = rating.account;
                r.account_type = rating.account_type;
                r.normal_account_level = rating.normal_account_level;
                r.code_account_level = rating.code_account_level;
            });
        }
        else
        {
            ratinglist.modify(iter, 0, [&](auto &r) {
                r.account_type = rating.account_type;
                r.normal_account_level = rating.normal_account_level;
                r.code_account_level = rating.code_account_level;
            });
        }
    }

    //@abi action
    void delrating(const Rating &rating)
    {
        require_auth(_self);

        rating_index ratinglist(_self, _self);
        auto iter = ratinglist.find(rating.account);
        if (iter != ratinglist.end())
        {
            ratinglist.erase(iter);
        }
    }
};

EOSIO_ABI(pradata, (checkblack)(addrating)(delrating))

//} // namespace prochain
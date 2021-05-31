def make_change(goal, coins):
    wallets = [[coin] for coin in coins]
    new_wallets = []
    collected = []

    while wallets:
        for wallet in wallets:
            s = sum(wallet)
            for coin in coins:
                if coin >= wallet[-1]:
                    if s + coin < goal:
                        new_wallets.append(wallet + [coin])
                    elif s + coin == goal:
                        collected.append(wallet + [coin])
        wallets = new_wallets
        new_wallets = []
    return collected




print(make_change(14, [2, 3, 14]))
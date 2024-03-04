# すでに購入済みかどうかを判定する処理を作成してください
def is_item_purchased(user, item_id, orders):
    for order in orders:
        if order["user_id"]==user["user_id"]:
            if item_id in order["items"]:
                return True
    return False

# ここから下は触らないでください
# 利用するデータ
orders = [
    {
        'order_id': 1,
        'user_id': 1,
        'items': [1, 4]
    },
    {
        'order_id': 2,
        'user_id': 2,
        'items': [2, 4]
    },
    {
        'order_id': 3,
        'user_id': 1,
        'items': [2, 3]
    },
    {
        'order_id': 4,
        'user_id': 3,
        'items': [1, 5, 6]
    }
]
user = {'user_id': 1, 'name': 'Ken', 'status': 'basic'}
item_id = 5
# 関数の呼び出し
purchased = is_item_purchased(user, item_id, orders)
print('入力1：未購入の商品の場合')
if purchased:
    print('商品ID:' + str(item_id) + 'は購入済みです')
else:
    print('商品ID:' + str(item_id) + 'は未購入です')

print('-----------------------------')

# 利用するデータ
item_id = 2
# 関数の呼び出し
purchased = is_item_purchased(user, item_id, orders)
print('入力2：購入済み商品の場合')
if purchased:
    print('商品ID:' + str(item_id) + 'は購入済みです')
else:
    print('商品ID:' + str(item_id) + 'は未購入です')
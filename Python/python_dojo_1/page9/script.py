# 注文ステータスをキャンセルに更新をする処理を作成してください
def cancel_order(cancel_order_id, orders):
    for order in orders:
        if order["order_id"]==cancel_order_id:
            if order["status"]=="processing" or order["status"]=="cancelled":
                order["status"]="cancelled"
                return "注文をキャンセルしました"
            else:
                return "エラー：出荷済みのためキャンセルすることはできません"
    return "エラー：対象の注文が見つかりませんでした"
    
# ここから下は触らないでください
# 利用するデータ
orders = [
    {
        'order_id': 1,
        'user_id': 1,
        'items': [1, 4],
        'status': 'shipped'
    },
    {
        'order_id': 2,
        'user_id': 2,
        'items': [2, 4],
        'status': 'shipped'
    },
    {
        'order_id': 3,
        'user_id': 1,
        'items': [2, 3],
        'status': 'processing'
    },
    {
        'order_id': 4,
        'user_id': 3,
        'items': [1, 5, 6],
        'status': 'processing'
    }
]
cancel_order_id = 3
# 関数の呼び出し
result = cancel_order(cancel_order_id, orders)
print('入力1：キャンセルにできるステータスの場合')
print(result)

print('-----------------------------')

# 利用するデータ
cancel_order_id = 1
# 関数の呼び出し
result = cancel_order(cancel_order_id, orders)
print('入力2：キャンセルにできないステータスの場合')
print(result)

print('-----------------------------')

# 利用するデータ
cancel_order_id = 10
# 関数の呼び出し
result = cancel_order(cancel_order_id, orders)
print('入力3：注文IDが該当しない場合')
print(result)

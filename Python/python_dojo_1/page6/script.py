# 購入金額と会員情報によって送料の有無を判定する処理を作成してください
def is_shipping_free(cart_items, user):
    total_price=0
    for cart_item in cart_items:
        total_price+=cart_item["price"]
    
    if user["status"]=="premium" and total_price>=5000:
        return True
    elif user["status"]=="basic" and total_price>=10000:
        return True
    else:
        return False
# ここから下は触らないでください
# 利用するデータ
cart_items = [
    {'id': 2, 'name': 'ヘッドホン', 'price': 5500},
    {'id': 4, 'name': '乾電池', 'price': 100}
]
user = {'user_id': 2, 'name': 'John', 'status': 'basic'}
# 関数の呼び出し
free_shipping = is_shipping_free(cart_items, user)
print('入力1：送料有料になる金額の場合')
if free_shipping:
    print("配送料は無料です")
else:
    print("配送料がかかります")

print('-----------------------------')

# 利用するデータ
cart_items = [
    {'id': 1, 'name': 'ゲームソフト', 'price': 5000}
]
user = {'user_id': 2, 'name': 'John', 'status': 'premium'}
# 関数の呼び出し
free_shipping = is_shipping_free(cart_items, user)
print('入力2：送料無料になる金額の場合')
if free_shipping:
    print("配送料は無料です")
else:
    print("配送料がかかります")

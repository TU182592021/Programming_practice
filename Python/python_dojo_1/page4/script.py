# 購入数に応じた割引計算をする処理を作成してください
def calculate_large_discounts(price, quantity):
    if quantity>=20:
        price=round(price*quantity*0.9)
        return price
    elif quantity>=10:
        price=round(price*quantity*0.95)
        return price
    else:
        return price*quantity

# ここから下は触らないでください
# 利用するデータ
price = 100
quantity = 20
# 関数の呼び出し
total_price = calculate_large_discounts(price, quantity)
print('入力1：購入数が20個の場合')
print(total_price)

print('-----------------------------')

# 利用するデータ
quantity = 10
# 関数の呼び出し
total_price = calculate_large_discounts(price, quantity)
print('入力2：購入数が10個の場合')
print(total_price)

print('-----------------------------')

# 利用するデータ
quantity = 9
# 関数の呼び出し
total_price = calculate_large_discounts(price, quantity)
print('入力3：購入数が9個の場合')
print(total_price)

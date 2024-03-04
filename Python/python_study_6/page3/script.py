# カート内の商品の税込合計金額を返す処理を作成してください
def calculate_total_with_tax(cart_items, tax_rate):
  total_price=0
  for cart in cart_items:
    total_price+=cart["price"]
  total_price+=round(total_price*tax_rate)
  return total_price

# ここから下は触らないでください
# 利用するデータ
cart_items = [
    {'name': 'Tシャツ', 'type': 'clothes', 'price': 2000},
    {'name': 'キャップ', 'type': 'cap', 'price': 8000}
]
tax_rate = 0.1
# 関数の呼び出し
total_with_tax = calculate_total_with_tax(cart_items, tax_rate)
print(total_with_tax)
# カート内の合計金額を返す処理を作成してください
def calculate_total_price(cart_items):
  total_price=0
  for cart_item in cart_items:
    if cart_item["type"]=="food":
      total_price+=round(cart_item["price"]*0.9)
    elif cart_item["type"]=="clothes":
      total_price+=cart_item["price"]-1000
    else:
      total_price+=cart_item["price"]
  return total_price

# ここから下は触らないでください
# 利用するデータ
cart_items = [
    {'name': 'Tシャツ', 'type': 'clothes', 'price': 2000},
    {'name': 'キャップ', 'type': 'cap', 'price': 8000},
    {'name': 'ランニングシューズ', 'type': 'shoes', 'price': 15000},
    {'name': 'アンダーウェア', 'type': 'clothes', 'price': 4500},
    {'name': 'テニスラケット', 'type': 'sports goods', 'price': 8000},
    {'name': 'スポーツドリンク', 'type': 'food', 'price': 150}
]
# 関数の呼び出し
total_price = calculate_total_price(cart_items)
print(total_price)